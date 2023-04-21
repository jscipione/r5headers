#ifndef _IOVEC_H
#define _IOVEC_H

#include <sys/types.h>

typedef struct iovec iovec;

struct iovec {
	void	*iov_base;
	size_t	iov_len;
};


#endif

