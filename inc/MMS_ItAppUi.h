/*
* ============================================================================
*  Name     : CMMS_ItAppUi from MMS_ItAppUi.h
*  Part of  : MMS_It
*  Created  : 29/9/2003 by Makidis Michael
*  Description:
*     Declares UI class for application.
*  Copyright: Makidis Michael 2003-2005
* ============================================================================
*/

#ifndef MMS_ITAPPUI_H
#define MMS_ITAPPUI_H

// INCLUDES
#include <eikapp.h>
#include <eikdoc.h>
#include <e32std.h>
#include <coeccntx.h>
#include <aknviewappui.h>
#include <akntabgrp.h>
#include <aknnavide.h>

// MMS
#include <msvapi.h>  // for MMsvSessionObserver 
#include <mmsclient.h>  // for CMmsClientMtm

// FORWARD DECLARATIONS
class CClientMtmRegistry;
class CMMS_ItView;
class CMMS_ItView2;
class CMMS_ItView3;
class CMMS_ItDocument;


// CONSTANTS
//const ?type ?constant_var = ?constant;


// CLASS DECLARATION

/**
* Application UI class.
* Provides support for the following features:
* - EIKON control architecture
* - view architecture
* - status pane
* 
*/
class CMMS_ItAppUi : public CAknViewAppUi, public MMsvSessionObserver
    {
    public: // Constructors and destructor

		CMMS_ItAppUi(CMMS_ItDocument *aDocument);

		/**
        * EPOC default constructor.
        */      
        void ConstructL();

        /**
        * Destructor.
        */      
        ~CMMS_ItAppUi();
        
    public: // New functions

		void ShowDefaultNaviPaneL();

		void ShowAtNaviPanelL(TPtrC message);

    public: // Functions from base classes

        /**
        * From CEikAppUi, takes care of command handling.
        * @param aCommand command to be handled
        */
        void HandleCommandL(TInt aCommand);

    private:

        /**
        * From CEikAppUi, handles key events.
        * @param aKeyEvent Event to handled.
        * @param aType Type of the key event. 
        * @return Response code (EKeyWasConsumed, EKeyWasNotConsumed). 
        */
        virtual TKeyResponse HandleKeyEventL(
            const TKeyEvent& aKeyEvent,TEventCode aType);

        // From MEikMenuObserver
        void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

		// from MMsvSessionObserver
		void HandleSessionEventL
			(TMsvSessionEvent aEvent, TAny* aArg1, TAny* aArg2, TAny* aArg3);

		void CompleteConstructL();

		TBool SendMessageL(TBool aUsePbForAddresses = ETrue);

    private: //Data
        CAknNavigationControlContainer* iNaviPane;
        CAknNavigationDecorator* iNaviDecorator;

		CMMS_ItView* iView1;
		CMMS_ItView2* iView2;
		CMMS_ItView3* iView3;

		/*! @var iDocument The current document */
		CMMS_ItDocument* iDocument;

		
		CMsvSession* iSession;          // Client session on the message server
		CMmsClientMtm* iMmsMtm;         // Message Type Module (MMS)
		CClientMtmRegistry* iMtmReg;    // Mtm client registry for creating new mtms
    };

#endif

// End of File
