#ifndef _GRP_H_
#define _GRP_H_

#include <sys/types.h>
#if __BEOS__
#include <BeBuild.h>
#else
#ifndef _IMPEXP_ROOT
#define	_IMPEXP_ROOT
#endif
#endif

struct group {
       char *gr_name;
       char *gr_passwd;
       int gr_gid;
       char **gr_mem;
};


#ifdef __cplusplus
extern "C" {
#endif

extern _IMPEXP_ROOT struct group *getgrgid(gid_t gid);
extern _IMPEXP_ROOT struct group *getgrnam(const char *name);

extern _IMPEXP_ROOT struct group *getgrent(void);
extern _IMPEXP_ROOT void          setgrent(void);
extern _IMPEXP_ROOT void          endgrent(void);

#ifdef __cplusplus
}
#endif

#endif /* _GRP_H_ */
