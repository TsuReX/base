#include <stdint.h>

/*
 *
 */
__attribute__((naked, section(".after_vectors")))
void nmi_handler(void)
{
	__asm(	".syntax unified\n"
			"mrs r0, CONTROL\n"
			"mov r1, #0x1\n"
			"and r1, r0\n"

			"ite eq\n"
			"moveq r0, #0x68\n"
			"movne r0, #0x20\n"

			"mov r1, lr\n"
			"mov r2, sp\n"
			"push {lr}\n"
			"bl context_parse\n"
			"pop {lr}\n"
			"bx lr\n"
			".syntax divided\n"
		);
}
