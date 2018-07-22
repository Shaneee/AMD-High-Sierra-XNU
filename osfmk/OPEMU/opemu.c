/*   ** SINETEK **
 * This is called the Opcode Emulator: it traps invalid opcode exceptions
 *   and modifies the state of the running thread accordingly.
 * There are two entry points, one for user space exceptions, and another for
 *   exceptions coming from kernel space.
 *
 * STATUS
 *  . SSE3 is implemented.
 *  . SSSE3 is implemented.
 *  . SYSENTER is implemented.
 *  . SYSEXIT is implemented.
 *  . RDMSR is implemented.
 *  . Vector register save and restore is implemented.
 *
 * This is a new version of AnV Software based on the AMD SSEPlus project
 * It runs much more reliable and much faster
 */
#include <stdint.h>

#include "opemu.h"
#include "opemu_math.h"
#include <i386/cpuid.h>

#ifndef TESTCASE
#include <kern/sched_prim.h>

#define EMULATION_FAILED -1

// forward declaration for syscall handlers of mach/bsd (32+64 bit);
extern void mach_call_munger(x86_saved_state_t *state);
extern void unix_syscall(x86_saved_state_t *);
extern void mach_call_munger64(x86_saved_state_t *state);
extern void unix_syscall64(x86_saved_state_t *);

// forward declaration of panic handler for kernel traps;
extern void panic_trap(x86_saved_state64_t *regs);

// AnV - Implemented i386 version
#ifdef __x86_64__
unsigned char opemu_ktrap(x86_saved_state_t *state)
{
    x86_saved_state64_t *saved_state = saved_state64(state);
    
    uint8_t *code_buffer = (uint8_t *)saved_state->isf.rip;
    unsigned int bytes_skip = 0;
    
    
    bytes_skip = ssse3_run(code_buffer, state, 1, 0);
    
    if (!bytes_skip)
    {
        bytes_skip = sse3_run_a(code_buffer, state, 1, 0);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = sse3_run_b(code_buffer, state, 1, 0);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = sse3_run_c(code_buffer, state, 1, 0);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = fisttp_run(code_buffer, state, 1, 0);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = monitor_mwait_run(code_buffer, state, 1, 0);
    }
    
    if(!bytes_skip)
    {
        /* since this is ring0, it could be an invalid MSR read.
         * Instead of crashing the whole machine, report on it and keep running. */
        if((code_buffer[0]==0x0f) && (code_buffer[1]==0x32))
        {
            printf("[MSR] unknown location 0x%016llx\r\n", saved_state->rcx);
            // best we can do is return 0;
            saved_state->rdx = saved_state->rax = 0;
            bytes_skip = 2;
        }
    }
    
    saved_state->isf.rip += bytes_skip;
    
    if(!bytes_skip)
    {
        uint8_t *ripptr = (uint8_t *)&(saved_state->isf.rip);
        printf("invalid kernel opcode (64-bit): ");
        print_bytes(ripptr, 16);
        
        /* Fall through to trap */
        return 0;
    }
    
    
    
    return 1;
}
#endif
#ifdef __i386__
unsigned char opemu_ktrap(x86_saved_state_t *state)
{
    x86_saved_state32_t *saved_state = saved_state32(state);
    uint32_t op = saved_state->eip;
    uint8_t *code_buffer = (uint8_t*)op ;
    unsigned int bytes_skip = 0;
    
    
    bytes_skip = ssse3_run(code_buffer, state, 0, 1);
    
    if (!bytes_skip)
    {
        bytes_skip = sse3_run_a(code_buffer, state, 0, 1);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = sse3_run_b(code_buffer, state, 0, 1);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = sse3_run_c(code_buffer, state, 0, 1);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = fisttp_run(code_buffer, state, 0, 1);
    }
    
    if (!bytes_skip)
    {
        bytes_skip = monitor_mwait_run(code_buffer, state, 0, 1);
    }
    
    if(!bytes_skip)
    {
        /* since this is ring0, it could be an invalid MSR read.
         * Instead of crashing the whole machine, report on it and keep running. */
        if(code_buffer[0]==0x0f && code_buffer[1]==0x32)
        {
            printf("[MSR] unknown location 0x%016ux\r\n", saved_state->ecx);
            
            // best we can do is return 0;
            saved_state->edx = saved_state->eax = 0;
            bytes_skip = 2;
        }
    }
    
    saved_state->eip += bytes_skip;
    
    if(!bytes_skip)
    {
        uint8_t *eipptr = (uint8_t *)&(saved_state->eip);
        
        printf("invalid kernel opcode (32-bit): ");
        print_bytes(eipptr, 16);
        
        /* Fall through to trap */
        return 0;
    }
    
    return 1;
}
#endif


static i386_cpu_info_t	cpuid_cpu_info;
//static i386_cpu_info_t	*cpuid_cpu_infop = NULL;

void opemu_utrap(x86_saved_state_t *state)
{
    i386_cpu_info_t		*info_p = &cpuid_cpu_info;
    
    int longmode;
    
    
    unsigned int bytes_skip = 0;
    
    if ((longmode = is_saved_state64(state)))
    {
        
        x86_saved_state64_t *regs;
        regs = saved_state64(state);
        uint8_t *code_buffer = (uint8_t*)regs->isf.rip;
        
        vm_offset_t addr;
        
        addr = regs->isf.rip;
        uint16_t opcode;
        
        opcode = *(uint16_t *) addr;
        
        if (IsAmdCPU()){
            switch(opcode){
                case 0x340f:
                {
                    for(;;){
                        regs->isf.rip = regs->rdx;
                        regs->isf.rsp = regs->rcx;
                        
                        if((signed int)regs->rax < 0) {
                            //      printf("mach call 64\n");
                            mach_call_munger64(state);
                        } else {
                            //      printf("unix call 64\n");
                            unix_syscall64(state);
                        }
                        
                    }
                    return ;
                }
                    break;
                    
                case 0x350f:
                {
                    for(;;){
                        regs->isf.rip = regs->rdx;
                        regs->isf.rsp = regs->rcx;
                        // if (kernel_trap)
                        // {
                        //     addr = regs->rcx;
                        //     return 0x7FFF;
                        // } else {
                        
                        thread_exception_return();
                        
                    }
                    return ;
                }break;
                    
                    // default:
                    // return;
            }
        }
        
        //if (!(info_p->cpuid_features & CPUID_FEATURE_SSSE3))
        bytes_skip = ssse3_run(code_buffer, state, longmode, 1);
        
        if (!(info_p->cpuid_features & CPUID_FEATURE_SSE3)){
            
            if (!bytes_skip)
            {
                bytes_skip = sse3_run_a(code_buffer, state, longmode, 1);
            }
            
            if (!bytes_skip)
            {
                bytes_skip = sse3_run_b(code_buffer, state, longmode, 1);
            }
            
            if (!bytes_skip)
            {
                bytes_skip = sse3_run_c(code_buffer, state, longmode, 1);
            }
            
            if (!bytes_skip)
            {
                bytes_skip = fisttp_run(code_buffer, state, longmode, 1);
            }
        }
        if(!(info_p->cpuid_features & CPUID_FEATURE_MONITOR))
        {
            if (!bytes_skip)
            {
                bytes_skip = monitor_mwait_run(code_buffer, state, longmode, 1);
            }
        }
        
        //if (bytes_skip != 0xFFFFFFFF)
        regs->isf.rip += bytes_skip;
        //else
        //  memcpy((void *) regs->isf.rip, code_buffer, 15);
        
        if(!bytes_skip) {
            uint8_t *ripptr = (uint8_t *)&(regs->isf.rip);
            
            printf("invalid user opcode 64: ");
            print_bytes(ripptr, 16);
            // Fall through to trap
            return;
        }
        
        
        
        // return 0;
        
    }
    else
    {
        
        uint8_t code_buffer_32[15];
        x86_saved_state32_t *regs;
        regs = saved_state32(state);
        //copyin(regs->eip, (char*) code_buffer_32, 15);
        memcpy(code_buffer_32, (const void *)(uint64_t)regs->eip, 15);
        
        vm_offset_t addr;
        
        addr = regs->eip;
        uint16_t opcode;
        
        opcode = *(uint16_t *) addr;
        
        //if((code_buffer_32[0]==0x0f) && (code_buffer_32[1]==0x34))
        if (IsAmdCPU())
        {
            switch(opcode){
                case 0x340f:
                {
                    for(;;){
                        
                        
                        regs->eip = regs->edx;
                        regs->uesp = regs->ecx;
                        
                        if((signed int)regs->eax < 0) {
                            mach_call_munger(state);
                        } else {
                            unix_syscall(state);
                        }
                        
                        return ;
                    }
                }
                    break;
                    
                case 0x350f:
                {
                    for(;;)
                    {
                        regs->eip = regs->edx;
                        regs->uesp = regs->ecx;
                        
                        thread_exception_return();
                        
                        return ;
                    }
                }
                    break;
                    
                    //default:
                    //  return  0;
            }
        }
        //if(!(info_p->cpuid_features & CPUID_FEATURE_SSSE3))
        bytes_skip = ssse3_run(code_buffer_32, state, longmode, 0);
        
        if(!(info_p->cpuid_features & CPUID_FEATURE_SSE3))
        {
            
            if (!bytes_skip)
            {
                bytes_skip = sse3_run_a(code_buffer_32, state, longmode, 0);
            }
            
            if (!bytes_skip)
            {
                bytes_skip = sse3_run_b(code_buffer_32, state, longmode, 0);
            }
            
            if (!bytes_skip)
            {
                bytes_skip = sse3_run_c(code_buffer_32, state, longmode, 0);
            }
            
            if (!bytes_skip)
            {
                bytes_skip = fisttp_run(code_buffer_32, state, longmode, 0);
            }
        }
        if(!(info_p->cpuid_features & CPUID_FEATURE_MONITOR))
        {
            if (!bytes_skip)
            {
                bytes_skip = monitor_mwait_run(code_buffer_32, state, longmode, 0);
            }
        }
        if (bytes_skip != 0xFFFF)
            regs->eip += bytes_skip;
        else
            memcpy((void *)(uint64_t) regs->eip, code_buffer_32, 15);
        
        //regs->eip += bytes_skip;
        
        if(!bytes_skip) {
            uint8_t *eipptr = (uint8_t *)&(regs->eip);
            
            printf("invalid user opcode 32: ");
            print_bytes(eipptr, 16);
            
            /* Fall through to trap */
            return ;
        }
        
        // return 0;
    }
    
    thread_exception_return();
    /*** NOTREACHED ***/
    
    //return 0;//EMULATION_FAILED;
}

/** Runs the sse3 emulator. returns the number of bytes consumed.
 **/
int sse3_run_a(uint8_t *instruction, x86_saved_state_t *state, int longmode, int kernel_trap)
{
    uint8_t *bytep = instruction;
    int ins_size = 0;
    XMM xmmsrc, xmmdst, xmmres;
    int src_higher = 0, dst_higher = 0;
    
    int modbyte = 0; //Calculate byte 0 - modrm long
    int fisttp = 0;
    int rex = 0; //REX Mode
    int hsreg = 0; //High Source Register Only
    
    //if(*bytep != 0xF2) return 0;
    
    //bytep++;
    //ins_size++;
    
    //if(*bytep != 0x0f) return 0;
    //bytep++;
    //ins_size++;
    if(*bytep == 0xF2 && bytep[1] == 0x0f)
    {
        bytep += 2;
        ins_size += 2;
        modbyte += 4;
        
        uint8_t *modrm = &bytep[1];
        ins_size += 1;
        int consumed = fetchoperands(modrm, src_higher, dst_higher, &xmmsrc, &xmmdst, longmode, state, kernel_trap, 1, rex, hsreg, modbyte, fisttp);
        ins_size += consumed;
        
        
        switch (*bytep)
        {
            case 0x12:
                movddup(&xmmsrc,&xmmres);
                break;
                
            case 0x7C:
                haddps(&xmmsrc,&xmmdst,&xmmres);
                break;
                
            case 0x7D:
                hsubps(&xmmsrc,&xmmdst,&xmmres);
                break;
                
            case 0xD0:
                addsubps(&xmmsrc,&xmmdst,&xmmres);
                break;
                
            case 0xF0:
                lddqu(&xmmsrc,&xmmres);
                break;
                
            default:
                return 0;
        }
        
        storeresult128(*modrm, dst_higher, xmmres);
    }
    
    return ins_size;
}

int sse3_run_b(uint8_t *instruction, x86_saved_state_t *state, int longmode, int kernel_trap)
{
    uint8_t *bytep = instruction;
    int ins_size = 0;
    XMM xmmsrc, xmmdst, xmmres;
    int src_higher = 0, dst_higher = 0;
    int modbyte = 0; //Calculate byte 0 - modrm long
    int fisttp = 0;
    int rex = 0; //REX Mode
    int hsreg = 0; //High Source Register Only
    
    /*if(*bytep != 0xF3) return 0;
     
     bytep++;
     ins_size++;
     
     if(*bytep != 0x0f) return 0;
     bytep++;
     ins_size++;*/
    
    if(*bytep == 0xF3 && bytep[1] == 0x0f)
    {
        bytep += 2;
        ins_size += 2;
        modbyte += 4;
        
        uint8_t *modrm = &bytep[1];
        ins_size += 1;
        int consumed = fetchoperands(modrm, src_higher, dst_higher, &xmmsrc, &xmmdst, longmode, state, kernel_trap, 1, rex, hsreg, modbyte, fisttp);
        ins_size += consumed;
        
        switch (*bytep)
        {
            case 0x12:
                movsldup(&xmmsrc,&xmmres);
                break;
                
            case 0x16:
                movshdup(&xmmsrc,&xmmres);
                break;
                
            default:
                return 0;
        }
        
        storeresult128(*modrm, dst_higher, xmmres);
    }
    
    return ins_size;
}

int sse3_run_c(uint8_t *instruction, x86_saved_state_t *state, int longmode, int kernel_trap)
{
    uint8_t *bytep = instruction;
    int ins_size = 0;
    XMM xmmsrc, xmmdst, xmmres;
    int src_higher = 0, dst_higher = 0;
    
    int modbyte = 0; //Calculate byte 0 - modrm long
    int fisttp = 0;
    int rex = 0; //REX Mode
    int hsreg = 0; //High Source Register Only
    
    /* if(*bytep != 0x66) return 0;
     
     bytep++;
     ins_size++;
     
     if(*bytep != 0x0f) return 0;
     bytep++;
     ins_size++;
     */
    
    if(*bytep == 0x66 && bytep[1] == 0x0f)
    {
        bytep += 2;
        ins_size += 2;
        modbyte += 4;
        
        uint8_t *modrm = &bytep[1];
        ins_size += 1;
        int consumed = fetchoperands(modrm, src_higher, dst_higher, &xmmsrc, &xmmdst, longmode, state, kernel_trap, 1, rex, hsreg, modbyte, fisttp);
        ins_size += consumed;
        
        
        switch (*bytep)
        {
            case 0x7C:
                haddpd(&xmmsrc,&xmmdst,&xmmres);
                break;
                
            case 0x7D:
                hsubpd(&xmmsrc,&xmmdst,&xmmres);
                break;
                
            case 0xD0:
                addsubpd(&xmmsrc,&xmmdst,&xmmres);
                break;
                
            default:
                return 0;
        }
        
        storeresult128(*modrm, dst_higher, xmmres);
    }
    
    return ins_size;
}

int fisttp_run(uint8_t *instruction, x86_saved_state_t *state, int longmode, int kernel_trap)
{
    uint8_t *bytep = instruction;
    int ins_size = 0;
    XMM xmmsrc, xmmdst, xmmres;
    int src_higher = 0, dst_higher = 0;
    int modbyte = 0; //Calculate byte 0 - modrm long
    int fisttp = 0;
    int rex = 0; //REX Mode
    int hsreg = 0; //High Source Register Only
    
    if ((*bytep == 0x66 && bytep[1] == 0xDB)||(*bytep == 0x66 && bytep[1] == 0xDD)||(*bytep == 0x66 && bytep[1] == 0xDF))
    {
        bytep++;
        ins_size += 2;
        modbyte += 3;
        
        switch (*bytep)
        {
            case 0xDB: //fild 0x66 0xDB
                fisttp = 1;
                break;
            case 0xDD: //fld 0x66 0xDD
                fisttp = 2;
                break;
            case 0xDF: //fild 0x66 0xDF
                fisttp = 3;
                break;
        }
        
        uint8_t *modrm = &bytep[1];
        int consumed = fetchoperands(modrm, src_higher, dst_higher, &xmmsrc, &xmmdst, longmode, state, kernel_trap, 1, rex, hsreg, modbyte, fisttp);
        ins_size += consumed;
        
        storeresult128(*modrm, dst_higher, xmmres);
        
    }
    return ins_size;
    
}

int monitor_mwait_run(uint8_t *instruction, __unused x86_saved_state_t *  state, int __unused longmode, int __unused kernel_trap)
{
    uint8_t *bytep = instruction;
    int ins_size = 0;
    /*if (*bytep != 0x0F)
     {
     return 0;
     }
     
     bytep++;
     
     if (*bytep != 0x01)
     {
     return 0;
     }
     
     bytep++;
     
     switch(*bytep)
     {
     case 0xC8:
     case 0xC9:
     return 3;
     }
     
     return 0;*/
    
    if(*bytep == 0x0F && bytep[1] == 0x01)
    {
        
        bytep += 2;
        ins_size += 3;
        
        switch(*bytep)
        {
                
            case 0xC8: break; //monitor: 0x0f,0x01,0xc8
            case 0xC9: break; //mwait: 0x0f,0x01,0xc9
            default: return 0;
        }
        
    }
    return ins_size;
    
}

/** Runs the ssse3 emulator. returns the number of bytes consumed.
 **/
int ssse3_run(uint8_t *instruction, x86_saved_state_t *state, int longmode, int kernel_trap)
{
    // pointer to the current byte we're working on
    uint8_t *bytep = instruction;
    int ins_size = 0;
    int is_128 = 0, src_higher = 0, dst_higher = 0;
    int modbyte = 0; //Calculate byte 0 - modrm long
    int fisttp = 0;
    int rex = 0; //REX Mode
    int hsreg = 0; //High Source Register Only
    
    XMM xmmsrc, xmmdst, xmmres;
    MM mmsrc,mmdst, mmres;
    
    
    /** We can get a few prefixes, in any order:
     **  66 throws into 128-bit xmm mode.
     **  40->4f use higher xmm registers.
     **/
    if(*bytep == 0x66) {
        is_128 = 1;
        bytep++;
        ins_size++;
        modbyte++;
    }
    if((*bytep & 0xF0) == 0x40)
    {
        rex = 1;
        if(*bytep & 1) src_higher = 1;
        if(*bytep & 4) dst_higher = 1;
        /*** High Source Register Only ***/
        if((*bytep == 0x41)||(*bytep == 0x43)||(*bytep == 0x49)||(*bytep == 0x4B))
            hsreg = 1;
        
        bytep++;
        ins_size++;
        modbyte++;
    }
    
    if(*bytep != 0x0f) return 0;
    bytep++;
    ins_size++;
    modbyte++;
    
    /* Two SSSE3 instruction prefixes. */
    if((*bytep == 0x38 && bytep[1] != 0x0f) || (*bytep == 0x3a && bytep[1] == 0x0f)) {
        uint8_t opcode = bytep[1];
        uint8_t *modrm = &bytep[2];
        uint32_t imm;
        
        //uint32_t operand;
        
        // uint8_t mod = *modrm >> 6;
        // uint8_t num_src = *modrm & 0x7;
        // uint8_t base = modrm[1] & 0x7;
        
        
        /* if (mod == 0)
         {
         if (num_src == 4)
         if(base == 5) imm = bytep[8];//modrm offset + 6
         else imm = bytep[4];//modrm offset + 2
         else if (num_src == 5) imm = bytep[7];//modrm offset + 5
         else imm = bytep[3];//modrm offset + 1
         }
         
         if (mod == 1)
         {
         if(num_src == 4) imm = bytep[5];//modrm offset + 3
         else imm = bytep[4];//modrm offset + 2
         }
         
         if (mod == 2)
         {
         if(num_src == 4) imm = bytep[8];//modrm offset + 6
         else imm = bytep[7];//modrm offset + 5
         }
         
         if (mod == 3) imm = bytep[3];//modrm offset + 1
         */
        
        ins_size += 2; // not counting modRM byte or anything after.
        
        if(*bytep == 0x3a && bytep[1] == 0x0f) modbyte += 4;
        else modbyte += 3;
        
        if(is_128) {
            
            XMM *src, *dst, *rs;
            src = &xmmsrc;
            dst = &xmmdst;
            rs = &xmmres;
            int consumed=0;
            
            if(ins_size == 4)
                consumed = fetchoperands(modrm, src_higher, dst_higher, src, dst, longmode, state, kernel_trap, 1, rex, hsreg, modbyte, fisttp);
            else
                if(ins_size == 5)
                    consumed = fetchoperands(modrm, src_higher, dst_higher, src, dst, longmode, state, kernel_trap, 1, rex, hsreg, modbyte, fisttp);
            
            imm = bytep[2 + consumed];
            
            ins_size += consumed;
            
            //getxmm(dst, dst_higher);
            
            switch(opcode) {
                case 0x00: pshufb128(src,dst,rs); break;
                case 0x01: phaddw128(src,dst,rs); break;
                case 0x02: phaddd128(src,dst,rs); break;
                case 0x03: phaddsw128(src,dst,rs); break;
                case 0x04: pmaddubsw128(src,dst,rs); break;
                case 0x05: phsubw128(src,dst,rs); break;
                case 0x06: phsubd128(src,dst,rs); break;
                case 0x07: phsubsw128(src,dst,rs); break;
                case 0x08: psignb128(src,dst,rs); break;
                case 0x09: psignw128(src,dst,rs); break;
                case 0x0A: psignd128(src,dst,rs); break;
                case 0x0B: pmulhrsw128(src,dst,rs); break;
                case 0x0F: palignr128(src, dst,rs,imm);
                    ins_size++;
                    // printf("ins_size %d\n",ins_size);
                    break;
                case 0x1C: pabsb128(src,rs); break;
                case 0x1D: pabsw128(src,rs); break;
                case 0x1E: pabsd128(src,rs); break;
                default: return 0;
            }
            
            storeresult128(*modrm, dst_higher, xmmres);
            
        } else {
            
            MM *src, *dst, *rs;
            src = &mmsrc;
            dst = &mmdst;
            rs = &mmres;
            int consumed=0;
            
            consumed = fetchoperands(modrm, src_higher, dst_higher, src, dst, longmode, state, kernel_trap, 0, rex, hsreg, modbyte, fisttp);
            
            imm = bytep[2 + consumed];
            
            ins_size += consumed;
            
            
            switch(opcode) {
                case 0x00:pshufb64(src,dst,rs); break;
                case 0x01:phaddw64(src,dst,rs); break;
                case 0x02:phaddd64(src,dst,rs); break;
                case 0x03:phaddsw64(src,dst,rs);break;
                case 0x04:pmaddubsw64(src,dst,rs);break;
                case 0x05:phsubw64(src,dst,rs);break;
                case 0x06:phsubd64(src,dst,rs);break;
                case 0x07:phsubsw64(src,dst,rs);break;
                case 0x08:psignb64(src,dst,rs);break;
                case 0x09:psignw64(src,dst,rs);break;
                case 0x0A:psignd64(src,dst,rs);break;
                case 0x0B:pmulhrsw64(src,dst,rs);break;
                case 0x0F:palignr64(src, dst,rs, imm);
                    ins_size++;
                    break;
                case 0x1C:pabsb64(src,rs);break;
                case 0x1D:pabsw64(src,rs);break;
                case 0x1E:pabsd64(src,rs);break;
                default:
                    return 0;
            }
            
            storeresult64(*modrm, dst_higher, *rs);
        }
        
    } else {
        // opcode wasn't handled here
        return 0;
    }
    
    return ins_size;
}

void print_bytes(uint8_t *from, int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        printf("%02x ", from[i]);
    }
    printf("\n");
}

/** Fetch SSSE3 operands (except immediate values, which are fetched elsewhere).
 * We depend on memory copies, which differs depending on whether we're in kernel space
 * or not. For this reason, need to pass in a lot of information, including the state of
 * registers.
 *
 * The return value is the number of bytes used, including the ModRM byte,
 * and displacement values, as well as SIB if used.
 */
int fetchoperands(uint8_t *ModRM, unsigned int hsrc, unsigned int hdst, void *src, void *dst, unsigned int longmode, x86_saved_state_t *saved_state, int kernel_trap, int size_128, int  __unused rex, int __unused hsreg, int modbyte, int fisttp)
{
    unsigned int num_src = *ModRM & 0x7;
    unsigned int num_dst = (*ModRM >> 3) & 0x7;
    unsigned int mod = *ModRM >> 6;
    int consumed = 1;
    uint8_t bytelong = 0x00;
    
    if(hsrc) num_src += 8;
    if(hdst) num_dst += 8;
    //printf("dst : %d\n",dst);
    if(size_128) getxmm((XMM*)dst, num_dst);
    else getmm((MM*)dst, num_dst);
    
    if(mod == 3) {
        if(size_128) getxmm((XMM*)src, num_src);
        else getmm((MM*)src, num_src);
    } else if ((longmode = is_saved_state64(saved_state))) {
        uint64_t address;
        
        // DST is always an XMM register. decode for SRC.
        uint64_t reg_sel[8] ;
        x86_saved_state64_t* r64 = saved_state64(saved_state);
        if (hsrc)
        {
            reg_sel[0] = r64->r8;
            reg_sel[1] = r64->r9;
            reg_sel[2] = r64->r10;
            reg_sel[3] = r64->r11;
            reg_sel[4] = r64->r12;
            reg_sel[5] = r64->r13;
            reg_sel[6] = r64->r14;
            reg_sel[7] = r64->r15;
        }
        else
        {
            reg_sel[0] = r64->rax;
            reg_sel[1] = r64->rcx;
            reg_sel[2] = r64->rdx;
            reg_sel[3] = r64->rbx;
            reg_sel[4] = r64->isf.rsp;
            reg_sel[5] = r64->rbp;
            reg_sel[6] = r64->rsi;
            reg_sel[7] = r64->rdi;
        }
        
        
        // if(hsrc) printf("opemu error: high reg ssse\n"); // FIXME
        
        uint8_t scale = ModRM[1] >> 6; //40 byte + 1
        uint8_t base = ModRM[1] & 0x7; //1 byte + 1 regs loop
        uint8_t index = (ModRM[1] >> 3) & 0x7; //8 byte + 1 regs loop
        
        /*uint8_t factor; //Scaling factor
         if (scale == 0) factor = 1;
         else if (scale == 1) factor = 2;
         else if (scale == 2) factor = 4;
         else if (scale == 3) factor = 8;
         */
        if (mod == 0) //mod field = 00b
        {
            if (num_src == 4)
            {
                
                if(base == 5) //Base Register = RBP
                {
                    if(index == 4) //Base Register = RBP & Index Register = RSP
                    {
                        //ModRM              0  1  2  3  4  5
                        //byte   0  1  2  3  4  5  6  7  8  9
                        //OPCPDE 66 0F 38 01 04 25 04 03 02 01
                        //INS    phaddw xmm0, xmmword [ds:0x1020304]
                        //PTR = Disp32
                        bytelong = modbyte + 5;
                        uint64_t ModRMVal = (uint64_t)&ModRM[2];
                        int32_t *ModRMCast = (int32_t *)ModRMVal;
                        address = r64->isf.rip + bytelong + *ModRMCast;
                        consumed += 5;
                    }
                    else //base 5 & Not Index 4
                    {
                        //ModRM              0  1  2  3  4  5
                        //byte   0  1  2  3  4  5  6  7  8  9
                        //OPCPDE 66 0F 38 01 04 05 04 03 02 01
                        //INS    phaddw xmm0, xmmword [ds:0x1020304+rax]
                        //PTR = Disp32 + (Index*Scale)
                        bytelong = modbyte + 5;
                        uint64_t ModRMVal = (uint64_t)&ModRM[2];
                        int32_t *ModRMCast = (int32_t *)ModRMVal;
                        address = (r64->isf.rip + bytelong + *ModRMCast) + (reg_sel[index] * (1<<scale));
                        consumed += 5;
                    }
                }
                else //Not Base 5
                {
                    if (index == 4) // Index Register = RSP
                    {
                        //ModRM              0  1
                        //byte   0  1  2  3  4  5
                        //OPCPDE 66 0F 38 01 04 61
                        //INS    phaddw xmm0, xmmword [ds:rcx]
                        //PTR = Base
                        address = reg_sel[base];
                        consumed++;
                    }
                    else //SIB General Mode
                    {
                        //ModRM              0  1
                        //byte   0  1  2  3  4  5
                        //OPCPDE 66 0F 38 01 04 44
                        //INS    phaddw xmm0, xmmword ptr [rsp+rax*2]
                        //PTR = Base + (Index*Scale)
                        address = reg_sel[base] + (reg_sel[index] * (1<<scale));
                        consumed++;
                    }
                }
            }
            else if (num_src == 5)
            {
                //ModRM              0  1  2  3  4
                //BYTE   0  1  2  3  4  5  6  7  8
                //OPCPDE 66 0F 38 01 05 01 02 03 04
                //INS    phaddw xmm0, xmmword ptr [cs:04030201h]
                //PTR = Disp32
                bytelong = modbyte + 4;
                uint64_t ModRMVal = (uint64_t)&ModRM[consumed];
                int32_t *ModRMCast = (int32_t *)ModRMVal;
                address = r64->isf.rip + bytelong + *ModRMCast;
                consumed += 4;
                /***DEBUG***/
                //int32_t ds = *((int32_t*)&ModRM[1]);
                //printf("DEBUG-MSG: byte=%x, RIP=%llx ,DS=%d, PTR = %llx\n", bytelong , r64->isf.rip, ds, address);
                /***DEBUG***/
            }
            else /*** General Mode ***/
            {
                //ModRM              0
                //BYTE   0  1  2  3  4
                //OPCPDE 66 0F 38 01 03
                //INS    phaddw xmm0, xmmword [ds:rbx]
                //PTR = R/M
                address = reg_sel[num_src];
            }
        }
        
        if (mod == 1) //mod field = 01b
        {
            if(num_src == 4)
            {
                if (index == 4) // Index Register = RSP
                {
                    //ModRM              0  1  2
                    //BYTE   0  1  2  3  4  5  6
                    //OPCPDE 66 0F 38 01 44 27 80
                    //INS    phaddw xmm0, xmmword ptr [rdi-80h]
                    //PTR = Base + Disp8
                    address = reg_sel[base] + (int8_t)ModRM[2];
                    consumed+= 2;
                }
                else //SIB General Mode
                {
                    //ModRM              0  1  2
                    //BYTE   0  1  2  3  4  5  6
                    //OPCPDE 66 0F 38 01 44 44 80
                    //INS    phaddw xmm0, xmmword ptr [rsp+rax*2-80h]
                    //PTR = Base + (Index*Scale) + Disp8
                    address = reg_sel[base] + (reg_sel[index] * (1<<scale)) + (int8_t)ModRM[2];
                    consumed+= 2;
                }
            }
            else  /*** General Mode ***/
            {
                //ModRM              0  1
                //BYTE   0  1  2  3  4  5
                //OPCPDE 66 0F 38 01 43 01
                //INS    phaddw xmm0, xmmword [ds:rbx+0x1]
                //PTR = R/M + Disp8
                address = reg_sel[num_src] + (int8_t)ModRM[consumed];
                consumed++;
            }
        }
        
        if (mod == 2)
        {
            if(num_src == 4)
            {
                
                if (index == 4) // Index Register = RSP
                {
                    //ModRM              0  1  2  3  4  5
                    //BYTE   0  1  2  3  4  5  6  7  8  9
                    //OPCPDE 66 0F 38 01 84 20 04 03 02 01
                    //INS    phaddw xmm0, xmmword ptr [rax+1020304h]
                    //PTR = Base + Disp32
                    bytelong = modbyte + 5;
                    uint64_t ModRMVal = (uint64_t)&ModRM[2];
                    int32_t *ModRMCast = (int32_t *)ModRMVal;
                    address = reg_sel[base] + (r64->isf.rip + bytelong + *ModRMCast);//Bronzovka: Here fix ...
                    consumed += 5;
                }
                else //SIB General Mode
                {
                    //ModRM              0  1  2  3  4  5
                    //BYTE   0  1  2  3  4  5  6  7  8  9
                    //OPCPDE 66 0F 38 01 84 44 04 03 02 01
                    //INS    phaddw xmm0, xmmword ptr [rsp+rax*2+1020304h]
                    //PTR = Base + (Index*Scale) + Disp32
                    bytelong = modbyte + 5;
                    uint64_t ModRMVal = (uint64_t)&ModRM[2];
                    int32_t *ModRMCast = (int32_t *)ModRMVal;
                    address = reg_sel[base] + (reg_sel[index] * (1<<scale)) + (r64->isf.rip + bytelong + *ModRMCast);
                    consumed += 5;
                }
                
            }
            else /*** General Mode ***/
            {
                //ModRM              0  1  2  3  4
                //BYTE   0  1  2  3  4  5  6  7  8
                //OPCPDE 66 0F 38 01 83 01 02 03 04
                //INS    phaddw xmm0, xmmword [ds:rbx+0x4030201]
                //PTR = R/M + Disp32
                bytelong = modbyte + 4;
                uint64_t ModRMVal = (uint64_t)&ModRM[consumed];
                int32_t *ModRMCast = (int32_t *)ModRMVal;
                address = reg_sel[num_src] + (r64->isf.rip + bytelong + *ModRMCast);
                consumed += 4;
            }
        }
        
        if (fisttp == 1) //fild 0x66 0xDB
        {
            *(int *)address = fisttpl((double *)address);
        }
        else if (fisttp == 2) //fld 0x66 0xDD
        {
            *(long long *)address = fisttpq((long double *)address);
        }
        else if (fisttp == 3) //fild 0x66 0xDF
        {
            *(short *)address = fisttps((float *)address);
        }
        else //fisttp = 0
        {
            
            // address is good now, do read and store operands.
            if(kernel_trap)
            {
                if(size_128) ((XMM*)src)->ui = (*(__uint128_t*)address);
                else ((MM*)src)->u64 = (*(uint64_t*)address);
            } else {
                //printf("xnu: da = %llx, rsp=%llx,  rip=%llx\n", address, reg_sel[4], r64->isf.rip);
                if(size_128) copyin(address, (char*)& ((XMM*)src)->ui, 16);
                else copyin(address, (char*)& ((MM*)src)->u64, 8);
            }
        }
    }else {
        // AnV - Implemented 32-bit fetch
        uint32_t address;
        
        // DST is always an XMM register. decode for SRC.
        uint32_t reg_sel[8] ;
        x86_saved_state32_t* r32 = saved_state32(saved_state);
        
        reg_sel[0] = r32->eax;
        reg_sel[1] = r32->ecx;
        reg_sel[2] = r32->edx;
        reg_sel[3] = r32->ebx;
        reg_sel[4] = r32->uesp;
        reg_sel[5] = r32->ebp;
        reg_sel[6] = r32->esi;
        reg_sel[7] = r32->edi;
        
        uint8_t scale = ModRM[1] >> 6; //40 byte + 1
        uint8_t base = ModRM[1] & 0x7; //1 byte + 1 reg loop
        uint8_t index = (ModRM[1] >> 3) & 0x7; //8 byte + 1 reg loop
        
        /*uint8_t factor; //Scaling factor
         if (scale == 0) factor = 1;
         else if (scale == 1) factor = 2;
         else if (scale == 2) factor = 4;
         else if (scale == 3) factor = 8;
         */
        if(hsrc) printf("opemu error: high reg ssse\n"); // FIXME
        
        if (mod == 0)
        {
            if (num_src == 4)
            {
                if(base == 5) // Base Register = EBP
                {
                    if(index == 4) // Index Register = ESP & Base Register = EBP
                    {
                        //ModRM           0  1  2  3  4  5
                        //byte   0  1  2  3  4  5  6  7  8
                        //OPCPDE 0F 38 01 04 25 04 03 02 01
                        //INS    phaddw mm0, qword [ds:0x1020304]
                        //PTR = DISP32 OFFSET
                        uint64_t ModRMVal = (uint64_t)&ModRM[2];
                        int32_t *ModRMCast = (int32_t *)ModRMVal;
                        address = *ModRMCast;
                        consumed += 5;
                    }
                    else //base 5 & Not Index 4
                    {
                        //ModRM           0  1  2  3  4  5
                        //byte   0  1  2  3  4  5  6  7  8
                        //OPCPDE 0F 38 01 04 05 04 03 02 01
                        //INS    phaddw mm0, qword [ds:0x1020304+rax]
                        //PTR = (DISP32 OFFSET) + (INDEX REG * SCALE)
                        uint64_t ModRMVal = (uint64_t)&ModRM[2];
                        int32_t *ModRMCast = (int32_t *)ModRMVal;
                        address = *ModRMCast + (reg_sel[index] * (1<<scale));
                        consumed += 5;
                    }
                }
                else //Not base 5
                {
                    if (index == 4) // Index Register = ESP
                    {
                        //ModRM           0  1
                        //byte   0  1  2  3  4
                        //OPCPDE 0F 38 01 04 61
                        //INS    phaddw mm0, qword [ds:rcx]
                        address = reg_sel[base];
                        consumed++;
                    }
                    else //SIB General Mode
                    {
                        //ModRM           0  1
                        //byte   0  1  2  3  4
                        //OPCPDE 0F 38 01 04 44
                        //INS    phaddw mm0, qword ptr [rsp+rax*2]
                        address = reg_sel[base] + (reg_sel[index] * (1<<scale));
                        consumed++;
                    }
                }
            }
            else if (num_src == 5)
            {
                //ModRM           0  1  2  3  4
                //BYTE   0  1  2  3  4  5  6  7
                //OPCPDE 0F 38 01 05 01 02 03 04
                //INS    phaddw mm0, qword ptr [cs:04030201h]
                //PTR = DISP32 OFFSET
                uint64_t ModRMVal = (uint64_t)&ModRM[consumed];
                int32_t *ModRMCast = (int32_t *)ModRMVal;
                address = *ModRMCast;
                consumed += 4;
            }
            else /*** General Mode ***/
            {
                //ModRM           0
                //BYTE   0  1  2  3
                //OPCPDE 0F 38 01 03
                //INS    phaddw mm0, qword [ds:rbx]
                address = reg_sel[num_src];
            }
        }
        
        if (mod == 1) //mod field = 01b
        {
            if(num_src == 4)
            {
                if (index == 4) // Index Register = ESP
                {
                    //ModRM           0  1  2
                    //BYTE   0  1  2  3  4  5
                    //OPCPDE 0F 38 01 44 27 80
                    //INS    phaddw mm0, qword ptr [rdi-80h]
                    //PTR = BASE REG + (DISP8 OFFSET)
                    address = reg_sel[base] + *((int8_t*)&ModRM[2]);
                    consumed+= 2;
                }
                else //SIB General Mode
                {
                    //ModRM           0  1  2
                    //BYTE   0  1  2  3  4  5
                    //OPCPDE 0F 38 01 44 44 80
                    //INS    phaddw mm0, qword ptr [rsp+rax*2-80h]
                    //PTR = BASE REG + (INDEX REG * SCALE) + (DISP8 OFFSET)
                    address = reg_sel[base] + (reg_sel[index] * (1<<scale)) + *((int8_t*)&ModRM[2]);
                    consumed+= 2;
                }
            }
            else /*** General Mode ***/
            {
                //ModRM           0  1
                //BYTE   0  1  2  3  4
                //OPCPDE 0F 38 01 43 01
                //INS    phaddw mm0, qword [ds:rbx+0x1]
                //PTR = R/M REG + (DISP8 OFFSET)
                address = reg_sel[num_src] + *((int8_t*)&ModRM[1]);
                consumed++;
            }
        }
        
        if (mod == 2)
        {
            if(num_src == 4)
            {
                
                if (index == 4) // Index Register = ESP
                {
                    //ModRM           0  1  2  3  4  5
                    //BYTE   0  1  2  3  4  5  6  7  8
                    //OPCPDE 0F 38 01 84 20 04 03 02 01
                    //INS    phaddw mm0, qword ptr [rax+1020304h]
                    //PTR = BASE REG + (DISP32 OFFSET)
                    uint64_t ModRMVal = (uint64_t)&ModRM[2];
                    int32_t *ModRMCast = (int32_t *)ModRMVal;
                    address = reg_sel[base] + *ModRMCast;
                    consumed += 5;
                }
                else //SIB General Mode
                {
                    //ModRM           0  1  2  3  4  5
                    //BYTE   0  1  2  3  4  5  6  7  8
                    //OPCPDE 0F 38 01 84 44 04 03 02 01
                    //INS    phaddw mm0, qword ptr [rsp+rax*2+1020304h]
                    //PTR = BASE REG + (INDEX REG * SCALE) + (DISP32 OFFSET)
                    uint64_t ModRMVal = (uint64_t)&ModRM[2];
                    int32_t *ModRMCast = (int32_t *)ModRMVal;
                    address = reg_sel[base] + (reg_sel[index] * (1<<scale)) + *ModRMCast;
                    consumed += 5;
                }
                
            }
            else /*** General Mode ***/
            {
                //ModRM           0  1  2  3  4
                //BYTE   0  1  2  3  4  5  6  7
                //OPCPDE 0F 38 01 83 01 02 03 04
                //INS    phaddw mm0, qword [ds:rbx+0x4030201]
                //PTR = R/M REG + (DISP32 OFFSET)
                uint64_t ModRMVal = (uint64_t)&ModRM[consumed];
                int32_t *ModRMCast = (int32_t *)ModRMVal;
                address = reg_sel[num_src] + *ModRMCast;
                consumed += 4;
            }
        }
        
        uint64_t addr = address;
        
        if (fisttp == 1) //fild 0x66 0xDB
        {
            *(int *)addr = fisttpl((double *)addr);
        }
        else if (fisttp == 2) //fld 0x66 0xDD
        {
            *(long long *)addr = fisttpq((long double *)addr);
        }
        else if (fisttp == 3) //fild 0x66 0xDF
        {
            *(short *)addr = fisttps((float *)addr);
        }
        else //fisttp = 0
        {
            
            // address is good now, do read and store operands.
            
            
            if(kernel_trap)
            {
                if(size_128) ((XMM*)src)->ui = *(__uint128_t *)addr;
                else ((MM*)src)->u64 = *(uint64_t *)addr;
            }
            else
            {
                //printf("xnu: da = %llx, rsp=%llx,  rip=%llx\n", address, reg_sel[4], r32->eip);
                if(size_128) copyin(addr, (char*) &((XMM*)src)->ui, 16);
                else copyin(addr, (char*) &((MM*)src)->u64, 8);
            }
        }
    }
    //AnV - Implemented 32-bit fetch END
    return consumed;
}

void storeresult128(uint8_t ModRM, unsigned int hdst, XMM res)
{
    unsigned int num_dst = (ModRM >> 3) & 0x7;
    if(hdst) num_dst += 8;
    movxmm(&res, num_dst);
}

void storeresult64(uint8_t ModRM, unsigned int __unused hdst, MM res)
{
    unsigned int num_dst = (ModRM >> 3) & 0x7;
    movmm(&res, num_dst);
}

#endif /* TESTCASE */

/* get value from the xmm register i */
void getxmm(XMM *xmm_reg, uint32_t i)
{
    switch(i) {
        case 0:
            asm __volatile__ ("movdqu %%xmm0, %0" : "=m" (*xmm_reg));
            break;
        case 1:
            asm __volatile__ ("movdqu %%xmm1, %0" : "=m" (*xmm_reg));
            break;
        case 2:
            asm __volatile__ ("movdqu %%xmm2, %0" : "=m" (*xmm_reg));
            break;
        case 3:
            asm __volatile__ ("movdqu %%xmm3, %0" : "=m" (*xmm_reg));
            break;
        case 4:
            asm __volatile__ ("movdqu %%xmm4, %0" : "=m" (*xmm_reg));
            break;
        case 5:
            asm __volatile__ ("movdqu %%xmm5, %0" : "=m" (*xmm_reg));
            break;
        case 6:
            asm __volatile__ ("movdqu %%xmm6, %0" : "=m" (*xmm_reg));
            break;
        case 7:
            asm __volatile__ ("movdqu %%xmm7, %0" : "=m" (*xmm_reg));
            break;
#ifdef __x86_64__
        case 8:
            asm __volatile__ ("movdqu %%xmm8, %0" : "=m" (*xmm_reg));
            break;
        case 9:
            asm __volatile__ ("movdqu %%xmm9, %0" : "=m" (*xmm_reg));
            break;
        case 10:
            asm __volatile__ ("movdqu %%xmm10, %0" : "=m" (*xmm_reg));
            break;
        case 11:
            asm __volatile__ ("movdqu %%xmm11, %0" : "=m" (*xmm_reg));
            break;
        case 12:
            asm __volatile__ ("movdqu %%xmm12, %0" : "=m" (*xmm_reg));
            break;
        case 13:
            asm __volatile__ ("movdqu %%xmm13, %0" : "=m" (*xmm_reg));
            break;
        case 14:
            asm __volatile__ ("movdqu %%xmm14, %0" : "=m" (*xmm_reg));
            break;
        case 15:
            asm __volatile__ ("movdqu %%xmm15, %0" : "=m" (*xmm_reg));
            break;
#endif
    }
    
}

/* get value from the mm register i  */
void getmm(MM *v, unsigned int i)
{
    switch(i) {
        case 0:
            asm __volatile__ ("movq %%mm0, %0" : "=m" (*v));
            break;
        case 1:
            asm __volatile__ ("movq %%mm1, %0" : "=m" (*v));
            break;
        case 2:
            asm __volatile__ ("movq %%mm2, %0" : "=m" (*v));
            break;
        case 3:
            asm __volatile__ ("movq %%mm3, %0" : "=m" (*v));
            break;
        case 4:
            asm __volatile__ ("movq %%mm4, %0" : "=m" (*v));
            break;
        case 5:
            asm __volatile__ ("movq %%mm5, %0" : "=m" (*v));
            break;
        case 6:
            asm __volatile__ ("movq %%mm6, %0" : "=m" (*v));
            break;
        case 7:
            asm __volatile__ ("movq %%mm7, %0" : "=m" (*v));
            break;
    }
}

/* move value over to xmm register i */
void movxmm(XMM *xmm_reg, unsigned int i)
{
    switch(i) {
        case 0:
            asm __volatile__ ("movdqu %0, %%xmm0" :  : "m" (*xmm_reg) : "%xmm0"  );
            break;
        case 1:
            asm __volatile__ ("movdqu %0, %%xmm1" :  : "m" (*xmm_reg) : "%xmm1"  );
            break;
        case 2:
            asm __volatile__ ("movdqu %0, %%xmm2" :  : "m" (*xmm_reg) : "%xmm2"  );
            break;
        case 3:
            asm __volatile__ ("movdqu %0, %%xmm3" :  : "m" (*xmm_reg) : "%xmm3"  );
            break;
        case 4:
            asm __volatile__ ("movdqu %0, %%xmm4" :  : "m" (*xmm_reg) : "%xmm4"  );
            break;
        case 5:
            asm __volatile__ ("movdqu %0, %%xmm5" :  : "m" (*xmm_reg) : "%xmm5"  );
            break;
        case 6:
            asm __volatile__ ("movdqu %0, %%xmm6" :  : "m" (*xmm_reg) : "%xmm6"  );
            break;
        case 7:
            asm __volatile__ ("movdqu %0, %%xmm7" :  : "m" (*xmm_reg) : "%xmm7"  );
            break;
#ifdef __x86_64__
        case 8:
            asm __volatile__ ("movdqu %0, %%xmm8" :  : "m" (*xmm_reg) : "%xmm8"  );
            break;
        case 9:
            asm __volatile__ ("movdqu %0, %%xmm9" :  : "m" (*xmm_reg) : "%xmm9"  );
            break;
        case 10:
            asm __volatile__ ("movdqu %0, %%xmm10" :  : "m" (*xmm_reg) : "%xmm10"  );
            break;
        case 11:
            asm __volatile__ ("movdqu %0, %%xmm11" :  : "m" (*xmm_reg) : "%xmm11"  );
            break;
        case 12:
            asm __volatile__ ("movdqu %0, %%xmm12" :  : "m" (*xmm_reg) : "%xmm12"  );
            break;
        case 13:
            asm __volatile__ ("movdqu %0, %%xmm13" :  : "m" (*xmm_reg) : "%xmm13"  );
            break;
        case 14:
            asm __volatile__ ("movdqu %0, %%xmm14" :  : "m" (*xmm_reg) : "%xmm14"  );
            break;
        case 15:
            asm __volatile__ ("movdqu %0, %%xmm15" :  : "m" (*xmm_reg) : "%xmm15"  );
            break;
#endif
    }
}

/* move value over to mm register i */
void movmm(MM *mm_reg, unsigned int i)
{
    switch(i) {
        case 0:
            asm __volatile__ ("movq %0, %%mm0" :  : "m" (*mm_reg) : "%mm0"  );
            break;
        case 1:
            asm __volatile__ ("movq %0, %%mm1" :  : "m" (*mm_reg) : "%mm1"  );
            break;
        case 2:
            asm __volatile__ ("movq %0, %%mm2" :  : "m" (*mm_reg) : "%mm2"  );
            break;
        case 3:
            asm __volatile__ ("movq %0, %%mm3" :  : "m" (*mm_reg) : "%mm3"  );
            break;
        case 4:
            asm __volatile__ ("movq %0, %%mm4" :  : "m" (*mm_reg) : "%mm4"  );
            break;
        case 5:
            asm __volatile__ ("movq %0, %%mm5" :  : "m" (*mm_reg) : "%mm5"  );
            break;
        case 6:
            asm __volatile__ ("movq %0, %%mm6" :  : "m" (*mm_reg) : "%mm6"  );
            break;
        case 7:
            asm __volatile__ ("movq %0, %%mm7" :  : "m" (*mm_reg) : "%mm7"  );
            break;
    }
}

/** AnV - New auto generation of fisttpX using compiler cast
 ** Works correct when no SSSE3 extensions are used
 **/
short fisttps(float *res)
{
    /*float value = opemu_truncf(*res);
     __asm__ ("fistps %0" : : "m" (value));
     *res = value;*/
    return (short)*(res);
}

int fisttpl(double *res)
{
    /*double value = opemu_trunc(*res);
     __asm__ ("fistpl %0" : : "m" (value));
     *res = value;*/
    return (int)*res;
}

long long fisttpq(long double *res)
{
    /*long double value = *res;
     __asm__ ("fistpq %0" : : "m" (value));
     *res = value;*/
    return (long long)*res;
}


void addsubpd(XMM *src, XMM *dst, XMM *res)
{
    res->f64[0] = src->f64[0] - dst->f64[0];
    res->f64[1] = src->f64[1] + dst->f64[1];
}

void addsubps(XMM *src, XMM *dst, XMM *res)
{
    res->f32[0] = src->f32[0] - dst->f32[0];
    res->f32[1] = src->f32[1] + dst->f32[1];
    res->f32[2] = src->f32[2] - dst->f32[2];
    res->f32[3] = src->f32[3] + dst->f32[3];
}

void haddpd(XMM *src, XMM *dst, XMM *res)
{
    res->f64[0] = src->f64[0] + src->f64[1];
    res->f64[1] = dst->f64[0] + dst->f64[1];
}

void haddps(XMM *src, XMM *dst, XMM *res)
{
    res->f32[0] = src->f32[0] + src->f32[1];
    res->f32[1] = src->f32[2] + src->f32[3];
    res->f32[2] = dst->f32[0] + dst->f32[1];
    res->f32[3] = dst->f32[2] + dst->f32[3];
}

void hsubpd(XMM *src, XMM *dst, XMM *res)
{
    res->f64[0] = src->f64[0] - src->f64[1];
    res->f64[1] = dst->f64[0] - dst->f64[1];
}

void hsubps(XMM *src, XMM *dst, XMM *res)
{
    res->f32[0] = src->f32[0] - src->f32[1];
    res->f32[1] = src->f32[2] - src->f32[3];
    res->f32[2] = dst->f32[0] - dst->f32[1];
    res->f32[3] = dst->f32[2] - dst->f32[3];
}

void lddqu(XMM *src, XMM *res)
{
    res->f64[0] = src->f64[0];
    res->f64[1] = src->f64[1];
}

void movddup(XMM *src, XMM *res)
{
    res->f64[0] = src->f64[0];
    res->f64[1] = src->f64[0];
}

void movshdup(XMM *src, XMM *res)
{
    res->f32[0] = src->f32[1];
    res->f32[1] = src->f32[1];
    res->f32[2] = src->f32[3];
    res->f32[3] = src->f32[3];
}

void movsldup(XMM *src, XMM *res)
{
    res->f32[0] = src->f32[0];
    res->f32[1] = src->f32[0];
    res->f32[2] = src->f32[2];
    res->f32[3] = src->f32[2];
}


/***************************************/
/** SSSE3 instructions implementation **/
/***************************************/

//#define SATSW(x) ((x > 32767)? 32767 : ((x < -32768)? -32768 : x) )
/*static inline int SATSW(int x)
 {
 if (x < -32768)
 return -32768;
 else if (x > 32767)
 return 32767;
 else
 return x;
 }
 */

static short
signed_saturate_to_word (int x)
{
    if (x > (int) 0x7fff)
        return 0x7fff;
    if (x < (int) 0xffff8000)
        return 0x8000;
    return (short) x;
}


/** complex byte shuffle **/
/*void pshufb128(ssp_m128 *MSK, ssp_m128 *A, ssp_m128 *B)
 {
 //int i;
 
 
 //ssp_m128 A, MSK, B;
 //A.i = a;
 //MSK.i = mask;
 
 B->s8[0]  = (MSK->s8[0]  & 0x80) ? 0 : A->s8[(MSK->s8[0]  & 0xf)];
 B->s8[1]  = (MSK->s8[1]  & 0x80) ? 0 : A->s8[(MSK->s8[1]  & 0xf)];
 B->s8[2]  = (MSK->s8[2]  & 0x80) ? 0 : A->s8[(MSK->s8[2]  & 0xf)];
 B->s8[3]  = (MSK->s8[3]  & 0x80) ? 0 : A->s8[(MSK->s8[3]  & 0xf)];
 B->s8[4]  = (MSK->s8[4]  & 0x80) ? 0 : A->s8[(MSK->s8[4]  & 0xf)];
 B->s8[5]  = (MSK->s8[5]  & 0x80) ? 0 : A->s8[(MSK->s8[5]  & 0xf)];
 B->s8[6]  = (MSK->s8[6]  & 0x80) ? 0 : A->s8[(MSK->s8[6]  & 0xf)];
 B->s8[7]  = (MSK->s8[7]  & 0x80) ? 0 : A->s8[(MSK->s8[7]  & 0xf)];
 B->s8[8]  = (MSK->s8[8]  & 0x80) ? 0 : A->s8[(MSK->s8[8]  & 0xf)];
 B->s8[9]  = (MSK->s8[9]  & 0x80) ? 0 : A->s8[(MSK->s8[9]  & 0xf)];
 B->s8[10] = (MSK->s8[10] & 0x80) ? 0 : A->s8[(MSK->s8[10] & 0xf)];
 B->s8[11] = (MSK->s8[11] & 0x80) ? 0 : A->s8[(MSK->s8[11] & 0xf)];
 B->s8[12] = (MSK->s8[12] & 0x80) ? 0 : A->s8[(MSK->s8[12] & 0xf)];
 B->s8[13] = (MSK->s8[13] & 0x80) ? 0 : A->s8[(MSK->s8[13] & 0xf)];
 B->s8[14] = (MSK->s8[14] & 0x80) ? 0 : A->s8[(MSK->s8[14] & 0xf)];
 B->s8[15] = (MSK->s8[15] & 0x80) ? 0 : A->s8[(MSK->s8[15] & 0xf)];
 */
//return B->i;

//}

/** complex byte shuffle **/
void pshufb128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    
    for (i = 0; i < 16; i++)
    {
        if (src->u8[i] & 0x80)
            res->u8[i] = 0;
        else
            res->u8[i] = dst->u8[src->u8[i] & 0xf];
    }
}

void pshufb64(MM *src, MM *dst, MM *res)
{
    int i;
    
    for (i = 0; i < 8; ++i){
        if (src->u8[i] & 0x80){
            res->u8[i] =  0;
        }
        else
        {
            res->u8[i] = dst->u8[src->u8[i] & 0x07];
        }
    }
}


/** packed horizontal add word **/
void phaddw128(XMM *src, XMM *dst, XMM *res)
{
    
    
    int i;
    
    for (i = 0; i < 4; i++)
        res->s16[i] = dst->s16[2 * i] + dst->s16[2 * i + 1];
    
    for (i = 0; i < 4; i++)
        res->s16[i + 4] = src->s16[2 * i] + src->s16[2 * i + 1];
    
}

void phaddw64(MM *src, MM *dst, MM *res)
{
    res->s16[0] = dst->s16[0] + dst->s16[1];
    res->s16[1] = dst->s16[2] + dst->s16[3];
    res->s16[2] = src->s16[0] + src->s16[1];
    res->s16[3] = src->s16[2] + src->s16[3];
}

/** packed horizontal add double **/
void phaddd128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    for(i = 0; i < 2; ++i) {
        res->s32[i  ] = dst->s32[2*i] + dst->s32[2*i+1];
    }
    for(i = 0; i < 2; ++i)
        res->s32[i+2] = src->s32[2*i] + src->s32[2*i+1];
}

void phaddd64(MM *src, MM *dst, MM *res)
{
    res->s32[0] = dst->s32[0] + dst->s32[1];
    res->s32[1] = src->s32[0] + src->s32[1];
}

/** packed horizontal add and saturate word **/
void phaddsw128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    for(i = 0; i < 4; ++i)
        res->s16[i] = signed_saturate_to_word( dst->s16[2*i] + dst->s16[2*i+1] );
    for(i = 0; i < 4; ++i)
        res->s16[i+4] = signed_saturate_to_word( src->s16[2*i] + src->s16[2*i+1] );
}

void phaddsw64(MM *src, MM *dst, MM *res)
{
    res->s16[0] = signed_saturate_to_word( dst->s16[0] + dst->s16[1] );
    res->s16[1] = signed_saturate_to_word( dst->s16[2] + dst->s16[3] );
    res->s16[2] = signed_saturate_to_word( src->s16[0] + src->s16[1] );
    res->s16[3] = signed_saturate_to_word( src->s16[2] + src->s16[3] );
    
}

/** multiply and add packed signed and unsigned bytes **/
void pmaddubsw128(XMM *src, XMM *dst, XMM *res)
{
    
    
    int t0;
    int i;
    for (i = 0; i < 8; i++)
    {
        t0 = ((int) dst->u8[2 * i] * (int) src->s8[2 * i] +
              (int) dst->u8[2 * i + 1] * (int) src->s8[2 * i + 1]);
        res->s16[i] = signed_saturate_to_word (t0);
    }
}


void pmaddubsw64(MM *src, MM *dst, MM *res)
{
    int t0;
    int i;
    for (i = 0; i < 4; i++)
    {
        t0 = ((int) dst->u8[2 * i] * (int) src->s8[2 * i] +
              (int) dst->u8[2 * i + 1] * (int) src->s8[2 * i + 1]);
        res->s16[i] = signed_saturate_to_word (t0);
    }
    
}

/** packed horizontal subtract word **/
void phsubw128(XMM *src, XMM *dst, XMM *res)
{
    
    int i;
    for (i = 0; i < 4; i++)
        res->s16[i] = dst->s16[2 * i] - dst->s16[2 * i + 1];
    for (i = 0; i < 4; i++)
        res->s16[i + 4] = src->s16[2 * i] - src->s16[2 * i + 1];
}

void phsubw64(MM *src, MM *dst, MM *res)
{
    res->s16[0] = dst->s16[0] - dst->s16[1];
    res->s16[1] = dst->s16[2] - dst->s16[3];
    res->s16[2] = src->s16[0] - src->s16[1];
    res->s16[3] = src->s16[2] - src->s16[3];
}

/** packed horizontal subtract double **/
void phsubd128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    for(i = 0; i < 2; i++)
        res->s32[i  ] = dst->s32[2*i] - dst->s32[2*i+1];
    for(i = 0; i < 2; i++)
        res->s32[i+2] = src->s32[2*i] - src->s32[2*i+1];
}

void phsubd64(MM *src, MM *dst, MM *res)
{
    res->s32[0] = dst->s32[0] - dst->s32[1];
    res->s32[1] = src->s32[0] - src->s32[1];
}

/** packed horizontal subtract and saturate word **/
void phsubsw128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    for(i = 0; i < 4; i++)
        res->s16[i] = signed_saturate_to_word( dst->s16[2*i] - dst->s16[2*i+1] );
    for(i = 0; i < 4; i++)
        res->s16[i+4] = signed_saturate_to_word( src->s16[2*i] - src->s16[2*i+1] );
}

void phsubsw64(MM *src, MM *dst, MM *res)
{
    res->s16[0] = signed_saturate_to_word( dst->s16[0] - dst->s16[1] );
    res->s16[1] = signed_saturate_to_word( dst->s16[2] - dst->s16[3] );
    res->s16[2] = signed_saturate_to_word( src->s16[0] - src->s16[1] );
    res->s16[3] = signed_saturate_to_word( src->s16[2] - src->s16[3] );
    
}

/** packed sign byte **/
void psignb128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    for(i = 0; i < 16; i++) {
        if(src->s8[i] < 0) res->s8[i] = -dst->s8[i];
        else if(src->s8[i] == 0) res->s8[i] = 0;
        else res->s8[i] = dst->s8[i];
    }
}

void psignb64(MM *src, MM *dst, MM *res)
{
    int i;
    for(i = 0; i < 8; i++) {
        if(src->s8[i] < 0) res->s8[i] = -dst->s8[i];
        else if(src->s8[i] == 0) res->s8[i] = 0;
        else res->s8[i] = dst->s8[i];
    }
}

/** packed sign word **/
void psignw128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    for(i = 0; i < 8; i++) {
        if(src->s16[i] < 0) res->s16[i] = -dst->s16[i];
        else if(src->s16[i] == 0) res->s16[i] = 0;
        else res->s16[i] = dst->s16[i];
    }
}

void psignw64(MM *src, MM *dst, MM *res)
{
    int i;
    for(i = 0; i < 4; i++) {
        if(src->s16[i] < 0) res->s16[i] = -dst->s16[i];
        else if(src->s16[i] == 0) res->s16[i] = 0;
        else res->s16[i] = dst->s16[i];
    }
}

/** packed sign double **/
void psignd128(XMM *src, XMM *dst, XMM *res)
{
    int i;
    for(i = 0; i < 4; i++) {
        if(src->s32[i] < 0) res->s32[i] = -dst->s32[i];
        else if(src->s32[i] == 0) res->s32[i] = 0;
        else res->s32[i] = dst->s32[i];
    }
}

void psignd64(MM *src, MM *dst, MM *res)
{
    int i;
    for(i = 0; i < 2; i++) {
        if(src->s32[i] < 0) res->s32[i] = -dst->s32[i];
        else if(src->s32[i] == 0) res->s32[i] = 0;
        else res->s32[i] = dst->s32[i];
    }
}

/** packed multiply high with round and scale word **/
void pmulhrsw128(XMM *src, XMM *dst, XMM *res)
{
    int t0;
    int i;
    for (i = 0; i < 8; i++)
    {
        t0 = (((int) dst->s16[i] * (int) src->s16[i]) >> 14) + 1;
        res->s16[i] = (short) (t0 >> 1);
    }
    
}

void pmulhrsw64(MM *src, MM *dst, MM *res)
{
    int t0;
    int i;
    for (i = 0; i < 4; i++)
    {
        t0 = (((int) dst->s16[i] * (int) src->s16[i]) >> 14) + 1;
        res->s16[i] = (short) (t0 >> 1);
    }
    
}

/** packed absolute value byte **/
void pabsb128(XMM *src, XMM *res)
{
    int i;
    for(i = 0; i < 16; i++)
        if(src->s8[i] < 0) res->s8[i] = -src->s8[i];
        else res->s8[i] = src->s8[i];
}

void pabsb64(MM *src, MM *res)
{
    int i;
    for(i = 0; i < 8; i++)
        if(src->s8[i] < 0) res->s8[i] = -src->s8[i];
        else res->s8[i] = src->s8[i];
}

/** packed absolute value word **/
void pabsw128(XMM *src, XMM *res)
{
    int i;
    for(i = 0; i < 8; i++)
        if(src->s16[i] < 0) res->s16[i] = -src->s16[i];
        else res->s16[i] = src->s16[i];
}

void pabsw64(MM *src, MM *res)
{
    int i;
    for(i = 0; i < 4; i++)
        if(src->s16[i] < 0) res->s16[i] = -src->s16[i];
        else res->s16[i] = src->s16[i];
}

/** packed absolute value double **/
void pabsd128(XMM *src, XMM *res)
{
    int i;
    for(i = 0; i < 4; i++)
        if(src->s32[i] < 0) res->s32[i] = -src->s32[i];
        else res->s32[i] = src->s32[i];
}

void pabsd64(MM *src, MM *res)
{
    int i;
    for(i = 0; i < 2; i++)
        if(src->s32[i] < 0) res->s32[i] = -src->s32[i];
        else res->s32[i] = src->s32[i];
}

/** packed align right **/
void palignr128(XMM *src, XMM *dst, XMM *res, uint32_t IMM)
{
    
    char buf [32];
    int i;
    
    memcpy (&buf[0], src->s32, 16);
    memcpy (&buf[16], dst->s32, 16);
    
    for (i = 0; i < 16; i++)
        if (IMM >= 32 || IMM + i >= 32)
            res->s8[i] = 0;
        else
            res->s8[i] = buf[IMM + i];
    
    
    
}

void palignr64(MM *src, MM *dst, MM *res, uint32_t IMM)
{
    char buf [16];
    int i;
    
    /* Handle the first half */
    memcpy (&buf[0], src->s32, 8);
    memcpy (&buf[8], dst->s32, 8);
    
    for (i = 0; i < 8; i++)
        if (IMM >= 16 || IMM + i >= 16)
            res->s8[i] = 0;
        else
            res->s8[i] = buf[IMM + i];
    
    /* Handle the second half */
    memcpy (&buf[0], &src->s32[2], 8);
    memcpy (&buf[8], &dst->s32[2], 8);
    
    for (i = 0; i < 8; i++)
        if (IMM >= 16 || IMM + i >= 16)
            res->s8[i + 8] = 0;
        else
            res->s8[i + 8] = buf[IMM + i];
    
    
}
