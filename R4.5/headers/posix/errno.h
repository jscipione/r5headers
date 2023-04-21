#ifndef _ERRNO_H_
#define _ERRNO_H_

#include <be_setup.h>

#include <Errors.h>

#define ENOERR          0
#define EOK 			ENOERR  /* some code assumes EOK exists */


__extern_c_start
extern int *_errnop(void);
__extern_c_end

#define errno (*(_errnop()))


#endif /* _ERRNO_H_ */

