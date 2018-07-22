//
// Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
// This software is subject to the Apache v2.0 License.
//
#ifndef __MAP_SSE3__
#define __MAP_SSE3__

#include "SSEPlus_MAP_SSE2.h"

//Native Instructons
#undef ssp_addsub_pd    
#undef ssp_addsub_ps    
#undef ssp_hadd_pd      
#undef ssp_hadd_ps      
#undef ssp_hsub_pd      
#undef ssp_hsub_ps      
#undef ssp_lddqu_si128  
#undef ssp_loaddup_pd   
#undef ssp_movedup_pd   
#undef ssp_movehdup_ps  
#undef ssp_moveldup_ps  

#define ssp_addsub_pd        ssp_addsub_pd_SSE3        
#define ssp_addsub_ps        ssp_addsub_ps_SSE3        
#define ssp_hadd_pd          ssp_hadd_pd_SSE3          
#define ssp_hadd_ps          ssp_hadd_ps_SSE3          
#define ssp_hsub_pd          ssp_hsub_pd_SSE3          
#define ssp_hsub_ps          ssp_hsub_ps_SSE3          
#define ssp_lddqu_si128      ssp_lddqu_si128_SSE3      
#define ssp_loaddup_pd       ssp_loaddup_pd_SSE3       
#define ssp_movedup_pd       ssp_movedup_pd_SSE3       
#define ssp_movehdup_ps      ssp_movehdup_ps_SSE3      
#define ssp_moveldup_ps      ssp_moveldup_ps_SSE3      

// Emulated
#undef  ssp_dp_ps
#define ssp_dp_ps            ssp_dp_ps_SSE3    

// Arithmetic
#undef  ssp_arithmetic_hadd4_dup_ps
#define ssp_arithmetic_hadd4_dup_ps ssp_arithmetic_hadd4_dup_ps_SSE3

#endif __MAP_SSE3__