/* ------------------------------------------------------------
name: "DISTORTION"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -light -it -nvi -ct 1 -mapp -cn DistortionFAUST -scn FaustInterpolate -es 1 -exp10 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0 -vec -lv 0 -vs 32
------------------------------------------------------------ */

#ifndef  __DistortionFAUST_H__
#define  __DistortionFAUST_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include "Faust_interpolate.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS DistortionFAUST
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

static float DistortionFAUST_faustpower2_f(float value) {
	return value * value;
}

class DistortionFAUST final : public FaustInterpolate {
	
 private:
	
	int iRec0_perm[4];
	int fSampleRate;
	
 public:
	DistortionFAUST() {
	}
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -light -it -nvi -ct 1 -mapp -cn DistortionFAUST -scn FaustInterpolate -es 1 -exp10 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0 -vec -lv 0 -vs 32");
		m->declare("filename", "DISTORTION.dsp");
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
		m->declare("misceffects.lib/cubicnl:author", "Julius O. Smith III");
		m->declare("misceffects.lib/cubicnl:license", "STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "DISTORTION");
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
	}
	
	void instanceResetUserInterface() {
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 4; l0 = l0 + 1) {
			iRec0_perm[l0] = 0;
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
	
	DistortionFAUST* clone() {
		return new DistortionFAUST();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DISTORTION");
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* input1_ptr = inputs[1];
		FAUSTFLOAT* output0_ptr = outputs[0];
		FAUSTFLOAT* output1_ptr = outputs[1];
		int iSlow0 = timerActive > 0;
		int iSlow1 = frames;
		int iRec0_tmp[36];
		int* iRec0 = &iRec0_tmp[4];
		int iSlow2 = selectInterpolator;
		int iSlow3 = iSlow2 >= 2;
		int iSlow4 = iSlow2 >= 1;
		float fSlow5 = 8.0f / float(iSlow1);
		float fZec0[32];
		int iZec1[32];
		float fSlow6 = v1;
		float fSlow7 = v2;
		float fSlow8 = v3;
		float fSlow9 = v4;
		float fSlow10 = v5;
		float fSlow11 = v6;
		float fSlow12 = v7;
		float fSlow13 = v8;
		float fZec2[32];
		int iZec3[32];
		float fZec4[32];
		float fZec5[32];
		float fZec6[32];
		float fZec7[32];
		int iSlow14 = iSlow2 >= 3;
		int iZec8[32];
		float fZec9[32];
		int iZec10[32];
		float fZec11[32];
		float fSlow15 = vZero;
		float fZec12[32];
		float fZec13[32];
		float fZec14[32];
		int vindex = 0;
		/* Main loop */
		for (vindex = 0; vindex <= (count - 32); vindex = vindex + 32) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* input1 = &input1_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			FAUSTFLOAT* output1 = &output1_ptr[vindex];
			int vsize = 32;
			/* Recursive loop 0 */
			/* Pre code */
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				iRec0_tmp[j0] = iRec0_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec0[i] = ((iSlow0) ? 0 : std::min<int>(iSlow1, iRec0[i - 1] + 1));
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				iRec0_perm[j1] = iRec0_tmp[vsize + j1];
			}
			/* Vectorizable loop 1 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = fSlow5 * float(iRec0[i]);
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec1[i] = int(fZec0[i]);
			}
			/* Vectorizable loop 3 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec3[i] = iZec1[i] + 1;
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec2[i] = ((iZec1[i] >= 4) ? ((iZec1[i] >= 6) ? ((iZec1[i] >= 7) ? fSlow13 : fSlow12) : ((iZec1[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec1[i] >= 2) ? ((iZec1[i] >= 3) ? fSlow9 : fSlow8) : ((iZec1[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 5 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec4[i] = ((iZec3[i] >= 4) ? ((iZec3[i] >= 6) ? ((iZec3[i] >= 7) ? fSlow13 : fSlow12) : ((iZec3[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec3[i] >= 2) ? ((iZec3[i] >= 3) ? fSlow9 : fSlow8) : ((iZec3[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec6[i] = float(iZec1[i]);
			}
			/* Vectorizable loop 7 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec8[i] = iZec1[i] + -1;
			}
			/* Vectorizable loop 8 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec10[i] = iZec1[i] + 2;
			}
			/* Vectorizable loop 9 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec5[i] = fZec4[i] - fZec2[i];
			}
			/* Vectorizable loop 10 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec7[i] = fZec0[i] - ((fZec0[i] == fZec6[i]) ? fZec0[i] : ((fZec0[i] >= 0.0f) ? fZec6[i] : fZec6[i] + -1.0f));
			}
			/* Vectorizable loop 11 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec9[i] = ((iZec8[i] >= 4) ? ((iZec8[i] >= 6) ? ((iZec8[i] >= 7) ? fSlow13 : fSlow12) : ((iZec8[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec8[i] >= 2) ? ((iZec8[i] >= 3) ? fSlow9 : fSlow8) : ((iZec8[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec11[i] = ((iZec10[i] >= 4) ? ((iZec10[i] >= 6) ? ((iZec10[i] >= 7) ? fSlow13 : fSlow12) : ((iZec10[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec10[i] >= 2) ? ((iZec10[i] >= 3) ? fSlow9 : fSlow8) : ((iZec10[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec12[i] = std::pow(1e+01f, 2.0f * std::max<float>(0.0f, std::min<float>(1.0f, ((iSlow3) ? ((iSlow14) ? fSlow15 : fZec2[i] + 0.5f * fZec7[i] * (fZec4[i] + fZec7[i] * (2.0f * fZec9[i] + 4.0f * fZec4[i] + fZec7[i] * (fZec11[i] + 3.0f * (fZec2[i] - fZec4[i]) - fZec9[i]) - (5.0f * fZec2[i] + fZec11[i])) - fZec9[i])) : ((iSlow4) ? fZec2[i] + 0.5f * fZec5[i] * (1.0f - std::cos(3.1415927f * fZec7[i])) : fZec2[i] + fZec7[i] * fZec5[i])))));
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = std::max<float>(-1.0f, std::min<float>(1.0f, float(input0[i]) * fZec12[i]));
			}
			/* Vectorizable loop 15 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = std::max<float>(-1.0f, std::min<float>(1.0f, float(input1[i]) * fZec12[i]));
			}
			/* Vectorizable loop 16 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fZec13[i] * (1.0f - 0.33333334f * DistortionFAUST_faustpower2_f(fZec13[i])));
			}
			/* Vectorizable loop 17 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(fZec14[i] * (1.0f - 0.33333334f * DistortionFAUST_faustpower2_f(fZec14[i])));
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
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				iRec0_tmp[j0] = iRec0_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec0[i] = ((iSlow0) ? 0 : std::min<int>(iSlow1, iRec0[i - 1] + 1));
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				iRec0_perm[j1] = iRec0_tmp[vsize + j1];
			}
			/* Vectorizable loop 1 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = fSlow5 * float(iRec0[i]);
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec1[i] = int(fZec0[i]);
			}
			/* Vectorizable loop 3 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec3[i] = iZec1[i] + 1;
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec2[i] = ((iZec1[i] >= 4) ? ((iZec1[i] >= 6) ? ((iZec1[i] >= 7) ? fSlow13 : fSlow12) : ((iZec1[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec1[i] >= 2) ? ((iZec1[i] >= 3) ? fSlow9 : fSlow8) : ((iZec1[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 5 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec4[i] = ((iZec3[i] >= 4) ? ((iZec3[i] >= 6) ? ((iZec3[i] >= 7) ? fSlow13 : fSlow12) : ((iZec3[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec3[i] >= 2) ? ((iZec3[i] >= 3) ? fSlow9 : fSlow8) : ((iZec3[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec6[i] = float(iZec1[i]);
			}
			/* Vectorizable loop 7 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec8[i] = iZec1[i] + -1;
			}
			/* Vectorizable loop 8 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec10[i] = iZec1[i] + 2;
			}
			/* Vectorizable loop 9 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec5[i] = fZec4[i] - fZec2[i];
			}
			/* Vectorizable loop 10 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec7[i] = fZec0[i] - ((fZec0[i] == fZec6[i]) ? fZec0[i] : ((fZec0[i] >= 0.0f) ? fZec6[i] : fZec6[i] + -1.0f));
			}
			/* Vectorizable loop 11 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec9[i] = ((iZec8[i] >= 4) ? ((iZec8[i] >= 6) ? ((iZec8[i] >= 7) ? fSlow13 : fSlow12) : ((iZec8[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec8[i] >= 2) ? ((iZec8[i] >= 3) ? fSlow9 : fSlow8) : ((iZec8[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec11[i] = ((iZec10[i] >= 4) ? ((iZec10[i] >= 6) ? ((iZec10[i] >= 7) ? fSlow13 : fSlow12) : ((iZec10[i] >= 5) ? fSlow11 : fSlow10)) : ((iZec10[i] >= 2) ? ((iZec10[i] >= 3) ? fSlow9 : fSlow8) : ((iZec10[i] >= 1) ? fSlow7 : fSlow6)));
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec12[i] = std::pow(1e+01f, 2.0f * std::max<float>(0.0f, std::min<float>(1.0f, ((iSlow3) ? ((iSlow14) ? fSlow15 : fZec2[i] + 0.5f * fZec7[i] * (fZec4[i] + fZec7[i] * (2.0f * fZec9[i] + 4.0f * fZec4[i] + fZec7[i] * (fZec11[i] + 3.0f * (fZec2[i] - fZec4[i]) - fZec9[i]) - (5.0f * fZec2[i] + fZec11[i])) - fZec9[i])) : ((iSlow4) ? fZec2[i] + 0.5f * fZec5[i] * (1.0f - std::cos(3.1415927f * fZec7[i])) : fZec2[i] + fZec7[i] * fZec5[i])))));
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = std::max<float>(-1.0f, std::min<float>(1.0f, float(input0[i]) * fZec12[i]));
			}
			/* Vectorizable loop 15 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = std::max<float>(-1.0f, std::min<float>(1.0f, float(input1[i]) * fZec12[i]));
			}
			/* Vectorizable loop 16 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fZec13[i] * (1.0f - 0.33333334f * DistortionFAUST_faustpower2_f(fZec13[i])));
			}
			/* Vectorizable loop 17 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(fZec14[i] * (1.0f - 0.33333334f * DistortionFAUST_faustpower2_f(fZec14[i])));
			}
		}
	}

};

#endif
