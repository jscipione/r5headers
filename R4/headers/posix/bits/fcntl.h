/* O_*, F_*, FD_* bit values for BeOS configuration.
   Copyright (C) 1991, 1992, 1997, 1998 Free Software Foundation, Inc.
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

/* These values should be changed as appropriate for your system.  */

#ifndef	_FCNTL_H
#error "Never use <bits/fcntl.h> directly; include <fcntl.h> instead."
#endif


/* File access modes for `open' and `fcntl'.  */
#define	O_RDONLY	0	/* Open read-only.  */
#define	O_WRONLY	1	/* Open write-only.  */
#define	O_RDWR		2	/* Open read/write.  */

#ifdef __USE_MISC
/* Be specific.  Do not use this in portable programs.  Use O_ACCMODE
   instead.  */
# define O_RWMASK	3
#endif

/* Bits OR'd into the second argument to open.  */
#define	O_CREAT		0x0200	/* Create file if it doesn't exist.  */
#define	O_EXCL		0x0100	/* Fail if file already exists.  */
#define	O_TRUNC		0x0400	/* Truncate file to zero length.  */
#define	O_NOCTTY	0x1000	/* Don't assign a controlling terminal.  */
#define O_CLOEXEC	0x0040	/* Close file descriptor on exec.  */

/* File status flags for `open' and `fcntl'.  */
#define	O_APPEND	0x0800	/* Writes append to the file.  */
#define	O_NONBLOCK	0x0080	/* Non-blocking I/O.  */

#ifdef __USE_BSD
#define	O_NDELAY	O_NONBLOCK
#endif

/* Mask for file access modes.  This is system-dependent in case
   some system ever wants to define some other flavor of access.  */
#define	O_ACCMODE	(O_RDONLY|O_WRONLY|O_RDWR)

/* There is no special large file support.  All accesses are 64bit.  */
#define O_LARGEFILE	0

/* Be-specific modes.  */
#ifdef __USE_MISC
# define O_NOTRAVERSE	0x2000	/* Do not traverse leaf link.  */
# define O_TEXT		0x4000	/* CR-LF translation.  */
# define O_BINARY	0x8000	/* No translation.  */
#endif

/* Values for the second argument to `fcntl'.  */
#define	F_DUPFD	  	0x0001	/* Duplicate file descriptor.  */
#define	F_GETFD		0x0002	/* Get file descriptor flags.  */
#define	F_SETFD		0x0004	/* Set file descriptor flags.  */
#define	F_GETFL		0x0008	/* Get file status flags.  */
#define	F_SETFL		0x0010	/* Set file status flags.  */
#define	F_GETLK		0x0020	/* Get record locking info.  */
#define	F_SETLK		0x0080	/* Set record locking info.  */
#define	F_SETLKW	0x0100	/* Set record locking info, wait.  */

/* File descriptor flags used with F_GETFD and F_SETFD.  */
#define	FD_CLOEXEC	1	/* Close on exec.  */


#include <bits/types.h>

/* The structure describing an advisory lock.  This is the type of the third
   argument to `fcntl' for the F_GETLK, F_SETLK, and F_SETLKW requests.  */
struct flock
  {
    short int l_type;	/* Type of lock: F_RDLCK, F_WRLCK, or F_UNLCK.  */
    short int l_whence;	/* Where `l_start' is relative to (like `lseek').  */
    __off_t l_start;	/* Offset where the lock begins.  */
    __off_t l_len;	/* Size of the locked area; zero means until EOF.  */
    __pid_t l_pid;	/* Process holding the lock.  */
  };

/* Values for the `l_type' field of a `struct flock'.  */
#define	F_RDLCK	0x0040	/* Read lock.  */
#define	F_WRLCK	0x0400	/* Write lock.  */
#define	F_UNLCK	0x0200	/* Remove lock.  */
