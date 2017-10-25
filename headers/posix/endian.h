#ifndef	_ENDIAN_H_
#define	_ENDIAN_H_


/* Definitions for byte order, according to significance of bytes, from low
   addresses to high addresses.  The value is what you get by putting '4'
   in the most significant byte, '3' in the second most significant byte,
   '2' in the second least significant byte, and '1' in the least
   significant byte.  */

#if __INTEL__
#define	__LITTLE_ENDIAN	1234
#define LITTLE_ENDIAN	__LITTLE_ENDIAN
#define __BYTE_ORDER 	__LITTLE_ENDIAN
#define BYTE_ORDER		__BYTE_ORDER

#define __BIG_ENDIAN 	0
#define BIG_ENDIAN		0
#endif                       /* __INTEL__ */

#if __POWERPC__
#define	__BIG_ENDIAN	4321
#define BIG_ENDIAN		__BIG_ENDIAN
#define __BYTE_ORDER 	__BIG_ENDIAN
#define BYTE_ORDER		__BYTE_ORDER

#define __LITTLE_ENDIAN	0
#define LITTLE_ENDIAN	0
#endif                      /* __POWERPC__ */

#if __PDP__
#define	__PDP_ENDIAN	3412
#define PDP_ENDIAN		__PDP_ENDIAN
#endif /* __PDP__ */

#endif	/* endian.h */
