/*
* ============================================================================
*  Name     : TMMS_ItAttachment from MMS_ItAttachment.h
*  Part of  : MMS_It
*  Created  : 23/10/2004 by Makidis Michael
*  Description:
*     Declares the attachment type of the application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITATTACHMENT_H
#define MMS_ITATTACHMENT_H

// INCLUDES
#include <e32std.h>

// CONSTANTS

// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
*  TMMS_ItAttachment class.
*/
class TMMS_ItAttachment
    {
    public: // Constructors and destructor
        /**
        * Two-phased constructor.
        */
        TMMS_ItAttachment();


    public:
		TFileName iFilename;
		TBuf8<40> iMIMEType;
		TBool iMIMETypeSet;
		TInt iSize;

    protected:  // New functions

    protected:  // Functions from base classes

    private:

    };

#endif

// End of File

