//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_ARITHMETIC_REF_H__
#define __SSEPLUS_ARITHMETIC_REF_H__


/** @addtogroup supplimental_REF   
 *  @{ 
 *  @name Arithmetic Operations
 */


/** */
SSP_FORCEINLINE __m128 ssp_arithmetic_hadd4_dup_ps_REF( __m128 a )      // Sum all 4 values
{
    ssp_m128 A;
    ssp_f32 t;
    
    A.f = a;
    t   = A.f32[0] + 
          A.f32[1] + 
          A.f32[2] + 
          A.f32[3];

    A.f32[0] = t;
    A.f32[1] = t;
    A.f32[2] = t;
    A.f32[3] = t;
    return A.f;
}  

SSP_FORCEINLINE __m128i ssp_arithmetic_hadd4_epu16_REF( __m128i a )      // Sum 2 sets of 4 values, dest in 0, and 4
{
    ssp_m128 A;
    A.i = a;

    A.u16[0] = A.u16[0] + A.u16[1] + + A.u16[2] + + A.u16[3];
    A.u16[4] = A.u16[4] + A.u16[5] + + A.u16[6] + + A.u16[7];

    return A.i;
}  

//@}
//@}


#endif // __SSEPLUS_ARITHMETIC_REF_H__
