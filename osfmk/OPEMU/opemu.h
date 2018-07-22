#ifndef OPEMU_H
#define OPEMU_H
#include <stdint.h>

#ifndef TESTCASE
#include <mach/thread_status.h>
#endif

#define ALIGN16 __attribute__ ((aligned(16)))
#define ALIGN8  __attribute__ ((aligned(8)))

union XMM_u {
    char s8[16];
    int16_t s16[8];
    int32_t s32[4];
    int64_t s64[2];
    __int128_t s128;
    //__int64_t a128;
    unsigned char u8[16];
    uint16_t u16[8];
    uint32_t u32[4];
    uint64_t u64[2];
    __uint128_t ui;
    //__uint64_t ua128;
    double f64[2];
    float f32[4];
};
typedef union XMM_u XMM;

union MM_u {
    int8_t s8[8];
    int16_t s16[4];
    int32_t s32[2];
    int64_t s64;
    uint8_t u8[8];
    uint16_t u16[4];
    uint32_t u32[2];
    uint64_t u64;
};
typedef union MM_u MM;

//#include <SSEPlus/SSEPlus_base.h>
//#include <SSEPlus/SSEPlus_REF.h>
//#include <SSEPlus/SSEPlus_SSE2.h>
//#include <SSEPlus/emulation/SSEPlus_emulation_SSE2.h>
//#include <SSEPlus/SSEPlus_REF.h>
//#include <SSEPlus/SSEPlus_SSE2.h>
//#include <SSEPlus/memory/SSEPlus_memory_REF.h>

#ifndef TESTCASE
/** XNU TRAP HANDLERS **/
unsigned char opemu_ktrap(x86_saved_state_t *state);
void opemu_utrap(x86_saved_state_t *state);
int ssse3_run(uint8_t *instruction, x86_saved_state_t *state, int longmode, int);
int sse3_run_a(uint8_t *instruction, x86_saved_state_t *state, int longmode, int );
int sse3_run_b(uint8_t *instruction, x86_saved_state_t *state, int longmode, int );
int sse3_run_c(uint8_t *instruction, x86_saved_state_t *state, int longmode, int );
//int sysenter_run(uint8_t *instruction, x86_saved_state_t *state, int longmode);
int sysexit_run(uint8_t *instruction, x86_saved_state_t *state, int longmode, int );
int monitor_mwait_run(uint8_t *instruction, x86_saved_state_t *state, int longmode, int kernel_trap);
int fisttp_run(uint8_t *instruction, x86_saved_state_t *state, int longmode, int kernel_trap);

int fetchoperands(uint8_t *ModRM, unsigned int hsrc, unsigned int hdst, void *src, void *dst,
                  unsigned int longmode, x86_saved_state_t *regs, int , int size_128, int rex, int hsreg, int modbyte, int fisttp);
void storeresult128(uint8_t ModRM, unsigned int hdst, XMM res);
void storeresult64(uint8_t ModRM, unsigned int hdst, MM res);
/*void pshufb64(ssp_m64 *src,ssp_m64 *dst,ssp_m64 *res);
 void pshufb128(ssp_m128 *src,ssp_m128 *dst,ssp_m128 *res);
 void palignr128(ssp_m128 *src,ssp_m128 *dst,ssp_m128 *res,uint8_t operand);
 void palignr64(ssp_m64 *src,ssp_m64 *dst,ssp_m64 *res,uint8_t operand);
 */
#endif
//typedef  ssp_m128 XMM;
//typedef  ssp_m64 MM;


/** All 32 SSSE3 instructions **/
void pshufb128	(XMM *src, XMM *dst, XMM *res);
void pshufb64	(MM *src, MM *dst, MM *res);
void phaddw128	(XMM *src, XMM *dst, XMM *res);
void phaddw64	(MM *src, MM *dst, MM *res);
void phaddd128	(XMM *src, XMM *dst, XMM *res);
void phaddd64	(MM *src, MM *dst, MM *res);
void phaddsw128	(XMM *src, XMM *dst, XMM *res);
void phaddsw64	(MM *src, MM *dst, MM *res);
void pmaddubsw128(XMM *src, XMM *dst, XMM *res);
void pmaddubsw64(MM *src, MM *dst, MM *res);
void phsubw128	(XMM *src, XMM *dst, XMM *res);
void phsubw64	(MM *src, MM *dst, MM *res);
void phsubd128	(XMM *src, XMM *dst, XMM *res);
void phsubd64	(MM *src, MM *dst, MM *res);
void phsubsw128	(XMM *src, XMM *dst, XMM *res);
void phsubsw64	(MM *src, MM *dst, MM *res);
void psignb128	(XMM *src, XMM *dst, XMM *res);
void psignb64	(MM *src, MM *dst, MM *res);
void psignw128	(XMM *src, XMM *dst, XMM *res);
void psignw64	(MM *src, MM *dst, MM *res);
void psignd128	(XMM *src, XMM *dst, XMM *res);
void psignd64	(MM *src, MM *dst, MM *res);
void pmulhrsw128(XMM *src, XMM *dst, XMM *res);
void pmulhrsw64	(MM *src, MM *dst, MM *res);
void pabsb128	(XMM *src, XMM *res);
void pabsb64	(MM *src, MM *res);
void pabsw128	(XMM *src, XMM *res);
void pabsw64	(MM *src, MM *res);
void pabsd128	(XMM *src, XMM *res);
void pabsd64	(MM *src, MM *res);
void palignr128	(XMM *src, XMM *dst, XMM *res, uint32_t IMM);
void palignr64	(MM *src, MM *dst, MM *res, uint32_t IMM);

void print_bytes(uint8_t *from, int size);

//void loadallxmm(void);
//void loadallmm(void);
//void storeallxmm(void);
//void storeallmm(void);

void getxmm(XMM *xmm_reg, uint32_t i);
void getmm(MM *v, unsigned int i);
void movxmm(XMM *xmm_reg, unsigned int i);
void movmm(MM *v, unsigned int i);

/** AnV - SSE3 instructions **/
void addsubpd   (XMM *src, XMM *dst, XMM *res);
void addsubps   (XMM *src, XMM *dst, XMM *res);
void haddpd     (XMM *src, XMM *dst, XMM *res);
void haddps     (XMM *src, XMM *dst, XMM *res);
void hsubpd     (XMM *src, XMM *dst, XMM *res);
void hsubps     (XMM *src, XMM *dst, XMM *res);
void lddqu      (XMM *src, XMM *res);
void movddup    (XMM *src, XMM *res);
void movshdup   (XMM *src, XMM *res);
void movsldup   (XMM *src, XMM *res);
short fisttps(float *res);
int fisttpl(double *res);
long long fisttpq(long double *res);

#endif