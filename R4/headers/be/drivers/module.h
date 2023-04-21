/*******************************************************************************
/
/	File:			modules.h
/
/	Description:	Public module-related API
/
/	Copyright 1998, Be Incorporated, All Rights Reserved.
/
*******************************************************************************/

#ifndef _MODULE_H
#define _MODULE_H

#include <BeBuild.h>
#include <OS.h>

#ifdef __cplusplus
extern "C" {
#endif

/* module flags */

#define	B_KEEP_LOADED		0x00000001


/* module info structure */

typedef struct module_info module_info;

struct module_info {
	const char	*name;
	uint32		flags;
	status_t	(*std_ops)(int32);
};

#define	B_MODULE_INIT	1
#define	B_MODULE_UNINIT	2

_IMPEXP_KERNEL status_t	get_module(const char *path, module_info **vec);
_IMPEXP_KERNEL status_t	put_module(const char *path);

#ifdef __cplusplus
}
#endif

#endif
