/* Copyright (C) 1997, 1998 Free Software Foundation, Inc.
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
 *	ISO C 9X: 7.5 Format conversion of integer types	<inttypes.h>
 */

#ifndef _INTTYPES_H
#define _INTTYPES_H	1

#include <features.h>
/* Get the type definitions.  */
#include <stdint.h>


/* The ISO C 9X standard specifies that these macros must only be
   defined if explicitly requested.  */
#if !defined __cplusplus || defined __STDC_FORMAT_MACROS

/* Macros for printing format specifiers.  */

/* Decimal notation.  */
# define PRId8		"d"
# define PRId16		"d"
# define PRId32		"d"
# define PRId64		"lld"

# define PRIdLEAST8	"d"
# define PRIdLEAST16	"d"
# define PRIdLEAST32	"d"
# define PRIdLEAST64	"lld"

# define PRIdFAST8	"d"
# define PRIdFAST16	"d"
# define PRIdFAST32	"d"
# define PRIdFAST64	"lld"


# define PRIi8		"i"
# define PRIi16		"i"
# define PRIi32		"i"
# define PRIi64		"lli"

# define PRIiLEAST8	"i"
# define PRIiLEAST16	"i"
# define PRIiLEAST32	"i"
# define PRIiLEAST64	"lli"

# define PRIiFAST8	"i"
# define PRIiFAST16	"i"
# define PRIiFAST32	"i"
# define PRIiFAST64	"lli"

/* Octal notation.  */
# define PRIo8		"o"
# define PRIo16		"o"
# define PRIo32		"o"
# define PRIo64		"llo"

# define PRIoLEAST8	"o"
# define PRIoLEAST16	"o"
# define PRIoLEAST32	"o"
# define PRIoLEAST64	"llo"

# define PRIoFAST8	"o"
# define PRIoFAST16	"o"
# define PRIoFAST32	"o"
# define PRIoFAST64	"llo"

/* lowercase hexadecimal notation.  */
# define PRIx8		"x"
# define PRIx16		"x"
# define PRIx32		"x"
# define PRIx64		"llx"

# define PRIxLEAST8	"x"
# define PRIxLEAST16	"x"
# define PRIxLEAST32	"x"
# define PRIxLEAST64	"llx"

# define PRIxFAST8	"x"
# define PRIxFAST16	"x"
# define PRIxFAST32	"x"
# define PRIxFAST64	"llx"

/* UPPERCASE hexadecimal notation.  */
# define PRIX8		"X"
# define PRIX16		"X"
# define PRIX32		"X"
# define PRIX64		"llX"

# define PRIXLEAST8	"X"
# define PRIXLEAST16	"X"
# define PRIXLEAST32	"X"
# define PRIXLEAST64	"llX"

# define PRIXFAST8	"X"
# define PRIXFAST16	"X"
# define PRIXFAST32	"X"
# define PRIXFAST64	"llX"


/* Unsigned integers.  */
# define PRIu8		"u"
# define PRIu16		"u"
# define PRIu32		"u"
# define PRIu64		"llu"

# define PRIuLEAST8	"u"
# define PRIuLEAST16	"u"
# define PRIuLEAST32	"u"
# define PRIuLEAST64	"llu"

# define PRIuFAST8	"u"
# define PRIuFAST16	"u"
# define PRIuFAST32	"u"
# define PRIuFAST64	"llu"


/* Macros for printing `intmax_t' and `uintmax_t'.  */
# define PRIdMAX	"lld"
# define PRIoMAX	"llo"
# define PRIxMAX	"llx"
# define PRIuMAX	"llu"


/* Macros for printing `intptr_t' and `uintptr_t'.  */
# define PRIdPTR	"d"
# define PRIoPTR	"o"
# define PRIxPTR	"x"
# define PRIuPTR	"u"


/* Macros for scanning format specifiers.  */

/* Decimal notation.  */
# define SCNd8		"hhd"
# define SCNd16		"hd"
# define SCNd32		"d"
# define SCNd64		"lld"

# define SCNi8		"hhi"
# define SCNi16		"hi"
# define SCNi32		"i"
# define SCNi64		"lli"

# define SCNu8		"hhu"
# define SCNu16		"hu"
# define SCNu32		"u"
# define SCNu64		"llu"

/* Octal notation.  */
# define SCNo8		"hho"
# define SCNo16		"ho"
# define SCNo32		"o"
# define SCNo64		"llo"

/* Hexadecimal notation.  */
# define SCNx8		"hhx"
# define SCNx16		"hx"
# define SCNx32		"x"
# define SCNx64		"llx"


/* Macros for scaning `intptr_t' and `uintptr_t'.  */
# define SCNdPTR	"d"
# define SCNiPTR	"i"
# define SCNoPTR	"o"
# define SCNxPTR	"x"

#endif	/* C++ && format macros */


__BEGIN_DECLS

/* Like `strtol' but convert to `intmax_t'.  */
extern intmax_t strtoimax __P ((__const char *__restrict __nptr,
				char **__restrict __endptr, int __base));

/* Like `strtoul' but convert to `uintmax_t'.  */
extern uintmax_t strtoumax __P ((__const char * __restrict __nptr,
				 char ** __restrict __endptr, int __base));

/* Like `wcstol' but convert to `intmax_t'.  */
extern intmax_t wcstoimax __P ((__const wchar_t * __restrict __nptr,
				wchar_t **__restrict __endptr, int __base));

/* Like `wcstoul' but convert to `uintmax_t'.  */
extern uintmax_t wcstoumax __P ((__const wchar_t * __restrict __nptr,
				 wchar_t ** __restrict __endptr, int __base));

#if defined __GNUC__ && __GNUC__ >= 2 && defined __OPTIMIZE__

/* Like `strtol' but convert to `intmax_t'.  */
# ifndef __strtoll_internal_defined
extern long long int __strtoll_internal __P ((__const char *__restrict __nptr,
					      char **__restrict __endptr,
					      int __base, int __group));
#  define __strtoll_internal_defined	1
# endif
extern __inline intmax_t
strtoimax (__const char *__restrict nptr, char **__restrict endptr, int base)
{
  return __strtoll_internal (nptr, endptr, base, 0);
}

/* Like `strtoul' but convert to `uintmax_t'.  */
# ifndef __strtoull_internal_defined
extern unsigned long long int __strtoull_internal __P ((__const char *
							__restrict __nptr,
							char **
							__restrict __endptr,
							int __base,
							int __group));
#  define __strtoull_internal_defined	1
# endif
extern __inline uintmax_t
strtoumax (__const char *__restrict nptr, char **__restrict endptr, int base)
{
  return __strtoull_internal (nptr, endptr, base, 0);
}

/* Like `wcstol' but convert to `intmax_t'.  */
# ifndef __wcstoll_internal_defined
extern long long int __wcstoll_internal __P ((__const wchar_t *
					      __restrict __nptr,
					      wchar_t **__restrict __endptr,
					      int __base, int __group));
#  define __wcstoll_internal_defined	1
# endif
extern __inline intmax_t
wcstoimax (__const wchar_t *__restrict nptr, wchar_t **__restrict endptr,
	   int base)
{
  return __wcstoll_internal (nptr, endptr, base, 0);
}


/* Like `wcstoul' but convert to `uintmax_t'.  */
# ifndef __wcstoull_internal_defined
extern unsigned long long int __wcstoull_internal __P ((__const wchar_t *
							__restrict __nptr,
							wchar_t **
							__restrict __endptr,
							int __base,
							int __group));
#  define __wcstoull_internal_defined	1
# endif
extern __inline uintmax_t
wcstoumax (__const wchar_t *__restrict nptr, wchar_t **__restrict endptr,
	   int base)
{
  return __wcstoull_internal (nptr, endptr, base, 0);
}
#endif	/* GCC and Optimization.  */

__END_DECLS

#endif /* inttypes.h */
