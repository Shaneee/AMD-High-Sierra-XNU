//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __BASE_H__
#define __BASE_H__

#define __SSEPLUS_LOGICAL_SSE2_H__ 1
#define __SSEPLUS_MEMORY_SSE2_H__ 1
#define __SSEPLUS_CONVERT_SSE2_H__ 1

#include "SSEPlus_platform.h"

#if 0
#include <xmmintrin.h>  // SSE  (Required to use the __m128, and __m128d type)
#include <emmintrin.h>  // SSE2 (Required to use the __m128i type)
#else
typedef struct {
    float f[4];
} __m128;

typedef struct {
    double d[2];
} __m128d;

#ifdef __LP64__
typedef struct {
    unsigned long i[2];
} __m128i;
#else
typedef struct {
    unsigned long long i[2];
} __m128i;
#endif

typedef struct {
    float m64[2];
} __m64;

static __inline__ __m128i __attribute__((__always_inline__, __nodebug__))
_mm_setzero_si128(void)
{
    return (__m128i){ 0LL, 0LL };
}
#endif

//---------------------------------------
// Type Definitions
//---------------------------------------

typedef   signed char      ssp_s8;
typedef unsigned char      ssp_u8;

typedef   signed short     ssp_s16;
typedef unsigned short     ssp_u16;

typedef   signed int       ssp_s32;
typedef unsigned int       ssp_u32;

typedef float              ssp_f32;
typedef double             ssp_f64;

typedef   signed long long ssp_s64;
typedef unsigned long long ssp_u64;

typedef union 
{
    __m128  f;
    __m128d d;
    __m128i i;
    __uint128_t ui;
    __m64	m64[ 2];
    ssp_u64 u64[ 2];  
    ssp_s64 s64[ 2];
    ssp_f64 f64[ 2]; 
    ssp_u32 u32[ 4];
    ssp_s32 s32[ 4];    
    ssp_f32 f32[ 4]; 
    ssp_u16 u16[ 8];  
    ssp_s16 s16[ 8];    
    ssp_u8  u8 [16];
    ssp_s8  s8 [16];    
} ssp_m128;

typedef union 
{
    __m64	m64;
    ssp_u64 u64;  
    ssp_s64 s64;
    ssp_u32 u32[ 2];
    ssp_s32 s32[ 2];    
    ssp_u16 u16[ 4];  
    ssp_s16 s16[ 4];    
    ssp_u8  u8 [ 8];
    ssp_s8  s8 [ 8];    
} ssp_m64;

ssp_u16 MAX_U16 = 65535;

//---------------------------------------
// Rounding mode macros
//---------------------------------------
#define SSP_FROUND_TO_NEAREST_INT    0x00
#define SSP_FROUND_TO_NEG_INF        0x01
#define SSP_FROUND_TO_POS_INF        0x02
#define SSP_FROUND_TO_ZERO           0x03
#define SSP_FROUND_CUR_DIRECTION     0x04

#define SSP_FROUND_RAISE_EXC         0x00
#define SSP_FROUND_NO_EXC            0x08

//---------------------------------------
// Floating point precision requirements
//---------------------------------------
const static float  SSP_F32_ALLOWANCE =  0.0001f;
const static double SSP_F64_ALLOWANCE =  0.0001;


//---------------------------------------
// Warning macros
//---------------------------------------
#define STRING2(x) #x
#define STRING(x) STRING2(x)
#define WARN( ) __FILE__"("STRING(__LINE__)") : NOTE " 

//#define _SSP_SHUFFLE(w,x,y,z) (((w)<<3) | ((x)<<2) | ((y)<<1) | (z))

//---------------------------------------
// Common Case Statements 
//    for native intrinsics with an immediate input
//---------------------------------------
#define CASE_2( fn, ... )                   \
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
default:  return fn( __VA_ARGS__, 0x1 );

#define CASE_4( fn, ... )                   \
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
case 0x1: return fn( __VA_ARGS__, 0x1 );    \
case 0x2: return fn( __VA_ARGS__, 0x2 );    \
default: return fn( __VA_ARGS__, 0x3 );

#define CASE_4_NR( fn, ... )         \
case 0x0: fn( __VA_ARGS__, 0x0 );    \
case 0x1: fn( __VA_ARGS__, 0x1 );    \
case 0x2: fn( __VA_ARGS__, 0x2 );    \
default: fn( __VA_ARGS__, 0x3 );

#define CASE_8( fn, ... )                   \
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
case 0x1: return fn( __VA_ARGS__, 0x1 );    \
case 0x2: return fn( __VA_ARGS__, 0x2 );    \
case 0x3: return fn( __VA_ARGS__, 0x3 );    \
case 0x4: return fn( __VA_ARGS__, 0x4 );    \
case 0x5: return fn( __VA_ARGS__, 0x5 );    \
case 0x6: return fn( __VA_ARGS__, 0x6 );    \
default: return fn( __VA_ARGS__, 0x7 );

#define CASE_16( fn, ... )                  \
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
case 0x1: return fn( __VA_ARGS__, 0x1 );    \
case 0x2: return fn( __VA_ARGS__, 0x2 );    \
case 0x3: return fn( __VA_ARGS__, 0x3 );    \
case 0x4: return fn( __VA_ARGS__, 0x4 );    \
case 0x5: return fn( __VA_ARGS__, 0x5 );    \
case 0x6: return fn( __VA_ARGS__, 0x6 );    \
case 0x7: return fn( __VA_ARGS__, 0x7 );    \
case 0x8: return fn( __VA_ARGS__, 0x8 );    \
case 0x9: return fn( __VA_ARGS__, 0x9 );    \
case 0xA: return fn( __VA_ARGS__, 0xA );    \
case 0xB: return fn( __VA_ARGS__, 0xB );    \
case 0xC: return fn( __VA_ARGS__, 0xC );    \
case 0xD: return fn( __VA_ARGS__, 0xD );    \
case 0xE: return fn( __VA_ARGS__, 0xE );    \
default: return fn( __VA_ARGS__, 0xF );

#define CASE_32( fn, ... )                  \
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
case 0x1: return fn( __VA_ARGS__, 0x1 );    \
case 0x2: return fn( __VA_ARGS__, 0x2 );    \
case 0x3: return fn( __VA_ARGS__, 0x3 );    \
case 0x4: return fn( __VA_ARGS__, 0x4 );    \
case 0x5: return fn( __VA_ARGS__, 0x5 );    \
case 0x6: return fn( __VA_ARGS__, 0x6 );    \
case 0x7: return fn( __VA_ARGS__, 0x7 );    \
case 0x8: return fn( __VA_ARGS__, 0x8 );    \
case 0x9: return fn( __VA_ARGS__, 0x9 );    \
case 0xA: return fn( __VA_ARGS__, 0xA );    \
case 0xB: return fn( __VA_ARGS__, 0xB );    \
case 0xC: return fn( __VA_ARGS__, 0xC );    \
case 0xD: return fn( __VA_ARGS__, 0xD );    \
case 0xE: return fn( __VA_ARGS__, 0xE );    \
case 0xF: return fn( __VA_ARGS__, 0xF );    \
case 0x10: return fn( __VA_ARGS__, 0x10 );    \
case 0x11: return fn( __VA_ARGS__, 0x11 );    \
case 0x12: return fn( __VA_ARGS__, 0x12 );    \
case 0x13: return fn( __VA_ARGS__, 0x13 );    \
case 0x14: return fn( __VA_ARGS__, 0x14 );    \
case 0x15: return fn( __VA_ARGS__, 0x15 );    \
case 0x16: return fn( __VA_ARGS__, 0x16 );    \
case 0x17: return fn( __VA_ARGS__, 0x17 );    \
case 0x18: return fn( __VA_ARGS__, 0x18 );    \
case 0x19: return fn( __VA_ARGS__, 0x19 );    \
case 0x1A: return fn( __VA_ARGS__, 0x1A );    \
case 0x1B: return fn( __VA_ARGS__, 0x1B );    \
case 0x1C: return fn( __VA_ARGS__, 0x1C );    \
case 0x1D: return fn( __VA_ARGS__, 0x1D );    \
case 0x1E: return fn( __VA_ARGS__, 0x1E );    \
default:   return fn( __VA_ARGS__, 0x1F );    

#define CASE_128( fn, ... )                 \
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
case 0x1: return fn( __VA_ARGS__, 0x1 );    \
case 0x2: return fn( __VA_ARGS__, 0x2 );    \
case 0x3: return fn( __VA_ARGS__, 0x3 );    \
case 0x4: return fn( __VA_ARGS__, 0x4 );    \
case 0x5: return fn( __VA_ARGS__, 0x5 );    \
case 0x6: return fn( __VA_ARGS__, 0x6 );    \
case 0x7: return fn( __VA_ARGS__, 0x7 );    \
case 0x8: return fn( __VA_ARGS__, 0x8 );    \
case 0x9: return fn( __VA_ARGS__, 0x9 );    \
case 0xA: return fn( __VA_ARGS__, 0xA );    \
case 0xB: return fn( __VA_ARGS__, 0xB );    \
case 0xC: return fn( __VA_ARGS__, 0xC );    \
case 0xD: return fn( __VA_ARGS__, 0xD );    \
case 0xE: return fn( __VA_ARGS__, 0xE );    \
case 0xF: return fn( __VA_ARGS__, 0xF );    \
case 0x10: return fn( __VA_ARGS__, 0x10 );    \
case 0x11: return fn( __VA_ARGS__, 0x11 );    \
case 0x12: return fn( __VA_ARGS__, 0x12 );    \
case 0x13: return fn( __VA_ARGS__, 0x13 );    \
case 0x14: return fn( __VA_ARGS__, 0x14 );    \
case 0x15: return fn( __VA_ARGS__, 0x15 );    \
case 0x16: return fn( __VA_ARGS__, 0x16 );    \
case 0x17: return fn( __VA_ARGS__, 0x17 );    \
case 0x18: return fn( __VA_ARGS__, 0x18 );    \
case 0x19: return fn( __VA_ARGS__, 0x19 );    \
case 0x1A: return fn( __VA_ARGS__, 0x1A );    \
case 0x1B: return fn( __VA_ARGS__, 0x1B );    \
case 0x1C: return fn( __VA_ARGS__, 0x1C );    \
case 0x1D: return fn( __VA_ARGS__, 0x1D );    \
case 0x1E: return fn( __VA_ARGS__, 0x1E );    \
case 0x1F: return fn( __VA_ARGS__, 0x1F );    \
case 0x20: return fn( __VA_ARGS__, 0x20 );    \
case 0x21: return fn( __VA_ARGS__, 0x21 );    \
case 0x22: return fn( __VA_ARGS__, 0x22 );    \
case 0x23: return fn( __VA_ARGS__, 0x23 );    \
case 0x24: return fn( __VA_ARGS__, 0x24 );    \
case 0x25: return fn( __VA_ARGS__, 0x25 );    \
case 0x26: return fn( __VA_ARGS__, 0x26 );    \
case 0x27: return fn( __VA_ARGS__, 0x27 );    \
case 0x28: return fn( __VA_ARGS__, 0x28 );    \
case 0x29: return fn( __VA_ARGS__, 0x29 );    \
case 0x2A: return fn( __VA_ARGS__, 0x2A );    \
case 0x2B: return fn( __VA_ARGS__, 0x2B );    \
case 0x2C: return fn( __VA_ARGS__, 0x2C );    \
case 0x2D: return fn( __VA_ARGS__, 0x2D );    \
case 0x2E: return fn( __VA_ARGS__, 0x2E );    \
case 0x2F: return fn( __VA_ARGS__, 0x2F );    \
case 0x30: return fn( __VA_ARGS__, 0x30 );    \
case 0x31: return fn( __VA_ARGS__, 0x31 );    \
case 0x32: return fn( __VA_ARGS__, 0x32 );    \
case 0x33: return fn( __VA_ARGS__, 0x33 );    \
case 0x34: return fn( __VA_ARGS__, 0x34 );    \
case 0x35: return fn( __VA_ARGS__, 0x35 );    \
case 0x36: return fn( __VA_ARGS__, 0x36 );    \
case 0x37: return fn( __VA_ARGS__, 0x37 );    \
case 0x38: return fn( __VA_ARGS__, 0x38 );    \
case 0x39: return fn( __VA_ARGS__, 0x39 );    \
case 0x3A: return fn( __VA_ARGS__, 0x3A );    \
case 0x3B: return fn( __VA_ARGS__, 0x3B );    \
case 0x3C: return fn( __VA_ARGS__, 0x3C );    \
case 0x3D: return fn( __VA_ARGS__, 0x3D );    \
case 0x3E: return fn( __VA_ARGS__, 0x3E );    \
case 0x3F: return fn( __VA_ARGS__, 0x3F );    \
case 0x40: return fn( __VA_ARGS__, 0x40 );    \
case 0x41: return fn( __VA_ARGS__, 0x41 );    \
case 0x42: return fn( __VA_ARGS__, 0x42 );    \
case 0x43: return fn( __VA_ARGS__, 0x43 );    \
case 0x44: return fn( __VA_ARGS__, 0x44 );    \
case 0x45: return fn( __VA_ARGS__, 0x45 );    \
case 0x46: return fn( __VA_ARGS__, 0x46 );    \
case 0x47: return fn( __VA_ARGS__, 0x47 );    \
case 0x48: return fn( __VA_ARGS__, 0x48 );    \
case 0x49: return fn( __VA_ARGS__, 0x49 );    \
case 0x4A: return fn( __VA_ARGS__, 0x4A );    \
case 0x4B: return fn( __VA_ARGS__, 0x4B );    \
case 0x4C: return fn( __VA_ARGS__, 0x4C );    \
case 0x4D: return fn( __VA_ARGS__, 0x4D );    \
case 0x4E: return fn( __VA_ARGS__, 0x4E );    \
case 0x4F: return fn( __VA_ARGS__, 0x4F );    \
case 0x50: return fn( __VA_ARGS__, 0x50 );    \
case 0x51: return fn( __VA_ARGS__, 0x51 );    \
case 0x52: return fn( __VA_ARGS__, 0x52 );    \
case 0x53: return fn( __VA_ARGS__, 0x53 );    \
case 0x54: return fn( __VA_ARGS__, 0x54 );    \
case 0x55: return fn( __VA_ARGS__, 0x55 );    \
case 0x56: return fn( __VA_ARGS__, 0x56 );    \
case 0x57: return fn( __VA_ARGS__, 0x57 );    \
case 0x58: return fn( __VA_ARGS__, 0x58 );    \
case 0x59: return fn( __VA_ARGS__, 0x59 );    \
case 0x5A: return fn( __VA_ARGS__, 0x5A );    \
case 0x5B: return fn( __VA_ARGS__, 0x5B );    \
case 0x5C: return fn( __VA_ARGS__, 0x5C );    \
case 0x5D: return fn( __VA_ARGS__, 0x5D );    \
case 0x5E: return fn( __VA_ARGS__, 0x5E );    \
case 0x5F: return fn( __VA_ARGS__, 0x5F );    \
case 0x60: return fn( __VA_ARGS__, 0x60 );    \
case 0x61: return fn( __VA_ARGS__, 0x61 );    \
case 0x62: return fn( __VA_ARGS__, 0x62 );    \
case 0x63: return fn( __VA_ARGS__, 0x63 );    \
case 0x64: return fn( __VA_ARGS__, 0x64 );    \
case 0x65: return fn( __VA_ARGS__, 0x65 );    \
case 0x66: return fn( __VA_ARGS__, 0x66 );    \
case 0x67: return fn( __VA_ARGS__, 0x67 );    \
case 0x68: return fn( __VA_ARGS__, 0x68 );    \
case 0x69: return fn( __VA_ARGS__, 0x69 );    \
case 0x6A: return fn( __VA_ARGS__, 0x6A );    \
case 0x6B: return fn( __VA_ARGS__, 0x6B );    \
case 0x6C: return fn( __VA_ARGS__, 0x6C );    \
case 0x6D: return fn( __VA_ARGS__, 0x6D );    \
case 0x6E: return fn( __VA_ARGS__, 0x6E );    \
case 0x6F: return fn( __VA_ARGS__, 0x6F );    \
case 0x70: return fn( __VA_ARGS__, 0x70 );    \
case 0x71: return fn( __VA_ARGS__, 0x71 );    \
case 0x72: return fn( __VA_ARGS__, 0x72 );    \
case 0x73: return fn( __VA_ARGS__, 0x73 );    \
case 0x74: return fn( __VA_ARGS__, 0x74 );    \
case 0x75: return fn( __VA_ARGS__, 0x75 );    \
case 0x76: return fn( __VA_ARGS__, 0x76 );    \
case 0x77: return fn( __VA_ARGS__, 0x77 );    \
case 0x78: return fn( __VA_ARGS__, 0x78 );    \
case 0x79: return fn( __VA_ARGS__, 0x79 );    \
case 0x7A: return fn( __VA_ARGS__, 0x7A );    \
case 0x7B: return fn( __VA_ARGS__, 0x7B );    \
case 0x7C: return fn( __VA_ARGS__, 0x7C );    \
case 0x7D: return fn( __VA_ARGS__, 0x7D );    \
case 0x7E: return fn( __VA_ARGS__, 0x7E );    \
default: return fn( __VA_ARGS__, 0x7F );

#define CASE_64( fn, ... )					\
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
case 0x1: return fn( __VA_ARGS__, 0x1 );    \
case 0x2: return fn( __VA_ARGS__, 0x2 );    \
case 0x3: return fn( __VA_ARGS__, 0x3 );    \
case 0x4: return fn( __VA_ARGS__, 0x4 );    \
case 0x5: return fn( __VA_ARGS__, 0x5 );    \
case 0x6: return fn( __VA_ARGS__, 0x6 );    \
case 0x7: return fn( __VA_ARGS__, 0x7 );    \
case 0x8: return fn( __VA_ARGS__, 0x8 );    \
case 0x9: return fn( __VA_ARGS__, 0x9 );    \
case 0xA: return fn( __VA_ARGS__, 0xA );    \
case 0xB: return fn( __VA_ARGS__, 0xB );    \
case 0xC: return fn( __VA_ARGS__, 0xC );    \
case 0xD: return fn( __VA_ARGS__, 0xD );    \
case 0xE: return fn( __VA_ARGS__, 0xE );    \
case 0xF: return fn( __VA_ARGS__, 0xF );    \
case 0x10: return fn( __VA_ARGS__, 0x10 );    \
case 0x11: return fn( __VA_ARGS__, 0x11 );    \
case 0x12: return fn( __VA_ARGS__, 0x12 );    \
case 0x13: return fn( __VA_ARGS__, 0x13 );    \
case 0x14: return fn( __VA_ARGS__, 0x14 );    \
case 0x15: return fn( __VA_ARGS__, 0x15 );    \
case 0x16: return fn( __VA_ARGS__, 0x16 );    \
case 0x17: return fn( __VA_ARGS__, 0x17 );    \
case 0x18: return fn( __VA_ARGS__, 0x18 );    \
case 0x19: return fn( __VA_ARGS__, 0x19 );    \
case 0x1A: return fn( __VA_ARGS__, 0x1A );    \
case 0x1B: return fn( __VA_ARGS__, 0x1B );    \
case 0x1C: return fn( __VA_ARGS__, 0x1C );    \
case 0x1D: return fn( __VA_ARGS__, 0x1D );    \
case 0x1E: return fn( __VA_ARGS__, 0x1E );    \
case 0x1F: return fn( __VA_ARGS__, 0x1F );    \
case 0x20: return fn( __VA_ARGS__, 0x20 );    \
case 0x21: return fn( __VA_ARGS__, 0x21 );    \
case 0x22: return fn( __VA_ARGS__, 0x22 );    \
case 0x23: return fn( __VA_ARGS__, 0x23 );    \
case 0x24: return fn( __VA_ARGS__, 0x24 );    \
case 0x25: return fn( __VA_ARGS__, 0x25 );    \
case 0x26: return fn( __VA_ARGS__, 0x26 );    \
case 0x27: return fn( __VA_ARGS__, 0x27 );    \
case 0x28: return fn( __VA_ARGS__, 0x28 );    \
case 0x29: return fn( __VA_ARGS__, 0x29 );    \
case 0x2A: return fn( __VA_ARGS__, 0x2A );    \
case 0x2B: return fn( __VA_ARGS__, 0x2B );    \
case 0x2C: return fn( __VA_ARGS__, 0x2C );    \
case 0x2D: return fn( __VA_ARGS__, 0x2D );    \
case 0x2E: return fn( __VA_ARGS__, 0x2E );    \
case 0x2F: return fn( __VA_ARGS__, 0x2F );    \
case 0x30: return fn( __VA_ARGS__, 0x30 );    \
case 0x31: return fn( __VA_ARGS__, 0x31 );    \
case 0x32: return fn( __VA_ARGS__, 0x32 );    \
case 0x33: return fn( __VA_ARGS__, 0x33 );    \
case 0x34: return fn( __VA_ARGS__, 0x34 );    \
case 0x35: return fn( __VA_ARGS__, 0x35 );    \
case 0x36: return fn( __VA_ARGS__, 0x36 );    \
case 0x37: return fn( __VA_ARGS__, 0x37 );    \
case 0x38: return fn( __VA_ARGS__, 0x38 );    \
case 0x39: return fn( __VA_ARGS__, 0x39 );    \
case 0x3A: return fn( __VA_ARGS__, 0x3A );    \
case 0x3B: return fn( __VA_ARGS__, 0x3B );    \
case 0x3C: return fn( __VA_ARGS__, 0x3C );    \
case 0x3D: return fn( __VA_ARGS__, 0x3D );    \
case 0x3E: return fn( __VA_ARGS__, 0x3E );    \
default: return fn( __VA_ARGS__, 0x3F );

#define CASE_256( fn, ... )                 \
case 0x0: return fn( __VA_ARGS__, 0x0 );    \
case 0x1: return fn( __VA_ARGS__, 0x1 );    \
case 0x2: return fn( __VA_ARGS__, 0x2 );    \
case 0x3: return fn( __VA_ARGS__, 0x3 );    \
case 0x4: return fn( __VA_ARGS__, 0x4 );    \
case 0x5: return fn( __VA_ARGS__, 0x5 );    \
case 0x6: return fn( __VA_ARGS__, 0x6 );    \
case 0x7: return fn( __VA_ARGS__, 0x7 );    \
case 0x8: return fn( __VA_ARGS__, 0x8 );    \
case 0x9: return fn( __VA_ARGS__, 0x9 );    \
case 0xA: return fn( __VA_ARGS__, 0xA );    \
case 0xB: return fn( __VA_ARGS__, 0xB );    \
case 0xC: return fn( __VA_ARGS__, 0xC );    \
case 0xD: return fn( __VA_ARGS__, 0xD );    \
case 0xE: return fn( __VA_ARGS__, 0xE );    \
case 0xF: return fn( __VA_ARGS__, 0xF );    \
case 0x10: return fn( __VA_ARGS__, 0x10 );    \
case 0x11: return fn( __VA_ARGS__, 0x11 );    \
case 0x12: return fn( __VA_ARGS__, 0x12 );    \
case 0x13: return fn( __VA_ARGS__, 0x13 );    \
case 0x14: return fn( __VA_ARGS__, 0x14 );    \
case 0x15: return fn( __VA_ARGS__, 0x15 );    \
case 0x16: return fn( __VA_ARGS__, 0x16 );    \
case 0x17: return fn( __VA_ARGS__, 0x17 );    \
case 0x18: return fn( __VA_ARGS__, 0x18 );    \
case 0x19: return fn( __VA_ARGS__, 0x19 );    \
case 0x1A: return fn( __VA_ARGS__, 0x1A );    \
case 0x1B: return fn( __VA_ARGS__, 0x1B );    \
case 0x1C: return fn( __VA_ARGS__, 0x1C );    \
case 0x1D: return fn( __VA_ARGS__, 0x1D );    \
case 0x1E: return fn( __VA_ARGS__, 0x1E );    \
case 0x1F: return fn( __VA_ARGS__, 0x1F );    \
case 0x20: return fn( __VA_ARGS__, 0x20 );    \
case 0x21: return fn( __VA_ARGS__, 0x21 );    \
case 0x22: return fn( __VA_ARGS__, 0x22 );    \
case 0x23: return fn( __VA_ARGS__, 0x23 );    \
case 0x24: return fn( __VA_ARGS__, 0x24 );    \
case 0x25: return fn( __VA_ARGS__, 0x25 );    \
case 0x26: return fn( __VA_ARGS__, 0x26 );    \
case 0x27: return fn( __VA_ARGS__, 0x27 );    \
case 0x28: return fn( __VA_ARGS__, 0x28 );    \
case 0x29: return fn( __VA_ARGS__, 0x29 );    \
case 0x2A: return fn( __VA_ARGS__, 0x2A );    \
case 0x2B: return fn( __VA_ARGS__, 0x2B );    \
case 0x2C: return fn( __VA_ARGS__, 0x2C );    \
case 0x2D: return fn( __VA_ARGS__, 0x2D );    \
case 0x2E: return fn( __VA_ARGS__, 0x2E );    \
case 0x2F: return fn( __VA_ARGS__, 0x2F );    \
case 0x30: return fn( __VA_ARGS__, 0x30 );    \
case 0x31: return fn( __VA_ARGS__, 0x31 );    \
case 0x32: return fn( __VA_ARGS__, 0x32 );    \
case 0x33: return fn( __VA_ARGS__, 0x33 );    \
case 0x34: return fn( __VA_ARGS__, 0x34 );    \
case 0x35: return fn( __VA_ARGS__, 0x35 );    \
case 0x36: return fn( __VA_ARGS__, 0x36 );    \
case 0x37: return fn( __VA_ARGS__, 0x37 );    \
case 0x38: return fn( __VA_ARGS__, 0x38 );    \
case 0x39: return fn( __VA_ARGS__, 0x39 );    \
case 0x3A: return fn( __VA_ARGS__, 0x3A );    \
case 0x3B: return fn( __VA_ARGS__, 0x3B );    \
case 0x3C: return fn( __VA_ARGS__, 0x3C );    \
case 0x3D: return fn( __VA_ARGS__, 0x3D );    \
case 0x3E: return fn( __VA_ARGS__, 0x3E );    \
case 0x3F: return fn( __VA_ARGS__, 0x3F );    \
case 0x40: return fn( __VA_ARGS__, 0x40 );    \
case 0x41: return fn( __VA_ARGS__, 0x41 );    \
case 0x42: return fn( __VA_ARGS__, 0x42 );    \
case 0x43: return fn( __VA_ARGS__, 0x43 );    \
case 0x44: return fn( __VA_ARGS__, 0x44 );    \
case 0x45: return fn( __VA_ARGS__, 0x45 );    \
case 0x46: return fn( __VA_ARGS__, 0x46 );    \
case 0x47: return fn( __VA_ARGS__, 0x47 );    \
case 0x48: return fn( __VA_ARGS__, 0x48 );    \
case 0x49: return fn( __VA_ARGS__, 0x49 );    \
case 0x4A: return fn( __VA_ARGS__, 0x4A );    \
case 0x4B: return fn( __VA_ARGS__, 0x4B );    \
case 0x4C: return fn( __VA_ARGS__, 0x4C );    \
case 0x4D: return fn( __VA_ARGS__, 0x4D );    \
case 0x4E: return fn( __VA_ARGS__, 0x4E );    \
case 0x4F: return fn( __VA_ARGS__, 0x4F );    \
case 0x50: return fn( __VA_ARGS__, 0x50 );    \
case 0x51: return fn( __VA_ARGS__, 0x51 );    \
case 0x52: return fn( __VA_ARGS__, 0x52 );    \
case 0x53: return fn( __VA_ARGS__, 0x53 );    \
case 0x54: return fn( __VA_ARGS__, 0x54 );    \
case 0x55: return fn( __VA_ARGS__, 0x55 );    \
case 0x56: return fn( __VA_ARGS__, 0x56 );    \
case 0x57: return fn( __VA_ARGS__, 0x57 );    \
case 0x58: return fn( __VA_ARGS__, 0x58 );    \
case 0x59: return fn( __VA_ARGS__, 0x59 );    \
case 0x5A: return fn( __VA_ARGS__, 0x5A );    \
case 0x5B: return fn( __VA_ARGS__, 0x5B );    \
case 0x5C: return fn( __VA_ARGS__, 0x5C );    \
case 0x5D: return fn( __VA_ARGS__, 0x5D );    \
case 0x5E: return fn( __VA_ARGS__, 0x5E );    \
case 0x5F: return fn( __VA_ARGS__, 0x5F );    \
case 0x60: return fn( __VA_ARGS__, 0x60 );    \
case 0x61: return fn( __VA_ARGS__, 0x61 );    \
case 0x62: return fn( __VA_ARGS__, 0x62 );    \
case 0x63: return fn( __VA_ARGS__, 0x63 );    \
case 0x64: return fn( __VA_ARGS__, 0x64 );    \
case 0x65: return fn( __VA_ARGS__, 0x65 );    \
case 0x66: return fn( __VA_ARGS__, 0x66 );    \
case 0x67: return fn( __VA_ARGS__, 0x67 );    \
case 0x68: return fn( __VA_ARGS__, 0x68 );    \
case 0x69: return fn( __VA_ARGS__, 0x69 );    \
case 0x6A: return fn( __VA_ARGS__, 0x6A );    \
case 0x6B: return fn( __VA_ARGS__, 0x6B );    \
case 0x6C: return fn( __VA_ARGS__, 0x6C );    \
case 0x6D: return fn( __VA_ARGS__, 0x6D );    \
case 0x6E: return fn( __VA_ARGS__, 0x6E );    \
case 0x6F: return fn( __VA_ARGS__, 0x6F );    \
case 0x70: return fn( __VA_ARGS__, 0x70 );    \
case 0x71: return fn( __VA_ARGS__, 0x71 );    \
case 0x72: return fn( __VA_ARGS__, 0x72 );    \
case 0x73: return fn( __VA_ARGS__, 0x73 );    \
case 0x74: return fn( __VA_ARGS__, 0x74 );    \
case 0x75: return fn( __VA_ARGS__, 0x75 );    \
case 0x76: return fn( __VA_ARGS__, 0x76 );    \
case 0x77: return fn( __VA_ARGS__, 0x77 );    \
case 0x78: return fn( __VA_ARGS__, 0x78 );    \
case 0x79: return fn( __VA_ARGS__, 0x79 );    \
case 0x7A: return fn( __VA_ARGS__, 0x7A );    \
case 0x7B: return fn( __VA_ARGS__, 0x7B );    \
case 0x7C: return fn( __VA_ARGS__, 0x7C );    \
case 0x7D: return fn( __VA_ARGS__, 0x7D );    \
case 0x7E: return fn( __VA_ARGS__, 0x7E );    \
case 0x7F: return fn( __VA_ARGS__, 0x7F );    \
case 0x80: return fn( __VA_ARGS__, 0x80 );    \
case 0x81: return fn( __VA_ARGS__, 0x81 );    \
case 0x82: return fn( __VA_ARGS__, 0x82 );    \
case 0x83: return fn( __VA_ARGS__, 0x83 );    \
case 0x84: return fn( __VA_ARGS__, 0x84 );    \
case 0x85: return fn( __VA_ARGS__, 0x85 );    \
case 0x86: return fn( __VA_ARGS__, 0x86 );    \
case 0x87: return fn( __VA_ARGS__, 0x87 );    \
case 0x88: return fn( __VA_ARGS__, 0x88 );    \
case 0x89: return fn( __VA_ARGS__, 0x89 );    \
case 0x8A: return fn( __VA_ARGS__, 0x8A );    \
case 0x8B: return fn( __VA_ARGS__, 0x8B );    \
case 0x8C: return fn( __VA_ARGS__, 0x8C );    \
case 0x8D: return fn( __VA_ARGS__, 0x8D );    \
case 0x8E: return fn( __VA_ARGS__, 0x8E );    \
case 0x8F: return fn( __VA_ARGS__, 0x8F );    \
case 0x90: return fn( __VA_ARGS__, 0x90 );    \
case 0x91: return fn( __VA_ARGS__, 0x91 );    \
case 0x92: return fn( __VA_ARGS__, 0x92 );    \
case 0x93: return fn( __VA_ARGS__, 0x93 );    \
case 0x94: return fn( __VA_ARGS__, 0x94 );    \
case 0x95: return fn( __VA_ARGS__, 0x95 );    \
case 0x96: return fn( __VA_ARGS__, 0x96 );    \
case 0x97: return fn( __VA_ARGS__, 0x97 );    \
case 0x98: return fn( __VA_ARGS__, 0x98 );    \
case 0x99: return fn( __VA_ARGS__, 0x99 );    \
case 0x9A: return fn( __VA_ARGS__, 0x9A );    \
case 0x9B: return fn( __VA_ARGS__, 0x9B );    \
case 0x9C: return fn( __VA_ARGS__, 0x9C );    \
case 0x9D: return fn( __VA_ARGS__, 0x9D );    \
case 0x9E: return fn( __VA_ARGS__, 0x9E );    \
case 0x9F: return fn( __VA_ARGS__, 0x9F );    \
case 0xA0: return fn( __VA_ARGS__, 0xA0 );    \
case 0xA1: return fn( __VA_ARGS__, 0xA1 );    \
case 0xA2: return fn( __VA_ARGS__, 0xA2 );    \
case 0xA3: return fn( __VA_ARGS__, 0xA3 );    \
case 0xA4: return fn( __VA_ARGS__, 0xA4 );    \
case 0xA5: return fn( __VA_ARGS__, 0xA5 );    \
case 0xA6: return fn( __VA_ARGS__, 0xA6 );    \
case 0xA7: return fn( __VA_ARGS__, 0xA7 );    \
case 0xA8: return fn( __VA_ARGS__, 0xA8 );    \
case 0xA9: return fn( __VA_ARGS__, 0xA9 );    \
case 0xAA: return fn( __VA_ARGS__, 0xAA );    \
case 0xAB: return fn( __VA_ARGS__, 0xAB );    \
case 0xAC: return fn( __VA_ARGS__, 0xAC );    \
case 0xAD: return fn( __VA_ARGS__, 0xAD );    \
case 0xAE: return fn( __VA_ARGS__, 0xAE );    \
case 0xAF: return fn( __VA_ARGS__, 0xAF );    \
case 0xB0: return fn( __VA_ARGS__, 0xB0 );    \
case 0xB1: return fn( __VA_ARGS__, 0xB1 );    \
case 0xB2: return fn( __VA_ARGS__, 0xB2 );    \
case 0xB3: return fn( __VA_ARGS__, 0xB3 );    \
case 0xB4: return fn( __VA_ARGS__, 0xB4 );    \
case 0xB5: return fn( __VA_ARGS__, 0xB5 );    \
case 0xB6: return fn( __VA_ARGS__, 0xB6 );    \
case 0xB7: return fn( __VA_ARGS__, 0xB7 );    \
case 0xB8: return fn( __VA_ARGS__, 0xB8 );    \
case 0xB9: return fn( __VA_ARGS__, 0xB9 );    \
case 0xBA: return fn( __VA_ARGS__, 0xBA );    \
case 0xBB: return fn( __VA_ARGS__, 0xBB );    \
case 0xBC: return fn( __VA_ARGS__, 0xBC );    \
case 0xBD: return fn( __VA_ARGS__, 0xBD );    \
case 0xBE: return fn( __VA_ARGS__, 0xBE );    \
case 0xBF: return fn( __VA_ARGS__, 0xBF );    \
case 0xC0: return fn( __VA_ARGS__, 0xC0 );    \
case 0xC1: return fn( __VA_ARGS__, 0xC1 );    \
case 0xC2: return fn( __VA_ARGS__, 0xC2 );    \
case 0xC3: return fn( __VA_ARGS__, 0xC3 );    \
case 0xC4: return fn( __VA_ARGS__, 0xC4 );    \
case 0xC5: return fn( __VA_ARGS__, 0xC5 );    \
case 0xC6: return fn( __VA_ARGS__, 0xC6 );    \
case 0xC7: return fn( __VA_ARGS__, 0xC7 );    \
case 0xC8: return fn( __VA_ARGS__, 0xC8 );    \
case 0xC9: return fn( __VA_ARGS__, 0xC9 );    \
case 0xCA: return fn( __VA_ARGS__, 0xCA );    \
case 0xCB: return fn( __VA_ARGS__, 0xCB );    \
case 0xCC: return fn( __VA_ARGS__, 0xCC );    \
case 0xCD: return fn( __VA_ARGS__, 0xCD );    \
case 0xCE: return fn( __VA_ARGS__, 0xCE );    \
case 0xCF: return fn( __VA_ARGS__, 0xCF );    \
case 0xD0: return fn( __VA_ARGS__, 0xD0 );    \
case 0xD1: return fn( __VA_ARGS__, 0xD1 );    \
case 0xD2: return fn( __VA_ARGS__, 0xD2 );    \
case 0xD3: return fn( __VA_ARGS__, 0xD3 );    \
case 0xD4: return fn( __VA_ARGS__, 0xD4 );    \
case 0xD5: return fn( __VA_ARGS__, 0xD5 );    \
case 0xD6: return fn( __VA_ARGS__, 0xD6 );    \
case 0xD7: return fn( __VA_ARGS__, 0xD7 );    \
case 0xD8: return fn( __VA_ARGS__, 0xD8 );    \
case 0xD9: return fn( __VA_ARGS__, 0xD9 );    \
case 0xDA: return fn( __VA_ARGS__, 0xDA );    \
case 0xDB: return fn( __VA_ARGS__, 0xDB );    \
case 0xDC: return fn( __VA_ARGS__, 0xDC );    \
case 0xDD: return fn( __VA_ARGS__, 0xDD );    \
case 0xDE: return fn( __VA_ARGS__, 0xDE );    \
case 0xDF: return fn( __VA_ARGS__, 0xDF );    \
case 0xE0: return fn( __VA_ARGS__, 0xE0 );    \
case 0xE1: return fn( __VA_ARGS__, 0xE1 );    \
case 0xE2: return fn( __VA_ARGS__, 0xE2 );    \
case 0xE3: return fn( __VA_ARGS__, 0xE3 );    \
case 0xE4: return fn( __VA_ARGS__, 0xE4 );    \
case 0xE5: return fn( __VA_ARGS__, 0xE5 );    \
case 0xE6: return fn( __VA_ARGS__, 0xE6 );    \
case 0xE7: return fn( __VA_ARGS__, 0xE7 );    \
case 0xE8: return fn( __VA_ARGS__, 0xE8 );    \
case 0xE9: return fn( __VA_ARGS__, 0xE9 );    \
case 0xEA: return fn( __VA_ARGS__, 0xEA );    \
case 0xEB: return fn( __VA_ARGS__, 0xEB );    \
case 0xEC: return fn( __VA_ARGS__, 0xEC );    \
case 0xED: return fn( __VA_ARGS__, 0xED );    \
case 0xEE: return fn( __VA_ARGS__, 0xEE );    \
case 0xEF: return fn( __VA_ARGS__, 0xEF );    \
case 0xF0: return fn( __VA_ARGS__, 0xF0 );    \
case 0xF1: return fn( __VA_ARGS__, 0xF1 );    \
case 0xF2: return fn( __VA_ARGS__, 0xF2 );    \
case 0xF3: return fn( __VA_ARGS__, 0xF3 );    \
case 0xF4: return fn( __VA_ARGS__, 0xF4 );    \
case 0xF5: return fn( __VA_ARGS__, 0xF5 );    \
case 0xF6: return fn( __VA_ARGS__, 0xF6 );    \
case 0xF7: return fn( __VA_ARGS__, 0xF7 );    \
case 0xF8: return fn( __VA_ARGS__, 0xF8 );    \
case 0xF9: return fn( __VA_ARGS__, 0xF9 );    \
case 0xFA: return fn( __VA_ARGS__, 0xFA );    \
case 0xFB: return fn( __VA_ARGS__, 0xFB );    \
case 0xFC: return fn( __VA_ARGS__, 0xFC );    \
case 0xFD: return fn( __VA_ARGS__, 0xFD );    \
case 0xFE: return fn( __VA_ARGS__, 0xFE );    \
default: return fn( __VA_ARGS__, 0xFF );

#endif // __BASE_H__
