/*                                                                  8888888 8888888 8888888 
                                                                      888     888     888   
                                                                      888     888     888   
             .d88b.  88888b.   .d88b.  88888b.d88b.  888  888         888     888     888   
            d88""88b 888 "88b d8P  Y8b 888 "888 "88b 888  888         888     888     888   
            888  888 888  888 88888888 888  888  888 888  888         888     888     888   
            Y88..88P 888 d88P Y8b.     888  888  888 Y88b 888         888     888     888   
             "Y88P"  88888P"   "Y8888  888  888  888  "Y88888       8888888 8888888 8888888 
                     888                                                                    
                     888                                                                    
                     888                                                                    
IM      ~ SINETEK                                                                           
        ~ ANV                                                                               
        ~ BRONZOVKA                                                                         
                                                                                          */
/**
 * This is called the Opcode Emulator: it traps invalid opcode exceptions
 *   and modifies the state of the running thread accordingly.
 * There are two entry points, one for user space exceptions, and another for
 *   exceptions coming from kernel space.
 *
 * STATUS
 *  . RDMSR/WRMSR is implemented.
 *  . SYSENTER is implemented.
 *  . SYSEXIT is implemented
 *  . SSSE3 is implemented.
 *  . SSE42 is partly implemented. (Needs testing)
 *  . SSE3 is implemented. (Needs testing)
 *
 * HISTORY
 *  . SINETEK  Big cleanup, bumping version
 *  . AnV Added sysexit, adapt opemu ktrap
 *  . AnV Added a few SSE42 instructions
 */
#include <stdint.h>
#include <i386/trap.h>

#include "opemu.h"

/*
 * The KTRAP is only ever called from within the kernel,
 * and for now that is x86_64 only, so we simplify things,
 * and assume everything runs in x86_64.
 */
int opemu_ktrap(x86_saved_state_t *state)
{
	x86_saved_state64_t *saved_state = saved_state64(state);
	const uint8_t *code_stream = (const uint8_t*) saved_state->isf.rip;
	uint8_t bytes_skip = 0;

	ud_t ud_obj;		// disassembler object
	op_t op_obj;
	
	ud_init(&ud_obj);
	ud_set_input_buffer(&ud_obj, code_stream, 15);	// TODO dangerous
	ud_set_mode(&ud_obj, 64);
	ud_set_syntax(&ud_obj, UD_SYN_INTEL);
	ud_set_vendor(&ud_obj, UD_VENDOR_ANY);

	bytes_skip = ud_disassemble(&ud_obj);
	if ( bytes_skip == 0 ) goto bad;
	const uint32_t mnemonic = ud_insn_mnemonic(&ud_obj);

	/* since this is ring0, it could be an invalid MSR read.
	 * Instead of crashing the whole machine, report on it and keep running. */
	if (mnemonic == UD_Irdmsr) {
		printf ("[RDMSR] unknown location 0x%016llx\r\n", saved_state->rcx);
		// best we can do is return 0;
		saved_state->rdx = saved_state->rax = 0;
		goto cleanexit;
	} else if (mnemonic == UD_Iwrmsr) {
		printf ("[WRMSR] unknown location 0x%016llx\r\n", saved_state->rcx);
		goto cleanexit;
	}

	/* Else run the full-blown opemu */

	int error = 0;

	// fill in the opemu object
	op_obj.state = state;
	op_obj.state64 = saved_state;
	op_obj.state_flavor = SAVEDSTATE_64;
	op_obj.ud_obj = &ud_obj;
	op_obj.ring0 = 1;

	error |= op_sse3x_run(&op_obj);

    if (error)
    {
        error = 0;
        error |= op_sse3_run(&op_obj);
    }

	if (!error) goto cleanexit;

	/** fallthru **/
bad:
	{
		/* Well, now go in and get the asm text at least.. */
		const char *instruction_asm;
		instruction_asm = ud_insn_asm(&ud_obj);

		printf ( "OPEMU:  %s\n", instruction_asm) ;
		return 0;
	}

cleanexit:
	saved_state->isf.rip += bytes_skip;
    return 1;
}

/**
 * Run the opcode emulator on a userspace thread.
 */
void opemu_utrap(x86_saved_state_t *state)
{
	uint8_t islongmode = is_saved_state64(state);
	const uint8_t *code_stream;
	uint8_t bytes_skip = 0;

	ud_t ud_obj;		// disassembler object
	op_t op_obj;

	if (islongmode) {
		code_stream = (const uint8_t*) state->ss_64.isf.rip;
	} else {
		uint64_t ip = state->ss_32.eip; // prevent warning
		code_stream = (const uint8_t*) ip;
	}

	ud_init(&ud_obj);
	ud_set_input_buffer(&ud_obj, code_stream, 15);	// TODO dangerous
	ud_set_mode(&ud_obj, 64);
	ud_set_syntax(&ud_obj, UD_SYN_INTEL);
	ud_set_vendor(&ud_obj, UD_VENDOR_ANY);

	bytes_skip = ud_disassemble(&ud_obj);
	if ( bytes_skip == 0 ) goto bad;
	const uint32_t mnemonic = ud_insn_mnemonic(&ud_obj);

	int error = 0;

	/* It could be a sysenter instruction, which translates to a system call
	 * (both mach and bsd calls)
	 */
	if (mnemonic == UD_Isysenter) {
        if (islongmode)
        {
            saved_state64(state)->isf.rip = saved_state64(state)->rdx;
            saved_state64(state)->isf.rsp = saved_state64(state)->rcx;
            
            if ((signed) saved_state64(state)->rax < 0) {
                mach_call_munger64(state);
            } else {
                unix_syscall64(state);
            }
        } else {
            saved_state32(state)->eip = saved_state32(state)->edx;
            saved_state32(state)->uesp = saved_state32(state)->ecx;

            if ((signed) saved_state32(state)->eax < 0) {
                mach_call_munger(state);
            } else {
                unix_syscall(state);
            }
        }
		/** NOTREACHED **/
		__builtin_unreachable(); // clang extension
	}

    /* It could be a sysexit instruction, which translates to a specific return */
    if (mnemonic == UD_Isysexit) {
        if (islongmode)
        {
            saved_state64(state)->isf.rip = saved_state64(state)->rdx;
            saved_state64(state)->isf.rsp = saved_state64(state)->rcx;
            
            thread_exception_return();
        } else {
            saved_state32(state)->eip = saved_state32(state)->edx;
            saved_state32(state)->uesp = saved_state32(state)->ecx;
            
            thread_exception_return();
        }
		/** NOTREACHED **/
		__builtin_unreachable(); // clang extension
    }

	// fill in the opemu object
	op_obj.state = state;
	op_obj.state64 = saved_state64(state);
	op_obj.state32 = saved_state32(state);
	op_obj.state_flavor = (islongmode) ? SAVEDSTATE_64 : SAVEDSTATE_32;
	op_obj.ud_obj = &ud_obj;
	op_obj.ring0 = 0;

	error |= op_sse3x_run(&op_obj);

    if (error)
    {
        error = 0;
        error |= op_sse3_run(&op_obj);
    }
    
	if (!error) goto cleanexit;

	/** fallthru **/
bad:
	{
		/* Well, now go in and get the asm text at least.. */
		const char *instruction_asm;
		instruction_asm = ud_insn_asm(&ud_obj);

		printf ( "OPEMU:  %s\n", instruction_asm) ;
		i386_exception (EXC_BAD_INSTRUCTION, EXC_I386_INVOP, 0);
	}

cleanexit:
	if (islongmode) saved_state64(state)->isf.rip += bytes_skip;
	else saved_state32(state)->eip += bytes_skip;

	thread_exception_return();
	/** NOTREACHED **/
	__builtin_unreachable(); // clang extension
}

/**
 * Retrieve a general purpose value register's value
 * @param saved_state: the saved state
 * @param base:  the register type itself
 * @param where: reg's value will be stored there
 * @return: zero if the state could be retrieved
 */
int retrieve_reg(/*const*/ x86_saved_state_t *state, const ud_type_t base, uint64_t *where)
{
	const x86_saved_state64_t *ss64 = saved_state64(state);
	const x86_saved_state32_t *ss32 = saved_state32(state);

	switch (base) {

	case UD_NONE:
		*where = 0;
		break;

	// TODO what if 32?
	case UD_R_RIP:
		*where = ss64 -> isf.rip;
		break;

	case UD_R_RAX:
		*where = ss64 -> rax;
		break;

	case UD_R_RCX:
		*where = ss64 -> rcx;
		break;

	case UD_R_RDX:
		*where = ss64 -> rdx;
		break;

	case UD_R_RBX:
		*where = ss64 -> rbx;
		break;

	case UD_R_RSP:
		*where = ss64 -> isf.rsp;
		break;

	case UD_R_RBP:
		*where = ss64 -> rbp;
		break;

	case UD_R_RSI:
		*where = ss64 -> rsi;
		break;

	case UD_R_RDI:
		*where = ss64 -> rdi;
		break;

	case UD_R_R8:
		*where = ss64 -> r8;
		break;

	case UD_R_R9:
		*where = ss64 -> r9;
		break;

	case UD_R_R10:
		*where = ss64 -> r10;
		break;

	case UD_R_R11:
		*where = ss64 -> r11;
		break;

	case UD_R_R12:
		*where = ss64 -> r12;
		break;

	case UD_R_R13:
		*where = ss64 -> r13;
		break;

	case UD_R_R14:
		*where = ss64 -> r14;
		break;

	case UD_R_R15:
		*where = ss64 -> r15;
		break;

	/* 32 bit general purpose */

	case UD_R_EAX:
		*where = ss32 -> eax;
		break;

	case UD_R_ECX:
		*where = ss32 -> ecx;
		break;

	case UD_R_EDX:
		*where = ss32 -> edx;
		break;

	case UD_R_EBX:
		*where = ss32 -> ebx;
		break;

	case UD_R_ESP:
		*where = ss32 -> uesp;
		break;

	case UD_R_EBP:
		*where = ss32 -> ebp;
		break;

	case UD_R_ESI:
		*where = ss32 -> esi;
		break;

	case UD_R_EDI:
		*where = ss32 -> edi;
		break;

	default: goto bad;

	}		

    return 0;

    // Only reached if bad
bad:
    return -1;
}

