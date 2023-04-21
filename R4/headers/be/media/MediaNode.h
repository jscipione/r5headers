/*******************************************************************************
/
/	File:			MediaNode.h
/
/   Description:  BMediaNode is the indirect base class for all Media Kit participants.
/	However, you should use the more specific BBufferConsumer, BBufferProducer
/	and others rather than BMediaNode directly. It's OK to multiply inherit.
/
/	Copyright 1997-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/


#if !defined(_MEDIA_NODE_H)
#define _MEDIA_NODE_H

#include <MediaDefs.h>


class BMediaAddOn;



class media_node {

public:

	media_node();
	~media_node();

	media_node_id node;
	port_id port;
	uint32 kind;

static media_node null;

private:
	uint32 _reserved_[3];
};


struct media_input {
	media_input();
	~media_input();
	media_node node;
	media_source source;
	media_destination destination;
	media_format format;
	char name[B_MEDIA_NAME_LENGTH];
private:
	uint32 _reserved_media_input_[4];
};

struct media_output {
	media_output();
	~media_output();
	media_node node;
	media_source source;
	media_destination destination;
	media_format format;
	char name[B_MEDIA_NAME_LENGTH];
private:
	uint32 _reserved_media_output_[4];
};

struct live_node_info {
	live_node_info();
	~live_node_info();
	media_node node;
	BPoint hint_point;
	char name[B_MEDIA_NAME_LENGTH];
private:
	char reserved[160];
};


class BMediaNode
{
protected:
		/* this has to be on top rather than bottom to force a vtable in mwcc */
virtual	~BMediaNode();	/* should be called through Release() */
public:

		enum run_mode {
			B_OFFLINE = 1,				/* data accurate, no realtime constraint */
			B_DECREASE_PRECISION,		/* when slipping, try to catch up */
			B_INCREASE_LATENCY,			/* when slipping, increase playout delay */
			B_DROP_DATA,				/* when slipping, skip data */
			B_RECORDING					/* you're on the receiving end of recording; buffers are guaranteed to be late */
		};


		BMediaNode * Acquire();	/* return itself */
		BMediaNode * Release();	/* release will decrement refcount, and delete if 0 */

		const char * Name() const;
		media_node_id ID() const;
		uint64 Kinds() const;
		media_node Node() const;
		run_mode RunMode() const;
		BTimeSource * TimeSource() const;

	/* this port is what a media node listens to for commands */
virtual	port_id ControlPort() const = 0;

virtual	BMediaAddOn* AddOn(
				int32 * internal_id) const = 0;	/* Who instantiated you -- or NULL for app class */

	/* These will be sent to anyone watching the MediaRoster. */
	/* The message field "be:node_id" will contain the node ID. */
		enum node_error {
			/* Note that these belong with the notifications in MediaDefs.h! */
			/* They are here to provide compiler type checking in ReportError(). */
			B_NODE_FAILED_START = 'TRI0',
			B_NODE_FAILED_STOP,
			B_NODE_FAILED_SEEK,
			B_NODE_FAILED_SET_RUN_MODE,
			B_NODE_FAILED_TIME_WARP,
			B_NODE_FAILED_PREROLL,
			B_NODE_FAILED_SET_TIME_SOURCE_FOR,
			B_NODE_IN_DISTRESS		/* display this node with a blinking exclamation mark or something */
		};

protected:

		/* Send one of the above codes to anybody who's watching. */
		status_t ReportError(
				node_error what,
				const BMessage * info = NULL);	/* String "message" for instance */

explicit 	BMediaNode(		/* constructor sets refcount to 1 */
				const char * name);

		/* These don't return errors; instead, they use the global error condition reporter. */
		/* A node is required to have a queue of at least one pending command (plus TimeWarp) */
		/* and is recommended to allow for at least one pending command of each type. */
		/* Allowing an arbitrary number of outstanding commands might be nice, but apps */
		/* cannot depend on that happening. */
virtual	void Start(
				bigtime_t performance_time);
virtual	void Stop(
				bigtime_t performance_time,
				bool immediate);
virtual	void Seek(
				bigtime_t media_time,
				bigtime_t performance_time);
virtual	void SetRunMode(
				run_mode mode);
virtual	void TimeWarp(
				bigtime_t at_real_time,
				bigtime_t to_performance_time);
virtual	void Preroll();
virtual	void SetTimeSource(
				BTimeSource * time_source);

		int32 IncrementChangeTag();
		int32 ChangeTag();
		int32 MintChangeTag();
		status_t ApplyChangeTag(
				int32 previously_reserved);

virtual	status_t HandleMessage(
				int32 message,
				const void * data,
				size_t size);
		void HandleBadMessage(		/* call this with messages you and your superclasses don't recognize */
				int32 code,
				const void * buffer,
				size_t size);

		/* Called from derived system classes; you don't need to */
		void AddNodeKind(
				uint64 kind);

private:
	friend class BTimeSource;
	friend class _BTimeSourceP;
		/* Mmmh, stuffing! */
virtual		status_t _Reserved_MediaNode_0(void *);
virtual		status_t _Reserved_MediaNode_1(void *);
virtual		status_t _Reserved_MediaNode_2(void *);
virtual		status_t _Reserved_MediaNode_3(void *);
virtual		status_t _Reserved_MediaNode_4(void *);
virtual		status_t _Reserved_MediaNode_5(void *);
virtual		status_t _Reserved_MediaNode_6(void *);
virtual		status_t _Reserved_MediaNode_7(void *);
virtual		status_t _Reserved_MediaNode_8(void *);
virtual		status_t _Reserved_MediaNode_9(void *);
virtual		status_t _Reserved_MediaNode_10(void *);
virtual		status_t _Reserved_MediaNode_11(void *);
virtual		status_t _Reserved_MediaNode_12(void *);
virtual		status_t _Reserved_MediaNode_13(void *);
virtual		status_t _Reserved_MediaNode_14(void *);
virtual		status_t _Reserved_MediaNode_15(void *);

	friend class _BMediaRosterP;
	friend class BMediaRoster;
	friend class MNodeManager;

		BMediaNode();	/* private unimplemented */
		BMediaNode(
				const BMediaNode & clone);
		BMediaNode & operator=(
				const BMediaNode & clone);

		BMediaNode(		/* constructor sets refcount to 1 */
				const char * name,
				media_node_id id,
				uint32 kinds);

		media_node_id _mNodeID;
		BTimeSource * _mTimeSource;
		int32 _mRefCount;
		char _mName[B_MEDIA_NAME_LENGTH];
		run_mode _mRunMode;
		int32 _mChangeCount;
		int32 _mChangeCountReserved;
		uint64 _mKinds;
		media_node_id _mTimeSourceID;
		bool _mUnregisterWhenDone;
		bool _mReservedBool[3];

		uint32 _reserved_media_node_[14];


		void PStart(
				bigtime_t performance_time);
		void PStop(
				bigtime_t performance_time,
				bool immediate);
		void PSeek(
				bigtime_t media_time,
				bigtime_t performance_time);
		void PSetRunMode(
				run_mode mode);
		void PTimeWarp(
				bigtime_t at_real_time,
				bigtime_t to_performance_time);
		void PPreroll();
		void PSetTimeSource(
				BTimeSource * time_source);
};



#endif /* _MEDIA_NODE_H */

