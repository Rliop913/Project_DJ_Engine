#pragma once
#include <string>
//#include "Binary_Save_Load_Main.hpp"
enum dj_type {
	FILTER,
	EQ,
	DISTORTION,
	CONTROL,
	VOL,
	LOAD,
	UNLOAD,
	BEAT_MATCH,
	SOLA,
	DJ_COMP,
	INIT,
	ECHO,
	LFS,
	FLANGER,
	PHASER,
	TRANCE,
	PANNER,
	BATTLE_DJ,
	ALIVE,
	ROLL
};

enum dj_what {
	SINGLE,
	HIGH,
	MID,
	LOW,
	CUE,
	PLAY,
	PAUSE,
	TRIM,
	FADER,
	WARP,
	MASTER,
	RAW,
	SPIN,
	BSPIN,
	REV,
	SCRATCH,
	BSCRATCH
};
// struct DTAG {
// 	bool is_interpolate;
// 	dj_type type;
// 	int from;
// 	dj_what what;
// 	double first_value;
// 	double second_value;
// 	double third_value;
// 	int target;
// 	std::string first_str;
// 	std::string second_str;
// };
// struct DJBSL {
// 	DTAG djtag;
// 	unsigned int Sbar;
// 	unsigned int Sbeat;
// 	unsigned int Ssep;
// 	unsigned int Ebar;
// 	unsigned int Ebeat;
// 	unsigned int Esep;
// };