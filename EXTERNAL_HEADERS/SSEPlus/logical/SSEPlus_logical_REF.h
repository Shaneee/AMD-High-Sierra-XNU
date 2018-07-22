//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_LOGICAL_REF_H__
#define __SSEPLUS_LOGICAL_REF_H__

#include "../SSEPlus_base.h"


/** @addtogroup supplimental_REF   
 *  @{ 
 *  @name Logical Operations
 */
SSP_FORCEINLINE __m128i ssp_logical_invert_si128_REF( __m128i a )
{
    ssp_m128 A;
    A.i = a;

    A.u32[0] = ~A.u32[0];
    A.u32[1] = ~A.u32[1];
    A.u32[2] = ~A.u32[2];
    A.u32[3] = ~A.u32[3];
    return A.i;
}


/**
  r_:= a_ << b; (logical left shift)
*/
SSP_FORCEINLINE __m128i ssp_slli_epi8_REF(__m128i a, const int b)
{
    int n;
    ssp_m128 A;
    A.i = a;
    for( n = 0; n < 16; n++ )
    {
        A.u8[n] = A.u8[n] << b;
    }
    return A.i;
}

/**
  r_:= a_ >> b; (logical right shift)
*/
SSP_FORCEINLINE __m128i ssp_srli_epi8_REF(__m128i a, const int b)
{                                            //  a = VfVeVdVcVbVaV9V8V7V6V5V4V3V2V1V0
    int n;
    ssp_m128 A;
    A.i = a;
    for( n = 0; n < 16; n++ )
    {
        A.u8[n] = A.u8[n] >> b;
    }
    return A.i;
}

/** @} 
 *  @}
 */


#endif // __SSEPLUS_LOGICAL_REF_H__
