//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_NATIVE_SSE2_H__
#define __SSEPLUS_NATIVE_SSE2_H__

#include "../SSEPlus_base.h"
#include <emmintrin.h>  // SSE2

/** @addtogroup native_SSE2  
 *  @{ 
 *  @name Native SSE2 Operations
 */


/** \SSE2{Native,_mm_add_epi16} */ 
SSP_FORCEINLINE __m128i ssp_add_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_add_epi16( a, b );
}
/** \SSE2{Native,_mm_add_epi32} */ 
SSP_FORCEINLINE __m128i ssp_add_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_add_epi32( a, b );
}
/** \SSE2{Native,_mm_add_epi64} */ 
SSP_FORCEINLINE __m128i ssp_add_epi64_SSE2( __m128i a, __m128i b )
{
    return _mm_add_epi64( a, b );
}
/** \SSE2{Native,_mm_add_epi8} */ 
SSP_FORCEINLINE __m128i ssp_add_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_add_epi8( a, b );
}
/** \SSE2{Native,_mm_add_pd} */ 
SSP_FORCEINLINE __m128d ssp_add_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_add_pd( a, b );
}
/** \SSE2{Native,_mm_add_sd} */ 
SSP_FORCEINLINE __m128d ssp_add_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_add_sd( a, b );
}
/** \SSE2{Native,_mm_add_si64} */ 
SSP_FORCEINLINE __m64 ssp_add_si64_SSE2( __m64 a, __m64 b)
{
    return _mm_add_si64( a, b );
}
/** \SSE2{Native,_mm_adds_epi16} */ 
SSP_FORCEINLINE __m128i ssp_adds_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_adds_epi16( a, b );
}
/** \SSE2{Native,_mm_adds_epi8} */ 
SSP_FORCEINLINE __m128i ssp_adds_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_adds_epi8( a, b );
}
/** \SSE2{Native,_mm_adds_epu16} */ 
SSP_FORCEINLINE __m128i ssp_adds_epu16_SSE2( __m128i a, __m128i b )
{
    return _mm_adds_epu16( a, b );
}
/** \SSE2{Native,_mm_adds_epu8} */ 
SSP_FORCEINLINE __m128i ssp_adds_epu8_SSE2( __m128i a, __m128i b )
{
    return _mm_adds_epu8( a, b );
}
/** \SSE2{Native,_mm_and_pd} */ 
SSP_FORCEINLINE __m128d ssp_and_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_and_pd( a, b );
}
/** \SSE2{Native,_mm_and_si128} */ 
SSP_FORCEINLINE __m128i ssp_and_si128_SSE2( __m128i a, __m128i b )
{
    return _mm_and_si128( a, b );
}
/** \SSE2{Native,_mm_andnot_pd} */ 
SSP_FORCEINLINE __m128d ssp_andnot_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_andnot_pd( a, b );
}
/** \SSE2{Native,_mm_andnot_si128} */ 
SSP_FORCEINLINE __m128i ssp_andnot_si128_SSE2( __m128i a, __m128i b )
{
    return _mm_andnot_si128( a, b );
}
/** \SSE2{Native,_mm_avg_epu16} */ 
SSP_FORCEINLINE __m128i ssp_avg_epu16_SSE2( __m128i a, __m128i b )
{
    return _mm_avg_epu16( a, b );
}
/** \SSE2{Native,_mm_avg_epu8} */ 
SSP_FORCEINLINE __m128i ssp_avg_epu8_SSE2( __m128i a, __m128i b )
{
    return _mm_avg_epu8( a, b );
}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
//SSE2{Native,_mm_castpd_ps}
//SSP_FORCEINLINE __m128 ssp_castpd_ps_SSE2( __m128d a )
//{
//    return _mm_castpd_ps( a );
//}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
//SSE2{Native,_mm_castpd_si128}
//SSP_FORCEINLINE __m128i ssp_castpd_si128_SSE2( __m128d a )
//{
//    return _mm_castpd_si128( a );
//}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
//SSE2{Native,_mm_castps_pd}  
//SSP_FORCEINLINE __m128d ssp_castps_pd_SSE2( __m128 a )
//{
//    return _mm_castps_pd( a );
//}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
//SSE2{Native,_mm_castps_si128} 
//SSP_FORCEINLINE __m128i ssp_castps_si128_SSE2( __m128 a )
//{
//    return _mm_castps_si128( a );
//}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
//SSE2{Native,_mm_castsi128_pd} 
//SSP_FORCEINLINE __m128d ssp_castsi128_pd_SSE2( __m128i a )
//{
//    return _mm_castsi128_pd( a );
//}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
//SSE2{Native,_mm_castsi128_ps} 
//SSP_FORCEINLINE __m128 ssp_castsi128_ps_SSE2( __m128i a )
//{
//    return _mm_castsi128_ps( a );
//}

/** \SSE2{Native,_mm_clflush} */ 
SSP_FORCEINLINE void ssp_clflush_SSE2( void const *p )
{
    _mm_clflush( p );
}
/** \SSE2{Native,_mm_cmpeq_epi16} */ 
SSP_FORCEINLINE __m128i ssp_cmpeq_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_cmpeq_epi16( a, b );
}
/** \SSE2{Native,_mm_cmpeq_epi32} */ 
SSP_FORCEINLINE __m128i ssp_cmpeq_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_cmpeq_epi32( a, b );
}
/** \SSE2{Native,_mm_cmpeq_epi8} */ 
SSP_FORCEINLINE __m128i ssp_cmpeq_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_cmpeq_epi8( a, b );
}
/** \SSE2{Native,_mm_cmpeq_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpeq_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpeq_pd( a, b );
}
/** \SSE2{Native,_mm_cmpeq_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpeq_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpeq_sd( a, b );
}
/** \SSE2{Native,_mm_cmpge_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpge_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpge_pd( a, b );
}
/** \SSE2{Native,_mm_cmpge_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpge_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpge_sd( a, b );
}
/** \SSE2{Native,_mm_cmpgt_epi16} */ 
SSP_FORCEINLINE __m128i ssp_cmpgt_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_cmpgt_epi16( a, b );
}
/** \SSE2{Native,_mm_cmpgt_epi32} */ 
SSP_FORCEINLINE __m128i ssp_cmpgt_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_cmpgt_epi32( a, b );
}
/** \SSE2{Native,_mm_cmpgt_epi8} */ 
SSP_FORCEINLINE __m128i ssp_cmpgt_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_cmpgt_epi8( a, b );
}
/** \SSE2{Native,_mm_cmpgt_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpgt_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpgt_pd( a, b );
}
/** \SSE2{Native,_mm_cmpgt_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpgt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpgt_sd( a, b );
}
/** \SSE2{Native,_mm_cmple_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmple_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmple_pd( a, b );
}
/** \SSE2{Native,_mm_cmple_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmple_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmple_sd( a, b );
}
/** \SSE2{Native,_mm_cmplt_epi16} */ 
SSP_FORCEINLINE __m128i ssp_cmplt_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_cmplt_epi16( a, b );
}
/** \SSE2{Native,_mm_cmplt_epi32} */ 
SSP_FORCEINLINE __m128i ssp_cmplt_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_cmplt_epi32( a, b );
}
/** \SSE2{Native,_mm_cmplt_epi8} */ 
SSP_FORCEINLINE __m128i ssp_cmplt_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_cmplt_epi8( a, b );
}
/** \SSE2{Native,_mm_cmplt_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmplt_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmplt_pd( a, b );
}
/** \SSE2{Native,_mm_cmplt_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmplt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmplt_sd( a, b );
}
/** \SSE2{Native,_mm_cmpneq_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpneq_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpneq_pd( a, b );
}
/** \SSE2{Native,_mm_cmpneq_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpneq_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpneq_sd( a, b );
}
/** \SSE2{Native,_mm_cmpnge_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpnge_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpnge_pd( a, b );
}
/** \SSE2{Native,_mm_cmpnge_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpnge_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpnge_sd( a, b );
}
/** \SSE2{Native,_mm_cmpngt_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpngt_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpngt_pd( a, b );
}
/** \SSE2{Native,_mm_cmpngt_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpngt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpngt_sd( a, b );
}
/** \SSE2{Native,_mm_cmpnle_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpnle_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpnle_pd( a, b );
}
/** \SSE2{Native,_mm_cmpnle_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpnle_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpnle_sd( a, b );
}
/** \SSE2{Native,_mm_cmpnlt_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpnlt_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpnlt_pd( a, b );
}
/** \SSE2{Native,_mm_cmpnlt_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpnlt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpnlt_sd( a, b );
}
/** \SSE2{Native,_mm_cmpord_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpord_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpord_pd( a, b );
}
/** \SSE2{Native,_mm_cmpord_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpord_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpord_sd( a, b );
}
/** \SSE2{Native,_mm_cmpunord_pd} */ 
SSP_FORCEINLINE __m128d ssp_cmpunord_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpunord_pd( a, b );
}
/** \SSE2{Native,_mm_cmpunord_sd} */ 
SSP_FORCEINLINE __m128d ssp_cmpunord_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_cmpunord_sd( a, b );
}
/** \SSE2{Native,_mm_comieq_sd} */ 
SSP_FORCEINLINE int ssp_comieq_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_comieq_sd( a, b );
}
/** \SSE2{Native,_mm_comige_sd} */ 
SSP_FORCEINLINE int ssp_comige_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_comige_sd( a, b );
}
/** \SSE2{Native,_mm_comigt_sd} */ 
SSP_FORCEINLINE int ssp_comigt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_comigt_sd( a, b );
}
/** \SSE2{Native,_mm_comile_sd} */ 
SSP_FORCEINLINE int ssp_comile_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_comile_sd( a, b );
}
/** \SSE2{Native,_mm_comilt_sd} */ 
SSP_FORCEINLINE int ssp_comilt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_comilt_sd( a, b );
}
/** \SSE2{Native,_mm_comineq_sd} */ 
SSP_FORCEINLINE int ssp_comineq_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_comineq_sd( a, b );
}
/** \SSE2{Native,_mm_cvtepi32_pd} */ 
SSP_FORCEINLINE __m128d ssp_cvtepi32_pd_SSE2( __m128i a )
{
    return _mm_cvtepi32_pd( a );
}
/** \SSE2{Native,_mm_cvtepi32_ps} */ 
SSP_FORCEINLINE __m128 ssp_cvtepi32_ps_SSE2( __m128i a )
{
    return _mm_cvtepi32_ps( a );
}
/** \SSE2{Native,_mm_cvtpd_epi32} */ 
SSP_FORCEINLINE __m128i ssp_cvtpd_epi32_SSE2( __m128d a )
{
    return _mm_cvtpd_epi32( a );
}
/** \SSE2{Native,_mm_cvtpd_pi32} */ 
SSP_FORCEINLINE __m64 ssp_cvtpd_pi32_SSE2( __m128d a )
{
    return _mm_cvtpd_pi32( a );
}
/** \SSE2{Native,_mm_cvtpd_ps} */ 
SSP_FORCEINLINE __m128 ssp_cvtpd_ps_SSE2( __m128d a )
{
    return _mm_cvtpd_ps( a );
}
/** \SSE2{Native,_mm_cvtpi32_pd} */ 
SSP_FORCEINLINE __m128d ssp_cvtpi32_pd_SSE2( __m64 a )
{
    return _mm_cvtpi32_pd( a );
}
/** \SSE2{Native,_mm_cvtps_epi32} */ 
SSP_FORCEINLINE __m128i ssp_cvtps_epi32_SSE2( __m128 a )
{
    return _mm_cvtps_epi32( a );
}
/** \SSE2{Native,_mm_cvtps_pd} */ 
SSP_FORCEINLINE __m128d ssp_cvtps_pd_SSE2( __m128 a )
{
    return _mm_cvtps_pd( a );
}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
//SSE2{Native,_mm_cvtsd_f64} */ 
//SSP_FORCEINLINE double ssp_cvtsd_f64_SSE2( __m128d a )
//{
//    return _mm_cvtsd_f64( a );
//}

/** \SSE2{Native,_mm_cvtsd_si32} */ 
SSP_FORCEINLINE int ssp_cvtsd_si32_SSE2( __m128d a )
{
    return _mm_cvtsd_si32( a );
}
#ifdef SYS64
//// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
///** \SSE2{Native,_mm_cvtsd_si64} */ 
//SSP_FORCEINLINE __int64 ssp_cvtsd_si64_SSE2( __m128d a )
//{
//    return _mm_cvtsd_si64( a );
//}
#endif
/** \SSE2{Native,_mm_cvtsd_ss} */ 
SSP_FORCEINLINE __m128 ssp_cvtsd_ss_SSE2( __m128 a, __m128d b )
{
    return _mm_cvtsd_ss( a, b );
}
/** \SSE2{Native,_mm_cvtsi128_si32} */ 
SSP_FORCEINLINE int ssp_cvtsi128_si32_SSE2( __m128i a )
{
    return _mm_cvtsi128_si32( a );
}
#ifdef SYS64
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
///** \SSE2{Native,_mm_cvtsi128_si64} */ 
//SSP_FORCEINLINE __int64 ssp_cvtsi128_si64_SSE2( __m128i a )
//{
//    return _mm_cvtsi128_si64( a );
//}
#endif
/** \SSE2{Native,_mm_cvtsi32_sd} */ 
SSP_FORCEINLINE __m128d ssp_cvtsi32_sd_SSE2( __m128d a, int b )
{
    return _mm_cvtsi32_sd( a, b );
}
/** \SSE2{Native,_mm_cvtsi32_si128} */ 
SSP_FORCEINLINE __m128i ssp_cvtsi32_si128_SSE2( int a )
{
    return _mm_cvtsi32_si128( a );
}
#ifdef SYS64
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
///** \SSE2{Native,_mm_cvtsi64_sd} */ 
//SSP_FORCEINLINE __m128d ssp_cvtsi64_sd_SSE2( __m128d a, __int64 b )
//{
//    return _mm_cvtsi64_sd( a, b );
//}
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
///** \SSE2{Native,_mm_cvtsi64_si128} */ 
//SSP_FORCEINLINE __m128i ssp_cvtsi64_si128_SSE2( __int64 a )
//{
//    return _mm_cvtsi64_si128( a );
//}
#endif
/** \SSE2{Native,_mm_cvtss_sd} */ 
SSP_FORCEINLINE __m128d ssp_cvtss_sd_SSE2( __m128d a, __m128 b )
{
    return _mm_cvtss_sd( a, b );
}
/** \SSE2{Native,_mm_cvttpd_epi32} */ 
SSP_FORCEINLINE __m128i ssp_cvttpd_epi32_SSE2( __m128d a )
{
    return _mm_cvttpd_epi32( a );
}
/** \SSE2{Native,_mm_cvttpd_pi32} */ 
SSP_FORCEINLINE __m64 ssp_cvttpd_pi32_SSE2( __m128d a )
{
    return _mm_cvttpd_pi32( a );
}
/** \SSE2{Native,_mm_cvttps_epi32} */ 
SSP_FORCEINLINE __m128i ssp_cvttps_epi32_SSE2( __m128 a )
{
    return _mm_cvttps_epi32( a );
}
/** \SSE2{Native,_mm_cvttsd_si32} */ 
SSP_FORCEINLINE int ssp_cvttsd_si32_SSE2( __m128d a )
{
    return _mm_cvttsd_si32( a );
}
#ifdef SYS64
// *** Microsoft Specific Intrinsic TODO: Write Reference for VS8
///** \SSE2{Native,_mm_cvttsd_si64} */ 
//SSP_FORCEINLINE __int64 ssp_cvttsd_si64_SSE2( __m128d a )
//{
//    return _mm_cvttsd_si64( a );
//}
#endif
/** \SSE2{Native,_mm_div_pd} */ 
SSP_FORCEINLINE __m128d ssp_div_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_div_pd( a, b );
}
/** \SSE2{Native,_mm_div_sd} */ 
SSP_FORCEINLINE __m128d ssp_div_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_div_sd( a, b );
}
/** \SSE2{Native,_mm_extract_epi16} */ 
SSP_FORCEINLINE int ssp_extract_epi16_SSE2( __m128i a, int imm )
{
    switch( imm & 0x7 )
    {
        CASE_8( _mm_extract_epi16, a );
    }
}
/** \SSE2{Native,_mm_insert_epi16} */ 
SSP_FORCEINLINE __m128i ssp_insert_epi16_SSE2( __m128i a, int b, int imm )
{
    switch( imm & 0x7 )
    {
        CASE_8( _mm_insert_epi16, a, b );
    }
}
/** \SSE2{Native,_mm_lfence} */ 
SSP_FORCEINLINE void ssp_lfence_SSE2( void )
{
    _mm_lfence();
}
/** \SSE2{Native,_mm_load_pd} */ 
SSP_FORCEINLINE __m128d ssp_load_pd_SSE2( double const*dp )
{
    return _mm_load_pd( dp );
}
/** \SSE2{Native,_mm_load_sd} */ 
SSP_FORCEINLINE __m128d ssp_load_sd_SSE2( double const*dp )
{
    return _mm_load_sd( dp );
}
/** \SSE2{Native,_mm_load_si128} */ 
SSP_FORCEINLINE __m128i ssp_load_si128_SSE2( __m128i const*p )
{
    return _mm_load_si128( p );
}
/** \SSE2{Native,_mm_load1_pd} */ 
SSP_FORCEINLINE __m128d ssp_load1_pd_SSE2( double const*dp )
{
    return _mm_load1_pd( dp );
}
/** \SSE2{Native,_mm_loadh_pd} */ 
SSP_FORCEINLINE __m128d ssp_loadh_pd_SSE2( __m128d a, double const*dp )
{
    return _mm_loadh_pd( a, dp );
}
/** \SSE2{Native,_mm_loadl_epi64} */ 
SSP_FORCEINLINE __m128i ssp_loadl_epi64_SSE2( __m128i const*p)
{
    return _mm_loadl_epi64( p );
}
/** \SSE2{Native,_mm_loadl_pd} */ 
SSP_FORCEINLINE __m128d ssp_loadl_pd_SSE2( __m128d a, double const*dp )
{
    return _mm_loadl_pd( a, dp );
}
/** \SSE2{Native,_mm_loadr_pd} */ 
SSP_FORCEINLINE __m128d ssp_loadr_pd_SSE2( double const*dp )
{
    return _mm_loadr_pd( dp );
}
/** \SSE2{Native,_mm_loadu_pd} */ 
SSP_FORCEINLINE __m128d ssp_loadu_pd_SSE2( double const*dp )
{
    return _mm_loadu_pd( dp );
}
/** \SSE2{Native,_mm_loadu_si128} */ 
SSP_FORCEINLINE __m128i ssp_loadu_si128_SSE2( __m128i const*p )
{
    return _mm_loadu_si128( p );
}
/** \SSE2{Native,_mm_madd_epi16} */ 
SSP_FORCEINLINE __m128i ssp_madd_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_madd_epi16( a, b );
}
/** \SSE2{Native,_mm_maskmoveu_si128} */ 
SSP_FORCEINLINE void ssp_maskmoveu_si128_SSE2( __m128i a, __m128i b, char *c )
{
    _mm_maskmoveu_si128( a, b, c );
}
/** \SSE2{Native,_mm_max_epi16} */ 
SSP_FORCEINLINE __m128i ssp_max_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_max_epi16( a, b );
}
/** \SSE2{Native,_mm_max_epu8} */ 
SSP_FORCEINLINE __m128i ssp_max_epu8_SSE2( __m128i a, __m128i b )
{
    return _mm_max_epu8( a, b );
}
/** \SSE2{Native,_mm_max_pd} */ 
SSP_FORCEINLINE __m128d ssp_max_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_max_pd( a, b );
}
/** \SSE2{Native,_mm_max_sd} */ 
SSP_FORCEINLINE __m128d ssp_max_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_max_sd( a, b );
}
/** \SSE2{Native,_mm_mfence} */ 
SSP_FORCEINLINE void ssp_mfence_SSE2( void )
{
    _mm_mfence( );
}
/** \SSE2{Native,_mm_min_epi16} */ 
SSP_FORCEINLINE __m128i ssp_min_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_min_epi16( a, b );
}
/** \SSE2{Native,_mm_min_epu8} */ 
SSP_FORCEINLINE __m128i ssp_min_epu8_SSE2( __m128i a, __m128i b )
{
    return _mm_min_epu8( a, b );
}
/** \SSE2{Native,_mm_min_pd} */ 
SSP_FORCEINLINE __m128d ssp_min_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_min_pd( a, b );
}
/** \SSE2{Native,_mm_min_sd} */ 
SSP_FORCEINLINE __m128d ssp_min_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_min_sd( a, b );
}
/** \SSE2{Native,_mm_move_epi64} */ 
SSP_FORCEINLINE __m128i ssp_move_epi64_SSE2( __m128i a )
{
    return _mm_move_epi64( a );
}
/** \SSE2{Native,_mm_move_sd} */ 
SSP_FORCEINLINE __m128d ssp_move_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_move_sd( a, b );
}
/** \SSE2{Native,_mm_movemask_epi8} */ 
SSP_FORCEINLINE int ssp_movemask_epi8_SSE2( __m128i a )
{
    return _mm_movemask_epi8( a );
}
/** \SSE2{Native,_mm_movemask_pd} */ 
SSP_FORCEINLINE int ssp_movemask_pd_SSE2( __m128d a )
{
    return _mm_movemask_pd( a );
}
/** \SSE2{Native,_mm_movepi64_pi64} */ 
SSP_FORCEINLINE __m64 ssp_movepi64_pi64_SSE2( __m128i a )
{
    return _mm_movepi64_pi64( a );
}
/** \SSE2{Native,_mm_movpi64_epi64} */ 
SSP_FORCEINLINE __m128i ssp_movpi64_epi64_SSE2( __m64 a )
{
    return _mm_movpi64_epi64( a );
}
/** \SSE2{Native,_mm_mul_epu32} */ 
SSP_FORCEINLINE __m128i ssp_mul_epu32_SSE2( __m128i a, __m128i b )
{
    return _mm_mul_epu32( a, b );
}
/** \SSE2{Native,_mm_mul_pd} */ 
SSP_FORCEINLINE __m128d ssp_mul_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_mul_pd( a, b );
}
/** \SSE2{Native,_mm_mul_sd} */ 
SSP_FORCEINLINE __m128d ssp_mul_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_mul_sd( a, b );
}
/** \SSE2{Native,_mm_mul_su32} */ 
SSP_FORCEINLINE __m64 ssp_mul_su32_SSE2( __m64 a, __m64 b)
{
    return _mm_mul_su32( a, b );
}
/** \SSE2{Native,_mm_mulhi_epi16} */ 
SSP_FORCEINLINE __m128i ssp_mulhi_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_mulhi_epi16( a, b );
}
/** \SSE2{Native,_mm_mulhi_epu16} */ 
SSP_FORCEINLINE __m128i ssp_mulhi_epu16_SSE2( __m128i a, __m128i b )
{
    return _mm_mulhi_epu16( a, b );
}
/** \SSE2{Native,_mm_mullo_epi16} */ 
SSP_FORCEINLINE __m128i ssp_mullo_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_mullo_epi16( a, b );
}
/** \SSE2{Native,_mm_or_pd} */ 
SSP_FORCEINLINE __m128d ssp_or_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_or_pd( a, b );
}
/** \SSE2{Native,_mm_or_si128} */ 
SSP_FORCEINLINE __m128i ssp_or_si128_SSE2( __m128i a, __m128i b )
{
    return _mm_or_si128( a, b );
}
/** \SSE2{Native,_mm_packs_epi16} */ 
SSP_FORCEINLINE __m128i ssp_packs_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_packs_epi16( a, b );
}
/** \SSE2{Native,_mm_packs_epi32} */ 
SSP_FORCEINLINE __m128i ssp_packs_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_packs_epi32( a, b );
}
/** \SSE2{Native,_mm_packus_epi16} */ 
SSP_FORCEINLINE __m128i ssp_packus_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_packus_epi16( a, b );
}
/** \SSE2{Native,_mm_pause} */ 
SSP_FORCEINLINE void ssp_pause_SSE2( void )
{
    _mm_pause();
}
/** \SSE2{Native,_mm_sad_epu8} */ 
SSP_FORCEINLINE __m128i ssp_sad_epu8_SSE2( __m128i a, __m128i b )
{
    return _mm_sad_epu8( a, b );
}
/** \SSE2{Native,_mm_set_epi16} */ 
SSP_FORCEINLINE __m128i ssp_set_epi16_SSE2( short w7, short w6, short w5, short w4, short w3, short w2, short w1, short w0 )
{
    return _mm_set_epi16( w7, w6, w5, w4, w3, w2, w1, w0 );
}
/** \SSE2{Native,_mm_set_epi32} */ 
SSP_FORCEINLINE __m128i ssp_set_epi32_SSE2( int i3, int i2, int i1, int i0 )
{
    return _mm_set_epi32( i3, i2, i1, i0 );
}
/** \SSE2{Native,_mm_set_epi64} */ 
SSP_FORCEINLINE __m128i ssp_set_epi64_SSE2( __m64 a1, __m64 a0 )
{
    return _mm_set_epi64( a1, a0 );
}
/** \SSE2{Native,_mm_set_epi8} */ 
SSP_FORCEINLINE __m128i ssp_set_epi8_SSE2( char b15, char b14, char b13, char b12, char b11, char b10, char b9, char b8, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0 )
{
    return _mm_set_epi8( b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0 );
}
/** \SSE2{Native,_mm_set_pd} */ 
SSP_FORCEINLINE __m128d ssp_set_pd_SSE2( double a1, double a0)
{
    return _mm_set_pd( a1, a0 );
}
/** \SSE2{Native,_mm_set_sd} */ 
SSP_FORCEINLINE __m128d ssp_set_sd_SSE2( double w)
{
    return _mm_set_sd( w );
}
/** \SSE2{Native,_mm_set1_epi16} */ 
SSP_FORCEINLINE __m128i ssp_set1_epi16_SSE2( short w)
{
    return _mm_set1_epi16( w );
}
/** \SSE2{Native,_mm_set1_epi32} */ 
SSP_FORCEINLINE __m128i ssp_set1_epi32_SSE2( int i )
{
    return _mm_set1_epi32( i );
}
/** \SSE2{Native,_mm_set1_epi64} */ 
SSP_FORCEINLINE __m128i ssp_set1_epi64_SSE2( __m64 a )
{
    return _mm_set1_epi64( a );
}
/** \SSE2{Native,_mm_set1_epi8} */ 
SSP_FORCEINLINE __m128i ssp_set1_epi8_SSE2( char b )
{
    return _mm_set1_epi8( b );
}
/** \SSE2{Native,_mm_set1_pd} */ 
SSP_FORCEINLINE __m128d ssp_set1_pd_SSE2( double a )
{
    return _mm_set1_pd( a );
}
// Composite intrinsic not supported in GCC
#ifdef SSP_MSVC
/** \SSE2{Native,_mm_setl_epi64} */ 
SSP_FORCEINLINE __m128i ssp_setl_epi64_SSE2( __m128i a )
{
    return _mm_setl_epi64( a );
}
#endif
/** \SSE2{Native,_mm_setr_epi16} */ 
SSP_FORCEINLINE __m128i ssp_setr_epi16_SSE2( short w0, short w1, short w2, short w3, short w4, short w5, short w6, short w7 )
{
    return _mm_setr_epi16( w0, w1, w2, w3, w4, w5, w6, w7 );
}
/** \SSE2{Native,_mm_setr_epi32} */ 
SSP_FORCEINLINE __m128i ssp_setr_epi32_SSE2( int i0, int i1, int i2, int i3)
{
    return _mm_setr_epi32( i0, i1, i2, i3);
}
/** \SSE2{Native,_mm_setr_epi64} */ 
SSP_FORCEINLINE __m128i ssp_setr_epi64_SSE2( __m64 a0, __m64 a1)
{
    return _mm_setr_epi64( a0, a1);
}
/** \SSE2{Native,_mm_setr_epi8} */ 
SSP_FORCEINLINE __m128i ssp_setr_epi8_SSE2( char b15, char b14, char b13, char b12, char b11, char b10, char b9, char b8, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0 )
{
    return _mm_setr_epi8( b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0 );
}
/** \SSE2{Native,_mm_setr_pd} */ 
SSP_FORCEINLINE __m128d ssp_setr_pd_SSE2( double a0, double a1 )
{
    return _mm_setr_pd( a0, a1);
}
/** \SSE2{Native,_mm_setzero_pd} */ 
SSP_FORCEINLINE __m128d ssp_setzero_pd_SSE2( void )
{
    return _mm_setzero_pd( );
}
/** \SSE2{Native,_mm_setzero_si128} */ 
SSP_FORCEINLINE __m128i ssp_setzero_si128_SSE2( void )
{
    return _mm_setzero_si128( );
}
/** \SSE2{Native,_mm_shuffle_epi32} */ 
SSP_FORCEINLINE __m128i ssp_shuffle_epi32_SSE2( __m128i a, int imm )
{
    switch( imm & 0xFF )
    {
        CASE_256( _mm_shuffle_epi32, a );
    }
}
/** \SSE2{Native,_mm_shuffle_pd} */ 
SSP_FORCEINLINE __m128d ssp_shuffle_pd_SSE2( __m128d a, __m128d b, int imm )
{
    switch( imm & 0xFF )
    {
        CASE_4( _mm_shuffle_pd, a, b );
    }
}
/** \SSE2{Native,_mm_shufflehi_epi16} */ 
SSP_FORCEINLINE __m128i ssp_shufflehi_epi16_SSE2( __m128i a, int imm )
{
    switch( imm & 0xFF )
    {
        CASE_256( _mm_shufflehi_epi16, a );
    }
}
/** \SSE2{Native,_mm_shufflelo_epi16} */ 
SSP_FORCEINLINE __m128i ssp_shufflelo_epi16_SSE2( __m128i a, int imm )
{
    switch( imm & 0xFF )
    {
        CASE_256( _mm_shufflelo_epi16, a );
    }
}
/** \SSE2{Native,_mm_sll_epi16} */ 
SSP_FORCEINLINE __m128i ssp_sll_epi16_SSE2( __m128i a, __m128i count )
{
    return _mm_sll_epi16( a, count );
}
/** \SSE2{Native,_mm_sll_epi32} */ 
SSP_FORCEINLINE __m128i ssp_sll_epi32_SSE2( __m128i a, __m128i count )
{
    return _mm_sll_epi32( a, count );
}
/** \SSE2{Native,_mm_sll_epi64} */ 
SSP_FORCEINLINE __m128i ssp_sll_epi64_SSE2( __m128i a, __m128i count )
{
    return _mm_sll_epi64( a, count );
}
/** \SSE2{Native,_mm_slli_epi16} */ 
SSP_FORCEINLINE __m128i ssp_slli_epi16_SSE2( __m128i a, int count )
{
    return _mm_slli_epi16( a, count );
}
/** \SSE2{Native,_mm_slli_epi32} */ 
SSP_FORCEINLINE __m128i ssp_slli_epi32_SSE2( __m128i a, int count )
{
    return _mm_slli_epi32( a, count );
}
/** \SSE2{Native,_mm_slli_epi64} */ 
SSP_FORCEINLINE __m128i ssp_slli_epi64_SSE2( __m128i a, int count )
{
    return _mm_slli_epi64( a, count );
}
/** \SSE2{Native,_mm_slli_si128} */ 
SSP_FORCEINLINE __m128i ssp_slli_si128_SSE2( __m128i a, int imm )
{
    switch( imm & 0x7F )
    {
        CASE_128( _mm_slli_si128, a );
    }
}
/** \SSE2{Native,_mm_sqrt_pd} */ 
SSP_FORCEINLINE __m128d ssp_sqrt_pd_SSE2( __m128d a )
{
    return _mm_sqrt_pd( a );
}
/** \SSE2{Native,_mm_sqrt_sd} */ 
SSP_FORCEINLINE __m128d ssp_sqrt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_sqrt_sd( a, b );
}
/** \SSE2{Native,_mm_sra_epi16} */ 
SSP_FORCEINLINE __m128i ssp_sra_epi16_SSE2( __m128i a, __m128i count )
{
    return _mm_sra_epi16( a, count );
}
/** \SSE2{Native,_mm_sra_epi32} */ 
SSP_FORCEINLINE __m128i ssp_sra_epi32_SSE2( __m128i a, __m128i count )
{
    return _mm_sra_epi32( a, count );
}
/** \SSE2{Native,_mm_srai_epi16} */ 
SSP_FORCEINLINE __m128i ssp_srai_epi16_SSE2( __m128i a, int count )
{
    return _mm_srai_epi16( a, count );
}
/** \SSE2{Native,_mm_srai_epi32} */ 
SSP_FORCEINLINE __m128i ssp_srai_epi32_SSE2( __m128i a, int count )
{
    return _mm_srai_epi32( a, count );
}
/** \SSE2{Native,_mm_srl_epi16} */ 
SSP_FORCEINLINE __m128i ssp_srl_epi16_SSE2( __m128i a, __m128i count )
{
    return _mm_srl_epi16( a, count );
}
/** \SSE2{Native,_mm_srl_epi32} */ 
SSP_FORCEINLINE __m128i ssp_srl_epi32_SSE2( __m128i a, __m128i count )
{
    return _mm_srl_epi32( a, count );
}
/** \SSE2{Native,_mm_srl_epi64} */ 
SSP_FORCEINLINE __m128i ssp_srl_epi64_SSE2( __m128i a, __m128i count )
{
    return _mm_srl_epi64( a, count );
}
/** \SSE2{Native,_mm_srli_epi16} */ 
SSP_FORCEINLINE __m128i ssp_srli_epi16_SSE2( __m128i a, int count )
{
    return _mm_srli_epi16( a, count );
}
/** \SSE2{Native,_mm_srli_epi32} */ 
SSP_FORCEINLINE __m128i ssp_srli_epi32_SSE2( __m128i a, int count )
{
    return _mm_srli_epi32( a, count );
}
/** \SSE2{Native,_mm_srli_epi64} */ 
SSP_FORCEINLINE __m128i ssp_srli_epi64_SSE2( __m128i a, int count )
{
    return _mm_srli_epi64( a, count );
}
/** \SSE2{Native,_mm_srli_si128} */ 
SSP_FORCEINLINE __m128i ssp_srli_si128_SSE2( __m128i a, int imm )
{
    switch( imm & 0x7F )
    {
        CASE_128( _mm_srli_si128, a );
    }
}
/** \SSE2{Native,_mm_store_pd} */ 
SSP_FORCEINLINE void ssp_store_pd_SSE2( double *dp, __m128d a )
{
    _mm_store_pd( dp, a );
}
/** \SSE2{Native,_mm_store_sd} */ 
SSP_FORCEINLINE void ssp_store_sd_SSE2( double *dp, __m128d a )
{
    _mm_store_sd( dp, a );
}
/** \SSE2{Native,_mm_store_si128} */ 
SSP_FORCEINLINE void ssp_store_si128_SSE2( __m128i *p, __m128i b )
{
    _mm_store_si128( p, b );
}
/** \SSE2{Native,_mm_store1_pd} */ 
SSP_FORCEINLINE void ssp_store1_pd_SSE2( double *dp, __m128d a )
{
    _mm_store1_pd( dp, a );
}
/** \SSE2{Native,_mm_storeh_pd} */ 
SSP_FORCEINLINE void ssp_storeh_pd_SSE2( double *dp, __m128d a )
{
    _mm_storeh_pd( dp, a );
}
/** \SSE2{Native,_mm_storel_epi64} */ 
SSP_FORCEINLINE void ssp_storel_epi64_SSE2( __m128i *p, __m128i b )
{
    _mm_storel_epi64( p, b );
}
/** \SSE2{Native,_mm_storel_pd} */ 
SSP_FORCEINLINE void ssp_storel_pd_SSE2( double *dp, __m128d a )
{
    _mm_storel_pd( dp, a );
}
/** \SSE2{Native,_mm_storer_pd} */ 
SSP_FORCEINLINE void ssp_storer_pd_SSE2( double *dp, __m128d a )
{
    _mm_storer_pd( dp, a );
}
/** \SSE2{Native,_mm_storeu_pd} */ 
SSP_FORCEINLINE void ssp_storeu_pd_SSE2( double *dp, __m128d a )
{
    _mm_storeu_pd( dp, a );
}
/** \SSE2{Native,_mm_storeu_si128} */ 
SSP_FORCEINLINE void ssp_storeu_si128_SSE2( __m128i *p, __m128i b )
{
    _mm_storeu_si128( p, b );
}
/** \SSE2{Native,_mm_stream_pd} */ 
SSP_FORCEINLINE void ssp_stream_pd_SSE2( double *dp, __m128d a )
{
    _mm_stream_pd( dp, a );
}
/** \SSE2{Native,_mm_stream_si128} */ 
SSP_FORCEINLINE void ssp_stream_si128_SSE2( __m128i *p, __m128i a )
{
    _mm_stream_si128( p, a );
}
/** \SSE2{Native,_mm_stream_si32} */ 
SSP_FORCEINLINE void ssp_stream_si32_SSE2( int *p, int i )
{
    _mm_stream_si32( p, i );
}
/** \SSE2{Native,_mm_sub_epi16} */ 
SSP_FORCEINLINE __m128i ssp_sub_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_sub_epi16( a, b );
}
/** \SSE2{Native,_mm_sub_epi32} */ 
SSP_FORCEINLINE __m128i ssp_sub_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_sub_epi32( a, b );
}
/** \SSE2{Native,_mm_sub_epi64} */ 
SSP_FORCEINLINE __m128i ssp_sub_epi64_SSE2( __m128i a, __m128i b )
{
    return _mm_sub_epi64( a, b );
}
/** \SSE2{Native,_mm_sub_epi8} */ 
SSP_FORCEINLINE __m128i ssp_sub_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_sub_epi8( a, b );
}
/** \SSE2{Native,_mm_sub_pd} */ 
SSP_FORCEINLINE __m128d ssp_sub_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_sub_pd( a, b );
}
/** \SSE2{Native,_mm_sub_sd} */ 
SSP_FORCEINLINE __m128d ssp_sub_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_sub_sd( a, b );
}
/** \SSE2{Native,_mm_sub_si64} */ 
SSP_FORCEINLINE __m64 ssp_sub_si64_SSE2( __m64 a, __m64 b)
{
    return _mm_sub_si64( a, b );
}
/** \SSE2{Native,_mm_subs_epi16} */ 
SSP_FORCEINLINE __m128i ssp_subs_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_subs_epi16( a, b );
}
/** \SSE2{Native,_mm_subs_epi8} */ 
SSP_FORCEINLINE __m128i ssp_subs_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_subs_epi8( a, b );
}
/** \SSE2{Native,_mm_subs_epu16} */ 
SSP_FORCEINLINE __m128i ssp_subs_epu16_SSE2( __m128i a, __m128i b )
{
    return _mm_subs_epu16( a, b );
}
/** \SSE2{Native,_mm_subs_epu8} */ 
SSP_FORCEINLINE __m128i ssp_subs_epu8_SSE2( __m128i a, __m128i b )
{
    return _mm_subs_epu8( a, b );
}
/** \SSE2{Native,_mm_ucomieq_sd} */ 
SSP_FORCEINLINE int ssp_ucomieq_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_ucomieq_sd( a, b );
}
/** \SSE2{Native,_mm_ucomige_sd} */ 
SSP_FORCEINLINE int ssp_ucomige_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_ucomige_sd( a, b );
}
/** \SSE2{Native,_mm_ucomigt_sd} */ 
SSP_FORCEINLINE int ssp_ucomigt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_ucomigt_sd( a, b );
}
/** \SSE2{Native,_mm_ucomile_sd} */ 
SSP_FORCEINLINE int ssp_ucomile_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_ucomile_sd( a, b );
}
/** \SSE2{Native,_mm_ucomilt_sd} */ 
SSP_FORCEINLINE int ssp_ucomilt_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_ucomilt_sd( a, b );
}
/** \SSE2{Native,_mm_ucomineq_sd} */ 
SSP_FORCEINLINE int ssp_ucomineq_sd_SSE2( __m128d a, __m128d b )
{
    return _mm_ucomineq_sd( a, b );
}
/** \SSE2{Native,_mm_unpackhi_epi16} */ 
SSP_FORCEINLINE __m128i ssp_unpackhi_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_unpackhi_epi16( a, b );
}
/** \SSE2{Native,_mm_unpackhi_epi32} */ 
SSP_FORCEINLINE __m128i ssp_unpackhi_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_unpackhi_epi32( a, b );
}
/** \SSE2{Native,_mm_unpackhi_epi64} */ 
SSP_FORCEINLINE __m128i ssp_unpackhi_epi64_SSE2( __m128i a, __m128i b )
{
    return _mm_unpackhi_epi64( a, b );
}
/** \SSE2{Native,_mm_unpackhi_epi8} */ 
SSP_FORCEINLINE __m128i ssp_unpackhi_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_unpackhi_epi8( a, b );
}
/** \SSE2{Native,_mm_unpackhi_pd} */ 
SSP_FORCEINLINE __m128d ssp_unpackhi_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_unpackhi_pd( a, b );
}
/** \SSE2{Native,_mm_unpacklo_epi16} */ 
SSP_FORCEINLINE __m128i ssp_unpacklo_epi16_SSE2( __m128i a, __m128i b )
{
    return _mm_unpacklo_epi16( a, b );
}
/** \SSE2{Native,_mm_unpacklo_epi32} */ 
SSP_FORCEINLINE __m128i ssp_unpacklo_epi32_SSE2( __m128i a, __m128i b )
{
    return _mm_unpacklo_epi32( a, b );
}
/** \SSE2{Native,_mm_unpacklo_epi64} */ 
SSP_FORCEINLINE __m128i ssp_unpacklo_epi64_SSE2( __m128i a, __m128i b )
{
    return _mm_unpacklo_epi64( a, b );
}
/** \SSE2{Native,_mm_unpacklo_epi8} */ 
SSP_FORCEINLINE __m128i ssp_unpacklo_epi8_SSE2( __m128i a, __m128i b )
{
    return _mm_unpacklo_epi8( a, b );
}
/** \SSE2{Native,_mm_unpacklo_pd} */ 
SSP_FORCEINLINE __m128d ssp_unpacklo_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_unpacklo_pd( a, b );
}
/** \SSE2{Native,_mm_xor_pd} */ 
SSP_FORCEINLINE __m128d ssp_xor_pd_SSE2( __m128d a, __m128d b )
{
    return _mm_xor_pd( a, b );
}
/** \SSE2{Native,_mm_xor_si128} */ 
SSP_FORCEINLINE __m128i ssp_xor_si128_SSE2( __m128i a, __m128i b )
{
    return _mm_xor_si128( a, b );
}

//@}
//@}

#endif // __SSP_NATIVE_SSE2_H__
