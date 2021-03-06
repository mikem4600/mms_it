/*
* ============================================================================
*  Name     : CMMS_ItApp from MMS_ItApp.cpp
*  Part of  : MMS_It
*  Created  : 29/9/2003 by Makidis Michael
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

// INCLUDE FILES
#include    "MMS_ItApp.h"
#include    "MMS_ItDocument.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CMMS_ItApp::AppDllUid()
// Returns application UID
// ---------------------------------------------------------
//
TUid CMMS_ItApp::AppDllUid() const
    {
    return KUidMMS_It;
    }

   
// ---------------------------------------------------------
// CMMS_ItApp::CreateDocumentL()
// Creates CMMS_ItDocument object
// ---------------------------------------------------------
//
CApaDocument* CMMS_ItApp::CreateDocumentL()
    {
    return CMMS_ItDocument::NewL( *this );
    }

// ================= OTHER EXPORTED FUNCTIONS ==============
//
// ---------------------------------------------------------
// NewApplication() 
// Constructs CMMS_ItApp
// Returns: created application object
// ---------------------------------------------------------
//
EXPORT_C CApaApplication* NewApplication()
    {
    return new CMMS_ItApp;
    }

// ---------------------------------------------------------
// E32Dll(TDllReason) 
// Entry point function for EPOC Apps
// Returns: KErrNone: No error
// ---------------------------------------------------------
//
GLDEF_C TInt E32Dll( TDllReason )
    {
    return KErrNone;
    }

// End of File  

