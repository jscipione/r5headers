/* Copyright (C) 1991, 1992, 1996, 1997, 1998 Free Software Foundation, Inc.
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
# error "Never include <bits/sigaction.h> directly; use <signal.h> instead."
#endif

/* These definitions match those used by the 4.4 BSD kernel.
   If the operating system has a `sigaction' system call that correctly
   implements the POSIX.1 behavior, there should be a system-dependent
   version of this file that defines `struct sigaction' and the `SA_*'
   constants appropriately.  */

/* Structure describing the action to be taken when a signal arrives.  */
struct sigaction
  {
    /* Signal handler.  */
    __sighandler_t sa_handler;

    /* Additional set of signals to be blocked.  */
    __sigset_t sa_mask;

    /* Special flags.  */
    int sa_flags;

    /* User data passed to the signal handler.  */
    void *sa_userdata;
  };

/* Bits in `sa_flags'.  */
#ifdef	__USE_BSD
# define SA_ONSTACK	0x1	/* Take signal on signal stack.  */
# define SA_RESTART	0x2	/* Restart syscall on signal return.  */
# define SA_DISABLE	0x4	/* Disable alternate signal stack.  */
#endif
#define	SA_NOCLDSTOP	0x8	/* Don't send SIGCHLD when children stop.  */


/* Values for the HOW argument to `sigprocmask'.  */
#define	SIG_BLOCK	1	/* Block signals.  */
#define	SIG_UNBLOCK	2	/* Unblock signals.  */
#define	SIG_SETMASK	3	/* Set the set of blocked signals.  */

typedef __sighandler_t __signal_func_ptr; /* Backward compatibility */
extern int send_signal __P ((__pid_t tid, unsigned int sig));
