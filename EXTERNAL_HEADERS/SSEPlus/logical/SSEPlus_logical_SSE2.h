//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_LOGICAL_SSE2_H__
#define __SSEPLUS_LOGICAL_SSE2_H__

#include "../native/SSEPlus_native_SSE2.h"

/** @addtogroup supplimental_SSE2
 *  @{ 
 *  @name Logical Operations
 */

SSP_FORCEINLINE __m128i ssp_logical_bitwise_select_SSE2( __m128i a, __m128i b, __m128i mask )   // Bitwise (mask ? a : b) 
{
    a = _mm_and_si128   ( a,    mask );                                 // clear a where mask = 0
    b = _mm_andnot_si128( mask, b    );                                 // clear b where mask = 1
    a = _mm_or_si128    ( a,    b    );                                 // a = a OR b                         
    return a; 
}


/** Arithmetic 8 bit right shift */
SSP_FORCEINLINE __m128i ssp_logical_srai_epi8_SSE2( __m128i a, int count )
{
    const static __m128i MASK = SSP_CONST_SET_8I( 0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0 );
    __m128i b;         
    b = _mm_srai_epi16 ( a, count   ); // Shift even indexes into position
    a = _mm_slli_epi16 ( a, 8       ); // Prepare odd indexes
    a = _mm_srai_epi16 ( a, count+8 ); // Shift even indexes into position
    a = ssp_logical_bitwise_select_SSE2( b, a, MASK );
    return a;
}


/** Invert 'mask' if 'a' and 'b' have different signs. */
SSP_FORCEINLINE __m128i ssp_logical_signinvert_16_SSE2( __m128i mask, __m128i a, __m128i b)
{
    __m128i signMask;   
    signMask = _mm_xor_si128  ( a, b );              // Signbit is 1 where signs differ 
    signMask = _mm_srai_epi16 ( signMask, 15 );      // fill all fields with sign bit     
    mask     = _mm_xor_si128  ( mask, signMask );    // Invert output where signs differed
    return mask;  
}

/** Invert 'mask' if 'a' and 'b' have different signs. */
SSP_FORCEINLINE __m128i ssp_logical_signinvert_32_SSE2( __m128i mask, __m128i a, __m128i b)
{
    __m128i signMask;   
    signMask = _mm_xor_si128  ( a, b );              // Signbit is 1 where signs differ 
    signMask = _mm_srai_epi32 ( signMask, 31 );      // fill all fields with sign bit     
    mask     = _mm_xor_si128  ( mask, signMask );    // Invert output where signs differed
    return mask;  
}

/** Invert 'mask' if 'a' and 'b' have different signs. */
SSP_FORCEINLINE __m128i ssp_logical_signinvert_8_SSE2( __m128i mask, __m128i a, __m128i b)
{
    __m128i signMask;   
    signMask = _mm_xor_si128              ( a, b );             // Signbit is 1 where signs differ 
    signMask = ssp_logical_srai_epi8_SSE2 ( signMask, 7 );      // fill all fields with sign bit     
    mask     = _mm_xor_si128              ( mask, signMask );   // Invert output where signs differed
    return mask;  
}



SSP_FORCEINLINE __m128i ssp_logical_invert_si128_SSE2( __m128i a )
{
    const static __m128i mask = SSP_CONST_SET_32I( 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF );
    a = _mm_xor_si128( a, mask );
    return a;
}

SSP_FORCEINLINE __m128d ssp_logical_invert_sd_SSE2( __m128d a )
{
    const static __m128i mask = SSP_CONST_SET_32I( 0xFFFFFFFF, 0xFFFFFFFF, 0, 0 );
    ssp_m128 A;
    A.d    = a;
    A.i = _mm_xor_si128( A.i, mask );
    return A.d;
}

SSP_FORCEINLINE __m128 ssp_logical_invert_ss_SSE2( __m128 a )
{
    const static __m128i mask = SSP_CONST_SET_32I( 0xFFFFFFFF, 0, 0, 0 );
    ssp_m128 A;
    A.f    = a;
    A.i = _mm_xor_si128( A.i, mask );
    return A.f;
}





//SSP_FORCEINLINE
//__m128i ssp_generate_mask_imm8_to_epi16_SSE2( int mask )
//{
//    __m128i screen;
//    const static __m128i mulShiftImm = SSP_CONST_SET_16I( 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000 ); // Shift mask multiply moves all bits to left, becomes MSB
//    screen = _mm_set1_epi16  ( mask                );   // Load the mask into register
//    screen = _mm_mullo_epi16 ( screen, mulShiftImm );   // Shift bits to MSB
//    screen = _mm_srai_epi16  ( screen, 15          );   // Shift bits to obtain 0xFFFF or 0x0000
//    return screen;
//}

SSP_FORCEINLINE
__m128i ssp_movmask_imm8_to_epi32_SSE2( int mask )
{
    __m128i screen;
    const static __m128i mulShiftImm = SSP_CONST_SET_16I( 0x1000, 0x0000, 0x2000, 0x0000, 0x4000, 0x0000, 0x8000, 0x0000 ); // Shift mask multiply moves all bits to left, becomes MSB
    screen = _mm_set1_epi16 ( mask                );   // Load the mask into register
    screen = _mm_mullo_epi16( screen, mulShiftImm );   // Shift bits to MSB
    screen = _mm_srai_epi32 ( screen, 31          );   // Shift bits to obtain all F's or all 0's
    return screen;
}


/**
  r_:= a_ << b; (logical left shift)
*/
SSP_FORCEINLINE __m128i ssp_slli_epi8_SSE2(__m128i a, const int b)
{                                            //  a = VfVeVdVcVbVaV9V8V7V6V5V4V3V2V1V0
    __m128i t1 = _mm_srli_epi16( a, 8 );     // t1 =   Vf  Vd  Vb  V9  V7  V5  V3  V1
    __m128i t2 = _mm_slli_epi16( a, b + 8 ); // t2 = Re  Rc  Ra  R8  R6  R4  R2  R0
    t1 = _mm_slli_epi16( t1, b + 8 );        // t1 = Rf  Rd  Rb  R9  R7  R5  R3  R1
    t2 = _mm_srli_epi16( t1, 8 );            // t2 =   Re  Rc  Ra  R8  R6  R4  R2  R0
    t1 = _mm_or_si128( t1, t2 );             // t1 = RfReRdRcRbRaR9R8R7R6R5R4R3R2R1R0
    return t1;
}

/**
  r_:= a_ >> b; (logical right shift)
*/
SSP_FORCEINLINE __m128i ssp_srli_epi8_SSE2(__m128i a, const int b)
{                                            //  a = VfVeVdVcVbVaV9V8V7V6V5V4V3V2V1V0
    __m128i t1 = _mm_slli_epi16( a, 8 );     // t1 = Ve  Vc  Va  V8  V6  V4  V2  V0
    __m128i t2 = _mm_srli_epi16( a, b + 8 ); // t2 =   Rf  Rd  Rb  R9  R7  R5  R3  R1
    t1 = _mm_srli_epi16( t1, b + 8 );        // t1 =   Re  Rc  Ra  R8  R6  R4  R2  R0
    t2 = _mm_slli_epi16( t1, 8 );            // t2 = Rf  Rd  Rb  R9  R7  R5  R3  R1
    t1 = _mm_or_si128( t1, t2 );             // t1 = RfReRdRcRbRaR9R8R7R6R5R4R3R2R1R0
    return t1;
}

/** @} 
 *  @}
 */

#endif // __SSEPLUS_LOGICAL_SSE2_H__
