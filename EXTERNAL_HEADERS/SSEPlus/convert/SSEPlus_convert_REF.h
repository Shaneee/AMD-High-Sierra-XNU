//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_CONVERT_REF_H__
#define __SSEPLUS_CONVERT_REF_H__


/** @addtogroup supplimental_REF   
 *  @{ 
 *  @name Convert Operations
 */


//a: 9  6 3 0    3  2  1 0               
//b: 10 7 4 1 -> 7  6  5 4       
//c: 11 8 5 2    11 10 9 8
SSP_FORCEINLINE
void ssp_convert_reverse_transpose_REF( __m128i *a, __m128i *b, __m128i *c )
{
    ssp_m128 Ai, Ao, Bi, Bo, Ci, Co;
    Ai.i = *a;   
    Bi.i = *b;   
    Ci.i = *c;   

    Ao.u32[ 0 ] = Ai.u32[ 0 ];
    Ao.u32[ 1 ] = Bi.u32[ 0 ];
    Ao.u32[ 2 ] = Ci.u32[ 0 ];
    Ao.u32[ 3 ] = Ai.u32[ 1 ];

    Bo.u32[ 0 ] = Bi.u32[ 1 ];
    Bo.u32[ 1 ] = Ci.u32[ 1 ];
    Bo.u32[ 2 ] = Ai.u32[ 2 ];
    Bo.u32[ 3 ] = Bi.u32[ 2 ];

    Co.u32[ 0 ] = Ci.u32[ 2 ];
    Co.u32[ 1 ] = Ai.u32[ 3 ];
    Co.u32[ 2 ] = Bi.u32[ 3 ];
    Co.u32[ 3 ] = Ci.u32[ 3 ];

    *a = Ao.i;
    *b = Bo.i;
    *c = Co.i;
}


SSP_FORCEINLINE 
void ssp_convert_3c_3p_epi8_REF( __m128i *rgb1, __m128i *rgb2, __m128i *rgb3)
{
    ssp_m128 RGB1, RGB2, RGB3;
    ssp_m128 R,G,B;

    RGB1.i = *rgb1;
    RGB2.i = *rgb2;
    RGB3.i = *rgb3;
    
    R.u8[0 ] = RGB1.u8[0 ];  //RED
    R.u8[1 ] = RGB1.u8[3 ];
    R.u8[2 ] = RGB1.u8[6 ];
    R.u8[3 ] = RGB1.u8[9 ];
    R.u8[4 ] = RGB1.u8[12];
    R.u8[5 ] = RGB1.u8[15];
    R.u8[6 ] = RGB2.u8[2 ];
    R.u8[7 ] = RGB2.u8[5 ];
    R.u8[8 ] = RGB2.u8[8 ];
    R.u8[9 ] = RGB2.u8[11];
    R.u8[10] = RGB2.u8[14];
    R.u8[11] = RGB3.u8[1 ];
    R.u8[12] = RGB3.u8[4 ];
    R.u8[13] = RGB3.u8[7 ];
    R.u8[14] = RGB3.u8[10];
    R.u8[15] = RGB3.u8[13];

    G.u8[0 ] = RGB1.u8[1 ];  //GREEN
    G.u8[1 ] = RGB1.u8[4 ];
    G.u8[2 ] = RGB1.u8[7 ];
    G.u8[3 ] = RGB1.u8[10];
    G.u8[4 ] = RGB1.u8[13];
    G.u8[5 ] = RGB2.u8[0 ];
    G.u8[6 ] = RGB2.u8[3 ];
    G.u8[7 ] = RGB2.u8[6 ];
    G.u8[8 ] = RGB2.u8[9 ];
    G.u8[9 ] = RGB2.u8[12];
    G.u8[10] = RGB2.u8[15];
    G.u8[11] = RGB3.u8[2 ];
    G.u8[12] = RGB3.u8[5 ];
    G.u8[13] = RGB3.u8[8 ];
    G.u8[14] = RGB3.u8[11];
    G.u8[15] = RGB3.u8[14];

    B.u8[0 ] = RGB1.u8[2 ];  //BLUE
    B.u8[1 ] = RGB1.u8[5 ];
    B.u8[2 ] = RGB1.u8[8 ];
    B.u8[3 ] = RGB1.u8[11];
    B.u8[4 ] = RGB1.u8[14];
    B.u8[5 ] = RGB2.u8[1 ];
    B.u8[6 ] = RGB2.u8[4 ];
    B.u8[7 ] = RGB2.u8[7 ];
    B.u8[8 ] = RGB2.u8[10];
    B.u8[9 ] = RGB2.u8[13];
    B.u8[10] = RGB3.u8[0 ];
    B.u8[11] = RGB3.u8[3 ];
    B.u8[12] = RGB3.u8[6 ];
    B.u8[13] = RGB3.u8[9 ];
    B.u8[14] = RGB3.u8[12];
    B.u8[15] = RGB3.u8[15];
   

    *rgb1 = R.i;
    *rgb2 = G.i;
    *rgb3 = B.i;   
}


SSP_FORCEINLINE
void ssp_convert_3p_3c_epi8_REF( __m128i *r, __m128i *g, __m128i *b )
{
    ssp_m128 R,G,B;
    ssp_m128 RGB1, RGB2, RGB3;
    
    R.i = *r;
    G.i = *g;
    B.i = *b;

    RGB1.u8[0 ] = R.u8[0 ];  
    RGB1.u8[1 ] = G.u8[0 ];
    RGB1.u8[2 ] = B.u8[0 ];
    RGB1.u8[3 ] = R.u8[1 ];
    RGB1.u8[4 ] = G.u8[1 ];
    RGB1.u8[5 ] = B.u8[1 ];
    RGB1.u8[6 ] = R.u8[2 ];
    RGB1.u8[7 ] = G.u8[2 ];
    RGB1.u8[8 ] = B.u8[2 ];
    RGB1.u8[9 ] = R.u8[3 ];
    RGB1.u8[10] = G.u8[3 ];
    RGB1.u8[11] = B.u8[3 ];
    RGB1.u8[12] = R.u8[4 ];
    RGB1.u8[13] = G.u8[4 ];
    RGB1.u8[14] = B.u8[4 ];
    RGB1.u8[15] = R.u8[5 ];

    RGB2.u8[0 ] = G.u8[5 ];  
    RGB2.u8[1 ] = B.u8[5 ];
    RGB2.u8[2 ] = R.u8[6 ];
    RGB2.u8[3 ] = G.u8[6 ];
    RGB2.u8[4 ] = B.u8[6 ];
    RGB2.u8[5 ] = R.u8[7 ];
    RGB2.u8[6 ] = G.u8[7 ];
    RGB2.u8[7 ] = B.u8[7 ];
    RGB2.u8[8 ] = R.u8[8 ];
    RGB2.u8[9 ] = G.u8[8 ];
    RGB2.u8[10] = B.u8[8 ];
    RGB2.u8[11] = R.u8[9 ];
    RGB2.u8[12] = G.u8[9 ];
    RGB2.u8[13] = B.u8[9 ];
    RGB2.u8[14] = R.u8[10];
    RGB2.u8[15] = G.u8[10];

    RGB3.u8[0 ] = B.u8[10];  
    RGB3.u8[1 ] = R.u8[11];
    RGB3.u8[2 ] = G.u8[11];
    RGB3.u8[3 ] = B.u8[11];
    RGB3.u8[4 ] = R.u8[12];
    RGB3.u8[5 ] = G.u8[12];
    RGB3.u8[6 ] = B.u8[12];
    RGB3.u8[7 ] = R.u8[13];
    RGB3.u8[8 ] = G.u8[13];
    RGB3.u8[9 ] = B.u8[13];
    RGB3.u8[10] = R.u8[14];
    RGB3.u8[11] = G.u8[14];
    RGB3.u8[12] = B.u8[14];
    RGB3.u8[13] = R.u8[15];
    RGB3.u8[14] = G.u8[15];
    RGB3.u8[15] = B.u8[15];

    *r = RGB1.i;
    *g = RGB2.i;
    *b = RGB3.i;
}

SSP_FORCEINLINE 
void ssp_convert_3c_3p_epi16_REF(__m128i *rgb1,__m128i *rgb2,__m128i *rgb3)
{
    ssp_m128 trgb1, trgb2, trgb3;
    ssp_m128 r, g, b;
    trgb1.i = *rgb1;
    trgb2.i = *rgb2;
    trgb3.i = *rgb3;

    r.s16[0] = trgb1.s16[0];
    r.s16[1] = trgb1.s16[3];
    r.s16[2] = trgb1.s16[6];
    r.s16[3] = trgb2.s16[1];
    r.s16[4] = trgb2.s16[4];
    r.s16[5] = trgb2.s16[7];
    r.s16[6] = trgb3.s16[2];
    r.s16[7] = trgb3.s16[5];

    g.s16[0] = trgb1.s16[1];
    g.s16[1] = trgb1.s16[4];
    g.s16[2] = trgb1.s16[7];
    g.s16[3] = trgb2.s16[2];
    g.s16[4] = trgb2.s16[5];
    g.s16[5] = trgb3.s16[0];
    g.s16[6] = trgb3.s16[3];
    g.s16[7] = trgb3.s16[6];

    b.s16[0] = trgb1.s16[2];
    b.s16[1] = trgb1.s16[5];
    b.s16[2] = trgb2.s16[0];
    b.s16[3] = trgb2.s16[3];
    b.s16[4] = trgb2.s16[6];
    b.s16[5] = trgb3.s16[1];
    b.s16[6] = trgb3.s16[4];
    b.s16[7] = trgb3.s16[7];

	*rgb1 = r.i;
	*rgb2 = g.i;
	*rgb3 = b.i;
}

SSP_FORCEINLINE 
void ssp_convert_3p_3c_epi16_REF(__m128i *r,__m128i *g,__m128i *b)
{
    ssp_m128 rgb1, rgb2, rgb3;
    ssp_m128 tr, tg, tb;
    tr.i = *r;
    tg.i = *g;
    tb.i = *b;

    rgb1.s16[0] = tr.s16[0];
    rgb1.s16[3] = tr.s16[1];
    rgb1.s16[6] = tr.s16[2];
    rgb2.s16[1] = tr.s16[3];
    rgb2.s16[4] = tr.s16[4];
    rgb2.s16[7] = tr.s16[5];
    rgb3.s16[2] = tr.s16[6];
    rgb3.s16[5] = tr.s16[7];

    rgb1.s16[1] = tg.s16[0];
    rgb1.s16[4] = tg.s16[1];
    rgb1.s16[7] = tg.s16[2];
    rgb2.s16[2] = tg.s16[3];
    rgb2.s16[5] = tg.s16[4];
    rgb3.s16[0] = tg.s16[5];
    rgb3.s16[3] = tg.s16[6];
    rgb3.s16[6] = tg.s16[7];

    rgb1.s16[2] = tb.s16[0];
    rgb1.s16[5] = tb.s16[1];
    rgb2.s16[0] = tb.s16[2];
    rgb2.s16[3] = tb.s16[3];
    rgb2.s16[6] = tb.s16[4];
    rgb3.s16[1] = tb.s16[5];
    rgb3.s16[4] = tb.s16[6];
    rgb3.s16[7] = tb.s16[7];

	*r = rgb1.i;
	*g = rgb2.i;
	*b = rgb3.i;
}

SSP_FORCEINLINE 
void ssp_convert_3c_3p_epi32_REF(__m128i *rgb1,__m128i *rgb2,__m128i *rgb3)
{
    ssp_m128 trgb1, trgb2, trgb3;
    ssp_m128 r, g, b;
	trgb1.i = *rgb1;
	trgb2.i = *rgb2;
	trgb3.i = *rgb3;

    r.s32[0] = trgb1.s32[0];
    r.s32[1] = trgb1.s32[3];
    r.s32[2] = trgb2.s32[2];
    r.s32[3] = trgb3.s32[1];

    g.s32[0] = trgb1.s32[1];
    g.s32[1] = trgb2.s32[0];
    g.s32[2] = trgb2.s32[3];
    g.s32[3] = trgb3.s32[2];

    b.s32[0] = trgb1.s32[2];
    b.s32[1] = trgb2.s32[1];
    b.s32[2] = trgb3.s32[0];
    b.s32[3] = trgb3.s32[3];

	*rgb1 = r.i;
	*rgb2 = g.i;
	*rgb3 = b.i;
}

SSP_FORCEINLINE 
void ssp_convert_3p_3c_epi32_REF(__m128i *r,__m128i *g,__m128i *b)
{
    ssp_m128 tr, tg, tb;
    ssp_m128 rgb1, rgb2, rgb3;

	tr.i = *r;
	tg.i = *g;
	tb.i = *b;

    rgb1.s32[0] = tr.s32[0];
    rgb1.s32[3] = tr.s32[1];
    rgb2.s32[2] = tr.s32[2];
    rgb3.s32[1] = tr.s32[3];

    rgb1.s32[1] = tg.s32[0];
    rgb2.s32[0] = tg.s32[1];
    rgb2.s32[3] = tg.s32[2];
    rgb3.s32[2] = tg.s32[3];

    rgb1.s32[2] = tb.s32[0];
    rgb2.s32[1] = tb.s32[1];
    rgb3.s32[0] = tb.s32[2];
    rgb3.s32[3] = tb.s32[3];

	*r = rgb1.i;
	*g = rgb2.i;
	*b = rgb3.i;
}

/* convert 4-channel RGBA to 4-planar format */
SSP_FORCEINLINE 
void ssp_convert_4c_4p_epi8_REF( __m128i *rgba1, __m128i *rgba2, __m128i *rgba3, __m128i *rgba4 )
{
	int n;
	ssp_m128 trgba1, trgba2, trgba3, trgba4;
	ssp_m128 r, g, b, a;

	trgba1.i = *rgba1;
	trgba2.i = *rgba2;
	trgba3.i = *rgba3;
	trgba4.i = *rgba4;

    for( n = 0; n < 4; n++ )
    {
        r.s8[0+n] = trgba1.s8[4*n];
        r.s8[4+n] = trgba2.s8[4*n];
        r.s8[8+n] = trgba3.s8[4*n];
        r.s8[12+n] = trgba4.s8[4*n];

        g.s8[0+n] = trgba1.s8[4*n+1];
        g.s8[4+n] = trgba2.s8[4*n+1];
        g.s8[8+n] = trgba3.s8[4*n+1];
        g.s8[12+n] = trgba4.s8[4*n+1];

        b.s8[0+n] = trgba1.s8[4*n+2];
        b.s8[4+n] = trgba2.s8[4*n+2];
        b.s8[8+n] = trgba3.s8[4*n+2];
        b.s8[12+n] = trgba4.s8[4*n+2];

        a.s8[0+n] = trgba1.s8[4*n+3];
        a.s8[4+n] = trgba2.s8[4*n+3];
        a.s8[8+n] = trgba3.s8[4*n+3];
        a.s8[12+n] = trgba4.s8[4*n+3];
    }

	*rgba1 = r.i;
	*rgba2 = g.i;
	*rgba3 = b.i;
	*rgba4 = a.i;
}

/* convert 4-planar RGBA to 4-channel format */
SSP_FORCEINLINE 
void ssp_convert_4p_4c_epi8_REF(__m128i *r,__m128i *g,__m128i *b,__m128i *a)
{
	int n;
    ssp_m128 tr, tg, tb, ta;
    ssp_m128 rgba1, rgba2, rgba3, rgba4;
	tr.i = *r;
	tg.i = *g;
	tb.i = *b;
	ta.i = *a;

    for( n = 0; n < 4; n++ )
    {
        rgba1.s8[4*n] = tr.s8[0+n];
        rgba2.s8[4*n] = tr.s8[4+n];
        rgba3.s8[4*n] = tr.s8[8+n];
        rgba4.s8[4*n] = tr.s8[12+n];

        rgba1.s8[4*n+1] = tg.s8[0+n];
        rgba2.s8[4*n+1] = tg.s8[4+n];
        rgba3.s8[4*n+1] = tg.s8[8+n];
        rgba4.s8[4*n+1] = tg.s8[12+n];

        rgba1.s8[4*n+2] = tb.s8[0+n];
        rgba2.s8[4*n+2] = tb.s8[4+n];
        rgba3.s8[4*n+2] = tb.s8[8+n];
        rgba4.s8[4*n+2] = tb.s8[12+n];

        rgba1.s8[4*n+3] = ta.s8[0+n];
        rgba2.s8[4*n+3] = ta.s8[4+n];
        rgba3.s8[4*n+3] = ta.s8[8+n];
        rgba4.s8[4*n+3] = ta.s8[12+n];
    }

	*r = rgba1.i;
	*g = rgba2.i;
	*b = rgba3.i;
	*a = rgba4.i;
}

SSP_FORCEINLINE 
void ssp_convert_4c_4p_epi16_REF(__m128i *rgba1,__m128i *rgba2,__m128i *rgba3,__m128i *rgba4)
{
	int n;
	ssp_m128 trgba1, trgba2, trgba3, trgba4;
	ssp_m128 r, g, b, a;

	trgba1.i = *rgba1;
	trgba2.i = *rgba2;
	trgba3.i = *rgba3;
	trgba4.i = *rgba4;

    for( n = 0; n < 2; n++ )
    {
        r.s16[0+n] = trgba1.s16[4*n];
        r.s16[2+n] = trgba2.s16[4*n];
        r.s16[4+n] = trgba3.s16[4*n];
        r.s16[6+n] = trgba4.s16[4*n];

        g.s16[0+n] = trgba1.s16[4*n+1];
        g.s16[2+n] = trgba2.s16[4*n+1];
        g.s16[4+n] = trgba3.s16[4*n+1];
        g.s16[6+n] = trgba4.s16[4*n+1];

        b.s16[0+n] = trgba1.s16[4*n+2];
        b.s16[2+n] = trgba2.s16[4*n+2];
        b.s16[4+n] = trgba3.s16[4*n+2];
        b.s16[6+n] = trgba4.s16[4*n+2];

        a.s16[0+n] = trgba1.s16[4*n+3];
        a.s16[2+n] = trgba2.s16[4*n+3];
        a.s16[4+n] = trgba3.s16[4*n+3];
        a.s16[6+n] = trgba4.s16[4*n+3];
    }

	*rgba1 = r.i;
	*rgba2 = g.i;
	*rgba3 = b.i;
	*rgba4 = a.i;
}

SSP_FORCEINLINE 
void ssp_convert_4p_4c_epi16_REF(__m128i *r,__m128i *g,__m128i *b,__m128i *a)
{
	int n;
    ssp_m128 tr, tg, tb, ta;
    ssp_m128 rgba1, rgba2, rgba3, rgba4;
	tr.i = *r;
	tg.i = *g;
	tb.i = *b;
	ta.i = *a;

    for( n = 0; n < 2; n++ )
    {
        rgba1.s16[4*n] = tr.s16[0+n];
        rgba2.s16[4*n] = tr.s16[2+n];
        rgba3.s16[4*n] = tr.s16[4+n];
        rgba4.s16[4*n] = tr.s16[6+n];

        rgba1.s16[4*n+1] = tg.s16[0+n];
        rgba2.s16[4*n+1] = tg.s16[2+n];
        rgba3.s16[4*n+1] = tg.s16[4+n];
        rgba4.s16[4*n+1] = tg.s16[6+n];

        rgba1.s16[4*n+2] = tb.s16[0+n];
        rgba2.s16[4*n+2] = tb.s16[2+n];
        rgba3.s16[4*n+2] = tb.s16[4+n];
        rgba4.s16[4*n+2] = tb.s16[6+n];

        rgba1.s16[4*n+3] = ta.s16[0+n];
        rgba2.s16[4*n+3] = ta.s16[2+n];
        rgba3.s16[4*n+3] = ta.s16[4+n];
        rgba4.s16[4*n+3] = ta.s16[6+n];
    }

	*r = rgba1.i;
	*g = rgba2.i;
	*b = rgba3.i;
	*a = rgba4.i;
}

SSP_FORCEINLINE 
void ssp_convert_4c_4p_epi32_REF(__m128i *rgba1,__m128i *rgba2,__m128i *rgba3, __m128i *rgba4)
{
	ssp_m128 trgba1, trgba2, trgba3, trgba4;
	ssp_m128 r, g, b, a;

	trgba1.i = *rgba1;
	trgba2.i = *rgba2;
	trgba3.i = *rgba3;
	trgba4.i = *rgba4;

    r.s32[0] = trgba1.s32[0];
    r.s32[1] = trgba2.s32[0];
    r.s32[2] = trgba3.s32[0];
    r.s32[3] = trgba4.s32[0];

    g.s32[0] = trgba1.s32[1];
    g.s32[1] = trgba2.s32[1];
    g.s32[2] = trgba3.s32[1];
    g.s32[3] = trgba4.s32[1];

    b.s32[0] = trgba1.s32[2];
    b.s32[1] = trgba2.s32[2];
    b.s32[2] = trgba3.s32[2];
    b.s32[3] = trgba4.s32[2];

    a.s32[0] = trgba1.s32[3];
    a.s32[1] = trgba2.s32[3];
    a.s32[2] = trgba3.s32[3];
    a.s32[3] = trgba4.s32[3];

	*rgba1 = r.i;
	*rgba2 = g.i;
	*rgba3 = b.i;
	*rgba4 = a.i;
}

SSP_FORCEINLINE 
void ssp_convert_4p_4c_epi32_REF(__m128i *r,__m128i *g,__m128i *b,__m128i *a)
{
    ssp_m128 tr, tg, tb, ta;
    ssp_m128 rgba1, rgba2, rgba3, rgba4;
	tr.i = *r;
	tg.i = *g;
	tb.i = *b;
	ta.i = *a;

    rgba1.s32[0] = tr.s32[0];
    rgba2.s32[0] = tr.s32[1];
    rgba3.s32[0] = tr.s32[2];
    rgba4.s32[0] = tr.s32[3];

    rgba1.s32[1] = tg.s32[0];
    rgba2.s32[1] = tg.s32[1];
    rgba3.s32[1] = tg.s32[2];
    rgba4.s32[1] = tg.s32[3];

    rgba1.s32[2] = tb.s32[0];
    rgba2.s32[2] = tb.s32[1];
    rgba3.s32[2] = tb.s32[2];
    rgba4.s32[2] = tb.s32[3];

    rgba1.s32[3] = ta.s32[0];
    rgba2.s32[3] = ta.s32[1];
    rgba3.s32[3] = ta.s32[2];
    rgba4.s32[3] = ta.s32[3];

	*r = rgba1.i;
	*g = rgba2.i;
	*b = rgba3.i;
	*a = rgba4.i;
}

/** @} 
 *  @}
 */



#endif // __SSEPLUS_CONVERT_REF_H__
