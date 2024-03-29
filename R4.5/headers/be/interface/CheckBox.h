/******************************************************************************
/
/	File:			CheckBox.h
/
/   Description:    BCheckBox displays an on/off control.
/
/	Copyright 1992-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/


#ifndef	_CHECK_BOX_H
#define	_CHECK_BOX_H

#include <BeBuild.h>
#include <Control.h>
#include <Window.h>

/*----------------------------------------------------------------*/
/*----- BCheckBox class ------------------------------------------*/

class BCheckBox : public BControl {

public:
					BCheckBox(BRect frame,
							const char *name,
							const char *label,
							BMessage *message,
							uint32 resizeMask = B_FOLLOW_LEFT | B_FOLLOW_TOP, 
							uint32 flags = B_WILL_DRAW | B_NAVIGABLE); 
virtual				~BCheckBox();

/* Archiving */
					BCheckBox(BMessage *data);
static	BArchivable	*Instantiate(BMessage *data);
virtual	status_t	Archive(BMessage *data, bool deep = true) const;

virtual	void		Draw(BRect updateRect);
virtual	void		AttachedToWindow();
virtual	void		MouseDown(BPoint where);

virtual void		MessageReceived(BMessage *msg);
virtual void		WindowActivated(bool state);
virtual	void		KeyDown(const char *bytes, int32 numBytes);
virtual	void		MouseUp(BPoint pt);
virtual	void		MouseMoved(BPoint pt, uint32 code, const BMessage *msg);
virtual	void		DetachedFromWindow();
virtual	void		SetValue(int32 value);
virtual void		GetPreferredSize(float *width, float *height);
virtual void		ResizeToPreferred();
virtual	status_t	Invoke(BMessage *msg = NULL);
virtual	void		FrameMoved(BPoint new_position);
virtual	void		FrameResized(float new_width, float new_height);

virtual BHandler	*ResolveSpecifier(BMessage *msg,
									int32 index,
									BMessage *specifier,
									int32 form,
									const char *property);
virtual status_t	GetSupportedSuites(BMessage *data);

virtual void		MakeFocus(bool state = true);
virtual void		AllAttached();
virtual void		AllDetached();


/*----- Private or reserved -----------------------------------------*/
virtual status_t	Perform(perform_code d, void *arg);

private:

virtual	void		_ReservedCheckBox1();
virtual	void		_ReservedCheckBox2();
virtual	void		_ReservedCheckBox3();

		BCheckBox	&operator=(const BCheckBox &);

		bool		fOutlined;
		uint32		_reserved[2];
};

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

#endif /* _CHECK_BOX_H */
