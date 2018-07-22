//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_ARITHMETIC_SSE2_H__
#define __SSEPLUS_ARITHMETIC_SSE2_H__

#include "../native/SSEPlus_native_SSE2.h"
#include "../emulation/SSEPlus_emulation_SSE2.h"

/** @addtogroup supplimental_SSE2
 *  @{ 
 *  @name Arithmetic Operations
 */

SSP_FORCEINLINE
__m128 ssp_arithmetic_hadd4_dup_ps_SSE2( __m128 a )      // [18 cycles]                 // Sum all 4 values
{
    __m128 t;
    t = _mm_shuffle_ps( a, a, _MM_SHUFFLE(2, 3, 0, 1) );                //TODO shuflo, shuf hi
    a = _mm_add_ps( a, t );   

    t = _mm_shuffle_ps( a, a, _MM_SHUFFLE(1, 0, 3, 2) );                //TODO shuflo, shuf hi
    a = _mm_add_ps( a, t );
    return a;
} 


/**
    in  = a,b,c,d       | e,f,g,h,       0
    out = x,x,x,a+b+c+d | x,x,x,e+f+g+h

    in  = a,b,c,d       | e,f,g,h,       3
    out = a+b+c+d,x,x,x,| x,x,x,e+f+g+h

    offset indicates desired position of sum (0,1,2,3)
*/
SSP_FORCEINLINE
__m128i ssp_arithmetic_hadd4_epi16_SSE2( __m128i a, const unsigned int offset )      // Sum 2 sets of 4 values, dest in 0, and 4
{
    ssp_m128 A,B;
    A.i = a;                                           //A = a, b, c, d | e, f, g, h

    if( offset >= 2 ) B.i = _mm_slli_si128( A.i, 4 );  //B = c, d, x, x | g, h, x, x
    else              B.i = _mm_srli_si128( A.i, 4 );  //B = x, x, a, b | x, x, e, f

    A.i = _mm_add_epi16 ( A.i, B.i );      

    if( offset & 1 )  B.i = _mm_slli_si128( A.i, 2 );  
    else              B.i = _mm_srli_si128( A.i, 2 ); 
  
    A.i = _mm_add_epi16 ( A.i, B.i );      
    return A.i;
}  



//__m128 ssp_arithmetic_hadd4_dup_ps_SSE2_a( __m128 a_ )      // [19 cycles]                 // Sum all 4 values
//{
//    ssp_m128 t, a; a.f = a_;
//
//    t.i  = _mm_shufflehi_epi16( a.i, _MM_SHUFFLE(1, 0, 3, 2) );
//    t.i  = _mm_shufflelo_epi16( t.i, _MM_SHUFFLE(1, 0, 3, 2) );
//    
//    //t.f  = _mm_shuffle_ps( a, a, _MM_SHUFFLE(2, 3, 0, 1) );           //TODO shuflo, shuf hi   
//
//    a.f = _mm_add_ps    ( a.f, t.f );  
//
//    t.f = _mm_shuffle_ps( a.f, a.f, _MM_SHUFFLE(1, 0, 3, 2) );                //TODO shuflo, shuf hi
//
//
//    a.f = _mm_add_ps    ( a.f, t.f );
//    return a.f;
//}  
//
//__m128 ssp_arithmetic_hadd4_dup_ps_SSE2_b( __m128 a )      // [18 cycles]                 // Sum all 4 values
//{
//    __m128 t;
//    t = _mm_shuffle_ps( a, a, _MM_SHUFFLE(2, 3, 0, 1) );                //TODO shuflo, shuf hi
//    a = _mm_add_ps( a, t );     
//
//    t = _mm_movelh_ps( t, a );
//    t = _mm_movehl_ps( t, a );
//   
//    a = _mm_add_ps( a, t );
//    return a;
//}  

/** This function wraps ssp_round_ps_SSE2. It guarantees that numbers rounding to 0 from a negative will generate a negative zero. */
SSP_FORCEINLINE
__m128 ssp_round_ps_neg_zero_SSE2( __m128  a, int iRoundMode )
{
    const static __m128i SIGN_BIT = SSP_CONST_SET_32I( 0x80000000, 0x80000000, 0x80000000,0x80000000 );
    ssp_m128 A, sign;
    A.f = a;
    
    sign.i = _mm_and_si128    ( A.i, SIGN_BIT );  // Store the sign bits
    A.f    = ssp_round_ps_SSE2( A.f, iRoundMode );   
    A.i    = _mm_or_si128     ( A.i, sign.i );    // Restore the sign bits (preserves -0)
   
    return A.f;
}

/** @} 
 *  @}
 */

#endif // __SSEPLUS_ARITHMETIC_SSE2_H__
