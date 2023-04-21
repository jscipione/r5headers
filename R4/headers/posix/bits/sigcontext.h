/* Structure describing state saved while handling a signal.  Stub version.
   Copyright (C) 1991, 1994, 1997, 1998 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef _SIGNAL_H
# error "Never use <bits/sigcontext.h> directly; include <signal.h> instead."
#endif

#if __INTEL__

/* State of the FPU.  */
typedef struct fp_state
{
  unsigned short int fp_cw;
  unsigned short int res1;
  unsigned short int fp_status;
  unsigned short int res2;
  unsigned short int fp_tag;
  unsigned short int res3;
  unsigned long int fp_eip;
  unsigned short int fp_cs;
  unsigned short int fp_opcode;
  unsigned long int fp_datap;
  unsigned short int fp_ds;
  unsigned short int res4;
  unsigned char fp1[10];
  unsigned char fp2[10];
  unsigned char fp3[10];
  unsigned char fp4[10];
  unsigned char fp5[10];
  unsigned char fp6[10];
  unsigned char fp7[10];
  unsigned char fp8[10];
} fp_state;

typedef struct vregs {
	unsigned long	eip;
	unsigned long	eflags;
	unsigned long	eax;
	unsigned long	ecx;
	unsigned long	edx;
	unsigned long	esp;
	unsigned long	ebp;
	fp_state		fpu;
} vregs;

#endif /* __INTEL__ */

/* State of this thread when the signal was taken.  */
struct sigcontext
  {
    int sc_onstack;
    __sigset_t sc_mask;

    /* Registers and such.  */
  };

/* Signal subcodes should be defined here.  */
