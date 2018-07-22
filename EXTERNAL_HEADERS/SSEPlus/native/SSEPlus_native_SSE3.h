//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_NATIVE_SSE3_H__
#define __SSEPLUS_NATIVE_SSE3_H__

#include "../SSEPlus_base.h"
#include SSP_INCLUDE_FILE_SSE3


/** @addtogroup native_SSE3   
 *  @{ 
 *  @name Native SSE3 Operations
 */

/** \SSE3{Native,_mm_addsub_ps} */ 
SSP_FORCEINLINE __m128 ssp_addsub_ps_SSE3(__m128 a, __m128 b)                              
{
    return _mm_addsub_ps( a, b );
}
/** \SSE3{Native,_mm_addsub_pd} */ 
SSP_FORCEINLINE __m128d ssp_addsub_pd_SSE3( __m128d a, __m128d b)
{
    return _mm_addsub_pd( a, b );
}
/** \SSE3{Native,_mm_hadd_pd} */ 
SSP_FORCEINLINE __m128d ssp_hadd_pd_SSE3( __m128d a, __m128d b)
{
    return _mm_hadd_pd(a, b );
}
/** \SSE3{Native,_mm_hadd_ps} */ 
SSP_FORCEINLINE __m128 ssp_hadd_ps_SSE3( __m128 a, __m128 b)
{
    return _mm_hadd_ps( a, b);    
}
/** \SSE3{Native,_mm_hsub_pd} */ 
SSP_FORCEINLINE __m128d ssp_hsub_pd_SSE3( __m128d a, __m128d b)
{
    return _mm_hsub_pd (a, b);
}
/** \SSE3{Native,_mm_hsub_ps} */ 
SSP_FORCEINLINE __m128 ssp_hsub_ps_SSE3( __m128 a, __m128 b)
{
    return _mm_hsub_ps (a, b);
}
/** \SSE3{Native,_mm_lddqu_si128} */ 
SSP_FORCEINLINE __m128i ssp_lddqu_si128_SSE3( __m128i const *p)
{
    return _mm_lddqu_si128 (p);    
}
/** \SSE3{Native,_mm_loaddup_pd} */ 
SSP_FORCEINLINE __m128d ssp_loaddup_pd_SSE3 (double const * dp)
{
    return _mm_loaddup_pd (dp);
}
/** \SSE3{Native,_mm_movedup_pd} */ 
SSP_FORCEINLINE __m128d ssp_movedup_pd_SSE3( __m128d a)
{
    return _mm_movedup_pd (a);    
}
/** \SSE3{Native,_mm_movehdup_ps} */ 
SSP_FORCEINLINE __m128 ssp_movehdup_ps_SSE3( __m128 a)
{
    return _mm_movehdup_ps (a);
}
/** \SSE3{Native,_mm_moveldup_ps} */ 
SSP_FORCEINLINE __m128 ssp_moveldup_ps_SSE3( __m128 a)
{
    return _mm_moveldup_ps (a);
}

//@}
//@}

#endif // __SSEPLUS_NATIVE_SSE3_H__
