/* Macros to swap the order of bytes in integer values.
   Copyright (C) 1997, 1998 Free Software Foundation, Inc.
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

#if !defined _BYTESWAP_H && !defined _NETINET_IN_H
# error "Never use <bits/byteswap.h> directly; include <byteswap.h> instead."
#endif

/* Swap bytes in 16 bit value.  */
#define __bswap_constant_16(x) \
     ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))

#if defined __GNUC__ && __GNUC__ >= 2
# define __bswap_16(x) \
     ({ register unsigned short int __v;				      \
	if (__builtin_constant_p (x))					      \
	  __v = __bswap_constant_16 (x);				      \
	else								      \
	  __asm__ __volatile__ ("rorw $8, %w0"				      \
				: "=r" (__v)				      \
				: "0" ((unsigned short int) (x))	      \
				: "cc");				      \
	__v; })
#else
/* This is better than nothing.  */
# define __bswap_16(x) __bswap_constant_16 (x)
#endif


/* Swap bytes in 32 bit value.  */
#define __bswap_constant_32(x) \
     ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) |		      \
      (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))

#if defined __GNUC__ && __GNUC__ >= 2
/* To swap the bytes in a word the i486 processors and up provide the
   `bswap' opcode.  On i386 we have to use three instructions.  */
# if !defined __i486__ && !defined __pentium__ && !defined __pentiumpro__
#  define __bswap_32(x) \
     ({ register unsigned int __v;					      \
	if (__builtin_constant_p (x))					      \
	  __v = __bswap_constant_32 (x);				      \
	else								      \
	  __asm__ __volatile__ ("rorw $8, %w0;"				      \
				"rorl $16, %0;"				      \
				"rorw $8, %w0"				      \
				: "=r" (__v)				      \
				: "0" ((unsigned int) (x))		      \
				: "cc");				      \
	__v; })
# else
#  define __bswap_32(x) \
     ({ register unsigned int __v;					      \
	if (__builtin_constant_p (x))					      \
	  __v = __bswap_constant_32 (x);				      \
	else								      \
	  __asm__ __volatile__ ("bswap %0"				      \
				: "=r" (__v)				      \
				: "0" ((unsigned int) (x)));		      \
	__v; })
# endif
#else
# define __bswap_32(x) __bswap_constant_32 (x)
#endif


#if defined __GNUC__ && __GNUC__ >= 2
/* Swap bytes in 64 bit value.  */
# define __bswap_64(x) \
     ({ union { unsigned long long int __ll;				      \
		unsigned long int __l[2]; } __v, __r;			      \
        __v.__ll = (x);							      \
	__r.__l[0] = __bswap_32 (__v.__l[1]);				      \
	__r.__l[1] = __bswap_32 (__v.__l[0]);				      \
	__r.__ll; })
#endif
