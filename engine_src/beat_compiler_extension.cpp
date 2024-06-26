#include "beat_compiler_extension.hpp"
#include "Engine_Main.h"
#include <functional>
#include <assert.h>


beat_compiler_extension::beat_compiler_extension(const dj_init_group& init, function_pointers& fp) {
	BFP = &fp;
	if (init.process_pointer != nullptr) {
		voidp = init.process_pointer;
	}
	if (init.dj_data != "" ) {
		data_manager dm(*BFP);
		dm[init.dj_data];
		main_reader_start(dm);
	}
}


beat_compiler_extension::~beat_compiler_extension()
{
	//delete(bindj);
}


void
beat_compiler_extension::main_reader_start(data_manager& DM) {
	Processor* pproc = (Processor*)voidp;
	std::string temp;
	KV kv;
	while (DM>>=kv) {
		if (SI(kv["type"]) == dj_type::INIT) {
			pproc->set_MAX_DECK_USE(SI(kv["first"]));
			continue;
		}
		else if (SI(kv["type"]) == dj_type::LOAD) {
			album_specific_data.insert(std::make_pair(SI(kv["target"]), kv["first"]));
		}
		raw_reserve[SI(kv["from"])].push_back(kv);
	}	
	//readed to end complete
	std::vector<std::thread> thread_pool;
	for (auto i = raw_reserve.begin(); i != raw_reserve.end(); i++) {
		thread_pool.emplace_back([this, i, &DM]() {
			
			auto nm = DM.clone_self();
			
			calculate_raw_data(i->first, *nm);
			});
	}
	for (int i = 0; i < thread_pool.size(); i++) {
		thread_pool.at(i).join();
	}
	sort_reservation();
	raw_reserve.clear();
	album_specific_data.clear();
}

void
beat_compiler_extension::calculate_raw_data(const int& albumID, data_manager& new_manager) {//thread safe & using thread//
	char* bin_origin;
	long long bsize;
	
	BFP->read_whole_file(bin_origin, bsize, album_specific_data[albumID]);
	
	struct inside_scope_data {
		double start_bpm;
		double first_beat;
	}inside;
	KV kv;
	//MLBSL* tst;
	new_manager[album_specific_data[albumID]];
	//std::vector<ch_bpm_data_table> storage;//inside_scope_bpm_change_storage
	while (new_manager >>= kv) {
		inside.first_beat = SF(kv["firstBeat"]);
		inside.start_bpm = SF(kv["bpm"]);
		stored_data dat;
		dat.start_bpm = inside.start_bpm;
		dat.first_beat = inside.first_beat;
		if (kv["sofLanPath"] != "") {
			auto sofdm = (new_manager.clone_self());
			
			(*sofdm)[kv["sofLanPath"]];
			KV sofkv;
			//char* sof_bin;
			//long long bsize;
			//BFP->read_whole_file(sof_bin, bsize, kv["sof_lan_path"]);
			//PBSL* sof_strt = (PBSL*)sof_bin;
			//sfit<PBSL> sbit(bsize, sof_strt);
			//PBSL* tt;

			while ((*sofdm) >>= sofkv) {
				ch_bpm_data_table ttable;
				ttable.std_table.bar = SI(sofkv["Sbar"]);
				ttable.std_table.separate = SI(sofkv["Ssep"]);
				ttable.std_table.beat = SI(sofkv["Sbeat"]);
				ttable.bpm = SF(sofkv["Sbar"]);
				dat.bpm_storage.push_back(ttable);
			}
			
			sort_storage(dat.bpm_storage);
			calc_bpm_storage(dat.bpm_storage, inside.start_bpm,inside.first_beat);
		}
		real_time_mutex.lock();
		album_data_for_real_time[albumID] = dat;
		real_time_mutex.unlock();
		reservation(dat.bpm_storage, albumID, inside.start_bpm,inside.first_beat);
	}
	return;
}

int
beat_compiler_extension::check_bpms(const std::vector<ch_bpm_data_table>& bpmS, const double& aprx)
{
	if (aprx > bpmS.at(bpmS.size() - 1).approx_loc) {//no more higher approx
		return int(bpmS.size()) - 1;
	}
	else if (aprx < bpmS.at(0).approx_loc) {//lower than every bpm ch
		return 0;
	}
	else {
		for (int j = 1; j < bpmS.size(); j++) {
			if (aprx< bpmS.at(j).approx_loc) {
				return j - 1;
			}
		}
		return -1;
	}
}


void
beat_compiler_extension::reservation(std::vector<ch_bpm_data_table>& inside,const int& albumID, const double& start_bpm, const double& first_beat) {//bpm storage and ID
	for (int i = 0; i < raw_reserve.at(albumID).size(); i++) {
		// standard_tag_table sloc;
		// sloc.bar = raw_reserve.at(albumID).at(i).Sbar;
		// sloc.beat = raw_reserve.at(albumID).at(i).Sbeat;
		// sloc.separate = raw_reserve.at(albumID).at(i).Ssep;
		// standard_tag_table eloc;
		// eloc.bar = raw_reserve.at(albumID).at(i).Ebar;
		// eloc.beat = raw_reserve.at(albumID).at(i).Ebeat;
		// eloc.separate = raw_reserve.at(albumID).at(i).Esep;

		if (raw_reserve.at(albumID).at(i).contains("Sbar")) {//interpolations
			standard_tag_table sloc;
			sloc.bar = SI(raw_reserve.at(albumID).at(i)["Sbar"]);
			sloc.beat = SI(raw_reserve.at(albumID).at(i)["Sbeat"]);
			sloc.separate = SI(raw_reserve.at(albumID).at(i)["Ssep"]);
			standard_tag_table eloc;
			eloc.bar = SI(raw_reserve.at(albumID).at(i)["Ebar"]);
			eloc.beat = SI(raw_reserve.at(albumID).at(i)["Ebeat"]);
			eloc.separate = SI(raw_reserve.at(albumID).at(i)["Esep"]);
			if (inside.size() == 0) {//no bpm changes
				engine_order order;
				order.frame_in = calc_time_T_S(sloc, start_bpm, first_beat);
				order.frame_out = calc_time_T_S(eloc, start_bpm, first_beat);
				order.dj_tags = raw_reserve.at(albumID).at(i);
				data_locker.lock();
				reservation_storage[albumID].push_back(order);
				data_locker.unlock();
			}
			else {//bpm changed
				double start_approx = to_appr(sloc);
				double end_approx = to_appr(eloc);
				int start_bpm_point = 0;
				int end_bpm_point = 0;
				start_bpm_point = check_bpms(inside, start_approx);
				end_bpm_point = check_bpms(inside, end_approx);
				engine_order order;
				
				start_bpm_point == 0 ? 
					order.frame_in = calc_time_T_S(sloc, start_bpm, first_beat) 
					: 
					order.frame_in = calc_time_between_T_S(inside.at(start_bpm_point), sloc);
				
				end_bpm_point == 0 ? 
					order.frame_out = calc_time_T_S(eloc, start_bpm, first_beat) 
					:
					order.frame_out = calc_time_between_T_S(inside.at(end_bpm_point), eloc);

				order.dj_tags = raw_reserve.at(albumID).at(i);
				data_locker.lock();
				reservation_storage[albumID].push_back(order);
				data_locker.unlock();
			}
			
		}//--------------------------------------------------------------------------------------------------------------------------//
		else {//normals
			standard_tag_table nloc;
			nloc.bar = SI(raw_reserve.at(albumID).at(i)["bar"]);
			nloc.beat = SI(raw_reserve.at(albumID).at(i)["beat"]);
			nloc.separate = SI(raw_reserve.at(albumID).at(i)["sep"]);
			if (inside.size() == 0) {//no bpm changes
				engine_order order;
				order.frame_in = calc_time_T_S(nloc, start_bpm, first_beat);
				order.frame_out = 0;
				order.dj_tags = raw_reserve.at(albumID).at(i);
				data_locker.lock();
				reservation_storage[albumID].push_back(order);
				data_locker.unlock();
			}
			else {//bpm changed
				double temp_approx = to_appr(nloc);
				int bpm_point = 0;
				bpm_point = check_bpms(inside, temp_approx);
				engine_order order;
				order.frame_in = bpm_point == 0 ?
					calc_time_T_S(nloc, start_bpm, first_beat)
					:
					calc_time_between_T_S(inside.at(bpm_point), nloc);
				order.frame_out = 0;
				order.dj_tags = raw_reserve.at(albumID).at(i);
				data_locker.lock();
				reservation_storage[albumID].push_back(order);
				data_locker.unlock();
			}
		}
	}
}
				
			


void
beat_compiler_extension::sort_storage(std::vector<ch_bpm_data_table>& inside) {
	for (int i = 0; i < inside.size(); i++) {
		inside.at(i).approx_loc = to_appr(inside.at(i).std_table);
	}
	ch_bpm_data_table key;
	int j = 0;
	for (int i = 1; i < inside.size(); i++) {
		key = inside.at(i);
		for (j = i - 1; j >= 0 && inside.at(j).approx_loc > key.approx_loc; j--) {
			inside.at(j + 1) = inside.at(j);
		}
		inside.at(j + 1) = key;
	}
}
void
beat_compiler_extension::sort_reservation() {
	engine_order key;
	for (auto res_iter = reservation_storage.begin(); res_iter != reservation_storage.end(); ++res_iter) {
		int j = 0;
		for (int i = 1; i < res_iter->second.size(); i++) {
			key = res_iter->second.at(i);
			for (j = i - 1; j >= 0 && res_iter->second.at(i).frame_in> key.frame_in; j--) {
				res_iter->second.at(j + 1) = res_iter->second.at(j);
			}
			res_iter->second.at(j + 1) = key;
		}
	}
}



void
beat_compiler_extension::calc_bpm_storage(std::vector<ch_bpm_data_table>& inside,const double& start_bpm,const double& first_beat) {
	double accumulator = 0.0;
	if (inside.size() != 0) {
		inside.at(0).time_to_here = calc_time_T_S(inside.at(0).approx_loc, start_bpm, first_beat);
	}
	for (int i = 1; i < inside.size(); i++) {
		inside.at(i).time_to_here = calc_time_between_T_S(inside.at(i-1), inside.at(i).std_table);
	}
}


double
beat_compiler_extension::calc_time_T_S(const standard_tag_table& std_dat,const double& bpm,const double& first_beat) {
	double final_value = first_beat;
	double approx_loc = to_appr(std_dat);
	final_value += approx_loc * (double(CONST_BPM) / bpm);
	return final_value;
}

double
beat_compiler_extension::calc_time_T_S(const double& approx_loc,const double& bpm,const double& first_beat) {
	double final_value = first_beat;
	final_value += approx_loc * (double(CONST_BPM) / bpm);
	return final_value;
}

double
beat_compiler_extension::calc_time_between_T_S(const ch_bpm_data_table& front_dat,const standard_tag_table& back_dat){
	double between_time = 0.0;
	double temp_approx = to_appr(back_dat) - to_appr(front_dat.std_table);
	between_time = calc_time_T_S(temp_approx, front_dat.bpm, 0.0) + front_dat.time_to_here;
	return between_time;
}

double
beat_compiler_extension::calc_time_between_T_S(const ch_bpm_data_table& front_dat,const double& back_approx_loc) {
	double between_time = 0.0;
	double temp_approx = back_approx_loc - to_appr(front_dat.std_table);
	between_time = calc_time_T_S(temp_approx, front_dat.bpm, 0.0) + front_dat.time_to_here;
	return between_time;
}

double
beat_compiler_extension::to_appr(const standard_tag_table& table) {
	return double(table.bar) + (double(table.beat) / double(table.separate));
}



//----------------------------------------for_real_time-------------------------------------//

double
beat_compiler_extension::calc_in_real_time(const double& approx_loc,const int& albumID) {
	stored_data in_here = album_data_for_real_time[albumID];
	if (in_here.bpm_storage.size() == 0) {//no bpm changes
		engine_order order;
		return calc_time_T_S(approx_loc, in_here.start_bpm, in_here.first_beat);

	}
	else {//bpm changed
		if (approx_loc > in_here.bpm_storage.at(in_here.bpm_storage.size() - 1).approx_loc) {//no more higher approx

			return calc_time_between_T_S(in_here.bpm_storage.at(in_here.bpm_storage.size() - 1), approx_loc);
		}
		else if (approx_loc < in_here.bpm_storage.at(0).approx_loc) {//lower than every bpm ch
			return calc_time_T_S(approx_loc, in_here.start_bpm, in_here.first_beat);
		}
		else {
			for (int j = 1; j < in_here.bpm_storage.size(); j++) {
				if (approx_loc < in_here.bpm_storage.at(j).approx_loc) {
					return calc_time_between_T_S(in_here.bpm_storage.at(j - 1), approx_loc);
				}
			}
			return -1.0;
		}

	}
}

void
beat_compiler_extension::calc_now_bpm(const unsigned long long& now_frame, const int& albumID, double& bpmP) {
	stored_data in_here = album_data_for_real_time[albumID];
	if (in_here.bpm_storage.size() == 0) {//no bpm changes
		bpmP = album_data_for_real_time[albumID].start_bpm;
		return;
	}
	else {
		if (now_frame > (unsigned long long)(in_here.bpm_storage.at(in_here.bpm_storage.size() - 1).time_to_here*48000)) {//no more higher approx
			bpmP = (in_here.bpm_storage.at(in_here.bpm_storage.size() - 1).bpm);
			return;
		}
		else if (now_frame < (unsigned long long)(in_here.bpm_storage.at(0).time_to_here*48000.0)) {//lower than every bpm ch
			return;
		}
		else {
			for (int j = 1; j < in_here.bpm_storage.size(); j++) {
				if (now_frame< (unsigned long long)(in_here.bpm_storage.at(j).time_to_here)) {
					bpmP = (in_here.bpm_storage.at(j- 1).bpm);
					return;
				}
			}
		}
	}
}

void
beat_compiler_extension::init_in_real_time(const int& albumID, double& bpmP, double& first_beat_P) {
	bpmP = album_data_for_real_time[albumID].start_bpm;
	first_beat_P = album_data_for_real_time[albumID].first_beat;
}