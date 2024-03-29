#ifndef __GLX_glx_h__
#define __GLX_glx_h__

/*
** Copyright 1991, 1992, Silicon Graphics, Inc.
** All Rights Reserved.
** 
** This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
** the contents of this file may not be disclosed to third parties, copied or
** duplicated in any form, in whole or in part, without the prior written
** permission of Silicon Graphics, Inc.
** 
** RESTRICTED RIGHTS LEGEND:
** Use, duplication or disclosure by the Government is subject to restrictions
** as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
** and Computer Software clause at DFARS 252.227-7013, and/or in similar or
** successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
** rights reserved under the Copyright Laws of the United States.
*/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xmd.h>
#include <GL/gl.h>
#include <GL/glxproto.h>
#include <GL/glxtokens.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
** GLX resources.
*/
typedef XID GLXContextID;
typedef XID GLXPixmap;
typedef XID GLXDrawable;

/*
** GLXContext is a pointer to opaque data.
**/
typedef struct __glXContextRec *GLXContext;


/************************************************************************/

extern XVisualInfo* glXChooseVisual (Display *dpy, int screen, int *attribList);
extern void glXCopyContext (Display *dpy, GLXContext src, GLXContext dst, unsigned long mask);
extern GLXContext glXCreateContext (Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct);
extern GLXPixmap glXCreateGLXPixmap (Display *dpy, XVisualInfo *vis, Pixmap pixmap);
extern void glXDestroyContext (Display *dpy, GLXContext ctx);
extern void glXDestroyGLXPixmap (Display *dpy, GLXPixmap pix);
extern int glXGetConfig (Display *dpy, XVisualInfo *vis, int attrib, int *value);
extern GLXContext glXGetCurrentContext (void);
extern GLXDrawable glXGetCurrentDrawable (void);
extern Bool glXIsDirect (Display *dpy, GLXContext ctx);
extern Bool glXMakeCurrent (Display *dpy, GLXDrawable drawable, GLXContext ctx);
extern Bool glXQueryExtension (Display *dpy, int *errorBase, int *eventBase);
extern Bool glXQueryVersion (Display *dpy, int *major, int *minor);
extern void glXSwapBuffers (Display *dpy, GLXDrawable drawable);
extern void glXUseXFont (Font font, int first, int count, int listBase);
extern void glXWaitGL (void);
extern void glXWaitX (void);
extern const char * glXGetClientString (Display *dpy, int name );
extern const char * glXQueryServerString (Display *dpy, int screen, int name );
extern const char * glXQueryExtensionsString (Display *dpy, int screen );

extern Display * glXGetCurrentDisplayEXT (void);
extern GLXContextID glXGetContextIDEXT (const GLXContext ctx);
extern GLXDrawable glXGetCurrentDrawableEXT (void);
extern GLXContext glXImportContextEXT (Display *dpy, GLXContextID contextID);
extern void glXFreeContextEXT (Display *dpy, GLXContext ctx);
extern int glXQueryContextInfoEXT (Display *dpy, GLXContext ctx, int attribute, int *value);



#ifdef __cplusplus
}
#endif

#endif /* !__GLX_glx_h__ */
