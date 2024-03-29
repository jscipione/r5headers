/******************************************************************************
/
/	File:			AppDefs.h
/
/	Description:	Message codes and the global cursors.
/
/	Copyright 1993-98, Be Incorporated
/
*******************************************************************************/

#ifndef _APP_DEFS_H
#define _APP_DEFS_H

#include <BeBuild.h>
#include <SupportDefs.h>
#include <TypeConstants.h>

/*---------------------------------------------------------*/
/*----- Global Cursors ------------------------------------*/

extern _IMPEXP_BE const unsigned char B_HAND_CURSOR[];
extern _IMPEXP_BE const unsigned char B_I_BEAM_CURSOR[];

/*---------------------------------------------------------------*/
/*----- System Message Codes ------------------------------------*/

enum {
	B_ABOUT_REQUESTED		= '_ABR',
	B_WINDOW_ACTIVATED		= '_ACT',
	B_APP_ACTIVATED			= '_ACT',	/* Same as B_WINDOW_ACTIVATED */
	B_ARGV_RECEIVED 		= '_ARG',
	B_QUIT_REQUESTED 		= '_QRQ',
	B_CLOSE_REQUESTED 		= '_QRQ',	/* Obsolete; use B_QUIT_REQUESTED */
	B_CANCEL				= '_CNC',
	B_KEY_DOWN 				= '_KYD',
	B_KEY_UP 				= '_KYU',
	B_MODIFIERS_CHANGED		= '_MCH',
	B_MINIMIZE				= '_WMN',
	B_MOUSE_DOWN 			= '_MDN',
	B_MOUSE_MOVED 			= '_MMV',
	B_MOUSE_ENTER_EXIT		= '_MEX',
	B_MOUSE_UP 				= '_MUP',
	B_OPEN_IN_WORKSPACE		= '_OWS',
	B_PULSE 				= '_PUL',
	B_READY_TO_RUN 			= '_RTR',
	B_REFS_RECEIVED 		= '_RRC',
	B_SCREEN_CHANGED 		= '_SCH',
	B_VALUE_CHANGED 		= '_VCH',
	B_VIEW_MOVED 			= '_VMV',
	B_VIEW_RESIZED 			= '_VRS',
	B_WINDOW_MOVED 			= '_WMV',
	B_WINDOW_RESIZED 		= '_WRS',
	B_WORKSPACES_CHANGED	= '_WCG',
	B_WORKSPACE_ACTIVATED	= '_WAC',
	B_ZOOM					= '_WZM',
	_APP_MENU_				= '_AMN',
	_BROWSER_MENUS_			= '_BRM',
	_MENU_EVENT_ 			= '_MEV',
	_PING_					= '_PBL',
	_QUIT_ 					= '_QIT',
	_VOLUME_MOUNTED_ 		= '_NVL',
	_VOLUME_UNMOUNTED_		= '_VRM',
	_MESSAGE_DROPPED_ 		= '_MDP',
	_DISPOSE_DRAG_ 			= '_DPD',
	_MENUS_DONE_			= '_MND',
	_SHOW_DRAG_HANDLES_		= '_SDH',
	_EVENTS_PENDING_ 		= '_EVP',
	_UPDATE_ 				= '_UPD'
	/* Media Kit reserves all reserved codes starting in '_TR' */
};


/*---------------------------------------------------------*/
/*----- Other Commands ------------------------------------*/

enum {
	B_SET_PROPERTY				= 'PSET',
	B_GET_PROPERTY				= 'PGET',
	B_CREATE_PROPERTY			= 'PCRT',
	B_DELETE_PROPERTY			= 'PDEL',
	B_COUNT_PROPERTIES			= 'PCNT',
	B_EXECUTE_PROPERTY			= 'PEXE',
	B_GET_SUPPORTED_SUITES		= 'SUIT',
	B_UNDO						= 'UNDO',
	B_CUT 						= 'CCUT',
	B_COPY 						= 'COPY',
	B_PASTE 					= 'PSTE',
	B_SELECT_ALL				= 'SALL',
	B_SAVE_REQUESTED 			= 'SAVE',
	B_MESSAGE_NOT_UNDERSTOOD	= 'MNOT',
	B_NO_REPLY 					= 'NONE',
	B_REPLY 					= 'RPLY',
	B_SIMPLE_DATA				= 'DATA',
	B_MIME_DATA					= 'MIME',
	B_ARCHIVED_OBJECT			= 'ARCV',
	B_UPDATE_STATUS_BAR			= 'SBUP',
	B_RESET_STATUS_BAR			= 'SBRS',
	B_NODE_MONITOR				= 'NDMN',
	B_QUERY_UPDATE				= 'QUPD',
	B_ENDORSABLE				= 'ENDO',
	B_COPY_TARGET				= 'DDCP',
	B_MOVE_TARGET				= 'DDMV',
	B_TRASH_TARGET				= 'DDRM',
	B_LINK_TARGET				= 'DDLN',
	B_INPUT_DEVICES_CHANGED		= 'IDCH',
	B_INPUT_METHOD_EVENT		= 'IMEV'
	/* Media Kit reserves all reserved codes starting in 'TRI' */
};

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

#endif /* _APP_DEFS_H */
