/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.3.0
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

// source: /home/rrop/rropdb/box_inside/pdje/Project_DJ_Engine/PDJE_swig.i


extern
#ifdef __cplusplus
  "C"
#endif
  void cgo_panic__pdje_POLYGLOT_555bf1454b31f4c0(const char*);
static void _swig_gopanic(const char *p) {
  cgo_panic__pdje_POLYGLOT_555bf1454b31f4c0(p);
}



#define SWIG_VERSION 0x040300
#define SWIGGO
#define SWIGMODULE pdje_POLYGLOT
/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif

#if defined(__cplusplus) && __cplusplus >=201103L
# define SWIG_NULLPTR nullptr
#else
# define SWIG_NULLPTR NULL
#endif 

/* -----------------------------------------------------------------------------
 * swigcompat.swg
 *
 * Macros to provide support compatibility with older C and C++ standards.
 *
 * Note that SWIG expects __cplusplus to be defined to the appropriate C++ standard.
 * MSVC users are urged to check and examine the /Zc:__cplusplus compiler option.
 * See https://learn.microsoft.com/en-us/cpp/build/reference/zc-cplusplus.
 * ----------------------------------------------------------------------------- */

/* C99 and C++11 should provide snprintf, but define SWIG_NO_SNPRINTF
 * if you're missing it.
 */
#if ((defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L) || \
     (defined __cplusplus && __cplusplus >= 201103L) || \
     defined SWIG_HAVE_SNPRINTF) && \
    !defined SWIG_NO_SNPRINTF
# define SWIG_snprintf(O,S,F,A) snprintf(O,S,F,A)
# define SWIG_snprintf2(O,S,F,A,B) snprintf(O,S,F,A,B)
#else
/* Fallback versions ignore the buffer size, but most of our uses either have a
 * fixed maximum possible size or dynamically allocate a buffer that's large
 * enough.
 */
# define SWIG_snprintf(O,S,F,A) sprintf(O,F,A)
# define SWIG_snprintf2(O,S,F,A,B) sprintf(O,F,A,B)
#endif


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>



typedef ptrdiff_t intgo;
typedef size_t uintgo;


# if !defined(__clang__) && (defined(__i386__) || defined(__x86_64__))
#   define SWIGSTRUCTPACKED __attribute__((__packed__, __gcc_struct__))
# else
#   define SWIGSTRUCTPACKED __attribute__((__packed__))
# endif



typedef struct { char *p; intgo n; } _gostring_;
typedef struct { void* array; intgo len; intgo cap; } _goslice_;



#ifdef __cplusplus
#include <utility>
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigSmartPointer {
    T *ptr;
    SwigSmartPointer(T *p) : ptr(p) { }
    ~SwigSmartPointer() { delete ptr; }
    SwigSmartPointer& operator=(SwigSmartPointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
    void reset(T *p) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = p; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigSmartPointer tmp(new T(t)); pointer = tmp; return *this; }
#if __cplusplus >=201103L
  SwigValueWrapper& operator=(T&& t) { SwigSmartPointer tmp(new T(std::move(t))); pointer = tmp; return *this; }
  operator T&&() const { return std::move(*pointer.ptr); }
#else
  operator T&() const { return *pointer.ptr; }
#endif
  T *operator&() const { return pointer.ptr; }
  static void reset(SwigValueWrapper& t, T *p) { t.pointer.reset(p); }
};

/*
 * SwigValueInit() is a generic initialisation solution as the following approach:
 * 
 *       T c_result = T();
 * 
 * doesn't compile for all types for example:
 * 
 *       unsigned int c_result = unsigned int();
 */
template <typename T> T SwigValueInit() {
  return T();
}

#if __cplusplus >=201103L
# define SWIG_STD_MOVE(OBJ) std::move(OBJ)
#else
# define SWIG_STD_MOVE(OBJ) OBJ
#endif

#endif


static void Swig_free(void* p) {
  free(p);
}

static void* Swig_malloc(int c) {
  return malloc(c);
}


    #include "PDJE_interface.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void _wrap_Swig_free_pdje_POLYGLOT_555bf1454b31f4c0(void *_swig_go_0) {
  void *arg1 = (void *) 0 ;
  
  arg1 = *(void **)&_swig_go_0; 
  
  Swig_free(arg1);
  
}


void *_wrap_Swig_malloc_pdje_POLYGLOT_555bf1454b31f4c0(intgo _swig_go_0) {
  int arg1 ;
  void *result = 0 ;
  void *_swig_go_result;
  
  arg1 = (int)_swig_go_0; 
  
  result = (void *)Swig_malloc(arg1);
  *(void **)&_swig_go_result = (void *)result; 
  return _swig_go_result;
}


intgo _wrap_FULL_PRE_RENDER_pdje_POLYGLOT_555bf1454b31f4c0() {
  PLAY_MODE result;
  intgo _swig_go_result;
  
  
  result = FULL_PRE_RENDER;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_HYBRID_RENDER_pdje_POLYGLOT_555bf1454b31f4c0() {
  PLAY_MODE result;
  intgo _swig_go_result;
  
  
  result = HYBRID_RENDER;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FULL_MANUAL_RENDER_pdje_POLYGLOT_555bf1454b31f4c0() {
  PLAY_MODE result;
  intgo _swig_go_result;
  
  
  result = FULL_MANUAL_RENDER;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


PDJE *_wrap_new_PDJE_pdje_POLYGLOT_555bf1454b31f4c0(std::string *_swig_go_0) {
  std::string *arg1 = 0 ;
  PDJE *result = 0 ;
  PDJE *_swig_go_result;
  
  arg1 = *(std::string **)&_swig_go_0; 
  
  result = (PDJE *)new PDJE((std::string const &)*arg1);
  *(PDJE **)&_swig_go_result = (PDJE *)result; 
  return _swig_go_result;
}


void _wrap_delete_PDJE_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0) {
  PDJE *arg1 = (PDJE *) 0 ;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  
  delete arg1;
  
}


void _wrap_PDJE_player_set_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0, std::optional< audioPlayer > *_swig_go_1) {
  PDJE *arg1 = (PDJE *) 0 ;
  std::optional< audioPlayer > arg2 ;
  std::optional< audioPlayer > *argp2 ;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  
  argp2 = (std::optional< audioPlayer > *)_swig_go_1;
  if (argp2 == NULL) {
    _swig_gopanic("Attempt to dereference null std::optional< audioPlayer >");
  }
  arg2 = (std::optional< audioPlayer >)*argp2;
  
  
  if (arg1) (arg1)->player = arg2;
  
}


std::optional< audioPlayer > *_wrap_PDJE_player_get_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0) {
  PDJE *arg1 = (PDJE *) 0 ;
  std::optional< audioPlayer > result;
  std::optional< audioPlayer > *_swig_go_result;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  
  result =  ((arg1)->player);
  *(std::optional< audioPlayer > **)&_swig_go_result = new std::optional< audioPlayer >(result); 
  return _swig_go_result;
}


bool _wrap_PDJE_InitPlayer_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0, intgo _swig_go_1, trackdata *_swig_go_2, intgo _swig_go_3) {
  PDJE *arg1 = (PDJE *) 0 ;
  PLAY_MODE arg2 ;
  trackdata *arg3 = 0 ;
  unsigned int arg4 ;
  bool result;
  bool _swig_go_result;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  arg2 = (PLAY_MODE)_swig_go_1; 
  arg3 = *(trackdata **)&_swig_go_2; 
  arg4 = (unsigned int)_swig_go_3; 
  
  result = (bool)(arg1)->InitPlayer(arg2,*arg3,arg4);
  _swig_go_result = result; 
  return _swig_go_result;
}


bool _wrap_PDJE_GetNoteObjects_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0, trackdata *_swig_go_1, OBJ_SETTER_CALLBACK *_swig_go_2) {
  PDJE *arg1 = (PDJE *) 0 ;
  trackdata *arg2 = 0 ;
  OBJ_SETTER_CALLBACK *arg3 = 0 ;
  bool result;
  bool _swig_go_result;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  arg2 = *(trackdata **)&_swig_go_1; 
  arg3 = *(OBJ_SETTER_CALLBACK **)&_swig_go_2; 
  
  result = (bool)(arg1)->GetNoteObjects(*arg2,*arg3);
  _swig_go_result = result; 
  return _swig_go_result;
}


MAYBE_MUS_VEC *_wrap_PDJE_SearchMusic__SWIG_0_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0, std::string *_swig_go_1, std::string *_swig_go_2, double _swig_go_3) {
  PDJE *arg1 = (PDJE *) 0 ;
  std::string *arg2 = 0 ;
  std::string *arg3 = 0 ;
  double arg4 ;
  MAYBE_MUS_VEC result;
  MAYBE_MUS_VEC *_swig_go_result;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  arg2 = *(std::string **)&_swig_go_1; 
  arg3 = *(std::string **)&_swig_go_2; 
  arg4 = (double)_swig_go_3; 
  
  result = (arg1)->SearchMusic((std::string const &)*arg2,(std::string const &)*arg3,arg4);
  *(MAYBE_MUS_VEC **)&_swig_go_result = new MAYBE_MUS_VEC(result); 
  return _swig_go_result;
}


MAYBE_MUS_VEC *_wrap_PDJE_SearchMusic__SWIG_1_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0, std::string *_swig_go_1, std::string *_swig_go_2) {
  PDJE *arg1 = (PDJE *) 0 ;
  std::string *arg2 = 0 ;
  std::string *arg3 = 0 ;
  MAYBE_MUS_VEC result;
  MAYBE_MUS_VEC *_swig_go_result;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  arg2 = *(std::string **)&_swig_go_1; 
  arg3 = *(std::string **)&_swig_go_2; 
  
  result = (arg1)->SearchMusic((std::string const &)*arg2,(std::string const &)*arg3);
  *(MAYBE_MUS_VEC **)&_swig_go_result = new MAYBE_MUS_VEC(result); 
  return _swig_go_result;
}


MAYBE_TRACK_VEC *_wrap_PDJE_SearchTrack_pdje_POLYGLOT_555bf1454b31f4c0(PDJE *_swig_go_0, std::string *_swig_go_1) {
  PDJE *arg1 = (PDJE *) 0 ;
  std::string *arg2 = 0 ;
  MAYBE_TRACK_VEC result;
  MAYBE_TRACK_VEC *_swig_go_result;
  
  arg1 = *(PDJE **)&_swig_go_0; 
  arg2 = *(std::string **)&_swig_go_1; 
  
  result = (arg1)->SearchTrack((std::string const &)*arg2);
  *(MAYBE_TRACK_VEC **)&_swig_go_result = new MAYBE_TRACK_VEC(result); 
  return _swig_go_result;
}


#ifdef __cplusplus
}
#endif

