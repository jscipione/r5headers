#ifndef __GLX_glxtokens_h__
#define __GLX_glxtokens_h__

/*
** Copyright 1991-95, Silicon Graphics, Inc.
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

#ifdef __cplusplus
extern "C" {
#endif

#define GLX_VERSION_1_1 1
#define GLX_VERSION_1_2 1

/*
** Names for attributes to glXGetConfig.
*/
#define GLX_USE_GL		1	/* support GLX rendering */
#define GLX_BUFFER_SIZE		2	/* depth of the color buffer */
#define GLX_LEVEL		3	/* level in plane stacking */
#define GLX_RGBA		4	/* true if RGBA mode */
#define GLX_DOUBLEBUFFER	5	/* double buffering supported */
#define GLX_STEREO		6	/* stereo buffering supported */
#define GLX_AUX_BUFFERS 	7	/* number of aux buffers */
#define GLX_RED_SIZE		8	/* number of red component bits */
#define GLX_GREEN_SIZE		9	/* number of green component bits */
#define GLX_BLUE_SIZE		10	/* number of blue component bits */
#define GLX_ALPHA_SIZE		11	/* number of alpha component bits */
#define GLX_DEPTH_SIZE		12	/* number of depth bits */
#define GLX_STENCIL_SIZE	13	/* number of stencil bits */
#define GLX_ACCUM_RED_SIZE	14	/* number of red accum bits */
#define GLX_ACCUM_GREEN_SIZE	15	/* number of green accum bits */
#define GLX_ACCUM_BLUE_SIZE	16	/* number of blue accum bits */
#define GLX_ACCUM_ALPHA_SIZE	17	/* number of alpha accum bits */

/*
** Error return values from glXGetConfig.  Success is indicated by
** a value of 0.
*/
#define GLX_BAD_SCREEN		1	/* screen # is bad */
#define GLX_BAD_ATTRIBUTE	2	/* attribute to get is bad */
#define GLX_NO_EXTENSION	3	/* no glx extension on server */
#define GLX_BAD_VISUAL		4	/* visual # not known by GLX */
#define GLX_BAD_CONTEXT         5
#define GLX_BAD_VALUE           6
#define GLX_BAD_ENUM            7

/*
** Extension return values from glXGetConfig.  These are also
** accepted as parameter values for glXChooseVisual.
*/

#define GLX_X_VISUAL_TYPE_EXT	0x22	/* visual_info extension type */
#define GLX_TRANSPARENT_TYPE_EXT 0x23	/* visual_info extension */
#define GLX_TRANSPARENT_INDEX_VALUE_EXT 0x24	/* visual_info extension */
#define GLX_TRANSPARENT_RED_VALUE_EXT   0x25	/* visual_info extension */
#define GLX_TRANSPARENT_GREEN_VALUE_EXT 0x26	/* visual_info extension */
#define GLX_TRANSPARENT_BLUE_VALUE_EXT  0x27	/* visual_info extension */
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT 0x28	/* visual_info extension */

/* Property values for visual_type */
#define GLX_TRUE_COLOR_EXT     	0x8002
#define GLX_DIRECT_COLOR_EXT    0x8003  
#define GLX_PSEUDO_COLOR_EXT    0x8004 
#define GLX_STATIC_COLOR_EXT    0x8005
#define GLX_GRAY_SCALE_EXT    	0x8006  
#define GLX_STATIC_GRAY_EXT    	0x8007 

/* Property values for transparent pixel */
#define GLX_NONE_EXT     	0x8000     
#define GLX_TRANSPARENT_RGB_EXT    	0x8008    
#define GLX_TRANSPARENT_INDEX_EXT    	0x8009    

/* Property values for visual_rating */
#define GLX_VISUAL_CAVEAT_EXT    	0x20  /* visual_rating extension type */
#define GLX_SLOW_VISUAL_EXT		0x8001   
#define GLX_NON_CONFORMANT_VISUAL_EXT	0x800D

/*
** Names for attributes to glXGetClientString.
*/
#define GLX_EXTENSIONS		0x1
#define GLX_VENDOR		0x2
#define GLX_VERSION		0x3

/*
** Names for attributes to glXQueryContextInfoEXT.
*/
#define GLX_SHARE_CONTEXT_EXT	0x800A	/* id of share context */
#define GLX_VISUAL_ID_EXT	0x800B	/* id of context's visual */
#define GLX_SCREEN_EXT		0x800C	/* screen number */

/* GLX Extension Strings */
#define GLX_EXT_import_context  1
#define GLX_EXT_visual_info     1
#define GLX_EXT_visual_rating   1

#ifdef __cplusplus
}
#endif

#endif /* !__GLX_glxtokens_h__ */
