#include "sound_module.h"
#include <iostream>


sound_module::sound_module(Processor* first, ALBUM* second, Faust_engine* third) {
	processor = first;
	palbum = second;
	pfaust = third;
	tog_hash_filler();
}
void
sound_module::tog_hash_filler()
{
	tog_hash["EQ"] = tog_module::EQ;
	tog_hash["DISTORTION"] = tog_module::DISTORTION;
	tog_hash["FILTER"] = tog_module::FILTER;
	tog_hash["CONTROL"] = tog_module::CONTROL;
	tog_hash["VOL"] = tog_module::VOL;
	tog_hash["LOAD"] = tog_module::LOAD;
	tog_hash["UNLOAD"] = tog_module::UNLOAD;
	tog_hash["DJ_COMP"] = tog_module::DJ_COMP;
	tog_hash["BEAT_MATCH"] = tog_module::BEAT_MATCH;
	tog_hash["SOLA"] = tog_module::SOLA;
	tog_hash["ECHO"] = tog_module::ECHO;
	tog_hash["LFS"] = tog_module::LFS;
	tog_hash["FLANGER"] = tog_module::FLANGER;
	tog_hash["PHASER"] = tog_module::PHASER;
	tog_hash["TRANCE"] = tog_module::TRANCE;
	tog_hash["PANNER"] = tog_module::PANNER;
	tog_hash["BATTLE_DJ"] = tog_module::BATTLE_DJ;
	tog_hash["ROLL"] = tog_module::ROLL;
	tog_hash["ALIVE"] = tog_module::ALIVE;
}

void
sound_module::inter_hash_filler()
{
	inter_hash["EQ"] = inter_module::EQ;
	inter_hash["FILTER"] = inter_module::FILTER;
	inter_hash["DISTORTION"] = inter_module::DISTORTION;
	inter_hash["VOL"] = inter_module::VOL;
	inter_hash["SOLA"] = inter_module::SOLA;
	inter_hash["BATTLE_DJ"] = inter_module::BATTLE_DJ;
}



void
sound_module::toggle(tagables tag) {
	switch (tog_hash[tag.type]) {
	case tog_module::EQ:
		eq_tog(tag);
		break;
	case tog_module::DISTORTION:
		distortion_tog(tag);
		break;
	case tog_module::FILTER:
		filter_tog(tag);
		break;
	case tog_module::CONTROL:
		control_tog(tag);
		break;
	case tog_module::VOL:
		vol_tog(tag);
		break;
	case tog_module::LOAD:
		load_tog(tag);
		break;
	case tog_module::UNLOAD:
		unload_tog(tag);
		break;
	case tog_module::DJ_COMP:
		dj_comp_tog(tag);
		break;
	case tog_module::BEAT_MATCH:
		beat_match_tog(tag);
		break;
	case tog_module::SOLA:
		sola_tog(tag);
		break;
	case tog_module::ECHO:
		echo_tog(tag);
		break;
	case tog_module::LFS:
		LFS_tog(tag);
		break;
	case tog_module::FLANGER:
		flanger_tog(tag);
		break;
	case tog_module::PHASER:
		phaser_tog(tag);
		break;
	case tog_module::TRANCE:
		trance_tog(tag);
		break;
	case tog_module::PANNER:
		panner_tog(tag);
		break;
	case tog_module::BATTLE_DJ:
		battle_tog(tag);
		break;
	case tog_module::ROLL:
		roll_tog(tag);
		break;
	case tog_module::ALIVE:
		break;
	default:
		break;
	}
}

void
sound_module::eq_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);

	//Faust_engine* PF= processor->acc_faust(tag.for_who);//for self or other
	
	if (tag.what_ == "HIGH") {
		tag.first < -60.0 ?
			([PF](double val) {
			PF->EQ_high_sw(false); 
			PF->set_eq_high_value(val); 
		}(tag.first))
			:
			([PF](double val) {
			PF->EQ_high_sw(true); 
			PF->set_eq_high_value(val);
		}(tag.first));

	}
	else if (tag.what_ == "MID") {
				tag.first < -60.0 ?
				([PF](double val) {
				PF->EQ_mid_sw(false);
				PF->set_eq_mid_value(val);
				}(tag.first))
				:
				([PF](double val) {
				PF->EQ_mid_sw(true);
				PF->set_eq_mid_value(val);
				}(tag.first));

	}
	else if (tag.what_ == "LOW") {
				tag.first < -60.0 ?
				([PF](double val) {
				PF->EQ_low_sw(false);
				PF->set_eq_low_value(val);
				}(tag.first))
				:
				([PF](double val) {
				PF->EQ_low_sw(true);
				PF->set_eq_low_value(val);
				}(tag.first));

	}

}

void
sound_module::distortion_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	
	tag.first < 0 ?
		([PF](double val) {
		PF->_distortion_sw(false);
		PF->set_distortion_gain(val);
		}(tag.first))
		:
		([PF](double val) {
		PF->_distortion_sw(true);
		PF->set_distortion_gain(val);
		}(tag.first));
}

void
sound_module::filter_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	if (tag.what_ == "HIGH") {
		tag.first < 0 ?
			([PF](double val) {
			PF->filter_high_sw(false);
			}(tag.first))
			:
			([PF](double val) {
			PF->filter_high_sw(true);
			PF->set_filter_high_freq_value(val);
			}(tag.first));
	}
	else {//LOW
		tag.first < 0 ?
			([PF](double val) {
			PF->filter_low_sw(false);
			}(tag.first))
			:
			([PF](double val){
			PF->filter_low_sw(true);
			PF->set_filter_low_freq_value(int(val));
			}(tag.first));
	}
}

void
sound_module::control_tog(tagables tag) {
	ALBUM* PA;//for self or other
	tag.where_ != tag.for_who ? PA= processor->acc_album(tag.for_who): PA = palbum;
	if (tag.what_ == "CUE") {
		PA->get_cursor()->set_point(
			processor->raw_to_processed(
				processor->pBCE->calc_in_real_time(tag.first, tag.for_who)
			)
		);
	}
	else if (tag.what_ == "PLAY") {
		PA->PLAY();
	}
	else {//PAUSE
		PA->STOP();
	}
	
}
void
sound_module::vol_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	
	if (tag.what_ == "TRIM") {
		PF->set_trim(tag.first);
	}
	else {//fader
		PF->set_fader(tag.first);
	}
}
void
sound_module::load_tog(tagables tag) {
	processor->load_album(tag.str_first, tag.str_second, tag.for_who);
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
}

void
sound_module::unload_tog(tagables tag) {
	processor->unload_album(tag.for_who);
}

void
sound_module::dj_comp_tog(tagables tag) {
	processor->unload_album(tag.where_);
	
}

void
sound_module::sola_tog(tagables tag) {
	ALBUM* AP;//for self or other
	tag.where_ != tag.for_who ? AP = processor->acc_album(tag.for_who) : AP = palbum;
	if (tag.what_ == "MASTER") {
		AP->get_cursor()->set_speed(1.0, tag.first / 100.0);
	}
	else {//RAW
		AP->get_cursor()->set_speed(tag.first / 100.0, 1.0);
	}
}

void
sound_module::beat_match_tog(tagables tag) {//WARP MATCHING
	ALBUM* MA;//Master album
	MA = processor->acc_album(tag.for_who);
	ALBUM* ME;
	ME = palbum;
	ma_uint64 master_cursor=0;
	ma_uint64 my_cursor = 0;
	
	double my_speed = ME->get_cursor()->get_IOSR();
	double master_speed = MA->get_cursor()->get_IOSR();
	ME->get_cursor()->get_now_frame(my_cursor);
	MA->get_cursor()->get_now_frame(master_cursor);
	MA->got_frames() ? master_cursor -= ceil(441.0 / master_speed) : true;
	int match_time = my_cursor - tag.frame_in + (
		master_speed * (
			processor->raw_to_processed(processor->pBCE->calc_in_real_time(tag.first, tag.for_who)
			) - double(master_cursor))) / my_speed;
	my_cursor -= match_time;
	ME->get_cursor()->set_point(my_cursor);
}

void
sound_module::echo_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	tag.first < 0 ? ([PF](float dur, float feedback) {
			PF->_echo_sw(false);
			dur;
			feedback;
		}(float(tag.first), float(tag.second)))
		:
		([PF](float dur, float feedback) {
			PF->_echo_sw(true);
			PF->set_echo_dur_value(dur);
			PF->set_echo_feedback_value(feedback);
		}(float(tag.first), float(tag.second)));
}

void
sound_module::LFS_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	tag.first < 0 ?
		([PF](float bps) {
			PF->low_siren_sw(false);
		}(float(tag.first)))
		:
		([PF](float bps,int min_freq) {
			PF->low_siren_sw(true);
			PF->set_l_f_s_gain_min_freq(min_freq);
			PF->set_l_f_s_bps_value(bps);
		}(float(tag.first),int(tag.second)));
}

void
sound_module::flanger_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	tag.first < 0 ?
		([PF](float bps) {
			PF->_flanger_sw(false);
		}(float(tag.first)))
		:
		([PF](float bps,float gain) {
			PF->_flanger_sw(true);
			PF->set_flanger_bps_value(bps);
			PF->set_flanger_gain_value(gain);
		}(float(tag.first),float(tag.second)));
}

void
sound_module::phaser_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	tag.first < 0 ?
		([PF](float bps) {
			PF->_phaser_sw(false);
		}(float(tag.first)))
		:
		([PF](float bps, float gain) {
			PF->_phaser_sw(true);
			PF->set_phaser_bps_value(bps);
			PF->set_phaser_gain_value(gain);
		}(float(tag.first), float(tag.second)));
}

void
sound_module::trance_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	tag.first < 0 ?
		([PF](float bps) {
			PF->_trance_sw(false);
		}(float(tag.first)))
		:
		([PF](float bps,float gain) {
			PF->_trance_sw(true);
			PF->set_trance_gain(gain);
			PF->set_trance_bps(bps);
		}(float(tag.first),float(tag.second)));
}


void
sound_module::panner_tog(tagables tag) {
	Faust_engine* PF = processor->acc_faust(tag.for_who);//for self or other
	tag.first < 0 ?
		([PF](float bps) {
			PF->_panner_sw(false);
		}(float(tag.first)))
		:
		([PF](float bps,float gain) {
			PF->_panner_sw(true);
			PF->set_panner_gain(gain);
			PF->set_panner_bps(bps);
		}(float(tag.first),float(tag.second)));
}

void
sound_module::battle_tog(tagables tag) {
	CURSOR *CR = processor->acc_album(tag.for_who)->get_cursor();
	if (tag.what_ == "SCRATCH") {
		
		double SCR_entry_pos = processor->pBCE->calc_in_real_time(tag.first, tag.for_who);
		ma_uint32 ent_pos = processor->raw_to_processed(SCR_entry_pos);
		CR->set_point(ent_pos);
		ma_uint32 out_pos = processor->raw_to_processed(processor->pBCE->calc_in_real_time(std::stod(tag.str_first), tag.for_who));
		CR->temp_mv(true, tag.second, 1.0, out_pos - ent_pos);
	}
	else if (tag.what_ == "BSCRATCH") {
		double SCR_entry_pos = processor->pBCE->calc_in_real_time(tag.first, tag.for_who);
		ma_uint32 ent_pos = processor->raw_to_processed(SCR_entry_pos);
		CR->set_point(ent_pos);
		ma_uint32 out_pos = processor->raw_to_processed(processor->pBCE->calc_in_real_time(std::stod(tag.str_first), tag.for_who));
		CR->temp_mv(false, tag.second, 1.0, ent_pos-out_pos);
	}
}

void
sound_module::roll_tog(tagables tag) {
	ALBUM* AP = processor->acc_album(tag.for_who);
	//implementing
}




//--------------------------------------------------------------------------------//





void
sound_module::interpolate(tagables tag, ma_uint64 start_frame_,ma_uint64 end_frame_) {
	inter_body body;
	body.start_frame = start_frame_;
	body.end_frame = end_frame_;
	body.album_pointer = palbum;
	body.for_who_album_p = processor->acc_album(tag.for_who);
	switch (inter_hash[tag.type])
	{
	case inter_module::EQ:
		eq_inter(tag, body);
		break;
	case inter_module::FILTER:
		filter_inter(tag, body);
		break;
	case inter_module::DISTORTION:
		distortion_inter(tag, body);
		break;
	case inter_module::VOL:
		vol_inter(tag, body);
		break;
	case inter_module::SOLA:
		sola_inter(tag, body);
		break;
	case inter_module::BATTLE_DJ:
		battle_inter(tag, body);
		break;
	default:
		break;
	}
}


void
sound_module::eq_inter(tagables tag,inter_body body) {
	body.start_value = tag.first;
	body.end_value = tag.second;
	
	Faust_engine* PF = body.for_who_album_p->get_faust();
	ALBUM* AP = body.album_pointer;
	body.death_method = []() {
		;
	};
	if (tag.what_ == "HIGH") {
		body.sw_method =[PF](bool turn_on) {
			PF->EQ_high_sw(turn_on);

		};
		body.setter_method = [PF](float val) {
			PF->set_eq_high_value(val);
		};
		AP->inter_queue.push_back(body);
		
	}
	else if (tag.what_ == "MID") {
		body.sw_method = [PF](bool turn_on) {
			PF->EQ_mid_sw(turn_on);

		};
		body.setter_method = [PF](float val) {
			PF->set_eq_mid_value(val);
		};
		AP->inter_queue.push_back(body);
	}
	else if (tag.what_ == "LOW") {
		body.sw_method = [PF](bool turn_on) {
			PF->EQ_low_sw(turn_on);

		};
		body.setter_method = [PF](float val) {
			PF->set_eq_low_value(val);
		};
		AP->inter_queue.push_back(body);
	}
	else {
		return;
	}
}

void
sound_module::distortion_inter(tagables tag,inter_body body) {
	body.start_value = tag.first;
	body.end_value = tag.second;
	Faust_engine* PF = body.for_who_album_p->get_faust();
	body.sw_method = [PF](bool turn_on) {
		PF->_distortion_sw(turn_on);
	};
	body.setter_method = [PF](float val) {
		PF->set_distortion_gain(val);
	};
	body.death_method = []() {
		;
	};
	ALBUM* AP = body.album_pointer;
	AP->inter_queue.push_back(body);
}



void
sound_module::filter_inter(tagables tag,inter_body body) {
	Faust_engine* PF = body.for_who_album_p->get_faust();//for self or other
	
	body.start_value = tag.first;
	body.end_value = tag.second;
	body.death_method = []() {
		;
	};
	if (tag.what_ == "HIGH") {
		body.sw_method = [PF](bool turn_on) {
			PF->filter_high_sw(turn_on);
		};
		body.setter_method = [PF](float val) {
			PF->set_filter_high_freq_value(val);
		};
	}
	else {//LOW
		body.sw_method = [PF](bool turn_on) {
			PF->filter_low_sw(turn_on);
		};
		body.setter_method = [PF](float val) {
			PF->set_filter_low_freq_value(val);
		};
	}
	ALBUM* AP = body.album_pointer;
	AP->inter_queue.push_back(body);

}


void
sound_module::vol_inter(tagables tag,inter_body body) {
	Faust_engine* PF = body.for_who_album_p->get_faust();//for self or other
	body.start_value = tag.first;
	body.end_value = tag.second;
	body.sw_method = [](bool nothing) {
		nothing;
	};
	body.death_method = []() {
		;
	};
	if (tag.what_ == "TRIM") {
		body.setter_method = [PF](float val) {
			PF->set_trim(val);
		};
	}
	else {//FADER
		body.setter_method = [PF](float val) {
			PF->set_fader(val);
		};
	}
	ALBUM* AP = body.album_pointer;
	AP->inter_queue.push_back(body);
}


void
sound_module::sola_inter(tagables tag,inter_body body) {
	CURSOR *CR = body.for_who_album_p->get_cursor();//for self or other
	body.start_value = 1.0 + tag.first / 100.0;
	body.end_value = 1.0 + tag.second / 100.0;
	body.sw_method = [](bool nothing) {
		nothing;
	};
	body.death_method = []() {
		;
	};
	if (tag.what_ == "MASTER") {
		body.setter_method = [CR](double val) {
			CR->set_speed(1.0, val);
		};
	}
	else {//RAW
		body.setter_method = [CR](double val) {
			CR->set_speed(val, 1.0);
		};
	}

	body.for_who_album_p->inter_queue.push_back(body);
}

void
sound_module::battle_inter(tagables tag,inter_body body) {
	CURSOR* CR = body.for_who_album_p->get_cursor();
	
	if (tag.what_ == "SPIN") {
		CR->temp_mv(true, tag.first, 1.0, body.end_frame - body.start_frame);
	}
	if (tag.what_ == "BSPIN") {
		CR->temp_mv(false, tag.first, 1.0, body.start_frame- body.end_frame);

	}
	if (tag.what_ == "REV") {
		CR->set_dir(false);
		body.setter_method = [](double nothing) {
			nothing;
		};
		body.sw_method = [](bool nothing) {
			nothing;
		};
		body.death_method = [CR]() {
			CR->set_dir(true);
		};
		body.for_who_album_p->inter_queue.push_back(body);
	}
}