/*******************************************************************************
/
/	File:			BufferConsumer.h
/
/   Description:  A BBufferConsumer is anything that wants to receive buffers in the Media Kit
/
/	Copyright 1997-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#if !defined(_BUFFER_CONSUMER_H)
#define _BUFFER_CONSUMER_H

#include <MediaDefs.h>
#include <MediaNode.h>

class _buffer_id_cache;

class BBufferConsumer :
	public virtual BMediaNode
{
protected:
		/* this has to be at the top to force a vtable */
virtual	~BBufferConsumer();

public:

		media_type ConsumerType();

		/* for encoding a region into the format needed for clipping requests */
static	status_t RegionToClipData(
				const BRegion * region,
				int32 * format,
				int32 * ioSize,
				void * data);

protected:
explicit	BBufferConsumer(
				media_type consumer_type = B_MEDIA_UNKNOWN_TYPE);

static	status_t SetVideoClippingFor(
				const media_source & output,
				const int16 * shorts,
				int32 short_count,
				const media_video_display_info & display,
				int32 * out_from_change_count);
static	void NotifyLateProducer(
				const media_source & what_source,
				bigtime_t how_much,
				bigtime_t performance_time);
static	status_t RequestFormatChange(
				const media_source & source,
				const media_destination & destination,
				media_format * io_to_format,
				int32 * out_from_change_count);
static	status_t SetOutputEnabled(
				const media_source & source,
				bool enabled, 
				int32 * out_from_change_count);

virtual	status_t HandleMessage(
				int32 message,
				const void * data,
				size_t size);

	/* Someone, probably the producer, is asking you about this format. Give */
	/* your honest opinion, possibly modifying *format. Do not ask upstream */
	/* producer about the format, since he's synchronously waiting for your */
	/* reply. */
virtual	status_t AcceptFormat(
				const media_destination & dest,
				media_format * format) = 0;
virtual	status_t GetNextInput(
				int32 * cookie,
				media_input * out_input) = 0;
virtual	void DisposeInputCookie(
				int32 cookie) = 0;
virtual	void BufferReceived(
				BBuffer * buffer) = 0;
virtual	void ProducerDataStatus(
				const media_destination & for_whom,
				int32 status,
				bigtime_t at_media_time) = 0;
virtual	status_t GetLatencyFor(
				const media_destination & for_whom,
				bigtime_t * out_latency,
				media_node_id * out_timesource) = 0;
virtual	status_t Connected(
				const media_source & producer,	/* here's a good place to request buffer group usage */
				const media_destination & where,
				const media_format & with_format,
				media_input * out_input) = 0;
virtual	void Disconnected(
				const media_source & producer,
				const media_destination & where) = 0;
	/* The notification comes from the upstream producer, so he's already cool with */
	/* the format; you should not ask him about it in here. */
virtual	status_t FormatChanged(
				const media_source & producer,
				const media_destination & consumer, 
				int32 from_change_count,
				const media_format & format) = 0;

private:

		BBufferConsumer();	/* private unimplemented */
		BBufferConsumer(
				const BBufferConsumer & clone);
		BBufferConsumer & operator=(
				const BBufferConsumer & clone);

		/* Mmmh, stuffing! */
virtual		status_t _Reserved_BufferConsumer_0(void *);
virtual		status_t _Reserved_BufferConsumer_1(void *);
virtual		status_t _Reserved_BufferConsumer_2(void *);
virtual		status_t _Reserved_BufferConsumer_3(void *);
virtual		status_t _Reserved_BufferConsumer_4(void *);
virtual		status_t _Reserved_BufferConsumer_5(void *);
virtual		status_t _Reserved_BufferConsumer_6(void *);
virtual		status_t _Reserved_BufferConsumer_7(void *);
virtual		status_t _Reserved_BufferConsumer_8(void *);
virtual		status_t _Reserved_BufferConsumer_9(void *);
virtual		status_t _Reserved_BufferConsumer_10(void *);
virtual		status_t _Reserved_BufferConsumer_11(void *);
virtual		status_t _Reserved_BufferConsumer_12(void *);
virtual		status_t _Reserved_BufferConsumer_13(void *);
virtual		status_t _Reserved_BufferConsumer_14(void *);
virtual		status_t _Reserved_BufferConsumer_15(void *);

	friend class BMediaRoster;

		media_type _m_consumer_type;
		_buffer_id_cache * _mBufferCache;
		uint32 _reserved_buffer_consumer_[15];

};


#endif /* _BUFFER_CONSUMER_H */

