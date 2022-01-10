/*
* ============================================================================
*  Name     : CMMS_ItContainer3 from MMS_ItContainer3.h
*  Part of  : MMS_It
*  Created  : 21/11/2004 by 
*  Description:
*     Declares container control for application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITCONTAINER3_H
#define MMS_ITCONTAINER3_H

// INCLUDES
#include <coecntrl.h>
#include <aknlists.h> // for the listbox
   
// FORWARD DECLARATIONS
class CMMS_ItAppUi;
class CMMS_ItDocument;

// CLASS DECLARATION

/**
*  CMMS_ItContainer  container control class.
*  
*/
class CMMS_ItContainer3 : public CCoeControl, MCoeControlObserver,
							public MEikListBoxObserver
    {
    public: // Constructors and destructor
        
		CMMS_ItContainer3(CMMS_ItAppUi* aUI, CMMS_ItDocument* aDocument);

        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);

        /**
        * Destructor.
        */
        ~CMMS_ItContainer3();

    public: // New functions

		void AddAttachmentL();

		void AddAttachmentManuallyL();

		void RemoveAttachmentL();

		void RemoveAllAttachments();

		void EditMimeType();

		void SetMimeTypeL(TDes8& aMimeType);

		void ResetMimeTypeL();

		void UpdateNaviPanelL();

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

		void HandleListBoxEventL(CEikListBox* /*aListBox*/, TListBoxEvent /*aEventType*/){};
        
    private: //data
        CAknDoubleLargeStyleListBox* iListBox;
        CMMS_ItAppUi* iUI;

		/*! @var iDocument The current document */
		CMMS_ItDocument* iDocument;
    };

#endif

// End of File
