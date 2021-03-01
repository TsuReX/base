/*
 * context.h
 *
 *  Created on: Apr 15, 2020
 *      Author: vasily
 */

#ifndef INCLUDE_CONTEXT_H_
#define INCLUDE_CONTEXT_H_

#include <stddef.h>

#define BASE_CONTEXT_SIZE	0x48
#define FULL_CONTEXT_SIZE	0x90
#define CONTEXT_COUNT		0x4

struct base_frame_t {
	uint32_t	r0;
	uint32_t	r1;
	uint32_t	r2;
	uint32_t	r3;
	uint32_t	r12;
	uint32_t	lr;
	uint32_t	pc;
	uint32_t	xpsr;
};

struct extended_frame_t {
	uint32_t	r0;
	uint32_t	r1;
	uint32_t	r2;
	uint32_t	r3;
	uint32_t	r12;
	uint32_t	lr;
	uint32_t	pc;
	uint32_t	xpsr;
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	s2;
	uint32_t	s3;
	uint32_t	s4;
	uint32_t	s5;
	uint32_t	s6;
	uint32_t	s7;
	uint32_t	s8;
	uint32_t	s9;
	uint32_t	s10;
	uint32_t	s11;
	uint32_t	s12;
	uint32_t	s13;
	uint32_t	s14;
	uint32_t	s15;
	uint32_t	fpscr;
	uint32_t	reserved;
};

struct context {

	/* Manually saved frame */
	uint32_t	exc_return;	/* <<  Special lr value of current exception. */
	uint32_t	psp;		/* <<  Stack pointer of interrupted process. */
	uint32_t	r4;
	uint32_t	r5;
	uint32_t	r6;
	uint32_t	r7;
	uint32_t	r8;
	uint32_t	r9;
	uint32_t	r10;
	uint32_t	r11;

	/* Automatically saved base frame */
	uint32_t	r0;
	uint32_t	r1;
	uint32_t	r2;
	uint32_t	r3;
	uint32_t	r12;
	uint32_t	lr;
	uint32_t	pc;
	uint32_t	xpsr;

	/* Automatically saved extension to base frame */
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	s2;
	uint32_t	s3;
	uint32_t	s4;
	uint32_t	s5;
	uint32_t	s6;
	uint32_t	s7;
	uint32_t	s8;
	uint32_t	s9;
	uint32_t	s10;
	uint32_t	s11;
	uint32_t	s12;
	uint32_t	s13;
	uint32_t	s14;
	uint32_t	s15;
	uint32_t	fpscr;
	uint32_t	reserved;
};

typedef void (*func_ptr)(void);

void pendsv_setup(func_ptr handler);

func_ptr pendsv_get();

void nmi_trigger();

void pendsv_trigger();

void init_process_start();

void init_process_create(uint32_t proc_addr, size_t  proc_addr_size);



#endif /* INCLUDE_CONTEXT_H_ */
