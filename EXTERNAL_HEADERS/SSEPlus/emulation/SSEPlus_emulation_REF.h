//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_EMULATION_REF_H__
#define __SSEPLUS_EMULATION_REF_H__

#include "../SSEPlus_base.h"
#include "../number/SSEPlus_number_REF.h"
#include "../arithmetic/SSEPlus_arithmetic_REF.h"
#include "SSEPlus_emulation_comps_REF.h"

#ifndef KERNEL
#include <math.h>
#endif

/** @addtogroup emulated_REF   
 *  @{ 
 *  @name SSE[3,4A,...,5] implemented in reference
 */


//--------------------------------------
// Extract Fraction
//--------------------------------------
/** \SSE5{Reference,_mm_frcz_pd_REF, frczpd  } */
SSP_FORCEINLINE __m128d ssp_frcz_pd_REF(__m128d a)
{
	ssp_m128 A;
	long long temp;

	A.d = a;

	temp = (long long) A.f64[0];
	A.f64[0] -= temp;
	temp = (long long) A.f64[1];
	A.f64[1] -= temp;

	return A.d;
}

/** \SSE5{Reference,_mm_frcz_ps_REF, frczps  } */
SSP_FORCEINLINE __m128 ssp_frcz_ps_REF(__m128 a)
{
	ssp_m128 A;
	int temp;
	A.f = a;

	temp = (int) A.f32[0];
	A.f32[0] -= temp;
	temp = (int) A.f32[1];
	A.f32[1] -= temp;
	temp = (int) A.f32[2];
	A.f32[2] -= temp;
	temp = (int) A.f32[3];
	A.f32[3] -= temp;

	return A.f;
}

/** \SSE5{Reference,_mm_frcz_sd_REF, frczsd  } */
SSP_FORCEINLINE __m128d ssp_frcz_sd_REF(__m128d a, __m128d b)
{
	ssp_m128 A, B;
	long long temp;

	A.d = a;
	B.d = b;

	temp = (long long) A.f64[0];
	B.f64[0] = A.f64[0] - temp;

	return B.d;
}

/** \SSE5{Reference,_mm_frcz_ss_REF, frczss  } */
SSP_FORCEINLINE __m128 ssp_frcz_ss_REF(__m128 a, __m128 b)
{
	ssp_m128 A, B;
	int temp;

	A.f = a;
	B.f = b;

	temp = (int) A.f32[0];
	B.f32[0] = A.f32[0] - temp;

	return B.f;
}

//--------------------------------------
// Horizontal Add and Sub
//--------------------------------------
/** \SSE5{Reference,_mm_haddd_epi16, phaddwd  } */
SSP_FORCEINLINE __m128i ssp_haddd_epi16_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s32[0] = A.s16[0] + A.s16[1];
	B.s32[1] = A.s16[2] + A.s16[3];
	B.s32[2] = A.s16[4] + A.s16[5];
	B.s32[3] = A.s16[6] + A.s16[7];

	return B.i;
}

/** \SSE5{Reference,_mm_haddd_epi8, phaddbd  } */
SSP_FORCEINLINE __m128i ssp_haddd_epi8_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s32[0] = A.s8[ 0] + A.s8[ 1] + A.s8[ 2] + A.s8[ 3];
	B.s32[1] = A.s8[ 4] + A.s8[ 5] + A.s8[ 6] + A.s8[ 7];
	B.s32[2] = A.s8[ 8] + A.s8[ 9] + A.s8[10] + A.s8[11];
	B.s32[3] = A.s8[12] + A.s8[13] + A.s8[14] + A.s8[15];

	return B.i;
}

/** \SSE5{Reference,_mm_haddd_epu16, phadduwd  } */
SSP_FORCEINLINE __m128i ssp_haddd_epu16_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.u32[0] = A.u16[0] + A.u16[1];
	B.u32[1] = A.u16[2] + A.u16[3];
	B.u32[2] = A.u16[4] + A.u16[5];
	B.u32[3] = A.u16[6] + A.u16[7];

	return B.i;
}

/** \SSE5{Reference,_mm_haddd_epu8, phaddubd  } */
SSP_FORCEINLINE __m128i ssp_haddd_epu8_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.u32[0] = A.u8[ 0] + A.u8[ 1] + A.u8[ 2] + A.u8[ 3];
	B.u32[1] = A.u8[ 4] + A.u8[ 5] + A.u8[ 6] + A.u8[ 7];
	B.u32[2] = A.u8[ 8] + A.u8[ 9] + A.u8[10] + A.u8[11];
	B.u32[3] = A.u8[12] + A.u8[13] + A.u8[14] + A.u8[15];

	return B.i;
}

/** \SSE5{Reference,_mm_haddq_epi16, phaddwq  } */
SSP_FORCEINLINE __m128i ssp_haddq_epi16_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s64[0] = A.s16[0] + A.s16[1] + A.s16[2] + A.s16[3];
	B.s64[1] = A.s16[4] + A.s16[5] + A.s16[6] + A.s16[7];

	return B.i;
}

/** \SSE5{Reference,_mm_haddq_epi32, phadddq  } */
SSP_FORCEINLINE __m128i ssp_haddq_epi32_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s64[0] = A.s32[0] + (long long)A.s32[1];
	B.s64[1] = A.s32[2] + (long long)A.s32[3];

	return B.i;
}

/** \SSE5{Reference,_mm_haddq_epi8, phaddbq  } */
SSP_FORCEINLINE __m128i ssp_haddq_epi8_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s64[0] = A.s8[0] + A.s8[1] + A.s8[2] + A.s8[3] + A.s8[4] + A.s8[5] + A.s8[6] + A.s8[7];
	B.s64[1] = A.s8[8] + A.s8[9] + A.s8[10] + A.s8[11] + A.s8[12] + A.s8[13] + A.s8[14] + A.s8[15];

	return B.i;
}

/** \SSE5{Reference,_mm_haddq_epu16, phadduwq  } */
SSP_FORCEINLINE __m128i ssp_haddq_epu16_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.u64[0] = A.u16[0] + A.u16[1] + A.u16[2] + A.u16[3];
	B.u64[1] = A.u16[4] + A.u16[5] + A.u16[6] + A.u16[7];

	return B.i;
}

/** \SSE5{Reference,_mm_haddq_epu32, phaddudq  } */
SSP_FORCEINLINE __m128i ssp_haddq_epu32_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.u64[0] = A.u32[0] + (long long)A.u32[1];
	B.u64[1] = A.u32[2] + (long long)A.u32[3];

	return B.i;
}

/** \SSE5{Reference,_mm_haddq_epu8, phaddubq  } */
SSP_FORCEINLINE __m128i ssp_haddq_epu8_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.u64[0] = A.u8[0] + A.u8[1] + A.u8[2] + A.u8[3] + A.u8[4] + A.u8[5] + A.u8[6] + A.u8[7];
	B.u64[1] = A.u8[8] + A.u8[9] + A.u8[10] + A.u8[11] + A.u8[12] + A.u8[13] + A.u8[14] + A.u8[15];

	return B.i;
}

/** \SSE5{Reference,_mm_haddw_epi8, phaddbw  } */
SSP_FORCEINLINE __m128i ssp_haddw_epi8_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s16[0] = A.s8[0] + A.s8[1];
	B.s16[1] = A.s8[2] + A.s8[3];
	B.s16[2] = A.s8[4] + A.s8[5];
	B.s16[3] = A.s8[6] + A.s8[7];
	B.s16[4] = A.s8[8] + A.s8[9];
	B.s16[5] = A.s8[10] + A.s8[11];
	B.s16[6] = A.s8[12] + A.s8[13];
	B.s16[7] = A.s8[14] + A.s8[15];

	return B.i;
}

/** \SSE5{Reference,_mm_haddw_epu8, phaddubw  } */
SSP_FORCEINLINE __m128i ssp_haddw_epu8_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.u16[0] = A.u8[0] + A.u8[1];
	B.u16[1] = A.u8[2] + A.u8[3];
	B.u16[2] = A.u8[4] + A.u8[5];
	B.u16[3] = A.u8[6] + A.u8[7];
	B.u16[4] = A.u8[8] + A.u8[9];
	B.u16[5] = A.u8[10] + A.u8[11];
	B.u16[6] = A.u8[12] + A.u8[13];
	B.u16[7] = A.u8[14] + A.u8[15];

	return B.i;
}

/** \SSE5{Reference,_mm_hsubd_epi16, phsubwd  } */
SSP_FORCEINLINE __m128i ssp_hsubd_epi16_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s32[0] = A.s16[1] - A.s16[0];
	B.s32[1] = A.s16[3] - A.s16[2];
	B.s32[2] = A.s16[5] - A.s16[4];
	B.s32[3] = A.s16[7] - A.s16[6];

	return B.i;
}

/** \SSE5{Reference,_mm_hsubq_epi32, phsubdq  } */
SSP_FORCEINLINE __m128i ssp_hsubq_epi32_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s64[0] = (long long)A.s32[1] - A.s32[0];
	B.s64[1] = (long long)A.s32[3] - A.s32[2];

	return B.i;
}

/** \SSE5{Reference,_mm_hsubw_epi8, phsubbw  } */
SSP_FORCEINLINE __m128i ssp_hsubw_epi8_REF(__m128i a)
{
	ssp_m128 A, B;
	A.i = a;

	B.s16[0] = A.s8[1] - A.s8[0];
	B.s16[1] = A.s8[3] - A.s8[2];
	B.s16[2] = A.s8[5] - A.s8[4];
	B.s16[3] = A.s8[7] - A.s8[6];
	B.s16[4] = A.s8[9] - A.s8[8];
	B.s16[5] = A.s8[11] - A.s8[10];
	B.s16[6] = A.s8[13] - A.s8[12];
	B.s16[7] = A.s8[15] - A.s8[14];

	return B.i;
}

//--------------------------------------
// Multiply Add
//--------------------------------------

/** \SSE5{Reference,_mm_macc_epi16, pmacsww } */ 
SSP_FORCEINLINE __m128i ssp_macc_epi16_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A,B,C;
    A.i = a;
    B.i = b;
    C.i = c;

    A.s16[0] = A.s16[0] * B.s16[0] + C.s16[0];
    A.s16[1] = A.s16[1] * B.s16[1] + C.s16[1];
    A.s16[2] = A.s16[2] * B.s16[2] + C.s16[2];
    A.s16[3] = A.s16[3] * B.s16[3] + C.s16[3];
    A.s16[4] = A.s16[4] * B.s16[4] + C.s16[4];
    A.s16[5] = A.s16[5] * B.s16[5] + C.s16[5];
    A.s16[6] = A.s16[6] * B.s16[6] + C.s16[6];
    A.s16[7] = A.s16[7] * B.s16[7] + C.s16[7];

    return A.i;
}

/** \SSE5{Reference,_mm_macc_epi32, pmacsdd } */ 
SSP_FORCEINLINE __m128i ssp_macc_epi32_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A,B,C;
    A.i = a;
    B.i = b;
    C.i = c;

    A.s32[0] = A.s32[0] * B.s32[0] + C.s32[0];
    A.s32[1] = A.s32[1] * B.s32[1] + C.s32[1];
    A.s32[2] = A.s32[2] * B.s32[2] + C.s32[2];
    A.s32[3] = A.s32[3] * B.s32[3] + C.s32[3];

    return A.i;
}

/** \SSE5{Reference,_mm_macc_ps,fmaddps } */ 
SSP_FORCEINLINE __m128 ssp_macc_ps_REF( __m128 a, __m128 b, __m128 c )
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = A.f32[0] * B.f32[0] + C.f32[0];
    A.f32[1] = A.f32[1] * B.f32[1] + C.f32[1];
    A.f32[2] = A.f32[2] * B.f32[2] + C.f32[2];
    A.f32[3] = A.f32[3] * B.f32[3] + C.f32[3];
    return A.f;
}

/** \SSE5{Reference,_mm_macc_pd,fmaddpd} */ 
SSP_FORCEINLINE __m128d ssp_macc_pd_REF( __m128d a, __m128d b, __m128d c )
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = A.f64[0] * B.f64[0] + C.f64[0];
    A.f64[1] = A.f64[1] * B.f64[1] + C.f64[1]; 
    return A.d;
}

/** \SSE5{Reference,_mm_macc_ss,fmaddss} */ 
SSP_FORCEINLINE __m128 ssp_macc_ss_REF(__m128 a, __m128 b, __m128 c)   // Assuming SSE5 *_ss semantics are similar to _mm_add_ss. TODO: confirm
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = A.f32[0] * B.f32[0] + C.f32[0];   
    return A.f;
}

/** \SSE5{Reference,_mm_macc_sd,fmaddss} */ 
SSP_FORCEINLINE __m128d ssp_macc_sd_REF(__m128d a, __m128d b, __m128d c)   // Assuming SSE5 *_ss semantics are similar to _mm_add_ss. TODO: confirm
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = A.f64[0] * B.f64[0] + C.f64[0];   
    return A.d;
}

/** \SSE5{Reference,_mm_maccd_epi16, pmacswd } */ 
SSP_FORCEINLINE __m128i ssp_maccd_epi16_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
    A.i = a;
    B.i = b;
    C.i = c;

    D.s32[0] = A.s16[0] * B.s16[0] + C.s32[0];
    D.s32[1] = A.s16[2] * B.s16[2] + C.s32[1];
    D.s32[2] = A.s16[4] * B.s16[4] + C.s32[2];
    D.s32[3] = A.s16[6] * B.s16[6] + C.s32[3];

    return D.i;
}

/** \SSE5{Reference,_mm_macchi_epi32, pmacsdqh } */ 
SSP_FORCEINLINE __m128i ssp_macchi_epi32_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
    A.i = a;
    B.i = b;
    C.i = c;

    D.s64[0] = A.s32[1] * B.s32[1] + C.s64[0];
    D.s64[1] = A.s32[3] * B.s32[3] + C.s64[1];

    return D.i;
}

/** \SSE5{Reference,_mm_macclo_epi32, pmacsdql } */ 
SSP_FORCEINLINE __m128i ssp_macclo_epi32_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
    A.i = a;
    B.i = b;
    C.i = c;

    D.s64[0] = A.s32[0] * B.s32[0] + C.s64[0];
    D.s64[1] = A.s32[2] * B.s32[2] + C.s64[1];

    return D.i;
}

#define SSP_SATURATION(a, pos_limit, neg_limit) (a>pos_limit) ? pos_limit : ((a<neg_limit)?neg_limit:a)

/** \SSE5{Reference,_mm_maccs_epi16, pmacssww } */ 
SSP_FORCEINLINE __m128i ssp_maccs_epi16_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C;
	int temp;
    A.i = a;
    B.i = b;
    C.i = c;

	temp = A.s16[0] * B.s16[0] + C.s16[0];
	A.s16[0] = SSP_SATURATION(temp, 32767, -32768);
	temp = A.s16[1] * B.s16[1] + C.s16[1];
    A.s16[1] = SSP_SATURATION(temp, 32767, -32768);
	temp = A.s16[2] * B.s16[2] + C.s16[2];
    A.s16[2] = SSP_SATURATION(temp, 32767, -32768);
	temp = A.s16[3] * B.s16[3] + C.s16[3];
    A.s16[3] = SSP_SATURATION(temp, 32767, -32768);
	temp = A.s16[4] * B.s16[4] + C.s16[4];
    A.s16[4] = SSP_SATURATION(temp, 32767, -32768);
	temp = A.s16[5] * B.s16[5] + C.s16[5];
    A.s16[5] = SSP_SATURATION(temp, 32767, -32768);
	temp = A.s16[6] * B.s16[6] + C.s16[6];
    A.s16[6] = SSP_SATURATION(temp, 32767, -32768);
	temp = A.s16[7] * B.s16[7] + C.s16[7];
    A.s16[7] = SSP_SATURATION(temp, 32767, -32768);

    return A.i;
}

/** \SSE5{Reference,_mm_maccs_epi32, pmacssdd } */ 
SSP_FORCEINLINE __m128i ssp_maccs_epi32_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C;
	long long temp;
    A.i = a;
    B.i = b;
    C.i = c;

	temp = (long long)A.s32[0] * B.s32[0] + C.s32[0];
	A.s32[0] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));
	temp = (long long)A.s32[1] * B.s32[1] + C.s32[1];
    A.s32[1] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));
	temp = (long long)A.s32[2] * B.s32[2] + C.s32[2];
    A.s32[2] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));
	temp = (long long)A.s32[3] * B.s32[3] + C.s32[3];
    A.s32[3] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));

    return A.i;
}

/** \SSE5{Reference,_mm_maccsd_epi16, pmacsswd } */ 
SSP_FORCEINLINE __m128i ssp_maccsd_epi16_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
	long long temp;
    A.i = a;
    B.i = b;
    C.i = c;

	//should be able to compare data to see whether overflow/underflow
	temp = A.s16[0] * B.s16[0] + (long long)C.s32[0];
    D.s32[0] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));
	temp = A.s16[2] * B.s16[2] + (long long)C.s32[1];
    D.s32[1] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));
	temp = A.s16[4] * B.s16[4] + (long long)C.s32[2];
    D.s32[2] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));
	temp = A.s16[6] * B.s16[6] + (long long)C.s32[3];
    D.s32[3] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));

    return D.i;
}

/** \SSE5{Reference,_mm_maccshi_epi32, pmacssdqh } */ 
SSP_FORCEINLINE __m128i ssp_maccshi_epi32_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
	long long temp;
	unsigned long long signT, signC;
    A.i = a;
    B.i = b;
    C.i = c;

	temp = (long long)A.s32[1] * B.s32[1];
	signT = temp & 0x8000000000000000LL;
	signC = C.s64[0] & 0x8000000000000000LL;
	temp += C.s64[0];
	D.s64[0] = (signT==signC) ? ((signT >0) ? ((temp > C.s64[0]) ? 0x8000000000000000LL : temp) 
		: ((temp < C.s64[0])? 0x7FFFFFFFFFFFFFFFLL : temp)) : temp;
	temp = (long long)A.s32[3] * B.s32[3];
	signT = temp & 0x8000000000000000LL;
	signC = C.s64[1] & 0x8000000000000000LL;
	temp += C.s64[1];
	D.s64[1] = (signT==signC) ? ((signT >0) ? ((temp > C.s64[1]) ? 0x8000000000000000LL : temp) 
		: ((temp < C.s64[1])? 0x7FFFFFFFFFFFFFFFLL : temp)) : temp;

    return D.i;
}

/** \SSE5{Reference,_mm_maccslo_epi32, pmacssdql } */ 
SSP_FORCEINLINE __m128i ssp_maccslo_epi32_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
	long long temp;
	unsigned long long signT, signC;
    A.i = a;
    B.i = b;
    C.i = c;

	temp = (long long)A.s32[0] * B.s32[0];
	signT = temp & 0x8000000000000000LL;
	signC = C.s64[0] & 0x8000000000000000LL;
	temp += C.s64[0];
	D.s64[0] = (signT==signC) ? ((signT >0) ? ((temp > C.s64[0]) ? 0x8000000000000000LL : temp) 
		: ((temp < C.s64[0])? 0x7FFFFFFFFFFFFFFFLL : temp)) : temp;
	temp = (long long)A.s32[2] * B.s32[2];
	signT = temp & 0x8000000000000000LL;
	signC = C.s64[1] & 0x8000000000000000LL;
	temp += C.s64[1];
	D.s64[1] = (signT==signC) ? ((signT >0) ? ((temp > C.s64[1]) ? 0x8000000000000000LL : temp) 
		: ((temp < C.s64[1])? 0x7FFFFFFFFFFFFFFFLL : temp)) : temp;

    return D.i;
}

/** \SSE5{Reference,_mm_maddd_epi16, pmadcswd } */ 
SSP_FORCEINLINE __m128i ssp_maddd_epi16_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
    A.i = a;
    B.i = b;
    C.i = c;

    D.s32[0] = A.s16[0] * B.s16[0] + A.s16[1] * B.s16[1] + C.s32[0];
    D.s32[1] = A.s16[2] * B.s16[2] + A.s16[3] * B.s16[3] + C.s32[1];
    D.s32[2] = A.s16[4] * B.s16[4] + A.s16[5] * B.s16[5] + C.s32[2];
    D.s32[3] = A.s16[6] * B.s16[6] + A.s16[7] * B.s16[7] + C.s32[3];

    return D.i;
}

/** \SSE5{Reference,_mm_maddsd_epi16, pmadcsswd } */ 
SSP_FORCEINLINE __m128i ssp_maddsd_epi16_REF( __m128i a, __m128i b, __m128i c )
{
    ssp_m128 A, B, C, D;
	long long temp;

    A.i = a;
    B.i = b;
    C.i = c;

	temp = A.s16[0] * B.s16[0] + A.s16[1] * B.s16[1] + (long long)C.s32[0];
    D.s32[0] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));
	temp = A.s16[2] * B.s16[2] + A.s16[3] * B.s16[3] + (long long)C.s32[1];
    D.s32[1] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));;
	temp = A.s16[4] * B.s16[4] + A.s16[5] * B.s16[5] + (long long)C.s32[2];
    D.s32[2] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));;
	temp = A.s16[6] * B.s16[6] + A.s16[7] * B.s16[7] + (long long)C.s32[3];
    D.s32[3] = (ssp_s32)(SSP_SATURATION(temp, 2147483647LL, -2147483648LL));;

    return D.i;
}

//--------------------------------------
// Negative Multiply Add
//--------------------------------------

/** \SSE5{Reference,_mm_nmacc_ps,fnmaddps} */ 
SSP_FORCEINLINE __m128 ssp_nmacc_ps_REF(__m128 a, __m128 b, __m128 c)
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = -(A.f32[0] * B.f32[0]) + C.f32[0];
    A.f32[1] = -(A.f32[1] * B.f32[1]) + C.f32[1];
    A.f32[2] = -(A.f32[2] * B.f32[2]) + C.f32[2];
    A.f32[3] = -(A.f32[3] * B.f32[3]) + C.f32[3];
    return A.f;
}

/** \SSE5{Reference,_mm_nmacc_pd,fnmaddpd} */ 
SSP_FORCEINLINE __m128d ssp_nmacc_pd_REF(__m128d a, __m128d b, __m128d c)
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = -(A.f64[0] * B.f64[0]) + C.f64[0];
    A.f64[1] = -(A.f64[1] * B.f64[1]) + C.f64[1]; 
    return A.d;
}

/** \SSE5{Reference,_mm_nmacc_ss,fnmaddss} */ 
SSP_FORCEINLINE __m128 ssp_nmacc_ss_REF(__m128 a, __m128 b, __m128 c)
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = -(A.f32[0] * B.f32[0]) + C.f32[0];   
    return A.f;
}

/** \SSE5{Reference,_mm_nmacc_sd,fnmaddsd} */ 
SSP_FORCEINLINE __m128d ssp_nmacc_sd_REF(__m128d a, __m128d b, __m128d c)
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = -(A.f64[0] * B.f64[0]) + C.f64[0];   
    return A.d;
}


//--------------------------------------
// Multiply Subtract
//--------------------------------------

/** \SSE5{Reference,_mm_msub_ps,fmsubps} */ 
SSP_FORCEINLINE __m128 ssp_msub_ps_REF( __m128 a, __m128 b, __m128 c )
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = A.f32[0] * B.f32[0] - C.f32[0];
    A.f32[1] = A.f32[1] * B.f32[1] - C.f32[1];
    A.f32[2] = A.f32[2] * B.f32[2] - C.f32[2];
    A.f32[3] = A.f32[3] * B.f32[3] - C.f32[3];
    return A.f;
}

/** \SSE5{Reference,_mm_msub_pd,fmsubpd} */ 
SSP_FORCEINLINE __m128d ssp_msub_pd_REF( __m128d a, __m128d b, __m128d c )
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = A.f64[0] * B.f64[0] - C.f64[0];
    A.f64[1] = A.f64[1] * B.f64[1] - C.f64[1]; 
    return A.d;
}

/** \SSE5{Reference,_mm_msub_ss,fmsubss} */ 
SSP_FORCEINLINE __m128 ssp_msub_ss_REF(__m128 a, __m128 b, __m128 c)   // Assuming SSE5 *_ss semantics are similar to _mm_add_ss. TODO: confirm
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = A.f32[0] * B.f32[0] - C.f32[0];   
    return A.f;
}

/** \SSE5{Reference,_mm_msub_sd,fmsubss} */ 
SSP_FORCEINLINE __m128d ssp_msub_sd_REF(__m128d a, __m128d b, __m128d c)   // Assuming SSE5 *_ss semantics are similar to _mm_add_ss. TODO: confirm
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = A.f64[0] * B.f64[0] - C.f64[0];   
    return A.d;
}

//--------------------------------------
// Negative Multiply Subtract
//--------------------------------------

/** \SSE5{Reference,_mm_nmsub_ps,fnmsubps} */ 
SSP_FORCEINLINE __m128 ssp_nmsub_ps_REF(__m128 a, __m128 b, __m128 c)
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = -(A.f32[0] * B.f32[0]) - C.f32[0];
    A.f32[1] = -(A.f32[1] * B.f32[1]) - C.f32[1];
    A.f32[2] = -(A.f32[2] * B.f32[2]) - C.f32[2];
    A.f32[3] = -(A.f32[3] * B.f32[3]) - C.f32[3];
    return A.f;
}

/** \SSE5{Reference,_mm_nmsub_pd,fnmsubpd} */ 
SSP_FORCEINLINE __m128d ssp_nmsub_pd_REF(__m128d a, __m128d b, __m128d c)
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = -(A.f64[0] * B.f64[0]) - C.f64[0];
    A.f64[1] = -(A.f64[1] * B.f64[1]) - C.f64[1]; 
    return A.d;
}

/** \SSE5{Reference,_mm_nmsub_ss,fnmsubss} */ 
SSP_FORCEINLINE __m128 ssp_nmsub_ss_REF(__m128 a, __m128 b, __m128 c)
{
    ssp_m128 A,B,C;
    A.f = a;
    B.f = b;
    C.f = c;

    A.f32[0] = -(A.f32[0] * B.f32[0]) - C.f32[0];   
    return A.f;
}

/** \SSE5{Reference,_mm_nmsub_sd,fnmsubsd} */ 
SSP_FORCEINLINE __m128d ssp_nmsub_sd_REF(__m128d a, __m128d b, __m128d c)
{
    ssp_m128 A,B,C;
    A.d = a;
    B.d = b;
    C.d = c;

    A.f64[0] = -(A.f64[0] * B.f64[0]) - C.f64[0];   
    return A.d;
}



//---------------------------------------
// AddSubtract
//---------------------------------------

/** \SSE3{Reference,_mm_addsub_ps} */
SSP_FORCEINLINE __m128 ssp_addsub_ps_REF(__m128 a, __m128 b)
{
    ssp_m128 A, B;
    A.f = a;
    B.f = b;

    A.f32[0] -= B.f32[0];
    A.f32[1] += B.f32[1];
    A.f32[2] -= B.f32[2];
    A.f32[3] += B.f32[3];
    return A.f;
}

/** \SSE3{Reference,_mm_addsub_pd} */
SSP_FORCEINLINE __m128d ssp_addsub_pd_REF(__m128d a, __m128d b)
{
    ssp_m128 A, B;
    A.d = a;
    B.d = b;

    A.f64[0] -= B.f64[0];
    A.f64[1] += B.f64[1];
    return A.d;
}

//---------------------------------------
//Blend
//---------------------------------------

/** \SSE4_1{Reference,_mm_blend_epi16} */
SSP_FORCEINLINE __m128i ssp_blend_epi16_REF     ( __m128i a, __m128i b, const int mask )
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;

    A.s16[0] = (mask & 0x01) ? B.s16[0] : A.s16[0];
    A.s16[1] = (mask & 0x02) ? B.s16[1] : A.s16[1];
    A.s16[2] = (mask & 0x04) ? B.s16[2] : A.s16[2];
    A.s16[3] = (mask & 0x08) ? B.s16[3] : A.s16[3];
    A.s16[4] = (mask & 0x10) ? B.s16[4] : A.s16[4];
    A.s16[5] = (mask & 0x20) ? B.s16[5] : A.s16[5];
    A.s16[6] = (mask & 0x40) ? B.s16[6] : A.s16[6];
    A.s16[7] = (mask & 0x80) ? B.s16[7] : A.s16[7];
    return A.i;
}

/** \SSE4_1{Reference,_mm_blend_pd} */
SSP_FORCEINLINE __m128d ssp_blend_pd_REF        ( __m128d a, __m128d b, const int mask )
{
    ssp_m128 A, B;
    A.d = a;
    B.d = b;

    A.f64[0] = (mask & 0x1) ? B.f64[0] : A.f64[0];
    A.f64[1] = (mask & 0x2) ? B.f64[1] : A.f64[1];
    return A.d;
}

/** \SSE4_1{Reference,_mm_blend_ps} */
SSP_FORCEINLINE __m128 ssp_blend_ps_REF        ( __m128 a, __m128 b, const int mask )
{
    ssp_m128 A, B;
    A.f = a;
    B.f = b;

    A.f32[0] = (mask & 0x1) ? B.f32[0] : A.f32[0];
    A.f32[1] = (mask & 0x2) ? B.f32[1] : A.f32[1];
    A.f32[2] = (mask & 0x4) ? B.f32[2] : A.f32[2];
    A.f32[3] = (mask & 0x8) ? B.f32[3] : A.f32[3];
    return A.f;
}

/** \SSE4_1{Reference,_mm_blendv_epi8} */
SSP_FORCEINLINE __m128i ssp_blendv_epi8_REF     ( __m128i a, __m128i b, __m128i mask )
{
    ssp_m128 A, B, Mask;
    A.i = a;
    B.i = b;
    Mask.i = mask;

    A.s8[0]  = (Mask.s8[0]  & 0x80) ? B.s8[0]  : A.s8[0];
    A.s8[1]  = (Mask.s8[1]  & 0x80) ? B.s8[1]  : A.s8[1];
    A.s8[2]  = (Mask.s8[2]  & 0x80) ? B.s8[2]  : A.s8[2];
    A.s8[3]  = (Mask.s8[3]  & 0x80) ? B.s8[3]  : A.s8[3];
    A.s8[4]  = (Mask.s8[4]  & 0x80) ? B.s8[4]  : A.s8[4];
    A.s8[5]  = (Mask.s8[5]  & 0x80) ? B.s8[5]  : A.s8[5];
    A.s8[6]  = (Mask.s8[6]  & 0x80) ? B.s8[6]  : A.s8[6];
    A.s8[7]  = (Mask.s8[7]  & 0x80) ? B.s8[7]  : A.s8[7];
    A.s8[8]  = (Mask.s8[8]  & 0x80) ? B.s8[8]  : A.s8[8];
    A.s8[9]  = (Mask.s8[9]  & 0x80) ? B.s8[9]  : A.s8[9];
    A.s8[10] = (Mask.s8[10] & 0x80) ? B.s8[10] : A.s8[10];
    A.s8[11] = (Mask.s8[11] & 0x80) ? B.s8[11] : A.s8[11];
    A.s8[12] = (Mask.s8[12] & 0x80) ? B.s8[12] : A.s8[12];
    A.s8[13] = (Mask.s8[13] & 0x80) ? B.s8[13] : A.s8[13];
    A.s8[14] = (Mask.s8[14] & 0x80) ? B.s8[14] : A.s8[14];
    A.s8[15] = (Mask.s8[15] & 0x80) ? B.s8[15] : A.s8[15];
    return A.i;
}

/** \SSE4_1{Reference,_mm_blendv_pd} */
SSP_FORCEINLINE __m128d ssp_blendv_pd_REF       ( __m128d a, __m128d b, __m128d mask )
{
    ssp_m128 A, B, Mask;
    A.d = a;
    B.d = b;
    Mask.d = mask;

    A.f64[0] = (Mask.u64[0] & 0x8000000000000000ll) ? B.f64[0] : A.f64[0];
    A.f64[1] = (Mask.u64[1] & 0x8000000000000000ll) ? B.f64[1] : A.f64[1];
    return A.d;
}

/** \SSE4_1{Reference,_mm_blendv_epi8} */
SSP_FORCEINLINE __m128 ssp_blendv_ps_REF       ( __m128 a, __m128 b, __m128 mask )     
{
    ssp_m128 A, B, Mask;
    A.f = a;
    B.f = b;
    Mask.f = mask;

    A.f32[0] = (Mask.u32[0] & 0x80000000) ? B.f32[0] : A.f32[0];
    A.f32[1] = (Mask.u32[1] & 0x80000000) ? B.f32[1] : A.f32[1];
    A.f32[2] = (Mask.u32[2] & 0x80000000) ? B.f32[2] : A.f32[2];
    A.f32[3] = (Mask.u32[3] & 0x80000000) ? B.f32[3] : A.f32[3];
    return A.f;
}


//---------------------------------------
//Compare
//---------------------------------------
/** \SSE4_1{Reference,_mm_cmpeq_epi64} */
SSP_FORCEINLINE __m128i ssp_cmpeq_epi64_REF( __m128i a, __m128i b )                       
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;

    if( A.s64[0] == B.s64[0] )
        A.s64[0] = 0xFFFFFFFFFFFFFFFFll;
    else
        A.s64[0] = 0x0ll;

    if( A.s64[1] == B.s64[1] )
        A.s64[1] = 0xFFFFFFFFFFFFFFFFll;
    else
        A.s64[1] = 0x0ll;
    return A.i;
}

//---------------------------------------
// Dot Product
//---------------------------------------
/** \SSE4_1{Reference,_mm_dp_pd} */
SSP_FORCEINLINE __m128d ssp_dp_pd_REF( __m128d a, __m128d b, const int mask )             
{
    ssp_f64 tmp[3];
    ssp_m128 A, B;
    A.d = a;
    B.d = b;

    tmp[0] = (mask & 0x10) ? (A.f64[0] * B.f64[0]) : 0.0;
    tmp[1] = (mask & 0x20) ? (A.f64[1] * B.f64[1]) : 0.0;

    tmp[2] = tmp[0] + tmp[1];

    A.f64[0] = (mask & 0x1) ? tmp[2] : 0.0;
    A.f64[1] = (mask & 0x2) ? tmp[2] : 0.0;
    return A.d;
}

/** \SSE4_1{Reference,_mm_dp_ps} */
SSP_FORCEINLINE __m128 ssp_dp_ps_REF( __m128 a, __m128 b, const int mask )                
{
    ssp_f32 tmp[5];
    ssp_m128 A, B;
    A.f = a;
    B.f = b;

    tmp[0] = (mask & 0x10) ? (A.f32[0] * B.f32[0]) : 0.0f;
    tmp[1] = (mask & 0x20) ? (A.f32[1] * B.f32[1]) : 0.0f;
    tmp[2] = (mask & 0x40) ? (A.f32[2] * B.f32[2]) : 0.0f;
    tmp[3] = (mask & 0x80) ? (A.f32[3] * B.f32[3]) : 0.0f;

    tmp[4] = tmp[0] + tmp[1] + tmp[2] + tmp[3];

    A.f32[0] = (mask & 0x1) ? tmp[4] : 0.0f;
    A.f32[1] = (mask & 0x2) ? tmp[4] : 0.0f;
    A.f32[2] = (mask & 0x4) ? tmp[4] : 0.0f;
    A.f32[3] = (mask & 0x8) ? tmp[4] : 0.0f;
    return A.f;
}

/** \SSSE3{Reference,_mm_maddubs_epi16} */
SSP_FORCEINLINE __m128i ssp_maddubs_epi16_REF( __m128i a,  __m128i b)
{
    ssp_m128 A, B, C;
	int tmp[8];
    A.i = a;
    B.i = b;

	// a is 8 bit unsigned integer, b is signed integer
	tmp[0] = A.u8[0] * B.s8[0] +  A.u8[1] * B.s8[1];
	C.s16[0] = (ssp_s16)(SSP_SATURATION(tmp[0], 32767, -32768));

	tmp[1] = A.u8[2] * B.s8[2] +  A.u8[3] * B.s8[3];
	C.s16[1] = (ssp_s16)(SSP_SATURATION(tmp[1], 32767, -32768));

	tmp[2] = A.u8[4] * B.s8[4] +  A.u8[5] * B.s8[5];
	C.s16[2] = (ssp_s16)(SSP_SATURATION(tmp[2], 32767, -32768));

	tmp[3] = A.u8[6] * B.s8[6] +  A.u8[7] * B.s8[7];
	C.s16[3] = (ssp_s16)(SSP_SATURATION(tmp[3], 32767, -32768));

	tmp[4] = A.u8[8] * B.s8[8] +  A.u8[9] * B.s8[9];
	C.s16[4] = (ssp_s16)(SSP_SATURATION(tmp[4], 32767, -32768));

	tmp[5] = A.u8[10] * B.s8[10] +  A.u8[11] * B.s8[11];
	C.s16[5] = (ssp_s16)(SSP_SATURATION(tmp[5], 32767, -32768));

	tmp[6] = A.u8[12] * B.s8[12] +  A.u8[13] * B.s8[13];
	C.s16[6] = (ssp_s16)(SSP_SATURATION(tmp[6], 32767, -32768));

	tmp[7] = A.u8[14] * B.s8[14] +  A.u8[15] * B.s8[15];
	C.s16[7] = (ssp_s16)(SSP_SATURATION(tmp[7], 32767, -32768));

	return C.i;
}

/** \SSSE3{Reference,_mm_maddubs_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
 */
//__m64 _mm_maddubs_pi16( __m64 a,  __m64 b); [SSSE3]
SSP_FORCEINLINE __m64 ssp_maddubs_pi16_REF( __m64 a,  __m64 b)
{
    ssp_m64 A, B, C;
	int tmp[4];
    A.m64 = a;
    B.m64 = b;

	// a is 8 bit unsigned integer, b is signed integer
	tmp[0] = A.u8[0] * B.s8[0] +  A.u8[1] * B.s8[1];
	C.s16[0] = (ssp_s16)(SSP_SATURATION(tmp[0], 32767, -32768));

	tmp[1] = A.u8[2] * B.s8[2] +  A.u8[3] * B.s8[3];
	C.s16[1] = (ssp_s16)(SSP_SATURATION(tmp[1], 32767, -32768));

	tmp[2] = A.u8[4] * B.s8[4] +  A.u8[5] * B.s8[5];
	C.s16[2] = (ssp_s16)(SSP_SATURATION(tmp[2], 32767, -32768));

	tmp[3] = A.u8[6] * B.s8[6] +  A.u8[7] * B.s8[7];
	C.s16[3] = (ssp_s16)(SSP_SATURATION(tmp[3], 32767, -32768));

	return C.m64;
}

//__m128i _mm_mulhrs_epi16( __m128i a,  __m128i b);
/** \SSSE3{Reference,_mm_mulhrs_epi16} */
SSP_FORCEINLINE __m128i ssp_mulhrs_epi16_REF( __m128i a, __m128i b )
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

	A.s16[0] = (ssp_s16) ((A.s16[0] * B.s16[0] + 0x4000) >> 15);
	A.s16[1] = (ssp_s16) ((A.s16[1] * B.s16[1] + 0x4000) >> 15);
	A.s16[2] = (ssp_s16) ((A.s16[2] * B.s16[2] + 0x4000) >> 15);
	A.s16[3] = (ssp_s16) ((A.s16[3] * B.s16[3] + 0x4000) >> 15);
	A.s16[4] = (ssp_s16) ((A.s16[4] * B.s16[4] + 0x4000) >> 15);
	A.s16[5] = (ssp_s16) ((A.s16[5] * B.s16[5] + 0x4000) >> 15);
	A.s16[6] = (ssp_s16) ((A.s16[6] * B.s16[6] + 0x4000) >> 15);
	A.s16[7] = (ssp_s16) ((A.s16[7] * B.s16[7] + 0x4000) >> 15);

    return A.i;
}

//__m64 _mm_mulhrs_epi16( __m64 a,  __m64 b);
/** \SSSE3{Reference,_mm_mulhrs_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_mulhrs_pi16_REF( __m64 a, __m64 b )
{
    ssp_m64 A,B;
    A.m64 = a;
    B.m64 = b;

	A.s16[0] = (ssp_s16) ((A.s16[0] * B.s16[0] + 0x4000) >> 15);
	A.s16[1] = (ssp_s16) ((A.s16[1] * B.s16[1] + 0x4000) >> 15);
	A.s16[2] = (ssp_s16) ((A.s16[2] * B.s16[2] + 0x4000) >> 15);
	A.s16[3] = (ssp_s16) ((A.s16[3] * B.s16[3] + 0x4000) >> 15);

    return A.m64;
}

//---------------------------------------
//Extract
//---------------------------------------

// TODO PHS: Test the actual intrinsic to deterine what value is returned if he ndx/imm is a large number.
//           ie.  for _mm_extract_epi8, what is returned if ndx = 20 [since 20=0x14 > 0x0F]?
//           Repeat procedures for other extract functions.
/** \SSE4_1{Reference,_mm_extract_epi8} */
SSP_FORCEINLINE int ssp_extract_epi8_REF( __m128i a, const int ndx )                       
{
    ssp_m128 A;
    A.i = a;
    return (int)A.u8[ndx&0xF];
}

/** \SSE4_1{Reference,_mm_extract_epi32} */
SSP_FORCEINLINE int ssp_extract_epi32_REF( __m128i a, const int imm )                            
{
    ssp_m128 A;
    A.i = a;
    return (int)A.u32[imm&0x3];
}

/** \SSE4_1{Reference,_mm_extract_epi64} */
SSP_FORCEINLINE ssp_s64 ssp_extract_epi64_REF( __m128i a, const int ndx )                  
{
    ssp_m128 A;
    A.i = a;
    return A.s64[ndx & 0x1];
}

/** \SSE4_1{Reference,_mm_extract_ps} */
SSP_FORCEINLINE int ssp_extract_ps_REF( __m128 a, const int ndx )                          
{ 
    ssp_m128 A;
    A.f = a; 
    return A.s32[ndx&0x3];
}


/**  \SSE4a{Reference,_mm_extract_si64} 
\n  NOTE: The upper 64-bit of the destination register are undefined.
*/
SSP_FORCEINLINE __m128i ssp_extract_si64_REF( __m128i a ,__m128i b )        
{
    ssp_u32 len, ndx;
    ssp_s64 mask;
    ssp_m128 A, B;
    A.i = a;
    B.i = b;
    ndx = (ssp_u32)((B.u64[0] & 0x3F00) >> 8);    // Mask ndx field.
    len = (ssp_u32)((B.u64[0] & 0x003F));         // Mask len field.

    len = (len) ? len : 64;    
    if( (ndx+len) > 64 )               // If the sum of ndx and length is greater than 64, the results are undefined.
        return a;                      // If index = 0 and length = 0/64, extract all lower bits.
    mask = ~(-1 << len);
    A.u64[0] = A.u64[0] >> ndx;
    A.u64[0] = A.u64[0] & mask;
    return A.i;
}
/**  \SSE4a{Reference,_mm_extracti_si64}
\n  NOTE: The upper 64-bits of the destination register are undefined.
*/
SSP_FORCEINLINE __m128i ssp_extracti_si64_REF( __m128i a, int len, int ndx )   
{
    ssp_s64 mask;
    ssp_m128 A;
    A.i = a;
    ndx = ndx & 0x3F; // ndx % 64
    len = len & 0x3F; // len % 64

    len = (len) ? len : 64;    
    if( (ndx+len) > 64 )               // If the sum of ndx and length is greater than 64, the results are undefined.
        return a;                      // If index = 0 and length = 0/64, extract all lower bits.
    mask = ~(-1 << len);
    A.u64[0] = A.u64[0] >> ndx;
    A.u64[0] = A.u64[0] & mask;
    return A.i;
}



//---------------------------------------
// Horizontal Add
//---------------------------------------
/** \SSSE3{Reference,_mm_hadd_epi16} */
SSP_FORCEINLINE __m128i ssp_hadd_epi16_REF ( __m128i a, __m128i b )                       
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;

    A.s16[0] = A.s16[0] + A.s16[1];
    A.s16[1] = A.s16[2] + A.s16[3];
    A.s16[2] = A.s16[4] + A.s16[5];
    A.s16[3] = A.s16[6] + A.s16[7];
    A.s16[4] = B.s16[0] + B.s16[1];
    A.s16[5] = B.s16[2] + B.s16[3];
    A.s16[6] = B.s16[4] + B.s16[5];
    A.s16[7] = B.s16[6] + B.s16[7];
    return A.i;
}

/** \SSSE3{Reference,_mm_hadd_epi32} */
SSP_FORCEINLINE __m128i ssp_hadd_epi32_REF ( __m128i a, __m128i b )                        
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;

    A.s32[0] = A.s32[0] + A.s32[1];
    A.s32[1] = A.s32[2] + A.s32[3];
    A.s32[2] = B.s32[0] + B.s32[1];
    A.s32[3] = B.s32[2] + B.s32[3];

    return A.i;
}

/** \SSSE3{Reference,_mm_hadd_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_hadd_pi16_REF ( __m64 a, __m64 b )                        
{
    ssp_m64 A, B;
    A.m64 = a;
    B.m64 = b;

    A.s16[0] = A.s16[0] + A.s16[1];
    A.s16[1] = A.s16[2] + A.s16[3];
    A.s16[2] = B.s16[0] + B.s16[1];
    A.s16[3] = B.s16[2] + B.s16[3];

    return A.m64;
}

/** \SSSE3{Reference,_mm_add_pi32}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_hadd_pi32_REF ( __m64 a, __m64 b )                        
{
    ssp_m64 A, B;
    A.m64 = a;
    B.m64 = b;

    A.s32[0] = A.s32[0] + A.s32[1];
    A.s32[1] = B.s32[0] + B.s32[1];

    return A.m64;
}

/** \SSSE3{Reference,_mm_hadds_epi16} */
SSP_FORCEINLINE __m128i ssp_hadds_epi16_REF ( __m128i a, __m128i b )                         
{
    ssp_m128 A, B;
	int answer[8];
    A.i = a;
    B.i = b;

	answer[0] = A.s16[0] + A.s16[1];
    A.s16[0]  = (ssp_s16) (SSP_SATURATION(answer[0], 32767, -32768));
	answer[1] = A.s16[2] + A.s16[3];
    A.s16[1]  = (ssp_s16) (SSP_SATURATION(answer[1], 32767, -32768));
	answer[2] = A.s16[4] + A.s16[5];
    A.s16[2]  = (ssp_s16) (SSP_SATURATION(answer[2], 32767, -32768));
	answer[3] = A.s16[6] + A.s16[7];
    A.s16[3]  = (ssp_s16) (SSP_SATURATION(answer[3], 32767, -32768));
	answer[4] = B.s16[0] + B.s16[1];
    A.s16[4]  = (ssp_s16) (SSP_SATURATION(answer[4], 32767, -32768));
	answer[5] = B.s16[2] + B.s16[3];
    A.s16[5]  = (ssp_s16) (SSP_SATURATION(answer[5], 32767, -32768));
	answer[6] = B.s16[4] + B.s16[5];
    A.s16[6]  = (ssp_s16) (SSP_SATURATION(answer[6], 32767, -32768));
	answer[7] = B.s16[6] + B.s16[7];
    A.s16[7]  = (ssp_s16) (SSP_SATURATION(answer[7], 32767, -32768));

	return A.i;
}

/** \SSSE3{Reference,_mm_hadds_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_hadds_pi16_REF ( __m64 a, __m64 b )                         
{
    ssp_m64 A, B;
	int answer[4];
    A.m64 = a;
    B.m64 = b;

	answer[0] = A.s16[0] + A.s16[1];
    A.s16[0]  = (ssp_s16) (SSP_SATURATION(answer[0], 32767, -32768));
	answer[1] = A.s16[2] + A.s16[3];
    A.s16[1]  = (ssp_s16) (SSP_SATURATION(answer[1], 32767, -32768));
	answer[2] = B.s16[0] + B.s16[1];
    A.s16[2]  = (ssp_s16) (SSP_SATURATION(answer[2], 32767, -32768));
	answer[3] = B.s16[2] + B.s16[3];
    A.s16[3]  = (ssp_s16) (SSP_SATURATION(answer[3], 32767, -32768));

	return A.m64;
}

/** \SSSE3{Reference,_mm_hadd_ps} */
SSP_FORCEINLINE __m128 ssp_hadd_ps_REF(__m128 a, __m128 b)                                 
{
    ssp_m128 A, B;
    A.f = a;
    B.f = b;

    A.f32[0] = A.f32[0] + A.f32[1];
    A.f32[1] = A.f32[2] + A.f32[3];
    A.f32[2] = B.f32[0] + B.f32[1];
    A.f32[3] = B.f32[2] + B.f32[3];
    return A.f;
}

/** \SSSE3{Reference,_mm_hadd_pd} */
SSP_FORCEINLINE __m128d ssp_hadd_pd_REF(__m128d a, __m128d b)                               
{
    ssp_m128 A, B;
    A.d = a;
    B.d = b;

    A.f64[0] = A.f64[0] + A.f64[1];
    A.f64[1] = B.f64[0] + B.f64[1];
    return A.d;
}


//---------------------------------------
// Horizontal Subtract
//---------------------------------------
/** \SSSE3{Reference,_mm_hsub_epi16} */
SSP_FORCEINLINE __m128i ssp_hsub_epi16_REF ( __m128i a, __m128i b )                        
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;

    A.s16[0] = A.s16[0] - A.s16[1];
    A.s16[1] = A.s16[2] - A.s16[3];
    A.s16[2] = A.s16[4] - A.s16[5];
    A.s16[3] = A.s16[6] - A.s16[7];
    A.s16[4] = B.s16[0] - B.s16[1];
    A.s16[5] = B.s16[2] - B.s16[3];
    A.s16[6] = B.s16[4] - B.s16[5];
    A.s16[7] = B.s16[6] - B.s16[7];

	return A.i;
}

/** \SSSE3{Reference,_mm_hsub_epi32} */
SSP_FORCEINLINE __m128i ssp_hsub_epi32_REF ( __m128i a, __m128i b )                        
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;

    A.s32[0] = A.s32[0] - A.s32[1];
    A.s32[1] = A.s32[2] - A.s32[3];
    A.s32[2] = B.s32[0] - B.s32[1];
    A.s32[3] = B.s32[2] - B.s32[3];

    return A.i;
}

/** \SSSE3{Reference,_mm_hsub_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_hsub_pi16_REF ( __m64 a, __m64 b )                         
{
    ssp_m64 A, B;
    A.m64 = a;
    B.m64 = b;

    A.s16[0] = A.s16[0] - A.s16[1];
    A.s16[1] = A.s16[2] - A.s16[3];
    A.s16[2] = B.s16[0] - B.s16[1];
    A.s16[3] = B.s16[2] - B.s16[3];

	return A.m64;
}

/** \SSSE3{Reference,_mm_hsub_pi32}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_hsub_pi32_REF ( __m64 a, __m64 b )                         
{
    ssp_m64 A, B;
    A.m64 = a;
    B.m64 = b;

    A.s32[0] = A.s32[0] - A.s32[1];
    A.s32[1] = B.s32[0] - B.s32[1];

    return A.m64;
}

/** \SSSE3{Reference,_mm_hsubs_epi16} */
SSP_FORCEINLINE __m128i ssp_hsubs_epi16_REF ( __m128i a, __m128i b )                 
{
    ssp_m128 A, B;
	int answer[8];
    A.i = a;
    B.i = b;

	answer[0] = A.s16[0] - A.s16[1];
    A.s16[0]  = (ssp_s16) (SSP_SATURATION(answer[0], 32767, -32768));
	answer[1] = A.s16[2] - A.s16[3];
    A.s16[1]  = (ssp_s16) (SSP_SATURATION(answer[1], 32767, -32768));
	answer[2] = A.s16[4] - A.s16[5];
    A.s16[2]  = (ssp_s16) (SSP_SATURATION(answer[2], 32767, -32768));
	answer[3] = A.s16[6] - A.s16[7];
    A.s16[3]  = (ssp_s16) (SSP_SATURATION(answer[3], 32767, -32768));
	answer[4] = B.s16[0] - B.s16[1];
    A.s16[4]  = (ssp_s16) (SSP_SATURATION(answer[4], 32767, -32768));
	answer[5] = B.s16[2] - B.s16[3];
    A.s16[5]  = (ssp_s16) (SSP_SATURATION(answer[5], 32767, -32768));
	answer[6] = B.s16[4] - B.s16[5];
    A.s16[6]  = (ssp_s16) (SSP_SATURATION(answer[6], 32767, -32768));
	answer[7] = B.s16[6] - B.s16[7];
    A.s16[7]  = (ssp_s16) (SSP_SATURATION(answer[7], 32767, -32768));

	return A.i;
}

/** \SSSE3{Reference,_mm_hsubs_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_hsubs_pi16_REF ( __m64 a, __m64 b )                        
{
    ssp_m64 A, B;
	int answer[4];
    A.m64 = a;
    B.m64 = b;

	answer[0] = A.s16[0] - A.s16[1];
    A.s16[0]  = (ssp_s16) (SSP_SATURATION(answer[0], 32767, -32768));
	answer[1] = A.s16[2] - A.s16[3];
    A.s16[1]  = (ssp_s16) (SSP_SATURATION(answer[1], 32767, -32768));
	answer[2] = B.s16[0] - B.s16[1];
    A.s16[2]  = (ssp_s16) (SSP_SATURATION(answer[2], 32767, -32768));
	answer[3] = B.s16[2] - B.s16[3];
    A.s16[3]  = (ssp_s16) (SSP_SATURATION(answer[3], 32767, -32768));

	return A.m64;
}

/** \SSSE3{Reference,_mm_hsub_ps} */
SSP_FORCEINLINE __m128 ssp_hsub_ps_REF(__m128 a, __m128 b)                           
{
    ssp_m128 A, B;
    A.f = a;
    B.f = b;

    A.f32[0] = A.f32[0] - A.f32[1];
    A.f32[1] = A.f32[2] - A.f32[3];
    A.f32[2] = B.f32[0] - B.f32[1];
    A.f32[3] = B.f32[2] - B.f32[3];
    return A.f;
}

/** \SSSE3{Reference,_mm_hsub_pd} */
SSP_FORCEINLINE __m128d ssp_hsub_pd_REF(__m128d a, __m128d b)                        
{
    ssp_m128 A, B;
    A.d = a;
    B.d = b;

    A.f64[0] = A.f64[0] - A.f64[1];
    A.f64[1] = B.f64[0] - B.f64[1];
    return A.d;
}

//---------------------------------------
//Insert
//---------------------------------------
/** \SSE4_1{Reference,_mm_insert_epi8} */
SSP_FORCEINLINE __m128i ssp_insert_epi8_REF( __m128i a, int b, const int ndx )       // Verify behavior on Intel Hardware
{
    ssp_m128 A;
    A.i = a;

    A.s8[ndx & 0xF] = (ssp_s8)b;
    return A.i;
}

/** \SSE4_1{Reference,_mm_insert_epi32} */
SSP_FORCEINLINE __m128i ssp_insert_epi32_REF( __m128i a, int b, const int ndx )      // Verify behavior on Intel Hardware
{
    ssp_m128 A;
    A.i = a;

    A.s32[ndx & 0x3] = b;
    return A.i;
}

/** \SSE4_1{Reference,_mm_insert_epi64} */
SSP_FORCEINLINE __m128i ssp_insert_epi64_REF( __m128i a, ssp_s64 b, const int ndx )  // Verify behavior on Intel Hardware
{
    ssp_m128 A;
    A.i = a;

    A.s64[ndx & 0x1] = b;
    return A.i;
}

/** \SSE4_1{Reference,_mm_insert_ps} */
SSP_FORCEINLINE __m128 ssp_insert_ps_REF( __m128 a, __m128 b, const int sel )          // Verify behavior on Intel Hardware
{
    ssp_f32 tmp;
    int count_d,zmask;

    ssp_m128 A,B;
    A.f = a;
    B.f = b;

    tmp     = B.f32[(sel & 0xC0)>>6];   // 0xC0 = sel[7:6]
    count_d = (sel & 0x30)>>4;          // 0x30 = sel[5:4]
    zmask   = sel & 0x0F;               // 0x0F = sel[3:0]

    A.f32[count_d] = tmp;

    A.f32[0] = (zmask & 0x1) ? 0 : A.f32[0];
    A.f32[1] = (zmask & 0x2) ? 0 : A.f32[1];
    A.f32[2] = (zmask & 0x4) ? 0 : A.f32[2];
    A.f32[3] = (zmask & 0x8) ? 0 : A.f32[3];
    return A.f;
}

/** \SSE4a{Reference,_mm_insert_si64} */
SSP_FORCEINLINE __m128i ssp_insert_si64_REF( __m128i a, __m128i b )
{
    ssp_u32  ndx, len;
    ssp_s64  mask;
    ssp_m128 A, B;
    B.i = b;
    ndx = (ssp_u32)((B.u64[1] & 0x3F00) >> 8);    // Mask length field.
    len = (ssp_u32)((B.u64[1] & 0x003F));         // Mask ndx field.

    if( ( (ndx + len) > 64 ) ||
        ( (len == 0) && (ndx > 0) ) )
        return a;

    A.i = a;
    if( (len == 0 ) && (ndx == 0) )
    {
        A.u64[0] = B.u64[0];
        return A.i;
    }

    len = (len) ? len : 64;         // A value of zero for field length is interpreted as 64.
    mask = ~(-1 << len);
    B.u64[0]  = B.u64[0] & mask;
    B.u64[0]  = B.u64[0] << ndx;
    mask      = ~(mask << ndx);
    A.u64[0]  = A.u64[0] & mask;
    A.u64[0] |= B.u64[0];
    return A.i;
}

/** \SSE4a{Reference,_mm_inserti_si64} */
SSP_FORCEINLINE __m128i ssp_inserti_si64_REF( __m128i a, __m128i b, int len, int ndx )
{
    ssp_s64 mask;
    ssp_m128 A, B;
    A.i = a;
    ndx = ndx & 0x3F; // ndx % 64
    len = len & 0x3F; // len % 64

    if( ( (ndx + len) > 64 ) ||
        ( (len == 0) && (ndx > 0) ) )
        return a;

    B.i = b;
    if( (len == 0 ) && (ndx == 0) )
    {
        A.u64[0] = B.u64[0];
        return A.i;
    }

    len = (len) ? len : 64;         // A value of zero for field length is interpreted as 64.
    mask = ~(-1 << len);
    B.u64[0]  = B.u64[0] & mask;
    B.u64[0]  = B.u64[0] << ndx;
    mask      = ~(mask << ndx);
    A.u64[0]  = A.u64[0] & mask;
    A.u64[0] |= B.u64[0];
    return A.i;
}



//---------------------------------------
// Load
//---------------------------------------
/** \SSE3{Reference,_mm_loaddup_pd} */
SSP_FORCEINLINE __m128d ssp_loaddup_pd_REF(double const * dp)                               
{
    ssp_m128 a;
    a.f64[0] = *dp;
    a.f64[1] = *dp;
    return a.d;
}

/** \SSE3{Reference,_mm_lddqu_si128} */
SSP_FORCEINLINE __m128i ssp_lddqu_si128_REF(__m128i const *p)                               
{
    return *p;
}

/** \SSE4_1{Reference,_mm_stream_load_si128} */
SSP_FORCEINLINE __m128i ssp_stream_load_si128_REF( __m128i *p )                             
{
    return *p;
}


//---------------------------------------
// Min / Max
//---------------------------------------

#define SSP_SET_MIN( sd, s) sd=(sd<s)?sd:s;
#define SSP_SET_MAX( sd, s) sd=(sd>s)?sd:s;

//8 bit min/max
/** \SSE4_1{Reference,_mm_min_epi8} */
SSP_FORCEINLINE __m128i ssp_min_epi8_REF( __m128i a, __m128i b )
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MIN( A.s8[ 0], B.s8[ 0] );
    SSP_SET_MIN( A.s8[ 1], B.s8[ 1] );
    SSP_SET_MIN( A.s8[ 2], B.s8[ 2] );
    SSP_SET_MIN( A.s8[ 3], B.s8[ 3] );
    SSP_SET_MIN( A.s8[ 4], B.s8[ 4] );
    SSP_SET_MIN( A.s8[ 5], B.s8[ 5] );
    SSP_SET_MIN( A.s8[ 6], B.s8[ 6] );
    SSP_SET_MIN( A.s8[ 7], B.s8[ 7] );
    SSP_SET_MIN( A.s8[ 8], B.s8[ 8] );
    SSP_SET_MIN( A.s8[ 9], B.s8[ 9] );
    SSP_SET_MIN( A.s8[10], B.s8[10] );
    SSP_SET_MIN( A.s8[11], B.s8[11] );
    SSP_SET_MIN( A.s8[12], B.s8[12] );
    SSP_SET_MIN( A.s8[13], B.s8[13] );
    SSP_SET_MIN( A.s8[14], B.s8[14] );
    SSP_SET_MIN( A.s8[15], B.s8[15] );
    return A.i;
}

/** \SSE4_1{Reference,_mm_max_epi8} */
SSP_FORCEINLINE __m128i ssp_max_epi8_REF( __m128i a, __m128i b )
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MAX( A.s8[ 0], B.s8[ 0] );
    SSP_SET_MAX( A.s8[ 1], B.s8[ 1] );
    SSP_SET_MAX( A.s8[ 2], B.s8[ 2] );
    SSP_SET_MAX( A.s8[ 3], B.s8[ 3] );
    SSP_SET_MAX( A.s8[ 4], B.s8[ 4] );
    SSP_SET_MAX( A.s8[ 5], B.s8[ 5] );
    SSP_SET_MAX( A.s8[ 6], B.s8[ 6] );
    SSP_SET_MAX( A.s8[ 7], B.s8[ 7] );
    SSP_SET_MAX( A.s8[ 8], B.s8[ 8] );
    SSP_SET_MAX( A.s8[ 9], B.s8[ 9] );
    SSP_SET_MAX( A.s8[10], B.s8[10] );
    SSP_SET_MAX( A.s8[11], B.s8[11] );
    SSP_SET_MAX( A.s8[12], B.s8[12] );
    SSP_SET_MAX( A.s8[13], B.s8[13] );
    SSP_SET_MAX( A.s8[14], B.s8[14] );
    SSP_SET_MAX( A.s8[15], B.s8[15] );
    return A.i;
}

//16 bit min/max
/** \SSE4_1{Reference,_mm_min_epu16} */
SSP_FORCEINLINE __m128i ssp_min_epu16_REF ( __m128i a, __m128i b )
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MIN( A.u16[ 0], B.u16[ 0] );
    SSP_SET_MIN( A.u16[ 1], B.u16[ 1] );
    SSP_SET_MIN( A.u16[ 2], B.u16[ 2] );
    SSP_SET_MIN( A.u16[ 3], B.u16[ 3] );
    SSP_SET_MIN( A.u16[ 4], B.u16[ 4] );
    SSP_SET_MIN( A.u16[ 5], B.u16[ 5] );
    SSP_SET_MIN( A.u16[ 6], B.u16[ 6] );
    SSP_SET_MIN( A.u16[ 7], B.u16[ 7] );
    return A.i;
}

/** \SSE4_1{Reference,_mm_max_epu16} */
SSP_FORCEINLINE __m128i ssp_max_epu16_REF ( __m128i a, __m128i b )
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MAX( A.u16[ 0], B.u16[ 0] );
    SSP_SET_MAX( A.u16[ 1], B.u16[ 1] );
    SSP_SET_MAX( A.u16[ 2], B.u16[ 2] );
    SSP_SET_MAX( A.u16[ 3], B.u16[ 3] );
    SSP_SET_MAX( A.u16[ 4], B.u16[ 4] );
    SSP_SET_MAX( A.u16[ 5], B.u16[ 5] );
    SSP_SET_MAX( A.u16[ 6], B.u16[ 6] );
    SSP_SET_MAX( A.u16[ 7], B.u16[ 7] );
    return A.i;
}

//32 bit min/max
/** \SSE4_1{Reference,_mm_min_epi32} */
SSP_FORCEINLINE __m128i ssp_min_epi32_REF( __m128i a, __m128i b )                     
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MIN( A.s32[ 0], B.s32[ 0] );
    SSP_SET_MIN( A.s32[ 1], B.s32[ 1] );
    SSP_SET_MIN( A.s32[ 2], B.s32[ 2] );
    SSP_SET_MIN( A.s32[ 3], B.s32[ 3] );
    return A.i;
}

/** \SSE4_1{Reference,_mm_max_epi32} */
SSP_FORCEINLINE __m128i ssp_max_epi32_REF( __m128i a, __m128i b )                     
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MAX( A.s32[ 0], B.s32[ 0] );
    SSP_SET_MAX( A.s32[ 1], B.s32[ 1] );
    SSP_SET_MAX( A.s32[ 2], B.s32[ 2] );
    SSP_SET_MAX( A.s32[ 3], B.s32[ 3] );
    return A.i;
}

/** \SSE4_1{Reference,_mm_min_epu32} */
SSP_FORCEINLINE __m128i ssp_min_epu32_REF ( __m128i a, __m128i b )                    
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MIN( A.u32[ 0], B.u32[ 0] );
    SSP_SET_MIN( A.u32[ 1], B.u32[ 1] );
    SSP_SET_MIN( A.u32[ 2], B.u32[ 2] );
    SSP_SET_MIN( A.u32[ 3], B.u32[ 3] );
    return A.i;
}

/** \SSE4_1{Reference,_mm_max_epu32} */
SSP_FORCEINLINE __m128i ssp_max_epu32_REF ( __m128i a, __m128i b )                    
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    SSP_SET_MAX( A.u32[ 0], B.u32[ 0] );
    SSP_SET_MAX( A.u32[ 1], B.u32[ 1] );
    SSP_SET_MAX( A.u32[ 2], B.u32[ 2] );
    SSP_SET_MAX( A.u32[ 3], B.u32[ 3] );
    return A.i;
}

#undef SSP_SET_MIN
#undef SSP_SET_MAX

/** \SSE4_1{Reference,_mm_minpos_epu16} */
SSP_FORCEINLINE __m128i ssp_minpos_epu16_REF( __m128i shortValues )                   
{
    ssp_m128 ShortValues;
    ShortValues.i = shortValues;

    if( ShortValues.u16[1] < ShortValues.u16[0] )
    {
        ShortValues.u16[0] = ShortValues.u16[1];
        ShortValues.u16[1] = 1;
    }
    else
        ShortValues.u16[1] = 0;


#define FN( I )                                     \
    if( ShortValues.u16[I] < ShortValues.u16[0] )   \
    {                                               \
        ShortValues.u16[0] = ShortValues.u16[I];    \
        ShortValues.u16[1] = I;                     \
    }

    FN( 2 );
    FN( 3 );
    FN( 4 );
    FN( 5 );
    FN( 6 );
    FN( 7 );

    ShortValues.u32[1] = 0;
    ShortValues.u64[1] = 0;

#undef FN

    return ShortValues.i;
}

/** \SSE4_1{Reference,_mm_minpos_epu16} */
SSP_FORCEINLINE __m128i ssp_minpos_epu16_REFb( __m128i shortValues )                   
{
    ssp_m128 ShortValues;
    ssp_u32 i;
    ssp_u16 pos = 0;
    ssp_u16 minVal;
    ShortValues.i = shortValues;
    minVal = ShortValues.u16[0];

    for( i=1; i<8; ++i )
    {
        if( ShortValues.u16[i] < minVal )
        {
            minVal = ShortValues.u16[i];
            pos    = i;
        }

        ShortValues.u16[i] = 0;
    }

    ShortValues.u16[0] = minVal;
    ShortValues.u16[1] = pos;
    return ShortValues.i;
}


//---------------------------------------
// Move
//---------------------------------------
/** \SSE3{Reference,_mm_movehdup_ps} */
SSP_FORCEINLINE __m128 ssp_movehdup_ps_REF(__m128 a)                                   
{
    ssp_m128 A;
    A.f = a;

    A.f32[0] = A.f32[1];
    A.f32[2] = A.f32[3];
    return A.f;
}

/** \SSE3{Reference,_mm_moveldup_ps} */
SSP_FORCEINLINE __m128 ssp_moveldup_ps_REF(__m128 a)                                   
{
    ssp_m128 A;
    A.f = a;

    A.f32[1] = A.f32[0];
    A.f32[3] = A.f32[2];
    return A.f;
}

/** \SSE3{Reference,_mm_movedup_pd} */
SSP_FORCEINLINE __m128d ssp_movedup_pd_REF(__m128d a)                                  
{
    ssp_m128 A;
    A.d = a;

    A.f64[1] = A.f64[0];
    return A.d;
}

//---------------------------------------
// Multiply
//---------------------------------------
/** \SSE4_1{Reference,_mm_mul_epi32} */
SSP_FORCEINLINE __m128i ssp_mul_epi32_REF( __m128i a, __m128i b )                      
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    A.s64[0] = A.s32[0] * B.s32[0];
    A.s64[1] = A.s32[2] * B.s32[2];
    return A.i;
}

/** \SSE4_1{Reference,_mm_mullo_epi32} */
SSP_FORCEINLINE __m128i ssp_mullo_epi32_REF( __m128i a, __m128i b )                    
{
    ssp_m128 t[2];
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    t[0].s64[0] = A.s32[0] * B.s32[0];
    t[0].s64[1] = A.s32[1] * B.s32[1];
    t[1].s64[0] = A.s32[2] * B.s32[2];
    t[1].s64[1] = A.s32[3] * B.s32[3];    

    A.s32[0] = t[0].s32[0];
    A.s32[1] = t[0].s32[2];
    A.s32[2] = t[1].s32[0];
    A.s32[3] = t[1].s32[2];
    return A.i;
}

/** \SSE4_1{Reference,_mm_mpsadbw_epu8} */
SSP_FORCEINLINE __m128i ssp_mpsadbw_epu8_REF ( __m128i a,   __m128i b,   const int msk  ) 
{
	ssp_u8 Abyte[11], Bbyte[4], tmp[4];
	ssp_u8 Boffset, Aoffset;
	int i;

    ssp_m128 A,B;
    A.i = a;
    B.i = b;

	Boffset = (msk & 0x3) << 2; // *32/8,   for byte size count
	Aoffset = (msk & 0x4);      // *32/8/4, for byte size count and shift msk to bit 2

	for (i=0; i<11; i++)
	{
		Abyte[i] = A.u8[i+Aoffset];
	}
	
	Bbyte[0] = B.u8[Boffset  ];
	Bbyte[1] = B.u8[Boffset+1];
	Bbyte[2] = B.u8[Boffset+2];
	Bbyte[3] = B.u8[Boffset+3];

	for (i=0; i<8; i++)
	{
		tmp[0] = (Abyte[i  ] > Bbyte[0]) ? (Abyte[i  ] - Bbyte[0]) :  (Bbyte[0] - Abyte[i  ]);        //abs diff
		tmp[1] = (Abyte[i+1] > Bbyte[1]) ? (Abyte[i+1] - Bbyte[1]) :  (Bbyte[1] - Abyte[i+1]);
		tmp[2] = (Abyte[i+2] > Bbyte[2]) ? (Abyte[i+2] - Bbyte[2]) :  (Bbyte[2] - Abyte[i+2]);
		tmp[3] = (Abyte[i+3] > Bbyte[3]) ? (Abyte[i+3] - Bbyte[3]) :  (Bbyte[3] - Abyte[i+3]);

		A.u16[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
	}

	return A.i;
}

//---------------------------------------
// Pack
//---------------------------------------
/** \SSE4_1{Reference,_mm_packus_epi32} */
SSP_FORCEINLINE __m128i ssp_packus_epi32_REF( __m128i a, __m128i b )                       
{
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    if( A.s32[0] < 0 )
        A.u16[0] = 0;
    else
        if( A.s32[0] > 0xFFFF )
            A.u16[0] = 0xFFFF;
        else
            A.s16[0] = (ssp_u16)A.s32[0];

    if( A.s32[1] < 0 )
        A.u16[1] = 0;
    else
        if( A.s32[1] > 0xFFFF )
            A.u16[1] = 0xFFFF;
        else
            A.s16[1] = (ssp_u16)A.s32[1];

    if( A.s32[2] < 0 )
        A.u16[2] = 0;
    else
        if( A.s32[2] > 0xFFFF )
            A.u16[2] = 0xFFFF;
        else
            A.s16[2] = (ssp_u16)A.s32[2];


    if( A.s32[3] < 0 )
        A.u16[3] = 0;
    else
        if( A.s32[3] > 0xFFFF )
            A.u16[3] = 0xFFFF;
        else
            A.s16[3] = (ssp_u16)A.s32[3];

    if( B.s32[0] < 0 )
        A.u16[4] = 0;
    else
        if( B.s32[0] > 0xFFFF )
            A.u16[4] = 0xFFFF;
        else
            A.s16[4] = (ssp_u16)B.s32[0];

    if( B.s32[1] < 0 )
        A.u16[5] = 0;
    else
        if( B.s32[1] > 0xFFFF )
            A.u16[5] = 0xFFFF;
        else
            A.s16[5] = (ssp_u16)B.s32[1];

    if( B.s32[2] < 0 )
        A.u16[6] = 0;
    else
        if( B.s32[2] > 0xFFFF )
            A.u16[6] = 0xFFFF;
        else
            A.s16[6] = (ssp_u16)B.s32[2];


    if( B.s32[3] < 0 )
        A.u16[7] = 0;
    else
        if( B.s32[3] > 0xFFFF )
            A.u16[7] = 0xFFFF;
        else
            A.s16[7] = (ssp_u16)B.s32[3];

    return A.i;
}

//---------------------------------------
// Type Conversion
//---------------------------------------
/** \SSE4_1{Reference,_mm_cvtepi8_epi16} */
SSP_FORCEINLINE __m128i ssp_cvtepi8_epi16_REF ( __m128i a)                                  
{
    ssp_m128 A;
    A.i = a;

	A.s16[7] = A.s8[7];
	A.s16[6] = A.s8[6];
	A.s16[5] = A.s8[5];
	A.s16[4] = A.s8[4];
	A.s16[3] = A.s8[3];
	A.s16[2] = A.s8[2];
	A.s16[1] = A.s8[1];
	A.s16[0] = A.s8[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepi8_epi32} */
SSP_FORCEINLINE __m128i ssp_cvtepi8_epi32_REF ( __m128i a)                                  
{
    ssp_m128 A;
    A.i = a;

	A.s32[3] = A.s8[3];
	A.s32[2] = A.s8[2];
	A.s32[1] = A.s8[1];
	A.s32[0] = A.s8[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepi8_epi64} */
SSP_FORCEINLINE __m128i ssp_cvtepi8_epi64_REF ( __m128i a)                                  
{
    ssp_m128 A;
    A.i = a;

	A.s64[1] = A.s8[1];
	A.s64[0] = A.s8[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepi16_epi32} */
SSP_FORCEINLINE __m128i ssp_cvtepi16_epi32_REF ( __m128i a)                                 
{
    ssp_m128 A;
    A.i = a;

	A.s32[3] = A.s16[3];
	A.s32[2] = A.s16[2];
	A.s32[1] = A.s16[1];
	A.s32[0] = A.s16[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepi16_epi64} */
SSP_FORCEINLINE __m128i ssp_cvtepi16_epi64_REF ( __m128i a)                                 
{
    ssp_m128 A;
    A.i = a;

	A.s64[1] = A.s16[1];
	A.s64[0] = A.s16[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepi32_epi64} */
SSP_FORCEINLINE __m128i ssp_cvtepi32_epi64_REF ( __m128i a)                                 
{
    ssp_m128 A;
    A.i = a;

	A.s64[1] = A.s32[1];
    A.s64[0] = A.s32[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepu8_epi16} */
SSP_FORCEINLINE __m128i ssp_cvtepu8_epi16_REF ( __m128i a)                                  
{
    ssp_m128 A;
    A.i = a;

	A.s16[7] = A.u8[7];
	A.s16[6] = A.u8[6];
	A.s16[5] = A.u8[5];
	A.s16[4] = A.u8[4];
	A.s16[3] = A.u8[3];
	A.s16[2] = A.u8[2];
	A.s16[1] = A.u8[1];
	A.s16[0] = A.u8[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepu8_epi32} */
SSP_FORCEINLINE __m128i ssp_cvtepu8_epi32_REF ( __m128i a)                                  
{
    ssp_m128 A;
    A.i = a;

	A.s32[3] = A.u8[3];
	A.s32[2] = A.u8[2];
	A.s32[1] = A.u8[1];
	A.s32[0] = A.u8[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepu8_epi64} */
SSP_FORCEINLINE __m128i ssp_cvtepu8_epi64_REF ( __m128i a)                                  
{
    ssp_m128 A;
    A.i = a;

	A.s64[1] = A.u8[1];
	A.s64[0] = A.u8[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepu16_epi32} */
SSP_FORCEINLINE __m128i ssp_cvtepu16_epi32_REF ( __m128i a)                                 
{
    ssp_m128 A;
    A.i = a;

	A.s32[3] = A.u16[3];
	A.s32[2] = A.u16[2];
	A.s32[1] = A.u16[1];
	A.s32[0] = A.u16[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepu16_epi64} */
SSP_FORCEINLINE __m128i ssp_cvtepu16_epi64_REF ( __m128i a)                                 
{
    ssp_m128 A;
    A.i = a;

	A.s64[1] = A.u16[1];
	A.s64[0] = A.u16[0];
	return A.i;
}

/** \SSE4_1{Reference,_mm_cvtepu32_epi64} */
SSP_FORCEINLINE __m128i ssp_cvtepu32_epi64_REF ( __m128i a)                                 
{
    ssp_m128 A;
    A.i = a;

	A.s64[1] = A.u32[1];
	A.s64[0] = A.u32[0];
	return A.i;
}

//SSSE3
//__m128i _mm_abs_epi8(__m128i a);
/** \SSSE3{Reference,_mm_abs_epi8} */
SSP_FORCEINLINE __m128i ssp_abs_epi8_REF (__m128i a)
{
    ssp_m128 A;
    A.i = a;

	A.s8[0]  = (A.s8[0] < 0) ? -A.s8[0]  : A.s8[0];
	A.s8[1]  = (A.s8[1] < 0) ? -A.s8[1]  : A.s8[1];
	A.s8[2]  = (A.s8[2] < 0) ? -A.s8[2]  : A.s8[2];
	A.s8[3]  = (A.s8[3] < 0) ? -A.s8[3]  : A.s8[3];
	A.s8[4]  = (A.s8[4] < 0) ? -A.s8[4]  : A.s8[4];
	A.s8[5]  = (A.s8[5] < 0) ? -A.s8[5]  : A.s8[5];
	A.s8[6]  = (A.s8[6] < 0) ? -A.s8[6]  : A.s8[6];
	A.s8[7]  = (A.s8[7] < 0) ? -A.s8[7]  : A.s8[7];
	A.s8[8]  = (A.s8[8] < 0) ? -A.s8[8]  : A.s8[8];
	A.s8[9]  = (A.s8[9] < 0) ? -A.s8[9]  : A.s8[9];
	A.s8[10] = (A.s8[10]< 0) ? -A.s8[10] : A.s8[10];
	A.s8[11] = (A.s8[11]< 0) ? -A.s8[11] : A.s8[11];
	A.s8[12] = (A.s8[12]< 0) ? -A.s8[12] : A.s8[12];
	A.s8[13] = (A.s8[13]< 0) ? -A.s8[13] : A.s8[13];
	A.s8[14] = (A.s8[14]< 0) ? -A.s8[14] : A.s8[14];
	A.s8[15] = (A.s8[15]< 0) ? -A.s8[15] : A.s8[15];

	return A.i;
}

//__m128i _mm_abs_epi16(__m128i a);
/** \SSSE3{Reference,_mm_abs_epi16} */
SSP_FORCEINLINE __m128i ssp_abs_epi16_REF (__m128i a)
{
    ssp_m128 A;
    A.i = a;

	A.s16[0]  = (A.s16[0] < 0) ? -A.s16[0]  : A.s16[0];
	A.s16[1]  = (A.s16[1] < 0) ? -A.s16[1]  : A.s16[1];
	A.s16[2]  = (A.s16[2] < 0) ? -A.s16[2]  : A.s16[2];
	A.s16[3]  = (A.s16[3] < 0) ? -A.s16[3]  : A.s16[3];
	A.s16[4]  = (A.s16[4] < 0) ? -A.s16[4]  : A.s16[4];
	A.s16[5]  = (A.s16[5] < 0) ? -A.s16[5]  : A.s16[5];
	A.s16[6]  = (A.s16[6] < 0) ? -A.s16[6]  : A.s16[6];
	A.s16[7]  = (A.s16[7] < 0) ? -A.s16[7]  : A.s16[7];

	return A.i;
}

/**  \SSSE3{Reference,_mm_abs_epi32} */
SSP_FORCEINLINE __m128i ssp_abs_epi32_REF (__m128i a)
{
    ssp_m128 A;
    A.i = a;

	A.s32[0]  = (A.s32[0] < 0) ? -A.s32[0]  : A.s32[0];
	A.s32[1]  = (A.s32[1] < 0) ? -A.s32[1]  : A.s32[1];
	A.s32[2]  = (A.s32[2] < 0) ? -A.s32[2]  : A.s32[2];
	A.s32[3]  = (A.s32[3] < 0) ? -A.s32[3]  : A.s32[3];

	return A.i;
}

/** \SSSE3{Reference,_mm_abs_pi8}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
 */
SSP_FORCEINLINE __m64 ssp_abs_pi8_REF (__m64 a)
{
    ssp_m64 A;
    A.m64 = a;

	A.s8[0]  = (A.s8[0] < 0) ? -A.s8[0]  : A.s8[0];
	A.s8[1]  = (A.s8[1] < 0) ? -A.s8[1]  : A.s8[1];
	A.s8[2]  = (A.s8[2] < 0) ? -A.s8[2]  : A.s8[2];
	A.s8[3]  = (A.s8[3] < 0) ? -A.s8[3]  : A.s8[3];
	A.s8[4]  = (A.s8[4] < 0) ? -A.s8[4]  : A.s8[4];
	A.s8[5]  = (A.s8[5] < 0) ? -A.s8[5]  : A.s8[5];
	A.s8[6]  = (A.s8[6] < 0) ? -A.s8[6]  : A.s8[6];
	A.s8[7]  = (A.s8[7] < 0) ? -A.s8[7]  : A.s8[7];

	return A.m64;
}

//__m64 _mm_abs_pi16( __m64 a);
/** \SSSE3{Reference,_mm_abs_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_abs_pi16_REF (__m64 a)
{
    ssp_m64 A;
    A.m64 = a;

	A.s16[0]  = (A.s16[0] < 0) ? -A.s16[0]  : A.s16[0];
	A.s16[1]  = (A.s16[1] < 0) ? -A.s16[1]  : A.s16[1];
	A.s16[2]  = (A.s16[2] < 0) ? -A.s16[2]  : A.s16[2];
	A.s16[3]  = (A.s16[3] < 0) ? -A.s16[3]  : A.s16[3];

	return A.m64;
}

//__m64 _mm_abs_pi32( __m64 a);
/** \SSSE3{Reference,_mm_abs_pi32}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_abs_pi32_REF (__m64 a)
{
    ssp_m64 A;
    A.m64 = a;

	A.s32[0]  = (A.s32[0] < 0) ? -A.s32[0]  : A.s32[0];
	A.s32[1]  = (A.s32[1] < 0) ? -A.s32[1]  : A.s32[1];

	return A.m64;
}

// bit manipulation
//__m128i _mm_alignr_epi8(__m128i a, __m128i b, const int ralign);
/**  \SSSE3{Reference,_mm_alignr_epi8} */
SSP_FORCEINLINE __m128i ssp_alignr_epi8_REF (__m128i a, __m128i b, const int ralign)
{
    ssp_m128 C[3];
	ssp_s8 * tmp;
	int i, j;

	if (ralign <0) return b; //only shift to right, no negative
	C[2].i = _mm_setzero_si128();
	if (ralign > 32) return C[2].i;
    C[1].i = a;
	C[0].i = b;
	tmp = & (C[0].s8[0]);

	for (i=ralign+15, j=15; i >=ralign; i--, j--) {
		C[2].s8[j] = tmp[i];
	}

	return C[2].i;
}

/**  \SSSE3{Reference,_mm_alignr_pi8}
 \n \b NOTE: The user must call _mm_empty() after a call to this function.
 */
SSP_FORCEINLINE __m64 ssp_alignr_pi8_REF (__m64 a, __m64 b, const int ralign)
{
    ssp_m64 C[3];
    ssp_s8 * tmp;
    int i, j;
    
    if (ralign <0) return b; //only shift to right, no negative
    C[2].u32[0] = 0;
    C[2].u32[1] = 0;
    if (ralign > 16) return C[2].m64;
    C[1].m64 = a;
    C[0].m64 = b;
    tmp = & (C[0].s8[0]);
    
    for (i=ralign+7, j=7; i >=ralign; i--, j--) {
        C[2].s8[j] = tmp[i];
    }
    
    return C[2].m64;
}

//__m128i _mm_shuffle_epi8( __m128i a, __m128i mask);
/**  \SSSE3{Reference,_mm_shuffle_epi8} */
SSP_FORCEINLINE __m128i ssp_shuffle_epi8_REF (__m128i a, __m128i mask)
{
    ssp_m128 A, MSK, B;
	A.i = a;
	MSK.i = mask;

	B.s8[0]  = (MSK.s8[0]  & 0x80) ? 0 : A.s8[(MSK.s8[0]  & 0xf)];
	B.s8[1]  = (MSK.s8[1]  & 0x80) ? 0 : A.s8[(MSK.s8[1]  & 0xf)];
	B.s8[2]  = (MSK.s8[2]  & 0x80) ? 0 : A.s8[(MSK.s8[2]  & 0xf)];
	B.s8[3]  = (MSK.s8[3]  & 0x80) ? 0 : A.s8[(MSK.s8[3]  & 0xf)];
	B.s8[4]  = (MSK.s8[4]  & 0x80) ? 0 : A.s8[(MSK.s8[4]  & 0xf)];
	B.s8[5]  = (MSK.s8[5]  & 0x80) ? 0 : A.s8[(MSK.s8[5]  & 0xf)];
	B.s8[6]  = (MSK.s8[6]  & 0x80) ? 0 : A.s8[(MSK.s8[6]  & 0xf)];
	B.s8[7]  = (MSK.s8[7]  & 0x80) ? 0 : A.s8[(MSK.s8[7]  & 0xf)];
	B.s8[8]  = (MSK.s8[8]  & 0x80) ? 0 : A.s8[(MSK.s8[8]  & 0xf)];
	B.s8[9]  = (MSK.s8[9]  & 0x80) ? 0 : A.s8[(MSK.s8[9]  & 0xf)];
	B.s8[10] = (MSK.s8[10] & 0x80) ? 0 : A.s8[(MSK.s8[10] & 0xf)];
	B.s8[11] = (MSK.s8[11] & 0x80) ? 0 : A.s8[(MSK.s8[11] & 0xf)];
	B.s8[12] = (MSK.s8[12] & 0x80) ? 0 : A.s8[(MSK.s8[12] & 0xf)];
	B.s8[13] = (MSK.s8[13] & 0x80) ? 0 : A.s8[(MSK.s8[13] & 0xf)];
	B.s8[14] = (MSK.s8[14] & 0x80) ? 0 : A.s8[(MSK.s8[14] & 0xf)];
	B.s8[15] = (MSK.s8[15] & 0x80) ? 0 : A.s8[(MSK.s8[15] & 0xf)];

	return B.i;
}

/**  \SSSE3{Reference,_mm_shuffle_pi8}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_shuffle_pi8_REF (__m64 a, __m64 mask)
{
    ssp_m64 A, MSK, B;
	A.m64 = a;
	MSK.m64 = mask;

	B.s8[0]  = (MSK.s8[0]  & 0x80) ? 0 : A.s8[(MSK.s8[0]  & 0x7)];
	B.s8[1]  = (MSK.s8[1]  & 0x80) ? 0 : A.s8[(MSK.s8[1]  & 0x7)];
	B.s8[2]  = (MSK.s8[2]  & 0x80) ? 0 : A.s8[(MSK.s8[2]  & 0x7)];
	B.s8[3]  = (MSK.s8[3]  & 0x80) ? 0 : A.s8[(MSK.s8[3]  & 0x7)];
	B.s8[4]  = (MSK.s8[4]  & 0x80) ? 0 : A.s8[(MSK.s8[4]  & 0x7)];
	B.s8[5]  = (MSK.s8[5]  & 0x80) ? 0 : A.s8[(MSK.s8[5]  & 0x7)];
	B.s8[6]  = (MSK.s8[6]  & 0x80) ? 0 : A.s8[(MSK.s8[6]  & 0x7)];
	B.s8[7]  = (MSK.s8[7]  & 0x80) ? 0 : A.s8[(MSK.s8[7]  & 0x7)];

	return B.m64;
}

//__m64 _mm_sign_pi8( __m64 a, __m64 b);
/**  \SSSE3{Reference,_mm_sign_pi8} */
/** AnV - Compile fix **/
SSP_FORCEINLINE __m64 ssp_sign_pi8_REF (__m64 a, __m64 b)
{
    ssp_m64 A, B;
    A.m64 = a;
    B.m64 = b;
    
    A.s8[0]  = (B.s8[0]<0)  ? (-A.s8[0])  :((B.s8[0]==0) ? 0: A.s8[0]);
    A.s8[1]  = (B.s8[1]<0)  ? (-A.s8[1])  :((B.s8[1]==0) ? 0: A.s8[1]);
    A.s8[2]  = (B.s8[2]<0)  ? (-A.s8[2])  :((B.s8[2]==0) ? 0: A.s8[2]);
    A.s8[3]  = (B.s8[3]<0)  ? (-A.s8[3])  :((B.s8[3]==0) ? 0: A.s8[3]);
    A.s8[4]  = (B.s8[4]<0)  ? (-A.s8[4])  :((B.s8[4]==0) ? 0: A.s8[4]);
    A.s8[5]  = (B.s8[5]<0)  ? (-A.s8[5])  :((B.s8[5]==0) ? 0: A.s8[5]);
    A.s8[6]  = (B.s8[6]<0)  ? (-A.s8[6])  :((B.s8[6]==0) ? 0: A.s8[6]);
    A.s8[7]  = (B.s8[7]<0)  ? (-A.s8[7])  :((B.s8[7]==0) ? 0: A.s8[7]);
    
    return A.m64;
}

//Negate the number
//__m128i _mm_sign_epi8( __m128i a, __m128i b);
/**  \SSSE3{Reference,_mm_sign_epi8} */
SSP_FORCEINLINE __m128i ssp_sign_epi8_REF (__m128i a, __m128i b)
{
    ssp_m128 A, B;
	A.i = a;
	B.i = b;

	A.s8[0]  = (B.s8[0]<0)  ? (-A.s8[0])  :((B.s8[0]==0) ? 0: A.s8[0]);
	A.s8[1]  = (B.s8[1]<0)  ? (-A.s8[1])  :((B.s8[1]==0) ? 0: A.s8[1]);
	A.s8[2]  = (B.s8[2]<0)  ? (-A.s8[2])  :((B.s8[2]==0) ? 0: A.s8[2]);
	A.s8[3]  = (B.s8[3]<0)  ? (-A.s8[3])  :((B.s8[3]==0) ? 0: A.s8[3]);
	A.s8[4]  = (B.s8[4]<0)  ? (-A.s8[4])  :((B.s8[4]==0) ? 0: A.s8[4]);
	A.s8[5]  = (B.s8[5]<0)  ? (-A.s8[5])  :((B.s8[5]==0) ? 0: A.s8[5]);
	A.s8[6]  = (B.s8[6]<0)  ? (-A.s8[6])  :((B.s8[6]==0) ? 0: A.s8[6]);
	A.s8[7]  = (B.s8[7]<0)  ? (-A.s8[7])  :((B.s8[7]==0) ? 0: A.s8[7]);
	A.s8[8]  = (B.s8[8]<0)  ? (-A.s8[8])  :((B.s8[8]==0) ? 0: A.s8[8]);
	A.s8[9]  = (B.s8[9]<0)  ? (-A.s8[9])  :((B.s8[9]==0) ? 0: A.s8[9]);
	A.s8[10] = (B.s8[10]<0) ? (-A.s8[10]) :((B.s8[10]==0)? 0: A.s8[10]);
	A.s8[11] = (B.s8[11]<0) ? (-A.s8[11]) :((B.s8[11]==0)? 0: A.s8[11]);
	A.s8[12] = (B.s8[12]<0) ? (-A.s8[12]) :((B.s8[12]==0)? 0: A.s8[12]);
	A.s8[13] = (B.s8[13]<0) ? (-A.s8[13]) :((B.s8[13]==0)? 0: A.s8[13]);
	A.s8[14] = (B.s8[14]<0) ? (-A.s8[14]) :((B.s8[14]==0)? 0: A.s8[14]);
	A.s8[15] = (B.s8[15]<0) ? (-A.s8[15]) :((B.s8[15]==0)? 0: A.s8[15]);

	return A.i;
}

//__m128i _mm_sign_epi16( __m128i a, __m128i b);
/**  \SSSE3{Reference,_mm_sign_epi16} */
SSP_FORCEINLINE __m128i ssp_sign_epi16_REF (__m128i a, __m128i b)
{
    ssp_m128 A, B;
	A.i = a;
	B.i = b;

	A.s16[0]  = (B.s16[0]<0)  ? (-A.s16[0])  :((B.s16[0]==0) ? 0: A.s16[0]);
	A.s16[1]  = (B.s16[1]<0)  ? (-A.s16[1])  :((B.s16[1]==0) ? 0: A.s16[1]);
	A.s16[2]  = (B.s16[2]<0)  ? (-A.s16[2])  :((B.s16[2]==0) ? 0: A.s16[2]);
	A.s16[3]  = (B.s16[3]<0)  ? (-A.s16[3])  :((B.s16[3]==0) ? 0: A.s16[3]);
	A.s16[4]  = (B.s16[4]<0)  ? (-A.s16[4])  :((B.s16[4]==0) ? 0: A.s16[4]);
	A.s16[5]  = (B.s16[5]<0)  ? (-A.s16[5])  :((B.s16[5]==0) ? 0: A.s16[5]);
	A.s16[6]  = (B.s16[6]<0)  ? (-A.s16[6])  :((B.s16[6]==0) ? 0: A.s16[6]);
	A.s16[7]  = (B.s16[7]<0)  ? (-A.s16[7])  :((B.s16[7]==0) ? 0: A.s16[7]);

	return A.i;
}

//__m128i _mm_sign_epi32( __m128i a, __m128i b);
/**  \SSSE3{Reference,_mm_sign_epi32} */
SSP_FORCEINLINE __m128i ssp_sign_epi32_REF (__m128i a, __m128i b)
{
    ssp_m128 A, B;
	A.i = a;
	B.i = b;

	A.s32[0]  = (B.s32[0]<0)  ? (-A.s32[0])  :((B.s32[0]==0) ? 0: A.s32[0]);
	A.s32[1]  = (B.s32[1]<0)  ? (-A.s32[1])  :((B.s32[1]==0) ? 0: A.s32[1]);
	A.s32[2]  = (B.s32[2]<0)  ? (-A.s32[2])  :((B.s32[2]==0) ? 0: A.s32[2]);
	A.s32[3]  = (B.s32[3]<0)  ? (-A.s32[3])  :((B.s32[3]==0) ? 0: A.s32[3]);

	return A.i;
}

//__m64 _mm_sign_pi16( __m64 a, __m64 b);
/**  \SSSE3{Reference,_mm_sign_pi16}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_sign_pi16_REF (__m64 a, __m64 b)
{
    ssp_m64 A, B;
	A.m64 = a;
	B.m64 = b;

	A.s16[0]  = (B.s16[0]<0)  ? (-A.s16[0])  :((B.s16[0]==0) ? 0: A.s16[0]);
	A.s16[1]  = (B.s16[1]<0)  ? (-A.s16[1])  :((B.s16[1]==0) ? 0: A.s16[1]);
	A.s16[2]  = (B.s16[2]<0)  ? (-A.s16[2])  :((B.s16[2]==0) ? 0: A.s16[2]);
	A.s16[3]  = (B.s16[3]<0)  ? (-A.s16[3])  :((B.s16[3]==0) ? 0: A.s16[3]);

	return A.m64;
}

//__m64 _mm_sign_pi32( __m64 a, __m64 b);
/**  \SSSE3{Reference,_mm_sign_pi32}
\n \b NOTE: The user must call _mm_empty() after a call to this function.
*/
SSP_FORCEINLINE __m64 ssp_sign_pi32_REF (__m64 a, __m64 b)
{
    ssp_m64 A, B;
	A.m64 = a;
	B.m64 = b;

	A.s32[0]  = (B.s32[0]<0)  ? (-A.s32[0])  :((B.s32[0]==0) ? 0: A.s32[0]);
	A.s32[1]  = (B.s32[1]<0)  ? (-A.s32[1])  :((B.s32[1]==0) ? 0: A.s32[1]);

	return A.m64;
}

/** \SSE4a{Reference,_mm_stream_sd} */ 
SSP_FORCEINLINE void ssp_stream_sd_REF( double *dst ,__m128d src )
{
    ssp_m128 SRC;
    SRC.d = src;
    *dst = SRC.f64[0];
}

/** \SSE4a{Reference,_mm_stream_ss} */ 
SSP_FORCEINLINE void ssp_stream_ss_REF( float *dst, __m128 src )
{
    ssp_m128 SRC;
    SRC.f = src;
    *dst = SRC.f32[0];
}

//---------------------------------------
// Leading Zeros Count
//---------------------------------------
/** \SSE4a{Reference,__lzcnt16} */ 
SSP_FORCEINLINE unsigned short ssp_lzcnt16_REF( unsigned short val )
{
    
    if( !val )
        return 16;
    // Binary Search Tree of possible output values
    else if( val > 0x00FF )
    {
        if( val > 0x0FFF )
        {
            if( val > 0x3FFF )
            {
                if( val > 0x7FFF )
                    return 0;
                else
                    return 1;
            }
            else // val < 0x3FFF
            {
                if( val > 0x1FFF )
                    return 2;
                else
                    return 3;
            }
        }
        else // val < 0x0FFF
        {
            if( val > 0x03FF )
            {
                if( val > 0x07FF )
                    return 4;
                else
                    return 5;
            }
            else // val < 0x03FF
            {
                if( val > 0x01FF )
                    return 6;
                else
                    return 7;
            }
        }
    }
    else // val < 0x00FF
    {
        if( val > 0x000F )
        {
            if( val > 0x003F  )
            {
                if( val > 0x007F  )
                    return 8;
                else
                    return 9;
            }
            else // val < 0x003F
            {
                if( val > 0x001F)
                    return 10;
                else
                    return 11;
            }
        }
        else // val < 0x000F
        {
            if( val > 0x0003  )
            {
                if( val > 0x0007  )
                    return 12;
                else
                    return 13;
            }
            else // val < 0x0003
            {
                if( val > 0x0001)
                    return 14;
                else
                    return 15;
            }
        }
    }
}
/** \SSE4a{Reference,__lzcnt} */ 
SSP_FORCEINLINE unsigned int ssp_lzcnt_REF( unsigned int val )
{
    ssp_u32 cnt;
    cnt = ssp_lzcnt16_REF( (ssp_u16)(val>>16) );
    if( cnt == 16 )
        cnt += ssp_lzcnt16_REF( (ssp_u16)(val & 0x0000FFFF) );
    return cnt;
}
/** \SSE4a{Reference,__lzcnt64} */ 
SSP_FORCEINLINE ssp_u64 ssp_lzcnt64_REF( ssp_u64 val )
{
    ssp_u64 cnt;
    cnt = ssp_lzcnt_REF( (ssp_u32)(val>>32) );
    if( cnt == 32 )
        cnt += ssp_lzcnt_REF( (ssp_u32)(val & 0x00000000FFFFFFFF) );
    return cnt;
}

//---------------------------------------
// Population Count
//---------------------------------------
/** \SSE4a{Native,__popcnt16} */ 
SSP_FORCEINLINE unsigned short ssp_popcnt16_REF( unsigned short val )
{
    int i = 0;
    ssp_u16 cnt = 0;

    while ((i < 16) && (val))
    {
	if (val & 0x1)
	{
		++cnt;
	}

        ++i;
        val >>= 1;
    }
    
    return cnt;
}
/** \SSE4a{Native,__popcnt} */ 
SSP_FORCEINLINE unsigned int ssp_popcnt_REF( unsigned int val )
{
    int i = 0;
    ssp_u32 cnt = 0;

    while ((i < 32) && (val))
    {
	if (val & 0x1)
	{
		++cnt;
	}

        ++i;
        val >>= 1;
    }

    return cnt;
}
/** \SSE4a{Native,__popcnt64} */ 
SSP_FORCEINLINE ssp_u64 ssp_popcnt64_REF( ssp_u64 val )
{
    int i = 0;
    ssp_u64 cnt = 0;

    while ((i < 64) && (val))
    {
	if (val & 0x1)
	{
		++cnt;
	}

        ++i;
        val >>= 1;
    }

    return cnt;
}

//--------------------------------------
// Packed permute
//--------------------------------------

/** \SSE5{Reference,_mm_perm_epi8, pperm } */
SSP_FORCEINLINE __m128i ssp_perm_epi8_REF(__m128i a, __m128i b, __m128i c)
{
    int n;
    ssp_m128 A,B,C,R;
    A.i = a;
    B.i = b;
    C.i = c;

    for( n = 0; n < 16; n++ )
    {
        int op = C.u8[n] >> 5;
        switch( op )
        {
        case 0: // source byte (no logical opeartion)
            R.u8[n] = ( C.u8[n] & 0x10 ) ? ( B.u8[C.u8[n] & 0xF] ) : ( A.u8[C.u8[n] & 0xF] );
            break;
        case 1: // invert source byte
            {
                ssp_u8 src = ( C.u8[n] & 0x10 ) ? ( B.u8[C.u8[n] & 0xF] ) : ( A.u8[C.u8[n] & 0xF] );
                R.u8[n] = ~src;
            }
            break;
        case 2: // bit reverse of source byte
            {
                ssp_u8 src = ( C.u8[n] & 0x10 ) ? ( B.u8[C.u8[n] & 0xF] ) : ( A.u8[C.u8[n] & 0xF] );
                R.u8[n] = ( (src & 0x0F) << 4 ) | ( (src & 0xF0) >> 4 );
                R.u8[n] = ( (R.u8[n] & 0x33) << 2 ) | ( (R.u8[n] & 0xCC) >> 2 );
                R.u8[n] = ( (R.u8[n] & 0x55) << 1 ) | ( (R.u8[n] & 0xAA) >> 1 );
            }
            break;
        case 3: // bit reverse of inverted source byte
            {
                ssp_u8 src = ( C.u8[n] & 0x10 ) ? ( B.u8[C.u8[n] & 0xF] ) : ( A.u8[C.u8[n] & 0xF] );
                R.u8[n] = ( (src & 0x0F) << 4 ) | ( (src & 0xF0) >> 4 );
                R.u8[n] = ( (R.u8[n] & 0x33) << 2 ) | ( (R.u8[n] & 0xCC) >> 2 );
                R.u8[n] = ( (R.u8[n] & 0x55) << 1 ) | ( (R.u8[n] & 0xAA) >> 1 );
                R.u8[n] = ~R.u8[n];
            }
            break;
        case 4: // 0x00
            R.u8[n] = 0x00;
            break;
        case 5: // 0xFF
            R.u8[n] = 0xFF;
            break;
        case 6: // most significant bit of source byte replicated in all bit positions
            {
                ssp_s8 src = ( C.u8[n] & 0x10 ) ? ( B.s8[C.u8[n] & 0xF] ) : ( A.s8[C.u8[n] & 0xF] );
                R.s8[n] = src >> 7;
            }
            break;
        case 7: // invert most significant bit of source byte and replicate in all bit positions
            {
                ssp_s8 src = ( C.u8[n] & 0x10 ) ? ( B.s8[C.u8[n] & 0xF] ) : ( A.s8[C.u8[n] & 0xF] );
                R.s8[n] = src >> 7;
                R.u8[n] = ~R.u8[n];
            }
            break;
        }
    }
    return R.i;
}
/** \SSE5{Reference,_mm_perm_ps,		 permps } */
SSP_FORCEINLINE __m128 ssp_perm_ps_REF(__m128 a, __m128 b, __m128i c)
{
    int n;
    ssp_m128 A,B,C,R;
    A.f = a;
    B.f = b;
    C.i = c;

    for( n = 0; n < 4; n++ )
    {
        unsigned char cb = C.u8[n*4];
        int op = (cb >> 5) & 0x7;
        switch( op )
        {
        case 0: // single-precision source operand
            R.f32[n] = ( cb & 0x04 ) ? ( B.f32[cb & 0x03] ) : ( A.f32[cb & 0x03] );
            break;
        case 1: // absolute value of single-precision source operand
            {
                ssp_f32 src = ( cb & 0x04 ) ? ( B.f32[cb & 0x03] ) : ( A.f32[cb & 0x03] );
                R.f32[n] = ( src < 0.0f ) ? (-src) : src;
            }
            break;
        case 2: // negative value of single-precision source operand
            {
                ssp_f32 src = ( cb & 0x04 ) ? ( B.f32[cb & 0x03] ) : ( A.f32[cb & 0x03] );
                R.f32[n] = -src;
            }
            break;
        case 3: // negative of absolute value of single-precision source operand
            {
                ssp_f32 src = ( cb & 0x04 ) ? ( B.f32[cb & 0x03] ) : ( A.f32[cb & 0x03] );
                R.f32[n] = ( src < 0.0f ) ? src : (-src);
            }
            break;
        case 4: // +0.0
            R.f32[n] = 0.0f;
            break;
        case 5: // -1.0
            R.f32[n] = -1.0f;
            break;
        case 6: // +1.0
            R.f32[n] = 1.0f;
            break;
        case 7: // +0.0
            R.u32[n] = 0x40490FDB; //(for mxcsr.rc 00 or 10 use 0x40490FDB, for 01 or 11 use 0x40490FDA)
            break;
        }
    }
    return R.f;
}
/** \SSE5{Reference,_mm_perm_pd,		 permpd } */
SSP_FORCEINLINE __m128d ssp_perm_pd_REF(__m128d a, __m128d b, __m128i c)
{
    int n;
    ssp_m128 A,B,C,R;
    A.d = a;
    B.d = b;
    C.i = c;

    for( n = 0; n < 2; n++ )
    {
        unsigned char cb = C.u8[n*8];
        int op = (cb >> 5) & 0x7;
        switch( op )
        {
        case 0: // single-precision source operand
            R.f64[n] = ( cb & 0x02 ) ? ( B.f64[cb & 0x01] ) : ( A.f64[cb & 0x01] );
            break;
        case 1: // absolute value of single-precision source operand
            {
                ssp_f64 src = ( cb & 0x02 ) ? ( B.f64[cb & 0x01] ) : ( A.f64[cb & 0x01] );
                R.f64[n] = ( src < 0.0 ) ? (-src) : src;
            }
            break;
        case 2: // negative value of single-precision source operand
            {
                ssp_f64 src = ( cb & 0x02 ) ? ( B.f64[cb & 0x01] ) : ( A.f64[cb & 0x01] );
                R.f64[n] = -src;
            }
            break;
        case 3: // negative of absolute value of single-precision source operand
            {
                ssp_f64 src = ( cb & 0x02 ) ? ( B.f64[cb & 0x01] ) : ( A.f64[cb & 0x01] );
                R.f64[n] = ( src < 0.0 ) ? src : (-src);
            }
            break;
        case 4: // +0.0
            R.f64[n] = 0.0;
            break;
        case 5: // -1.0
            R.f64[n] = -1.0;
            break;
        case 6: // +1.0
            R.f64[n] = 1.0;
            break;
        case 7: // +0.0
            R.u64[n] = 0x400921FB54442D18; //(for mxcsr.rc 00, 01 or 11 use 0x400921FB54442D18, for 10 use 0x400921FB54442D19)
            break;
        }
    }
    return R.d;
}

//--------------------------------------
// conditional move
//--------------------------------------

/** \SSE5{Reference,_mm_cmov_si128, pcmov } */
SSP_FORCEINLINE __m128i ssp_cmov_si128_REF(__m128i a, __m128i b, __m128i c)
{
    int n;
    ssp_m128 A,B,C;
    A.i = a;
    B.i = b;
    C.i = c;

    for( n = 0; n < 4; n++ )
    {
        A.u32[n] &= C.u32[n];
        C.u32[n] = ~C.u32[n];
        B.u32[n] &= C.u32[n];
        A.u32[n] |= B.u32[n];
    }

    return A.i;
}

//--------------------------------------
// Packed rotates
//--------------------------------------

/** \SSE5{Reference,_mm_rot_epi8,		 protb } */
SSP_FORCEINLINE __m128i ssp_rot_epi8_REF(__m128i a, __m128i b  )
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 16; n++ )
    {
      if( B.s8[n] < 0 )
      {
        unsigned int count = (-B.s8[n]) % 8;
        unsigned int carry_count = (8 - count) % 8;
        ssp_u8 carry = A.u8[n] << carry_count;
        A.u8[n] = A.u8[n] >> count;
        A.u8[n] = A.u8[n] | carry;
      }
      else
      {
        unsigned int count = B.s8[n] % 8;
        unsigned int carry_count = (8 - count) % 8;
        ssp_u8 carry = A.u8[n] >> carry_count;
        A.u8[n] = A.u8[n] << count;
        A.u8[n] = A.u8[n] | carry;
      }
    }
    return A.i;
}
/** \SSE5{Reference,_mm_rot_epi16,	 protw } */
SSP_FORCEINLINE __m128i ssp_rot_epi16_REF(__m128i a, __m128i b  )
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 8; n++ )
    {
      if( B.s16[n] < 0 )
      {
        unsigned int count = (-B.s16[n]) % 16;
        unsigned int carry_count = (16 - count) % 16;
        ssp_u16 carry = A.u16[n] << carry_count;
        A.u16[n] = A.u16[n] >> count;
        A.u16[n] = A.u16[n] | carry;
      }
      else
      {
        unsigned int count = B.s16[n] % 8;
        unsigned int carry_count = (16 - count) % 16;
        ssp_u16 carry = A.u16[n] >> carry_count;
        A.u16[n] = A.u16[n] << count;
        A.u16[n] = A.u16[n] | carry;
      }
    }
    return A.i;
}
/** \SSE5{Reference,_mm_rot_epi32,	 protd } */
SSP_FORCEINLINE __m128i ssp_rot_epi32_REF(__m128i a, __m128i b  )
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 4; n++ )
    {
      if( B.s32[n] < 0 )
      {
        unsigned int count = (-B.s32[n]) % 32;
        unsigned int carry_count = (32 - count) % 32;
        ssp_u32 carry = A.u32[n] << carry_count;
        A.u32[n] = A.u32[n] >> count;
        A.u32[n] = A.u32[n] | carry;
      }
      else
      {
        unsigned int count = B.s32[n] % 32;
        unsigned int carry_count = (32 - count) % 32;
        ssp_u32 carry = A.u32[n] >> carry_count;
        A.u32[n] = A.u32[n] << count;
        A.u32[n] = A.u32[n] | carry;
      }
    }
    return A.i;
}
/** \SSE5{Reference,_mm_rot_epi64,	 protq } */
SSP_FORCEINLINE __m128i ssp_rot_epi64_REF(__m128i a, __m128i b  )
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 2; n++ )
    {
      if( B.s64[n] < 0 )
      {
        unsigned int count = (unsigned int)((-B.s64[n]) % 64);
        unsigned int carry_count = (64 - count) % 64;
        ssp_u64 carry = A.u64[n] << carry_count;
        A.u64[n] = A.u64[n] >> count;
        A.u64[n] = A.u64[n] | carry;
      }
      else
      {
        unsigned int count = (unsigned int)(B.s64[n] % 64);
        unsigned int carry_count = (64 - count) % 64;
        ssp_u64 carry = A.u64[n] >> carry_count;
        A.u64[n] = A.u64[n] << count;
        A.u64[n] = A.u64[n] | carry;
      }
    }
    return A.i;
}
/** \SSE5{Reference,_mm_roti_epi8, protb } */
SSP_FORCEINLINE __m128i ssp_roti_epi8_REF(__m128i a, const int b)
{
    int n;
    ssp_m128 A;
    A.i = a;

    if( b < 0 )
    {
        unsigned int count = (-b) % 8;
        unsigned int carry_count = (8 - count) % 8;
        for( n = 0; n < 16; n++ )
        {
            ssp_u8 carry = A.u8[n] << carry_count;
            A.u8[n] = A.u8[n] >> count;
            A.u8[n] = A.u8[n] | carry;
        }
    }
    else
    {
        unsigned int count = b % 8;
        unsigned int carry_count = (8 - count) % 8;
        for( n = 0; n < 16; n++ )
        {
            ssp_u8 carry = A.u8[n] >> carry_count;
            A.u8[n] = A.u8[n] << count;
            A.u8[n] = A.u8[n] | carry;
        }
    }
    return A.i;
}
/** \SSE5{Reference,_mm_roti_epi16, protw } */
SSP_FORCEINLINE __m128i ssp_roti_epi16_REF(__m128i a, const int b)
{
    int n;
    ssp_m128 A;
    A.i = a;

    if( b < 0 )
    {
        unsigned int count = (-b) % 16;
        unsigned int carry_count = (16 - count) % 16;
        for( n = 0; n < 8; n++ )
        {
            ssp_u16 carry = A.u16[n] << carry_count;
            A.u16[n] = A.u16[n] >> count;
            A.u16[n] = A.u16[n] | carry;
        }
    }
    else
    {
        unsigned int count = b % 16;
        unsigned int carry_count = (16 - count) % 16;
        for( n = 0; n < 8; n++ )
        {
            ssp_u16 carry = A.u16[n] >> carry_count;
            A.u16[n] = A.u16[n] << count;
            A.u16[n] = A.u16[n] | carry;
        }
    }
    return A.i;
}
/** \SSE5{Reference,_mm_roti_epi32, protd } */
SSP_FORCEINLINE __m128i ssp_roti_epi32_REF(__m128i a, const int b)
{
    int n;
    ssp_m128 A;
    A.i = a;

    if( b < 0 )
    {
        unsigned int count = (-b) % 32;
        unsigned int carry_count = (32 - count) % 32;
        for( n = 0; n < 4; n++ )
        {
            ssp_u32 carry = A.u32[n] << carry_count;
            A.u32[n] = A.u32[n] >> count;
            A.u32[n] = A.u32[n] | carry;
        }
    }
    else
    {
        unsigned int count = b % 32;
        unsigned int carry_count = (32 - count) % 32;
        for( n = 0; n < 4; n++ )
        {
            ssp_u32 carry = A.u32[n] >> carry_count;
            A.u32[n] = A.u32[n] << count;
            A.u32[n] = A.u32[n] | carry;
        }
    }
    return A.i;
}
/** \SSE5{Reference,_mm_roti_epi64, protq } */
SSP_FORCEINLINE __m128i ssp_roti_epi64_REF(__m128i a, const int b)
{
    int n;
    ssp_m128 A;
    A.i = a;

    if( b < 0 )
    {
        unsigned int count = (-b) % 64;
        unsigned int carry_count = (64 - count) % 64;
        for( n = 0; n < 2; n++ )
        {
            ssp_u64 carry = A.u64[n] << carry_count;
            A.u64[n] = A.u64[n] >> count;
            A.u64[n] = A.u64[n] | carry;
        }
    }
    else
    {
        unsigned int count = b % 64;
        unsigned int carry_count = (64 - count) % 64;
        for( n = 0; n < 2; n++ )
        {
            ssp_u64 carry = A.u64[n] >> carry_count;
            A.u64[n] = A.u64[n] << count;
            A.u64[n] = A.u64[n] | carry;
        }
    }
    return A.i;
}


//--------------------------------------
// Packed Shift Logical (bytes, words, dwords, qwords)
//--------------------------------------

/** \SSE5{Reference,ssp_shl_epi8,pshlb } */ 
SSP_FORCEINLINE __m128i ssp_shl_epi8_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 16; n++ )
    {
      if( B.s8[n] < 0 )
      {
        unsigned int count = (-B.s8[n]) % 8;
        A.u8[n] = A.u8[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n] % 8;
        A.u8[n] = A.u8[n] << count;
      }
    }
    return A.i;
}

/** \SSE5{Reference,ssp_sha_epi8,pshab } */ 
SSP_FORCEINLINE __m128i ssp_sha_epi8_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 16; n++ )
    {
      if( B.s8[n] < 0 )
      {
        unsigned int count = (-B.s8[n]) % 8;
        A.s8[n] = A.s8[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n] % 8;
        A.s8[n] = A.s8[n] << count;
      }
    }

    return A.i;
}

/** \SSE5{Reference,ssp_shl_epi16,pshlw } */ 
SSP_FORCEINLINE __m128i ssp_shl_epi16_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 8; n++ )
    {
      if( B.s8[n*2] < 0 )
      {
        unsigned int count = (-B.s8[n*2]) % 16;
        A.u16[n] = A.u16[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n*2] % 16;
        A.u16[n] = A.u16[n] << count;
      }
    }
    return A.i;
}

/** \SSE5{Reference,ssp_sha_epi16,pshaw } */ 
SSP_FORCEINLINE __m128i ssp_sha_epi16_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 8; n++ )
    {
      if( B.s8[n*2] < 0 )
      {
        unsigned int count = (-B.s8[n*2]) % 16;
        A.s16[n] = A.s16[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n*2] % 16;
        A.s16[n] = A.s16[n] << count;
      }
    }

    return A.i;
}

/** \SSE5{Reference,ssp_shl_epi32,pshld } */ 
SSP_FORCEINLINE __m128i ssp_shl_epi32_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 4; n++ )
    {
      if( B.s8[n*4] < 0 )
      {
        unsigned int count = (-B.s8[n*4]) % 32;
        A.u32[n] = A.u32[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n*4] % 32;
        A.u32[n] = A.u32[n] << count;
      }
    }
    return A.i;
}

/** \SSE5{Reference,ssp_sha_epi32,pshad } */ 
SSP_FORCEINLINE __m128i ssp_sha_epi32_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 4; n++ )
    {
      if( B.s8[n*4] < 0 )
      {
        unsigned int count = (-B.s8[n*4]) % 32;
        A.s32[n] = A.s32[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n*4] % 32;
        A.s32[n] = A.s32[n] << count;
      }
    }

    return A.i;
}

/** \SSE5{Reference,ssp_shl_epi64,pshld } */ 
SSP_FORCEINLINE __m128i ssp_shl_epi64_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 2; n++ )
    {
      if( B.s8[n*8] < 0 )
      {
        unsigned int count = (-B.s8[n*8]) % 64;
        A.u64[n] = A.u64[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n*8] % 64;
        A.u64[n] = A.u64[n] << count;
      }
    }
    return A.i;
}

/** \SSE5{Reference,ssp_sha_epi64,pshad } */ 
SSP_FORCEINLINE __m128i ssp_sha_epi64_REF(__m128i a, __m128i b)
{
    int n;
    ssp_m128 A,B;
    A.i = a;
    B.i = b;

    for( n = 0; n < 2; n++ )
    {
      if( B.s8[n*8] < 0 )
      {
        unsigned int count = (-B.s8[n*8]) % 64;
        A.s64[n] = A.s64[n] >> count;
      }
      else
      {
        unsigned int count = B.s8[n*8] % 64;
        A.s64[n] = A.s64[n] << count;
      }
    }

    return A.i;
}

/** @} 
 *  @}
 */

#endif // __SSP_EMULATION_REF_H__
