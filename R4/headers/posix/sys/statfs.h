/* Definitions for getting information about a filesystem.
   Copyright (C) 1996, 1997 Free Software Foundation, Inc.
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

#ifndef	_SYS_STATFS_H
#define	_SYS_STATFS_H	1

#include <features.h>

/* Get the system-specific definition of `struct statfs'.  */
#include <bits/statfs.h>

__BEGIN_DECLS

/* Return information about the filesystem on which FILE resides.  */
extern int __statfs __P ((__const char *__file, struct statfs *__buf));
#ifndef __USE_FILE_OFFSET64
extern int statfs __P ((__const char *__file, struct statfs *__buf));
#else
# ifdef __REDIRECT
extern int __REDIRECT (statfs, __P ((__const char *__file,
				     struct statfs *__buf)), statfs64);
# else
#  define statfs statfs64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern int statfs64 __P ((__const char *__file, struct statfs64 *__buf));
#endif

/* Return information about the filesystem containing the file FILDES
   refers to.  */
extern int __fstatfs __P ((int __fildes, struct statfs *__buf));
#ifndef __USE_FILE_OFFSET64
extern int fstatfs __P ((int __fildes, struct statfs *__buf));
#else
# ifdef __REDIRECT
extern int __REDIRECT (fstatfs, __P ((int __fildes, struct statfs *__buf)),
		       fstatfs64);
# else
#  define statfs statfs64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern int fstatfs64 __P ((int __fildes, struct statfs64 *__buf));
#endif

__END_DECLS

#endif	/* sys/statfs.h */
