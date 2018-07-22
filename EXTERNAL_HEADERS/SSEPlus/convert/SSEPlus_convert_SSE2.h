//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_CONVERT_SSE2_H__
#define __SSEPLUS_CONVERT_SSE2_H__

#include "../native/SSEPlus_native_SSE2.h"

/** @addtogroup supplimental_SSE2   
 *  @{ 
 *  @name Convert Operations
 */


/**  */
SSP_FORCEINLINE
void ssp_convert_odd_even_epi16_SSE2( __m128i *a, __m128i *b )
{
    // IN
    // a = a7,a6,a5,a4,a3,a2,a1,a0
    // b = b7,b6,b5,b4,b3,b2,b1,b0

    // OUT
    // a = b6,b4,b2,b0,a6,a4,a2,a0  // even
    // b = b7,b5,b3,b1,a7,a5,a3,a1  // odd

    __m128i A = *a;
    __m128i B = *b;
    __m128i ta, tb, odd, even;

    ta   = _mm_srai_epi32 ( A, 16 );    // sign,a7,sign,a5,sign,a3,sign,a1
    tb   = _mm_srai_epi32 ( B, 16 );    // sign,b7,sign,b5,sign,b3,sign,b1
    odd  = _mm_packs_epi32( ta, tb );   //   b7,b5,  b3,b1,  a7,a5,  a3,a1

    A    = _mm_slli_si128 ( A, 2 );     //   a6, 0,  a4, 0,  a2, 0,  a0, 0
    B    = _mm_slli_si128 ( B, 2 );     //   b6, 0,  b4, 0,  b2, 0,  b0, 0
    A    = _mm_srai_epi32 ( A, 16 );    // sign,a6,sign,a4,sign,a2,sign,a0
    B    = _mm_srai_epi32 ( B, 16 );    // sign,b6,sign,b4,sign,b2,sign,b0                                        
    even = _mm_packs_epi32( A, B );     //   b6,b4,  b2,b0,  a6,a4,  a2,a0

    *a = even;
    *b = odd;
}


/** */
SSP_FORCEINLINE
void ssp_convert_odd_even_ps_SSE2( __m128 *a, __m128 *b )
{
    // IN
    // a = a3,a2,a1,a0
    // b = b3,b2,b1,b0

    // OUT
    // a = b2,b0,a2,a0  // even
    // b = b3,b1,a3,a1  // odd
    
    __m128 c, d;  
    c = _mm_shuffle_ps( *a, *b, _MM_SHUFFLE(3,1,3,1) );
    d = _mm_shuffle_ps( *a, *b, _MM_SHUFFLE(2,0,2,0) );
    *a = c;
    *b = d;     
}

/** */
SSP_FORCEINLINE
void ssp_convert_odd_even_epi32_SSE2( __m128i *a, __m128i *b )
{
    // IN
    // a = a3,a2,a1,a0
    // b = b3,b2,b1,b0

    // OUT
    // a = b2,b0,a2,a0  // even
    // b = b3,b1,a3,a1  // odd
    
    ssp_m128 A,B;
    A.i = *a;
    B.i = *b;  

    ssp_convert_odd_even_ps_SSE2( &A.f, &B.f );

    *a = A.i;
    *b = B.i;       
}


SSP_FORCEINLINE 
void ssp_convert_3c_3p_epi8_SSE2( __m128i *rgb1, __m128i *rgb2, __m128i *rgb3)
{
    __m128i temp1, temp2;
                                                            // RGB1 =         r5 , b4  g4  r4 , b3  g3  r3 , b2  g2  r2 , b1  g1  r1 , b0  g0 r0
                                                            // RGB2 =     g10 r10, b9  g9  r9 , b8  g8  r8 , b7  g7  r7 , b6  g6  r6 , b5  g5   
                                                            // RGB3 = b15 g15 r15, b14 g14 r14, b13 g13 r13, b12 g12 r12, b11 g11 r11, b10 


    *rgb2 = _mm_shuffle_epi32(*rgb2, _MM_SHUFFLE(1,0,3,2));	// b7, g7, r7, b6, g6, r6, b5, g5,g10,r10, b9, g9, r9, b8, g8, r8
    temp1 = _mm_unpacklo_epi8(*rgb1, *rgb2);				//g10, g2,r10, r2, b9, b1, g9, g1, r9, r1, b8, b0, g8, g0, r8, r0
    temp2 = _mm_unpackhi_epi8(*rgb2, *rgb3);				//b15, b7,g15, g7,r15, r7,b14, b6,g14, g6,r14, r6,b13, b5,g13, g5
    *rgb3 = _mm_slli_si128   (*rgb3, 8    );				//r13,b12,g12,r12,b11,g11,r11,b10,  0,  0,  0,  0,  0,  0,  0,  0
    *rgb2 = _mm_unpackhi_epi8(*rgb1, *rgb3);				//r13, r5,b12, b4,g12, g4,r12, r4,b11, b3,g11, g3,r11, r3,b10, b2

    *rgb3 = _mm_shuffle_epi32(*rgb2, _MM_SHUFFLE(1,0,3,2));	//b11, b3,g11, g3,r11, r3,b10, b2,r13, r5,b12, b4,g12, g4,r12, r4
    *rgb1 = _mm_unpacklo_epi8(temp1, *rgb3);				//r13, r9, r5, r1,b12, b8, b4, b0,g12, g8, g4, g0,r12, r8, r4, r0
    temp1 = _mm_srli_si128   (temp1, 8    );				//  0,  0,  0,  0,  0,  0,  0,  0,g10, g2,r10, r2, b9, b1, g9, g1
    temp1 = _mm_unpacklo_epi8(temp1, temp2);				//g14,g10, g6, g2,r14,r10, r6, r2,b13, b9, b5, b1,g13, g9, g5, g1
    temp2 = _mm_unpackhi_epi8(*rgb3, temp2);				//b15,b11, b7, b3,g15,g11, g7, g3,r15,r11, r7, r3,b14,b10, b6, b2

    temp1 = _mm_shuffle_epi32(temp1, _MM_SHUFFLE(1,0,3,2)); //b13, b9, b5, b1,g13, g9, g5, g1,g14,g10, g6, g2,r14,r10, r6, r2
    *rgb3 = _mm_unpackhi_epi8(temp1, temp2);				//b15,b13,b11, b9, b7, b5, b3, b1,g15,g13,g11, g9, g7, g5, g3, g1
    temp2 = _mm_slli_si128   (temp2, 8    );				//r15,r11, r7, r3,b14,b10, b6, b2,  0,  0,  0,  0,  0,  0,  0,  0
    temp2 = _mm_unpackhi_epi8(*rgb1, temp2);				//r15,r13,r11, r9, r7, r5, r3, r1,b14,b12,b10, b8, b6, b4, b2, b0
    temp1 = _mm_unpacklo_epi8(*rgb1, temp1);				//g14,g12,g10, g8, g6, g4, g2, g0,r14,r12,r10, r8, r6, r4, r2, r0

    temp2 = _mm_shuffle_epi32(temp2, _MM_SHUFFLE(1,0,3,2)); //b14,b12,b10, b8, b6, b4, b2, b0,r15,r13,r11, r9, r7, r5, r3, r1
    *rgb1 = _mm_unpacklo_epi8(temp1, temp2);				//r15,r14,r13,r12,r11,r10, r9, r8, r7, r6, r5, r4, r3, r2, r1, r0	
    temp1 = _mm_srli_si128   (temp1, 8    );				//  0,  0,  0,  0,  0,  0,  0,  0,g14,g12,g10, g8, g6, g4, g2, g0
    *rgb2 = _mm_unpacklo_epi8(temp1, *rgb3);				//g15,g14,g13,g12,g11,g10, g9, g8, g7, g6, g5, g4, g3, g2, g1, g0	
    *rgb3 = _mm_unpackhi_epi8(temp2, *rgb3);				//b15,b14,b13,b12,b11,b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0	
}


//a: 9  6 3 0    3  2  1 0               
//b: 10 7 4 1 -> 7  6  5 4       
//c: 11 8 5 2    11 10 9 8
SSP_FORCEINLINE
void ssp_convert_reverse_transpose_SSE2( __m128i *a, __m128i *b, __m128i *c )
{
    ssp_m128 A, B, C, T1, T2, T3;
    A.i = *a;   
    B.i = *b;   
    C.i = *c;  

    T1.f = _mm_shuffle_ps( C.f,  A.f,  _MM_SHUFFLE( 3,1,2,0) ); // 9  3  8  2
    T2.f = _mm_shuffle_ps( B.f,  A.f,  _MM_SHUFFLE( 2,0,2,0) ); // 6  0  7  1
    T3.f = _mm_shuffle_ps( C.f,  B.f,  _MM_SHUFFLE( 3,1,3,1) ); // 10 4  11 5

    A.f  = _mm_shuffle_ps( T2.f, T1.f, _MM_SHUFFLE( 2,0,0,2 ) ); //3  2  1  0  
    B.f  = _mm_shuffle_ps( T3.f, T2.f, _MM_SHUFFLE( 1,3,0,2 ) ); //7  6  5  4  
    C.f  = _mm_shuffle_ps( T1.f, T3.f, _MM_SHUFFLE( 1,3,3,1 ) ); //11 10 9  8   

    *a = A.i;
    *b = B.i;
    *c = C.i; 
}


SSP_FORCEINLINE
void ssp_convert_3p_3c_epi8_SSE2( __m128i *r, __m128i *g, __m128i *b )
{
    const static __m128i odd_8  = SSP_CONST_SET_8I(   0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0 );
    const static __m128i even_8 = SSP_CONST_SET_8I( 0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF   );

    const static __m128i odd_16  = SSP_CONST_SET_16I(   0xFFFF,0,0xFFFF,0,0xFFFF,0,0xFFFF,0 );
    const static __m128i even_16 = SSP_CONST_SET_16I( 0,0xFFFF,0,0xFFFF,0,0xFFFF,0,0xFFFF   );    

   ssp_m128 T, RG, EGB, BR, RGBR, GBRG, BRGB;
    
     RG.i = _mm_and_si128 (     *r, even_8  );  // Mask out the odd r bits
      T.i = _mm_slli_epi16(     *g, 8       );  // Move the even g bits to the odd position
     RG.i = _mm_or_si128  (   RG.i, T.i     );  // G14 R14 ... G2 R2 G0 R0

     EGB.i = _mm_srli_epi16(     *g, 8       );
      T.i = _mm_and_si128 (     *b, odd_8   );
     EGB.i = _mm_or_si128  (   EGB.i, T.i     );

     BR.i = _mm_and_si128 (     *b, even_8  );
      T.i = _mm_and_si128 (     *r, odd_8   );
     BR.i = _mm_or_si128  (   BR.i, T.i     );

   RGBR.i = _mm_and_si128 (   RG.i, even_16 );
      T.i = _mm_slli_epi32(   BR.i, 16      );
   RGBR.i = _mm_or_si128  ( RGBR.i, T.i     );

   GBRG.i = _mm_and_si128 (  EGB.i, even_16 );
      T.i = _mm_and_si128 (   RG.i, odd_16  );
   GBRG.i = _mm_or_si128  ( GBRG.i, T.i     );

   BRGB.i = _mm_srli_epi32(   BR.i, 16      );
      T.i = _mm_and_si128 (  EGB.i, odd_16  );
   BRGB.i = _mm_or_si128  ( BRGB.i, T.i     );

   ssp_convert_reverse_transpose_SSE2( &RGBR.i, &GBRG.i, &BRGB.i );

   *r = RGBR.i;
   *g = GBRG.i;
   *b = BRGB.i; 
}

SSP_FORCEINLINE 
void ssp_convert_3c_3p_epi16_SSE2(__m128i *rgb1,__m128i *rgb2,__m128i *rgb3)
{
		__m128i temp1, temp2;

		*rgb2  = _mm_shuffle_epi32(*rgb2, _MM_SHUFFLE(1,0,3,2));//b3,g3,r3,b2,r5,b4,g4,r4
		temp1 = _mm_unpacklo_epi16(*rgb1, *rgb2);				//r5,r1,b4,b0,g4,g0,r4,r0
		temp2 = _mm_unpackhi_epi16(*rgb2, *rgb3);				//b7,b3,g7,g3,r7,r3,b6,b2
		*rgb3  = _mm_slli_si128(*rgb3, 8);						//g6,r6,b5,g5, 0, 0, 0, 0
		*rgb2  = _mm_unpackhi_epi16(*rgb1, *rgb3);				//g6,g2,r6,r2,b5,b1,g5,g1
		
		*rgb3  = _mm_shuffle_epi32(*rgb2, _MM_SHUFFLE(1,0,3,2));//b5,b1,g5,g1,g6,g2,r6,r2
		*rgb1  = _mm_unpacklo_epi16(temp1, *rgb3);				//g6,g4,g2,g0,r6,r4,r2,r0
		temp1 = _mm_srli_si128(temp1, 8);						// 0, 0, 0, 0,r5,r1,b4,b0
		temp1 = _mm_unpacklo_epi16(temp1, temp2);				//r7,r5,r3,r1,b6,b4,b2,b0
		temp2 = _mm_unpackhi_epi16(*rgb3, temp2);				//b7,b5,b3,b1,g7,g5,g3,g1

		temp1 = _mm_shuffle_epi32(temp1, _MM_SHUFFLE(1,0,3,2)); //b6,b4,b2,b0,r7,r5,r3,r1
		*rgb3  = _mm_unpackhi_epi16(temp1, temp2);				//b7,b6,b5,b4,b3,b2,b1,b0				
		temp2 = _mm_slli_si128(temp2, 8);						//g7,g5,g3,g1, 0, 0, 0, 0
		*rgb2  = _mm_unpackhi_epi16(*rgb1, temp2);				//g7,g6,g5,g4,g3,g2,g1,g0				
		*rgb1  = _mm_unpacklo_epi16(*rgb1, temp1);				//r7,r6,r5,r4,r3,r2,r1,r0				
}

SSP_FORCEINLINE 
void ssp_convert_3p_3c_epi16_SSE2(__m128i *r,__m128i *g,__m128i *b)
{
		__m128i temp;

		temp = _mm_srli_si128(*r, 8);			// 0, 0, 0, 0,r7,r6,r5,r4
		*r    = _mm_unpacklo_epi16(*r, temp);	//r7,r3,r6,r2,r5,r1,r4,r0
		temp = _mm_srli_si128(*r, 8);			// 0, 0, 0, 0,r7,r3,r6,r2
		*r    = _mm_unpacklo_epi16(*r, temp);	//r7,r5,r3,r1,r6,r4,r2,r0

		temp = _mm_srli_si128(*g, 8);			//g7,g3,g6,g2,g5,g1,g4,g0
		*g    = _mm_unpacklo_epi16(*g, temp);	// 0, 0, 0, 0,g7,g3,g6,g2
		temp = _mm_srli_si128(*g, 8);			//g7,g5,g3,g1,g6,g4,g2,g0
		*g    = _mm_unpacklo_epi16(*g, temp);	//g7,g5,g3,g1,g6,g4,g2,g0

		temp = _mm_srli_si128(*b, 8);			//b7,b3,b6,b2,b5,b1,b4,b0
		*b    = _mm_unpacklo_epi16(*b, temp);	// 0, 0, 0, 0,b7,b3,b6,b2
		temp = _mm_srli_si128(*b, 8);			//b7,b5,b3,b1,b6,b4,b2,b0
		*b    = _mm_unpacklo_epi16(*b, temp);	//b7,b5,b3,b1,b6,b4,b2,b0

		temp = _mm_unpacklo_epi16(*r, *g);		//g6,r6,g4,r4,g2,r2,g0,r0
		*r    = _mm_srli_si128(*r , 8);			// 0, 0, 0, 0,r7,r5,r3,r1
		*r    = _mm_unpacklo_epi16(*b, *r);		//r7,b6,r5,b4,r3,b2,r1,b0
		*g    = _mm_unpackhi_epi16(*g, *b);		//b7,g7,b5,g5,b3,g3,b1,g1

		*b    = _mm_srli_si128(*r, 8);			// 0, 0, 0, 0,r7,b6,r5,b4
		*r    = _mm_unpacklo_epi32(*r, *b);		//r7,b6,r3,b2,r5,b4,r1,b0
		*b    = _mm_srli_si128(*g, 8);			// 0, 0, 0, 0,b7,g7,b5,g5
		*g    = _mm_unpacklo_epi32(*g, *b);		//b7,g7,b3,g3,b5,g5,b1,g1
		*b    = _mm_srli_si128(temp, 8);		// 0, 0, 0, 0,g6,r6,g4,r4
		temp = _mm_unpacklo_epi32(temp, *b);	//g6,r6,g2,r2,g4,r4,g0,r0

		*b    = _mm_unpacklo_epi32(temp, *g);	//b5,g5,g4,r4,b1,g1,g0,r0
		temp = _mm_srli_si128(temp, 8);			// 0, 0, 0, 0,g6,r6,g2,r2
		temp = _mm_unpacklo_epi32(*r, temp);	//g6,r6,r5,b4,g2,r2,r1,b0
		*g    = _mm_unpackhi_epi32(*r, *g);		//b7,g7,r7,b6,b3,g3,r3,b2
		
		*r    = _mm_unpacklo_epi32(*b, temp);	//g2,r2,b1,g1,r1,b0,g0,r0
		temp = _mm_unpackhi_epi32(*b, temp);	//g6,r6,b5,g5,r5,b4,g4,b4
		*b    = _mm_unpackhi_epi64(temp, *g);	//b7,g7,r7,b6,g6,r6,b5,g5
		*g    = _mm_unpacklo_epi64(*g, temp);	//r5,b4,g4,r4,b3,g3,r3,b2
}

SSP_FORCEINLINE 
void ssp_convert_3c_3p_epi32_SSE2(__m128i *rgb1,__m128i *rgb2,__m128i *rgb3)
{
		__m128i temp1, temp2;
		
		*rgb2  = _mm_shuffle_epi32(*rgb2, _MM_SHUFFLE(1,0,3,2));//b1,g1,g2,r2
		temp1 = _mm_unpacklo_epi32(*rgb1, *rgb2);				//g2,g0,r2,r0
		temp2 = _mm_unpackhi_epi32(*rgb2, *rgb3);				//b3,b1,g3,g1
		*rgb3  = _mm_slli_si128(*rgb3, 8);						//r3,b2, 0, 0
		*rgb2  = _mm_unpackhi_epi32(*rgb1, *rgb3);				//r3,r1,b2,b0
		
		*rgb3  = _mm_shuffle_epi32(*rgb2, _MM_SHUFFLE(1,0,3,2));//b2,b0,r3,r1
		*rgb1  = _mm_unpacklo_epi32(temp1, *rgb3);				//r3,r2,r1,r0
		temp1 = _mm_srli_si128(temp1, 8);						// 0, 0,g2,g0
		*rgb2  = _mm_unpacklo_epi32(temp1, temp2);				//g3,g2,g1,g0
		*rgb3  = _mm_unpackhi_epi32(*rgb3, temp2);				//b3,b2,b1,b0
}

SSP_FORCEINLINE 
void ssp_convert_3p_3c_epi32_SSE2(__m128i *r,__m128i *g,__m128i *b)
{
		__m128i temp;

		temp = _mm_srli_si128(*r, 8);			// 0, 0,r3,r2
		*r    = _mm_unpacklo_epi32(*r, temp);	//r3,r1,r2,r0
		temp = _mm_srli_si128(*g, 8);			// 0, 0,g3,g2
		*g    = _mm_unpacklo_epi32(*g, temp);	//g3,g1,g2,g0
		temp = _mm_srli_si128(*b, 8);			// 0, 0,b3,b2
		*b    = _mm_unpacklo_epi32(*b, temp);	//b3,b1,b2,b0

		temp = _mm_unpacklo_epi32(*r, *g);		//g2,r2,g0,r0
		*g    = _mm_unpackhi_epi32(*g, *b);		//b3,g3,b1,g1
		*r    = _mm_srli_si128(*r, 8);			// 0, 0,r3,r1
		*b    = _mm_unpacklo_epi32(*b, *r);		//r3,b2,r1,b0

		*r    = _mm_unpacklo_epi64(temp, *b);	//r1,b0,g0,r0
		*b    = _mm_unpackhi_epi64(*b, *g);		//b3,g3,r3,b2
		*g    = _mm_slli_si128(*g, 8);			//b1,g1, 0, 0
		*g    = _mm_unpackhi_epi64(*g, temp);	//g2,r2,b1,g1
}

/* convert 4-channel RGBA to 4-planar format */
SSP_FORCEINLINE 
void ssp_convert_4c_4p_epi8_SSE2( __m128i *rgba1, __m128i *rgba2, __m128i *rgba3, __m128i *rgba4 )
{
		__m128i temp1,temp2;

		temp1 = _mm_unpacklo_epi8(*rgba1, *rgba3);			// a9, a1, b9, b1, g9, g1, r9, r1, a8, a0, b8, b0, g8, g0, r8, r0
		*rgba1 = _mm_unpackhi_epi8(*rgba1, *rgba3);			//a11, a3,b11, b3,g11, g3,r11, r3,a10, a2,b10, b2,g10, g2,r10, r2
		*rgba3 = _mm_unpacklo_epi8(*rgba2, *rgba4);			//a13, a5,b13, b5,g13, g5,r13, r5,a12, a4,b12, b4,g12, g4,r12, r4
		temp2 = _mm_unpackhi_epi8(*rgba2, *rgba4);			//a15, a7,b15, b7,g15, g7,r15, r7,a14, a6,b14, b6,g14, g6,r14, r6

		*rgba4 = _mm_unpackhi_epi8(*rgba1, temp2);			//a15,a11, a7, a3,b15,b11, b7, b3,g15,g11, g7, g3,r15,r11, r7, r3
		*rgba1 = _mm_unpacklo_epi8(*rgba1, temp2);			//a14,a10, a6, a2,b14,b10, b6, b2,g14,g10, g6, g2,r14,r10, r6, r2
		*rgba2 = _mm_unpacklo_epi8(temp1, *rgba3);			//a12, a8, a4, a0,b12, b8, b4, b0,g12, g8, g4, g0,r12, r8, r4, r0
		*rgba3 = _mm_unpackhi_epi8(temp1, *rgba3);			//a13, a9, a5, a1,b13, b9, b5, b1,g13, g9, g5, g1,r13, r9, r5, r1

		temp1 = _mm_unpacklo_epi8(*rgba3, *rgba4);			//g15,g13,g11, g9, g7, g5, g3, g1,r15,r13,r11, r9, r7, r5, r3, r1
		*rgba3 = _mm_unpackhi_epi8(*rgba3, *rgba4);			//a15,a13,a11, a9, a7, a5, a3, a1,b15,b13,b11, b9, b7, b5, b3, b1
		temp2 = _mm_unpackhi_epi8(*rgba2, *rgba1);			//a14,a12,a10, a8, a6, a4, a2, a0,b14,b12,b10, b8, b6, b4, b2, b0
		*rgba2 = _mm_unpacklo_epi8(*rgba2, *rgba1);			//g14,g12,g10, g8, g6, g4, g2, g0,r14,r12,r10, r8, r6, r4, r2, r0

		*rgba1 = _mm_unpacklo_epi8(*rgba2, temp1);			//r15,r14,r13,r12,r11,r10, r9, r8, r7, r6, r5, r4, r3, r2, r1, r0
		*rgba2 = _mm_unpackhi_epi8(*rgba2, temp1);			//g15,g14,g13,g12,g11,g10, g9, g8, g7, g6, g5, g4, g3, g2, g1, g0
		*rgba4 = _mm_unpackhi_epi8(temp2, *rgba3);			//a15,a14,a13,a12,a11,a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0
		*rgba3 = _mm_unpacklo_epi8(temp2, *rgba3);			//b15,b14,b13,b12,b11,b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
}

/* convert 4-planar RGBA to 4-channel format */
SSP_FORCEINLINE 
void ssp_convert_4p_4c_epi8_SSE2(__m128i *r,__m128i *g,__m128i *b,__m128i *a)
{
		__m128i temp1, temp2;

		temp1 = _mm_unpacklo_epi8(*r, *b);			// b7, r7, b6, r6, b5, r5, b4, r4, b3, r3, b2, r2, b1, r1, b0, r0
		*r     = _mm_unpackhi_epi8(*r, *b);         //b15,r15,b14,r14,b13,r13,b12,r12,b11,r11,b10,r10, b9, r9, b8, r8
		temp2 = _mm_unpacklo_epi8(*g, *a);			// a7, g7, a6, g6, a5, g5, a4, g4, a3, g3, a2, g2, a1, g1, a0, g0
		*g     = _mm_unpackhi_epi8(*g, *a);			//a15,g15,a14,g14,a13,g13,a12,g12,a11,g11,a10,g10, a9, g9, a8, g8

		*b     = _mm_unpacklo_epi8(*r, *g);			//a11,b11,g11,r11,a10,b10,g10,r10, a9, b9, g9, r9, a8, b8, g8, r8
		*a     = _mm_unpackhi_epi8(*r, *g);			//a16,b16,g16,r16,a15,b15,g15,r15,a14, b1,g14,r14,a13,b13,g12,r12
		*r     = _mm_unpacklo_epi8(temp1, temp2);	// a3, b3, g3, r3, a2, b2, g2, r2, a1, b1, g1, r1, a0, b0, g0, r0
		*g     = _mm_unpackhi_epi8(temp1, temp2);	// a7, b7, g7, r7, a6, b6, g6, r6, a5, b5, g5, r5, a4, b4, g4, r4
}

SSP_FORCEINLINE 
void ssp_convert_4c_4p_epi16_SSE2(__m128i *rgba1,__m128i *rgba2,__m128i *rgba3,__m128i *rgba4)
{
		__m128i temp1, temp2;

		temp1  = _mm_unpacklo_epi16(*rgba1, *rgba3);		//a4,a0,b4,b0,g4,g0,r4,r0
		*rgba1  = _mm_unpackhi_epi16(*rgba1, *rgba3);		//a5,a1,b5,b1,g5,g1,r5,r1
		*rgba3  = _mm_unpacklo_epi16(*rgba2, *rgba4);		//a6,a2,b6,b2,g6,g2,r6,r2
		*rgba2  = _mm_unpackhi_epi16(*rgba2, *rgba4);		//a7,a3,b7,b3,g7,g3,r7,r3

		*rgba4  = _mm_unpackhi_epi16(*rgba1, *rgba2);		//a7,a5,a3,a1,b7,b5,b3,b1
		*rgba1  = _mm_unpacklo_epi16(*rgba1, *rgba2);		//g7,g5,g3,g1,r7,r5,r3,r1
		temp2  = _mm_unpacklo_epi16(temp1, *rgba3);			//g6,g4,g2,g0,r6,r4,r2,r0
		temp1  = _mm_unpackhi_epi16(temp1, *rgba3);			//a6,a4,a2,a0,b6,b4,b2,b0

		*rgba3  = _mm_unpacklo_epi16(temp1, *rgba4);		//b7,b6,b5,b4,b3,b2,b1,b0
		*rgba4  = _mm_unpackhi_epi16(temp1, *rgba4);		//a7,a6,a5,a4,a3,a2,a1,a0
		*rgba2  = _mm_unpackhi_epi16(temp2, *rgba1);		//g7,g6,g5,g4,g3,g2,g1,g0
		*rgba1  = _mm_unpacklo_epi16(temp2, *rgba1);		//r7,r6,r5,r4,r3,r2,r1,r0
}

SSP_FORCEINLINE 
void ssp_convert_4p_4c_epi16_SSE2(__m128i *r,__m128i *g,__m128i *b,__m128i *a)
{
		__m128i temp1, temp2;

		temp1 = _mm_unpacklo_epi16(*r, *b);			//b3,r3,b2,r2,b1,r1,b0,r0
		*r     = _mm_unpackhi_epi16(*r, *b);        //b7,r7,b6,r6,b5,r5,b4,r4
		temp2 = _mm_unpacklo_epi16(*g, *a);			//a3,g3,a2,g2,a1,g1,a0,g0
		*g     = _mm_unpackhi_epi16(*g, *a);		//a7,g7,a6,g6,a5,g5,a4,g4

		*b     = _mm_unpacklo_epi16(*r, *g);		//a5,b5,g5,r5,a4,b4,g4,r4
		*a     = _mm_unpackhi_epi16(*r, *g);		//a7,b7,g7,r7,a6,b6,g6,r6
		*r     = _mm_unpacklo_epi16(temp1, temp2);	//a1,b1,g1,r1,a0,b0,g0,r0
		*g     = _mm_unpackhi_epi16(temp1, temp2);	//a3,b3,g3,r3,a2,b2,g2,r2
}

SSP_FORCEINLINE 
void ssp_convert_4c_4p_epi32_SSE2(__m128i *rgba1,__m128i *rgba2,__m128i *rgba3, __m128i *rgba4)
{
		__m128i temp1, temp2;

		temp1  = _mm_unpacklo_epi32(*rgba1, *rgba3);		//g2,g0,r2,r0
		*rgba1  = _mm_unpackhi_epi32(*rgba1, *rgba3);		//a2,a0,b2,b0
		temp2  = _mm_unpacklo_epi32(*rgba2, *rgba4);		//g3,g1,r3,r1
		*rgba2  = _mm_unpackhi_epi32(*rgba2, *rgba4);		//a3,a1,b3,b1

		*rgba4  = _mm_unpackhi_epi32(*rgba1, *rgba2);		//a3,a2,a1,a0
		*rgba3  = _mm_unpacklo_epi32(*rgba1, *rgba2);		//b3,b2,b1,b0
		*rgba1  = _mm_unpacklo_epi32(temp1, temp2);			//r3,r2,r1,r0
		*rgba2  = _mm_unpackhi_epi32(temp1, temp2);			//g3,g2,g1,g0
}

SSP_FORCEINLINE 
void ssp_convert_4p_4c_epi32_SSE2(__m128i *r,__m128i *g,__m128i *b,__m128i *a)
{
		__m128i temp1, temp2;

		temp1 = _mm_unpacklo_epi32(*r, *b);			//b1,r1,b0,r0
		*r     = _mm_unpackhi_epi32(*r, *b);        //b3,r3,b2,r2
		temp2 = _mm_unpacklo_epi32(*g, *a);			//a1,g1,a0,g0
		*g     = _mm_unpackhi_epi32(*g, *a);		//a3,g3,a2,g2

		*b     = _mm_unpacklo_epi32(*r, *g);		//a2,b2,g2,r2
		*a     = _mm_unpackhi_epi32(*r, *g);		//a3,b3,g3,r3
		*r     = _mm_unpacklo_epi32(temp1, temp2);	//a0,b0,g0,r0
		*g     = _mm_unpackhi_epi32(temp1, temp2);	//a1,b1,g1,r1
}


/** @} 
 *  @}
 */

#endif // __SSEPLUS_CONVERT_SSE2_H__
