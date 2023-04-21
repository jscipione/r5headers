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

		void		BeginJob();	
		void		CommitJob();	
		int32		ConfigJob();
		void		CancelJob();

		int32		ConfigPage();
		void		SpoolPage();

		bool		CanContinue();

virtual	void		DrawView(BView *a_view, BRect a_rect, BPoint where);

		BMessage	*Settings();	/* const */	
		void		SetSettings(BMessage *a_msg);	

		BRect		PaperRect();
		BRect		PrintableRect();
		void		GetResolution(int32 *xdpi, int32 *ydpi);

		int32		FirstPage();	/* const */
		int32		LastPage();		/* const */

/*----- Private or reserved -----------------------------------------*/
private:

virtual void		_ReservedPrintJob1();
virtual void		_ReservedPrintJob2();
virtual void		_ReservedPrintJob3();
virtual void		_ReservedPrintJob4();

					BPrintJob(const BPrintJob &);
		BPrintJob	&operator=(const BPrintJob &);

		void				RecurseView(BView *v, BPoint origin, BPicture *p, BRect r, int32 stage);
		void				MangleName(char *filename);
		void				HandlePageSetup(BMessage *setup);
		bool				HandlePrintSetup(BMessage *setup);
		void				CreateSpoolDir(const char *printer_name);

		void				NewPage();
		void				EndLastPage();

		void				AddSetupSpec();
		void				AddPicture(BPicture *picture, BRect *rect, BPoint where);

		char*				GetCurrentPrinterName();
		void				LoadDefaultSettings();

		char *				print_job_name;
		int32				page_number;
		BFile *				spoolFile;
		print_file_header	current_header;
		BRect				paper_size;
		BRect				usable_size;
		int					pr_error;
		char				spool_file_name[256];	
		BMessage			*setup_msg;
		BMessage			*default_setup_msg;
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
