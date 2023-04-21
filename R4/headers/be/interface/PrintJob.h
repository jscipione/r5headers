/*******************************************************************************
/
/	File:			PrintJob.h
/
/   Description:    BPrintJob runs a printing session.
/
/	Copyright 1996-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#ifndef	_PRINTSESSION_H
#define	_PRINTSESSION_H

#include <BeBuild.h>
#include <InterfaceDefs.h>
#include <Rect.h>
#include <View.h>
#include <ClassInfo.h>

/*----------------------------------------------------------------*/
/*----- BPrintJob related structures -----------------------------*/

struct	print_file_header {
	int32	version;
	int32	page_count;
	off_t	first_page;
	int32	_reserved_3_;
	int32	_reserved_4_;
	int32	_reserved_5_;
};

struct _page_header_;

/*----------------------------------------------------------------*/
/*----- BPrintJob class ------------------------------------------*/

class BPrintJob {
public:

					BPrintJob(const char *job_name);
virtual				~BPrintJob();

		int32		ConfigPage();
		int32		ConfigJob();
virtual	void		DrawView(BView *a_view, BRect a_rect, BPoint where);
		void		CommitJob();	
		int32		FirstPage();
		int32		LastPage();
		BRect		PaperRect();
		BRect		PrintableRect();
		bool		CanContinue();
		void		BeginJob();	
		void		SpoolPage();
		BMessage	*Settings();	
		void		SetSettings(BMessage *a_msg);	
		void		CancelJob();

/*----- Private or reserved -----------------------------------------*/
private:

virtual void		_ReservedPrintJob1();
virtual void		_ReservedPrintJob2();
virtual void		_ReservedPrintJob3();
virtual void		_ReservedPrintJob4();

					BPrintJob(const BPrintJob &);
		BPrintJob	&operator=(const BPrintJob &);

		void				RecurseView(BView *v, BPoint origin, BPicture *p, BRect r);
		void				MangleName(char *filename);
		void				HandlePageSetup(BMessage *setup);
		void				HandlePrintSetup(BMessage *setup);
		void				CreateSpoolDir(const char *printer_name);

		void				NewPage();
		void				EndLastPage();

		void				AddSetupSpec();
		void				AddPicture(BPicture *picture, BRect *rect, BPoint where);

		void				GetXYDPI(long *xdpi, long *ydpi);

		char *				print_job_name;
		int32				page_number;
		BFile *				spoolFile;
		print_file_header	current_header;
		BRect				paper_size;
		BRect				usable_size;
		int					pr_error;
		char				spool_file_name[256];	
		BMessage			*setup_msg;
		BMessage			*job_msg;
		char				stop_the_show;
		int32				first_page;
		int32				last_page;
		short				v_xres;
		short				v_yres;
		_page_header_ *		m_curPageHeader;
		off_t				m_curPageHeaderOffset;
		uint32				_reserved[2];
};
 
/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

#endif /* _PRINTSESSION_H */
