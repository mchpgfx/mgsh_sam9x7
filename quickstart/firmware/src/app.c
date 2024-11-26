/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>

#include "app.h"

#include "peripheral/pio/plib_pio.h"

#include "plugin/qrcode/legato_plugin_qrcode.h"

#include "definitions.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

char qrText[1024] = {0};

leBool event_Screen0_lePluginQR_OnDraw(leDrawSurfaceWidget* sfc, leRect* bounds)
{   
    qrResult result; 
    
    result = generateVCardQRText("John", "Doe", 
                        "Company", "Title",
                        "+1234567890", 
                        "john.doe@domain.com",
                        "Earth",
                        "https://www.w3.org/",
                        qrText, 
                        sizeof(qrText));
    
    result = generateEmailQRText("example@domain.com", qrText, sizeof(qrText));
    
    result = generateEmailDetailedQRText("example@domain.com", 
                                         "Meeting Tomorrow", 
                                         "Let's meet at 2 PM", 
                                         qrText, 
                                         sizeof(qrText));
    
    result = generateSMSQRText("+1234567890", 
                               "Hello there!", 
                               qrText, 
                               sizeof(qrText));
    
    result = generatePhoneQRText("+1234567890", qrText, sizeof(qrText));;
    
    result = generateWiFiQRText("NetworkName", 
                                "Password123", 
                                "WPA", 
                                qrText, 
                                sizeof(qrText));
    
    result = generateCalendarQRText("Meeting", 
                                    2024, 
                                    1, 
                                    25, 
                                    10, 
                                    0, 
                                    2024, 
                                    1, 
                                    25, 
                                    11, 
                                    0,
                                    "Office", 
                                    "Team Meeting", 
                                    qrText, 
                                    sizeof(qrText));
    
    result = generateUPIQRText("username@bankid",
                      "User",
                      "1.00",
                      "INR",
                      "UPI Test",
                      qrText,
                      sizeof(qrText));
    
    if (result != QR_SUCCESS)
    {
        return LE_FALSE;
    }
    else
    {
        return lePlugin_QRCode(sfc, 
                               bounds, 
                               qrText, 
                               LE_COLOR_WHITE, 
                               LE_COLOR_BLACK);
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            gfxIOCTLArg_DisplaySize argDispSize;
            gfxIOCTLArg_Value argVal;

             // Fetch display parameters
            if ((DRV_XLCDC_IOCTL(GFX_IOCTL_GET_DISPLAY_SIZE, &argDispSize) == GFX_IOCTL_OK) &&
                (DRV_XLCDC_IOCTL(GFX_IOCTL_GET_FRAMEBUFFER, &argVal) == GFX_IOCTL_OK) && 
                 leRenderer_IsIdle())
            {
                appData.width = argDispSize.width;
                appData.height = argDispSize.height;
                appData.buffer = argVal.value.v_pbuffer->pixels;
                
        
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            // START OF CUSTOM CODE
            static bool once = true;
            
            if(once)
            {
                /* Enable AC69T88A Display Backlight */
                AC69T88A_BACKLIGHT_EN_Set();
                once = false;
            // END OF CUSTOM CODE
            }
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
