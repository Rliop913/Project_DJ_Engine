/* ------------------------------------------------------------
name: "ECHO"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -light -it -nvi -ct 1 -mapp -cn FilterFAUST -scn FilterVal -es 1 -exp10 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0 -vec -lv 0 -vs 64
------------------------------------------------------------ */

#ifndef  __FilterFAUST_H__
#define  __FilterFAUST_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

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


class FilterFAUST final : public FilterVal {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec0[2097152];
	int fRec0_idx;
	int fRec0_idx_save;
	int iRec1_perm[4];
	float fRec2[2097152];
	int fRec2_idx;
	int fRec2_idx_save;
	
 public:
	FilterFAUST() {
	}
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -light -it -nvi -ct 1 -mapp -cn FilterFAUST -scn FilterVal -es 1 -exp10 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0 -vec -lv 0 -vs 64");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("filename", "ECHO.dsp");
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
		m->declare("misceffects.lib/echo:author", "Romain Michon");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "ECHO");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 1e+01f * fConst0;
	}
	
	void instanceResetUserInterface() {
	}
	
	void instanceClear() {
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l0 = 0; l0 < 2097152; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		fRec0_idx = 0;
		fRec0_idx_save = 0;
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l1 = 0; l1 < 4; l1 = l1 + 1) {
			iRec1_perm[l1] = 0;
		}
		#pragma clang loop vectorize(enable) interleave(enable)
		for (int l2 = 0; l2 < 2097152; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		fRec2_idx = 0;
		fRec2_idx_save = 0;
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
		ui_interface->openVerticalBox("ECHO");
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* input1_ptr = inputs[1];
		FAUSTFLOAT* output0_ptr = outputs[0];
		FAUSTFLOAT* output1_ptr = outputs[1];
		int iSlow0 = int(std::min<float>(fConst1, std::max<float>(0.0f, fConst0 * EchoBps))) + 1;
		float fSlow1 = EchoFeedback;
		int iSlow2 = timerActive > 0;
		int iSlow3 = frames;
		int iRec1_tmp[68];
		int* iRec1 = &iRec1_tmp[4];
		int iSlow4 = selectInterpolator;
		int iSlow5 = iSlow4 >= 2;
		int iSlow6 = iSlow4 >= 1;
		float fSlow7 = 8.0f / float(iSlow3);
		float fZec0[64];
		int iZec1[64];
		int iSlow8 = v1;
		int iSlow9 = v2;
		int iSlow10 = v3;
		int iSlow11 = v4;
		int iSlow12 = v5;
		int iSlow13 = v6;
		int iSlow14 = v7;
		int iSlow15 = v8;
		int iZec2[64];
		int iZec3[64];
		int iZec4[64];
		float fZec5[64];
		float fZec6[64];
		float fZec7[64];
		float fZec8[64];
		int iSlow16 = iSlow4 >= 3;
		int iZec9[64];
		float fZec10[64];
		int iZec11[64];
		int iZec12[64];
		float fZec13[64];
		float fSlow17 = float(vZero);
		float fZec14[64];
		float fZec15[64];
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
				iRec1_tmp[j0] = iRec1_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec1[i] = ((iSlow2) ? 0 : std::min<int>(iSlow3, iRec1[i - 1] + 1));
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				iRec1_perm[j1] = iRec1_tmp[vsize + j1];
			}
			/* Vectorizable loop 1 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = fSlow7 * float(iRec1[i]);
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
				iZec2[i] = ((iZec1[i] >= 4) ? ((iZec1[i] >= 6) ? ((iZec1[i] >= 7) ? iSlow15 : iSlow14) : ((iZec1[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec1[i] >= 2) ? ((iZec1[i] >= 3) ? iSlow11 : iSlow10) : ((iZec1[i] >= 1) ? iSlow9 : iSlow8)));
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec4[i] = ((iZec3[i] >= 4) ? ((iZec3[i] >= 6) ? ((iZec3[i] >= 7) ? iSlow15 : iSlow14) : ((iZec3[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec3[i] >= 2) ? ((iZec3[i] >= 3) ? iSlow11 : iSlow10) : ((iZec3[i] >= 1) ? iSlow9 : iSlow8)));
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
				iZec12[i] = ((iZec11[i] >= 4) ? ((iZec11[i] >= 6) ? ((iZec11[i] >= 7) ? iSlow15 : iSlow14) : ((iZec11[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec11[i] >= 2) ? ((iZec11[i] >= 3) ? iSlow11 : iSlow10) : ((iZec11[i] >= 1) ? iSlow9 : iSlow8)));
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
				fZec10[i] = float(((iZec9[i] >= 4) ? ((iZec9[i] >= 6) ? ((iZec9[i] >= 7) ? iSlow15 : iSlow14) : ((iZec9[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec9[i] >= 2) ? ((iZec9[i] >= 3) ? iSlow11 : iSlow10) : ((iZec9[i] >= 1) ? iSlow9 : iSlow8))));
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
				fZec14[i] = std::max<float>(0.0f, std::min<float>(1.0f, ((iSlow5) ? ((iSlow16) ? fSlow17 : fZec8[i] + 0.5f * fZec7[i] * (float(iZec4[i] - iZec12[i]) + fZec7[i] * (2.0f * fZec13[i] + 4.0f * float(iZec4[i]) + fZec7[i] * (fZec10[i] + 3.0f * float(iZec2[i] - iZec4[i]) - fZec13[i]) - (5.0f * fZec8[i] + fZec10[i])))) : ((iSlow6) ? fZec8[i] + 0.5f * fZec5[i] * (1.0f - std::cos(3.1415927f * fZec7[i])) : fZec8[i] + fZec7[i] * fZec5[i]))));
			}
			/* Recursive loop 16 */
			/* Pre code */
			fRec0_idx = (fRec0_idx + fRec0_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[(i + fRec0_idx) & 2097151] = float(input0[i]) + fSlow1 * fRec0[(i + fRec0_idx - iSlow0) & 2097151];
			}
			/* Post code */
			fRec0_idx_save = vsize;
			/* Vectorizable loop 17 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec15[i] = 1.0f - fZec14[i];
			}
			/* Recursive loop 18 */
			/* Pre code */
			fRec2_idx = (fRec2_idx + fRec2_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec2[(i + fRec2_idx) & 2097151] = float(input1[i]) + fSlow1 * fRec2[(i + fRec2_idx - iSlow0) & 2097151];
			}
			/* Post code */
			fRec2_idx_save = vsize;
			/* Vectorizable loop 19 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fRec0[(i + fRec0_idx) & 2097151] * fZec14[i] + float(input0[i]) * fZec15[i]);
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(fRec2[(i + fRec2_idx) & 2097151] * fZec14[i] + float(input1[i]) * fZec15[i]);
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
				iRec1_tmp[j0] = iRec1_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec1[i] = ((iSlow2) ? 0 : std::min<int>(iSlow3, iRec1[i - 1] + 1));
			}
			/* Post code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				iRec1_perm[j1] = iRec1_tmp[vsize + j1];
			}
			/* Vectorizable loop 1 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = fSlow7 * float(iRec1[i]);
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
				iZec2[i] = ((iZec1[i] >= 4) ? ((iZec1[i] >= 6) ? ((iZec1[i] >= 7) ? iSlow15 : iSlow14) : ((iZec1[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec1[i] >= 2) ? ((iZec1[i] >= 3) ? iSlow11 : iSlow10) : ((iZec1[i] >= 1) ? iSlow9 : iSlow8)));
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				iZec4[i] = ((iZec3[i] >= 4) ? ((iZec3[i] >= 6) ? ((iZec3[i] >= 7) ? iSlow15 : iSlow14) : ((iZec3[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec3[i] >= 2) ? ((iZec3[i] >= 3) ? iSlow11 : iSlow10) : ((iZec3[i] >= 1) ? iSlow9 : iSlow8)));
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
				iZec12[i] = ((iZec11[i] >= 4) ? ((iZec11[i] >= 6) ? ((iZec11[i] >= 7) ? iSlow15 : iSlow14) : ((iZec11[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec11[i] >= 2) ? ((iZec11[i] >= 3) ? iSlow11 : iSlow10) : ((iZec11[i] >= 1) ? iSlow9 : iSlow8)));
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
				fZec10[i] = float(((iZec9[i] >= 4) ? ((iZec9[i] >= 6) ? ((iZec9[i] >= 7) ? iSlow15 : iSlow14) : ((iZec9[i] >= 5) ? iSlow13 : iSlow12)) : ((iZec9[i] >= 2) ? ((iZec9[i] >= 3) ? iSlow11 : iSlow10) : ((iZec9[i] >= 1) ? iSlow9 : iSlow8))));
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
				fZec14[i] = std::max<float>(0.0f, std::min<float>(1.0f, ((iSlow5) ? ((iSlow16) ? fSlow17 : fZec8[i] + 0.5f * fZec7[i] * (float(iZec4[i] - iZec12[i]) + fZec7[i] * (2.0f * fZec13[i] + 4.0f * float(iZec4[i]) + fZec7[i] * (fZec10[i] + 3.0f * float(iZec2[i] - iZec4[i]) - fZec13[i]) - (5.0f * fZec8[i] + fZec10[i])))) : ((iSlow6) ? fZec8[i] + 0.5f * fZec5[i] * (1.0f - std::cos(3.1415927f * fZec7[i])) : fZec8[i] + fZec7[i] * fZec5[i]))));
			}
			/* Recursive loop 16 */
			/* Pre code */
			fRec0_idx = (fRec0_idx + fRec0_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[(i + fRec0_idx) & 2097151] = float(input0[i]) + fSlow1 * fRec0[(i + fRec0_idx - iSlow0) & 2097151];
			}
			/* Post code */
			fRec0_idx_save = vsize;
			/* Vectorizable loop 17 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				fZec15[i] = 1.0f - fZec14[i];
			}
			/* Recursive loop 18 */
			/* Pre code */
			fRec2_idx = (fRec2_idx + fRec2_idx_save) & 2097151;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec2[(i + fRec2_idx) & 2097151] = float(input1[i]) + fSlow1 * fRec2[(i + fRec2_idx - iSlow0) & 2097151];
			}
			/* Post code */
			fRec2_idx_save = vsize;
			/* Vectorizable loop 19 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fRec0[(i + fRec0_idx) & 2097151] * fZec14[i] + float(input0[i]) * fZec15[i]);
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			#pragma clang loop vectorize(enable) interleave(enable)
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(fRec2[(i + fRec2_idx) & 2097151] * fZec14[i] + float(input1[i]) * fZec15[i]);
			}
		}
	}

};

#endif
