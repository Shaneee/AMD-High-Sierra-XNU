//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_EMULATION_COMPS_REF_H__
#define __SSEPLUS_EMULATION_COMPS_REF_H__

#include "../SSEPlus_base.h"

/** @addtogroup emulated_REF   
 *  @{ 
 *  @name SSE[3,4A,...,5] implemented in reference
 */

//----------------------------------------
// COMEQ (Condition 0)
//----------------------------------------

/** \SSE5{Reference,_mm_comeq_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comeq_epi16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.s16[0]==B.s16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.s16[1]==B.s16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.s16[2]==B.s16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.s16[3]==B.s16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.s16[4]==B.s16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.s16[5]==B.s16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.s16[6]==B.s16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.s16[7]==B.s16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comeq_epi32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.s32[0]==B.s32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.s32[1]==B.s32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.s32[2]==B.s32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.s32[3]==B.s32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comeq_epi64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.s64[0]==B.s64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.s64[1]==B.s64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comeq_epi8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.s8[ 0]==B.s8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.s8[ 1]==B.s8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.s8[ 2]==B.s8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.s8[ 3]==B.s8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.s8[ 4]==B.s8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.s8[ 5]==B.s8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.s8[ 6]==B.s8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.s8[ 7]==B.s8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.s8[ 8]==B.s8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.s8[ 9]==B.s8[ 9]) ? 0xFF : 0;
    A.u8[10]= (A.s8[10]==B.s8[10]) ? 0xFF : 0;
    A.u8[11] = (A.s8[11]==B.s8[11]) ? 0xFF : 0;
    A.u8[12] = (A.s8[12]==B.s8[12]) ? 0xFF : 0;
    A.u8[13] = (A.s8[13]==B.s8[13]) ? 0xFF : 0;
    A.u8[14] = (A.s8[14]==B.s8[14]) ? 0xFF : 0;
    A.u8[15] = (A.s8[15]==B.s8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_epu16, pcomuw } */
SSP_FORCEINLINE __m128i ssp_comeq_epu16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.u16[0]==B.u16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.u16[1]==B.u16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.u16[2]==B.u16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.u16[3]==B.u16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.u16[4]==B.u16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.u16[5]==B.u16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.u16[6]==B.u16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.u16[7]==B.u16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_epu32, pcomud } */
SSP_FORCEINLINE __m128i ssp_comeq_epu32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.u32[0]==B.u32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.u32[1]==B.u32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.u32[2]==B.u32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.u32[3]==B.u32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_epu64, pcomuq } */
SSP_FORCEINLINE __m128i ssp_comeq_epu64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.u64[0]==B.u64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.u64[1]==B.u64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_epu8, pcomub } */
SSP_FORCEINLINE __m128i ssp_comeq_epu8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.u8[ 0]==B.u8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.u8[ 1]==B.u8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.u8[ 2]==B.u8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.u8[ 3]==B.u8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.u8[ 4]==B.u8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.u8[ 5]==B.u8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.u8[ 6]==B.u8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.u8[ 7]==B.u8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.u8[ 8]==B.u8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.u8[ 9]==B.u8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.u8[10]==B.u8[10]) ? 0xFF : 0;
    A.u8[11] = (A.u8[11]==B.u8[11]) ? 0xFF : 0;
    A.u8[12] = (A.u8[12]==B.u8[12]) ? 0xFF : 0;
    A.u8[13] = (A.u8[13]==B.u8[13]) ? 0xFF : 0;
    A.u8[14] = (A.u8[14]==B.u8[14]) ? 0xFF : 0;
    A.u8[15] = (A.u8[15]==B.u8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comeq_pd, compd }*/
SSP_FORCEINLINE __m128d ssp_comeq_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]==B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.f64[1]==B.f64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comeq_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comeq_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]==B.f32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]==B.f32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]==B.f32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]==B.f32[3]) ? 0xFFFFFFFF : 0;
    return A.f;
}

/** \SSE5{Reference,_mm_comeq_sd, comsd }*/
SSP_FORCEINLINE __m128d ssp_comeq_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]==B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comeq_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comeq_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]==B.f32[0]) ? 0xFFFFFFFF : 0;
    return A.f;
}

//----------------------------------------
// COMLT (Condition 1)
//----------------------------------------

/** \SSE5{Reference,_mm_comlt_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comlt_epi16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.s16[0]<B.s16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.s16[1]<B.s16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.s16[2]<B.s16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.s16[3]<B.s16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.s16[4]<B.s16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.s16[5]<B.s16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.s16[6]<B.s16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.s16[7]<B.s16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comlt_epi32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.s32[0]<B.s32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.s32[1]<B.s32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.s32[2]<B.s32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.s32[3]<B.s32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comlt_epi64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.s64[0]<B.s64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.s64[1]<B.s64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comlt_epi8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.s8[ 0]<B.s8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.s8[ 1]<B.s8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.s8[ 2]<B.s8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.s8[ 3]<B.s8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.s8[ 4]<B.s8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.s8[ 5]<B.s8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.s8[ 6]<B.s8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.s8[ 7]<B.s8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.s8[ 8]<B.s8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.s8[ 9]<B.s8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.s8[10]<B.s8[10]) ? 0xFF : 0;
    A.u8[11] = (A.s8[11]<B.s8[11]) ? 0xFF : 0;
    A.u8[12] = (A.s8[12]<B.s8[12]) ? 0xFF : 0;
    A.u8[13] = (A.s8[13]<B.s8[13]) ? 0xFF : 0;
    A.u8[14] = (A.s8[14]<B.s8[14]) ? 0xFF : 0;
    A.u8[15] = (A.s8[15]<B.s8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_epu16, pcomuw } */
SSP_FORCEINLINE __m128i ssp_comlt_epu16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.u16[0]<B.u16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.u16[1]<B.u16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.u16[2]<B.u16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.u16[3]<B.u16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.u16[4]<B.u16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.u16[5]<B.u16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.u16[6]<B.u16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.u16[7]<B.u16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_epu32, pcomud } */
SSP_FORCEINLINE __m128i ssp_comlt_epu32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.u32[0]<B.u32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.u32[1]<B.u32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.u32[2]<B.u32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.u32[3]<B.u32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_epu64, pcomuq } */
SSP_FORCEINLINE __m128i ssp_comlt_epu64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.u64[0]<B.u64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.u64[1]<B.u64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_epu8, pcomub } */
SSP_FORCEINLINE __m128i ssp_comlt_epu8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.u8[ 0]<B.u8[0]) ? 0xFF : 0;
    A.u8[ 1] = (A.u8[ 1]<B.u8[1]) ? 0xFF : 0;
    A.u8[ 2] = (A.u8[ 2]<B.u8[2]) ? 0xFF : 0;
    A.u8[ 3] = (A.u8[ 3]<B.u8[3]) ? 0xFF : 0;
    A.u8[ 4] = (A.u8[ 4]<B.u8[4]) ? 0xFF : 0;
    A.u8[ 5] = (A.u8[ 5]<B.u8[5]) ? 0xFF : 0;
    A.u8[ 6] = (A.u8[ 6]<B.u8[6]) ? 0xFF : 0;
    A.u8[ 7] = (A.u8[ 7]<B.u8[7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.u8[ 8]<B.u8[8]) ? 0xFF : 0;
    A.u8[ 9] = (A.u8[ 9]<B.u8[9]) ? 0xFF : 0;
    A.u8[10] = (A.u8[10]<B.u8[10]) ? 0xFF : 0;
    A.u8[11] = (A.u8[11]<B.u8[11]) ? 0xFF : 0;
    A.u8[12] = (A.u8[12]<B.u8[12]) ? 0xFF : 0;
    A.u8[13] = (A.u8[13]<B.u8[13]) ? 0xFF : 0;
    A.u8[14] = (A.u8[14]<B.u8[14]) ? 0xFF : 0;
    A.u8[15] = (A.u8[15]<B.u8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comlt_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comlt_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = (A.f64[0]<B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.f64[1]<B.f64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comlt_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comlt_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]<B.f32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]<B.f32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]<B.f32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]<B.f32[3]) ? 0xFFFFFFFF : 0;
    return A.f;
}

/** \SSE5{Reference,_mm_comlt_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comlt_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = (A.f64[0]<B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comlt_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comlt_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
	A.u32[0] = (A.f32[0]<B.f32[0]) ? 0xFFFFFFFF : 0;
    return A.f;
}

//----------------------------------------
// COMLE (Condition 2)
//----------------------------------------

/** \SSE5{Reference,_mm_comle_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comle_epi16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.s16[0]<=B.s16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.s16[1]<=B.s16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.s16[2]<=B.s16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.s16[3]<=B.s16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.s16[4]<=B.s16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.s16[5]<=B.s16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.s16[6]<=B.s16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.s16[7]<=B.s16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comle_epi32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.s32[0]<=B.s32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.s32[1]<=B.s32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.s32[2]<=B.s32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.s32[3]<=B.s32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comle_epi64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.s64[0]<=B.s64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.s64[1]<=B.s64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comle_epi8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.s8[ 0]<=B.s8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.s8[ 1]<=B.s8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.s8[ 2]<=B.s8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.s8[ 3]<=B.s8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.s8[ 4]<=B.s8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.s8[ 5]<=B.s8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.s8[ 6]<=B.s8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.s8[ 7]<=B.s8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.s8[ 8]<=B.s8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.s8[ 9]<=B.s8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.s8[10]<=B.s8[10]) ? 0xFF : 0;
    A.u8[11] = (A.s8[11]<=B.s8[11]) ? 0xFF : 0;
    A.u8[12] = (A.s8[12]<=B.s8[12]) ? 0xFF : 0;
    A.u8[13] = (A.s8[13]<=B.s8[13]) ? 0xFF : 0;
    A.u8[14] = (A.s8[14]<=B.s8[14]) ? 0xFF : 0;
    A.u8[15] = (A.s8[15]<=B.s8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_epu16, pcomuw } */
SSP_FORCEINLINE __m128i ssp_comle_epu16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.u16[0]<=B.u16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.u16[1]<=B.u16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.u16[2]<=B.u16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.u16[3]<=B.u16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.u16[4]<=B.u16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.u16[5]<=B.u16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.u16[6]<=B.u16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.u16[7]<=B.u16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_epu32, pcomud } */
SSP_FORCEINLINE __m128i ssp_comle_epu32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.u32[0]<=B.u32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.u32[1]<=B.u32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.u32[2]<=B.u32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.u32[3]<=B.u32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_epu64, pcomuq } */
SSP_FORCEINLINE __m128i ssp_comle_epu64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.u64[0]<=B.u64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.u64[1]<=B.u64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_epu8, pcomub } */
SSP_FORCEINLINE __m128i ssp_comle_epu8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.u8[ 0]<=B.u8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.u8[ 1]<=B.u8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.u8[ 2]<=B.u8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.u8[ 3]<=B.u8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.u8[ 4]<=B.u8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.u8[ 5]<=B.u8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.u8[ 6]<=B.u8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.u8[ 7]<=B.u8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.u8[ 8]<=B.u8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.u8[ 9]<=B.u8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.u8[10]<=B.u8[10]) ? 0xFF : 0;
    A.u8[11] = (A.u8[11]<=B.u8[11]) ? 0xFF : 0;
    A.u8[12] = (A.u8[12]<=B.u8[12]) ? 0xFF : 0;
    A.u8[13] = (A.u8[13]<=B.u8[13]) ? 0xFF : 0;
    A.u8[14] = (A.u8[14]<=B.u8[14]) ? 0xFF : 0;
    A.u8[15] = (A.u8[15]<=B.u8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comle_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comle_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
   
	A.u64[0] = (A.f64[0]<=B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.f64[1]<=B.f64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comle_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comle_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]<=B.f32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]<=B.f32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]<=B.f32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]<=B.f32[3]) ? 0xFFFFFFFF : 0;
    return A.f;
}

/** \SSE5{Reference,_mm_comle_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comle_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
   
	A.u64[0] = (A.f64[0]<=B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comle_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comle_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
	A.u32[0] = (A.f32[0]<=B.f32[0]) ? 0xFFFFFFFF : 0;
    return A.f;
}

//----------------------------------------
// COMUNORD (Condition 3)
//----------------------------------------

/** \SSE5{Reference,_mm_comunord_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comunord_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b; // NAN(A)              || NAN(B)         
    A.u64[0] = ((A.f64[0]!=A.f64[0]) || (B.f64[0]!=B.f64[0])) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = ((A.f64[1]!=A.f64[1]) || (B.f64[1]!=B.f64[1])) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comunord_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comunord_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b; // NAN(A)              || NAN(B)         
    A.u32[0] = (A.f32[0]!=A.f32[0]) || (B.f32[0]!=B.f32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]!=A.f32[1]) || (B.f32[1]!=B.f32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]!=A.f32[2]) || (B.f32[2]!=B.f32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]!=A.f32[3]) || (B.f32[3]!=B.f32[3]) ? 0xFFFFFFFF : 0;
    return A.f;
}

/** \SSE5{Reference,_mm_comunord_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comunord_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b; // NAN(A)              || NAN(B)         
    A.u64[0] = ((A.f64[0]!=A.f64[0]) || (B.f64[0]!=B.f64[0])) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comunord_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comunord_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b; // NAN(A)              || NAN(B)         
    A.u32[0] = (A.f32[0]!=A.f32[0]) || (B.f32[0]!=B.f32[0]) ? 0xFFFFFFFF : 0;
    return A.f;
}


//----------------------------------------
// COMNEQ (Condition 4)
//----------------------------------------

/** \SSE5{Reference,_mm_comneq_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comneq_epi16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.s16[0]!=B.s16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.s16[1]!=B.s16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.s16[2]!=B.s16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.s16[3]!=B.s16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.s16[4]!=B.s16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.s16[5]!=B.s16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.s16[6]!=B.s16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.s16[7]!=B.s16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comneq_epi32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.s32[0]!=B.s32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.s32[1]!=B.s32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.s32[2]!=B.s32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.s32[3]!=B.s32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comneq_epi64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.s64[0]!=B.s64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.s64[1]!=B.s64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comneq_epi8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.s8[ 0]!=B.s8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.s8[ 1]!=B.s8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.s8[ 2]!=B.s8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.s8[ 3]!=B.s8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.s8[ 4]!=B.s8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.s8[ 5]!=B.s8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.s8[ 6]!=B.s8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.s8[ 7]!=B.s8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.s8[ 8]!=B.s8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.s8[ 9]!=B.s8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.s8[10]!=B.s8[10]) ? 0xFF : 0;
    A.u8[11] = (A.s8[11]!=B.s8[11]) ? 0xFF : 0;
    A.u8[12] = (A.s8[12]!=B.s8[12]) ? 0xFF : 0;
    A.u8[13] = (A.s8[13]!=B.s8[13]) ? 0xFF : 0;
    A.u8[14] = (A.s8[14]!=B.s8[14]) ? 0xFF : 0;
    A.u8[15] = (A.s8[15]!=B.s8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_epu16, pcomuw } */
SSP_FORCEINLINE __m128i ssp_comneq_epu16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.u16[0]!=B.u16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.u16[1]!=B.u16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.u16[2]!=B.u16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.u16[3]!=B.u16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.u16[4]!=B.u16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.u16[5]!=B.u16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.u16[6]!=B.u16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.u16[7]!=B.u16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_epu32, pcomud } */
SSP_FORCEINLINE __m128i ssp_comneq_epu32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.u32[0]!=B.u32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.u32[1]!=B.u32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.u32[2]!=B.u32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.u32[3]!=B.u32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_epu64, pcomuq } */
SSP_FORCEINLINE __m128i ssp_comneq_epu64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.u64[0]!=B.u64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.u64[1]!=B.u64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_epu8, pcomub } */
SSP_FORCEINLINE __m128i ssp_comneq_epu8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.u8[ 0]!=B.u8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.u8[ 1]!=B.u8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.u8[ 2]!=B.u8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.u8[ 3]!=B.u8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.u8[ 4]!=B.u8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.u8[ 5]!=B.u8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.u8[ 6]!=B.u8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.u8[ 7]!=B.u8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.u8[ 8]!=B.u8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.u8[ 9]!=B.u8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.u8[10]!=B.u8[10]) ? 0xFF : 0;
    A.u8[11] = (A.u8[11]!=B.u8[11]) ? 0xFF : 0;
    A.u8[12] = (A.u8[12]!=B.u8[12]) ? 0xFF : 0;
    A.u8[13] = (A.u8[13]!=B.u8[13]) ? 0xFF : 0;
    A.u8[14] = (A.u8[14]!=B.u8[14]) ? 0xFF : 0;
    A.u8[15] = (A.u8[15]!=B.u8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comneq_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comneq_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    
	A.u64[0] = (A.f64[0]!=B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.f64[1]!=B.f64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comneq_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comneq_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]!=B.f32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]!=B.f32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]!=B.f32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]!=B.f32[3]) ? 0xFFFFFFFF : 0;
    return A.f;
}

/** \SSE5{Reference,_mm_comneq_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comneq_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    
	A.u64[0] = (A.f64[0]!=B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comneq_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comneq_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
	A.u32[0] = (A.f32[0]!=B.f32[0]) ? 0xFFFFFFFF : 0;
    return A.f;
}


//----------------------------------------
// COMNLT (Condition 5)
//----------------------------------------

/** \SSE5{Reference,_mm_comnlt_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comnlt_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
 
    A.u64[0] = (A.f64[0]<B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    A.u64[1] = (A.f64[1]<B.f64[1]) ? 0 : 0xFFFFFFFFFFFFFFFF;
 
    return A.d;
}

/** \SSE5{Reference,_mm_comnlt_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comnlt_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]<B.f32[0]) ? 0 : 0xFFFFFFFF;
    A.u32[1] = (A.f32[1]<B.f32[1]) ? 0 : 0xFFFFFFFF;
    A.u32[2] = (A.f32[2]<B.f32[2]) ? 0 : 0xFFFFFFFF;
    A.u32[3] = (A.f32[3]<B.f32[3]) ? 0 : 0xFFFFFFFF;
    return A.f;
}

/** \SSE5{Reference,_mm_comnlt_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comnlt_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
 
    A.u64[0] = (A.f64[0]<B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
 
    return A.d;
}

/** \SSE5{Reference,_mm_comnlt_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comnlt_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]<B.f32[0]) ? 0 : 0xFFFFFFFF;
    return A.f;
}


//----------------------------------------
// COMNLE (Condition 6)
//----------------------------------------

/** \SSE5{Reference,_mm_comnle_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comnle_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]<=B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    A.u64[1] = (A.f64[1]<=B.f64[1]) ? 0 : 0xFFFFFFFFFFFFFFFF;
 
    return A.d;
}

/** \SSE5{Reference,_mm_comnle_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comnle_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]<=B.f32[0]) ? 0 : 0xFFFFFFFF;
    A.u32[1] = (A.f32[1]<=B.f32[1]) ? 0 : 0xFFFFFFFF;
    A.u32[2] = (A.f32[2]<=B.f32[2]) ? 0 : 0xFFFFFFFF;
    A.u32[3] = (A.f32[3]<=B.f32[3]) ? 0 : 0xFFFFFFFF;
    return A.f;
}

/** \SSE5{Reference,_mm_comnle_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comnle_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]<=B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
 
    return A.d;
}

/** \SSE5{Reference,_mm_comnle_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comnle_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
	A.u32[0] = (A.f32[0]<=B.f32[0]) ? 0 : 0xFFFFFFFF;
    return A.f;
}


//----------------------------------------
// COMORD (Condition 7)
//----------------------------------------

/** \SSE5{Reference,_mm_comord_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comord_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b; // NAN(A)              || NAN(B)         
    A.u64[0] = (A.f64[0]!=A.f64[0]) || (B.f64[0]!=B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    A.u64[1] = (A.f64[1]!=A.f64[1]) || (B.f64[1]!=B.f64[1]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comord_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comord_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b; // NAN(A)              || NAN(B)         
    A.u32[0] = (A.f32[0]!=A.f32[0]) || (B.f32[0]!=B.f32[0]) ? 0 : 0xFFFFFFFF;
    A.u32[1] = (A.f32[1]!=A.f32[1]) || (B.f32[1]!=B.f32[1]) ? 0 : 0xFFFFFFFF;
    A.u32[2] = (A.f32[2]!=A.f32[2]) || (B.f32[2]!=B.f32[2]) ? 0 : 0xFFFFFFFF;
    A.u32[3] = (A.f32[3]!=A.f32[3]) || (B.f32[3]!=B.f32[3]) ? 0 : 0xFFFFFFFF;
    return A.f;
}

/** \SSE5{Reference,_mm_comord_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comord_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b; // NAN(A)              || NAN(B)         
    A.u64[0] = (A.f64[0]!=A.f64[0]) || (B.f64[0]!=B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comord_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comord_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b; // NAN(A)              || NAN(B)         
    A.u32[0] = (A.f32[0]!=A.f32[0]) || (B.f32[0]!=B.f32[0]) ? 0 : 0xFFFFFFFF;
    return A.f;
}


//----------------------------------------
// COMUEQ (Condition 8)
//----------------------------------------

/** \SSE5{Reference,_mm_comueq_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comueq_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = ((A.f64[0]<B.f64[0]) || (A.f64[0]>B.f64[0])) ? 0 : 0xFFFFFFFFFFFFFFFF;
    A.u64[1] = ((A.f64[1]<B.f64[1]) || (A.f64[1]>B.f64[1])) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comueq_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comueq_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;             
    A.u32[0] = (A.f32[0]<B.f32[0]) || (A.f32[0]>B.f32[0]) ? 0 : 0xFFFFFFFF;
    A.u32[1] = (A.f32[1]<B.f32[1]) || (A.f32[1]>B.f32[1]) ? 0 : 0xFFFFFFFF;
    A.u32[2] = (A.f32[2]<B.f32[2]) || (A.f32[2]>B.f32[2]) ? 0 : 0xFFFFFFFF;
    A.u32[3] = (A.f32[3]<B.f32[3]) || (A.f32[3]>B.f32[3]) ? 0 : 0xFFFFFFFF;
    return A.f;
}

/** \SSE5{Reference,_mm_comueq_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comueq_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = ((A.f64[0]<B.f64[0]) || (A.f64[0]>B.f64[0])) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comueq_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comueq_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
	A.u32[0] = (A.f32[0]<B.f32[0]) || (A.f32[0]>B.f32[0]) ? 0 : 0xFFFFFFFF;
    return A.f;
}


//----------------------------------------
// COMNGE (Condition 9)
//----------------------------------------

/** \SSE5{Reference,_mm_comnge_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comnge_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = (A.f64[0]>=B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    A.u64[1] = (A.f64[1]>=B.f64[1]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comnge_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comnge_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]>=B.f32[0]) ? 0 : 0xFFFFFFFF;
    A.u32[1] = (A.f32[1]>=B.f32[1]) ? 0 : 0xFFFFFFFF;
    A.u32[2] = (A.f32[2]>=B.f32[2]) ? 0 : 0xFFFFFFFF;
    A.u32[3] = (A.f32[3]>=B.f32[3]) ? 0 : 0xFFFFFFFF;
    return A.f;
}

/** \SSE5{Reference,_mm_comnge_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comnge_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = (A.f64[0]>=B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comnge_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comnge_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]>=B.f32[0]) ? 0 : 0xFFFFFFFF;
    return A.f;
}


//----------------------------------------
// COMNGT (Condition 10)
//----------------------------------------

/** \SSE5{Reference,_mm_comngt_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comngt_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = (A.f64[0]>B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    A.u64[1] = (A.f64[1]>B.f64[1]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comngt_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comngt_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]>B.f32[0]) ? 0 : 0xFFFFFFFF;
    A.u32[1] = (A.f32[1]>B.f32[1]) ? 0 : 0xFFFFFFFF;
    A.u32[2] = (A.f32[2]>B.f32[2]) ? 0 : 0xFFFFFFFF;
    A.u32[3] = (A.f32[3]>B.f32[3]) ? 0 : 0xFFFFFFFF;
    return A.f;
}

/** \SSE5{Reference,_mm_comngt_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comngt_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
	A.u64[0] = (A.f64[0]>B.f64[0]) ? 0 : 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comngt_ss, comps } */
SSP_FORCEINLINE __m128 ssp_comngt_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
	A.u32[0] = (A.f32[0]>B.f32[0]) ? 0 : 0xFFFFFFFF;
    return A.f;
}


//----------------------------------------
// COMFALSE (Condition 11)
//----------------------------------------

/** \SSE5{Reference,_mm_comfalse_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comfalse_epi16_REF(__m128i a, __m128i b)
{
    const static __m128i tmp = SSP_CONST_SET_32I( 0,0,0,0 );  
    return tmp;
}

/** \SSE5{Reference,_mm_comfalse_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comfalse_epi32_REF(__m128i a, __m128i b)
{
    return ssp_comfalse_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comfalse_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comfalse_epi64_REF(__m128i a, __m128i b)
{
    return ssp_comfalse_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comfalse_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comfalse_epi8_REF(__m128i a, __m128i b)
{
    return ssp_comfalse_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comfalse_epu16, pcomuw } */
SSP_FORCEINLINE __m128i ssp_comfalse_epu16_REF(__m128i a, __m128i b)
{
    return ssp_comfalse_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comfalse_epu32, pcomud } */
SSP_FORCEINLINE __m128i ssp_comfalse_epu32_REF(__m128i a, __m128i b)
{
    return ssp_comfalse_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comfalse_epu64, pcomuq } */
SSP_FORCEINLINE __m128i ssp_comfalse_epu64_REF(__m128i a, __m128i b)
{
    return ssp_comfalse_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comfalse_epu8, pcomub } */
SSP_FORCEINLINE __m128i ssp_comfalse_epu8_REF(__m128i a, __m128i b)
{
    return ssp_comfalse_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comfalse_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comfalse_pd_REF(__m128d a, __m128d b)
{
    const static __m128d tmp = SSP_CONST_SET_64F( 0, 0 );      
    return tmp;
}

/** \SSE5{Reference,_mm_comfalse_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comfalse_ps_REF(__m128 a, __m128 b)
{
   const static __m128 tmp = SSP_CONST_SET_32F( 0, 0, 0, 0 );      
   return tmp;
}

/** \SSE5{Reference,_mm_comfalse_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comfalse_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A;
    A.d = a;
    A.u64[0] = 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comfalse_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comfalse_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A;
    A.f = a;
    A.u32[0] = 0;
    return A.f;
}


//----------------------------------------
// COMONEQ (Condition 12)
//----------------------------------------

/** \SSE5{Reference,_mm_comoneq_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comoneq_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b; 
    A.u64[0] = ((A.f64[0]<B.f64[0]) || (A.f64[0]>B.f64[0]))  ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = ((A.f64[1]<B.f64[1]) || (A.f64[1]>B.f64[1]))  ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;   
}

/** \SSE5{Reference,_mm_comoneq_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comoneq_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b; 
    A.u32[0] = (A.f32[0]<B.f32[0]) || (A.f32[0]>B.f32[0])  ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]<B.f32[1]) || (A.f32[1]>B.f32[1])  ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]<B.f32[2]) || (A.f32[2]>B.f32[2])  ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]<B.f32[3]) || (A.f32[3]>B.f32[3])  ? 0xFFFFFFFF : 0;
    return A.f;   
}

/** \SSE5{Reference,_mm_comoneq_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comoneq_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b; 
    A.u64[0] = ((A.f64[0]<B.f64[0]) || (A.f64[0]>B.f64[0]))  ? 0xFFFFFFFFFFFFFFFF : 0; 
    return A.d;   
}

/** \SSE5{Reference,_mm_comoneq_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comoneq_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;  
	A.u32[0] = (A.f32[0]<B.f32[0]) || (A.f32[0]>B.f32[0])  ? 0xFFFFFFFF : 0;
    return A.f;   
}


//----------------------------------------
// COMGE (Condition 13)
//----------------------------------------

/** \SSE5{Reference,_mm_comge_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comge_epi16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.s16[0]>=B.s16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.s16[1]>=B.s16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.s16[2]>=B.s16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.s16[3]>=B.s16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.s16[4]>=B.s16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.s16[5]>=B.s16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.s16[6]>=B.s16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.s16[7]>=B.s16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comge_epi32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.s32[0]>=B.s32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.s32[1]>=B.s32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.s32[2]>=B.s32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.s32[3]>=B.s32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comge_epi64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.s64[0]>=B.s64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.s64[1]>=B.s64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comge_epi8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.s8[ 0]>=B.s8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.s8[ 1]>=B.s8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.s8[ 2]>=B.s8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.s8[ 3]>=B.s8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.s8[ 4]>=B.s8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.s8[ 5]>=B.s8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.s8[ 6]>=B.s8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.s8[ 7]>=B.s8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.s8[ 8]>=B.s8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.s8[ 9]>=B.s8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.s8[10]>=B.s8[10]) ? 0xFF : 0;
    A.u8[11] = (A.s8[11]>=B.s8[11]) ? 0xFF : 0;
    A.u8[12] = (A.s8[12]>=B.s8[12]) ? 0xFF : 0;
    A.u8[13] = (A.s8[13]>=B.s8[13]) ? 0xFF : 0;
    A.u8[14] = (A.s8[14]>=B.s8[14]) ? 0xFF : 0;
    A.u8[15] = (A.s8[15]>=B.s8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_epu16, pcomuw } */
SSP_FORCEINLINE __m128i ssp_comge_epu16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.u16[0]>=B.u16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.u16[1]>=B.u16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.u16[2]>=B.u16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.u16[3]>=B.u16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.u16[4]>=B.u16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.u16[5]>=B.u16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.u16[6]>=B.u16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.u16[7]>=B.u16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_epu32, pcomud } */
SSP_FORCEINLINE __m128i ssp_comge_epu32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.u32[0]>=B.u32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.u32[1]>=B.u32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.u32[2]>=B.u32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.u32[3]>=B.u32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_epu64, pcomuq } */
SSP_FORCEINLINE __m128i ssp_comge_epu64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.u64[0]>=B.u64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.u64[1]>=B.u64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_epu8, pcomub } */
SSP_FORCEINLINE __m128i ssp_comge_epu8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.u8[ 0]>=B.u8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.u8[ 1]>=B.u8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.u8[ 2]>=B.u8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.u8[ 3]>=B.u8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.u8[ 4]>=B.u8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.u8[ 5]>=B.u8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.u8[ 6]>=B.u8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.u8[ 7]>=B.u8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.u8[ 8]>=B.u8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.u8[ 9]>=B.u8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.u8[10]>=B.u8[10]) ? 0xFF : 0;
    A.u8[11] = (A.u8[11]>=B.u8[11]) ? 0xFF : 0;
    A.u8[12] = (A.u8[12]>=B.u8[12]) ? 0xFF : 0;
    A.u8[13] = (A.u8[13]>=B.u8[13]) ? 0xFF : 0;
    A.u8[14] = (A.u8[14]>=B.u8[14]) ? 0xFF : 0;
    A.u8[15] = (A.u8[15]>=B.u8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comge_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comge_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]>=B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.f64[1]>=B.f64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comge_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comge_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]>=B.f32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]>=B.f32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]>=B.f32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]>=B.f32[3]) ? 0xFFFFFFFF : 0;
    return A.f;
}

/** \SSE5{Reference,_mm_comge_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comge_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]>=B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0 ;
    return A.d;
}

/** \SSE5{Reference,_mm_comge_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comge_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b; 
    A.u32[0] = (A.f32[0]>=B.f32[0]) ? 0xFFFFFFFF : 0; 
    return A.f;
}



//----------------------------------------
// COMGT (Condition 14)
//----------------------------------------

/** \SSE5{Reference,_mm_comgt_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comgt_epi16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.s16[0]>B.s16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.s16[1]>B.s16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.s16[2]>B.s16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.s16[3]>B.s16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.s16[4]>B.s16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.s16[5]>B.s16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.s16[6]>B.s16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.s16[7]>B.s16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comgt_epi32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.s32[0]>B.s32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.s32[1]>B.s32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.s32[2]>B.s32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.s32[3]>B.s32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comgt_epi64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.s64[0]>B.s64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.s64[1]>B.s64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comgt_epi8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.s8[ 0]>B.s8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.s8[ 1]>B.s8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.s8[ 2]>B.s8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.s8[ 3]>B.s8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.s8[ 4]>B.s8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.s8[ 5]>B.s8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.s8[ 6]>B.s8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.s8[ 7]>B.s8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.s8[ 8]>B.s8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.s8[ 9]>B.s8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.s8[10]>B.s8[10]) ? 0xFF : 0;
    A.u8[11] = (A.s8[11]>B.s8[11]) ? 0xFF : 0;
    A.u8[12] = (A.s8[12]>B.s8[12]) ? 0xFF : 0;
    A.u8[13] = (A.s8[13]>B.s8[13]) ? 0xFF : 0;
    A.u8[14] = (A.s8[14]>B.s8[14]) ? 0xFF : 0;
    A.u8[15] = (A.s8[15]>B.s8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_epu16, pcomuw } */
SSP_FORCEINLINE __m128i ssp_comgt_epu16_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u16[0] = (A.u16[0]>B.u16[0]) ? 0xFFFF : 0;
    A.u16[1] = (A.u16[1]>B.u16[1]) ? 0xFFFF : 0;
    A.u16[2] = (A.u16[2]>B.u16[2]) ? 0xFFFF : 0;
    A.u16[3] = (A.u16[3]>B.u16[3]) ? 0xFFFF : 0;
    A.u16[4] = (A.u16[4]>B.u16[4]) ? 0xFFFF : 0;
    A.u16[5] = (A.u16[5]>B.u16[5]) ? 0xFFFF : 0;
    A.u16[6] = (A.u16[6]>B.u16[6]) ? 0xFFFF : 0;
    A.u16[7] = (A.u16[7]>B.u16[7]) ? 0xFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_epu32, pcomud } */
SSP_FORCEINLINE __m128i ssp_comgt_epu32_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u32[0] = (A.u32[0]>B.u32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.u32[1]>B.u32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.u32[2]>B.u32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.u32[3]>B.u32[3]) ? 0xFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_epu64, pcomuq } */
SSP_FORCEINLINE __m128i ssp_comgt_epu64_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u64[0] = (A.u64[0]>B.u64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.u64[1]>B.u64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_epu8, pcomub } */
SSP_FORCEINLINE __m128i ssp_comgt_epu8_REF(__m128i a, __m128i b)
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;
    A.u8[ 0] = (A.u8[ 0]>B.u8[ 0]) ? 0xFF : 0;
    A.u8[ 1] = (A.u8[ 1]>B.u8[ 1]) ? 0xFF : 0;
    A.u8[ 2] = (A.u8[ 2]>B.u8[ 2]) ? 0xFF : 0;
    A.u8[ 3] = (A.u8[ 3]>B.u8[ 3]) ? 0xFF : 0;
    A.u8[ 4] = (A.u8[ 4]>B.u8[ 4]) ? 0xFF : 0;
    A.u8[ 5] = (A.u8[ 5]>B.u8[ 5]) ? 0xFF : 0;
    A.u8[ 6] = (A.u8[ 6]>B.u8[ 6]) ? 0xFF : 0;
    A.u8[ 7] = (A.u8[ 7]>B.u8[ 7]) ? 0xFF : 0; 
	A.u8[ 8] = (A.u8[ 8]>B.u8[ 8]) ? 0xFF : 0;
    A.u8[ 9] = (A.u8[ 9]>B.u8[ 9]) ? 0xFF : 0;
    A.u8[10] = (A.u8[10]>B.u8[10]) ? 0xFF : 0;
    A.u8[11] = (A.u8[11]>B.u8[11]) ? 0xFF : 0;
    A.u8[12] = (A.u8[12]>B.u8[12]) ? 0xFF : 0;
    A.u8[13] = (A.u8[13]>B.u8[13]) ? 0xFF : 0;
    A.u8[14] = (A.u8[14]>B.u8[14]) ? 0xFF : 0;
    A.u8[15] = (A.u8[15]>B.u8[15]) ? 0xFF : 0;
    return A.i;
}

/** \SSE5{Reference,_mm_comgt_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comgt_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]>B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.u64[1] = (A.f64[1]>B.f64[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
 
    return A.d;
}

/** \SSE5{Reference,_mm_comgt_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comgt_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]>B.f32[0]) ? 0xFFFFFFFF : 0;
    A.u32[1] = (A.f32[1]>B.f32[1]) ? 0xFFFFFFFF : 0;
    A.u32[2] = (A.f32[2]>B.f32[2]) ? 0xFFFFFFFF : 0;
    A.u32[3] = (A.f32[3]>B.f32[3]) ? 0xFFFFFFFF : 0;
    return A.f;
}

/** \SSE5{Reference,_mm_comgt_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comgt_sd_REF(__m128d a, __m128d b)
{
    ssp_m128 A,B;
    A.d = a;
    B.d = b;
    A.u64[0] = (A.f64[0]>B.f64[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.d;
}

/** \SSE5{Reference,_mm_comgt_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comgt_ss_REF(__m128 a, __m128 b)
{
    ssp_m128 A,B;
    A.f = a;
    B.f = b;
    A.u32[0] = (A.f32[0]>B.f32[0]) ? 0xFFFFFFFF : 0;
    return A.f;
}


//----------------------------------------
// COMTRUE (Condition 15)
//----------------------------------------

/** \SSE5{Reference,_mm_comtrue_epi16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comtrue_epi16_REF(__m128i a, __m128i b)
{
    const static __m128i tmp = SSP_CONST_SET_64I( 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF );  
    return tmp;
}

/** \SSE5{Reference,_mm_comtrue_epi32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comtrue_epi32_REF(__m128i a, __m128i b)
{
    return ssp_comtrue_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comtrue_epi64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comtrue_epi64_REF(__m128i a, __m128i b)
{
    return ssp_comtrue_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comtrue_epi8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comtrue_epi8_REF(__m128i a, __m128i b)
{
    return ssp_comtrue_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comtrue_epu16, pcomw } */
SSP_FORCEINLINE __m128i ssp_comtrue_epu16_REF(__m128i a, __m128i b)
{
    return ssp_comtrue_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comtrue_epu32, pcomd } */
SSP_FORCEINLINE __m128i ssp_comtrue_epu32_REF(__m128i a, __m128i b)
{
    return ssp_comtrue_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comtrue_epu64, pcomq } */
SSP_FORCEINLINE __m128i ssp_comtrue_epu64_REF(__m128i a, __m128i b)
{
    return ssp_comtrue_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comtrue_epu8, pcomb } */
SSP_FORCEINLINE __m128i ssp_comtrue_epu8_REF(__m128i a, __m128i b)
{
    return ssp_comtrue_epi16_REF(a,b);
}

/** \SSE5{Reference,_mm_comtrue_pd, compd } */
SSP_FORCEINLINE __m128d ssp_comtrue_pd_REF(__m128d a, __m128d b)
{   
    const static __m128i tmp = SSP_CONST_SET_64I( 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF );
    ssp_m128 A;  
    A.i = tmp;
    return A.d;
}

/** \SSE5{Reference,_mm_comtrue_ps, comps } */
SSP_FORCEINLINE __m128 ssp_comtrue_ps_REF(__m128 a, __m128 b)
{   
    const static __m128i tmp = SSP_CONST_SET_64I( 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF );
    ssp_m128 A;  
    A.i = tmp;
    return A.f;
}

/** \SSE5{Reference,_mm_comtrue_sd, comsd } */
SSP_FORCEINLINE __m128d ssp_comtrue_sd_REF(__m128d a, __m128d b)
{   
    ssp_m128 A;    
    A.d      = a;
    A.u64[0] = 0xFFFFFFFFFFFFFFFF;
    return A.d;
}

/** \SSE5{Reference,_mm_comtrue_ss, comss } */
SSP_FORCEINLINE __m128 ssp_comtrue_ss_REF(__m128 a, __m128 b)
{   
    ssp_m128 A;
    A.f = a;
    A.u32[0] = 0xFFFFFFFF;
    return A.f;
}

/** @} 
 *  @}
 */

#endif // __SSP_EMULATION_COMPS_REF_H__
