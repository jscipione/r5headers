#ifndef _PWD_H_
#define _PWD_H_

#include <sys/types.h>
#if __BEOS__
#include <BeBuild.h>
#else
#ifndef _IMPEXP_ROOT
#define	_IMPEXP_ROOT
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct passwd {
        char    *pw_name;
		char    *pw_passwd;
        uid_t   pw_uid;
        gid_t   pw_gid;
        char    *pw_dir;
        char    *pw_shell;
};

extern _IMPEXP_ROOT void           setpwent(void);
extern _IMPEXP_ROOT void           endpwent(void);
extern _IMPEXP_ROOT struct passwd *getpwent(void);
extern _IMPEXP_ROOT struct passwd *getpwnam(const char *name);
extern _IMPEXP_ROOT struct passwd *getpwuid(uid_t uid);

#ifdef __cplusplus
}
#endif
#endif /* _PWD_H_ */
