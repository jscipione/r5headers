/********************************************************************************
/
/      File:           Translator.h
/
/      Description:    This header file defines a superclass for translator
/                      objects which you can create within your application and 
/                      then add to a TranslatorRoster.
/
/      Copyright 1998-1999, Be Incorporated, All Rights Reserved.
/      Copyright 1995-1997, Jon Watte
/
********************************************************************************/

#ifndef _TRANSLATOR_H
#define _TRANSLATOR_H

#include <TranslationDefs.h>
#include <Archivable.h>

class BTranslator : public BArchivable {
public:
		BTranslator();	/* sets refcount to 1 */

		BTranslator * Acquire();	/* return actual object */
		BTranslator * Release();	/* return NULL if deleted by release */
		int32 ReferenceCount();		/* not thread safe; for debugging only! */

		virtual const char * TranslatorName() const = 0;
		virtual const char * TranslatorInfo() const = 0;
		virtual int32 TranslatorVersion() const = 0;
		virtual const translation_format * InputFormats(
				int32 * out_count) const = 0;
		virtual const translation_format * OutputFormats(
				int32 * out_count) const = 0;

		virtual status_t Identify(	/*	required	*/
				BPositionIO * inSource,
				const translation_format * inFormat,	/*	can beNULL	*/
				BMessage * ioExtension,	/*	can be NULL	*/
				translator_info * outInfo,
				uint32 outType) = 0;

		virtual status_t Translate(	/*	required	*/
				BPositionIO * inSource,
				const translator_info * inInfo,
				BMessage * ioExtension,	/*	can be NULL	*/
				uint32 outType,
				BPositionIO * outDestination) = 0;

		virtual status_t MakeConfigurationView(	/*	optional	*/
				BMessage * ioExtension,	/*	can be NULL	*/
				BView * * outView,
				BRect * outExtent);

		virtual status_t GetConfigurationMessage(	/*	optional	*/
				BMessage * ioExtension);

protected:

		virtual ~BTranslator();	/* because it's ref counted */

private:

		virtual status_t _Reserved_Translator_0(int32, void *);
		virtual status_t _Reserved_Translator_1(int32, void *);
		virtual status_t _Reserved_Translator_2(int32, void *);
		virtual status_t _Reserved_Translator_3(int32, void *);
		virtual status_t _Reserved_Translator_4(int32, void *);
		virtual status_t _Reserved_Translator_5(int32, void *);
		virtual status_t _Reserved_Translator_6(int32, void *);
		virtual status_t _Reserved_Translator_7(int32, void *);

		int32 _mRefCount;

		uint32 _reserved_translator_[9];

};


#endif /* _TRANSLATOR_H */
