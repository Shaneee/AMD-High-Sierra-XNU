//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_EMULATION_COMPS_SSE3_H__
#define __SSEPLUS_EMULATION_COMPS_SSE3_H__

#include "../SSEPlus_SSE3.h"

/** @addtogroup emulated_SSE2   
 *  @{ 
 *  @name SSE[3,4A,...,5] implemented in SSE2
 */

/** \SSE5{SSE2,_mm_comeq_epi64, pcomq } */  
SSP_FORCEINLINE __m128i ssp_comeq_epi64_SSE3(__m128i a, __m128i b)
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;
    A.i = _mm_cmpeq_epi32( A.i, B.i );  // A0=B0,  A1=B1, A2=B2,  A3=B3
    B.f = _mm_movehdup_ps( A.f );       // A1=B1,  A1=B1, A3=B3,  A3=B3
    A.f = _mm_moveldup_ps( A.f );       // A0=B0,  A0=B0, A2=B2,  A2=B2
    A.i = _mm_and_si128  ( A.i, B.i );  // A0=B0 & A1=B1, A2=B2 & A3=B3   
    return A.i;
}

/** @} 
 *  @}
 */


#endif // __SSEPLUS_EMULATION_COMPS_SSE3_H__
