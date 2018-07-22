//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_NATIVE_SSE_H__
#define __SSEPLUS_NATIVE_SSE_H__

#include "../SSEPlus_base.h"
#include <xmmintrin.h>  // SSE

/** @addtogroup native_SSE   
 *  @{ 
 *  @name Native SSE Operations
 */

/*
 * FP, arithmetic
 */

/** \SSE{Native,_mm_add_ss} */
SSP_FORCEINLINE __m128 ssp_add_ss_SSE( __m128 a, __m128 b )
{
    return _mm_add_ss( a, b );
}

/** \SSE{Native,_mm_add_ps} */
SSP_FORCEINLINE __m128 ssp_add_ps_SSE( __m128 a, __m128 b )
{
    return _mm_add_ps( a, b );
}

/** \SSE{Native,_mm_sub_ss} */
SSP_FORCEINLINE __m128 ssp_sub_ss_SSE( __m128 a, __m128 b )
{
    return _mm_sub_ss( a, b );
}

/** \SSE{Native,_mm_sub_ps} */
SSP_FORCEINLINE __m128 ssp_sub_ps_SSE( __m128 a, __m128 b )
{
    return _mm_sub_ps( a, b );
}

/** \SSE{Native,_mm_mul_ss} */
SSP_FORCEINLINE __m128 ssp_mul_ss_SSE( __m128 a, __m128 b )
{
    return _mm_mul_ss( a, b );
}

/** \SSE{Native,_mm_mul_ps} */
SSP_FORCEINLINE __m128 ssp_mul_ps_SSE( __m128 a, __m128 b )
{
    return _mm_mul_ps( a, b );
}

/** \SSE{Native,_mm_div_ss} */
SSP_FORCEINLINE __m128 ssp_div_ss_SSE( __m128 a, __m128 b )
{
    return _mm_div_ss( a, b );
}

/** \SSE{Native,_mm_div_ps} */
SSP_FORCEINLINE __m128 ssp_div_ps_SSE( __m128 a, __m128 b )
{
    return _mm_div_ps( a, b );
}

/** \SSE{Native,_mm_sqrt_ss} */
SSP_FORCEINLINE __m128 ssp_sqrt_ss_SSE( __m128 a )
{
    return _mm_sqrt_ss( a );
}

/** \SSE{Native,_mm_sqrt_ps} */
SSP_FORCEINLINE __m128 ssp_sqrt_ps_SSE( __m128 a )
{
    return _mm_sqrt_ps( a );
}

/** \SSE{Native,_mm_rcp_ss} */
SSP_FORCEINLINE __m128 ssp_rcp_ss_SSE( __m128 a )
{
    return _mm_rcp_ss( a );
}

/** \SSE{Native,_mm_rcp_ps} */
SSP_FORCEINLINE __m128 ssp_rcp_ps_SSE( __m128 a )
{
    return _mm_rcp_ps( a );
}

/** \SSE{Native,_mm_rsqrt_ss} */
SSP_FORCEINLINE __m128 ssp_rsqrt_ss_SSE( __m128 a )
{
    return _mm_rsqrt_ss( a );
}

/** \SSE{Native,_mm_rsqrt_ps} */
SSP_FORCEINLINE __m128 ssp_rsqrt_ps_SSE( __m128 a )
{
    return _mm_rsqrt_ps( a );
}

/** \SSE{Native,_mm_min_ss} */
SSP_FORCEINLINE __m128 ssp_min_ss_SSE( __m128 a, __m128 b )
{
    return _mm_min_ss( a, b );
}

/** \SSE{Native,_mm_min_ps} */
SSP_FORCEINLINE __m128 ssp_min_ps_SSE( __m128 a, __m128 b )
{
    return _mm_min_ps( a, b );
}

/** \SSE{Native,_mm_max_ss} */
SSP_FORCEINLINE __m128 ssp_max_ss_SSE( __m128 a, __m128 b )
{
    return _mm_max_ss( a, b );
}

/** \SSE{Native,_mm_max_ps} */
SSP_FORCEINLINE __m128 ssp_max_ps_SSE( __m128 a, __m128 b )
{
    return _mm_max_ps( a, b );
}

/** \SSE{Native,_mm_and_ps} */
SSP_FORCEINLINE __m128 ssp_and_ps_SSE( __m128 a, __m128 b )
{
    return _mm_and_ps( a, b );
}

/** \SSE{Native,_mm_andnot_ps} */
SSP_FORCEINLINE __m128 ssp_andnot_ps_SSE( __m128 a, __m128 b )
{
    return _mm_andnot_ps( a, b );
}

/** \SSE{Native,_mm_or_ps} */
SSP_FORCEINLINE __m128 ssp_or_ps_SSE( __m128 a, __m128 b )
{
    return _mm_or_ps( a, b );
}

/** \SSE{Native,_mm_xor_ps} */
SSP_FORCEINLINE __m128 ssp_xor_ps_SSE( __m128 a, __m128 b )
{
    return _mm_xor_ps( a, b );
}

/** \SSE{Native,_mm_cmpeq_ss} */
SSP_FORCEINLINE __m128 ssp_cmpeq_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpeq_ss( a, b );
}

/** \SSE{Native,_mm_cmpeq_ps} */
SSP_FORCEINLINE __m128 ssp_cmpeq_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpeq_ps( a, b );
}

/** \SSE{Native,_mm_cmplt_ss} */
SSP_FORCEINLINE __m128 ssp_cmplt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmplt_ss( a, b );
}

/** \SSE{Native,_mm_cmplt_ps} */
SSP_FORCEINLINE __m128 ssp_cmplt_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmplt_ps( a, b );
}

/** \SSE{Native,_mm_cmple_ss} */
SSP_FORCEINLINE __m128 ssp_cmple_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmple_ss( a, b );
}

/** \SSE{Native,_mm_cmple_ps} */
SSP_FORCEINLINE __m128 ssp_cmple_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmple_ps( a, b );
}

/** \SSE{Native,_mm_cmpgt_ss} */
SSP_FORCEINLINE __m128 ssp_cmpgt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpgt_ss( a, b );
}

/** \SSE{Native,_mm_cmpgt_ps} */
SSP_FORCEINLINE __m128 ssp_cmpgt_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpgt_ps( a, b );
}

/** \SSE{Native,_mm_cmpge_ss} */
SSP_FORCEINLINE __m128 ssp_cmpge_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpge_ss( a, b );
}

/** \SSE{Native,_mm_cmpge_ps} */
SSP_FORCEINLINE __m128 ssp_cmpge_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpge_ps( a, b );
}

/** \SSE{Native,_mm_cmpneq_ss} */
SSP_FORCEINLINE __m128 ssp_cmpneq_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpneq_ss( a, b );
}

/** \SSE{Native,_mm_cmpneq_ps} */
SSP_FORCEINLINE __m128 ssp_cmpneq_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpneq_ps( a, b );
}

/** \SSE{Native,_mm_cmpnlt_ss} */
SSP_FORCEINLINE __m128 ssp_cmpnlt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpnlt_ss( a, b );
}

/** \SSE{Native,_mm_cmpnlt_ps} */
SSP_FORCEINLINE __m128 ssp_cmpnlt_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpnlt_ps( a, b );
}

/** \SSE{Native,_mm_cmpnle_ss} */
SSP_FORCEINLINE __m128 ssp_cmpnle_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpnle_ss( a, b );
}

/** \SSE{Native,_mm_cmpnle_ps} */
SSP_FORCEINLINE __m128 ssp_cmpnle_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpnle_ps( a, b );
}

/** \SSE{Native,_mm_cmpngt_ss} */
SSP_FORCEINLINE __m128 ssp_cmpngt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpngt_ss( a, b );
}

/** \SSE{Native,_mm_cmpngt_ps} */
SSP_FORCEINLINE __m128 ssp_cmpngt_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpngt_ps( a, b );
}

/** \SSE{Native,_mm_cmpnge_ss} */
SSP_FORCEINLINE __m128 ssp_cmpnge_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpnge_ss( a, b );
}

/** \SSE{Native,_mm_cmpnge_ps} */
SSP_FORCEINLINE __m128 ssp_cmpnge_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpnge_ps( a, b );
}

/** \SSE{Native,_mm_cmpord_ss} */
SSP_FORCEINLINE __m128 ssp_cmpord_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpord_ss( a, b );
}

/** \SSE{Native,_mm_cmpord_ps} */
SSP_FORCEINLINE __m128 ssp_cmpord_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpord_ps( a, b );
}

/** \SSE{Native,_mm_cmpunord_ss} */
SSP_FORCEINLINE __m128 ssp_cmpunord_ss_SSE( __m128 a, __m128 b )
{
    return _mm_cmpunord_ss( a, b );
}

/** \SSE{Native,_mm_cmpunord_ps} */
SSP_FORCEINLINE __m128 ssp_cmpunord_ps_SSE( __m128 a, __m128 b )
{
    return _mm_cmpunord_ps( a, b );
}

/** \SSE{Native,_mm_comieq_ss} */
SSP_FORCEINLINE int ssp_comieq_ss_SSE( __m128 a, __m128 b )
{
    return _mm_comieq_ss( a, b );
}

/** \SSE{Native,_mm_comilt_ss} */
SSP_FORCEINLINE int ssp_comilt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_comilt_ss( a, b );
}

/** \SSE{Native,_mm_comile_ss} */
SSP_FORCEINLINE int ssp_comile_ss_SSE( __m128 a, __m128 b )
{
    return _mm_comile_ss( a, b );
}

/** \SSE{Native,_mm_comigt_ss} */
SSP_FORCEINLINE int ssp_comigt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_comigt_ss( a, b );
}

/** \SSE{Native,_mm_comige_ss} */
SSP_FORCEINLINE int ssp_comige_ss_SSE( __m128 a, __m128 b )
{
    return _mm_comige_ss( a, b );
}

/** \SSE{Native,_mm_comineq_ss} */
SSP_FORCEINLINE int ssp_comineq_ss_SSE( __m128 a, __m128 b )
{
    return _mm_comineq_ss( a, b );
}

/** \SSE{Native,_mm_ucomieq_ss} */
SSP_FORCEINLINE int ssp_ucomieq_ss_SSE( __m128 a, __m128 b )
{
    return _mm_ucomieq_ss( a, b );
}

/** \SSE{Native,_mm_ucomilt_ss} */
SSP_FORCEINLINE int ssp_ucomilt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_ucomilt_ss( a, b );
}

/** \SSE{Native,_mm_ucomile_ss} */
SSP_FORCEINLINE int ssp_ucomile_ss_SSE( __m128 a, __m128 b )
{
    return _mm_ucomile_ss( a, b );
}

/** \SSE{Native,_mm_ucomigt_ss} */
SSP_FORCEINLINE int ssp_ucomigt_ss_SSE( __m128 a, __m128 b )
{
    return _mm_ucomigt_ss( a, b );
}

/** \SSE{Native,_mm_ucomige_ss} */
SSP_FORCEINLINE int ssp_ucomige_ss_SSE( __m128 a, __m128 b )
{
    return _mm_ucomige_ss( a, b );
}

/** \SSE{Native,_mm_ucomineq_ss} */
SSP_FORCEINLINE int ssp_ucomineq_ss_SSE( __m128 a, __m128 b )
{
    return _mm_ucomineq_ss( a, b );
}

/** \SSE{Native,_mm_cvt_ss2si} */
SSP_FORCEINLINE int ssp_cvt_ss2si_SSE( __m128 a )
{
    return _mm_cvt_ss2si( a );
}

/** \SSE{Native,_mm_cvt_ps2pi} */
SSP_FORCEINLINE __m64 ssp_cvt_ps2pi_SSE( __m128 a )
{
    return _mm_cvt_ps2pi( a );
}

/** \SSE{Native,_mm_cvtt_ss2si} */
SSP_FORCEINLINE int ssp_cvtt_ss2si_SSE( __m128 a )
{
    return _mm_cvtt_ss2si( a );
}

/** \SSE{Native,_mm_cvtt_ps2pi} */
SSP_FORCEINLINE __m64 ssp_cvtt_ps2pi_SSE( __m128 a )
{
    return _mm_cvtt_ps2pi( a );
}

/** \SSE{Native,_mm_cvt_si2ss} */
SSP_FORCEINLINE __m128 ssp_cvt_si2ss_SSE( __m128 a, int imm )
{
    return _mm_cvt_si2ss( a, imm );
}

/** \SSE{Native,_mm_cvt_pi2ps} */
SSP_FORCEINLINE __m128 ssp_cvt_pi2ps_SSE( __m128 a, __m64 b )
{
    return _mm_cvt_pi2ps( a, b );
}
//TODO: Write Ref implementation. Will only work on VS9 & GCC
//SSP_FORCEINLINE float ssp_cvtss_f32_SSE( __m128 a )
//{
//    return _mm_cvtss_f32( a );
//}

/* 
 * Support for 64-bit extension intrinsics 
 */
#if defined(SYS64)
//TODO: Write Ref implementation. Will only work on VS9 & GCC
//SSP_FORCEINLINE __int64 ssp_cvtss_si64_SSE( __m128 a )
//{
//    return _mm_cvtss_si64( a );
//}
//SSP_FORCEINLINE __int64 ssp_cvttss_si64_SSE( __m128 a )
//{
//    return _mm_cvttss_si64( a );
//}
//SSP_FORCEINLINE __m128  ssp_cvtsi64_ss_SSE( __m128 a, __int64 b )
//{
//    return _mm_cvtsi64_ss( a, b );
//}
#endif

/*
 * FP, misc
 */

/**\SSE{Native,_mm_shuffle_ps} */
SSP_FORCEINLINE  __m128 ssp_shuffle_ps_SSE( __m128 a, __m128 b, unsigned int imm8 )
{
    switch( imm8 & 0xFF )
    {
        CASE_256( _mm_shuffle_ps, a, b );
    }
}

/**\SSE{Native,_mm_unpackhi_ps} */
SSP_FORCEINLINE  __m128 ssp_unpackhi_ps_SSE( __m128 a, __m128 b )
{
    return _mm_unpackhi_ps( a, b );
}

/**\SSE{Native,_mm_unpacklo_ps} */
SSP_FORCEINLINE __m128 ssp_unpacklo_ps_SSE( __m128 a, __m128 b )
{
    return _mm_unpacklo_ps( a, b );
}

/**\SSE{Native,_mm_loadh_pi} */
SSP_FORCEINLINE __m128 ssp_loadh_pi_SSE( __m128 a, __m64 const* b )
{
    return _mm_loadh_pi( a, b );
}

/**\SSE{Native,_mm_movehl_ps} */
SSP_FORCEINLINE __m128 ssp_movehl_ps_SSE( __m128 a, __m128 b )
{
    return _mm_movehl_ps( a, b );
}

/**\SSE{Native,_mm_movelh_ps} */
SSP_FORCEINLINE __m128 ssp_movelh_ps_SSE( __m128 a, __m128 b )
{
    return _mm_movelh_ps( a, b );
}

/**\SSE{Native,_mm_storeh_pi} */
SSP_FORCEINLINE void ssp_storeh_pi_SSE( __m64 *a, __m128 b )
{
    _mm_storeh_pi( a, b );
}

/**\SSE{Native,_mm_loadl_pi} */
SSP_FORCEINLINE __m128 ssp_loadl_pi_SSE( __m128 a, __m64 const* b )
{
    return _mm_loadl_pi( a, b );
}

/**\SSE{Native,_mm_storel_pi} */
SSP_FORCEINLINE void ssp_storel_pi_SSE( __m64 *a, __m128 b )
{
    _mm_storel_pi( a, b );
}

/**\SSE{Native,_mm_movemask_ps} */
SSP_FORCEINLINE int ssp_movemask_ps_SSE( __m128 a )
{
    return _mm_movemask_ps( a );
}


/*
 * Integer extensions
 */

/**\SSE{Native,_mm_pextrw} */
SSP_FORCEINLINE int ssp_pextrw_SSE( __m64 a, int imm )
{
    switch( imm & 0x3 )
    {
        CASE_4( _m_pextrw, a );
    }
}

/**\SSE{Native,_mm_pinsrw} */
SSP_FORCEINLINE __m64 ssp_pinsrw_SSE( __m64 a, int b, int imm )
{
    switch( imm & 0x3 )
    {
        CASE_4( _m_pinsrw, a, b );
    }
}

/**\SSE{Native,_mm_pmaxsw} */
SSP_FORCEINLINE __m64 ssp_pmaxsw_SSE( __m64 a, __m64 b )
{
    return _m_pmaxsw( a, b );
}

/**\SSE{Native,_mm_pmaxub} */
SSP_FORCEINLINE __m64 ssp_pmaxub_SSE( __m64 a, __m64 b )
{
    return _m_pmaxub( a, b );
}

/**\SSE{Native,_mm_pminsw} */
SSP_FORCEINLINE __m64 ssp_pminsw_SSE( __m64 a, __m64 b )
{
    return _m_pminsw( a, b );
}

/**\SSE{Native,_mm_pminub} */
SSP_FORCEINLINE __m64 ssp_pminub_SSE( __m64 a, __m64 b )
{
    return _m_pminub( a, b );
}

/**\SSE{Native,_mm_pmovmskb} */
SSP_FORCEINLINE int ssp_pmovmskb_SSE( __m64 a )
{
    return _m_pmovmskb( a );
}

/**\SSE{Native,_mm_pmulhuw} */
SSP_FORCEINLINE __m64 ssp_pmulhuw_SSE( __m64 a, __m64 b )
{
    return _m_pmulhuw( a, b );
}

/**\SSE{Native,_mm_pshufw} */
SSP_FORCEINLINE __m64 ssp_pshufw_SSE( __m64 a, int imm )
{
    switch( imm & 0xFF )
    {
        CASE_256( _m_pshufw, a );
    }
}

/**\SSE{Native,_mm_maskmovq} */
SSP_FORCEINLINE void ssp_maskmovq_SSE( __m64 a, __m64 b, char *c )
{
    _m_maskmovq( a, a, c );
}

/**\SSE{Native,_mm_pavgb} */
SSP_FORCEINLINE __m64 ssp_pavgb_SSE( __m64 a, __m64 b )
{
    return _m_pavgb( a, b );
}

/**\SSE{Native,_mm_pavgw} */
SSP_FORCEINLINE __m64 ssp_pavgw_SSE( __m64 a, __m64 b )
{
    return _m_pavgw( a, b );
}

/**\SSE{Native,_mm_psadbw} */
SSP_FORCEINLINE __m64 ssp_psadbw_SSE( __m64 a, __m64 b )
{
    return _m_psadbw( a, b );
}

/*
 * memory & initialization
 */

/**\SSE{Native,_mm_set_ss} */
SSP_FORCEINLINE __m128 ssp_set_ss_SSE( float a )
{
    return _mm_set_ss( a );
}

/**\SSE{Native,_mm_set_ps1} */
SSP_FORCEINLINE __m128 ssp_set_ps1_SSE( float a )
{
    return _mm_set_ps1( a );
}

/**\SSE{Native,_mm_set_ps_SSE} */
SSP_FORCEINLINE __m128 _mm_set_ps_SSE( float a, float b, float c, float d )
{
    return _mm_set_ps( a, b, c, d );
}

/**\SSE{Native,_mm_setr_ps} */
SSP_FORCEINLINE __m128 ssp_setr_ps_SSE( float a, float b, float c, float d )
{
    return _mm_setr_ps( a, b, c, d );
}

/**\SSE{Native,_mm_setzero_ps} */
SSP_FORCEINLINE __m128 ssp_setzero_ps_SSE( void )
{
    return _mm_setzero_ps( );
}

/**\SSE{Native,_mm_load_ss} */
SSP_FORCEINLINE __m128 ssp_load_ss_SSE( float const*a )
{
    return _mm_load_ss( a );
}

/**\SSE{Native,_mm_load_ps1} */
SSP_FORCEINLINE __m128 ssp_load_ps1_SSE( float const*a )
{
    return _mm_load_ps1( a );
}

/**\SSE{Native,_mm_load_ps} */
SSP_FORCEINLINE __m128 ssp_load_ps_SSE( float const*a )
{
    return _mm_load_ps( a );
}

/**\SSE{Native,_mm_loadr_ps} */
SSP_FORCEINLINE __m128 ssp_loadr_ps_SSE( float const*a )
{
    return _mm_loadr_ps( a );
}

/**\SSE{Native,_mm_loadu_ps} */
SSP_FORCEINLINE __m128 ssp_loadu_ps_SSE( float const*a )
{
    return _mm_loadu_ps( a );
}

/**\SSE{Native,_mm_store_ss} */
SSP_FORCEINLINE void ssp_store_ss_SSE( float *v, __m128 a )
{
    _mm_store_ss( v, a );
}

/**\SSE{Native,_mm_store_ps1} */
SSP_FORCEINLINE void ssp_store_ps1_SSE( float *v, __m128 a )
{
    _mm_store_ps1( v, a );
}

/**\SSE{Native,_mm_store_ps} */
SSP_FORCEINLINE void ssp_store_ps_SSE( float *v, __m128 a )
{
    _mm_store_ps( v, a );
}

/**\SSE{Native,_mm_storer_ps} */
SSP_FORCEINLINE void ssp_storer_ps_SSE( float *v, __m128 a )
{
    _mm_storer_ps( v, a );
}

/**\SSE{Native,_mm_storeu_ps} */
SSP_FORCEINLINE void ssp_storeu_ps_SSE( float *v, __m128 a )
{
    _mm_storeu_ps( v, a );
}

/**\SSE{Native,_mm_prefetch} */
SSP_FORCEINLINE void ssp_prefetch_SSE( char *a, int sel )
{
    switch( sel & 0x3 )
    {
    case 1:  _mm_prefetch( a, _MM_HINT_T0 ); break;
    case 2:  _mm_prefetch( a, _MM_HINT_T1 ); break;
    case 3:  _mm_prefetch( a, _MM_HINT_T2 ); break;
    default: _mm_prefetch( a, _MM_HINT_NTA );
    } 
}

/**\SSE{Native,_mm_stream_pi} */
SSP_FORCEINLINE void ssp_stream_pi_SSE( __m64 *a,  __m64 b )
{
    _mm_stream_pi( a,  b );
}

/**\SSE{Native,_mm_stream_ps} */
SSP_FORCEINLINE void ssp_stream_ps_SSE( float *a, __m128 b )
{
    _mm_stream_ps( a, b );
}

/**\SSE{Native,_mm_move_ss} */
SSP_FORCEINLINE __m128 ssp_move_ss_SSE( __m128 a, __m128 b )
{
    return _mm_move_ss( a, b );
}

/**\SSE{Native,_mm_sfence} */
SSP_FORCEINLINE void ssp_sfence_SSE( void )
{
    _mm_sfence( );
}

/**\SSE{Native,_mm_getcsr} */
 unsigned int ssp_getcsr_SSE( void )
{
    return _mm_getcsr( );
}

/**\SSE{Native,_mm_setcsr} */
SSP_FORCEINLINE void ssp_setcsr_SSE( unsigned int a )
{
    _mm_setcsr( a );
}


/**\SSE{Native,_mm_cvtpi16_ps} */
SSP_FORCEINLINE __m128 ssp_cvtpi16_ps_SSE( __m64 a )
{
    return _mm_cvtpi16_ps( a );
}

/**\SSE{Native,_mm_cvtpu16_ps} */
SSP_FORCEINLINE __m128 ssp_cvtpu16_ps_SSE( __m64 a )
{
    return _mm_cvtpu16_ps( a );
}

/**\SSE{Native,_mm_cvtps_pi16} */
SSP_FORCEINLINE __m64 ssp_cvtps_pi16_SSE( __m128 a )
{
    return _mm_cvtps_pi16( a );
}

/**\SSE{Native,_mm_cvtpi8_ps} */
SSP_FORCEINLINE __m128 ssp_cvtpi8_ps_SSE( __m64 a )
{
    return _mm_cvtpi8_ps( a );
}

/**\SSE{Native,_mm_cvtpu8_ps} */
SSP_FORCEINLINE __m128 ssp_cvtpu8_ps_SSE( __m64 a )
{
    return _mm_cvtpu8_ps( a );
}

/**\SSE{Native,_mm_cvtps_pi8} */
SSP_FORCEINLINE __m64 ssp_cvtps_pi8_SSE( __m128 a )
{
    return _mm_cvtps_pi8( a );
}

/**\SSE{Native,_mm_cvtpi32x2_ps} */
SSP_FORCEINLINE __m128 ssp_cvtpi32x2_ps_SSE( __m64 a, __m64 b )
{
    return _mm_cvtpi32x2_ps( a, b );
}

//@}

/**@name Alternate Name Definitions */

/** Alternate intrinsic names definition */
#define ssp_cvtss_si32_SSE      ssp_cvt_ss2si_SSE       
#define ssp_cvtps_pi32_SSE      ssp_cvt_ps2pi_SSE       
#define ssp_cvttss_si32_SSE     ssp_cvtt_ss2si_SSE      
#define ssp_cvttps_pi32_SSE     ssp_cvtt_ps2pi_SSE      
#define ssp_cvtsi32_ss_SSE      ssp_cvt_si2ss_SSE       
#define ssp_cvtpi32_ps_SSE      ssp_cvt_pi2ps_SSE       
#define ssp_extract_pi16_SSE    ssp_pextrw_SSE          
#define ssp_insert_pi16_SSE     ssp_pinsrw_SSE          
#define ssp_max_pi16_SSE        ssp_pmaxsw_SSE          
#define ssp_max_pu8_SSE         ssp_pmaxub_SSE          
#define ssp_min_pi16_SSE        ssp_pminsw_SSE          
#define ssp_min_pu8_SSE         ssp_pminub_SSE          
#define ssp_movemask_pi8_SSE    ssp_pmovmskb_SSE        
#define ssp_mulhi_pu16_SSE      ssp_pmulhuw_SSE         
#define ssp_shuffle_pi16_SSE    ssp_pshufw_SSE          
#define ssp_maskmove_si64_SSE   ssp_maskmovq_SSE        
#define ssp_avg_pu8_SSE         ssp_pavgb_SSE           
#define ssp_avg_pu16_SSE        ssp_pavgw_SSE           
#define ssp_sad_pu8_SSE         ssp_psadbw_SSE          
#define ssp_set1_ps_SSE         ssp_set_ps1_SSE         
#define ssp_load1_ps_SSE        ssp_load_ps1_SSE        
#define ssp_store1_ps_SSE       ssp_store_ps1_SSE 

/** @} 
 *  @}
 */

#endif // __SSEPLUS_NATIVE_SSE_H__
