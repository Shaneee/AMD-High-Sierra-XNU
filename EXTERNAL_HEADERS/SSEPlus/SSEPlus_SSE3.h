//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_SSE3_H__
#define __SSEPLUS_SSE3_H__

#include "SSEPlus_base.h"

//============================================
// SSE3 Native
//============================================
__m128d   ssp_addsub_pd_SSE3        ( __m128d a, __m128d b ); 
__m128    ssp_addsub_ps_SSE3        ( __m128 a, __m128 b ); 
__m128d   ssp_hadd_pd_SSE3          ( __m128d a, __m128d b ); 
__m128    ssp_hadd_ps_SSE3          ( __m128 a, __m128 b ); 
__m128d   ssp_hsub_pd_SSE3          ( __m128d a, __m128d b ); 
__m128    ssp_hsub_ps_SSE3          ( __m128 a, __m128 b ); 
__m128i   ssp_lddqu_si128_SSE3      ( __m128i const *p ); 
__m128d   ssp_loaddup_pd_SSE3       ( double const * dp ); 
__m128d   ssp_movedup_pd_SSE3       ( __m128d a ); 
__m128    ssp_movehdup_ps_SSE3      ( __m128 a ); 
__m128    ssp_moveldup_ps_SSE3      ( __m128 a ); 

////============================================
//// SSSE3 Emulation
////============================================
//__m128i   ssp_abs_epi16_SSE3        ( __m128i a );
//__m128i   ssp_abs_epi32_SSE3        ( __m128i a );
//__m128i   ssp_abs_epi8_SSE3         ( __m128i a );
//__m64     ssp_abs_pi16_SSE3         ( __m64 a );
//__m64     ssp_abs_pi32_SSE3         ( __m64 a );
//__m64     ssp_abs_pi8_SSE3          ( __m64 a );
//__m128i   ssp_alignr_epi8_SSE3      ( __m128i a, __m128i b, int n );
//__m64     ssp_alignr_pi8_SSE3       ( __m64 a, __m64 b, int n );
//__m128i   ssp_hadd_epi16_SSE3       ( __m128i a, __m128i b );
//__m128i   ssp_hadd_epi32_SSE3       ( __m128i a, __m128i b );
//__m64     ssp_hadd_pi16_SSE3        ( __m64 a, __m64 b );
//__m64     ssp_hadd_pi32_SSE3        ( __m64 a, __m64 b );
//__m128i   ssp_hadds_epi16_SSE3      ( __m128i a, __m128i b );
//__m64     ssp_hadds_pi16_SSE3       ( __m64 a, __m64 b );
//__m128i   ssp_hsub_epi16_SSE3       ( __m128i a, __m128i b );
//__m128i   ssp_hsub_epi32_SSE3       ( __m128i a, __m128i b );
//__m64     ssp_hsub_pi16_SSE3        ( __m64 a, __m64 b );
//__m64     ssp_hsub_pi32_SSE3        ( __m64 a, __m64 b );
//__m128i   ssp_hsubs_epi16_SSE3      ( __m128i a, __m128i b );
//__m64     ssp_hsubs_pi16_SSE3       ( __m64 a, __m64 b );
//__m128i   ssp_maddubs_epi16_SSE3    ( __m128i a, __m128i b );
//__m64     ssp_maddubs_pi16_SSE3     ( __m64 a, __m64 b );
//__m128i   ssp_mulhrs_epi16_SSE3     ( __m128i a, __m128i b );
//__m64     ssp_mulhrs_pi16_SSE3      ( __m64 a, __m64 b );
//__m128i   ssp_shuffle_epi8_SSE3     ( __m128i a, __m128i b );
//__m64     ssp_shuffle_pi8_SSE3      ( __m64 a, __m64 b );
//__m128i   ssp_sign_epi16_SSE3       ( __m128i a, __m128i b );
//__m128i   ssp_sign_epi32_SSE3       ( __m128i a, __m128i b );
//__m128i   ssp_sign_epi8_SSE3        ( __m128i a, __m128i b );
//__m64     ssp_sign_pi16_SSE3        ( __m64 a, __m64 b );
//__m64     ssp_sign_pi32_SSE3        ( __m64 a, __m64 b );
//__m64     ssp_sign_pi8_SSE3         ( __m64 a, __m64 b );
//
////============================================
//// SSE4A Emulation
////============================================
//__m128i   ssp_extract_si64_SSE3     ( __m128i,__m128i );   
//__m128i   ssp_extracti_si64_SSE3    ( __m128i, int, int );   
//__m128i   ssp_insert_si64_SSE3      ( __m128i,__m128i );   
//__m128i   ssp_inserti_si64_SSE3     ( __m128i, __m128i, int, int );   
//void      ssp_stream_sd_SSE3        ( double*,__m128d );   
//void      ssp_stream_ss_SSE3        ( float*,__m128 );   
//
////============================================
//// SSE4.1 Emulation
////============================================
//__m128i   ssp_blend_epi16_SSE3      ( __m128i v1, __m128i v2, const int mask );    
//__m128d   ssp_blend_pd_SSE3         ( __m128d v1, __m128d v2, const int mask );    
//__m128    ssp_blend_ps_SSE3         ( __m128  v1, __m128  v2, const int mask );    
//__m128i   ssp_blendv_epi8_SSE3      ( __m128i v1, __m128i v2, __m128i   mask );    
//__m128d   ssp_blendv_pd_SSE3        ( __m128d v1, __m128d v2, __m128d   mask );    
//__m128    ssp_blendv_ps_SSE3        ( __m128  v1, __m128  v2, __m128    mask );    
//__m128d   ssp_ceil_pd_SSE3          ( __m128d a );    
//__m128    ssp_ceil_ps_SSE3          ( __m128  a );    
//__m128d   ssp_ceil_sd_SSE3          ( __m128d a, __m128d b );    
//__m128    ssp_ceil_ss_SSE3          ( __m128  a, __m128  b );    
//__m128i   ssp_cmpeq_epi64_SSE3      ( __m128i val1, __m128i val2 );    
//__m128i   ssp_cvtepi16_epi32_SSE3   ( __m128i shortValues );    
//__m128i   ssp_cvtepi16_epi64_SSE3   ( __m128i shortValues );    
//__m128i   ssp_cvtepi32_epi64_SSE3   ( __m128i intValues   );    
//__m128i   ssp_cvtepi8_epi16_SSE3    ( __m128i byteValues  );    
//__m128i   ssp_cvtepi8_epi32_SSE3    ( __m128i byteValues  );    
//__m128i   ssp_cvtepi8_epi64_SSE3    ( __m128i byteValues  );    
//__m128i   ssp_cvtepu16_epi32_SSE3   ( __m128i shortValues );    
//__m128i   ssp_cvtepu16_epi64_SSE3   ( __m128i shortValues );    
//__m128i   ssp_cvtepu32_epi64_SSE3   ( __m128i intValues   );    
//__m128i   ssp_cvtepu8_epi16_SSE3    ( __m128i byteValues  );    
//__m128i   ssp_cvtepu8_epi32_SSE3    ( __m128i byteValues  );    
//__m128i   ssp_cvtepu8_epi64_SSE3    ( __m128i shortValues );    
//__m128d   ssp_dp_pd_SSE3            ( __m128d val1, __m128d val2, const int mask );    
//__m128    ssp_dp_ps_SSE3            ( __m128  val1, __m128  val2, const int mask );    
//int       ssp_extract_epi32_SSE3    ( __m128i src, const int ndx );    
//__int64   ssp_extract_epi64_SSE3    ( __m128i src, const int ndx );    
//int       ssp_extract_epi8_SSE3     ( __m128i src, const int ndx );    
//int       ssp_extract_ps_SSE3       ( __m128  src, const int ndx );    
//__m128d   ssp_floor_pd_SSE3         ( __m128d a );    
//__m128    ssp_floor_ps_SSE3         ( __m128  a );    
//__m128d   ssp_floor_sd_SSE3         ( __m128d a, __m128d b );    
//__m128    ssp_floor_ss_SSE3         ( __m128  a, __m128  b );    
//__m128i   ssp_insert_epi32_SSE3     ( __m128i dst,      int s, const int ndx );    
//__m128i   ssp_insert_epi64_SSE3     ( __m128i dst, __int64  s, const int ndx );    
//__m128i   ssp_insert_epi8_SSE3      ( __m128i dst,      int s, const int ndx );    
//__m128    ssp_insert_ps_SSE3        ( __m128  dst, __m128 src, const int ndx );    
//__m128i   ssp_max_epi32_SSE3        ( __m128i val1, __m128i val2 );    
//__m128i   ssp_max_epi8_SSE3         ( __m128i val1, __m128i val2 );    
//__m128i   ssp_max_epu16_SSE3        ( __m128i val1, __m128i val2 );    
//__m128i   ssp_max_epu32_SSE3        ( __m128i val1, __m128i val2 );    
//__m128i   ssp_min_epi32_SSE3        ( __m128i val1, __m128i val2 );    
//__m128i   ssp_min_epi8_SSE3         ( __m128i val1, __m128i val2 );    
//__m128i   ssp_min_epu16_SSE3        ( __m128i val1, __m128i val2 );    
//__m128i   ssp_min_epu32_SSE3        ( __m128i val1, __m128i val2 );    
//__m128i   ssp_minpos_epu16_SSE3     ( __m128i shortValues );    
//__m128i   ssp_mpsadbw_epu8_SSE3     ( __m128i s1,   __m128i s2,   const int msk  );    
//__m128i   ssp_mul_epi32_SSE3        ( __m128i a,    __m128i b );    
//__m128i   ssp_mullo_epi32_SSE3      ( __m128i a,    __m128i b );    
//__m128i   ssp_packus_epi32_SSE3     ( __m128i val1, __m128i val2 );    
//__m128d   ssp_round_pd_SSE3         ( __m128d val, int iRoundMode );    
//__m128    ssp_round_ps_SSE3         ( __m128  val, int iRoundMode );    
//__m128d   ssp_round_sd_SSE3         ( __m128d dst, __m128d val, int iRoundMode );    
//__m128    ssp_round_ss_SSE3         ( __m128  dst, __m128  val, int iRoundMode );    
//__m128i   ssp_stream_load_si128_SSE3( __m128i* v1 );    
//int       ssp_testc_si128_SSE3      ( __m128i mask, __m128i val );    
//int       ssp_testnzc_si128_SSE3    ( __m128i mask, __m128i s2  );    
//int       ssp_testz_si128_SSE3      ( __m128i mask, __m128i val );  
//
////============================================
//// SSE4.2 Emulation
////============================================
//int       ssp_cmpestra_SSE3         ( __m128i a, int la, __m128i b, int lb, const int mode );
//int       ssp_cmpestrc_SSE3         ( __m128i a, int la, __m128i b, int lb, const int mode );
//int       ssp_cmpestri_SSE3         ( __m128i a, int la, __m128i b, int lb, const int mode );
//__m128i   ssp_cmpestrm_SSE3         ( __m128i a, int la, __m128i b, int lb, const int mode );
//int       ssp_cmpestro_SSE3         ( __m128i a, int la, __m128i b, int lb, const int mode );
//int       ssp_cmpestrs_SSE3         ( __m128i a, int la, __m128i b, int lb, const int mode );
//int       ssp_cmpestrz_SSE3         ( __m128i a, int la, __m128i b, int lb, const int mode );
//__m128i   ssp_cmpgt_epi64_SSE3      ( __m128i a, __m128i b );
//int       ssp_cmpistra_SSE3         ( __m128i a, __m128i b, const int mode );
//int       ssp_cmpistrc_SSE3         ( __m128i a, __m128i b, const int mode );
//int       ssp_cmpistri_SSE3         ( __m128i a, __m128i b, const int mode );
//__m128i   ssp_cmpistrm_SSE3         ( __m128i a, __m128i b, const int mode );
//int       ssp_cmpistro_SSE3         ( __m128i a, __m128i b, const int mode );
//int       ssp_cmpistrs_SSE3         ( __m128i a, __m128i b, const int mode );
//int       ssp_cmpistrz_SSE3         ( __m128i a, __m128i b, const int mode );
//unsigned int     ssp_crc32_u16_SSE3 ( unsigned int crc, unsigned short   v );
//unsigned int     ssp_crc32_u32_SSE3 ( unsigned int crc, unsigned int     v );
//unsigned __int64 ssp_crc32_u64_SSE3 ( unsigned int crc, unsigned __int64 v );
//unsigned int     ssp_crc32_u8_SSE3  ( unsigned int crc, unsigned char    v );
//int       ssp_popcnt_u32_SSE3       ( unsigned int a     );
//int       ssp_popcnt_u64_SSE3       ( unsigned __int64 a );

#include "native/SSEPlus_native_SSE3.h" 
#include "emulation/SSEPlus_emulation_SSE3.h" 
#include "arithmetic/SSEPlus_arithmetic_SSE3.h"

#endif // __SSEPLUS_SSE3_H__
