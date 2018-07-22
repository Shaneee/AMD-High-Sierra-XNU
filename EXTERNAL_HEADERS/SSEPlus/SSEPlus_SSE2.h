//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_SSE2_H__
#define __SSEPLUS_SSE2_H__

#include "SSEPlus_base.h"

//Forward declarations
//============================================
// SSE2 Native
//============================================
__m128i   ssp_add_epi16_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_add_epi32_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_add_epi64_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_add_epi8_SSE2         ( __m128i _A, __m128i _B );
__m128d   ssp_add_pd_SSE2           ( __m128d _A, __m128d _B );
__m128d   ssp_add_sd_SSE2           ( __m128d _A, __m128d _B );
__m128i   ssp_adds_epi16_SSE2       ( __m128i _A, __m128i _B );
__m128i   ssp_adds_epi8_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_adds_epu16_SSE2       ( __m128i _A, __m128i _B );
__m128i   ssp_adds_epu8_SSE2        ( __m128i _A, __m128i _B );
__m128d   ssp_and_pd_SSE2           ( __m128d _A, __m128d _B );
__m128i   ssp_and_si128_SSE2        ( __m128i _A, __m128i _B );
__m128d   ssp_andnot_pd_SSE2        ( __m128d _A, __m128d _B );
__m128i   ssp_andnot_si128_SSE2     ( __m128i _A, __m128i _B );
__m128i   ssp_avg_epu16_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_avg_epu8_SSE2         ( __m128i _A, __m128i _B );
__m128    ssp_castpd_ps_SSE2        ( __m128d );
__m128i   ssp_castpd_si128_SSE2     ( __m128d );
__m128d   ssp_castps_pd_SSE2        ( __m128 );
__m128i   ssp_castps_si128_SSE2     ( __m128 );
__m128d   ssp_castsi128_pd_SSE2     ( __m128i );
__m128    ssp_castsi128_ps_SSE2     ( __m128i );
void      ssp_clflush_SSE2          ( void const*_P );
__m128i   ssp_cmpeq_epi16_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_cmpeq_epi32_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_cmpeq_epi8_SSE2       ( __m128i _A, __m128i _B );
__m128d   ssp_cmpeq_pd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmpeq_sd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmpge_pd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmpge_sd_SSE2         ( __m128d _A, __m128d _B );
__m128i   ssp_cmpgt_epi16_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_cmpgt_epi32_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_cmpgt_epi8_SSE2       ( __m128i _A, __m128i _B );
__m128d   ssp_cmpgt_pd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmpgt_sd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmple_pd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmple_sd_SSE2         ( __m128d _A, __m128d _B );
__m128i   ssp_cmplt_epi16_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_cmplt_epi32_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_cmplt_epi8_SSE2       ( __m128i _A, __m128i _B );
__m128d   ssp_cmplt_pd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmplt_sd_SSE2         ( __m128d _A, __m128d _B );
__m128d   ssp_cmpneq_pd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpneq_sd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpnge_pd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpnge_sd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpngt_pd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpngt_sd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpnle_pd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpnle_sd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpnlt_pd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpnlt_sd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpord_pd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpord_sd_SSE2        ( __m128d _A, __m128d _B );
__m128d   ssp_cmpunord_pd_SSE2      ( __m128d _A, __m128d _B );
__m128d   ssp_cmpunord_sd_SSE2      ( __m128d _A, __m128d _B );
int       ssp_comieq_sd_SSE2        ( __m128d _A, __m128d _B );
int       ssp_comige_sd_SSE2        ( __m128d _A, __m128d _B );
int       ssp_comigt_sd_SSE2        ( __m128d _A, __m128d _B );
int       ssp_comile_sd_SSE2        ( __m128d _A, __m128d _B );
int       ssp_comilt_sd_SSE2        ( __m128d _A, __m128d _B );
int       ssp_comineq_sd_SSE2       ( __m128d _A, __m128d _B );
__m128d   ssp_cvtepi32_pd_SSE2      ( __m128i _A );
__m128    ssp_cvtepi32_ps_SSE2      ( __m128i _A );
__m128i   ssp_cvtpd_epi32_SSE2      ( __m128d _A );
__m128    ssp_cvtpd_ps_SSE2         ( __m128d _A );
__m128i   ssp_cvtps_epi32_SSE2      ( __m128 _A );
__m128d   ssp_cvtps_pd_SSE2         ( __m128 _A );
double    ssp_cvtsd_f64_SSE2        ( __m128d _A );
int       ssp_cvtsd_si32_SSE2       ( __m128d _A );
ssp_s64   ssp_cvtsd_si64_SSE2       ( __m128d );
__m128    ssp_cvtsd_ss_SSE2         ( __m128 _A, __m128d _B );
int       ssp_cvtsi128_si32_SSE2    ( __m128i _A );
ssp_s64   ssp_cvtsi128_si64_SSE2    ( __m128i );
__m128d   ssp_cvtsi32_sd_SSE2       ( __m128d _A, int _B );
__m128i   ssp_cvtsi32_si128_SSE2    ( int _A );
__m128d   ssp_cvtsi64_sd_SSE2       ( __m128d, ssp_s64 );
__m128i   ssp_cvtsi64_si128_SSE2    ( ssp_s64 );
__m128d   ssp_cvtss_sd_SSE2         ( __m128d _A, __m128 _B );
__m128i   ssp_cvttpd_epi32_SSE2     ( __m128d _A );
__m128i   ssp_cvttps_epi32_SSE2     ( __m128 _A );
int       ssp_cvttsd_si32_SSE2      ( __m128d _A );
ssp_s64   ssp_cvttsd_si64_SSE2      ( __m128d );
__m128d   ssp_div_pd_SSE2           ( __m128d _A, __m128d _B );
__m128d   ssp_div_sd_SSE2           ( __m128d _A, __m128d _B );
int       ssp_extract_epi16_SSE2    ( __m128i _A, int _Imm );
__m128i   ssp_insert_epi16_SSE2     ( __m128i _A, int _B, int _Imm );
void      ssp_lfence_SSE2           ( void );
__m128d   ssp_load_pd_SSE2          ( double const*_Dp );
__m128d   ssp_load_sd_SSE2          ( double const*_Dp );
__m128i   ssp_load_si128_SSE2       ( __m128i const*_P );
__m128d   ssp_load1_pd_SSE2         ( double const*_Dp );
__m128d   ssp_loadh_pd_SSE2         ( __m128d _A, double const*_Dp );
__m128i   ssp_loadl_epi64_SSE2      ( __m128i const*_P );
__m128d   ssp_loadl_pd_SSE2         ( __m128d _A, double const*_Dp );
__m128d   ssp_loadr_pd_SSE2         ( double const*_Dp );
__m128d   ssp_loadu_pd_SSE2         ( double const*_Dp );
__m128i   ssp_loadu_si128_SSE2      ( __m128i const*_P );
__m128i   ssp_madd_epi16_SSE2       ( __m128i _A, __m128i _B );
void      ssp_maskmoveu_si128_SSE2  ( __m128i _D, __m128i _N, char *_P );
__m128i   ssp_max_epi16_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_max_epu8_SSE2         ( __m128i _A, __m128i _B );
__m128d   ssp_max_pd_SSE2           ( __m128d _A, __m128d _B );
__m128d   ssp_max_sd_SSE2           ( __m128d _A, __m128d _B );
void      ssp_mfence_SSE2           ( void );
__m128i   ssp_min_epi16_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_min_epu8_SSE2         ( __m128i _A, __m128i _B );
__m128d   ssp_min_pd_SSE2           ( __m128d _A, __m128d _B );
__m128d   ssp_min_sd_SSE2           ( __m128d _A, __m128d _B );
__m128i   ssp_move_epi64_SSE2       ( __m128i _Q );
__m128d   ssp_move_sd_SSE2          ( __m128d _A, __m128d _B );
int       ssp_movemask_epi8_SSE2    ( __m128i _A );
int       ssp_movemask_pd_SSE2      ( __m128d _A );
__m128i   ssp_mul_epu32_SSE2        ( __m128i _A, __m128i _B );
__m128d   ssp_mul_pd_SSE2           ( __m128d _A, __m128d _B );
__m128d   ssp_mul_sd_SSE2           ( __m128d _A, __m128d _B );
__m128i   ssp_mulhi_epi16_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_mulhi_epu16_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_mullo_epi16_SSE2      ( __m128i _A, __m128i _B );
__m128d   ssp_or_pd_SSE2            ( __m128d _A, __m128d _B );
__m128i   ssp_or_si128_SSE2         ( __m128i _A, __m128i _B );
__m128i   ssp_packs_epi16_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_packs_epi32_SSE2      ( __m128i _A, __m128i _B );
__m128i   ssp_packus_epi16_SSE2     ( __m128i _A, __m128i _B );
void      ssp_pause_SSE2            ( void );
__m128i   ssp_sad_epu8_SSE2         ( __m128i _A, __m128i _B );
__m128i   ssp_set_epi16_SSE2        ( short _W7, short _W6, short _W5, short _W4, short _W3, short _W2, short _W1, short _W0 );
__m128i   ssp_set_epi32_SSE2        ( int _I3, int _I2, int _I1, int _I0 );

__m128i   ssp_set_epi8_SSE2         ( char _B15, char _B14, char _B13, char _B12, char _B11, char _B10, char _B9, char _B8, char _B7, char _B6, char _B5, char _B4, char _B3, char _B2, char _B1, char _B0 );
__m128d   ssp_set_pd_SSE2           ( double _Z, double _Y );
__m128d   ssp_set_sd_SSE2           ( double _W );
__m128i   ssp_set1_epi16_SSE2       ( short _W );
__m128i   ssp_set1_epi32_SSE2       ( int _I );

__m128i   ssp_set1_epi8_SSE2        ( char _B );
__m128d   ssp_set1_pd_SSE2          ( double _A );
__m128i   ssp_setl_epi64_SSE2       ( __m128i _Q );
__m128i   ssp_setr_epi16_SSE2       ( short _W0, short _W1, short _W2, short _W3, short _W4, short _W5, short _W6, short _W7 );
__m128i   ssp_setr_epi32_SSE2       ( int _I0, int _I1, int _I2, int _I3 );

__m128i   ssp_setr_epi8_SSE2        ( char _B15, char _B14, char _B13, char _B12, char _B11, char _B10, char _B9, char _B8, char _B7, char _B6, char _B5, char _B4, char _B3, char _B2, char _B1, char _B0 );
__m128d   ssp_setr_pd_SSE2          ( double _Y, double _Z );
__m128d   ssp_setzero_pd_SSE2       ( void );
__m128i   ssp_setzero_si128_SSE2    ( void );
__m128i   ssp_shuffle_epi32_SSE2    ( __m128i _A, int _Imm );
__m128d   ssp_shuffle_pd_SSE2       ( __m128d _A, __m128d _B, int _I );
__m128i   ssp_shufflehi_epi16_SSE2  ( __m128i _A, int _Imm );
__m128i   ssp_shufflelo_epi16_SSE2  ( __m128i _A, int _Imm );
__m128i   ssp_sll_epi16_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_sll_epi32_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_sll_epi64_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_slli_epi16_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_slli_epi32_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_slli_epi64_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_slli_si128_SSE2       ( __m128i _A, int _Imm );
__m128d   ssp_sqrt_pd_SSE2          ( __m128d _A );
__m128d   ssp_sqrt_sd_SSE2          ( __m128d _A, __m128d _B );
__m128i   ssp_sra_epi16_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_sra_epi32_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_srai_epi16_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_srai_epi32_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_srl_epi16_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_srl_epi32_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_srl_epi64_SSE2        ( __m128i _A, __m128i _Count );
__m128i   ssp_srli_epi16_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_srli_epi32_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_srli_epi64_SSE2       ( __m128i _A, int _Count );
__m128i   ssp_srli_si128_SSE2       ( __m128i _A, int _Imm );
void      ssp_store_pd_SSE2         ( double *_Dp, __m128d _A );
void      ssp_store_sd_SSE2         ( double *_Dp, __m128d _A );
void      ssp_store_si128_SSE2      ( __m128i *_P, __m128i _B );
void      ssp_store1_pd_SSE2        ( double *_Dp, __m128d _A );
void      ssp_storeh_pd_SSE2        ( double *_Dp, __m128d _A );
void      ssp_storel_epi64_SSE2     ( __m128i *_P, __m128i _Q );
void      ssp_storel_pd_SSE2        ( double *_Dp, __m128d _A );
void      ssp_storer_pd_SSE2        ( double *_Dp, __m128d _A );
void      ssp_storeu_pd_SSE2        ( double *_Dp, __m128d _A );
void      ssp_storeu_si128_SSE2     ( __m128i *_P, __m128i _B );
void      ssp_stream_pd_SSE2        ( double *_Dp, __m128d _A );
void      ssp_stream_si128_SSE2     ( __m128i *_P, __m128i _A );
void      ssp_stream_si32_SSE2      ( int *_P, int _I );
__m128i   ssp_sub_epi16_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_sub_epi32_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_sub_epi64_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_sub_epi8_SSE2         ( __m128i _A, __m128i _B );
__m128d   ssp_sub_pd_SSE2           ( __m128d _A, __m128d _B );
__m128d   ssp_sub_sd_SSE2           ( __m128d _A, __m128d _B );

__m128i   ssp_subs_epi16_SSE2       ( __m128i _A, __m128i _B );
__m128i   ssp_subs_epi8_SSE2        ( __m128i _A, __m128i _B );
__m128i   ssp_subs_epu16_SSE2       ( __m128i _A, __m128i _B );
__m128i   ssp_subs_epu8_SSE2        ( __m128i _A, __m128i _B );
int       ssp_ucomieq_sd_SSE2       ( __m128d _A, __m128d _B );
int       ssp_ucomige_sd_SSE2       ( __m128d _A, __m128d _B );
int       ssp_ucomigt_sd_SSE2       ( __m128d _A, __m128d _B );
int       ssp_ucomile_sd_SSE2       ( __m128d _A, __m128d _B );
int       ssp_ucomilt_sd_SSE2       ( __m128d _A, __m128d _B );
int       ssp_ucomineq_sd_SSE2      ( __m128d _A, __m128d _B );
__m128i   ssp_unpackhi_epi16_SSE2   ( __m128i _A, __m128i _B );
__m128i   ssp_unpackhi_epi32_SSE2   ( __m128i _A, __m128i _B );
__m128i   ssp_unpackhi_epi64_SSE2   ( __m128i _A, __m128i _B );
__m128i   ssp_unpackhi_epi8_SSE2    ( __m128i _A, __m128i _B );
__m128d   ssp_unpackhi_pd_SSE2      ( __m128d _A, __m128d _B );
__m128i   ssp_unpacklo_epi16_SSE2   ( __m128i _A, __m128i _B );
__m128i   ssp_unpacklo_epi32_SSE2   ( __m128i _A, __m128i _B );
__m128i   ssp_unpacklo_epi64_SSE2   ( __m128i _A, __m128i _B );
__m128i   ssp_unpacklo_epi8_SSE2    ( __m128i _A, __m128i _B );
__m128d   ssp_unpacklo_pd_SSE2      ( __m128d _A, __m128d _B );
__m128d   ssp_xor_pd_SSE2           ( __m128d _A, __m128d _B );
__m128i   ssp_xor_si128_SSE2        ( __m128i _A, __m128i _B );

//============================================
// SSE3 Emulation
//============================================
__m128d   ssp_addsub_pd_SSE2        ( __m128d a, __m128d b ); 
__m128    ssp_addsub_ps_SSE2        ( __m128 a, __m128 b ); 
__m128d   ssp_hadd_pd_SSE2          ( __m128d a, __m128d b ); 
__m128    ssp_hadd_ps_SSE2          ( __m128 a, __m128 b ); 
__m128d   ssp_hsub_pd_SSE2          ( __m128d a, __m128d b ); 
__m128    ssp_hsub_ps_SSE2          ( __m128 a, __m128 b ); 
__m128i   ssp_lddqu_si128_SSE2      ( __m128i const *p ); 
__m128d   ssp_loaddup_pd_SSE2       ( double const * dp ); 
__m128d   ssp_movedup_pd_SSE2       ( __m128d a ); 
__m128    ssp_movehdup_ps_SSE2      ( __m128 a ); 
__m128    ssp_moveldup_ps_SSE2      ( __m128 a ); 

//============================================
// SSSE3 Emulation
//============================================
__m128i   ssp_abs_epi16_SSE2        ( __m128i a );
__m128i   ssp_abs_epi32_SSE2        ( __m128i a );
__m128i   ssp_abs_epi8_SSE2         ( __m128i a );
__m128i   ssp_alignr_epi8_SSE2      ( __m128i a, __m128i b, const int n );
__m128i   ssp_hadd_epi16_SSE2       ( __m128i a, __m128i b );
__m128i   ssp_hadd_epi32_SSE2       ( __m128i a, __m128i b );
__m128i   ssp_hadds_epi16_SSE2      ( __m128i a, __m128i b );
__m128i   ssp_hsub_epi16_SSE2       ( __m128i a, __m128i b );
__m128i   ssp_hsub_epi32_SSE2       ( __m128i a, __m128i b );
__m128i   ssp_hsubs_epi16_SSE2      ( __m128i a, __m128i b );
__m128i   ssp_maddubs_epi16_SSE2    ( __m128i a, __m128i b );
__m128i   ssp_mulhrs_epi16_SSE2     ( __m128i a, __m128i b );
__m128i   ssp_shuffle_epi8_SSE2     ( __m128i a, __m128i b );
__m128i   ssp_sign_epi16_SSE2       ( __m128i a, __m128i b );
__m128i   ssp_sign_epi32_SSE2       ( __m128i a, __m128i b );
__m128i   ssp_sign_epi8_SSE2        ( __m128i a, __m128i b );


//============================================
// SSE4A Emulation
//============================================
__m128i   ssp_extract_si64_SSE2     ( __m128i,__m128i );   
__m128i   ssp_extracti_si64_SSE2    ( __m128i, int, int );   
__m128i   ssp_insert_si64_SSE2      ( __m128i,__m128i );   
__m128i   ssp_inserti_si64_SSE2     ( __m128i, __m128i, int, int );   
void      ssp_stream_sd_SSE2        ( double*,__m128d );   
void      ssp_stream_ss_SSE2        ( float*,__m128 );   

//============================================
// SSE4.1 Emulation
//============================================
__m128i   ssp_blend_epi16_SSE2      ( __m128i v1, __m128i v2, const int mask );    
__m128d   ssp_blend_pd_SSE2         ( __m128d v1, __m128d v2, const int mask );    
__m128    ssp_blend_ps_SSE2         ( __m128  v1, __m128  v2, const int mask );    
__m128i   ssp_blendv_epi8_SSE2      ( __m128i v1, __m128i v2, __m128i   mask );    
__m128d   ssp_blendv_pd_SSE2        ( __m128d v1, __m128d v2, __m128d   mask );    
__m128    ssp_blendv_ps_SSE2        ( __m128  v1, __m128  v2, __m128    mask );    
__m128d   ssp_ceil_pd_SSE2          ( __m128d a );    
__m128    ssp_ceil_ps_SSE2          ( __m128  a );    
__m128d   ssp_ceil_sd_SSE2          ( __m128d a, __m128d b );    
__m128    ssp_ceil_ss_SSE2          ( __m128  a, __m128  b );    
__m128i   ssp_cmpeq_epi64_SSE2      ( __m128i val1, __m128i val2 );    
__m128i   ssp_cvtepi16_epi32_SSE2   ( __m128i shortValues );    
__m128i   ssp_cvtepi16_epi64_SSE2   ( __m128i shortValues );    
__m128i   ssp_cvtepi32_epi64_SSE2   ( __m128i intValues   );    
__m128i   ssp_cvtepi8_epi16_SSE2    ( __m128i byteValues  );    
__m128i   ssp_cvtepi8_epi32_SSE2    ( __m128i byteValues  );    
__m128i   ssp_cvtepi8_epi64_SSE2    ( __m128i byteValues  );    
__m128i   ssp_cvtepu16_epi32_SSE2   ( __m128i shortValues );    
__m128i   ssp_cvtepu16_epi64_SSE2   ( __m128i shortValues );    
__m128i   ssp_cvtepu32_epi64_SSE2   ( __m128i intValues   );    
__m128i   ssp_cvtepu8_epi16_SSE2    ( __m128i byteValues  );    
__m128i   ssp_cvtepu8_epi32_SSE2    ( __m128i byteValues  );    
__m128i   ssp_cvtepu8_epi64_SSE2    ( __m128i shortValues );    
__m128d   ssp_dp_pd_SSE2            ( __m128d val1, __m128d val2, const int mask );    
__m128    ssp_dp_ps_SSE2            ( __m128  val1, __m128  val2, const int mask );    
int       ssp_extract_epi32_SSE2    ( __m128i src, const int ndx );    
ssp_s64   ssp_extract_epi64_SSE2    ( __m128i src, const int ndx );    
int       ssp_extract_epi8_SSE2     ( __m128i src, const int ndx );    
int       ssp_extract_ps_SSE2       ( __m128  src, const int ndx );    
__m128d   ssp_floor_pd_SSE2         ( __m128d a );    
__m128    ssp_floor_ps_SSE2         ( __m128  a );    
__m128d   ssp_floor_sd_SSE2         ( __m128d a, __m128d b );    
__m128    ssp_floor_ss_SSE2         ( __m128  a, __m128  b );    
__m128i   ssp_insert_epi32_SSE2     ( __m128i dst,      int s, const int ndx );    
__m128i   ssp_insert_epi64_SSE2     ( __m128i dst, ssp_s64  s, const int ndx );    
__m128i   ssp_insert_epi8_SSE2      ( __m128i dst,      int s, const int ndx );    
__m128    ssp_insert_ps_SSE2        ( __m128  dst, __m128 src, const int ndx );    
__m128i   ssp_max_epi32_SSE2        ( __m128i val1, __m128i val2 );    
__m128i   ssp_max_epi8_SSE2         ( __m128i val1, __m128i val2 );    
__m128i   ssp_max_epu16_SSE2        ( __m128i val1, __m128i val2 );    
__m128i   ssp_max_epu32_SSE2        ( __m128i val1, __m128i val2 );    
__m128i   ssp_min_epi32_SSE2        ( __m128i val1, __m128i val2 );    
__m128i   ssp_min_epi8_SSE2         ( __m128i val1, __m128i val2 );    
__m128i   ssp_min_epu16_SSE2        ( __m128i val1, __m128i val2 );    
__m128i   ssp_min_epu32_SSE2        ( __m128i val1, __m128i val2 );    
__m128i   ssp_minpos_epu16_SSE2     ( __m128i shortValues );    
__m128i   ssp_mpsadbw_epu8_SSE2     ( __m128i s1,   __m128i s2,   const int msk  );    
__m128i   ssp_mul_epi32_SSE2        ( __m128i a,    __m128i b );   
__m128i   ssp_packus_epi32_SSE2     ( __m128i val1, __m128i val2 );    
__m128d   ssp_round_pd_SSE2         ( __m128d val, int iRoundMode );    

SSP_FORCEINLINE
__m128    ssp_round_ps_SSE2         ( __m128  val, int iRoundMode );    
__m128d   ssp_round_sd_SSE2         ( __m128d dst, __m128d val, int iRoundMode );    
__m128    ssp_round_ss_SSE2         ( __m128  dst, __m128  val, int iRoundMode );    
__m128i   ssp_stream_load_si128_SSE2( __m128i* v1 );    
int       ssp_testc_si128_SSE2      ( __m128i mask, __m128i val );    
int       ssp_testnzc_si128_SSE2    ( __m128i mask, __m128i s2  ); 

SSP_FORCEINLINE
int       ssp_testz_si128_SSE2      ( __m128i mask, __m128i val );  

//============================================
// SSE4.2 Emulation
//============================================
int       ssp_cmpestra_SSE2         ( __m128i a, int la, __m128i b, int lb, const int mode );
int       ssp_cmpestrc_SSE2         ( __m128i a, int la, __m128i b, int lb, const int mode );
int       ssp_cmpestri_SSE2         ( __m128i a, int la, __m128i b, int lb, const int mode );
__m128i   ssp_cmpestrm_SSE2         ( __m128i a, int la, __m128i b, int lb, const int mode );
int       ssp_cmpestro_SSE2         ( __m128i a, int la, __m128i b, int lb, const int mode );
int       ssp_cmpestrs_SSE2         ( __m128i a, int la, __m128i b, int lb, const int mode );
int       ssp_cmpestrz_SSE2         ( __m128i a, int la, __m128i b, int lb, const int mode );
__m128i   ssp_cmpgt_epi64_SSE2      ( __m128i a, __m128i b );
int       ssp_cmpistra_SSE2         ( __m128i a, __m128i b, const int mode );
int       ssp_cmpistrc_SSE2         ( __m128i a, __m128i b, const int mode );
int       ssp_cmpistri_SSE2         ( __m128i a, __m128i b, const int mode );
__m128i   ssp_cmpistrm_SSE2         ( __m128i a, __m128i b, const int mode );
int       ssp_cmpistro_SSE2         ( __m128i a, __m128i b, const int mode );
int       ssp_cmpistrs_SSE2         ( __m128i a, __m128i b, const int mode );
int       ssp_cmpistrz_SSE2         ( __m128i a, __m128i b, const int mode );
unsigned int     ssp_crc32_u16_SSE2 ( unsigned int crc, unsigned short   v );
unsigned int     ssp_crc32_u32_SSE2 ( unsigned int crc, unsigned int     v );
ssp_u64   ssp_crc32_u64_SSE2        ( unsigned int crc,          ssp_u64 v );
unsigned int     ssp_crc32_u8_SSE2  ( unsigned int crc, unsigned char    v );
int       ssp_popcnt_u32_SSE2       ( unsigned int a     );
int       ssp_popcnt_u64_SSE2       ( ssp_u64 a );

#include "native/SSEPlus_native_SSE2.h" 
#include "emulation/SSEPlus_emulation_SSE2.h" 
#include "arithmetic/SSEPlus_arithmetic_SSE2.h"
#include "logical/SSEPlus_logical_SSE2.h"
#include "memory/SSEPlus_memory_SSE2.h"
#include "convert/SSEPlus_convert_SSE2.h"

#endif // __SSEPLUS_SSE2_H__
