//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_EMULATION_COMPS_SSE2_H__
#define __SSEPLUS_EMULATION_COMPS_SSE2_H__

#include "../SSEPlus_SSE2.h"


/** @addtogroup emulated_SSE2   
 *  @{ 
 *  @name SSE[3,4A,...,5] implemented in SSE2
 */

//----------------------------------------
// COMEQ (Condition 0)
//----------------------------------------

/** \SSE5{SSE2,_mm_comeq_epi16, pcomw } */ 
SSP_FORCEINLINE __m128i ssp_comeq_epi16_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpeq_epi16( a, b );
    return a;   
}

/** \SSE5{SSE2,_mm_comeq_epi32, pcomd } */  
SSP_FORCEINLINE __m128i ssp_comeq_epi32_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpeq_epi32( a, b );
    return a;   
}

/** \SSE5{SSE2,_mm_comeq_epi64, pcomq } */  
SSP_FORCEINLINE __m128i ssp_comeq_epi64_SSE2(__m128i a, __m128i b)
{
    ssp_m128 A, B;
    A.i = a;
    B.i = b;
    A.i = _mm_cmpeq_epi32( A.i, B.i );  //  A0=B0, A1=B1,  A2=B2, A3=B3
    B.i = _mm_slli_epi64 ( A.i, 32 );   //  A1=B1,     0,  A3=B3,     0
    A.i = _mm_and_si128  ( A.i, B.i );  //  A0=B0      x,  A2=B2,     x
                                        //& A1=B1,        &A3=B3  

    A.i = _mm_shuffle_epi32( A.i, _MM_SHUFFLE(3,3,1,1) );        
    return A.i;
}

/** \SSE5{SSE2,_mm_comeq_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comeq_epi8_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpeq_epi8( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comeq_epu16, pcomuw } */  
SSP_FORCEINLINE __m128i ssp_comeq_epu16_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpeq_epi16( a, b );
    return a; 
}

/** \SSE5{SSE2,_mm_comeq_epu32, pcomud } */  
SSP_FORCEINLINE __m128i ssp_comeq_epu32_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpeq_epi32( a, b );
    return a; 
}

/** \SSE5{SSE2,_mm_comeq_epu64, pcomuq } */  
SSP_FORCEINLINE __m128i ssp_comeq_epu64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epi64_SSE2( a, b );  
    return a;
}

/** \SSE5{SSE2,_mm_comeq_epu8, pcomub } */ 
SSP_FORCEINLINE __m128i ssp_comeq_epu8_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpeq_epi8( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comeq_pd, compd }*/ 
SSP_FORCEINLINE __m128d ssp_comeq_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpeq_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comeq_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comeq_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpeq_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comeq_sd, comsd }*/   
SSP_FORCEINLINE __m128d ssp_comeq_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpeq_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comeq_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comeq_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpeq_ss( a, b );
    return a;
}

//----------------------------------------
// COMLT (Condition 1)
//----------------------------------------

/** \SSE5{SSE2,_mm_comlt_epi16, pcomw } */  
SSP_FORCEINLINE __m128i ssp_comlt_epi16_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmplt_epi16( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_epi32, pcomd } */  
SSP_FORCEINLINE __m128i ssp_comlt_epi32_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmplt_epi32( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_epi64, pcomq } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comlt_epi64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comlt_epi64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comlt_epi8_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmplt_epi8( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_epu16, pcomuw } */  
SSP_FORCEINLINE __m128i ssp_comlt_epu16_SSE2(__m128i a, __m128i b)
{
    __m128i signMask, mask;

    mask     = _mm_cmplt_epi16( a, b );              // FFFF where a < b (signed)
    signMask = _mm_xor_si128  ( a, b );              // Signbit is 1 where signs differ 
    signMask = _mm_srai_epi16 ( signMask, 15 );      // fill all fields with sign bit     
    mask     = _mm_xor_si128  ( mask, signMask );    // Invert output where signs differed
    return mask;
}

/** \SSE5{SSE2,_mm_comlt_epu32, pcomud } */  
SSP_FORCEINLINE __m128i ssp_comlt_epu32_SSE2(__m128i a, __m128i b)
{
    __m128i signMask, mask;

    mask     = _mm_cmplt_epi32( a, b );              // FFFF where a < b (signed)
    signMask = _mm_xor_si128  ( a, b );              // Signbit is 1 where signs differ 
    signMask = _mm_srai_epi32 ( signMask, 31 );      // fill all fields with sign bit     
    mask     = _mm_xor_si128  ( mask, signMask );    // Invert output where signs differed
    return mask;
}

/** \SSE5{SSE2,_mm_comlt_epu64, pcomuq } */  // TODO: SSE2
SSP_FORCEINLINE __m128i ssp_comlt_epu64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comlt_epu64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_epu8, pcomub } */  
SSP_FORCEINLINE __m128i ssp_comlt_epu8_SSE2(__m128i a, __m128i b)
{
    __m128i mask = _mm_cmplt_epi8( a, b );
    a = ssp_logical_signinvert_8_SSE2( mask, a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comlt_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmplt_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comlt_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmplt_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comlt_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmplt_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comlt_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comlt_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmplt_ss( a, b );
    return a;
}

//----------------------------------------
// COMLE (Condition 2)
//----------------------------------------

/** \SSE5{SSE2,_mm_comle_epi16, pcomw } */  
SSP_FORCEINLINE __m128i ssp_comle_epi16_SSE2(__m128i a, __m128i b)
{
    __m128i c;    
    c = _mm_cmplt_epi16( a, b );
    a = _mm_cmpeq_epi16( a, b );
    a = _mm_or_si128   ( a, c );
    return a;
}

/** \SSE5{SSE2,_mm_comle_epi32, pcomd } */  
SSP_FORCEINLINE __m128i ssp_comle_epi32_SSE2(__m128i a, __m128i b)
{
    __m128i c;    
    c = _mm_cmplt_epi32( a, b );
    a = _mm_cmpeq_epi32( a, b );
    a = _mm_or_si128   ( a, c );
    return a;
}

/** \SSE5{SSE2,_mm_comle_epi64, pcomq } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comle_epi64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comle_epi64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comle_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comle_epi8_SSE2(__m128i a, __m128i b)
{
    __m128i c;    
    c = _mm_cmplt_epi8( a, b );
    a = _mm_cmpeq_epi8( a, b );
    a = _mm_or_si128  ( a, c );
    return a;
}

/** \SSE5{SSE2,_mm_comle_epu16, pcomuw } */ 
SSP_FORCEINLINE __m128i ssp_comle_epu16_SSE2(__m128i a, __m128i b)
{
    __m128i mask = ssp_comle_epi16_SSE2( a, b );
    a = ssp_logical_signinvert_16_SSE2( mask, a, b );   
    return a;
}

/** \SSE5{SSE2,_mm_comle_epu32, pcomud } */ 
SSP_FORCEINLINE __m128i ssp_comle_epu32_SSE2(__m128i a, __m128i b)
{
    __m128i mask = ssp_comle_epi32_SSE2( a, b );
    a = ssp_logical_signinvert_32_SSE2( mask, a, b );   
    return a;
}

/** \SSE5{SSE2,_mm_comle_epu64, pcomuq } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comle_epu64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comle_epu64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comle_epu8, pcomub } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comle_epu8_SSE2(__m128i a, __m128i b)
{
    a = ssp_comle_epu8_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comle_pd, compd } */ 
SSP_FORCEINLINE __m128d ssp_comle_pd_SSE2(__m128d a, __m128d b)
{
   a = _mm_cmple_pd( a, b );
   return a;
}

/** \SSE5{SSE2,_mm_comle_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comle_ps_SSE2(__m128 a, __m128 b)
{
   a = _mm_cmple_ps( a, b );
   return a;
}

/** \SSE5{SSE2,_mm_comle_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comle_sd_SSE2(__m128d a, __m128d b)
{
   a = _mm_cmple_sd( a, b );
   return a;
}

/** \SSE5{SSE2,_mm_comle_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comle_ss_SSE2(__m128 a, __m128 b)
{
   a = _mm_cmple_ss( a, b );
   return a;
}

//----------------------------------------
// COMUNORD (Condition 3)
//----------------------------------------

/** \SSE5{SSE2,_mm_comunord_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comunord_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_or_pd    ( a, b );
    a = _mm_cmpneq_pd( a, a );
    return a;   
}

/** \SSE5{SSE2,_mm_comunord_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comunord_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_or_ps    ( a, b );
    a = _mm_cmpneq_ps( a, a );
    return a;      
}

/** \SSE5{SSE2,_mm_comunord_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comunord_sd_SSE2(__m128d a, __m128d b)
{
    b = _mm_or_pd    ( a, b );
    a = _mm_cmpneq_sd( a, b );
    return a; 
}

/** \SSE5{SSE2,_mm_comunord_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comunord_ss_SSE2(__m128 a, __m128 b)
{
    b = _mm_or_ps    ( a, b );
    a = _mm_cmpneq_ss( a, b );
    return a; 
}


//----------------------------------------
// COMNEQ (Condition 4)
//----------------------------------------

/** \SSE5{SSE2,_mm_comneq_epi16, pcomw } */  
SSP_FORCEINLINE __m128i ssp_comneq_epi16_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epi16_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_epi32, pcomd } */  
SSP_FORCEINLINE __m128i ssp_comneq_epi32_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epi32_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_epi64, pcomq } */  
SSP_FORCEINLINE __m128i ssp_comneq_epi64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epi64_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comneq_epi8_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epi8_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_epu16, pcomuw } */  
SSP_FORCEINLINE __m128i ssp_comneq_epu16_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epu16_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_epu32, pcomud } */  
SSP_FORCEINLINE __m128i ssp_comneq_epu32_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epu32_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_epu64, pcomuq } */ 
SSP_FORCEINLINE __m128i ssp_comneq_epu64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epu64_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_epu8, pcomub } */  
SSP_FORCEINLINE __m128i ssp_comneq_epu8_SSE2(__m128i a, __m128i b)
{
    a = ssp_comeq_epu8_SSE2( a, b );
    a = ssp_logical_invert_si128_SSE2( a );
    return a;   
}

/** \SSE5{SSE2,_mm_comneq_pd, compd }*/ 
SSP_FORCEINLINE __m128d ssp_comneq_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpneq_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comneq_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comneq_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpneq_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comneq_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comneq_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpneq_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comneq_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comneq_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpneq_ss( a, b );
    return a;
}

//----------------------------------------
// COMNLT (Condition 5)
//----------------------------------------

/** \SSE5{SSE2,_mm_comnlt_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comnlt_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpnlt_pd( a, b );    
    return a;
}

/** \SSE5{SSE2,_mm_comnlt_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comnlt_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpnlt_ps( a, b );    
    return a;
}

/** \SSE5{SSE2,_mm_comnlt_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comnlt_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpnlt_sd( a, b );    
    return a;
}

/** \SSE5{SSE2,_mm_comnlt_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comnlt_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpnlt_ss( a, b );    
    return a;
}


//----------------------------------------
// COMNLE (Condition 6)
//----------------------------------------

/** \SSE5{SSE2,_mm_comnle_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comnle_pd_SSE2(__m128d a, __m128d b)
{    
    a = _mm_cmpnle_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comnle_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comnle_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpnle_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comnle_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comnle_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpnle_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comnle_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comnle_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpnle_ss( a, b );
    return a;
}


//----------------------------------------
// COMORD (Condition 7)
//----------------------------------------

/** \SSE5{SSE2,_mm_comord_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comord_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpord_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comord_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comord_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpord_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comord_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comord_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpord_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comord_ss, comss } */  //TODO:SSE2
SSP_FORCEINLINE __m128 ssp_comord_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpord_ss( a, b );
    return a;
}


//----------------------------------------
// COMUEQ (Condition 8)
//----------------------------------------

/** \SSE5{SSE2,_mm_comueq_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comueq_pd_SSE2(__m128d a, __m128d b)
{
    __m128d c;
    c = _mm_cmpunord_pd( a, b );
    a = _mm_cmpeq_pd   ( a, b );
    a = _mm_or_pd      ( a, c );
    return a;   
}

/** \SSE5{SSE2,_mm_comueq_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comueq_ps_SSE2(__m128 a, __m128 b)
{
    __m128 c;
    c = _mm_cmpunord_ps( a, b );
    a = _mm_cmpeq_ps   ( a, b );
    a = _mm_or_ps      ( a, c );
    return a;   
}

/** \SSE5{SSE2,_mm_comueq_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comueq_sd_SSE2(__m128d a, __m128d b)
{
    __m128d c;
    c = _mm_cmpunord_sd( a, b );
    b = _mm_cmpeq_sd   ( a, b );
    b = _mm_or_pd      ( b, c );
    a = _mm_move_sd    ( a, b );
    return a;   
}

/** \SSE5{SSE2,_mm_comueq_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comueq_ss_SSE2(__m128 a, __m128 b)
{
    __m128 c;
    c = _mm_cmpunord_ss( a, b );
    b = _mm_cmpeq_ss   ( a, b );
    b = _mm_or_ps      ( a, c );
    a = _mm_move_ss    ( a, b );
    return a;   
}


//----------------------------------------
// COMNGE (Condition 9)
//----------------------------------------

/** \SSE5{SSE2,_mm_comnge_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comnge_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpnge_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comnge_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comnge_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpnge_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comnge_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comnge_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpnge_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comnge_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comnge_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpnge_ss( a, b );
    return a;
}


//----------------------------------------
// COMNGT (Condition 10)
//----------------------------------------

/** \SSE5{SSE2,_mm_comngt_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comngt_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpngt_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comngt_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comngt_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpngt_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comngt_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comngt_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpngt_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comngt_ss, comps } */  
SSP_FORCEINLINE __m128 ssp_comngt_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpngt_ss( a, b );
    return a;
}


//----------------------------------------
// COMFALSE (Condition 11)
//----------------------------------------

/** \SSE5{SSE2,_mm_comfalse_epi16, pcomw } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epi16_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_epi32, pcomd } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epi32_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_epi64, pcomq } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epi64_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epi8_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_epu16, pcomuw } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epu16_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_epu32, pcomud } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epu32_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_epu64, pcomuq } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epu64_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_epu8, pcomub } */  
SSP_FORCEINLINE __m128i ssp_comfalse_epu8_SSE2(__m128i a, __m128i b)
{
	return _mm_setzero_si128();
}

/** \SSE5{SSE2,_mm_comfalse_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comfalse_pd_SSE2(__m128d a, __m128d b)
{
	return _mm_setzero_pd();
}

/** \SSE5{SSE2,_mm_comfalse_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comfalse_ps_SSE2(__m128 a, __m128 b)
{
	return _mm_setzero_ps();
}

/** \SSE5{SSE2,_mm_comfalse_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comfalse_sd_SSE2(__m128d a, __m128d b)
{
	ssp_m128 B;
	B.i = _mm_set_epi32(0xFFFFFFFF, 0xFFFFFFFF, 0, 0);
	return _mm_and_pd(a, B.d);
}

/** \SSE5{SSE2,_mm_comfalse_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comfalse_ss_SSE2(__m128 a, __m128 b)
{
	ssp_m128 B;
	B.i = _mm_set_epi32(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);
	return _mm_and_ps(a, B.f);
}


//----------------------------------------
// COMONEQ (Condition 12)
//----------------------------------------

/** \SSE5{SSE2,_mm_comoneq_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comoneq_pd_SSE2(__m128d a, __m128d b)
{
    __m128d c;
    c = _mm_cmpord_pd( a, b );
    a = _mm_cmpneq_pd( a, b );
    a = _mm_and_pd   ( a, c );
    return a;
}

/** \SSE5{SSE2,_mm_comoneq_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comoneq_ps_SSE2(__m128 a, __m128 b)
{
    __m128 c;
    c = _mm_cmpord_ps( a, b );
    a = _mm_cmpneq_ps( a, b );
    a = _mm_and_ps   ( a, c );
    return a;
}


/** \SSE5{SSE2,_mm_comoneq_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comoneq_sd_SSE2(__m128d a, __m128d b)
{
    __m128d c;
    c = _mm_cmpord_pd( a, b );
    b = _mm_cmpneq_pd( a, b );
    b = _mm_and_pd   ( b, c );
    a = _mm_move_sd  ( a, b );
    return a;   
}

/** \SSE5{SSE2,_mm_comoneq_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comoneq_ss_SSE2(__m128 a, __m128 b)
{
    __m128 c;
    c = _mm_cmpord_ps( a, b );
    b = _mm_cmpneq_ps( a, b );
    b = _mm_and_ps   ( b, c );
    a = _mm_move_ss  ( a, b );
    return a; 
}


//----------------------------------------
// COMGE (Condition 13)
//----------------------------------------

/** \SSE5{SSE2,_mm_comge_epi16, pcomw } */  
SSP_FORCEINLINE __m128i ssp_comge_epi16_SSE2(__m128i a, __m128i b)
{
    __m128i c;
    c = _mm_cmpgt_epi16( a, b );
    a = _mm_cmpeq_epi16( a, b );
    a = _mm_or_si128  ( a, c );
    return a;
}

/** \SSE5{SSE2,_mm_comge_epi32, pcomd } */  
SSP_FORCEINLINE __m128i ssp_comge_epi32_SSE2(__m128i a, __m128i b)
{
    __m128i c;
    c = _mm_cmpgt_epi32( a, b );
    a = _mm_cmpeq_epi32( a, b );
    a = _mm_or_si128   ( a, c );
    return a;
}

/** \SSE5{SSE2,_mm_comge_epi64, pcomq } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comge_epi64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comge_epi64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comge_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comge_epi8_SSE2(__m128i a, __m128i b)
{
    __m128i c;
    c = _mm_cmpgt_epi8( a, b );
    a = _mm_cmpeq_epi8( a, b );
    a = _mm_or_si128  ( a, c );
    return a;
}


/** \SSE5{SSE2,_mm_comge_epu16, pcomuw } */  
SSP_FORCEINLINE __m128i ssp_comge_epu16_SSE2(__m128i a, __m128i b)
{
    __m128i mask;
    mask = ssp_comge_epi16_SSE2( a, b );         // FFFF where a < b (signed)
    mask = ssp_logical_signinvert_16_SSE2( mask, a, b );
    return mask;
}

/** \SSE5{SSE2,_mm_comge_epu32, pcomud } */  
SSP_FORCEINLINE __m128i ssp_comge_epu32_SSE2(__m128i a, __m128i b)
{
    __m128i mask;
    mask = ssp_comge_epi32_SSE2( a, b );         // FFFF where a < b (signed)
    mask = ssp_logical_signinvert_32_SSE2( mask, a, b );
    return mask;
}

/** \SSE5{SSE2,_mm_comge_epu64, pcomuq } */  //TODO: SSE2
SSP_FORCEINLINE __m128i ssp_comge_epu64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comge_epu64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comge_epu8, pcomub } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comge_epu8_SSE2(__m128i a, __m128i b)
{
    a = ssp_comge_epu8_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comge_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comge_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpge_pd( a, b );
    return a;    
}

/** \SSE5{SSE2,_mm_comge_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comge_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpge_ps( a, b );
    return a;   
}

/** \SSE5{SSE2,_mm_comge_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comge_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpge_sd( a, b );
    return a;   
}

/** \SSE5{SSE2,_mm_comge_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comge_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpge_ss( a, b );
    return a;   
}


//----------------------------------------
// COMGT (Condition 14)
//----------------------------------------

/** \SSE5{SSE2,_mm_comgt_epi16, pcomw } */ 
SSP_FORCEINLINE __m128i ssp_comgt_epi16_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpgt_epi16( a, b );
    return a;  
}

/** \SSE5{SSE2,_mm_comgt_epi32, pcomd } */ 
SSP_FORCEINLINE __m128i ssp_comgt_epi32_SSE2(__m128i a, __m128i b)
{
    a = _mm_cmpgt_epi32( a, b );
    return a;  
}

/** \SSE5{SSE2,_mm_comgt_epi64, pcomq } */  //TODO: SSE2
SSP_FORCEINLINE __m128i ssp_comgt_epi64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comgt_epi64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comgt_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comgt_epi8_SSE2(__m128i a, __m128i b)
{
     a = _mm_cmpgt_epi8( a, b );
    return a;  
}

/** \SSE5{SSE2,_mm_comgt_epu16, pcomuw } */  
SSP_FORCEINLINE __m128i ssp_comgt_epu16_SSE2(__m128i a, __m128i b)
{
    __m128i signMask, mask;

    mask     = _mm_cmpgt_epi16( a, b );              // FFFF where a > b (signed)
    signMask = _mm_xor_si128  ( a, b );              // Signbit is 1 where signs differ 
    signMask = _mm_srai_epi16 ( signMask, 15 );      // fill all fields with sign bit     
    mask     = _mm_xor_si128  ( mask, signMask );    // Invert output where signs differed
    return mask;
}

/** \SSE5{SSE2,_mm_comgt_epu32, pcomud } */ 
SSP_FORCEINLINE __m128i ssp_comgt_epu32_SSE2(__m128i a, __m128i b)
{
    __m128i signMask, mask;

    mask     = _mm_cmpgt_epi32( a, b );              // FFFF where a < b (signed)
    signMask = _mm_xor_si128  ( a, b );              // Signbit is 1 where signs differ 
    signMask = _mm_srai_epi32 ( signMask, 31 );      // fill all fields with sign bit     
    mask     = _mm_xor_si128  ( mask, signMask );    // Invert output where signs differed
    return mask;
}

/** \SSE5{SSE2,_mm_comgt_epu64, pcomuq } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comgt_epu64_SSE2(__m128i a, __m128i b)
{
    a = ssp_comgt_epu64_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comgt_epu8, pcomub } */  //TODO:SSE2
SSP_FORCEINLINE __m128i ssp_comgt_epu8_SSE2(__m128i a, __m128i b)
{
    a = ssp_comgt_epu8_REF( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comgt_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comgt_pd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpgt_pd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comgt_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comgt_ps_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpgt_ps( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comgt_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comgt_sd_SSE2(__m128d a, __m128d b)
{
    a = _mm_cmpgt_sd( a, b );
    return a;
}

/** \SSE5{SSE2,_mm_comgt_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comgt_ss_SSE2(__m128 a, __m128 b)
{
    a = _mm_cmpgt_ss( a, b );
    return a;
}


//----------------------------------------
// COMTRUE (Condition 15)
//----------------------------------------

/** \SSE5{SSE2,_mm_comtrue_epi16, pcomw } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epi16_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_epi32, pcomd } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epi32_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_epi64, pcomq } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epi64_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_epi8, pcomb } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epi8_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_epu16, pcomuw } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epu16_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_epu32, pcomud } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epu32_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_epu64, pcomuq } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epu64_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_epu8, pcomub } */  
SSP_FORCEINLINE __m128i ssp_comtrue_epu8_SSE2(__m128i a, __m128i b)
{
	return _mm_set1_epi32(0xFFFFFFFF);
}

/** \SSE5{SSE2,_mm_comtrue_pd, compd } */  
SSP_FORCEINLINE __m128d ssp_comtrue_pd_SSE2(__m128d a, __m128d b)
{
	ssp_m128 B;
	B.i = _mm_set1_epi32(0xFFFFFFFF);
	return B.d;
}

/** \SSE5{SSE2,_mm_comtrue_ps, comps } */  
SSP_FORCEINLINE __m128 ssp_comtrue_ps_SSE2(__m128 a, __m128 b)
{
	ssp_m128 B;
	B.i = _mm_set1_epi32(0xFFFFFFFF);
	return B.f;
}

/** \SSE5{SSE2,_mm_comtrue_sd, comsd } */  
SSP_FORCEINLINE __m128d ssp_comtrue_sd_SSE2(__m128d a, __m128d b)
{
	ssp_m128 B;
	B.i = _mm_set_epi32(0, 0, 0xFFFFFFFF, 0xFFFFFFFF);
	return _mm_or_pd(a, B.d);
}

/** \SSE5{SSE2,_mm_comtrue_ss, comss } */  
SSP_FORCEINLINE __m128 ssp_comtrue_ss_SSE2(__m128 a, __m128 b)
{
	ssp_m128 B;
	B.i = _mm_set_epi32(0, 0, 0, 0xFFFFFFFF);
	return _mm_or_ps(a, B.f);
}


/** @} 
 *  @}
 */


#endif // __SSEPLUS_EMULATION_COMPS_SSE2_H__
