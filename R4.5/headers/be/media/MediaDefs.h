/*******************************************************************************
/
/	File:			MediaDefs.h
/
/   Description:   Basic data types and defines for the Media Kit.
/
/	Copyright 1997-1999, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#if !defined(_MEDIA_DEFS_H)
#define _MEDIA_DEFS_H

#include <BeBuild.h>
#include <SupportDefs.h>
#include <OS.h>

#if defined(__cplusplus)
#include <GraphicsDefs.h>
#include <Looper.h>
#endif


#define B_MEDIA_NAME_LENGTH 64


enum {	/* maybe migrate these into Errors.h */
	B_MEDIA_SYSTEM_FAILURE = (int)B_MEDIA_ERROR_BASE+0x100,	/* 80004100 */
	B_MEDIA_BAD_NODE,
	B_MEDIA_NODE_BUSY,
	B_MEDIA_BAD_FORMAT,
	B_MEDIA_BAD_BUFFER,
	B_MEDIA_TOO_MANY_NODES,
	B_MEDIA_TOO_MANY_BUFFERS,
	B_MEDIA_NODE_ALREADY_EXISTS,
	B_MEDIA_BUFFER_ALREADY_EXISTS,
	B_MEDIA_CANNOT_SEEK,
	B_MEDIA_CANNOT_CHANGE_RUN_MODE,
	B_MEDIA_APP_ALREADY_REGISTERED,
	B_MEDIA_APP_NOT_REGISTERED,
	B_MEDIA_CANNOT_RECLAIM_BUFFERS,
	B_MEDIA_BUFFERS_NOT_RECLAIMED,
	B_MEDIA_TIME_SOURCE_STOPPED,
	B_MEDIA_TIME_SOURCE_BUSY,					/* 80004110 */
	B_MEDIA_BAD_SOURCE,
	B_MEDIA_BAD_DESTINATION,
	B_MEDIA_ALREADY_CONNECTED,
	B_MEDIA_NOT_CONNECTED,
	B_MEDIA_BAD_CLIP_FORMAT,
	B_MEDIA_ADDON_FAILED,
	B_MEDIA_ADDON_DISABLED,
	B_MEDIA_CHANGE_IN_PROGRESS,
	B_MEDIA_STALE_CHANGE_COUNT,
	B_MEDIA_ADDON_RESTRICTED,
	B_MEDIA_NO_HANDLER, 
	B_MEDIA_DUPLICATE_FORMAT,
	B_MEDIA_REALTIME_DISABLED,
	B_MEDIA_REALTIME_UNAVAILABLE
};

/* Notification message 'what's */
enum {
	// Note that BMediaNode::node_error also belongs in here! */
	B_MEDIA_WILDCARD = 'TRWC',		/* used to match any notification in Start/StopWatching */
	B_MEDIA_NODE_CREATED = 'TRIA',	/* "media_node_id" (multiple items) */
	B_MEDIA_NODE_DELETED,			/* "media_node_id" (multiple items) */
	B_MEDIA_CONNECTION_MADE,		/* "output", "input", "format" */
	B_MEDIA_CONNECTION_BROKEN,		/* "source", "destination" */
	B_MEDIA_BUFFER_CREATED,			/* "clone_info" -- handled by BMediaRoster */
	B_MEDIA_BUFFER_DELETED,			/* "media_buffer_id" -- handled by BMediaRoster */
	B_MEDIA_TRANSPORT_STATE,		/* "state", "location", "realtime" */
	B_MEDIA_PARAMETER_CHANGED,		/* N "node", "parameter" */
	B_MEDIA_FORMAT_CHANGED,			/* N "source", "destination", "format" */
	B_MEDIA_WEB_CHANGED,			/* N "node" */
	B_MEDIA_DEFAULT_CHANGED,		/* "default", "node" -- handled by BMediaRoster */
	B_MEDIA_NEW_PARAMETER_VALUE,	/* N "node", "parameter", "when", "value" */
	B_MEDIA_NODE_STOPPED			/* N "node", "when" */
};

enum media_type {
	B_MEDIA_NO_TYPE = -1,
	B_MEDIA_UNKNOWN_TYPE = 0,
	B_MEDIA_RAW_AUDIO = 1,			/* uncompressed raw_audio -- linear relationship bytes <-> samples */
	B_MEDIA_RAW_VIDEO,				/* uncompressed raw_video -- linear relationship bytes <-> pixels */
	B_MEDIA_VBL,					/* raw data from VBL area, 1600/line */
	B_MEDIA_TIMECODE,				/* data format TBD */
	B_MEDIA_MIDI,
	B_MEDIA_TEXT,					/* typically closed captioning */
	B_MEDIA_HTML,
	B_MEDIA_MULTISTREAM,			/* AVI, etc */
	B_MEDIA_PARAMETERS,				/* BControllable change data */
	B_MEDIA_ENCODED_AUDIO,			/* dts, AC3, ... */
	B_MEDIA_ENCODED_VIDEO,			/* Indeo, MPEG, ... */
	B_MEDIA_PRIVATE = 90000,		/* Don't touch! */
	B_MEDIA_FIRST_USER_TYPE = 100000	/* Use something bigger than this for */
										/* experimentation with your own media forms */
};

enum node_kind {
	B_BUFFER_PRODUCER = 0x1,
	B_BUFFER_CONSUMER = 0x2,
	B_TIME_SOURCE = 0x4,
	B_CONTROLLABLE = 0x8,
	B_FILE_INTERFACE = 0x10,
	B_ENTITY_INTERFACE = 0x20,
	/* Set these flags for nodes that are suitable as default entities */
	B_PHYSICAL_INPUT = 0x10000,
	B_PHYSICAL_OUTPUT = 0x20000,
	B_SYSTEM_MIXER = 0x40000
};

enum video_orientation {	/* for orientation, which pixel is first and how do we scan each "line"? */
	B_VIDEO_TOP_LEFT_RIGHT = 1,		/* This is the typical progressive scan format */
	B_VIDEO_BOTTOM_LEFT_RIGHT		/* This is how BMP and TGA might scan */
};


enum media_flags			/* data */
{
	B_MEDIA_FLAGS_VERSION = 1,			/* uint32, bigger for newer */
	B_MEDIA_FLAGS_PRIVATE = 0x40000000	/* private to Be */
};


enum media_producer_status {	/* for producer status */
	B_DATA_NOT_AVAILABLE = 1,
	B_DATA_AVAILABLE = 2,
	B_PRODUCER_STOPPED = 3
};

//	realtime flags
enum media_realtime_flags {
	B_MEDIA_REALTIME_ALLOCATOR = 0x1,
	B_MEDIA_REALTIME_AUDIO = 0x2,
	B_MEDIA_REALTIME_VIDEO = 0x4,
	B_MEDIA_REALTIME_ANYKIND = 0xffff
};

enum media_frame_flags {
	B_MEDIA_KEY_FRAME = 0x1
};


typedef int32 media_node_id;
typedef int32 media_buffer_id;
typedef int32 media_addon_id;


#if defined(__cplusplus)
struct media_destination {
	media_destination(port_id, int32);
	media_destination(const media_destination & clone);
	media_destination & operator=(const media_destination & clone);
	media_destination();
	~media_destination();
	port_id port;	/* can be different from media_node.port */
	int32 id;
static media_destination null;
private:
	uint32 _reserved_media_destination_[2];
};

struct media_source {
	media_source(port_id, int32);
	media_source(const media_source & clone);
	media_source & operator=(const media_source & clone);
	media_source();
	~media_source();
	port_id port;	/* must be the same as media_node.port	for owner */
	int32 id;
static media_source null;
private:
	uint32 _reserved_media_source_[2];
};

_IMPEXP_MEDIA bool operator==(const media_destination & a, const media_destination & b);
_IMPEXP_MEDIA bool operator!=(const media_destination & a, const media_destination & b);
_IMPEXP_MEDIA bool operator<(const media_destination & a, const media_destination & b);
_IMPEXP_MEDIA bool operator==(const media_source & a, const media_source & b);
_IMPEXP_MEDIA bool operator!=(const media_source & a, const media_source & b);
_IMPEXP_MEDIA bool operator<(const media_source & a, const media_source & b);
_IMPEXP_MEDIA bool operator==(const media_node & a, const media_node & b);
_IMPEXP_MEDIA bool operator!=(const media_node & a, const media_node & b);
_IMPEXP_MEDIA bool operator<(const media_node & a, const media_node & b);



/* Buffers are low-level constructs identified by an ID. */
/* Buffers consist of the actual data area, plus a 64-byte */
/* header area that is different for each type. */
/* Buffers contain typed data. Type is not part of the */
/* buffer header; it's negotiated out-of-bounds by nodes. */

enum {
	B_MEDIA_BIG_ENDIAN = 1,
	B_MEDIA_LITTLE_ENDIAN = 2
};

struct media_raw_audio_format {
	enum {						// for "format"
		B_AUDIO_UCHAR = 0x11,	// 128 == mid, 1 == bottom, 255 == top
		B_AUDIO_SHORT = 0x2,	// 0 == mid, -32767 == bottom, +32767 == top
		B_AUDIO_FLOAT = 0x24,	// 0 == mid, -1.0 == bottom, 1.0 == top
		B_AUDIO_INT = 0x4		// 0 == mid, 0x80000001 == bottom, 0x7fffffff == top
	};

	float		frame_rate;
	uint32		channel_count;		// 1 or 2, mostly
	uint32		format;				// for compressed formats, go to media_encoded_audio_format
	uint32		byte_order;			// 2 for little endian, 1 for big endian 
	size_t		buffer_size;		// size of each buffer

static media_raw_audio_format wildcard;
};

struct media_audio_header {
	// please put actual data at the end
	int32		_reserved_[16];		// gotta have something
};

struct media_encoded_audio_format {
	enum audio_encoding {
		B_ANY
	};
	media_raw_audio_format	output;
	audio_encoding			encoding;

	float					bit_rate;		// BIT rate, not byte rate
	size_t					frame_size;

static media_encoded_audio_format wildcard;
};

struct media_encoded_audio_header {
	// please put actual data at the end 
	int32		_reserved_0[14];	// gotta have something
	uint32		buffer_flags;		// B_MEDIA_KEY_FRAME for key buffers (ADPCM etc)
	uchar		unused_mask;		// mask of unused bits for the last byte of data
	uchar		_reserved_2[3];

};

struct media_video_display_info {
	color_space	format;
	uint32		line_width;
	uint32		line_count;		// total of all interlace fields 
	uint32		bytes_per_row;	// bytes_per_row is in format, not header, because it's part of SetBuffers
	uint32		pixel_offset;	// ... in BYTES. These are offsets from the start of the buffer ... 
	uint32		line_offset;	// ... to the start of the field. Think "buffer == framebuffer" ... 
								// ... when the window displaying the active field moves on screen. 
	uint32		_reserved_[4];
static media_video_display_info wildcard;
};

struct media_raw_video_format {
	float		field_rate;
	uint32		interlace;		// how many fields per frame -- 1 means progressive (non-interlaced)
	uint32		first_active;	// 0, typically, but could be 10 or 11 for full-NTSC formats
	uint32		last_active;	// line_count-1, typically
	uint32		orientation;	// B_VIDEO_TOP_LEFT_RIGHT is preferred
	// PIXEL aspect ratio; not active area aspect ratio...
	uint16		pixel_width_aspect;		// 1:1 has 1 here
	uint16		pixel_height_aspect;	// 4:3 has 3 here

	media_video_display_info	display;

static media_raw_video_format wildcard;
};

struct media_video_header {
	uint32		_reserved_[11];		// at the top to push used data to the end
	float		field_gamma;
	uint32		field_sequence;		// sequence since start of capture -- may roll over if machine is on for a LONG time
	uint16		field_number;		// 0 .. {interlace-1}; F1 == 0, F2 == 1
	uint16		pulldown_number;	// 0..2 for pulldown duplicated sequence
	uint32		first_active_line;	// among the lines in this interlaced field
	uint32		line_count;			// number of active lines in buffer

};

struct media_encoded_video_format {
	enum video_encoding {
		B_ANY
	};
	media_raw_video_format	output;				// set unknowns to wildcard
	float					avg_bit_rate;
	float					max_bit_rate;
	video_encoding			encoding;
	size_t					frame_size;
	int16					forward_history;	//	maximum forward memory required by algorithm
	int16					backward_history;	//	maximum backward memory required by algorithm

static media_encoded_video_format wildcard;
};

struct media_encoded_video_header {
	/* please put actual data at the end */
	int32		_reserved_1[9];		// gotta have something... 

	uint32		field_flags;		//	B_MEDIA_KEY_FRAME

	int16		forward_history;	// forward memory required by this buffer (0 for key frames)
	int16		backward_history;	// backward memory required by this buffer (0 for key frames)
	uchar		unused_mask;		// mask of unused bits for the last byte of data
	uchar		_reserved_2[3];
	float		field_gamma;
	uint32		field_sequence;		// sequence since start of capture
	uint16		field_number;		// 0 .. {interlace-1};  F1 == 0, F2 == 1
	uint16		_reserved_3;
	uint16		first_active_line;	// 0 or 1, typically, but could be 10 or 11 for full-NTSC formats
	uint16		line_count;			// number of actual lines in buffer
};

struct media_multistream_format {
	enum {
		B_ANY = 0,
		B_VID = 1,					// raw raw_video/raw_audio buffers
		B_AVI,
		B_MPEG1,
		B_MPEG2,
		B_QUICKTIME,
		B_PRIVATE = 90000,
		B_FIRST_USER_TYPE = 100000	// user formats >= 100000
	};
	float		avg_bit_rate;		// 8 * byte rate, on average
	float		max_bit_rate;		// 8 * byte rate, tops
	uint32		avg_chunk_size;		// == max_chunk_size for fixed-size chunks
	uint32		max_chunk_size;		// max buffer size
	enum {
		B_HEADER_HAS_FLAGS = 0x1,	// are flags important?
		B_CLEAN_BUFFERS = 0x2,		// each buffer represents an integral number of "frames"
		B_HOMOGENOUS_BUFFERS = 0x4	// a buffer has only one format in it
	};
	uint32		flags;
	int32		format;
	uint32		_reserved_[2];

	struct vid_info {
		float frame_rate;
		uint16 width;
		uint16 height;
		color_space space;

		float sampling_rate;
		uint32 sample_format;
		uint16 byte_order;
		uint16 channel_count;
	};
	struct avi_info {
		uint32 us_per_frame;
		uint16 width;
		uint16 height;
		uint16 _reserved_;
		uint16 type_count;
		media_type types[5];
	};

	union {
		vid_info	vid;
		avi_info	avi;
	}			u;

static media_multistream_format wildcard;
};

struct media_multistream_header {
	uint32 _reserved_[14];
	uchar	unused_mask;			// mask of unused bits for the last byte of data
	uchar	_reserved_2[3];
	enum {
		B_MASTER_HEADER = 0x1,		// for master stream header data in buffer
		B_SUBSTREAM_HEADER = 0x2,	// for sub-stream header data in buffer
		B_COMPLETE_BUFFER = 0x4		// data is an integral number of "frames"
	};
	uint32 	flags;
};

const type_code B_CODEC_TYPE_INFO = 0x040807b2;

/* typically, a field of 0 means "anything" or "wildcard" */
struct media_format {	/* no more than 192 bytes */
	media_type						type;
	type_code						user_data_type;
	uchar							user_data[64];

	private:

	void *							meta_data;
	int32							meta_data_size;
	area_id							meta_data_area;
	area_id							use_area;
	team_id							team;
	void *							thisPtr;

	public:

	union {
		media_raw_audio_format		raw_audio;
		media_raw_video_format		raw_video;
		media_multistream_format	multistream;
		media_encoded_audio_format	encoded_audio;
		media_encoded_video_format	encoded_video;
		char						_reserved_[96];	 // pad to 96 bytes
	} u;
	
	bool 			IsVideo()		{ return (type==B_MEDIA_ENCODED_VIDEO)|(type==B_MEDIA_RAW_VIDEO); };
	uint32 & 		Width()			{ return (type==B_MEDIA_ENCODED_VIDEO)?u.encoded_video.output.display.line_width:u.raw_video.display.line_width; };
	uint32 & 		Height()		{ return (type==B_MEDIA_ENCODED_VIDEO)?u.encoded_video.output.display.line_count:u.raw_video.display.line_count; };
	color_space & 	ColorSpace()	{ return (type==B_MEDIA_ENCODED_VIDEO)?u.encoded_video.output.display.format:u.raw_video.display.format; };

	bool 			IsAudio()		{ return (type==B_MEDIA_ENCODED_AUDIO)|(type==B_MEDIA_RAW_AUDIO); };
	uint32 & 		AudioFormat()	{ return (type==B_MEDIA_ENCODED_AUDIO)?u.encoded_audio.output.format:u.raw_audio.format; };

	bool			Matches(media_format *otherFormat);
	void			SpecializeTo(media_format *otherFormat);

	void			SetMetaData(void *data, int32 size);
	void *			MetaData() const;
	int32			MetaDataSize() const;

					media_format();
					media_format(const media_format &other);
					~media_format();
	media_format &	operator=(const media_format & clone);
};

/* return true if a and b are compatible (accounting for wildcards) */
_IMPEXP_MEDIA bool format_is_compatible(const media_format & a, const media_format & b);	/* a is the format you want to feed to something accepting b */
_IMPEXP_MEDIA bool string_for_format(const media_format & f, char * buf, size_t size);

struct media_seek_tag {
	char data[16];
};

struct media_header {		// Broadcast() fills in fields marked with "//+"
	media_type		type;			// what kind of data (for union)
	media_buffer_id buffer;			//+ what buffer does this header go with? 
	int32			destination;	//+ what 'socket' is this intended for?
	media_node_id	time_source;	// node that encoded start_time
	uint32			_deprecated_;	// used to be change_tag
	uint32			size_used;		// size within buffer that is used
	bigtime_t		start_time;		// performance time
	area_id			owner;			//+ buffer owner info area
	enum {
		B_SEEK_TAG = 'TRST'			// user data type of the codec seek
									// protocol. size of seek tag is 16 bytes
	};
	type_code		user_data_type;
	uchar			user_data[64];	// user_data_type indicates what this is
	uint32			_reserved_[2];

	off_t			file_pos;		// where in a file this data came from
	size_t			orig_size;		// and how big it was.  if unused, zero out

	uint32			data_offset;	// offset within buffer (already reflected in Data())

	union {
		media_audio_header			raw_audio;
		media_video_header			raw_video;
		media_multistream_header	multistream;
		media_encoded_audio_header	encoded_audio;
		media_encoded_video_header	encoded_video;
		char						_reserved_[64];		// pad to 64 bytes
	} u;
};


struct media_file_format_id {
	ino_t	node;
	dev_t	device;
	uint32	internal_id;
};
_IMPEXP_MEDIA bool operator==(const media_file_format_id & a, const media_file_format_id & b);
_IMPEXP_MEDIA bool operator<(const media_file_format_id & a, const media_file_format_id & b);

typedef enum {
	B_ANY_FORMAT_FAMILY = 0,
	B_BEOS_FORMAT_FAMILY = 1,
	B_QUICKTIME_FORMAT_FAMILY = 2,	/* QuickTime is a registered trademark of Apple Computer */
	B_AVI_FORMAT_FAMILY = 3,
	B_ASF_FORMAT_FAMILY = 4,
	B_MPEG_FORMAT_FAMILY = 5,
	B_WAV_FORMAT_FAMILY = 6,
	B_AIFF_FORMAT_FAMILY = 7,
	
	B_MISC_FORMAT_FAMILY = 99999
} media_format_family;

struct media_file_format {
		enum {	/* flags */
			B_READABLE = 0x1,
			B_WRITABLE = 0x2,
			B_PERFECTLY_SEEKABLE = 0x4,
			B_IMPERFECTLY_SEEKABLE = 0x8,
			B_KNOWS_RAW_VIDEO = 0x10,
			B_KNOWS_RAW_AUDIO = 0x20,
			B_KNOWS_MIDI = 0x40,
			B_KNOWS_ENCODED_VIDEO = 0x80,
			B_KNOWS_ENCODED_AUDIO = 0x100,
			B_KNOWS_OTHER = 0x1000000,	/* clipping, text, control, ... */
			B_KNOWS_ANYTHING = 0x2000000
		};
	uint32	capabilities;			// can this format support audio, video, etc
	media_file_format_id	id;		// opaque id used to construct a BMediaFile
	media_format_family family;		// one of the family enums
	int32	version;				// 100 for 1.0

	uint32		_reserved_[25];

	char	mime_type[64];			// eg: "video/quicktime", "audio/aiff", etc
	char	pretty_name[64];		// eg: "QuickTime File Format"
	char	short_name[32];			// eg: "quicktime", "avi", "mpeg"
	char	file_extension[8];		// eg: "mov", "avi", "mpg"
	char	reserved[88];
};


//
// Use this function iterate through available file format writers
//
status_t get_next_file_format(int32 *cookie, media_file_format *mfi);



/* This struct is guaranteed to be large enough for any message your service */
/* thread will get for any media_node -- 16k is an upper-bound size limit. */
/* In your thread, read_port() into this struct, and call HandleMessage() on it. */
const size_t B_MEDIA_MESSAGE_SIZE = 16384;

_IMPEXP_MEDIA extern const char * B_MEDIA_SERVER_SIGNATURE;

class media_node;	/* found in MediaNode.h */
struct media_input;
struct media_output;
struct live_node_info;
struct dormant_node_info;
struct buffer_clone_info;


//	If you for some reason need to get rid of the media_server (and friends)
//	use these functions, rather than sending messages yourself.
//	The callback will be called for various stages of the process, with 100 meaning completely done
//	The callback should always return TRUE for the time being.
status_t shutdown_media_server(bigtime_t timeout = B_INFINITE_TIMEOUT, bool (*progress)(int stage, const char * message, void * cookie) = NULL, void * cookie = NULL);
status_t launch_media_server(uint32 flags = 0);

//	Given an image_id, prepare that image_id for realtime media
//	If the kind of media indicated by "flags" is not enabled for real-time,
//	B_MEDIA_REALTIME_DISABLED is returned.
//	If there are not enough system resources to enable real-time performance,
//	B_MEDIA_REALTIME_UNAVAILABLE is returned.
status_t media_realtime_init_image(image_id image, uint32 flags);

//	Given a thread ID, and an optional indication of what the thread is
//	doing in "flags", prepare the thread for real-time media performance.
//	Currently, this means locking the thread stack, up to size_used bytes,
//	or all of it if 0 is passed. Typically, you will not be using all
//	256 kB of the stack, so you should pass some smaller value you determine
//	from profiling the thread; typically in the 32-64kB range.
//	Return values are the same as for media_prepare_realtime_image().
status_t media_realtime_init_thread(thread_id thread, size_t stack_used, uint32 flags);

//	A teeny bit of legacy preserved for BSoundFile from R3.
//	These came from the old MediaDefs.h; don't use them
//	unless you get them from BSoundFile.

/* values for byte_ordering */
enum { B_BIG_ENDIAN, B_LITTLE_ENDIAN };

/* values for sample_format */
enum { 
  B_UNDEFINED_SAMPLES,
  B_LINEAR_SAMPLES,
  B_FLOAT_SAMPLES,
  B_MULAW_SAMPLES
  };


#endif	//	__cplusplus

#endif /* MEDIA_DEFS_H */
