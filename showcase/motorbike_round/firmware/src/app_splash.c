// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "definitions.h"
#include "app_screen.h"

/* animation tick period */
#define CLOCK_TICK_TIMER_PERIOD_MS 20
#define ANIM_PERIOD_MS 40

#define MGS_LOGO_WIDTH 380
#define MGS_LOGO_HEIGHT 90
#define EASE_COEFF 2

#define SPLASH_DELAY_MS 400
#define SPLASH_DURATION_MS 300

#define ANIM_PERIOD_TICKS (ANIM_PERIOD_MS/CLOCK_TICK_TIMER_PERIOD_MS)

/* splash screen states */
typedef enum
{
    APP_SPLASH_INIT,
    APP_SPLASH_WAIT_FOR_GUI,
    APP_SPLASH_ANIM_MGS,
    APP_SPLASH_ANIM_PAUSE,
    APP_SPLASH_ANIM_MCHP,
    APP_SPLASH_DONE,
    APP_SPLASH_EXIT,
} APP_SPLASH_STATES;

/* splash screen state variable */
static APP_SPLASH_STATES appSplashState;

/* splash screen tick counters */
static volatile unsigned int tickCount = 0;
static volatile unsigned int animTickCount = 0;
uint32_t animTickCountLast = 0;

/* tick timer handle */
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

extern bool APP_GetDirectBootEnabled(void);

/* tick timer callback */
static void APP_UI_Timer_Callback ( uintptr_t context)
{
    /* Increment tick and animation counters */
    tickCount++;

    if (tickCount % ANIM_PERIOD_TICKS)
        animTickCount++;
}

/* splash screen on show event handler */
void Splash_OnShow(void)
{
    uint32_t xpos;
    
    
    if (APP_GetDirectBootEnabled() == true)
    {
        appSplashState = APP_SPLASH_EXIT;
    }
    else
    {
        /* initialize splash screen state */
        appSplashState = APP_SPLASH_INIT;
        
        /* hide logos */
        APP_LE_SETVISIBLE(Splash_MicrochipLogo, LE_FALSE);
        APP_LE_SETWIDTH(Splash_MGSLogo, 0);

        xpos = APP_LE_GETX(Splash_MGSLogo);
        APP_LE_SETX(Splash_AnimLine, xpos);

        /* register and start tick timers */
        timer = SYS_TIME_CallbackRegisterMS(APP_UI_Timer_Callback, 
                                            1,
                                            CLOCK_TICK_TIMER_PERIOD_MS,
                                            SYS_TIME_PERIODIC);
        SYS_TIME_TimerStart(timer);  
    }
}

void Splash_OnHide(void)
{
    
}

/* splash screen on update event handler. This is periodically called within 
   the GUI library task and manages the GUI state machine */
void Splash_OnUpdate(void)
{
    switch(appSplashState)
    {
        case APP_SPLASH_INIT:
        {
            /* add delay to initialize display */
            appSplashState = APP_SPLASH_WAIT_FOR_GUI;
            SYS_TIME_DelayMS(SPLASH_DELAY_MS, &timer);
            
            break;
        }
        case APP_SPLASH_WAIT_FOR_GUI:
        {
            /* wait until delay expires and gui is done drawing */
            if (leIsDrawing() == LE_FALSE && SYS_TIME_DelayIsComplete(timer))
            {
                appSplashState = APP_SPLASH_ANIM_MGS;
            }
            
            break;
        }
        case APP_SPLASH_ANIM_MGS:
        {
            if (animTickCount != animTickCountLast)
            {
                /* slide/animate MGS logo at animation tick intervals */
                uint32_t width = APP_LE_GETWIDTH(Splash_MGSLogo);
                uint32_t delta = (MGS_LOGO_WIDTH - width) / EASE_COEFF;
                uint32_t x = APP_LE_GETX(Splash_MGSLogo);
                
                if (delta == 0)
                {
                    /* MGS logo is in position, delay for a bit */
                    appSplashState = APP_SPLASH_ANIM_PAUSE;
                    
                    APP_LE_SETWIDTH(Splash_MGSLogo, MGS_LOGO_WIDTH);
                    APP_LE_SETX(Splash_AnimLine, x + MGS_LOGO_WIDTH);
                    APP_LE_SETVISIBLE(Splash_MicrochipLogo, LE_TRUE);
                    SYS_TIME_DelayMS(SPLASH_DURATION_MS, &timer);
                }
                else
                {
                    APP_LE_SETWIDTH(Splash_MGSLogo, width + delta);
                    APP_LE_SETX(Splash_AnimLine, x + width + delta);
                }
                
                animTickCountLast = animTickCount;
            }
            
            break;
        }
        case APP_SPLASH_ANIM_PAUSE:
        {
            if (SYS_TIME_DelayIsComplete(timer) == true)
            {
                /* delay is complete, start mchp logo animation */
                appSplashState = APP_SPLASH_ANIM_MCHP;
            }
            break;
        }
        case APP_SPLASH_ANIM_MCHP:
        {
            if (animTickCount != animTickCountLast)
            {
                /* slide/animate MCHP logo */
                uint32_t width = APP_LE_GETWIDTH(Splash_MGSLogo);
                uint32_t delta = width / EASE_COEFF;
                uint32_t x = APP_LE_GETX(Splash_MGSLogo);
                
                if (delta == 0)
                {
                    appSplashState = APP_SPLASH_DONE;
                    
                    /* MCHP logo now in frame, delay for a little bit */
                    APP_LE_SETWIDTH(Splash_MGSLogo, 0);
                    APP_LE_SETX(Splash_AnimLine, x);
                    APP_LE_SETVISIBLE(Splash_AnimLine, LE_FALSE);
                    
                    SYS_TIME_DelayMS(SPLASH_DURATION_MS, &timer);
                }
                else
                {
                    APP_LE_SETWIDTH(Splash_MGSLogo, width - delta);
                    APP_LE_SETX(Splash_AnimLine, x + width - delta);
                }
                
                animTickCountLast = animTickCount;
            }
            
            break;
        }
        case APP_SPLASH_DONE:
        {
            if (SYS_TIME_DelayIsComplete(timer) == true)
            {       
                /* delay is complete, exit splash screen */
                SYS_TIME_TimerStop(timer); 
                SYS_TIME_TimerDestroy(timer); 
            
                appSplashState = APP_SPLASH_EXIT;
            }
            
            break;
        }
        case APP_SPLASH_EXIT:
        {
            /* show main gauges screen */
            legato_showScreen(screenID_Screen0);
            
            break;
        }
        default:
        {
            break;
        }
    }
}
