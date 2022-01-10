/*
* ============================================================================
*  Name     : CMMS_ItView from MMS_ItView.h
*  Part of  : MMS_It
*  Created  : 29/9/2003 by Makidis Michael
*  Description:
*     Declares view for application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITVIEW_H
#define MMS_ITVIEW_H

// INCLUDES
#include "MMS_ItAppUi.h"
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KViewId = {1};

// FORWARD DECLARATIONS
class CMMS_ItContainer;
class CMMS_ItDocument;

// CLASS DECLARATION

/**
*  CMMS_ItView view class.
* 
*/
class CMMS_ItView : public CAknView
    {
    public: // Constructors and destructor

		CMMS_ItView(CMMS_ItAppUi* aUI);

		/**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CMMS_ItView();

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

		CMMS_ItContainer* iContainer;

    public: // Data
        
		CMMS_ItAppUi* iUI;
    };

#endif

// End of File
