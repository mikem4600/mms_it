/*
* ============================================================================
*  Name     : CMMS_ItDocument from MMS_ItDocument.h
*  Part of  : MMS_It
*  Created  : 29/9/2003 by Makidis Michael
*  Description:
*     Declares document for application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITDOCUMENT_H
#define MMS_ITDOCUMENT_H

// INCLUDES
#include "MMS_ItAttachment.h"
#include <akndoc.h>

#include <badesca.h>  // for CDesCArray

// CONSTANTS

// FORWARD DECLARATIONS
class  CEikAppUi;

// CLASS DECLARATION

/**
*  CMMS_ItDocument application class.
*/
class CMMS_ItDocument : public CAknDocument
    {
    public: // Constructors and destructor
        /**
        * Two-phased constructor.
        */
        static CMMS_ItDocument* NewL(CEikApplication& aApp);

        /**
        * Destructor.
        */
        virtual ~CMMS_ItDocument();

    public: // New functions

		TBool FileExists(TFileName aFilename);

		TBool AddAttachmentL(TFileName aFilename);

		TBool RemoveAttachment(TInt aIndex);

		void ResetAttachments();

		TInt CountAttachments();

		TMMS_ItAttachment* GetAttachment(TInt aIndex);

		TInt GetAttachmentsSize();

		CDesCArray* GetTextArrayForListbox();

		void SetMimeTypeL(TInt aIndex, TDes8& aMimeType);

		void ResetMimeTypeL(TInt aIndex);

		void SetSubject(TBuf<50> aSubject);

		TBool SetSMILFilename(TFileName aFilename);

		TBool SubjectSet() {return iSubjectSet;}

		TBool SMILAttSet() {return iSmilSet;}

		TFileName GetSMILFilename() {return iSmilFilename;}

		TBuf<50> GetSubject() {return iSubject;}

		void RemoveSMILFilename(){iSmilSet = EFalse;}

		void RemoveSubject(){iSubjectSet = EFalse;}

    protected:  // New functions

    protected:  // Functions from base classes

    private:

        /**
        * EPOC default constructor.
        */
        CMMS_ItDocument(CEikApplication& aApp);

        void ConstructL();

    private:

        /**
        * From CEikDocument, create CMMS_ItAppUi "App UI" object.
        */
        CEikAppUi* CreateAppUiL();

		TInt GuessTypeFromExtL(TPtrC aExt);

		TInt GetFileSizeL(TFileName aFilename);

	private:
		CArrayFixFlat<TMMS_ItAttachment>* iAttachments;  // the attached files
		CDesCArray* iTextArray;  // the attachments listbox view
		TInt iSize;

		TBool iSmilSet;
		TBool iSubjectSet;

		TFileName iSmilFilename;
		TBuf<100> iSubject;

	public:
		TBuf<1024> iMessageText;
    };

#endif

// End of File

