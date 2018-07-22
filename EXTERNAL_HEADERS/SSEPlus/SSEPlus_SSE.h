//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_SSE_H__
#define __SSEPLUS_SSE_H__

#include "SSEPlus_base.h"

//Forward declarations
//============================================
// SSE Native
//============================================
__m128        ssp_add_ps_SSE     (__m128 _A, __m128 _B);
__m128        ssp_add_ss_SSE     (__m128 _A, __m128 _B);
__m128        ssp_and_ps_SSE     (__m128 _A, __m128 _B);
__m128        ssp_andnot_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpeq_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpeq_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpge_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpge_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpgt_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpgt_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmple_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmple_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmplt_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmplt_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpneq_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpneq_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpnge_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpnge_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpngt_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpngt_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpnle_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpnle_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpnlt_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpnlt_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpord_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpord_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpunord_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_cmpunord_ss_SSE (__m128 _A, __m128 _B);
int           ssp_comieq_ss_SSE (__m128 _A, __m128 _B);
int           ssp_comige_ss_SSE (__m128 _A, __m128 _B);
int           ssp_comigt_ss_SSE (__m128 _A, __m128 _B);
int           ssp_comile_ss_SSE (__m128 _A, __m128 _B);
int           ssp_comilt_ss_SSE (__m128 _A, __m128 _B);
int           ssp_comineq_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_cvt_si2ss_SSE (__m128, int);
int           ssp_cvt_ss2si_SSE (__m128 _A);
__m128        ssp_cvtsi64_ss_SSE (__m128 _A, ssp_s64 _B);       // 64 bit instruction extensions
float         ssp_cvtss_f32_SSE (__m128 _A);
ssp_s64       ssp_cvtss_si64_SSE (__m128 _A);                   // 64 bit instruction extensions
int           ssp_cvtt_ss2si_SSE (__m128 _A);
ssp_s64       ssp_cvttss_si64_SSE (__m128 _A);                  // 64 bit instruction extensions
__m128        ssp_div_ps_SSE     (__m128 _A, __m128 _B);
__m128        ssp_div_ss_SSE     (__m128 _A, __m128 _B);
unsigned int  ssp_getcsr_SSE (void);
__m128        ssp_load_ps_SSE     (float const*_A);
__m128        ssp_load_ps1_SSE (float const*_A);
__m128        ssp_load_ss_SSE (float const*_A);
__m128        ssp_loadr_ps_SSE (float const*_A);
__m128        ssp_loadu_ps_SSE (float const*_A);
__m128        ssp_max_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_max_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_min_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_min_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_move_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_movehl_ps_SSE (__m128, __m128);
__m128        ssp_movelh_ps_SSE (__m128, __m128);
int           ssp_movemask_ps_SSE (__m128 _A);
__m128        ssp_mul_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_mul_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_or_ps_SSE (__m128 _A, __m128 _B);
void          ssp_prefetch_SSE (char *_A, int _Sel);
__m128        ssp_rcp_ps_SSE (__m128 _A);
__m128        ssp_rcp_ss_SSE (__m128 _A);
__m128        ssp_rsqrt_ps_SSE (__m128 _A);
__m128        ssp_rsqrt_ss_SSE (__m128 _A);
__m128        ssp_set_ps_SSE (float _A, float _B, float _C, float _D);
__m128        ssp_set_ps1_SSE (float _A);
__m128        ssp_set_ss_SSE (float _A);
void          ssp_setcsr_SSE (unsigned int);
__m128        ssp_setr_ps_SSE (float _A, float _B, float _C, float _D);
__m128        ssp_setzero_ps_SSE (void);
void          ssp_sfence_SSE (void);
__m128        ssp_shuffle_ps_SSE (__m128 _A, __m128 _B, unsigned int _Imm8);
__m128        ssp_sqrt_ps_SSE (__m128 _A);
__m128        ssp_sqrt_ss_SSE (__m128 _A);
void          ssp_store_ps_SSE (float *_V, __m128 _A);
void          ssp_store_ps1_SSE (float *_V, __m128 _A);
void          ssp_store_ss_SSE (float *_V, __m128 _A);
void          ssp_storer_ps_SSE (float *_V, __m128 _A);
void          ssp_storeu_ps_SSE (float *_V, __m128 _A);
void          ssp_stream_ps_SSE (float *, __m128);
__m128        ssp_sub_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_sub_ss_SSE (__m128 _A, __m128 _B);
int           ssp_ucomieq_ss_SSE (__m128 _A, __m128 _B);
int           ssp_ucomige_ss_SSE (__m128 _A, __m128 _B);
int           ssp_ucomigt_ss_SSE (__m128 _A, __m128 _B);
int           ssp_ucomile_ss_SSE (__m128 _A, __m128 _B);
int           ssp_ucomilt_ss_SSE (__m128 _A, __m128 _B);
int           ssp_ucomineq_ss_SSE (__m128 _A, __m128 _B);
__m128        ssp_unpackhi_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_unpacklo_ps_SSE (__m128 _A, __m128 _B);
__m128        ssp_xor_ps_SSE (__m128 _A, __m128 _B);


#include "native/SSEPlus_native_SSE.h"

#endif // __SSEPLUS_SSE_H__
