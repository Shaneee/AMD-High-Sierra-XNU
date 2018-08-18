#pragma once

#include <stdint.h>
#include <kern/sched_prim.h>
#include "libudis86/extern.h"

struct op {
	// one of either. order here matters.
	union {
		x86_saved_state64_t *state64;
		x86_saved_state32_t *state32;
	};

	enum {
		SAVEDSTATE_64,
		SAVEDSTATE_32,
	} state_flavor;

	// just another version of the above
	x86_saved_state_t *state;

	// disassembly object
	ud_t		*ud_obj;

	// boolean flag
	uint8_t		ring0;
};
typedef struct op op_t;

/**
 * Trap handlers, analogous to a program's entry point
 * @param state: xnu's trap.c saved thread state
 */
int opemu_ktrap(x86_saved_state_t *state);
void opemu_utrap(x86_saved_state_t *state) __attribute__((noreturn));


/**
 * Forward declarations of private xnu functions
 */
extern void mach_call_munger(x86_saved_state_t *state);
extern void unix_syscall(x86_saved_state_t *);
extern void mach_call_munger64(x86_saved_state_t *state);
extern void unix_syscall64(x86_saved_state_t *);

int retrieve_reg(/*const*/ x86_saved_state_t *, const ud_type_t, uint64_t *);

/**
 * Entry points for the "plugins"
 */
extern int op_sse3x_run(const op_t*);
extern int op_sse3_run(const op_t*);

