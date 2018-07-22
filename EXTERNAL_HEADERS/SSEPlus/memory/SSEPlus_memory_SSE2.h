//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_MEMORY_SSE2_H__
#define __SSEPLUS_MEMORY_SSE2_H__

#include "../SSEPlus_base.h"
#include <emmintrin.h>  // SSE2

/** @addtogroup supplimental_SSE2
 *  @{ 
 *  @name Memory Operations
 */



__m128i ssp_memory_load1_epu8_SSE2( unsigned char a )
{
    ssp_m128 A;
    
    A.u8[0] = a;
    A.u8[1] = a;
    A.u8[2] = a;
    A.u8[3] = a;

    A.u32[1] = A.u32[0];
    A.u32[2] = A.u32[0];
    A.u32[3] = A.u32[0]; 
    
    return A.i;
}


/** @} 
 *  @}
 */

#endif // __SSEPLUS_MEMORY_SSE2_H__
