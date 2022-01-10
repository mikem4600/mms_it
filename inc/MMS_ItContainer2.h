/*
* ============================================================================
*  Name     : CMMS_ItContainer2 from MMS_ItContainer2.h
*  Part of  : MMS_It
*  Created  : 21/11/2004 by 
*  Description:
*     Declares container control for application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITCONTAINER2_H
#define MMS_ITCONTAINER2_H

// INCLUDES
#include <coecntrl.h>
#include <fbs.h> // for bitmap

// FORWARD DECLARATIONS
class CEikLabel;        // for labels
class CEikEdwin;        // for editor
class CMMS_ItAppUi;
class CMMS_ItDocument;


// CLASS DECLARATION

/**
*  CMMS_ItContainer2  container control class.
*  
*/
class CMMS_ItContainer2 : public CCoeControl, MCoeControlObserver
    {
    public: // Constructors and destructor
        
		CMMS_ItContainer2(CMMS_ItAppUi* aUI, CMMS_ItDocument* aDocument);

        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);

        /**
        * Destructor.
        */
        ~CMMS_ItContainer2();

    public: // New functions

		void SaveMessageText();

		void UpdateLabelsL();

		void UpdateEditorL();

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
        
    private: //data
        CMMS_ItAppUi* iUI;

		/*! @var iDocument The current document */
		CMMS_ItDocument* iDocument;

        CEikLabel* iLblSubject;
        CEikLabel* iLblSmil;
		CEikLabel* iLblAttach;
		CEikEdwin* iEdwin;
		
		CFbsBitmap* iPicSubject;
		CFbsBitmap* iPicSmil;
		CFbsBitmap* iPicAttach;
    };

#endif

// End of File
