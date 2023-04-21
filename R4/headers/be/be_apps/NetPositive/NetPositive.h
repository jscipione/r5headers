/*******************************************************************************
/
/	File:			NetPositive.h
/
/   Description:    Defines all public APIs for communicating with NetPositive
/
/	Copyright 1998, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#ifndef	_NETPOSITIVE_H
#define	_NETPOSITIVE_H

/*----------------------------------------------------------------*/
/*-----  message command constants -------------------------------*/

enum {
	/* Can be sent to the NetPositive application, a window, or a replicant */
	/* view.  Put the URL in a String field named be:url                    */
	B_NETPOSITIVE_OPEN_URL		= 'NPOP',	

	/* Can be sent to a window or replicant view */
	B_NETPOSITIVE_BACK			= 'NPBK',
	B_NETPOSITIVE_FORWARD		= 'NPFW',
	B_NETPOSITIVE_HOME			= 'NPHM',
	B_NETPOSITIVE_RELOAD		= 'NPRL',
	B_NETPOSITIVE_STOP		 	= 'NPST'
};
	
/*----------------------------------------------------------------*/
/*----------------------------------------------------------------*/

#endif /* _NETPOSITIVE_H */
