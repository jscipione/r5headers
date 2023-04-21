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

#define GUID_SUPPORT 0


#if GUID_SUPPORT
typedef struct {
	uint8 data[16];
} GUID;
#endif

typedef enum {
	B_ANY_FORMAT_FAMILY = 0,
	B_BEOS_FORMAT_FAMILY = 1,
	B_QUICKTIME_FORMAT_FAMILY = 2,	/* QuickTime is a registered trademark of Apple Computer */
	B_AVI_FORMAT_FAMILY = 3,
	B_ASF_FORMAT_FAMILY = 4
} media_format_family;

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

#if GUID_SUPPORT
typedef struct {
	GUID guid;
} media_asf_description;
#endif

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
#if GUID_SUPPORT
		media_asf_description asf;
#endif
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

#if GUID_SUPPORT
_IMPEXP_MEDIA bool operator==(const GUID & a, const GUID & b);
_IMPEXP_MEDIA bool operator<(const GUID & a, const GUID & b);
_IMPEXP_MEDIA bool operator!=(const GUID & a, const GUID & b);
#endif
#endif

#if GUID_SUPPORT
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

