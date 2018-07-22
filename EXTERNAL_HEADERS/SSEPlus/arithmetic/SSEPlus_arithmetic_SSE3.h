//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_ARITHMETIC_SSE3_H__
#define __SSEPLUS_ARITHMETIC_SSE3_H__

#include "../native/SSEPlus_native_SSE3.h"

/** @addtogroup supplimental_SSE3  
 *  @{ 
 *  @name Arithmetic Operations
 */

SSP_FORCEINLINE
__m128 ssp_arithmetic_hadd4_dup_ps_SSE3( __m128 a )      // [18 cycles]                 // Sum all 4 values
{
	a = _mm_hadd_ps( a, a );
	a = _mm_hadd_ps( a, a );
    return a;
} 

/** @} 
 *  @}
 */


#endif // __SSEPLUS_ARITHMETIC_SSE2_H__
