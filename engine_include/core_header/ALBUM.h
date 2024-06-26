#pragma once
#include "GlobalStructs.hpp"
#include "sound_module.h"
#include "CURSOR.h"
#include "data_loader.hpp"
class Processor;
class ALBUM {
private:
	void reserve_read(const ma_uint64& frame_now);//read planner data and change value
	void interpolate_function(const ma_uint64& now_frame);//check interpolation queue and interpolate
	sound_module* module; //module pointer
	
	song_data this_data;
	void before_faust_caster(void* input, void* out_left, void* out_right,const ma_uint32& frameCount);
	void after_faust_caster(void* in_left, void* in_right, void* output,const ma_uint32& frameCount);

	Faust_engine* album_engine;
	CURSOR* cursor;

	void album_init(const std::string& song_path);//init album
	void dynamic_memory_init();
	void dynamic_memory_uninit();
	float* process_memory;//float*AB_SIZE*2
	float* faust_before1;//float*AB_SIZE
	float* faust_before2;//float*AB_SIZE
	float* faust_after1;//float*AB_SIZE
	float* faust_after2;//float*AB_SIZE
	data_manager* DM;
public:

	Processor* pproc;
	float* sola_buffer;//float*AB_SIZE*4
	std::vector<inter_body> inter_queue;//queue for interpolation

	ALBUM(const int& channel,const int& albumID, Processor* p, data_manager& DM);
	~ALBUM();
	void PLAY();
	void STOP();
	void idle_process(ma_uint32 frameCount, float* main_buffer);
	void dj_process(ma_uint32 frameCount, float* main_buffer);
	//void daw_process(ma_uint32 frameCount, float* main_buffer);
	mix_data_set get_mixing_data();//mixing data getter function 
	inline Faust_engine* get_faust() { return album_engine; };
	inline CURSOR* get_cursor() { return cursor; };
	bool got_frames() { return this_data.got_frames; };
	bool has_owner = false;
/************************************************************************************************************************************************************************************************************************/



//
//public://----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------data_arrays & main_datas
//	ma_decoder_config music_conf;//decoder init configure data
//
//public://----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------checker datas
//	//bool is_processing = false;//if data is processing, it is true. use for safely deactivate process
//	bool is_SCRATCH = false;//activates scratch function
//	bool is_rev = false;//activates reverse play function
//
//public://----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------special functions
//
//private://----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------important functions
//
//	//data caster for compute faust function, ||WATCH_OUT--> input becomes silence
//	//data caster after compute faust function
//
//public://----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------Album APIs
//	//void null_process(ma_uint32 frameCount, float* main_buffer);//main process function
//
//
//
//
//public://----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------inner classes
//	class METRONOME {
//	public:
//		Engine_Main* pengine;
//		METRONOME(Engine_Main* pe);
//		~METRONOME();
//
//		struct metronome_data {
//			bool data_ready = false;
//			float* met_buffer;
//			float* temp_buffer;
//			ma_uint64 len;
//		}MET;
//		void compute_metronome_state(ma_uint64 now_frame, song_data SD, double flow_ratio);
//		void inject_metronome_in_buffer(void* main_buffer);
//	};
//
//public://----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------pointers
//	METRONOME* met_p;//metronome pointer
//	Engine_Main* pengine;//engine pointer
//
//private://---------------------------memory pool----------------
};


