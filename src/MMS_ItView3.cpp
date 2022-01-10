/*
* ============================================================================
*  Name     : CMMS_ItView from MMS_ItView.h
*  Part of  : MMS_It
*  Created  : 21/11/2004 by 
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <MMS_It.rsg>
#include  "MMS_ItView3.h"
#include  "MMS_ItContainer3.h"

#include "MMS_ItDocument.h"
#include "MMS_ItAppUi.h"
#include "mms_it.hrh" // for handling commands

#include <stringloader.h>  // for StringLoader

// ================= MEMBER FUNCTIONS =======================

CMMS_ItView3::CMMS_ItView3(CMMS_ItDocument* aDocument, CMMS_ItAppUi* aUI)
:	iDocument(aDocument), iUI(aUI), iContainer(NULL)
{}

// ---------------------------------------------------------
// CMMS_ItView3::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CMMS_ItView3::ConstructL()
    {
    BaseConstructL( R_MMS_IT_VIEW3 );
    }

// ---------------------------------------------------------
// CMMS_ItView3::~CMMS_ItView()
// ?implementation_description
// ---------------------------------------------------------
//
CMMS_ItView3::~CMMS_ItView3()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CMMS_ItView3::Id()
// ?implementation_description
// ---------------------------------------------------------
//
TUid CMMS_ItView3::Id() const
    {
    return KView3Id;
    }

// ---------------------------------------------------------
// CMMS_ItView::HandleCommandL(TInt aCommand)
// ?implementation_description
// ---------------------------------------------------------
//
void CMMS_ItView3::HandleCommandL(TInt aCommand)
    {   
    switch ( aCommand )
        {
		case EAddAttachment:
			{
			iContainer->AddAttachmentL();
			break;
			}
		case EAddAttachmentManually:
			{
			iContainer->AddAttachmentManuallyL();
			break;
			}
		case ERemoveAttachment:
			{
			iContainer->RemoveAttachmentL();
			break;
			}
		case ERemoveAllAttachments:
			{
			iContainer->RemoveAllAttachments();
			break;
			}
		case EEditMime:
			{
			iContainer->EditMimeType();
			break;
			}
		case EMIMEImgGif:
			{
			TBuf8<40> mime = _L8("image/gif");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEImgJpeg:
			{
			TBuf8<40> mime = _L8("image/jpeg");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEImgPng:
			{
			TBuf8<40> mime = _L8("image/png");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEAudMidi:
			{
			TBuf8<40> mime = _L8("audio/midi");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEAudSPMidi:
			{
			TBuf8<40> mime = _L8("audio/sp-midi");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEAudAMR:
			{
			TBuf8<40> mime = _L8("audio/amr");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEAudMpeg:
			{
			TBuf8<40> mime = _L8("audio/mpeg");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEVid3GPP:
			{
			TBuf8<40> mime = _L8("video/3gpp");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case EMIMEVidMpeg:
			{
			TBuf8<40> mime = _L8("video/mpeg");
			iContainer->SetMimeTypeL(mime);
			break;
			}
		case ESetDefaultMime:
			{
			iContainer->ResetMimeTypeL();
			break;
			}
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

// ---------------------------------------------------------
// CMMS_ItView3::HandleClientRectChange()
// ---------------------------------------------------------
//
void CMMS_ItView3::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CMMS_ItView3::DoActivateL(...)
// ?implementation_description
// ---------------------------------------------------------
//
void CMMS_ItView3::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CMMS_ItContainer3(iUI, iDocument);
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
        }

	iContainer->UpdateNaviPanelL();
   }

// ---------------------------------------------------------
// CMMS_ItView3::HandleCommandL(TInt aCommand)
// ?implementation_description
// ---------------------------------------------------------
//
void CMMS_ItView3::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }

// End of File
