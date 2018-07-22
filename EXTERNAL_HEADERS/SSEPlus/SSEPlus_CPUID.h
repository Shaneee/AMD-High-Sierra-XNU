//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//

// This file should contain all platform specific code. 

#ifndef __SSEPLUS_CPUID_H__
#define __SSEPLUS_CPUID_H__

#include "SSEPlus_base.h"

/** @addtogroup CPUID   
 *  @{ 
 *  @name CPUID Operations
 */

typedef enum 
{
    SSP_REF,
    SSP_SSE,
    SSP_SSE2,
    SSP_SSE3,
    SSP_SSSE3,
    SSP_SSE4a,
    SSP_SSE4_1,
    SSP_SSE4_2,
    SSP_SSE5,
    SSP_SSE_COUNT
}ssp_cpu_feature;

typedef struct 
{
    int feature[SSP_SSE_COUNT]; 
}ssp_cpuid;


ssp_cpuid ssp_get_cpuid()
{
    unsigned maxInfoType;
    ssp_cpuid cpu;
    int data[4], i;

    for( i=0; i<SSP_SSE_COUNT; ++i )
    {
        cpu.feature[i] = 0;
    }

    __cpuid( data, 0 );  
    maxInfoType = data[0] + 0x80000000;

    __cpuid( data, 1 );      

    cpu.feature[SSP_SSE   ] = (data[3] & 0x1000000); // || 0;  // EDX: bit 25
    cpu.feature[SSP_SSE2  ] = (data[3] & 0x2000000); // || 0;  // EDX: bit 26
    cpu.feature[SSP_SSE3  ] = (data[2] & 0x1      ); // || 0;  // ECX: bit 0
    cpu.feature[SSP_SSSE3 ] = (data[2] & 0x100    ); // || 0;  // ECX: bit 9
    cpu.feature[SSP_SSE4_1] = (data[2] & 0x40000  ); // || 0;  // ECX: bit 19
    cpu.feature[SSP_SSE4_2] = (data[2] & 0x80000  ); // || 0;  // ECX: bit 20

    if( maxInfoType >= 0x80000001 )
    {
        __cpuid( data, 0x80000001 );        
        
        cpu.feature[ SSP_SSE4a ] = (data[2] & 0x40  ); // || 0;  // ECX: bit 6
        cpu.feature[ SSP_SSE5  ] = (data[2] & 0x800 ); // || 0;  // ECX: bit 11
    }
   
    return cpu;    
}

int ssp_is_supported( ssp_cpu_feature index )
{
    ssp_cpuid cpu = ssp_get_cpuid();
    return cpu.feature[ index ];
}

/** @} 
 *  @}
 */

#endif //__SSEPLUS_CPUID_H__
