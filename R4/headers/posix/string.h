/* Copyright (C) 1991, 92, 93, 95, 96, 97, 98 Free Software Foundation, Inc.
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

/*
 *	ISO C Standard: 4.11 STRING HANDLING	<string.h>
 */

#ifndef	_STRING_H
#define	_STRING_H	1

#include <features.h>

__BEGIN_DECLS

/* Get size_t and NULL from <stddef.h>.  */
#define	__need_size_t
#define	__need_NULL
#include <stddef.h>


/* Copy N bytes of SRC to DEST.  */
extern __ptr_t memcpy __P ((__ptr_t __restrict __dest,
			    __const __ptr_t __restrict __src, size_t __n));
/* Copy N bytes of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
extern __ptr_t memmove __P ((__ptr_t __dest, __const __ptr_t __src,
			     size_t __n));

/* Copy no more than N bytes of SRC to DEST, stopping when C is found.
   Return the position in DEST one byte past where C was copied,
   or NULL if C was not found in the first N bytes of SRC.  */
extern __ptr_t __memccpy __P ((__ptr_t __dest, __const __ptr_t __src,
			       int __c, size_t __n));
#if defined __USE_SVID || defined __USE_BSD || defined __USE_XOPEN
extern __ptr_t memccpy __P ((__ptr_t __dest, __const __ptr_t __src,
			     int __c, size_t __n));
#endif /* SVID.  */


/* Set N bytes of S to C.  */
extern __ptr_t memset __P ((__ptr_t __s, int __c, size_t __n));

/* Compare N bytes of S1 and S2.  */
extern int memcmp __P ((__const __ptr_t __s1, __const __ptr_t __s2,
			size_t __n));

/* Search N bytes of S for C.  */
extern __ptr_t memchr __P ((__const __ptr_t __s, int __c, size_t __n));


/* Copy SRC to DEST.  */
extern char *strcpy __P ((char *__restrict __dest,
			  __const char *__restrict __src));
/* Copy no more than N characters of SRC to DEST.  */
extern char *strncpy __P ((char *__restrict __dest,
			   __const char *__restrict __src, size_t __n));

/* Append SRC onto DEST.  */
extern char *strcat __P ((char *__restrict __dest,
			  __const char *__restrict __src));
/* Append no more than N characters from SRC onto DEST.  */
extern char *strncat __P ((char *__restrict __dest,
			   __const char *__restrict __src, size_t __n));

/* Compare S1 and S2.  */
extern int strcmp __P ((__const char *__s1, __const char *__s2));
/* Compare N characters of S1 and S2.  */
extern int strncmp __P ((__const char *__s1, __const char *__s2, size_t __n));

/* Compare the collated forms of S1 and S2.  */
extern int strcoll __P ((__const char *__s1, __const char *__s2));
/* Put a transformation of SRC into no more than N bytes of DEST.  */
extern size_t strxfrm __P ((char *__restrict __dest,
			    __const char *__restrict __src, size_t __n));

#if defined __USE_SVID || defined __USE_BSD || defined __USE_XOPEN_EXTENDED
/* Duplicate S, returning an identical malloc'd string.  */
extern char *__strdup __P ((__const char *__s));
extern char *strdup __P ((__const char *__s));
#endif

#if defined __USE_GNU && defined __GNUC__
/* Duplicate S, returning an identical alloca'd string.  */
# define strdupa(s)							      \
  (__extension__							      \
    ({									      \
      __const char *__old = (s);					      \
      size_t __len = strlen (__old) + 1;				      \
      char *__new = __builtin_alloca (__len);				      \
      (char *) memcpy (__new, __old, __len);				      \
    }))

/* Return an alloca'd copy of at most N bytes of string.  */
# define strndupa(s, n)							      \
  (__extension__							      \
    ({									      \
      __const char *__old = (s);					      \
      size_t __len = strnlen (__old, (n));				      \
      char *__new = __builtin_alloca (__len + 1);			      \
      __new[__len] = '\0';						      \
      (char *) memcpy (__new, __old, __len);				      \
    }))
#endif

/* Find the first occurrence of C in S.  */
extern char *strchr __P ((__const char *__s, int __c));
/* Find the last occurrence of C in S.  */
extern char *strrchr __P ((__const char *__s, int __c));

/* Return the length of the initial segment of S which
   consists entirely of characters not in REJECT.  */
extern size_t strcspn __P ((__const char *__s, __const char *__reject));
/* Return the length of the initial segment of S which
   consists entirely of characters in ACCEPT.  */
extern size_t strspn __P ((__const char *__s, __const char *__accept));
/* Find the first occurrence in S of any character in ACCEPT.  */
extern char *strpbrk __P ((__const char *__s, __const char *__accept));
/* Find the first occurrence of NEEDLE in HAYSTACK.  */
extern char *strstr __P ((__const char *__haystack, __const char *__needle));

/* Divide S into tokens separated by characters in DELIM.  */
extern char *strtok __P ((char *__restrict __s,
			  __const char *__restrict __delim));

/* Divide S into tokens separated by characters in DELIM.  Information
   passed between calls are stored in SAVE_PTR.  */
extern char *__strtok_r __P ((char *__s, __const char *__delim,
			      char **__save_ptr));
#if defined __USE_POSIX || defined __USE_MISC
extern char *strtok_r __P ((char *__s, __const char *__delim,
			    char **__save_ptr));
#endif


/* Return the length of S.  */
extern size_t strlen __P ((__const char *__s));


/* Return a string describing the meaning of the `errno' code in ERRNUM.  */
extern char *strerror __P ((int __errnum));
#ifdef	__USE_MISC
/* Reentrant version of `strerror'.  If a temporary buffer is required, at
   most BUFLEN bytes of BUF will be used.  */
extern char *__strerror_r __P ((int __errnum, char *__buf, size_t __buflen));
extern char *strerror_r __P ((int __errnum, char *__buf, size_t __buflen));
#endif

/* We define this function always since `bzero' is sometimes needed when
   the namespace rules does not allow this.  */
extern void __bzero __P ((__ptr_t __s, size_t __n));

#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED
/* Copy N bytes of SRC to DEST (like memmove, but args reversed).  */
extern void bcopy __P ((__const __ptr_t __src, __ptr_t __dest, size_t __n));

/* Set N bytes of S to 0.  */
extern void bzero __P ((__ptr_t __s, size_t __n));

/* Compare N bytes of S1 and S2 (same as memcmp).  */
extern int bcmp __P ((__const __ptr_t __s1, __const __ptr_t __s2, size_t __n));

/* Find the first occurrence of C in S (same as strchr).  */
extern char *index __P ((__const char *__s, int __c));

/* Find the last occurrence of C in S (same as strrchr).  */
extern char *rindex __P ((__const char *__s, int __c));

/* Return the position of the first bit set in I, or 0 if none are set.
   The least-significant bit is position 1, the most-significant 32.  */
extern int __ffs __P ((int __i));
extern int ffs __P ((int __i));

/* Compare S1 and S2, ignoring case.  */
extern int __strcasecmp __P ((__const char *__s1, __const char *__s2));
extern int strcasecmp __P ((__const char *__s1, __const char *__s2));

/* Compare no more than N chars of S1 and S2, ignoring case.  */
extern int __strncasecmp __P ((__const char *__s1, __const char *__s2,
			       size_t __n));
extern int strncasecmp __P ((__const char *__s1, __const char *__s2,
			     size_t __n));
#endif /* Use BSD or X/Open Unix.  */

#ifdef	__USE_BSD
/* Return the next DELIM-delimited token from *STRINGP,
   terminating it with a '\0', and update *STRINGP to point past it.  */
extern char *__strsep __P ((char **__stringp, __const char *__delim));
extern char *strsep __P ((char **__stringp, __const char *__delim));
#endif


#if defined __GNUC__ && __GNUC__ >= 2
# if defined __OPTIMIZE__ && !defined __OPTIMIZE_SIZE__
/* When using GNU CC we provide some optimized versions of selected
   functions from this header.  There are two kinds of optimizations:

   - machine-dependent optimizations, most probably using inline
     assembler code; these might be quite expensive since the code
     size can increase significantly.
     These optimizations are not used unless the symbol
	__USE_STRING_INLINES
     is defined before including this header.

   - machine-independent optimizations which do not increase the
     code size significantly and which optimize mainly situations
     where one or more arguments are compile-time constants.
     These optimizations are used always when the compiler is
     taught to optimize.

   One can inhibit all optimizations by defining __NO_STRING_INLINES.  */

/* Get the machine-dependent optimizations (if any).  */
#  include <bits/string.h>

/* These are generic optimizations which do not add too much inline code.  */
#  include <bits/string2.h>
# endif
#endif

__END_DECLS

#endif /* string.h  */
