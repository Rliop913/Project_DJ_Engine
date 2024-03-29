#pragma once
#include "beat_compiler_extension.h"
#include "Engine_Main.h"
#include <functional>
#include <assert.h>

extern function_pointers GFP;

beat_compiler_extension::beat_compiler_extension(const dj_init_group& init) {
	MAIN_DATA = init.dj_data_path;
	if (init.process_pointer != nullptr) {
		voidp = init.process_pointer;
	}
	if (MAIN_DATA != "") {
		void* main_p = GFP.init_fileitr(MAIN_DATA);
		main_reader_start(main_p);
		GFP.uninit_fileitr(main_p);
	}
}

void
beat_compiler_extension::hasher_init(std::unordered_map<std::string, int>& hasher)
{
	hasher["bar"] = 0;
	hasher["Sbar"] = 0;
	hasher["separate"] = 1;
	hasher["Sseparate"] = 1;
	hasher["Eseparate"] = 2;
	hasher["Ebeat"] = 3;
	hasher["Ebar"] = 4;
	hasher["beat"] = 5;
	hasher["Sbeat"] = 5;
	// hasher[no use key] = 10;
}

void
beat_compiler_extension::main_reader_start(void* mainP) {
	Processor* pproc = (Processor*)voidp;
	std::string temp;
	std::unordered_map<std::string, int> hasher;
	hasher_init(hasher);
	while (GFP.line_getter(mainP, temp)) {
		//assert(temp != "");
		JSON_OUT root = GFP.JSON_parser(temp);
		if (root.size()!=0) {
			if (root["type"] == "INIT") {
				pproc->set_MAX_DECK_USE(std::stoi((root["first"])));
				continue;
			}
			else if (root["type"] == "LOAD") {
				std::string tempppp = root["for_who"];
				//root["for_who"].asString()
				album_specific_data.insert(std::make_pair( std::stoi(tempppp), root["str_first"]));
				
			}
			
			raw_data raws;
			for (auto it = root.begin(); it != root.end(); ++it) {
				
				int hash_out = hasher[it->first];
		
				switch (hash_out) {

				case 0:
					raws.loc_table.bar = std::stoi(it->second);
					break;
				case 1:
					raws.loc_table.separate = std::stoi(it->second);
					break;
				case 2:
					raws.long_end_table.separate = std::stoi(it->second);
					break;
				case 3:
					raws.long_end_table.beat= std::stoi(it->second);
					break;
				case 4:
					raws.long_end_table.bar = std::stoi(it->second);
					break;
				case 5:
					raws.loc_table.beat = std::stoi(it->second);
					break;
				default:
					raws.other_tags[it->first] = it->second;
					break;
				}
			}
			raw_reserve[(std::stoi(root["where"]))].push_back(raws);
			root.clear();
		}
	}//readed to end complete
	std::vector<std::thread> thread_pool;
	for (auto i = raw_reserve.begin(); i != raw_reserve.end(); i++) {
		thread_pool.emplace_back([this,i]() {
			calculate_raw_data(i->first);
			});
	}
	for (int i = 0; i < thread_pool.size(); i++) {
		thread_pool.at(i).join();
	}
	sort_reservation();
	raw_reserve.clear();
	album_specific_data.clear();
	//calculate_raw_data();
}

void
beat_compiler_extension::calculate_raw_data(const int& albumID) {//thread safe & using thread//
	void* albumP = GFP.init_fileitr(album_specific_data[albumID]);
	std::string temp;
	
	struct inside_scope_data {
		double start_bpm;
		double first_beat;
	}inside;

	std::vector<ch_bpm_data_table> storage;//inside_scope_bpm_change_storage

	while (GFP.line_getter(albumP, temp)) {
		JSON_OUT jval = GFP.JSON_parser(temp);
		if (jval.size() != 0) {
			if (jval.contains("first_beat")) {//meta data init, only once
				inside.start_bpm = std::stod(jval["bpm"]);
				inside.first_beat = std::stod(jval["first_beat"]);
				stored_data dat;
				dat.start_bpm = inside.start_bpm;
				dat.first_beat = inside.first_beat;
				dat.bpm_storage.assign(storage.begin(), storage.end());//deep copy
				real_time_mutex.lock();
				album_data_for_real_time[albumID] = dat;
				real_time_mutex.unlock();
			}
			else {
				ch_bpm_data_table ttable;
				ttable.std_table.bar = std::stoi(jval["bar"]);
				ttable.std_table.separate = std::stoi(jval["separate"]);
				ttable.std_table.beat = std::stoi(jval["beat"]);
				ttable.bpm = std::stod(jval["ch_bpm"]);
				storage.push_back(ttable);
			}
		}
		jval.clear();
	}
	sort_storage(storage);
	calc_bpm_storage(storage, inside.start_bpm,inside.first_beat);
	reservation(storage,albumID, inside.start_bpm,inside.first_beat);
	GFP.uninit_fileitr(albumP);
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

		if (raw_reserve.at(albumID).at(i).long_end_table.separate != 0) {//interpolations
			if (inside.size() == 0) {//no bpm changes
				engine_order order;
				order.frame_in = calc_time_T_S(raw_reserve.at(albumID).at(i).loc_table, start_bpm, first_beat);
				order.frame_out = calc_time_T_S(raw_reserve.at(albumID).at(i).long_end_table, start_bpm, first_beat);
				order.tag = raw_reserve.at(albumID).at(i).other_tags;
				data_locker.lock();
				reservation_storage[albumID].push_back(order);
				data_locker.unlock();
			}
			else {//bpm changed
				double start_approx = to_appr(raw_reserve.at(albumID).at(i).loc_table);
				double end_approx = to_appr(raw_reserve.at(albumID).at(i).long_end_table);
				int start_bpm_point = 0;
				int end_bpm_point = 0;
				start_bpm_point = check_bpms(inside, start_approx);
				end_bpm_point = check_bpms(inside, end_approx);
				engine_order order;
				start_bpm_point == 0 ? order.frame_in = calc_time_T_S(raw_reserve.at(albumID).at(i).loc_table, start_bpm, first_beat) : order.frame_in = calc_time_between_T_S(inside.at(start_bpm_point), raw_reserve.at(albumID).at(i).loc_table);
				end_bpm_point == 0 ? order.frame_out = calc_time_T_S(raw_reserve.at(albumID).at(i).long_end_table, start_bpm, first_beat) : order.frame_out = calc_time_between_T_S(inside.at(end_bpm_point), raw_reserve.at(albumID).at(i).long_end_table);
				order.tag = raw_reserve.at(albumID).at(i).other_tags;
				data_locker.lock();
				reservation_storage[albumID].push_back(order);
				data_locker.unlock();
			}
			
		}//--------------------------------------------------------------------------------------------------------------------------//
		else {//normals
			if (inside.size() == 0) {//no bpm changes
				engine_order order;
				order.frame_in=calc_time_T_S(raw_reserve.at(albumID).at(i).loc_table,start_bpm, first_beat);
				order.frame_out = 0;
				order.tag= raw_reserve.at(albumID).at(i).other_tags;
				data_locker.lock();
				reservation_storage[albumID].push_back(order);
				data_locker.unlock();
			}
			else {//bpm changed
				double temp_approx = to_appr(raw_reserve.at(albumID).at(i).loc_table);
				int bpm_point = 0;
				bpm_point = check_bpms(inside, temp_approx);
				engine_order order;
				order.frame_in = bpm_point == 0? calc_time_T_S(raw_reserve.at(albumID).at(i).loc_table, start_bpm, first_beat): calc_time_between_T_S(inside.at(bpm_point), raw_reserve.at(albumID).at(i).loc_table);
				order.frame_out = 0;
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
		if (now_frame > unsigned long long(in_here.bpm_storage.at(in_here.bpm_storage.size() - 1).time_to_here*48000)) {//no more higher approx
			bpmP = (in_here.bpm_storage.at(in_here.bpm_storage.size() - 1).bpm);
			return;
		}
		else if (now_frame < unsigned long long(in_here.bpm_storage.at(0).time_to_here*48000.0)) {//lower than every bpm ch
			return;
		}
		else {
			for (int j = 1; j < in_here.bpm_storage.size(); j++) {
				if (now_frame< unsigned long long(in_here.bpm_storage.at(j).time_to_here)) {
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