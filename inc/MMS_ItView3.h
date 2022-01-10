/*
* ============================================================================
*  Name     : CMMS_ItView3 from MMS_ItView3.h
*  Part of  : MMS_It
*  Created  : 21/11/2004 by 
*  Description:
*     Declares view for application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITVIEW3_H
#define MMS_ITVIEW3_H

// INCLUDES
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KView3Id = {3};

// FORWARD DECLARATIONS
class CMMS_ItContainer3;
class CMMS_ItDocument;
class CMMS_ItAppUi;

// CLASS DECLARATION

/**
*  CMMS_ItView view class.
* 
*/
class CMMS_ItView3 : public CAknView
    {
    public: // Constructors and destructor

		CMMS_ItView3(CMMS_ItDocument* aDocument, CMMS_ItAppUi* aUI);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CMMS_ItView3();

    public: // Functions from base classes
        
        /**
        * From ?base_class ?member_description
        */
        TUid Id() const;

        /**
        * From ?base_class ?member_description
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From ?base_class ?member_description
        */
        void HandleClientRectChange();

    private:

        /**
        * From AknView, ?member_description
        */
        void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId,
            const TDesC8& aCustomMessage);

        /**
        * From AknView, ?member_description
        */
        void DoDeactivate();

    private: // Data
        
		/*! @var iDocument The current document */
		CMMS_ItDocument* iDocument;

		CMMS_ItAppUi* iUI;

		CMMS_ItContainer3* iContainer;

    };

#endif

// End of File
