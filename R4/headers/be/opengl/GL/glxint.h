#ifndef __GLX_glxint_h__
#define __GLX_glxint_h__

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

typedef struct __glXVisualConfigRec __glXVisualConfig;

struct __glXVisualConfigRec {
    VisualID vid;
    int class;
    Bool rgba;
    int redSize, greenSize, blueSize, alphaSize;
    int accumRedSize, accumGreenSize, accumBlueSize, accumAlphaSize;
    Bool doubleBuffer;
    Bool stereo;
    int bufferSize;
    int depthSize;
    int stencilSize;
    int auxBuffers;
    int level;
    /* Start of Extended Visual Properties */
    int visualRating;		/* visual_rating extension */
    int transparentPixel;	/* visual_info extension */
				/*    colors are floats scaled to ints */
    int transparentRed, transparentGreen, transparentBlue, transparentAlpha;
    int transparentIndex;
};

#define __GLX_MIN_CONFIG_PROPS	18
#define __GLX_MAX_CONFIG_PROPS	500

#define __GLX_EXT_CONFIG_PROPS 	7

/*
** Since we send all non-core visual properties as token, value pairs,
** we require 2 words across the wire. In order to maintain backwards
** compatibility, we need to send the total number of words that the
** VisualConfigs are sent back in so old libraries can simply "ignore"
** the new properties. 
*/
#define __GLX_TOTAL_CONFIG       (__GLX_MIN_CONFIG_PROPS +      \
                                    2 * __GLX_EXT_CONFIG_PROPS)

#endif /* !__GLX_glxint_h__ */
