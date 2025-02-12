/* ------------------------------------------------------------
name: "FILTER"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -light -it -nvi -ct 1 -mapp -cn FilterFAUST -scn Filter_PDJE -es 1 -exp10 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0 -vec -lv 0 -vs 64
------------------------------------------------------------ */

#ifndef  __FilterFAUST_H__
#define  __FilterFAUST_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include "Faust_interpolate.hpp"
#include "filter.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS FilterFAUST
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float FilterFAUST_faustpower2_f(float value) {
	return value * value;
}

class FilterFAUST final : public Filter_PDJE {
	
 private:
	
	int iRec6_perm[4];
	int fSampleRate;
	float fConst0;
	float fRec5_perm[4];
	float fRec4_perm[4];
	float fRec3_perm[4];
	float fRec2_perm[4];
	float fRec1_perm[4];
	float fRec0_perm[4];
	float fRec11_perm[4];
	float fRec10_perm[4];
	float fRec9_perm[4];
	float fRec8_perm[4];
	float fRec7_perm[4];
	float fRec17_perm[4];
	float fRec16_perm[4];
	float fRec15_perm[4];
	float fRec14_perm[4];
	float fRec13_perm[4];
	float fRec12_perm[4];
	float fRec22_perm[4];
	float fRec21_perm[4];
	float fRec20_perm[4];
	float fRec19_perm[4];
	float fRec18_perm[4];
	
 public:
	FilterFAUST() {
	}
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -light -it -nvi -ct 1 -mapp -cn FilterFAUST -scn Filter_PDJE -es 1 -exp10 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0 -vec -lv 0 -vs 64");
		m->declare("filename", "FILTER.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("interpolators.lib/interpolate_cosine:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_cosine:licence", "MIT");
		m->declare("interpolators.lib/interpolate_cubic:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_cubic:licence", "MIT");
		m->declare("interpolators.lib/interpolate_linear:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_linear:licence", "MIT");
		m->declare("interpolators.lib/interpolator_cosine:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolator_cosine:licence", "MIT");
		m->declare("interpolators.lib/interpolator_cubic:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolator_cubic:licence", "MIT");
		m->declare("interpolators.lib/interpolator_four_points:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolator_four_points:licence", "MIT");
		m->declare("interpolators.lib/interpolator_linear:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolator_linear:licence", "MIT");
		m->declare("interpolators.lib/interpolator_two_points:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolator_two_points:licence", "MIT");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/version", "1.3.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "FILTER");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {}
	
	void staticInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = 3.1415927f / std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
	}
	
	void instanceResetUserInterface() {
	}
	
	void instanceClear() {
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l0 = 0; l0 < 4; l0 = l0 + 1) {
			iRec6_perm[l0] = 0;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l1 = 0; l1 < 4; l1 = l1 + 1) {
			fRec5_perm[l1] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l2 = 0; l2 < 4; l2 = l2 + 1) {
			fRec4_perm[l2] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l3 = 0; l3 < 4; l3 = l3 + 1) {
			fRec3_perm[l3] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l4 = 0; l4 < 4; l4 = l4 + 1) {
			fRec2_perm[l4] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l5 = 0; l5 < 4; l5 = l5 + 1) {
			fRec1_perm[l5] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l6 = 0; l6 < 4; l6 = l6 + 1) {
			fRec0_perm[l6] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l7 = 0; l7 < 4; l7 = l7 + 1) {
			fRec11_perm[l7] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l8 = 0; l8 < 4; l8 = l8 + 1) {
			fRec10_perm[l8] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l9 = 0; l9 < 4; l9 = l9 + 1) {
			fRec9_perm[l9] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l10 = 0; l10 < 4; l10 = l10 + 1) {
			fRec8_perm[l10] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l11 = 0; l11 < 4; l11 = l11 + 1) {
			fRec7_perm[l11] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l12 = 0; l12 < 4; l12 = l12 + 1) {
			fRec17_perm[l12] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l13 = 0; l13 < 4; l13 = l13 + 1) {
			fRec16_perm[l13] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l14 = 0; l14 < 4; l14 = l14 + 1) {
			fRec15_perm[l14] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l15 = 0; l15 < 4; l15 = l15 + 1) {
			fRec14_perm[l15] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l16 = 0; l16 < 4; l16 = l16 + 1) {
			fRec13_perm[l16] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l17 = 0; l17 < 4; l17 = l17 + 1) {
			fRec12_perm[l17] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l18 = 0; l18 < 4; l18 = l18 + 1) {
			fRec22_perm[l18] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l19 = 0; l19 < 4; l19 = l19 + 1) {
			fRec21_perm[l19] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l20 = 0; l20 < 4; l20 = l20 + 1) {
			fRec20_perm[l20] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l21 = 0; l21 < 4; l21 = l21 + 1) {
			fRec19_perm[l21] = 0.0f;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l22 = 0; l22 < 4; l22 = l22 + 1) {
			fRec18_perm[l22] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		staticInit(sample_rate);
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FilterFAUST* clone() {
		return new FilterFAUST();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("FILTER");
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* input1_ptr = inputs[1];
		FAUSTFLOAT* output0_ptr = outputs[0];
		FAUSTFLOAT* output1_ptr = outputs[1];
		int iSlow0 = timerActive > 0;
		int iSlow1 = frames;
		int iRec6_tmp[68];
		int* iRec6 = &iRec6_tmp[4];
		int iSlow2 = selectInterpolator;
		int iSlow3 = iSlow2 >= 2;
		int iSlow4 = iSlow2 >= 1;
		float fSlow5 = 8.0f / float(iSlow1);
		float fZec0[64];
		int iZec1[64];
		int iSlow6 = v1;
		int iSlow7 = v2;
		int iSlow8 = v3;
		int iSlow9 = v4;
		int iSlow10 = v5;
		int iSlow11 = v6;
		int iSlow12 = v7;
		int iSlow13 = v8;
		int iZec2[64];
		int iZec3[64];
		int iZec4[64];
		float fZec5[64];
		float fZec6[64];
		float fZec7[64];
		float fZec8[64];
		int iSlow14 = iSlow2 >= 3;
		int iZec9[64];
		float fZec10[64];
		int iZec11[64];
		int iZec12[64];
		float fZec13[64];
		float fSlow15 = float(vZero);
		float fZec14[64];
		float fZec15[64];
		float fZec16[64];
		float fZec17[64];
		float fZec18[64];
		float fZec19[64];
		float fRec5_tmp[68];
		float* fRec5 = &fRec5_tmp[4];
		float fZec20[64];
		float fZec21[64];
		float fZec22[64];
		float fZec23[64];
		float fRec4_tmp[68];
		float* fRec4 = &fRec4_tmp[4];
		float fZec24[64];
		float fZec25[64];
		float fZec26[64];
		float fRec3_tmp[68];
		float* fRec3 = &fRec3_tmp[4];
		float fZec27[64];
		float fZec28[64];
		float fZec29[64];
		float fRec2_tmp[68];
		float* fRec2 = &fRec2_tmp[4];
		float fZec30[64];
		float fZec31[64];
		float fZec32[64];
		float fRec1_tmp[68];
		float* fRec1 = &fRec1_tmp[4];
		float fZec33[64];
		float fZec34[64];
		float fZec35[64];
		float fRec0_tmp[68];
		float* fRec0 = &fRec0_tmp[4];
		float fRec11_tmp[68];
		float* fRec11 = &fRec11_tmp[4];
		float fRec10_tmp[68];
		float* fRec10 = &fRec10_tmp[4];
		float fRec9_tmp[68];
		float* fRec9 = &fRec9_tmp[4];
		float fRec8_tmp[68];
		float* fRec8 = &fRec8_tmp[4];
		float fRec7_tmp[68];
		float* fRec7 = &fRec7_tmp[4];
		int iSlow16 = HLswitch;
		float fZec36[64];
		float fRec17_tmp[68];
		float* fRec17 = &fRec17_tmp[4];
		float fZec37[64];
		float fRec16_tmp[68];
		float* fRec16 = &fRec16_tmp[4];
		float fRec15_tmp[68];
		float* fRec15 = &fRec15_tmp[4];
		float fRec14_tmp[68];
		float* fRec14 = &fRec14_tmp[4];
		float fRec13_tmp[68];
		float* fRec13 = &fRec13_tmp[4];
		float fRec12_tmp[68];
		float* fRec12 = &fRec12_tmp[4];
		float fRec22_tmp[68];
		float* fRec22 = &fRec22_tmp[4];
		float fRec21_tmp[68];
		float* fRec21 = &fRec21_tmp[4];
		float fRec20_tmp[68];
		float* fRec20 = &fRec20_tmp[4];
		float fRec19_tmp[68];
		float* fRec19 = &fRec19_tmp[4];
		float fRec18_tmp[68];
		float* fRec18 = &fRec18_tmp[4];
		int vindex = 0;
		/* Main loop */
		for (vindex = 0; vindex <= (count - 64); vindex = vindex + 64) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* input1 = &input1_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			FAUSTFLOAT* output1 = &output1_ptr[vindex];
			int vsize = 64;
			/* Recursive loop 0 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				iRec6_tmp[j0] = iRec6_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec6[i] = ((iSlow0) ? 0 : std::min<int>(iSlow1, iRec6[i - 1] + 1));
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				iRec6_perm[j1] = iRec6_tmp[vsize + j1];
			}
			/* Vectorizable loop 1 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = fSlow5 * float(iRec6[i]);
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec1[i] = int(fZec0[i]);
			}
			/* Vectorizable loop 3 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec3[i] = iZec1[i] + 1;
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec11[i] = iZec1[i] + -1;
			}
			/* Vectorizable loop 5 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec2[i] = ((iZec1[i] >= 4) ? ((iZec1[i] >= 6) ? ((iZec1[i] >= 7) ? iSlow13 : iSlow12) : ((iZec1[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec1[i] >= 2) ? ((iZec1[i] >= 3) ? iSlow9 : iSlow8) : ((iZec1[i] >= 1) ? iSlow7 : iSlow6)));
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec4[i] = ((iZec3[i] >= 4) ? ((iZec3[i] >= 6) ? ((iZec3[i] >= 7) ? iSlow13 : iSlow12) : ((iZec3[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec3[i] >= 2) ? ((iZec3[i] >= 3) ? iSlow9 : iSlow8) : ((iZec3[i] >= 1) ? iSlow7 : iSlow6)));
			}
			/* Vectorizable loop 7 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec6[i] = float(iZec1[i]);
			}
			/* Vectorizable loop 8 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec9[i] = iZec1[i] + 2;
			}
			/* Vectorizable loop 9 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec12[i] = ((iZec11[i] >= 4) ? ((iZec11[i] >= 6) ? ((iZec11[i] >= 7) ? iSlow13 : iSlow12) : ((iZec11[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec11[i] >= 2) ? ((iZec11[i] >= 3) ? iSlow9 : iSlow8) : ((iZec11[i] >= 1) ? iSlow7 : iSlow6)));
			}
			/* Vectorizable loop 10 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec5[i] = float(iZec4[i] - iZec2[i]);
			}
			/* Vectorizable loop 11 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec7[i] = fZec0[i] - ((fZec0[i] == fZec6[i]) ? fZec0[i] : ((fZec0[i] >= 0.0f) ? fZec6[i] : fZec6[i] + -1.0f));
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec8[i] = float(iZec2[i]);
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec10[i] = float(((iZec9[i] >= 4) ? ((iZec9[i] >= 6) ? ((iZec9[i] >= 7) ? iSlow13 : iSlow12) : ((iZec9[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec9[i] >= 2) ? ((iZec9[i] >= 3) ? iSlow9 : iSlow8) : ((iZec9[i] >= 1) ? iSlow7 : iSlow6))));
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = float(iZec12[i]);
			}
			/* Vectorizable loop 15 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = std::tan(fConst0 * std::max<float>(1.0f, std::min<float>(2.4e+04f, ((iSlow3) ? ((iSlow14) ? fSlow15 : fZec8[i] + 0.5f * fZec7[i] * (float(iZec4[i] - iZec12[i]) + fZec7[i] * (2.0f * fZec13[i] + 4.0f * float(iZec4[i]) + fZec7[i] * (fZec10[i] + 3.0f * float(iZec2[i] - iZec4[i]) - fZec13[i]) - (5.0f * fZec8[i] + fZec10[i])))) : ((iSlow4) ? fZec8[i] + 0.5f * fZec5[i] * (1.0f - std::cos(3.1415927f * fZec7[i])) : fZec8[i] + fZec7[i] * fZec5[i])))));
			}
			/* Vectorizable loop 16 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec15[i] = 1.0f / fZec14[i];
			}
			/* Vectorizable loop 17 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec17[i] = FilterFAUST_faustpower2_f(fZec14[i]);
			}
			/* Vectorizable loop 18 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec16[i] = (fZec15[i] + 1.9828898f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 19 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec18[i] = 1.0f - 1.0f / fZec17[i];
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec19[i] = (fZec15[i] + -1.9828898f) / fZec14[i] + 1.0f;
			}
			/* Recursive loop 21 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec5_tmp[j2] = fRec5_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec5[i] = float(input0[i]) - (fRec5[i - 2] * fZec19[i] + 2.0f * fRec5[i - 1] * fZec18[i]) / fZec16[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec5_perm[j3] = fRec5_tmp[vsize + j3];
			}
			/* Recursive loop 22 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j24 = 0; j24 < 4; j24 = j24 + 1) {
				fRec17_tmp[j24] = fRec17_perm[j24];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec17[i] = float(input1[i]) - (fZec19[i] * fRec17[i - 2] + 2.0f * fZec18[i] * fRec17[i - 1]) / fZec16[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j25 = 0; j25 < 4; j25 = j25 + 1) {
				fRec17_perm[j25] = fRec17_tmp[vsize + j25];
			}
			/* Vectorizable loop 23 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec20[i] = (fZec15[i] + 1.847759f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 24 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec21[i] = (fZec15[i] + -1.847759f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 25 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec22[i] = fZec17[i] * fZec16[i];
			}
			/* Vectorizable loop 26 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec23[i] = 2.0f * fRec5[i - 1];
			}
			/* Vectorizable loop 27 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec37[i] = 2.0f * fRec17[i - 1];
			}
			/* Recursive loop 28 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec4_tmp[j4] = fRec4_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec4[i] = (fRec5[i - 2] + (fRec5[i] - fZec23[i])) / fZec22[i] - (fRec4[i - 2] * fZec21[i] + 2.0f * fZec18[i] * fRec4[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec4_perm[j5] = fRec4_tmp[vsize + j5];
			}
			/* Vectorizable loop 29 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec24[i] = (fZec15[i] + 1.5867066f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 30 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec25[i] = (fZec15[i] + -1.5867066f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 31 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec26[i] = fZec17[i] * fZec20[i];
			}
			/* Recursive loop 32 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				fRec11_tmp[j14] = fRec11_perm[j14];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec11[i] = (fRec5[i - 2] + fRec5[i] + fZec23[i]) / fZec16[i] - (fZec21[i] * fRec11[i - 2] + 2.0f * fZec18[i] * fRec11[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				fRec11_perm[j15] = fRec11_tmp[vsize + j15];
			}
			/* Recursive loop 33 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j26 = 0; j26 < 4; j26 = j26 + 1) {
				fRec16_tmp[j26] = fRec16_perm[j26];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec16[i] = (fRec17[i - 2] + (fRec17[i] - fZec37[i])) / fZec22[i] - (fZec21[i] * fRec16[i - 2] + 2.0f * fZec18[i] * fRec16[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j27 = 0; j27 < 4; j27 = j27 + 1) {
				fRec16_perm[j27] = fRec16_tmp[vsize + j27];
			}
			/* Recursive loop 34 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j36 = 0; j36 < 4; j36 = j36 + 1) {
				fRec22_tmp[j36] = fRec22_perm[j36];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec22[i] = (fRec17[i - 2] + fRec17[i] + fZec37[i]) / fZec16[i] - (fZec21[i] * fRec22[i - 2] + 2.0f * fZec18[i] * fRec22[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j37 = 0; j37 < 4; j37 = j37 + 1) {
				fRec22_perm[j37] = fRec22_tmp[vsize + j37];
			}
			/* Recursive loop 35 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				fRec3_tmp[j6] = fRec3_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec3[i] = (fRec4[i - 2] + (fRec4[i] - 2.0f * fRec4[i - 1])) / fZec26[i] - (fRec3[i - 2] * fZec25[i] + 2.0f * fZec18[i] * fRec3[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				fRec3_perm[j7] = fRec3_tmp[vsize + j7];
			}
			/* Vectorizable loop 36 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec27[i] = (fZec15[i] + 1.2175229f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 37 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec28[i] = (fZec15[i] + -1.2175229f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 38 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec29[i] = fZec17[i] * fZec24[i];
			}
			/* Recursive loop 39 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				fRec10_tmp[j16] = fRec10_perm[j16];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec10[i] = (fRec11[i - 2] + fRec11[i] + 2.0f * fRec11[i - 1]) / fZec20[i] - (fZec25[i] * fRec10[i - 2] + 2.0f * fZec18[i] * fRec10[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				fRec10_perm[j17] = fRec10_tmp[vsize + j17];
			}
			/* Recursive loop 40 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j28 = 0; j28 < 4; j28 = j28 + 1) {
				fRec15_tmp[j28] = fRec15_perm[j28];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec15[i] = (fRec16[i - 2] + (fRec16[i] - 2.0f * fRec16[i - 1])) / fZec26[i] - (fZec25[i] * fRec15[i - 2] + 2.0f * fZec18[i] * fRec15[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j29 = 0; j29 < 4; j29 = j29 + 1) {
				fRec15_perm[j29] = fRec15_tmp[vsize + j29];
			}
			/* Recursive loop 41 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j38 = 0; j38 < 4; j38 = j38 + 1) {
				fRec21_tmp[j38] = fRec21_perm[j38];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec21[i] = (fRec22[i - 2] + fRec22[i] + 2.0f * fRec22[i - 1]) / fZec20[i] - (fZec25[i] * fRec21[i - 2] + 2.0f * fZec18[i] * fRec21[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j39 = 0; j39 < 4; j39 = j39 + 1) {
				fRec21_perm[j39] = fRec21_tmp[vsize + j39];
			}
			/* Recursive loop 42 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec2_tmp[j8] = fRec2_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec2[i] = (fRec3[i - 2] + (fRec3[i] - 2.0f * fRec3[i - 1])) / fZec29[i] - (fRec2[i - 2] * fZec28[i] + 2.0f * fZec18[i] * fRec2[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec2_perm[j9] = fRec2_tmp[vsize + j9];
			}
			/* Vectorizable loop 43 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec30[i] = (fZec15[i] + 0.76536685f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 44 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec31[i] = (fZec15[i] + -0.76536685f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 45 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec32[i] = fZec17[i] * fZec27[i];
			}
			/* Recursive loop 46 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec9_tmp[j18] = fRec9_perm[j18];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec9[i] = (fRec10[i - 2] + fRec10[i] + 2.0f * fRec10[i - 1]) / fZec24[i] - (fZec28[i] * fRec9[i - 2] + 2.0f * fZec18[i] * fRec9[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec9_perm[j19] = fRec9_tmp[vsize + j19];
			}
			/* Recursive loop 47 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j30 = 0; j30 < 4; j30 = j30 + 1) {
				fRec14_tmp[j30] = fRec14_perm[j30];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec14[i] = (fRec15[i - 2] + (fRec15[i] - 2.0f * fRec15[i - 1])) / fZec29[i] - (fZec28[i] * fRec14[i - 2] + 2.0f * fZec18[i] * fRec14[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j31 = 0; j31 < 4; j31 = j31 + 1) {
				fRec14_perm[j31] = fRec14_tmp[vsize + j31];
			}
			/* Recursive loop 48 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j40 = 0; j40 < 4; j40 = j40 + 1) {
				fRec20_tmp[j40] = fRec20_perm[j40];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec20[i] = (fRec21[i - 2] + fRec21[i] + 2.0f * fRec21[i - 1]) / fZec24[i] - (fZec28[i] * fRec20[i - 2] + 2.0f * fZec18[i] * fRec20[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j41 = 0; j41 < 4; j41 = j41 + 1) {
				fRec20_perm[j41] = fRec20_tmp[vsize + j41];
			}
			/* Recursive loop 49 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec1_tmp[j10] = fRec1_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec1[i] = (fRec2[i - 2] + (fRec2[i] - 2.0f * fRec2[i - 1])) / fZec32[i] - (fRec1[i - 2] * fZec31[i] + 2.0f * fZec18[i] * fRec1[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec1_perm[j11] = fRec1_tmp[vsize + j11];
			}
			/* Vectorizable loop 50 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec33[i] = (fZec15[i] + 0.26105237f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 51 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec34[i] = (fZec15[i] + -0.26105237f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 52 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec35[i] = fZec17[i] * fZec30[i];
			}
			/* Recursive loop 53 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fRec8_tmp[j20] = fRec8_perm[j20];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec8[i] = (fRec9[i - 2] + fRec9[i] + 2.0f * fRec9[i - 1]) / fZec27[i] - (fZec31[i] * fRec8[i - 2] + 2.0f * fZec18[i] * fRec8[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fRec8_perm[j21] = fRec8_tmp[vsize + j21];
			}
			/* Recursive loop 54 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j32 = 0; j32 < 4; j32 = j32 + 1) {
				fRec13_tmp[j32] = fRec13_perm[j32];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec13[i] = (fRec14[i - 2] + (fRec14[i] - 2.0f * fRec14[i - 1])) / fZec32[i] - (fZec31[i] * fRec13[i - 2] + 2.0f * fZec18[i] * fRec13[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j33 = 0; j33 < 4; j33 = j33 + 1) {
				fRec13_perm[j33] = fRec13_tmp[vsize + j33];
			}
			/* Recursive loop 55 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j42 = 0; j42 < 4; j42 = j42 + 1) {
				fRec19_tmp[j42] = fRec19_perm[j42];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec19[i] = (fRec20[i - 2] + fRec20[i] + 2.0f * fRec20[i - 1]) / fZec27[i] - (fZec31[i] * fRec19[i - 2] + 2.0f * fZec18[i] * fRec19[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j43 = 0; j43 < 4; j43 = j43 + 1) {
				fRec19_perm[j43] = fRec19_tmp[vsize + j43];
			}
			/* Recursive loop 56 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				fRec0_tmp[j12] = fRec0_perm[j12];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[i] = (fRec1[i - 2] + (fRec1[i] - 2.0f * fRec1[i - 1])) / fZec35[i] - (fRec0[i - 2] * fZec34[i] + 2.0f * fZec18[i] * fRec0[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				fRec0_perm[j13] = fRec0_tmp[vsize + j13];
			}
			/* Recursive loop 57 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec7_tmp[j22] = fRec7_perm[j22];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec7[i] = (fRec8[i - 2] + fRec8[i] + 2.0f * fRec8[i - 1]) / fZec30[i] - (fZec34[i] * fRec7[i - 2] + 2.0f * fZec18[i] * fRec7[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec7_perm[j23] = fRec7_tmp[vsize + j23];
			}
			/* Vectorizable loop 58 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec36[i] = fZec17[i] * fZec33[i];
			}
			/* Recursive loop 59 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j34 = 0; j34 < 4; j34 = j34 + 1) {
				fRec12_tmp[j34] = fRec12_perm[j34];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec12[i] = (fRec13[i - 2] + (fRec13[i] - 2.0f * fRec13[i - 1])) / fZec35[i] - (fZec34[i] * fRec12[i - 2] + 2.0f * fZec18[i] * fRec12[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j35 = 0; j35 < 4; j35 = j35 + 1) {
				fRec12_perm[j35] = fRec12_tmp[vsize + j35];
			}
			/* Recursive loop 60 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j44 = 0; j44 < 4; j44 = j44 + 1) {
				fRec18_tmp[j44] = fRec18_perm[j44];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec18[i] = (fRec19[i - 2] + fRec19[i] + 2.0f * fRec19[i - 1]) / fZec30[i] - (fZec34[i] * fRec18[i - 2] + 2.0f * fZec18[i] * fRec18[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j45 = 0; j45 < 4; j45 = j45 + 1) {
				fRec18_perm[j45] = fRec18_tmp[vsize + j45];
			}
			/* Vectorizable loop 61 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(((iSlow16) ? (fRec7[i - 2] + fRec7[i] + 2.0f * fRec7[i - 1]) / fZec33[i] : (fRec0[i] + fRec0[i - 2] - 2.0f * fRec0[i - 1]) / fZec36[i]));
			}
			/* Vectorizable loop 62 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(((iSlow16) ? (fRec18[i - 2] + fRec18[i] + 2.0f * fRec18[i - 1]) / fZec33[i] : (fRec12[i] + fRec12[i - 2] - 2.0f * fRec12[i - 1]) / fZec36[i]));
			}
		}
		/* Remaining frames */
		if (vindex < count) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* input1 = &input1_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			FAUSTFLOAT* output1 = &output1_ptr[vindex];
			int vsize = count - vindex;
			/* Recursive loop 0 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				iRec6_tmp[j0] = iRec6_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec6[i] = ((iSlow0) ? 0 : std::min<int>(iSlow1, iRec6[i - 1] + 1));
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				iRec6_perm[j1] = iRec6_tmp[vsize + j1];
			}
			/* Vectorizable loop 1 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = fSlow5 * float(iRec6[i]);
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec1[i] = int(fZec0[i]);
			}
			/* Vectorizable loop 3 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec3[i] = iZec1[i] + 1;
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec11[i] = iZec1[i] + -1;
			}
			/* Vectorizable loop 5 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec2[i] = ((iZec1[i] >= 4) ? ((iZec1[i] >= 6) ? ((iZec1[i] >= 7) ? iSlow13 : iSlow12) : ((iZec1[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec1[i] >= 2) ? ((iZec1[i] >= 3) ? iSlow9 : iSlow8) : ((iZec1[i] >= 1) ? iSlow7 : iSlow6)));
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec4[i] = ((iZec3[i] >= 4) ? ((iZec3[i] >= 6) ? ((iZec3[i] >= 7) ? iSlow13 : iSlow12) : ((iZec3[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec3[i] >= 2) ? ((iZec3[i] >= 3) ? iSlow9 : iSlow8) : ((iZec3[i] >= 1) ? iSlow7 : iSlow6)));
			}
			/* Vectorizable loop 7 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec6[i] = float(iZec1[i]);
			}
			/* Vectorizable loop 8 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec9[i] = iZec1[i] + 2;
			}
			/* Vectorizable loop 9 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec12[i] = ((iZec11[i] >= 4) ? ((iZec11[i] >= 6) ? ((iZec11[i] >= 7) ? iSlow13 : iSlow12) : ((iZec11[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec11[i] >= 2) ? ((iZec11[i] >= 3) ? iSlow9 : iSlow8) : ((iZec11[i] >= 1) ? iSlow7 : iSlow6)));
			}
			/* Vectorizable loop 10 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec5[i] = float(iZec4[i] - iZec2[i]);
			}
			/* Vectorizable loop 11 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec7[i] = fZec0[i] - ((fZec0[i] == fZec6[i]) ? fZec0[i] : ((fZec0[i] >= 0.0f) ? fZec6[i] : fZec6[i] + -1.0f));
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec8[i] = float(iZec2[i]);
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec10[i] = float(((iZec9[i] >= 4) ? ((iZec9[i] >= 6) ? ((iZec9[i] >= 7) ? iSlow13 : iSlow12) : ((iZec9[i] >= 5) ? iSlow11 : iSlow10)) : ((iZec9[i] >= 2) ? ((iZec9[i] >= 3) ? iSlow9 : iSlow8) : ((iZec9[i] >= 1) ? iSlow7 : iSlow6))));
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = float(iZec12[i]);
			}
			/* Vectorizable loop 15 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = std::tan(fConst0 * std::max<float>(1.0f, std::min<float>(2.4e+04f, ((iSlow3) ? ((iSlow14) ? fSlow15 : fZec8[i] + 0.5f * fZec7[i] * (float(iZec4[i] - iZec12[i]) + fZec7[i] * (2.0f * fZec13[i] + 4.0f * float(iZec4[i]) + fZec7[i] * (fZec10[i] + 3.0f * float(iZec2[i] - iZec4[i]) - fZec13[i]) - (5.0f * fZec8[i] + fZec10[i])))) : ((iSlow4) ? fZec8[i] + 0.5f * fZec5[i] * (1.0f - std::cos(3.1415927f * fZec7[i])) : fZec8[i] + fZec7[i] * fZec5[i])))));
			}
			/* Vectorizable loop 16 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec15[i] = 1.0f / fZec14[i];
			}
			/* Vectorizable loop 17 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec17[i] = FilterFAUST_faustpower2_f(fZec14[i]);
			}
			/* Vectorizable loop 18 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec16[i] = (fZec15[i] + 1.9828898f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 19 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec18[i] = 1.0f - 1.0f / fZec17[i];
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec19[i] = (fZec15[i] + -1.9828898f) / fZec14[i] + 1.0f;
			}
			/* Recursive loop 21 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec5_tmp[j2] = fRec5_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec5[i] = float(input0[i]) - (fRec5[i - 2] * fZec19[i] + 2.0f * fRec5[i - 1] * fZec18[i]) / fZec16[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec5_perm[j3] = fRec5_tmp[vsize + j3];
			}
			/* Recursive loop 22 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j24 = 0; j24 < 4; j24 = j24 + 1) {
				fRec17_tmp[j24] = fRec17_perm[j24];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec17[i] = float(input1[i]) - (fZec19[i] * fRec17[i - 2] + 2.0f * fZec18[i] * fRec17[i - 1]) / fZec16[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j25 = 0; j25 < 4; j25 = j25 + 1) {
				fRec17_perm[j25] = fRec17_tmp[vsize + j25];
			}
			/* Vectorizable loop 23 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec20[i] = (fZec15[i] + 1.847759f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 24 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec21[i] = (fZec15[i] + -1.847759f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 25 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec22[i] = fZec17[i] * fZec16[i];
			}
			/* Vectorizable loop 26 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec23[i] = 2.0f * fRec5[i - 1];
			}
			/* Vectorizable loop 27 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec37[i] = 2.0f * fRec17[i - 1];
			}
			/* Recursive loop 28 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec4_tmp[j4] = fRec4_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec4[i] = (fRec5[i - 2] + (fRec5[i] - fZec23[i])) / fZec22[i] - (fRec4[i - 2] * fZec21[i] + 2.0f * fZec18[i] * fRec4[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec4_perm[j5] = fRec4_tmp[vsize + j5];
			}
			/* Vectorizable loop 29 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec24[i] = (fZec15[i] + 1.5867066f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 30 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec25[i] = (fZec15[i] + -1.5867066f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 31 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec26[i] = fZec17[i] * fZec20[i];
			}
			/* Recursive loop 32 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				fRec11_tmp[j14] = fRec11_perm[j14];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec11[i] = (fRec5[i - 2] + fRec5[i] + fZec23[i]) / fZec16[i] - (fZec21[i] * fRec11[i - 2] + 2.0f * fZec18[i] * fRec11[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				fRec11_perm[j15] = fRec11_tmp[vsize + j15];
			}
			/* Recursive loop 33 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j26 = 0; j26 < 4; j26 = j26 + 1) {
				fRec16_tmp[j26] = fRec16_perm[j26];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec16[i] = (fRec17[i - 2] + (fRec17[i] - fZec37[i])) / fZec22[i] - (fZec21[i] * fRec16[i - 2] + 2.0f * fZec18[i] * fRec16[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j27 = 0; j27 < 4; j27 = j27 + 1) {
				fRec16_perm[j27] = fRec16_tmp[vsize + j27];
			}
			/* Recursive loop 34 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j36 = 0; j36 < 4; j36 = j36 + 1) {
				fRec22_tmp[j36] = fRec22_perm[j36];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec22[i] = (fRec17[i - 2] + fRec17[i] + fZec37[i]) / fZec16[i] - (fZec21[i] * fRec22[i - 2] + 2.0f * fZec18[i] * fRec22[i - 1]) / fZec20[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j37 = 0; j37 < 4; j37 = j37 + 1) {
				fRec22_perm[j37] = fRec22_tmp[vsize + j37];
			}
			/* Recursive loop 35 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				fRec3_tmp[j6] = fRec3_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec3[i] = (fRec4[i - 2] + (fRec4[i] - 2.0f * fRec4[i - 1])) / fZec26[i] - (fRec3[i - 2] * fZec25[i] + 2.0f * fZec18[i] * fRec3[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				fRec3_perm[j7] = fRec3_tmp[vsize + j7];
			}
			/* Vectorizable loop 36 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec27[i] = (fZec15[i] + 1.2175229f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 37 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec28[i] = (fZec15[i] + -1.2175229f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 38 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec29[i] = fZec17[i] * fZec24[i];
			}
			/* Recursive loop 39 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				fRec10_tmp[j16] = fRec10_perm[j16];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec10[i] = (fRec11[i - 2] + fRec11[i] + 2.0f * fRec11[i - 1]) / fZec20[i] - (fZec25[i] * fRec10[i - 2] + 2.0f * fZec18[i] * fRec10[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				fRec10_perm[j17] = fRec10_tmp[vsize + j17];
			}
			/* Recursive loop 40 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j28 = 0; j28 < 4; j28 = j28 + 1) {
				fRec15_tmp[j28] = fRec15_perm[j28];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec15[i] = (fRec16[i - 2] + (fRec16[i] - 2.0f * fRec16[i - 1])) / fZec26[i] - (fZec25[i] * fRec15[i - 2] + 2.0f * fZec18[i] * fRec15[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j29 = 0; j29 < 4; j29 = j29 + 1) {
				fRec15_perm[j29] = fRec15_tmp[vsize + j29];
			}
			/* Recursive loop 41 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j38 = 0; j38 < 4; j38 = j38 + 1) {
				fRec21_tmp[j38] = fRec21_perm[j38];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec21[i] = (fRec22[i - 2] + fRec22[i] + 2.0f * fRec22[i - 1]) / fZec20[i] - (fZec25[i] * fRec21[i - 2] + 2.0f * fZec18[i] * fRec21[i - 1]) / fZec24[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j39 = 0; j39 < 4; j39 = j39 + 1) {
				fRec21_perm[j39] = fRec21_tmp[vsize + j39];
			}
			/* Recursive loop 42 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec2_tmp[j8] = fRec2_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec2[i] = (fRec3[i - 2] + (fRec3[i] - 2.0f * fRec3[i - 1])) / fZec29[i] - (fRec2[i - 2] * fZec28[i] + 2.0f * fZec18[i] * fRec2[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec2_perm[j9] = fRec2_tmp[vsize + j9];
			}
			/* Vectorizable loop 43 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec30[i] = (fZec15[i] + 0.76536685f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 44 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec31[i] = (fZec15[i] + -0.76536685f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 45 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec32[i] = fZec17[i] * fZec27[i];
			}
			/* Recursive loop 46 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec9_tmp[j18] = fRec9_perm[j18];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec9[i] = (fRec10[i - 2] + fRec10[i] + 2.0f * fRec10[i - 1]) / fZec24[i] - (fZec28[i] * fRec9[i - 2] + 2.0f * fZec18[i] * fRec9[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec9_perm[j19] = fRec9_tmp[vsize + j19];
			}
			/* Recursive loop 47 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j30 = 0; j30 < 4; j30 = j30 + 1) {
				fRec14_tmp[j30] = fRec14_perm[j30];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec14[i] = (fRec15[i - 2] + (fRec15[i] - 2.0f * fRec15[i - 1])) / fZec29[i] - (fZec28[i] * fRec14[i - 2] + 2.0f * fZec18[i] * fRec14[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j31 = 0; j31 < 4; j31 = j31 + 1) {
				fRec14_perm[j31] = fRec14_tmp[vsize + j31];
			}
			/* Recursive loop 48 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j40 = 0; j40 < 4; j40 = j40 + 1) {
				fRec20_tmp[j40] = fRec20_perm[j40];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec20[i] = (fRec21[i - 2] + fRec21[i] + 2.0f * fRec21[i - 1]) / fZec24[i] - (fZec28[i] * fRec20[i - 2] + 2.0f * fZec18[i] * fRec20[i - 1]) / fZec27[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j41 = 0; j41 < 4; j41 = j41 + 1) {
				fRec20_perm[j41] = fRec20_tmp[vsize + j41];
			}
			/* Recursive loop 49 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec1_tmp[j10] = fRec1_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec1[i] = (fRec2[i - 2] + (fRec2[i] - 2.0f * fRec2[i - 1])) / fZec32[i] - (fRec1[i - 2] * fZec31[i] + 2.0f * fZec18[i] * fRec1[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec1_perm[j11] = fRec1_tmp[vsize + j11];
			}
			/* Vectorizable loop 50 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec33[i] = (fZec15[i] + 0.26105237f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 51 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec34[i] = (fZec15[i] + -0.26105237f) / fZec14[i] + 1.0f;
			}
			/* Vectorizable loop 52 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec35[i] = fZec17[i] * fZec30[i];
			}
			/* Recursive loop 53 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fRec8_tmp[j20] = fRec8_perm[j20];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec8[i] = (fRec9[i - 2] + fRec9[i] + 2.0f * fRec9[i - 1]) / fZec27[i] - (fZec31[i] * fRec8[i - 2] + 2.0f * fZec18[i] * fRec8[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fRec8_perm[j21] = fRec8_tmp[vsize + j21];
			}
			/* Recursive loop 54 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j32 = 0; j32 < 4; j32 = j32 + 1) {
				fRec13_tmp[j32] = fRec13_perm[j32];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec13[i] = (fRec14[i - 2] + (fRec14[i] - 2.0f * fRec14[i - 1])) / fZec32[i] - (fZec31[i] * fRec13[i - 2] + 2.0f * fZec18[i] * fRec13[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j33 = 0; j33 < 4; j33 = j33 + 1) {
				fRec13_perm[j33] = fRec13_tmp[vsize + j33];
			}
			/* Recursive loop 55 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j42 = 0; j42 < 4; j42 = j42 + 1) {
				fRec19_tmp[j42] = fRec19_perm[j42];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec19[i] = (fRec20[i - 2] + fRec20[i] + 2.0f * fRec20[i - 1]) / fZec27[i] - (fZec31[i] * fRec19[i - 2] + 2.0f * fZec18[i] * fRec19[i - 1]) / fZec30[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j43 = 0; j43 < 4; j43 = j43 + 1) {
				fRec19_perm[j43] = fRec19_tmp[vsize + j43];
			}
			/* Recursive loop 56 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				fRec0_tmp[j12] = fRec0_perm[j12];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[i] = (fRec1[i - 2] + (fRec1[i] - 2.0f * fRec1[i - 1])) / fZec35[i] - (fRec0[i - 2] * fZec34[i] + 2.0f * fZec18[i] * fRec0[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				fRec0_perm[j13] = fRec0_tmp[vsize + j13];
			}
			/* Recursive loop 57 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec7_tmp[j22] = fRec7_perm[j22];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec7[i] = (fRec8[i - 2] + fRec8[i] + 2.0f * fRec8[i - 1]) / fZec30[i] - (fZec34[i] * fRec7[i - 2] + 2.0f * fZec18[i] * fRec7[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec7_perm[j23] = fRec7_tmp[vsize + j23];
			}
			/* Vectorizable loop 58 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec36[i] = fZec17[i] * fZec33[i];
			}
			/* Recursive loop 59 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j34 = 0; j34 < 4; j34 = j34 + 1) {
				fRec12_tmp[j34] = fRec12_perm[j34];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec12[i] = (fRec13[i - 2] + (fRec13[i] - 2.0f * fRec13[i - 1])) / fZec35[i] - (fZec34[i] * fRec12[i - 2] + 2.0f * fZec18[i] * fRec12[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j35 = 0; j35 < 4; j35 = j35 + 1) {
				fRec12_perm[j35] = fRec12_tmp[vsize + j35];
			}
			/* Recursive loop 60 */
			/* Pre code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j44 = 0; j44 < 4; j44 = j44 + 1) {
				fRec18_tmp[j44] = fRec18_perm[j44];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec18[i] = (fRec19[i - 2] + fRec19[i] + 2.0f * fRec19[i - 1]) / fZec30[i] - (fZec34[i] * fRec18[i - 2] + 2.0f * fZec18[i] * fRec18[i - 1]) / fZec33[i];
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j45 = 0; j45 < 4; j45 = j45 + 1) {
				fRec18_perm[j45] = fRec18_tmp[vsize + j45];
			}
			/* Vectorizable loop 61 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(((iSlow16) ? (fRec7[i - 2] + fRec7[i] + 2.0f * fRec7[i - 1]) / fZec33[i] : (fRec0[i] + fRec0[i - 2] - 2.0f * fRec0[i - 1]) / fZec36[i]));
			}
			/* Vectorizable loop 62 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(((iSlow16) ? (fRec18[i - 2] + fRec18[i] + 2.0f * fRec18[i - 1]) / fZec33[i] : (fRec12[i] + fRec12[i - 2] - 2.0f * fRec12[i - 1]) / fZec36[i]));
			}
		}
	}

};

#endif
