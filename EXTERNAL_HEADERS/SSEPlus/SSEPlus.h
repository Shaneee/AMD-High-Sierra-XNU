//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __SSEPLUS_H__
#define __SSEPLUS_H__

#include "SSEPlus_base.h"
#include "SSEPlus_CPUID.h"
#include "SSEPlus_REF.h"
#include "SSEPlus_SSE.h"
#include "SSEPlus_SSE2.h"
#include "SSEPlus_SSE3.h"

#ifdef SSP_COMPILER_SUPPORTS_SSSE3
#include "SSEPlus_SSSE3.h"
#endif 

#ifdef SSP_COMPILER_SUPPORTS_SSE4a
#include "SSEPlus_SSE4a.h"
#endif 

#ifdef SSP_COMPILER_SUPPORTS_SSE41
#include "SSEPlus_SSE4.1.h"
#endif 

#ifdef SSP_COMPILER_SUPPORTS_SSE42
#include "SSEPlus_SSE4.2.h"
#endif 

#ifdef SSP_COMPILER_SUPPORTS_SSE5
#include "SSEPlus_SSE5.h"
#endif 


#endif // __SSEPLUS_H__
