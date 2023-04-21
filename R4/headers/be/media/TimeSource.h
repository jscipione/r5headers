/*******************************************************************************
/
/	File:			TimeSource.h
/
/   Description:  A BTimeSource is something to which others can slave timing information
/	using the Media Kit.
/
/	Copyright 1997-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#if !defined(_TIME_SOURCE_H)
#define _TIME_SOURCE_H

#include <MediaDefs.h>
#include <MediaNode.h>


class _BSlaveNodeStorageP;
struct _time_transmit_buf;


class BTimeSource :
	public virtual BMediaNode
{
protected:
		/* this has to be at the top to force a vtable */
virtual	~BTimeSource();

public:

virtual	status_t SnoozeUntil(				/* returns error if stopped */
				bigtime_t performance_time,
				bigtime_t with_latency = 0,
				bool retry_signals = false);

		bigtime_t Now();	/* convenience, less accurate */
		bigtime_t PerformanceTimeFor(	/* all three go through GetTime() */
				bigtime_t real_time);
		bigtime_t RealTimeFor(
				bigtime_t performance_time,
				bigtime_t with_latency);
		bool IsRunning();

		status_t GetTime(	/* return B_OK if reading is usable */
				bigtime_t * performance_time,
				bigtime_t * real_time,
				float * drift);

static	bigtime_t RealTime();	/* this produces real time, nothing else is guaranteed to */

		status_t GetStartLatency(
				bigtime_t * out_latency);

protected:

		BTimeSource();

virtual	status_t HandleMessage(
				int32 message,
				const void * data,
				size_t size);

		void PublishTime(	/* call this at convenient times to update approximation */
				bigtime_t performance_time,
				bigtime_t real_time,
				float drift);

		void BroadcastTimeWarp(
				bigtime_t at_real_time,
				bigtime_t new_performance_time);	/* when running */
		void SendRunMode(
				run_mode mode);

virtual	void SetRunMode(
				run_mode mode);		/* or, instead, SendRunMode() */

private:

		BTimeSource(		/* private unimplemented */
				const BTimeSource & clone);
		BTimeSource & operator=(
				const BTimeSource & clone);

		/* Mmmh, stuffing! */
virtual		status_t _Reserved_TimeSource_0(void *);
virtual		status_t _Reserved_TimeSource_1(void *);
virtual		status_t _Reserved_TimeSource_2(void *);
virtual		status_t _Reserved_TimeSource_3(void *);
virtual		status_t _Reserved_TimeSource_4(void *);
virtual		status_t _Reserved_TimeSource_5(void *);

	friend class _BMediaRosterP;
	friend class _BTimeSourceP;
	friend class BMediaNode;
	friend class BMediaRoster;
	friend class _ServerApp; /* what's this? :-) */

		bool _mStopped;

		area_id _mArea;
volatile	_time_transmit_buf * _mBuf;
		_BSlaveNodeStorageP * _mSlaveNodes;

		uint32 _reserved_time_source_[12];

explicit	BTimeSource(
				media_node_id id);
		void FinishCreate(); /* called by roster and/or server */

virtual	status_t RemoveMe(
				BMediaNode * node);
virtual	status_t AddMe(
				BMediaNode * node);

};


#endif /* _TIME_SOURCE_H */

