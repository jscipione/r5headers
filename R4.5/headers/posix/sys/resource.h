#ifndef _SYS_RESOURCE_H
#define _SYS_RESOURCE_H

#include <sys/time.h>

/*
 * Resource control/accounting header file
 */

#define RUSAGE_SELF		0
#define RUSAGE_CHILDREN	-1

struct rusage {
	struct timeval ru_utime;	/* user time used */
	struct timeval ru_stime;	/* kernel (system) time used */
};

extern int getrusage(int who, struct rusage *r); 

#endif /* _SYS_RESOURCE_H */
