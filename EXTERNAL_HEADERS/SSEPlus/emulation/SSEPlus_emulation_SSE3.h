//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_EMULATION_SSE3_H__
#define __SSEPLUS_EMULATION_SSE3_H__

#include "../SSEPlus_base.h"
#include "../native/SSEPlus_native_SSE3.h"
#include "../arithmetic/SSEPlus_arithmetic_SSE3.h"
#include "SSEPlus_emulation_comps_SSE3.h"

/** @addtogroup emulated_SSE3   
 *  @{ 
 *  @name SSE[4A,...,5] implemented in SSE3
 */

/** \SSE4_1{SSE3,_mm_dp_ps} */ 
SSP_FORCEINLINE
__m128 ssp_dp_ps_SSE3( __m128 a, __m128 b, const int mask )                 
{
    const static __m128i mulShiftImm_0123 = SSP_CONST_SET_32I( 0x010000, 0x020000, 0x040000, 0x080000 );   // Shift mask multiply moves 0,1,2,3 bits to left, becomes MSB
    const static __m128i mulShiftImm_4567 = SSP_CONST_SET_32I( 0x100000, 0x200000, 0x400000, 0x800000 );   // Shift mask multiply moves 4,5,6,7 bits to left, becomes MSB

    // Begin mask preparation
    ssp_m128 mHi, mLo;
    mLo.i = _mm_set1_epi32( mask );                                 // Load the mask into register
    mLo.i = _mm_slli_si128( mLo.i, 3 );                         // Shift into reach of the 16 bit multiply

    mHi.i = _mm_mullo_epi16( mLo.i, mulShiftImm_0123 );   // Shift the bits
    mLo.i = _mm_mullo_epi16( mLo.i, mulShiftImm_4567 );   // Shift the bits

    mHi.i = _mm_cmplt_epi32( mHi.i, _mm_setzero_si128() );    // FFFFFFFF if bit set, 00000000 if not set
    mLo.i = _mm_cmplt_epi32( mLo.i, _mm_setzero_si128() );    // FFFFFFFF if bit set, 00000000 if not set
    // End mask preparation - Mask bits 0-3 in mLo, 4-7 in mHi

    a = _mm_and_ps( a, mHi.f );                                       // Clear input using the high bits of the mask
    a = _mm_mul_ps( a, b );

    a = ssp_arithmetic_hadd4_dup_ps_SSE3( a );                            // Horizontally add the 4 values
    a = _mm_and_ps( a, mLo.f );                                      // Clear output using low bits of the mask
    return a;
}

/** @} 
 *  @}
 */

#endif // __SSEPLUS_EMULATION_SSE3_H__
