/* Definitions of status bits for `wait' et al.
   Copyright (C) 1992, 1994, 1996, 1997, 1998 Free Software Foundation, Inc.
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

#ifndef _SYS_WAIT_H
# error "Never include <bits/waitstatus.h> directly; use <sys/wait.h> instead."
#endif


/* Everything extant so far uses these same bits.  */


/* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */
#define	__WEXITSTATUS(status)	((status) & 0xff)

/* If WIFSIGNALED(STATUS), the terminating signal.  */
#define	__WTERMSIG(status)	(((status) >> 8) & 0xff)

/* If WIFSTOPPED(STATUS), the signal that stopped the child.  */
#define	__WSTOPSIG(status)	(((status) >> 16) & 0xff)

/* Nonzero if STATUS indicates normal termination.  */
#define	__WIFEXITED(status)	(((status) & ~0xff) == 0)

/* Nonzero if STATUS indicates termination by a signal.  */
#define __WIFSIGNALED(status)	((((status) >> 8) & 0xff) != 0)

/* Nonzero if STATUS indicates the child is stopped.  */
#define	__WIFSTOPPED(status)	((((status) >> 16) & 0xff) != 0)

/* Nonzero if STATUS indicates the child dumped core.  */
#define	__WCOREDUMP(status)	((status) & __WCOREFLAG)
#ifdef __USE_MISC
# define WIFCORED(status)	__WCOREDUMP (status)
#endif

/* Macros for constructing status values.  */
#define	__W_EXITCODE(ret, sig)	((ret) | (sig) << 8)
#define	__W_STOPCODE(sig)	((sig) << 8 | 0x20000 | 0xff)
#define	__WCOREFLAG		0x10000


#ifdef	__USE_BSD

# include <endian.h>

union wait
  {
    int w_status;
    struct
      {
# if	__BYTE_ORDER == __LITTLE_ENDIAN
	unsigned int __w_retcode:8; /* Return code if exited normally.  */
	unsigned int __w_termsig:8; /* Terminating signal.  */
	unsigned int __w_coredump:1; /* Set if dumped core.  */
	unsigned int:15;
# endif				/* Little endian.  */
# if	__BYTE_ORDER == __BIG_ENDIAN
	unsigned int:15;
	unsigned int __w_coredump:1;
	unsigned int __w_termsig:8;
	unsigned int __w_retcode:8;
# endif				/* Big endian.  */
      } __wait_terminated;
    struct
      {
# if	__BYTE_ORDER == __LITTLE_ENDIAN
	unsigned int __w_retcode:8; /* Return code.  */
	unsigned int __w_stopsig:8; /* Stopping signal.  */
	unsigned int __w_stopval:8; /* W_STOPPED if stopped.  */
	unsigned int:8;
# endif				/* Little endian.  */
# if	__BYTE_ORDER == __BIG_ENDIAN
	unsigned int:8;
	unsigned int __w_stopval:8; /* W_STOPPED if stopped.  */
	unsigned int __w_stopsig:8; /* Stopping signal.  */
	unsigned int __w_retcode:8; /* Return code.  */
# endif				/* Big endian.  */
      } __wait_stopped;
  };

# define w_termsig	__wait_terminated.__w_termsig
# define w_coredump	__wait_terminated.__w_coredump
# define w_retcode	__wait_terminated.__w_retcode
# define w_stopsig	__wait_stopped.__w_stopsig
# define w_stopval	__wait_stopped.__w_stopval

#endif	/* Use BSD.  */
