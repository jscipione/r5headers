/******************************************************************************
/
/	File:			Handler.h
/
/	Description:	BHandler class defines the message-handling
/					protocol.  MessageReceived() is its linchpin.
/
/	Copyright 1995-98, Be Incorporated, All Rights Reserved.
/
*******************************************************************************/

#ifndef _HANDLER_H
#define _HANDLER_H

#include <BeBuild.h>
#include <Archivable.h>
#include <Message.h>
#include <PropertyInfo.h>

class BLooper;
class BMessageFilter;
class BMessage;
class BList;

/*----------------------------------------------------------------*/
/*----- BHandler class --------------------------------------------*/

class BHandler : public BArchivable {

public:
					BHandler(const char *name = NULL);
virtual				~BHandler();

/* Archiving */
					BHandler(BMessage *data);
static	BArchivable	*Instantiate(BMessage *data);
virtual	status_t	Archive(BMessage *data, bool deep = true) const;

/* BHandler guts. */
virtual	void		MessageReceived(BMessage *message);
		BLooper		*Looper() const;
		void		SetName(const char *name);
		const char	*Name() const;
virtual	void		SetNextHandler(BHandler *handler);
		BHandler	*NextHandler() const;

/* Message filtering */
virtual	void		AddFilter(BMessageFilter *filter);
virtual	bool		RemoveFilter(BMessageFilter *filter);
virtual	void		SetFilterList(BList *filters);
		BList		*FilterList();

		bool		LockLooper();
		status_t	LockLooperWithTimeout(bigtime_t timeout);
		void		UnlockLooper();

/* Scripting  */
virtual BHandler	*ResolveSpecifier(BMessage *msg,
									int32 index,
									BMessage *specifier,
									int32 form,
									const char *property);
virtual status_t	GetSupportedSuites(BMessage *data);

/*----- Private or reserved -----------------------------------------*/
virtual status_t	Perform(perform_code d, void *arg);

private:
typedef BArchivable _inherited;
friend inline int32 _get_object_token_(const BHandler *);
friend class BLooper;
friend class BMessageFilter;

virtual	void		_ReservedHandler1();
virtual	void		_ReservedHandler2();
virtual	void		_ReservedHandler3();
virtual	void		_ReservedHandler4();

		void		InitData(const char *name);

					BHandler(const BHandler &);
		BHandler	&operator=(const BHandler &);
		void		SetLooper(BLooper *loop);

		int32		fToken;
		char		*fName;
		BLooper		*fLooper;
		BHandler	*fNextHandler;
		BList		*fFilters;
		uint32		_reserved[4];
};

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

#endif /* _HANDLER_H */
