/*
* ============================================================================
*  Name     : CMMS_ItApp from MMS_ItApp.h
*  Part of  : MMS_It
*  Created  : 29/9/2003 by Makidis Michael
*  Description:
*     Declares main application class.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITAPP_H
#define MMS_ITAPP_H

// INCLUDES
#include <aknapp.h>

// CONSTANTS
// UID of the application
const TUid KUidMMS_It = { 0x0767A5B9 };  // please request a UID from Symbian

// CLASS DECLARATION

/**
* CMMS_ItApp application class.
* Provides factory to create concrete document object.
* 
*/
class CMMS_ItApp : public CAknApplication
    {
    
    public: // Functions from base classes
    private:

        /**
        * From CApaApplication, creates CMMS_ItDocument document object.
        * @return A pointer to the created document object.
        */
        CApaDocument* CreateDocumentL();
        
        /**
        * From CApaApplication, returns application's UID (KUidMMS_It).
        * @return The value of KUidMMS_It.
        */
        TUid AppDllUid() const;
    };

#endif

// End of File

