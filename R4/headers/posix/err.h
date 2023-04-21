/* 4.4BSD utility functions for error messages.
   Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.
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

#ifndef	_ERR_H
#define	_ERR_H	1

#include <features.h>

#define	__need___va_list
#include <stdarg.h>
#ifndef	__GNUC_VA_LIST
# define __gnuc_va_list	__ptr_t
#endif

__BEGIN_DECLS

/* Print FORMAT on stderr.  */
extern void warn __P ((__const char *__format, ...))
     __attribute__ ((format (printf, 1, 2)));
extern void vwarn __P ((__const char *__format, __gnuc_va_list))
     __attribute__ ((format (printf, 1, 0)));

/* Print "program: ", and FORMAT, and a newline, on stderr.  */
extern void warnx __P ((__const char *__format, ...))
     __attribute__ ((format (printf, 1, 2)));
extern void vwarnx __P ((__const char *__format, __gnuc_va_list))
     __attribute__ ((format (printf, 1, 0)));

/* Likewise, and then exit with STATUS.  */
extern void err __P ((int __status, __const char *__format, ...))
     __attribute__ ((noreturn, format (printf, 2, 3)));
extern void verr __P ((int __status, __const char *__format, __gnuc_va_list))
     __attribute__ ((noreturn, format (printf, 2, 0)));
extern void errx __P ((int __status, __const char *__format, ...))
     __attribute__ ((noreturn, format (printf, 2, 3)));
extern void verrx __P ((int __status, __const char *, __gnuc_va_list))
     __attribute__ ((noreturn, format (printf, 2, 0)));

__END_DECLS

#endif	/* err.h */
