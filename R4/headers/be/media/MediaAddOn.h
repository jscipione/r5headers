/*******************************************************************************
/
/	File:			MediaAddOn.h
/
/   Description:   A BMediaAddOn is created by Media Kit add-ons to instantiate and 
/	handle "latent" Nodes.
/
/	Copyright 1997-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#if !defined(_MEDIA_ADD_ON_H)
#define _MEDIA_ADD_ON_H

#include <image.h>

#include <MediaDefs.h>


struct dormant_node_info {
	dormant_node_info();
	~dormant_node_info();
	media_addon_id addon;
	int32 flavor_id;
	char name[B_MEDIA_NAME_LENGTH];
private:
	char reserved[128];
};



struct flavor_info {
	char *				name;
	char *				info;
	uint64				kinds;			/* node_kind */
	uint32				flavor_flags;
	int32				internal_id;	/* For BMediaAddOn internal use */
	int32				possible_count;	/* 0 for "any number" */

	int32				in_format_count;	/* for BufferConsumer kinds */
	uint32				in_format_flags;	/* set to 0 */
	const media_format *	in_formats;

	int32				out_format_count;	/* for BufferProducer kinds */
	uint32				out_format_flags;	/* set to 0 */
	const media_format *	out_formats;

	uint32				_reserved_[16];

private:
	flavor_info & operator=(const flavor_info & other);
};



/* a MediaAddOn is something which can manufacture MediaNodes */
class BMediaAddOn
{
public:
explicit	BMediaAddOn(
				image_id image);
virtual	~BMediaAddOn();

virtual	status_t InitCheck(
				const char ** out_failure_text) = 0;
virtual	int32 CountFlavors() = 0;
virtual	status_t GetFlavorAt(
				int32 n,
				const flavor_info ** out_info) = 0;
virtual	BMediaNode * InstantiateNodeFor(
				const flavor_info * info,
				BMessage * config,
				status_t * out_error) = 0;
virtual	status_t GetConfigurationFor(
				BMediaNode * your_node,
				BMessage * into_message) = 0;
virtual	bool WantsAutoStart() = 0;
virtual	status_t AutoStart(
				int in_count,
				BMediaNode ** out_node,
				int32 * out_internal_id,
				bool * out_has_more) = 0;
/* only implement if you have a B_FILE_INTERFACE node */
virtual	status_t SniffRef(
				const entry_ref & file,
				BMimeType * io_mime_type,
				float * out_quality,
				int32 * out_internal_id);
virtual	status_t SniffType(
				const BMimeType & type,
				float * out_quality,
				int32 * out_internal_id);

		image_id ImageID();
		media_addon_id AddonID();

private:

	friend class MLatentManager;	// apologies for the no-underscore name

		BMediaAddOn();	/* private unimplemented */
		BMediaAddOn(
				const BMediaAddOn & clone);
		BMediaAddOn & operator=(
				const BMediaAddOn & clone);

		/* Mmmh, stuffing! */
virtual		status_t _Reserved_MediaAddOn_0(void *);
virtual		status_t _Reserved_MediaAddOn_1(void *);
virtual		status_t _Reserved_MediaAddOn_2(void *);
virtual		status_t _Reserved_MediaAddOn_3(void *);
virtual		status_t _Reserved_MediaAddOn_4(void *);
virtual		status_t _Reserved_MediaAddOn_5(void *);
virtual		status_t _Reserved_MediaAddOn_6(void *);
virtual		status_t _Reserved_MediaAddOn_7(void *);

		image_id _m_image;
		media_addon_id _m_addon;
		uint32 _reserved_media_add_on_[7];

};


#if BUILDING_MEDIA_ADDON
extern "C" _EXPORT BMediaAddOn * make_media_addon(image_id you);
#endif


#endif /* _MEDIA_ADD_ON_H */

