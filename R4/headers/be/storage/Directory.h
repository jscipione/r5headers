/***************************************************************************
//
//	File:			Directory.h
//
//	Description:	BDirectory class
//
//	Copyright 1992-98, Be Incorporated, All Rights Reserved.
//
***************************************************************************/


#ifndef _DIRECTORY_H
#define _DIRECTORY_H

#ifndef _BE_BUILD_H
#include <BeBuild.h>
#endif
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>

#include <SupportDefs.h>
#include <Node.h>
#include <EntryList.h>
#include <StorageDefs.h>

class	BEntry;
class	BFile;
class	BSymLink;
struct	entry_ref;

_IMPEXP_BE status_t create_directory(const char *path, mode_t mode);

class BDirectory : public BNode, public BEntryList {
public:
						BDirectory();
						BDirectory(const BEntry *entry);
						BDirectory(const entry_ref *ref);
						BDirectory(const char *path);
						BDirectory(const BDirectory *dir, const char *path);
						BDirectory(const node_ref *ref);
						BDirectory(const BDirectory &dir);

virtual					~BDirectory();

		status_t		SetTo(const entry_ref *ref);
		status_t		SetTo(const BEntry *entry);
		status_t		SetTo(const char *path);
		status_t		SetTo(const BDirectory *dir, const char *path);
		status_t		SetTo(const node_ref *ref);

		status_t		GetEntry(BEntry *entry) const;
		bool			IsRootDirectory() const;

		status_t		FindEntry(const char *path, BEntry *entry,
								  bool traverse = false) const;

		bool			Contains(const char *path, 
								 int32 node_flags = B_ANY_NODE) const;
		bool			Contains(const BEntry *entry,
								 int32 node_flags = B_ANY_NODE) const;

		status_t		GetStatFor(const char *path, struct stat *st) const;

virtual	status_t		GetNextEntry(BEntry *entry, bool traverse = false);
virtual	status_t		GetNextRef(entry_ref *ref);
virtual	int32			GetNextDirents(struct dirent *buf, size_t length,
							int32 count = INT_MAX);
virtual	status_t		Rewind();
virtual	int32			CountEntries();

		status_t		CreateDirectory(const char *path, BDirectory *dir);
		status_t		CreateFile(const char *path, BFile *file, 
								   bool failIfExists = false);
		status_t		CreateSymLink(const char *path, const char *content,
							BSymLink *link);

		BDirectory &	operator=(const BDirectory &dir);

private:

		/* FBC */
virtual	void		_ErectorDirectory1();
virtual	void		_ErectorDirectory2();
virtual	void		_ErectorDirectory3();
virtual	void		_ErectorDirectory4();
virtual	void		_ErectorDirectory5();
virtual	void		_ErectorDirectory6();
		uint32		_erectorData[8];

virtual void			close_fd();
};


#endif
