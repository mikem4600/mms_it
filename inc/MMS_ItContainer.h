/*
* ============================================================================
*  Name     : CMMS_ItContainer from MMS_ItContainer.h
*  Part of  : MMS_It
*  Created  : 29/9/2003 by Makidis Michael
*  Description:
*     Declares container control for application.
*  Copyright: Makidis Michael 2003-2004
* ============================================================================
*/

#ifndef MMS_ITCONTAINER_H
#define MMS_ITCONTAINER_H

// INCLUDES
#include <coecntrl.h>
#include <fbs.h> // for bitmap
#include "MMS_ItAttachment.h"


// CLASS DECLARATION
class CMMS_ItAppUi;

/**
*  CMMS_ItContainer  container control class.
*  
*/
class CMMS_ItContainer : public CCoeControl, MCoeControlObserver
    {
    public: // Constructors and destructor

		CMMS_ItContainer(CMMS_ItAppUi* aUI);

        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);

        /**
        * Destructor.
        */
        ~CMMS_ItContainer();

    public: // Functions from base classes
		/**
		* From CoeControl, OfferKeyEventL.
		* Handles the key-events.
		* @return If key-event is consumed, EKeyWasConsumed. Else
		* EKeyWasNotConsumed.
		* @param aKeyEvent Key event.
		* @param aType Type of key event(EEventKey, EEventKeyUp or
		* EEventKeyDown).
		*/
		TKeyResponse OfferKeyEventL(
			const TKeyEvent& aKeyEvent,
				TEventCode aType );

    private: // Functions from base classes

       /**
        * From CoeControl,SizeChanged.
        */
        void SizeChanged();

       /**
        * From CoeControl,CountComponentControls.
        */
        TInt CountComponentControls() const;

       /**
        * From CCoeControl,ComponentControl.
        */
        CCoeControl* ComponentControl(TInt aIndex) const;

       /**
        * From CCoeControl,Draw.
        */
        void Draw(const TRect& aRect) const;

		/**
        * From ?base_class ?member_description
        */
        // event handling section
        // e.g Listbox events
        void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);

		void LoadBitmapL(CFbsBitmap* aBitMap,const TDesC& aFileName,TInt aId,TBool aShareIfLoaded);

	public: // new functions
        
    private: //data

		CMMS_ItAppUi* iUI;
		CFbsBitmap* iBitmap;
    };

#endif

// End of File
