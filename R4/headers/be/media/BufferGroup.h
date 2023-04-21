/*******************************************************************************
/
/	File:			BufferGroup.h
/
/   Description:   A BBufferGroup organizes sets of BBuffers so that you can request
/	and reclaim them.
/
/	Copyright 1997-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#if !defined(_BUFFER_GROUP_H)
#define _BUFFER_GROUP_H

#include <MediaDefs.h>


class _area_cluster;
class _buffer_id_cache;

class BBufferGroup
{
public:

		BBufferGroup(
				size_t size,
				int32 count = 3,
				uint32 placement = B_ANY_ADDRESS,
				uint32 lock = B_FULL_LOCK);
explicit	BBufferGroup();
		BBufferGroup(
				int32 count,
				const media_buffer_id * buffers);
		~BBufferGroup();	/* BBufferGroup is NOT a virtual class!!! */

		status_t InitCheck();

			/* use this function to add buffers you created on your own */
		status_t AddBuffer(
				const buffer_clone_info & info,
				BBuffer ** out_buffer = NULL);

		BBuffer * RequestBuffer(
				size_t size,
				bigtime_t timeout = B_INFINITE_TIMEOUT);
		status_t RequestBuffer(
				BBuffer * buffer,
				bigtime_t timeout = B_INFINITE_TIMEOUT);

		status_t ReclaimAllBuffers();

		status_t CountBuffers(
				int32 * out_count);
		status_t GetBufferList(
				int32 buf_count,
				BBuffer ** out_buffers);

		status_t SetRecyclePriority(
				int32 prio);

private:

static	status_t _entry_reclaim(void *);

	friend class _BMediaRosterP;
	friend class BMediaRoster;

		BBufferGroup(const BBufferGroup &);	/* not implemented */
		BBufferGroup& operator=(const BBufferGroup&); /* not implemented */

		status_t _m_init_error;
		int32 _mGroupID;

		_area_cluster * _mCluster;
		port_id _mRecycle;	/* For recycling buffers */
		thread_id _mRecycleThread;

		bool _mCanReclaim;	/* Not really related to _mRecycle and _mRecycleThread */
/*
		media_node_id _mReclaimNode;
		media_source _mReclaimFrom;
*/
		sem_id _mBufferAvailSem;
		int32 _mBufferCount;
		_buffer_id_cache * _mBufferCache;
		uint32 _reserved_buffer_group_[7];

		status_t IBufferGroup();
		void ReclaimThread();
		void MakeAvailable(
				BBuffer * buffer);

		status_t AddBuffersTo(
				BMessage * message,
				const char * name);
		status_t WaitForBuffers();

		void WillReclaim();

};

#endif /* _BUFFER_GROUP_H */

