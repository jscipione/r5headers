/* Copyright (C) 1992, 1996, 1997 Free Software Foundation, Inc.
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

#ifndef	_ALLOCA_H
#define	_ALLOCA_H	1

#include <features.h>

#define	__need_size_t
#include <stddef.h>

__BEGIN_DECLS

/* Remove any previous definitions.  */
#undef	__alloca
#undef	alloca

/* Allocate a block that will be freed when the calling function exits.  */
extern __ptr_t __alloca __P ((size_t __size));
extern __ptr_t alloca __P ((size_t __size));

#ifdef	__GNUC__
# define __alloca(size)	__builtin_alloca (size)
# define alloca(size)	__alloca (size)
#endif /* GCC.  */

__END_DECLS

#endif /* alloca.h */
