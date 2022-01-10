/*
* ============================================================================
*  Name     : CMMS_ItView2 from MMS_ItView2.h
*  Part of  : MMS_It
*  Created  : 21/11/2004 by 
*  Description:
*     Declares view for application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITVIEW2_H
#define MMS_ITVIEW2_H

// INCLUDES
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KView2Id = {2};

// FORWARD DECLARATIONS
class CMMS_ItContainer2;
class CMMS_ItDocument;
class CMMS_ItAppUi;

// CLASS DECLARATION

/**
*  CMMS_ItView2 view class.
* 
*/
class CMMS_ItView2 : public CAknView
    {
    public: // Constructors and destructor

		CMMS_ItView2(CMMS_ItDocument* aDocument, CMMS_ItAppUi* aUI);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CMMS_ItView2();

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

		void UpdateContainer();

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
        CMMS_ItContainer2* iContainer;

		/*! @var iDocument The current document */
		CMMS_ItDocument* iDocument;

		CMMS_ItAppUi* iUI;
    };

#endif

// End of File
