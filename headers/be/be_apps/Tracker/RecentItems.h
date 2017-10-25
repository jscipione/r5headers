/*******************************************************************************
/
/	File:			RecentItems.h
/
/   Description:    Defines constants for setting Tracker background images
/
/	Copyright 1998-1999, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#ifndef __RECENT_ITEMS_LIST__
#define __RECENT_ITEMS_LIST__

#include <Entry.h>
#include <Message.h>
#include <String.h>

/* BRecentItemsList classes allow creating an entire menu with
 * recent files, folders, apps. If the user wishes to add items to
 * their own menu, they can instead use the GetNextMenuItem call to
 * get one menu at a time to add it to their app.
 */

class BMenuItem;
class BMenu;

class BRecentItemsList {
public:
	BRecentItemsList(int32 maxItems, bool navMenuFolders);
		/* if <navMenuFolders> passed, folder items get NavMenu-style
		 * subdirectories attached to them
		 */

	virtual ~BRecentItemsList() {}
	
	virtual void Rewind();
		/* resets the iteration */
	
	virtual BMenuItem *GetNextMenuItem(const BMessage *fileOpenMessage = NULL,
		const BMessage *containerOpenMessage = NULL,
		BHandler *target = NULL, entry_ref *currentItemRef = 0);
		/* if <fileOpenMessage> specified, the item for a file gets a copy with
		 * the item ref attached as "refs", otherwise a default B_REFS_RECEIVED
		 * message message gets attached
		 * if <containerOpenMessage> specified, the item for a folder, volume or query
		 * gets a copy with the item ref attached as "refs", otherwise a default
		 * B_REFS_RECEIVED message message gets attached
		 * if <currentItemRef> gets passed, the caller gets to look at the
		 * entry_ref corresponding to the item
		 */

	virtual status_t GetNextRef(entry_ref *);

protected:
	BMessage items;
	int32 index;
	int32 maxItems;
	bool navMenuFolders;

private:

	virtual	void _r1();
	virtual	void _r2();
	virtual	void _r3();
	virtual	void _r4();
	virtual	void _r5();
	virtual	void _r6();
	virtual	void _r7();
	virtual	void _r8();
	virtual	void _r9();
	virtual	void _r10();

	uint32 _reserved[20];
};

class BRecentFilesList : public BRecentItemsList {
public:

	/* use one of the two constructors to set up next item iteration */
	BRecentFilesList(int32 maxItems = 10, bool navMenuFolders = false,
		const char *ofType = NULL, const char *openedByAppSig = NULL);
	BRecentFilesList(int32 maxItems, bool navMenuFolders, const char *ofTypeList[],
		int32 ofTypeListCount, const char *openedByAppSig = NULL);	
	virtual ~BRecentFilesList();

	/* use one of the two NewFileListMenu calls to get an entire menu */
	static BMenu *NewFileListMenu(const char *title,
		BMessage *openFileMessage = NULL, BMessage *openFolderMessage = NULL,
		BHandler *target = NULL,
		int32 maxItems = 10, bool navMenuFolders = false,
		const char *ofType = NULL, const char *openedByAppSig = NULL);

	static BMenu *NewFileListMenu(const char *title,
		BMessage *openFileMessage, BMessage *openFolderMessage,
		BHandler *target,
		int32 maxItems, bool navMenuFolders,
		const char *ofTypeList[], int32 ofTypeListCount,
		const char *openedByAppSig);

	virtual status_t GetNextRef(entry_ref *);

protected:
	
	BString type;
	char **types;
	int32 typeCount;
	BString appSig;

private:
	virtual	void _r11();
	virtual	void _r12();
	virtual	void _r13();
	virtual	void _r14();
	virtual	void _r15();
	virtual	void _r16();
	virtual	void _r17();
	virtual	void _r18();
	virtual	void _r19();
	virtual	void _r110();

	uint32 _reserved[20];	
};

class BRecentFoldersList : public BRecentItemsList {
public:
	/* use the constructor to set up next item iteration */
	BRecentFoldersList(int32 maxItems, bool navMenuFolders = false,
		const char *openedByAppSig = NULL);

	/* use NewFolderListMenu to get an entire menu */
	static BMenu *NewFolderListMenu(const char *title,
		BMessage *openMessage = NULL, BHandler *target = NULL,
		int32 maxItems = 10, bool navMenuFolders = false,
		const char *openedByAppSig = NULL);

	virtual status_t GetNextRef(entry_ref *);

protected:	
	BString appSig;

private:
	virtual	void _r21();
	virtual	void _r22();
	virtual	void _r23();
	virtual	void _r24();
	virtual	void _r25();
	virtual	void _r26();
	virtual	void _r27();
	virtual	void _r28();
	virtual	void _r29();
	virtual	void _r210();

	uint32 _reserved[20];
};

class BRecentAppsList : public BRecentItemsList {
public:
	/* use the constructor to set up next item iteration */
	BRecentAppsList(int32 maxItems);

	/* use NewFolderListMenu to get an entire menu */
	static BMenu *NewAppListMenu(const char *title,
		BMessage *openMessage = NULL, BHandler *target = NULL,
		int32 maxItems = 10);

	virtual status_t GetNextRef(entry_ref *);

private:
	virtual	void _r31();
	virtual	void _r32();
	virtual	void _r33();
	virtual	void _r34();
	virtual	void _r35();
	virtual	void _r36();
	virtual	void _r37();
	virtual	void _r38();
	virtual	void _r39();
	virtual	void _r310();

	uint32 _reserved[20];
};

#endif
