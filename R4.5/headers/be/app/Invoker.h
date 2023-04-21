/******************************************************************************
/
/	File:			Invoker.h
/
/	Description:	BInvoker class defines a protocol for objects that
/					post messages to a "target".
/
/	Copyright 1995-98, Be Incorporated, All Rights Reserved.
/
*******************************************************************************/

#ifndef _INVOKER_H
#define	_INVOKER_H

#include <BeBuild.h>
#include <Messenger.h>
#include <Message.h>
#include <Handler.h>
#include <Looper.h>

/*-----------------------------------------------------------------*/
/*----- BInvoker class --------------------------------------------*/

class BInvoker {
public:
					BInvoker(); 
					BInvoker(BMessage *message,
							 const BHandler *handler,
							 const BLooper *looper = NULL);
					BInvoker(BMessage *message, BMessenger target);
virtual				~BInvoker();

virtual	status_t	SetMessage(BMessage *message);
		BMessage	*Message() const;
		uint32		Command() const;

virtual status_t	SetTarget(const BHandler *h, const BLooper *loop = NULL);
virtual status_t	SetTarget(BMessenger messenger);
		bool		IsTargetLocal() const;
		BHandler	*Target(BLooper **looper = NULL) const;
		BMessenger	Messenger() const;

virtual status_t	SetHandlerForReply(BHandler *handler);
		BHandler	*HandlerForReply() const;

virtual	status_t	Invoke(BMessage *msg = NULL);

		status_t	SetTimeout(bigtime_t timeout);
		bigtime_t	Timeout() const;

/*----- Private or reserved -----------------------------------------*/
private:

virtual	void		_ReservedInvoker1();
virtual	void		_ReservedInvoker2();
virtual	void		_ReservedInvoker3();

					BInvoker(const BInvoker &);
		BInvoker	&operator=(const BInvoker &);

		BMessage	*fMessage;
		BMessenger	fMessenger;
		BHandler	*fReplyTo;
		uint32		fTimeout;
		uint32		_reserved[3];
};

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

#endif /* _INVOKER_H */
