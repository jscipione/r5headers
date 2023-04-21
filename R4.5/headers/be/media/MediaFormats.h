/*	MediaFormats.h	*/
/*	Copyright 1998 Be Incorporated. All rights reserved.	*/

#if !defined(_MEDIA_TYPES_H)
#define _MEDIA_TYPES_H

#if defined(__cplusplus)
#include <MediaDefs.h>

#include <Messenger.h>
#include <List.h>
#include <Locker.h>
#endif


struct media_codec_info {
	char	pretty_name[96];   // eg: "SuperSqueeze Encoder by Foo Inc"
	char	short_name[32];    // eg: "supersqueeze"
	
	int32	id;                // opaque id passed to BMediaFile::CreateTrack
	
	int32	pad[64];
};

//
// Use this to iterate through the available encoders for a file format.
//
status_t get_next_encoder(int32 *cookie,
						  const media_file_format *mfi,		// this comes from get_next_file_format()
						  const media_format *input_format,	// this is the type of data given to the encoder
						  media_format *output_format,		// this is the type of data encoder will output 
						  media_codec_info *ei);			// information about the encoder
 


typedef struct {
	uint8 data[16];
} GUID;

typedef struct {
	int32 format;
} media_beos_description;

typedef struct {
	uint32 codec;
	uint32 vendor;
} media_quicktime_description;

typedef struct {
	uint32 codec;
} media_avi_description;

typedef struct {
	GUID guid;
} media_asf_description;

enum mpeg_id {
	B_MPEG_ANY = 0,
	B_MPEG_1_AUDIO_LAYER_1 = 0x101,
	B_MPEG_1_AUDIO_LAYER_2 = 0x102,
	B_MPEG_1_AUDIO_LAYER_3 = 0x103,		//	"MP3"
	B_MPEG_1_VIDEO = 0x111
};
typedef struct {
	uint32 id;
} media_mpeg_description;

typedef struct {
	uint32 codec;
} media_wav_description;

typedef struct {
	uint32 codec;
} media_aiff_description;

typedef struct {
	uint32 file_format;
	uint32 codec;
} media_misc_description;

typedef struct _media_format_description {
#if defined(__cplusplus)
	_media_format_description();
	~_media_format_description();
	_media_format_description(const _media_format_description & other);
	_media_format_description & operator=(const _media_format_description & other);
#endif
	media_format_family family;
	uint32 _reserved_[3];
	union {
		media_beos_description beos;
		media_quicktime_description quicktime;
		media_avi_description avi;
		media_asf_description asf;
		media_mpeg_description mpeg;
		media_wav_description wav;
		media_aiff_description aiff;
		media_misc_description misc;
		uint32 _reserved_[12];
	} u;
} media_format_description;

#if defined(__cplusplus)
class BMediaFormats {
public:
		BMediaFormats();
virtual		~BMediaFormats();

		status_t InitCheck();

				/* Make sure you memset() your desc and in_format to 0 before you */
				/* start filling them in! Else you may register some bogus value. */
		status_t MakeFormatFor(
				const media_format_description & desc,
				const media_format & in_format,
				media_format * out_format);
		status_t GetFormatFor(
				const media_format_description & desc,
				media_format * out_format);
		status_t GetCodeFor(
				const media_format & format,
				media_format_family family,
				media_format_description * out_description);

		status_t RewindFormats();
		status_t GetNextFormat(
				media_format * out_format,
				media_format_description * out_description);
		bool Lock();
		void Unlock();

private:
		BMessenger m_server;
		BList m_formats;
		BLocker m_lock;
		int32 m_index;

		void clear_formats();
		status_t get_formats();
};

_IMPEXP_MEDIA bool operator==(const media_format_description & a, const media_format_description & b);
_IMPEXP_MEDIA bool operator<(const media_format_description & a, const media_format_description & b);

_IMPEXP_MEDIA bool operator==(const GUID & a, const GUID & b);
_IMPEXP_MEDIA bool operator<(const GUID & a, const GUID & b);
_IMPEXP_MEDIA bool operator!=(const GUID & a, const GUID & b);
#endif

#if 0
GUID functionality pending
#if defined(__cplusplus)
extern "C" {
#endif
_IMPEXP_MEDIA status_t media_mint_guid(GUID * guid);
_IMPEXP_MEDIA status_t guid_to_string(const GUID * guid, char * string);
_IMPEXP_MEDIA status_t string_to_guid(const char * string, GUID * guid);
#if defined(__cplusplus)
}
#endif
#endif

#endif	/* _MEDIA_TYPES_H */

