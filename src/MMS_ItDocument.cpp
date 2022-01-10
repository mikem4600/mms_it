/*
* ============================================================================
*  Name     : CMMS_ItDocument from MMS_ItDocument.h
*  Part of  : MMS_It
*  Created  : 29/9/2003 by Makidis Michael
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

// INCLUDE FILES
#include "MMS_ItDocument.h"
#include "MMS_ItAppUi.h"
#include <MMS_IT.RSG>  // for loading resources

#include <coeutils.h> // for file exists
#include <stringloader.h>  // for StringLoader
#include <utf.h> // for the UTF converter

// ================= MEMBER FUNCTIONS =======================

// constructor
CMMS_ItDocument::CMMS_ItDocument(CEikApplication& aApp)
: CAknDocument(aApp), iTextArray(NULL), iSize(0)
    {
	iSmilSet = EFalse;
	iSubjectSet = EFalse;
    }

// destructor
CMMS_ItDocument::~CMMS_ItDocument()
    {
	delete iTextArray;
	delete iAttachments;
    }

// EPOC default constructor can leave.
void CMMS_ItDocument::ConstructL()
    {
	iTextArray = new(ELeave) CDesCArraySeg(5);
	iTextArray->Reset();
	iAttachments = new(ELeave) CArrayFixFlat<TMMS_ItAttachment>(3);
    }

// Two-phased constructor.
CMMS_ItDocument* CMMS_ItDocument::NewL(
        CEikApplication& aApp)     // CMMS_ItApp reference
    {
    CMMS_ItDocument* self = new (ELeave) CMMS_ItDocument( aApp );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }
    
// ----------------------------------------------------
// CMMS_ItDocument::CreateAppUiL()
// constructs CMMS_ItAppUi
// ----------------------------------------------------
//
CEikAppUi* CMMS_ItDocument::CreateAppUiL()
    {
    return new (ELeave) CMMS_ItAppUi(this);
    }

TBool CMMS_ItDocument::FileExists(TFileName aFilename)
{
	return ConeUtils::FileExists(aFilename);
}

TInt CMMS_ItDocument::GetFileSizeL(TFileName aFilename)
{
	RFs fsSession;
	TInt size;

	User::LeaveIfError(fsSession.Connect());  // open session with file server
	RFile file;
	file.Open(fsSession, aFilename, EFileRead | EFileShareReadersOnly);

	TInt res = file.Size(size);

	file.Close();
	fsSession.Close(); // close session with file server

	if(res < 0) return 0;
	return size;
}

TBool CMMS_ItDocument::AddAttachmentL(TFileName aFilename)
{
	if(!FileExists(aFilename)) return EFalse;

	TMMS_ItAttachment attachment;
	TBuf<200> text;

	attachment.iFilename = aFilename;
	TParse p;
	p.Set(attachment.iFilename, NULL, NULL);
	if(p.ExtPresent())
	{
		text.AppendNum(GuessTypeFromExtL(p.Ext()));
		text.Append(_L("\t"));
	}
	else
	{
		text.Append(_L("0\t"));
	}
	text.Append(p.NameAndExt());
	text.Append(_L("\t"));

	// get the file size
	attachment.iSize = GetFileSizeL(attachment.iFilename);
	iSize += attachment.iSize;
	text.AppendNum(attachment.iSize);
	text.Append(_L(" B, "));

	HBufC* textResource = StringLoader::LoadLC(R_DEFAULT_MIME_TYPE);
	text.Append(*textResource);
	CleanupStack::PopAndDestroy(textResource);

	text.Append(_L("\t"));
	iTextArray->AppendL(text);

	// append the attachment
	iAttachments->AppendL(attachment);

	return ETrue;
}

TBool CMMS_ItDocument::RemoveAttachment(TInt aIndex)
{
	// check whether there are no attachments
	if(iAttachments->Count() == 0)
	{
		return EFalse;
	}

	// Set the size
	if(iTextArray->Count() == 1) // Deleting the only attachment
	{
		this->iSize = 0;
	}
	else
	{
		this->iSize -= iAttachments->At(aIndex).iSize;
	}

	// Actually delete the attachment (not the attached file!)
	iAttachments->Delete(aIndex);
	iTextArray->Delete(aIndex);

	iAttachments->Compress();
	iTextArray->Compress();

	return ETrue;
}

void CMMS_ItDocument::ResetAttachments()
{
	this->iSize = 0;

	iAttachments->Reset();
	iTextArray->Reset();

	iAttachments->Compress();
	iTextArray->Compress();
}

TMMS_ItAttachment* CMMS_ItDocument::GetAttachment(TInt aIndex)
{
	return &(iAttachments->At(aIndex));
}

TInt CMMS_ItDocument::CountAttachments()
{
	return iAttachments->Count();
}

TInt CMMS_ItDocument::GetAttachmentsSize()
{
	return iSize;
}

CDesCArray* CMMS_ItDocument::GetTextArrayForListbox()
{
	return iTextArray;
}

TInt CMMS_ItDocument::GuessTypeFromExtL(TPtrC aExt)
{
	TBuf<10> e = aExt.Left(10);
	e.LowerCase();
	if(e == _L(".wav") || e == _L(".mid") || e == _L(".midi") || e == _L(".spmidi") || e == _L(".spmid") || e == _L(".rmi") || e == _L(".mp3")  || e == _L(".ra") || e == _L(".wma") || e == _L(".ogg") || e == _L(".aac") || e == _L(".amr"))
		return 1;
	if(e == _L(".3gp") || e == _L(".3gpp") || e == _L(".rv") || e == _L(".rmvb") || e == _L(".rm") || e == _L(".wmv") || e == _L(".avi") || e == _L(".asf") || e == _L(".asx") || e == _L(".mpg") || e == _L(".mpeg") || e == _L(".mov") || e == _L(".qt") || e == _L(".3g2") || e == _L(".mp4"))
		return 2;
	if(e == _L(".sis") || e == _L(".jar"))
		return 3;
	if(e == _L(".gif") || e == _L(".jpg") || e == _L(".jpeg") || e == _L(".png") || e == _L(".bmp"))
		return 4;
	return 0;
}

void CMMS_ItDocument::SetMimeTypeL(TInt aIndex, TDes8& aMimeType)
{
	// Update the attachment
	iAttachments->At(aIndex).iMIMETypeSet = ETrue;
	iAttachments->At(aIndex).iMIMEType = aMimeType;

	TBuf<200> text;

	TParse p;
	p.Set(iAttachments->At(aIndex).iFilename, NULL, NULL);
	if(p.ExtPresent())
	{
		text.AppendNum(GuessTypeFromExtL(p.Ext()));
		text.Append(_L("\t"));
	}
	else
	{
		text.Append(_L("0\t"));
	}
	text.Append(p.NameAndExt());
	text.Append(_L("\t"));

	TBuf<40> MIMEType;
	CnvUtfConverter::ConvertToUnicodeFromUtf8(MIMEType, aMimeType);

	// get the file size
	text.AppendNum(iAttachments->At(aIndex).iSize);
	text.Append(_L(" B, "));
	text.Append(MIMEType);
	text.Append(_L("\t5"));

	iTextArray->Delete(aIndex);
	iTextArray->InsertL(aIndex, text);
}

void CMMS_ItDocument::ResetMimeTypeL(TInt aIndex)
{
	// Update the attachment
	iAttachments->At(aIndex).iMIMETypeSet = EFalse;

	TBuf<200> text;

	TParse p;
	p.Set(iAttachments->At(aIndex).iFilename, NULL, NULL);
	if(p.ExtPresent())
	{
		text.AppendNum(GuessTypeFromExtL(p.Ext()));
		text.Append(_L("\t"));
	}
	else
	{
		text.Append(_L("0\t"));
	}
	text.Append(p.NameAndExt());
	text.Append(_L("\t"));

	// get the file size
	text.AppendNum(iAttachments->At(aIndex).iSize);
	text.Append(_L(" B, "));

	HBufC* textResource = StringLoader::LoadLC(R_DEFAULT_MIME_TYPE);
	text.Append(*textResource);
	CleanupStack::PopAndDestroy(textResource);

	text.Append(_L("\t"));

	iTextArray->Delete(aIndex);
	iTextArray->InsertL(aIndex, text);
}

void CMMS_ItDocument::SetSubject(TBuf<50> aSubject)
{
	iSubject = aSubject;
	iSubjectSet = ETrue;
}

TBool CMMS_ItDocument::SetSMILFilename(TFileName aFilename)
{
	if(!FileExists(aFilename)) return EFalse;

	iSmilFilename = aFilename;
	iSmilSet = ETrue;

	return ETrue;
}

// End of File  