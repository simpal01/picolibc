/* a-memcpy.s -- memcpy, optimised for m68k asm
 *
 * Copyright (c) 2007 mocom software GmbH & Co KG)
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */

#include <picolibc.h>

#include "m68kasm.h"

#if defined (__mcoldfire__) || defined (__mc68020__) || defined (__mc68030__) || defined (__mc68040__) || defined (__mc68060__)
# define MISALIGNED_OK 1
#else
# define MISALIGNED_OK 0
#endif
	
	.text
	.align	4

	.globl	SYM(memcpy)
	.type	SYM(memcpy), @function

/*   memcpy, optimised
 *
 *   strategy:
 *       - no argument testing (the original memcpy from the GNU lib does
 *         no checking either)
 *       - make sure the destination pointer (the write pointer) is long word
 *         aligned. This is the best you can do, because writing to unaligned
 *         addresses can be the most costfull thing you could do.
 *       - Once you have figured that out, we do a little loop unrolling
 *         to further improve speed.
 */

SYM(memcpy):
	move.l	4(sp),a0	| dest ptr
	move.l	8(sp),a1	| src ptr
	move.l	12(sp),d1	| len
	cmp.l	#8,d1		| if fewer than 8 bytes to transfer,
	blo	.Lresidue	| do not optimise

#if !MISALIGNED_OK
	/* Goto .Lresidue if either dest or src is not 4-byte aligned */
	move.l	a0,d0
	and.l	#3,d0
	bne	.Lresidue
	move.l	a1,d0
	and.l	#3,d0
	bne	.Lresidue
#else /* MISALIGNED_OK */
	/* align dest */
	move.l	a0,d0		| copy of dest
	neg.l	d0
	and.l	#3,d0		| look for the lower two only
	beq	2f		| is aligned?
	sub.l	d0,d1
	lsr.l	#1,d0		| word align needed?
	bcc	1f
	move.b	(a1)+,(a0)+
1:
	lsr.l	#1,d0		| long align needed?
	bcc	2f
	move.w	(a1)+,(a0)+
2:
#endif /* !MISALIGNED_OK */

	/* long word transfers */
	move.l	d1,d0
	and.l	#3,d1		| byte residue
	lsr.l	#3,d0
	bcc	1f		| carry set for 4-byte residue
	move.l	(a1)+,(a0)+
1:
	lsr.l	#1,d0		| number of 16-byte transfers
	bcc	.Lcopy 		| carry set for 8-byte residue
	bra	.Lcopy8

1:
	move.l	(a1)+,(a0)+
	move.l	(a1)+,(a0)+
.Lcopy8:
	move.l	(a1)+,(a0)+
	move.l	(a1)+,(a0)+
.Lcopy:
#if !defined (__mcoldfire__)
	dbra	d0,1b
	sub.l	#0x10000,d0
#else
	subq.l	#1,d0
#endif
	bpl	1b
	bra	.Lresidue

1:
	move.b	(a1)+,(a0)+	| move residue bytes

.Lresidue:
#if !defined (__mcoldfire__)
	dbra	d1,1b		| loop until done
	sub.l	#0x10000,d1
#else
	subq.l	#1,d1
#endif
	bpl	1b
	move.l	4(sp),a0	| return value
	move.l	a0,d0		| in both a0 and d0
	rts
	.size	SYM(memcpy), . - SYM(memcpy)
	
#if defined(__linux__) && defined(__ELF__)
	.section .note.GNU-stack,"",%progbits
#endif
