//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_NUMBER_REF_H__
#define __SSEPLUS_NUMBER_REF_H__

#ifndef KERNEL
#include <math.h>
#endif

/** @addtogroup supplimental_REF   
 *  @{ 
 *  @name Number Operations{
 */

SSP_FORCEINLINE int ssp_number_isValidNumber_F32_REF( ssp_s32* val )//TODO: move into utility collection
{
    // Check for NAN, +infin, or -infin (exponent: 111 1111 1)
    // Are the exponent bits all 1's?
    if( (*val & 0x7F800000) == 0x7F800000 )
    {
        return 0;
    }
    return 1;
}
SSP_FORCEINLINE int ssp_number_isValidNumber_F64_REF( ssp_s64* val )   //TODO: move into utility collection
{
    // Check for NAN, +infin, or -infin (exponent: 1111 1111)
    // Are the exponent bits all 1's?
    if( (*val & 0x7FF0000000000000ll) == 0x7FF0000000000000ll )
    {
        return 0;
    }
    return 1;
}

SSP_FORCEINLINE ssp_f32 ssp_number_changeSNanToQNaN_F32_REF( ssp_s32* val )//TODO: move into utility collection
{
    ssp_f32* retVal = (ssp_f32*)val;
    // Check if the value is already a QNaN
    if( (*val & 0x00400000) != 0x00400000 )
    {
        // Check if the value is + or - infinitie
        if( (*val | 0x7F800000) != 0x7F800000 )
        {
            // Convert SNan To QNaN
            *retVal = (ssp_f32)( *val | 0x00400000 );
        }
    }
    return *retVal;
}

SSP_FORCEINLINE ssp_f64 ssp_number_changeSNanToQNaN_F64_REF( ssp_s64* val )//TODO: move into utility collection
{
    ssp_f64* retVal = (ssp_f64*)val;
    // Check if the value is already a QNaN
    if( (*val & 0x0008000000000000ll) != 0x0008000000000000ll )
    {
        // Check if the value is + or - infinitie
        if( (*val | 0x7FF0000000000000ll) != 0x7FF0000000000000ll )
        {
            // Convert SNan To QNaN
            *retVal = (ssp_f64)( *val | 0x0008000000000000ll );
        }
    }
    return *retVal;
}

/** @} 
 *  @}
 */

#endif // __SSEPLUS_NUMBER_REF_H__
