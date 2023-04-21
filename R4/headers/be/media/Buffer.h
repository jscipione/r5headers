/*******************************************************************************
/
/	File:			Buffer.h
/
/   Description:   A BBuffer is a container of media data in the Media Kit
/
/	Copyright 1997-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#if !defined(_BUFFER_H)
#define _BUFFER_H

#include <MediaDefs.h>


/*** A BBuffer is not the same thing as the area segment that gets cloned ***/
/*** For each buffer that gets created, a BBuffer object is created to represent ***/
/*** it in each participant address space. ***/


struct buffer_clone_info {
	buffer_clone_info();
	~buffer_clone_info();
	media_buffer_id	buffer;
	area_id		area;
	size_t		offset;
	size_t		size;
	int32		flags;
private:
	uint32 _reserved_[4];
};


class BBuffer
{
public:
		void * Data();	/* returns NULL if buffer not correctly initialized */
		size_t Size();
		uint32 Flags();

		void Recycle();
		buffer_clone_info CloneInfo() const;

		media_buffer_id ID();	/* 0 if not registered */
		media_type Type();
		media_header * Header();
		media_audio_header * AudioHeader();
		media_video_header * VideoHeader();

		enum {	/* for flags */
			B_F1_BUFFER = 0x1,
			B_F2_BUFFER = 0x2
		};

private:

		BBuffer(
				area_id area,
				size_t offset,
				size_t size,
				int32 flags = 0);
		~BBuffer();	/* BBuffer is NOT a virtual class!!! */

		BBuffer();
		BBuffer(
				const BBuffer & clone);
		BBuffer & operator=(
				const BBuffer & clone);

	friend class _BMediaRosterP;
	friend class BMediaRoster;
	friend class BBufferConsumer;	/* for buffer receiving */
	friend class BBufferGroup;

		media_header _mHeader;
		area_id _mArea;
		area_id _mOrigArea;
		void * _mData;
		size_t _mOffset;
		size_t _mSize;
		media_buffer_id _mBufferID;
		int32 _mFlags;
		uint32 _reserved_buffer_[8];

explicit	BBuffer(
				const buffer_clone_info & info);

//static	BBuffer * BufferFor(
//				const media_header * header);


};


#endif /* _BUFFER_H */

