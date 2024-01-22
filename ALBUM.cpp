#include "ALBUM.h"
#include "temp_json_reader.h"
#include "Processor.h"

void
ALBUM::idle_process(ma_uint32 frameCount, float* main_buffer) {
	this_data.got_frames = false;
	MAW::silence_memory(process_memory, frameCount);

	cursor->mvcur(process_memory, frameCount);
	this_data.got_frames = true;
	before_faust_caster(process_memory , faust_before1 , faust_before2 , frameCount);
	//---------------------------FAUST HERE-------------------------------//
	album_engine->compute(frameCount, faust_before1 ,faust_before2 , faust_after1 ,faust_after2 );
	//---------------------------FAUST HERE-------------------------------//
	pproc->buf_mutex.lock();
	after_faust_caster(faust_after1 , faust_after2 , main_buffer, frameCount);
	pproc->buf_mutex.unlock();
}















void
ALBUM::dj_process(ma_uint32 frameCount, float* main_buffer) {
	this_data.got_frames = false;
	MAW::silence_memory(process_memory , frameCount);
	ma_uint64 frame_now = 0;
	cursor->get_now_frame(frame_now);
	reserve_read(frame_now);
	interpolate_function(frame_now);
	if (this_data.playback_ordered) {
		cursor->mvcur(process_memory , frameCount);
		this_data.got_frames = true;
	}
	before_faust_caster(process_memory , faust_before1 , faust_before2 , frameCount);
	//---------------------------FAUST HERE-------------------------------//
	album_engine->compute(frameCount, faust_before1 , faust_before2 , faust_after1 ,faust_after2 );
	MAW::silence_memory(process_memory, frameCount);
	//---------------------------FAUST HERE-------------------------------//
	after_faust_caster(faust_after1 , faust_after2 , process_memory, frameCount);
	pproc->buf_mutex.lock();
	for (int i = 0; i < frameCount * 2; ++i) {

		main_buffer[i] += process_memory[i];
	}
	pproc->buf_mutex.unlock();
}




void
ALBUM::before_faust_caster(void* input, void* out_left, void* out_right,const ma_uint32& frameCount) {
	int whole_size = VOID_BUFFER_SIZE(frameCount, 2)/8;
	for (int i = 0; i < whole_size; i++) {//odd is right
		((float*)out_left)[i] = (((float*)input)[i * 2]);
		((float*)out_right)[i] = ((float*)input)[i * 2 + 1];
	}
}

void
ALBUM::after_faust_caster(void* in_left, void* in_right, void* output,const ma_uint32& frameCount) {
	int whole_size = VOID_BUFFER_SIZE(frameCount, 2) / 8;
	for (int i = 0; i < whole_size; i++) {//odd is right
		((float*)output)[i * 2] += ((float*)in_left)[i];
		((float*)output)[i * 2 + 1] += ((float*)in_right)[i];
	}//add to buffer
}


void
ALBUM::album_init(const std::string& song_path) {
	cursor = new CURSOR(song_path, *pproc);
	this_data.data_path = song_path;
	album_engine = new Faust_engine();
	album_engine->init(48000);
	module = new sound_module(pproc,this,album_engine);
}

void
ALBUM::dynamic_memory_uninit()
{
	free(process_memory);
	free(faust_before1);
	free(faust_before2);
	free(faust_after1);
	free(faust_after2);
//#ifdef FOR_LINUX_BUILD
//#endif
//#ifndef FOR_LINUX_BUILD
//	_aligned_free(process_memory);
//	_aligned_free(faust_before1);
//	_aligned_free(faust_before2);
//	_aligned_free(faust_after1);
//	_aligned_free(faust_after2);
//#endif
}

void
ALBUM::dynamic_memory_init()
{
	int AB_Size = pproc->get_audio_buffer_size();
	process_memory = (float*)malloc(sizeof(float) * AB_Size * 2);
	faust_before1 = (float*)malloc(sizeof(float) * AB_Size);
	faust_before2 = (float*)malloc(sizeof(float) * AB_Size);
	faust_after1 = (float*)malloc(sizeof(float) * AB_Size);
	faust_after2 = (float*)malloc(sizeof(float) * AB_Size);
	/*process_memory = (float*)_aligned_malloc(sizeof(float) * AB_Size * 2, 32);
	faust_before1 = (float*)_aligned_malloc(sizeof(float) * AB_Size, 32);
	faust_before2 = (float*)_aligned_malloc(sizeof(float) * AB_Size, 32);
	faust_after1 = (float*)_aligned_malloc(sizeof(float) * AB_Size, 32);
	faust_after2 = (float*)_aligned_malloc(sizeof(float) * AB_Size, 32);*/

}



ALBUM::~ALBUM() {
	delete cursor;
	delete album_engine;
	delete module;
	dynamic_memory_uninit();
}

ALBUM::ALBUM(const std::string& song_path, const int& channel, const int& albumID, Processor* p, const std::string& meta_data_path) {
	pproc = p;
	album_init(song_path);
	TJR_RETURN file_inside = TJR::temp_json_reader(meta_data_path);
	this->this_data.ID = albumID;
	this->this_data.bpm = std::stod(file_inside.at(0)["bpm"]);
	this->this_data.start_time = std::stod(file_inside.at(0)["start_time"]);
	dynamic_memory_init();
}
#include <iostream>
void
ALBUM::reserve_read(const ma_uint64& frame_now) {
	std::unordered_map<int,std::vector<engine_order>>* RS = &pproc->pBCE->reservation_storage;
go_to_function_for_simple_check://check until vector until reservation is available
	if ((*RS)[this_data.ID].size() == 0) {
		return;
	}
	if (pproc->raw_to_processed((*RS)[this_data.ID].at(0).frame_in) < frame_now) {
		//new code
		tagables tags;
		tags.type = (*RS)[this_data.ID].at(0).tag["type"];
		tags.what_ = (*RS)[this_data.ID].at(0).tag["what"];
		tags.where_ =std::stoi((*RS)[this_data.ID].at(0).tag["where"]);
		tags.for_who = std::stoi((*RS)[this_data.ID].at(0).tag["for_who"]);
		tags.first = std::stod((*RS)[this_data.ID].at(0).tag["first"]);
		tags.second = std::stod((*RS)[this_data.ID].at(0).tag["second"]);
		tags.str_first= (*RS)[this_data.ID].at(0).tag["str_first"];
		tags.str_second = (*RS)[this_data.ID].at(0).tag["str_second"];
		tags.frame_in = pproc->raw_to_processed((*RS)[this_data.ID].at(0).frame_in);
		tags.frame_out = pproc->raw_to_processed((*RS)[this_data.ID].at(0).frame_out);
		
		std::cout << tags.what_ << "ID:" << tags.for_who << std::endl;
		
		if (tags.frame_out == 0) {//toggle mode
			module->toggle(tags);
		}
		else {//interpolate mode
			module->interpolate(tags,tags.frame_in, tags.frame_out);
		}
		std::cout << (*RS)[this_data.ID].begin()->frame_in<<std::endl;
		((*RS)[this_data.ID]).erase((*RS)[this_data.ID].begin());

		goto go_to_function_for_simple_check;//back to if
	}

}

void
ALBUM::interpolate_function(const ma_uint64& now_frame) {
		for (auto i = 0; i < inter_queue.size(); i++) {
			inter_body body = inter_queue[i];
			if (now_frame > body.end_frame) {
				body.setter_method(body.end_value);
				body.death_method();
				inter_queue.erase(inter_queue.begin() + i);
				i--;
				continue;
			}
			body.sw_method(true);
			
			body.setter_method((float)(((1 - (double)(now_frame - body.start_frame) / (double)(body.end_frame - body.start_frame)) * body.start_value) + (double)(now_frame - body.start_frame) / (double)(body.end_frame - body.start_frame) * body.end_value));
		}

		
}

mix_data_set
ALBUM::get_mixing_data() {
	mix_data_set set;
	set.path = this_data.data_path;
	set.trim = album_engine->trim;
	set.fader = album_engine->fader;
	set.eq_mid_v = album_engine->eq_mid_v;
	set.eq_low_v = album_engine->eq_low_v;
	set.eq_hi_v = album_engine->eq_hi_v;
	album_engine->lo_fi_sw == 0 ? set.lpf_sw = true : set.lpf_sw = false;
	album_engine->hi_fi_sw == 0 ? set.hpf_sw = true : set.hpf_sw = false;
	album_engine->echo_sw == 0 ? set.echo_sw_ = true : set.echo_sw_= false;
	album_engine->l_f_s_sw== 0 ? set.l_f_s_sw_= true : set.l_f_s_sw_= false;
	album_engine->phaser_sw == 0 ? set.phaser_sw_= true : set.phaser_sw_= false;
	album_engine->flanger_sw == 0 ? set.flanger_sw_= true : set.flanger_sw_= false;
	album_engine->trance_sw == 0 ? set.trance_sw_= true : set.trance_sw_= false;
	album_engine->panner_sw == 0 ? set.panner_sw_= true : set.panner_sw_= false;
	album_engine->distortion_sw== 0 ? set.distortion_sw_= true : set.distortion_sw_= false;
	//set.scratch_sw_ = is_SCRATCH;
	//set.rev_sw_ = is_rev;
	set.now_bpm = float(this_data.bpm / cursor->get_IOSR());
	return set;
}

void
ALBUM::PLAY()
{
	this_data.playback_ordered = true;
}

void
ALBUM::STOP()
{
	this_data.playback_ordered = false;
}