//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//

// This file should contain all platform specific code. 

#ifndef __SSEPLUS_PLATFORM_H__
#define __SSEPLUS_PLATFORM_H__

//TODO: Detect 32/64




//---------------------------------------
// Microsoft Visual Studio
//---------------------------------------
#if defined( _MSC_VER )
#define SSP_MSVC

#if( _MSC_VER >= 1500 ) 
#define SSP_COMPILER_SUPPORTS_SSSE3
#define SSP_COMPILER_SUPPORTS_SSE4a
#define SSP_COMPILER_SUPPORTS_SSE41
#define SSP_COMPILER_SUPPORTS_SSE42
#endif

#define SSP_FORCEINLINE                 __forceinline
#define SSP_INCLUDE_FILE_SSE3           <intrin.h>          // All intrinsics, including SSE3
#define SSP_INCLUDE_FILE_SSE4a          <intrin.h>          // All intrinsics, including SSE4a
#define SSP_INCLUDE_FILE_SSE5           "SSEPlus_NoSSE5.h"  // SSE5
#define SSP_INCLUDE_FILE_SSE4_1_SSE5    <smmintrin.h>       // Functions common to SSE4.1 and SSE5

#include <intrin.h> // CPUID

//---------------------------------------
// GCC
//---------------------------------------
#elif defined( __GNUC__ )
#define SSP_GNUC

#if( __GNUC__       >= 4 )
#if( __GNUC_MINOR__ >= 3 )
#define SSP_COMPILER_SUPPORTS_SSSE3
#define SSP_COMPILER_SUPPORTS_SSE4a
#define SSP_COMPILER_SUPPORTS_SSE41
#define SSP_COMPILER_SUPPORTS_SSE42
#define SSP_COMPILER_SUPPORTS_SSE5
#endif
#endif

#define SSP_FORCEINLINE                 static inline
#define SSP_INCLUDE_FILE_SSE3           <pmmintrin.h>           // SSE3
#define SSP_INCLUDE_FILE_SSE4a          <ammintrin.h>           // All intrinsics, including SSE4a
#define SSP_INCLUDE_FILE_SSE5           <bmmintrin.h>           // SSE5
#define SSP_INCLUDE_FILE_SSE4_1_SSE5    <mmintrin-common.h>     // Functions common to SSE4.1 and SSE5

// CPUID
#if defined( SYS64 )
    #define __cpuid(CPUInfo, InfoType)    __asm__ __volatile__("    pushq %%rbx;                      \
                                                                xorq %%rax, %%rax;                    \
                                                                movl %%esi, %%eax;                    \
                                                                cpuid;                                \
                                                                movl %%eax, 0x0(%%rdi);               \
                                                                movl %%ebx, 0x4(%%rdi);               \
                                                                movl %%ecx, 0x8(%%rdi);               \
                                                                movl %%edx, 0xc(%%rdi);               \
                                                                popq %%rbx;"                          \
                                                                : : "D" (CPUInfo), "S" (InfoType)     \
                                                                : "%rax", "%rcx", "%rdx" )

#elif defined( SYS32 )
    #define __cpuid(CPUInfo, InfoType)    __asm__ __volatile__("    pushl %%ebx;                      \
                                                                xorl %%eax, %%eax;                    \
                                                                movl %%esi, %%eax;                    \
                                                                cpuid;                                \
                                                                movl %%eax, 0x0(%%edi);               \
                                                                movl %%ebx, 0x4(%%edi);               \
                                                                movl %%ecx, 0x8(%%edi);               \
                                                                movl %%edx, 0xc(%%edi);               \
                                                                popl %%ebx;"                          \
                                                                : : "D" (CPUInfo), "S" (InfoType)     \
                                                                : "%eax", "%ecx", "%edx" )
#endif
#endif 

//---------------------------------------
// Microsoft Visual Studio Initialization
//---------------------------------------

#define SSP_ALL_SET_32I 0xFFFFFFFF
#define SSP_ALL_SET_64I 0xFFFFFFFFFFFFFFFF


#if defined(SSP_MSVC)
//#undef SSP_MSVC	

#define SSP_CONST_SETR_8I( a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p ) \
    { (unsigned __int8)(a), (unsigned __int8)(b), (unsigned __int8)(c), (unsigned __int8)(d), \
      (unsigned __int8)(e), (unsigned __int8)(f), (unsigned __int8)(g), (unsigned __int8)(h), \
      (unsigned __int8)(i), (unsigned __int8)(j), (unsigned __int8)(k), (unsigned __int8)(l), \
      (unsigned __int8)(m), (unsigned __int8)(n), (unsigned __int8)(o), (unsigned __int8)(p) }

#define SSP_CONST_SET_8I( a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p ) \
    SSP_CONST_SETR_8I( (p), (o), (n), (m), (l), (k), (j), (i), (h), (g), (f), (e), (d), (c), (b), (a) )

#define SSP_CONST_SET1_8I( x ) \
    SSP_CONST_SET_8I( (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_8I() \
    SSP_CONST_SET1_8I( 0 )

#define __CNST16I28I_( x ) \
    ((unsigned __int8)((x) & 0xFF)), ((unsigned __int8)(((x) >> 8) & 0xFF))

#define SSP_CONST_SETR_16I( a, b, c, d, e, f, g, h ) \
    { __CNST16I28I_((a)), __CNST16I28I_((b)), __CNST16I28I_((c)), __CNST16I28I_((d)), __CNST16I28I_((e)), __CNST16I28I_((f)), __CNST16I28I_((g)), __CNST16I28I_((h)) }

#define SSP_CONST_SET_16I( a, b, c, d, e, f, g, h ) \
    SSP_CONST_SETR_16I( (h), (g), (f), (e), (d), (c), (b), (a) )

#define SSP_CONST_SET1_16I( x ) \
    SSP_CONST_SET_16I( (x), (x), (x), (x), (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_16I() \
    SSP_CONST_SETZERO_8I()

#define __CNST32I28I_( x ) \
    ((unsigned __int8)((x) & 0xFF)), ((unsigned __int8)(((x) >> 8) & 0xFF)), ((unsigned __int8)(((x) >> 16) & 0xFF)), ((unsigned __int8)(((x) >> 24) & 0xFF))

#define SSP_CONST_SETR_32I( a, b, c, d ) \
    { __CNST32I28I_((a)), __CNST32I28I_((b)), __CNST32I28I_((c)), __CNST32I28I_((d)) }

#define SSP_CONST_SET_32I( a, b, c, d ) \
    SSP_CONST_SETR_32I( (d), (c), (b), (a) )

#define SSP_CONST_SET1_32I( x ) \
    SSP_CONST_SET_32I( (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_32I() \
    SSP_CONST_SETZERO_8I()

#define __CNST64I28I_( x ) \
    ((unsigned __int8)((x) & 0xFF)), ((unsigned __int8)(((x) >> 8) & 0xFF)), ((unsigned __int8)(((x) >> 16) & 0xFF)), ((unsigned __int8)(((x) >> 24) & 0xFF)), ((unsigned __int8)(((x) >> 32) & 0xFF)), ((unsigned __int8)(((x) >> 40) & 0xFF)), ((unsigned __int8)(((x) >> 48) & 0xFF)), ((unsigned __int8)(((x) >> 56) & 0xFF))

#define SSP_CONST_SETR_64I( a, b ) \
    { __CNST64I28I_((a)), __CNST64I28I_((b)) }

#define SSP_CONST_SET_64I( a, b ) \
    SSP_CONST_SETR_64I( (b), (a) )

#define SSP_CONST_SET1_64I( x ) \
    SSP_CONST_SET_64I( (x), (x) )

#define SSP_CONST_SETZERO_I() \
	{ 0 }

#define SSP_CONST_SETZERO_64I() \
    SSP_CONST_SETZERO_8I()

#define SSP_CONST_SETR_32F( a, b, c, d ) \
    { (a), (b), (c), (d) }

#define SSP_CONST_SET_32F( a, b, c, d ) \
    SSP_CONST_SETR_32F( (d), (c), (b), (a) )

#define SSP_CONST_SET1_32F( x ) \
    SSP_CONST_SET_32F( (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_32F() \
    SSP_CONST_SET1_32F( 0 )

#define SSP_CONST_SETR_64F( a, b ) \
    { (a), (b) }

#define SSP_CONST_SET_64F( a, b ) \
    SSP_CONST_SETR_64F( (b), (a) )

#define SSP_CONST_SET1_64F( x ) \
    SSP_CONST_SET_64F( (x), (x) )

#define SSP_CONST_SETZERO_64F() \
    SSP_CONST_SET1_64F( 0 )

#endif // SSP_MSVC


//---------------------------------------
// GCC Initialization
//---------------------------------------
#if defined(SSP_GNUC)
//#undef SSP_GNUC

#define __CNST8TO64_( a, b, c, d, e, f, g, h ) \
	( (((h)&0xff)<<56) | (((g)&0xff)<<48) | (((f)&0xff)<<40) | (((e)&0xff)<<32) | \
 	(((d)&0xff)<<24) | (((c)&0xff)<<16) | (((b)&0xff)<<8) | ((a)&0xff) )

#define SSP_CONST_SETR_8I( a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p ) \
    { __CNST8TO64_( (ssp_s64)(a), (ssp_s64)(b), (ssp_s64)(c), (ssp_s64)(d), \
                 (ssp_s64)(e), (ssp_s64)(f), (ssp_s64)(g), (ssp_s64)(h) ), \
      __CNST8TO64_( (ssp_s64)(i), (ssp_s64)(j), (ssp_s64)(k), (ssp_s64)(l), \
                 (ssp_s64)(m), (ssp_s64)(n), (ssp_s64)(o), (ssp_s64)(p) ) }

#define SSP_CONST_SET_8I( a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p ) \
    SSP_CONST_SETR_8I( (p), (o), (n), (m), (l), (k), (j), (i), (h), (g), (f), (e), (d), (c), (b), (a) )

#define SSP_CONST_SET1_8I( x ) \
    SSP_CONST_SET_8I( (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_8I() \
    { 0, 0 }

// 16 bit integer types

#define __CNST16TO64_( a, b, c, d ) \
	( ((d)<<48) | (((c)&0xFFFF)<<32) | (((b)&0xFFFF)<<16) | ((a)&0xFFFF) )

#define SSP_CONST_SETR_16I( a, b, c, d, e, f, g, h ) \
    { __CNST16TO64_( (ssp_u64)(a), (ssp_u64)(b), \
                     (ssp_u64)(c), (ssp_u64)(d) ), \
      __CNST16TO64_( (ssp_u64)(e), (ssp_u64)(f), \
                     (ssp_u64)(g), (ssp_u64)(h) ) }

#define SSP_CONST_SET_16I( a, b, c, d, e, f, g, h ) \
    SSP_CONST_SETR_16I( (h), (g), (f), (e), (d), (c), (b), (a) )

#define SSP_CONST_SET1_16I( x ) \
    SSP_CONST_SET_16I( (x), (x), (x), (x), (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_16I() \
    SSP_CONST_SETZERO_8I()

// 32 bit integer types

#define __CNST32TO64_( a, b ) \
	( ((b)<<32) | ((a) & 0xFFFFFFFF) )

#define SSP_CONST_SETR_32I( a, b, c, d ) \
    { __CNST32TO64_( (ssp_u64)(a), (ssp_u64)(b) ), \
      __CNST32TO64_( (ssp_u64)(c), (ssp_u64)(d) ) }

#define SSP_CONST_SET_32I( a, b, c, d ) \
    SSP_CONST_SETR_32I( (d), (c), (b), (a) )

#define SSP_CONST_SET1_32I( x ) \
    SSP_CONST_SET_32I( (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_32I() \
    SSP_CONST_SETZERO_8I()

// 64 bit integer types

#define SSP_CONST_SETR_64I( a, b ) \
    { (a), (b) }

#define SSP_CONST_SET_64I( a, b ) \
    SSP_CONST_SETR_64I( (b), (a) )

#define SSP_CONST_SET1_64I( x ) \
    SSP_CONST_SET_64I( (x), (x) )

#define SSP_CONST_SETZERO_64I() \
    SSP_CONST_SETZERO_8I()


// 32 bit single precision floating point types

#define SSP_CONST_SETR_32F( a, b, c, d ) \
    { (a), (b), (c), (d) }

#define SSP_CONST_SET_32F( a, b, c, d ) \
    SSP_CONST_SETR_32F( (d), (c), (b), (a) )

#define SSP_CONST_SET1_32F( x ) \
    SSP_CONST_SET_32F( (x), (x), (x), (x) )

#define SSP_CONST_SETZERO_32F() \
    SSP_CONST_SET1_32F( 0 )

// 64 bit double precision floating point types
#define SSP_CONST_SETR_64F( a, b ) \
    { (a), (b) }

#define SSP_CONST_SET_64F( a, b ) \
    SSP_CONST_SETR_64F( (b), (a) )

#define SSP_CONST_SET1_64F( x ) \
    SSP_CONST_SET_64F( (x), (x) )

#define SSP_CONST_SETZERO_64F() \
    SSP_CONST_SET1_64F( 0 )

#endif // SSP_GNUC
#endif // __SSEPLUS_PLATFORM_H__
