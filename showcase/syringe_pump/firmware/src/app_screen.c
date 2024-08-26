/*******************************************************************************
  System Initialization File

  File Name:
    app_screen.c

  Summary:
    This file contains the GUI application code.

  Description:
    This file contains the application screen callbacks, update state machines 
    and application APIs.
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2024 Microchip Technology Inc. and its subsidiaries.
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

#include <math.h>

#include "definitions.h"
#include "app_screen.h"
#include "app_macros.h"

/* Canvas objects configuration table */
static APP_SCREEN_CANVAS_OBJ appScreenCanvasTable[APP_SCREEN_CANVAS_MAX] =
{
#ifdef MGS_SIM
    {APP_SCREEN_CANVAS_SPLASH, &Screen0_SplashPanel, 0, {1280, 400}, {0, 0}, {1280, 0}},
    {APP_SCREEN_CANVAS_MEDSMENU, &Screen0_MedsMenuPanel, 1, {1960, 400}, {0, 0}, {1280, 0}},
    {APP_SCREEN_CANVAS_MAINMENU, &Screen0_MainMenuPanel, 2, {1280, 400}, {0, 0}, {-400, 0}},
    {APP_SCREEN_CANVAS_DRUGMAIN, &Screen0_DrugScreenPanel, 0, {1280, 400}, {0, 0}, {1280, 0}},
    {APP_SCREEN_CANVAS_NUMENTRY, &Screen0_NumEditPanel, 1, {1280, 400}, {0, 0}, {0, 400}},
    {APP_SCREEN_CANVAS_POPUP_OK, &Screen0_SuccessScreenPanel, 1, {1280, 400}, {0, 0}, {0, 0}},
#else    
    {APP_SCREEN_CANVAS_SPLASH, &Screen0_SplashPanel, 0, {400, 1280}, {0, 0}, {0, 0}},
    {APP_SCREEN_CANVAS_MEDSMENU, &Screen0_MedsMenuPanel, 1, {400, 1960}, {0, 0}, {0, 1280}},
    {APP_SCREEN_CANVAS_MAINMENU, &Screen0_MainMenuPanel, 2, {400, 1280}, {0, 0}, {0, -400}},
    {APP_SCREEN_CANVAS_DRUGMAIN, &Screen0_DrugScreenPanel, 0, {400, 1280}, {0, 0}, {0, -400}},
    {APP_SCREEN_CANVAS_NUMENTRY, &Screen0_NumEditPanel, 1, {400, 1280}, {0, 0}, {0, -1280}},
    {APP_SCREEN_CANVAS_POPUP_OK, &Screen0_SuccessScreenPanel, 1, {400, 1280}, {0, 0}, {0, 0}},        
#endif
};

static APP_SCREEN_STATE appScreenState;     /* GUI application state */
static APP_SCREEN_STATE appNextScreenState; /* GUI application next state */
static uint32_t canvasMoveEffectStatusFlags = 0; /* Canvas move effect status flags */
static uint32_t canvasFadeEffectStatusFlags = 0; /* Canvas fade effect status flags */
static DRUG_DATABASE_ENTRY * currentDrug; /* The selected drug */

static APP_INPUT_RECORD_ID inputValueEntryId = APP_INPUT_MAX; /* The current input data */
static uint32_t screenEvents; /* screen event flags */
static int32_t lastX, lastY, deltaPos;  /* position variables for touch swipe/slide */
static uint32_t counter = 0;    /* screen counter */
SYS_TIME_HANDLE screenTimer;    /* GUI Timer handle */ 
static volatile unsigned int appScreenTick = 0;     /* GUI Timer tick */
static volatile unsigned int appScreenLastTick = 0; /* GUI timer last tick */

/* c string buffer for input data */
static char inputValueCharBuff[CHAR_LIMIT + 1] = {0};

/* Fixed string objects for input data */
static leFixedString valueNumStr[APP_INPUT_MAX];
static leChar valueNumStrBuff[APP_INPUT_MAX][CHAR_LIMIT + 1] = {0};

/* Fixed string objects for pressure label */
static leChar pressureStrBuff[PRESSURE_MAX_DIGITS + 1] = {0};
static leFixedString pressureStr;

/* Fixed string objects for time elapsed label */
static leChar timeElapsedStrBuff[TIME_MAX_CHARS + 1] = {0};
static leFixedString timeElapsedStr;

/* Fixed string objects for time left label */
static leChar timeLeftStrBuff[TIME_MAX_CHARS + 1] = {0};
static leFixedString timeLeftStr;

/* Fixed string objects for vol left label */
static leChar volLeftStrBuff[VOL_MAX_DIGITS + 1] = {0};
static leFixedString volLeftStr;

/* Fixed string objects for vol label */
static leChar volStrBuff[VOL_MAX_DIGITS + 1] = {0};
static leFixedString volStr;

/* Application sec ticks */
static uint32_t timeTicks = 0;
static uint32_t timeRemainingTicks = DEF_TIME_TICKS_LEFT;

/* input system service listener object */
static SYS_INP_InputListener APP_inputListener;

/* volume values */
static double volumeTickValue;
static double volumeLeft;

/* GUI tick timer callback */
static void APP_ScreenTick_TimerCallback ( uintptr_t context)
{
    appScreenTick++;
}

/* Helper function for updating volume remaining label */
static void APP_SetVolLeftLabel(uint32_t ml)
{
    if (ml <= MAX_VOL)
    {
        char vol[VOL_MAX_DIGITS + 1] = {0};

        snprintf(vol, VOL_MAX_DIGITS + 1, "%lu", ml);

        volLeftStr.fn->setFromCStr(&volLeftStr, vol);
        Screen0_VolLeftValueLabel->fn->setString(Screen0_VolLeftValueLabel, 
                                                 (leString *) &volLeftStr);
    }
}

/* Helper function for updating volume label */
static void APP_SetVolumeLabel(uint32_t ml)
{
    if (ml <= MAX_VOL)
    {
        char vol[VOL_MAX_DIGITS + 1] = {0};

        snprintf(vol, VOL_MAX_DIGITS + 1, "%lu", ml);

        volStr.fn->setFromCStr(&volStr, vol);
        Screen0_VolValueLabel->fn->setString(Screen0_VolValueLabel, 
                                             (leString *) &volStr);
    }
}

/* Helper function for converting application secs to hr, min, secs */
static void APP_GetTimeFromSecs(uint32_t * hr, 
                                uint32_t * min,
                                uint32_t * sec,
                                uint32_t secs)
{
    *sec = secs % 60;
    *min = (secs / 60) % 60;
    *hr = (secs / (60 * 60)) % 24;
}

/* Helper function for updating time left label */
static void APP_SetTimeLeftLabel(uint32_t hr, uint32_t min, uint32_t sec)
{
    char timeCStr[TIME_MAX_CHARS + 1] = {0};

    snprintf(timeCStr, TIME_MAX_CHARS + 1, "%02lu:%02lu:%02lu", hr, min, sec);

    timeLeftStr.fn->setFromCStr(&timeLeftStr, timeCStr);
    Screen0_TimeLeftValueLabel->fn->setString(Screen0_TimeLeftValueLabel, 
                                              (leString *) &timeLeftStr);
}

/* Helper function for updating time elapsed label */
static void APP_SetTimeElapsedLabel(uint32_t hr, uint32_t min, uint32_t sec)
{
    char timeCStr[TIME_MAX_CHARS + 1] = {0};

    snprintf(timeCStr, TIME_MAX_CHARS + 1, "%02lu:%02lu:%02lu", hr, min, sec);

    timeElapsedStr.fn->setFromCStr(&timeElapsedStr, timeCStr);
    Screen0_TimeElapsedValueLabel->fn->setString(Screen0_TimeElapsedValueLabel, 
                                              (leString *) &timeElapsedStr);
}

/* Helper function for setting GUI event flags */
static void APP_SetEvent(APP_SCREEN_EVT event)
{
    screenEvents |= (1 << event);
}

/* Helper function for clearing all GUI event flags */
static void APP_ClearEvents(void)
{
    screenEvents = 0;
}

/* Helper function for getting GUI event flag status */
static bool APP_GetEvent(APP_SCREEN_EVT event)
{
    uint32_t eventStatus = (screenEvents & (1 << event));
    
    screenEvents &= ~(1 << event);
    
    return (eventStatus != 0);
}

/* Application callback for touch down event */
static void APP_TouchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    lastX = evt->x;
    lastY = evt->y;
    
    APP_SetEvent(APP_SCREEN_EVT_TOUCH_DOWN);
}

/* Application callback for touch up event */
static void APP_TouchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    lastX = evt->x;
    lastY = evt->y;
    
    APP_SetEvent(APP_SCREEN_EVT_TOUCH_UP);
}

/* Application callback for touch move event. */
static void APP_TouchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    deltaPos = evt->x - lastX;
    
    if (deltaPos > TOUCH_SLIDE_DELTA_PX) //swipe right
    {
        APP_SetEvent(APP_SCREEN_EVT_TOUCH_SLIDE_RIGHT);        
    }
    else if (deltaPos < -TOUCH_SLIDE_DELTA_PX) //swipe left
    {
        APP_SetEvent(APP_SCREEN_EVT_TOUCH_SLIDE_LEFT);
    }
    
    lastX = evt->x;
}

/* Helper function to check if any canvas effects are still active */
static bool APP_ScreenCanvasEffectIdle(void)
{
    return (canvasMoveEffectStatusFlags == 0 && canvasFadeEffectStatusFlags == 0);
}

/* Application callback for canvas effects */
static void APP_Canvas_EffectsCallback(unsigned int canvasID,
                                       GFXC_FX_TYPE effect,
                                       GFXC_FX_STATUS status,
                                       void * parm)
{
    /* Set appropriate status bit for each canvas effect */
    switch (effect)
    {
        case GFXC_FX_MOVE:
        {
            if (status == GFXC_FX_START)
            {
                canvasMoveEffectStatusFlags |= (1 << canvasID);
            }
            else if (status == GFXC_FX_DONE)
            {
                canvasMoveEffectStatusFlags &= ~(1 << canvasID);
            }
        }
        case GFXC_FX_FADE:
        {
            if (status == GFXC_FX_START)
            {
                canvasFadeEffectStatusFlags |= (1 << canvasID);
            }
            else if (status == GFXC_FX_DONE)
            {
                canvasFadeEffectStatusFlags &= ~(1 << canvasID);
            }
        }
        default:
            break;
    }
    
}

#ifdef AUTO_PRESSURE_ANIM
/* Helper function for setting the pressure circular knob position based on value */
static void setPressureValue(uint32_t pressure)
{
    char pressureCStr[4] = {0};
    lePoint knobpos;
    double dx, dy, angle;
    
    if (pressure <= PRESSURE_MAX && pressure >= PRESSURE_MIN)
    {
        snprintf(pressureCStr, 4, "%lu", pressure);
        
        angle = ((pressure - PRESSURE_MIN) * 180) / (PRESSURE_MAX - PRESSURE_MIN);
        
        //determine knob point based on angle and main radius
        dx = RADMID * cos ((angle * M_PI) / 180);
        dy = RADMID * sin ((angle * M_PI) / 180);
        
        //move knob and adjust value
        knobpos.x = CENTERX - dx;
        knobpos.y = CENTERY - dy;
        
        leUtils_PointScreenToLocalSpace((leWidget *) Screen0_DrugInfoPressureBox, &knobpos);
        APP_LE_SETPOS(Screen0_KnobImage, knobpos.x - 20, knobpos.y - 20);        

        pressureStr.fn->setFromCStr(&pressureStr, pressureCStr);
        Screen0_PressureValueLabel->fn->setString(Screen0_PressureValueLabel, (leString *) &pressureStr);
    }
}

#else

/* Touch event filters to support manual pressure knob setting via touch */
static leBool Knob_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{
    leBool retval = LE_FALSE;    
    lePoint pnt, knobpos;
    double rad;
    double dx, dy, angle;
    uint32_t pressure;
    char pressureCStr[4] = {0};
    
    pnt.x = ((leWidgetEvent_TouchDown *) evt)->x;
    pnt.y = ((leWidgetEvent_TouchDown *) evt)->y;      
    
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_MOVE:         
        case LE_EVENT_TOUCH_DOWN:
        {
            evt->accepted = LE_TRUE;
            evt->owner = target;
            
            dx = CENTERX - pnt.x;
            dy = CENTERY - pnt.y;
            
            //Get radius from center
            rad = sqrt(dx*dx + dy*dy);
            
            //determine if radius is within active area
            if ((rad > RADMIN) && (rad < RADMAX))
            {
                //determine angle, from right x axis
                if (dx == 0)
                {
                    angle = 90;
                }
                else if (dy <= 0)
                {
                    angle = (dx < 0) ? 180 : 0;
                }
                else 
                {
                    angle = (asin(dy/rad) * 180) / (3.14);
                    if (dx < 0)
                    {
                        angle = 180 - angle;
                    }
                }
                
                //determine knob point based on angle and main radius
                dx = RADMID * cos ((angle * 3.14) / 180);
                dy = RADMID * sin ((angle * 3.14) / 180);

                //move knob and adjust value
                knobpos.x = CENTERX - dx;
                knobpos.y = CENTERY - dy;

                leUtils_PointScreenToLocalSpace((leWidget *) Screen0_DrugInfoPressureBox, &knobpos);
                APP_LE_SETPOS(Screen0_KnobImage, knobpos.x - 20, knobpos.y - 20);

                //get value based on angle from 0 - 180
                pressure = (((PRESSURE_MAX - PRESSURE_MIN) * angle) / 180) + PRESSURE_MIN;

                snprintf(pressureCStr, 4, "%lu", pressure);


                pressureStr.fn->setFromCStr(&pressureStr, pressureCStr);
                Screen0_PressureValueLabel->fn->setString(Screen0_PressureValueLabel, (leString *) &pressureStr);

            }
            
            leUtils_PointScreenToLocalSpace(target, &pnt);
            
            retval = LE_TRUE;
            
            break;
        }   
        case LE_EVENT_TOUCH_UP:            
        {
            
            leUtils_PointScreenToLocalSpace(target, &pnt);
            
            evt->accepted = LE_TRUE;
                    
            retval = LE_TRUE;

            break;        
        }
        default:
            break;
    }
    
   return retval;
}

/* Touch event filters for pressure knob touch input */
static leWidgetEventFilter KnobArea_eventFilter =
{
    Knob_filterEvent,
    NULL
};

#endif

/* Initialze the screen canvas objects. Called when the screen is shown. */
void APP_Screen_Initialize(void)
{
    uint32_t i = 0;
    
    /* Configure canvas objects for each pre-rendered virtual screens, incl HW layer, size, position
       callbacks. All screens are hidden at startup. */
    for (i = 0; i < APP_SCREEN_CANVAS_MAX; i++)
    {
        gfxcSetLayer(appScreenCanvasTable[i].id, 
                     appScreenCanvasTable[i].lcdLayer);
        
        gfxcSetWindowSize(appScreenCanvasTable[i].id,
                              appScreenCanvasTable[i].size.width,
                              appScreenCanvasTable[i].size.height);
        gfxcSetWindowPosition(appScreenCanvasTable[i].id,
                              appScreenCanvasTable[i].hidePos.x,
                              appScreenCanvasTable[i].hidePos.y);
        
        gfxcSetEffectsCallback(appScreenCanvasTable[i].id,
                               APP_Canvas_EffectsCallback,
                               NULL);        
        
        //Hide all layers
        gfxcHideCanvas(appScreenCanvasTable[i].id);
        gfxcCanvasUpdate(appScreenCanvasTable[i].id);
    }
    
            
}

/* Application callback for screen on show event. Called when screen is first initialized, before rendering. */
void Screen0_OnShow(void)
{
    uint32_t i;
    
    /* Initialize canvas objects */
    APP_Screen_Initialize();
    
    /* Hide all layers/panels */
    for (i = 0; i < APP_SCREEN_CANVAS_MAX; i++)
    {
        if (*(appScreenCanvasTable[i].panel) != NULL)
        {
            APP_LE_SETVISIBLE((*(appScreenCanvasTable[i].panel)), LE_FALSE);
        }
    }

    /* Initialize all input data fields */
    for (i = 0; i < APP_INPUT_MAX; i++)
    {
        INPUT_VALUE_ENTRY *  valueRecord = APP_GetValueRecord(i);
        if (valueRecord != NULL)
        {
           leFixedString_Constructor(&valueNumStr[i], valueNumStrBuff[i], CHAR_LIMIT);
           valueNumStr[i].fn->setFont(&valueNumStr[i], valueRecord->font);
        }
    }

    /* Initialize all fixed string objects */
    leFixedString_Constructor(&pressureStr, pressureStrBuff, PRESSURE_MAX_DIGITS);
    pressureStr.fn->setFont(&pressureStr, (const leFont* ) &BigBoldNum); 

    leFixedString_Constructor(&timeElapsedStr, timeElapsedStrBuff, TIME_MAX_CHARS);
    pressureStr.fn->setFont(&timeElapsedStr, (const leFont* ) &MedBoldNum);

    leFixedString_Constructor(&volLeftStr, volLeftStrBuff, VOL_MAX_DIGITS);
    pressureStr.fn->setFont(&volLeftStr, (const leFont* ) &MedBoldNum);

    leFixedString_Constructor(&timeLeftStr, timeLeftStrBuff, TIME_MAX_CHARS);
    pressureStr.fn->setFont(&timeLeftStr, (const leFont* ) &MedBoldNum);     

    leFixedString_Constructor(&volStr, volStrBuff, VOL_MAX_DIGITS);
    pressureStr.fn->setFont(&volStr, (const leFont* ) &MedBoldNum);     
    
    /* Show splash screen, this will tell the library to draw the splash screen layer */
    APP_LE_SETVISIBLE((*(appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].panel)), LE_TRUE);
    
    /* Register input system service touch event listeners */
    APP_inputListener.handleTouchDown = &APP_TouchDownHandler;
    APP_inputListener.handleTouchUp = &APP_TouchUpHandler;
    APP_inputListener.handleTouchMove = &APP_TouchMoveHandler;
                
    SYS_INP_AddListener(&APP_inputListener);    
    
#ifndef AUTO_PRESSURE_ANIM    
    APP_LE_SETEVENTFILTER(Screen0_DrugInfoPressureBox, KnobArea_eventFilter);
#endif    
    
    /* Clear all screen eents */
    screenEvents = 0;
    
    /* Initialize screen state and next state */
    appScreenState = APP_SCREEN_SHOW_SPLASH;
    appNextScreenState = APP_SCREEN_SHOW_MAINMENU;
        
    counter = 0;
}

/* Application callback for screen hide event */
void Screen0_OnHide(void)
{
    /* Do nothing. This is a single composer screen application. All application screens
     are designed as virtual screens, which are composer layers that are pre-rendered 
     to frame buffers using graphics canvas. */
}

/* Application callback for screen update event. This function will be periodically
   called at each GFX library task cycle. This function is used to manage the 
   GUI application state machine. */
void Screen0_OnUpdate(void)
{
    switch(appScreenState)
    {
        /* Show splash screen */
        case APP_SCREEN_SHOW_SPLASH:
        {
            /* Wait for splash screen to be completely rendered to frame buffer */
            if (leRenderer_IsIdle() == false)
                break;
            
            /* Use canvas to show the splash screen */
            gfxcSetLayer(appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].id, appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].lcdLayer);
            gfxcSetWindowPosition(appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].id,
                              appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].showPos.x,
                              appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].showPos.y);
            gfxcShowCanvas(appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].id);
            gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_SPLASH].id);
            
            appScreenState = APP_SCREEN_WAIT_SPLASH;

            /* Delay for splash screen to be visible */
            SYS_TIME_DelayMS(500, &screenTimer);

            break;
        }
        /* Wait for splash screen delay */
        case APP_SCREEN_WAIT_SPLASH:
        {
            if (leRenderer_IsIdle() == false || SYS_TIME_DelayIsComplete(screenTimer) == false)
                break;
            
            appScreenState = APP_SCREEN_DRAW_SCREENS;
            break;
        }
        /* Draw other screens while splas screen is shown */
        case APP_SCREEN_DRAW_SCREENS:
        {
            /* Set all virtual screen panels as visible to start library draw */
            if (counter < APP_SCREEN_CANVAS_MAX)
            {
                if (*(appScreenCanvasTable[counter].panel) != NULL)
                {
                    APP_LE_SETVISIBLE((*(appScreenCanvasTable[counter].panel)), LE_TRUE);
                }

                counter++;
            }
            else
            {
                appScreenState = APP_SCREEN_INIT;
            }
            
            break;
        }
        /* Once library is down drawing all screens, continue GUI app initialization */
        case APP_SCREEN_INIT:
        {
            if (leRenderer_IsIdle() == true)
            {
                screenTimer = SYS_TIME_CallbackRegisterMS(APP_ScreenTick_TimerCallback,
                              1, 
                              SCREEN_TICK_TIMER_PERIOD_MS,
                              SYS_TIME_PERIODIC);
                
                appScreenState = APP_SCREEN_SHOW_MAINMENU;
            }
            
            break;
        }
        /* Show the main menu screen */
        case APP_SCREEN_SHOW_MAINMENU:
        {
            /* Slide the main menu screen into view */
            gfxcSetLayer(appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].id, 
                         appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].lcdLayer);
            gfxcSetWindowPosition(appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].id,
                          appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].hidePos.x,
                          appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].hidePos.y);
            gfxcShowCanvas(appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].id);
            gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].id);   

            gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].id,
                                GFXC_FX_MOVE_DEC,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].hidePos.x,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].hidePos.y,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].showPos.x,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].showPos.y,
                                LAYER_FX_MOVE_DELTA); 

            /* Slide the meds menu screen into view */
            gfxcSetLayer(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id, 
                             appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].lcdLayer);
                
            gfxcSetWindowPosition(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id,
                          appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].hidePos.x,
                          appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].hidePos.y);
            gfxcShowCanvas(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id);
            gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id);                

            gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id,
                                GFXC_FX_MOVE_DEC,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].hidePos.x,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].hidePos.y,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.x,
                                appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.y,
                                LAYER_FX_MOVE_DELTA);            
                
            /* Wait for animation to complete, and transition to next screen state */
            appScreenState = APP_SCREEN_WAIT_SCREEN;
            appNextScreenState = APP_SCREEN_SHOW_MAIN;
            
            break;
        }        
        case APP_SCREEN_SHOW_MAIN:
        {
            /* Show the drug main screen (bottom layer) */
            gfxcSetLayer(appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].id, 
                         appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].lcdLayer);

            gfxcSetWindowSize(appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].id,
                                  appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].size.width,
                                  appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].size.height);
            gfxcSetWindowPosition(appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].id,
                                  appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].showPos.x,
                                  appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].showPos.y);            

            gfxcShowCanvas(appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].id);
            gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_DRUGMAIN].id);  
            
            appScreenState = APP_SCREEN_WAIT_SCREEN;
            appNextScreenState = APP_SCREEN_MAIN_READY;
            
            break;
        }
        case APP_SCREEN_MAIN_READY:
        {
            //Enable main menu and drug menu panels
            APP_LE_ENABLE_TOUCH(Screen0_MedsMenuPanel, LE_TRUE);
            APP_LE_ENABLE_TOUCH(Screen0_MainMenuPanel, LE_TRUE);
                   
            appScreenState = APP_SCREEN_IDLE_MAIN_0;
            
            break;
        }
        /* Main menu idle state */
        case APP_SCREEN_IDLE_MAIN_0: //fall through
        case APP_SCREEN_IDLE_MAIN_1:            
        {
            /* Process touch events (slide, down/up) */
            if (APP_GetEvent(APP_SCREEN_EVT_TOUCH_SLIDE_LEFT) || APP_GetEvent(APP_SCREEN_EVT_TOUCH_SLIDE_RIGHT))
            {
                appScreenState = APP_SCREEN_SLIDE_MOVE;
            }
            else if (APP_GetEvent(APP_SCREEN_EVT_TOUCH_DOWN))
            {
                lePoint point;
                
                point.x = (appScreenState == APP_SCREEN_IDLE_MAIN_0) ? lastX : (lastX + 680);
                point.y = lastY;
                
                /* Determine which button is pressed */
                DRUG_DATABASE_ENTRY * drug = APP_GetDrugButtonFromPosition(point);
                if (drug != NULL)
                {
                    leButtonWidget * button = *(drug->button);
                    button->fn->setPressed(button, LE_TRUE);
                }                
            }            
            else if (APP_GetEvent(APP_SCREEN_EVT_TOUCH_UP))
            {
                lePoint point;
                
                point.x = (appScreenState == APP_SCREEN_IDLE_MAIN_0) ? lastX : (lastX + 680);
                point.y = lastY;
                
                /* Determine selected drug for the button that was released */
                DRUG_DATABASE_ENTRY * drug = APP_GetDrugButtonFromPosition(point);
                if (drug != NULL)
                {
                    uint32_t hr, min, sec;

                    leButtonWidget * button = *(drug->button);
                    
                    currentDrug = drug;
                    
                    button->fn->setPressed(button, LE_FALSE);
                    
                    APP_LE_ENABLE_TOUCH(Screen0_MedsMenuPanel, LE_FALSE);
                    APP_LE_ENABLE_TOUCH(Screen0_MainMenuPanel, LE_FALSE);
                    
                    /* Update the drug screen to show the selected drug */
                    APP_LE_SETBUTTONIMAGE(Screen0_MedButton, currentDrug->drugButtonImg);
                    APP_LE_SETSTRING(Screen0_MedButton, currentDrug->drugString);

                    volumeLeft = currentDrug->mlVol;

                    APP_SetVolLeftLabel(volumeLeft);
                    APP_SetVolumeLabel(currentDrug->mlVol);

                    timeTicks = 0;
                    timeRemainingTicks = DEF_TIME_TICKS_LEFT;

                    APP_GetTimeFromSecs(&hr, &min, &sec, timeTicks);
                    APP_SetTimeElapsedLabel(hr, min, sec);

                    APP_GetTimeFromSecs(&hr, &min, &sec, timeRemainingTicks);
                    APP_SetTimeLeftLabel(hr, min, sec);

                    volumeTickValue = ((double) volumeLeft / (double) timeRemainingTicks);
                
                    appScreenState = APP_SCREEN_SHOW_DRUG_MAIN;
                }
            }
            
            APP_ClearEvents();
            
            break;
        }
        /* Process touch move/slide event on main menu screen */
        case APP_SCREEN_SLIDE_MOVE:
        {
            static int lastDeltaPos = 0;

            /* If touch was released after move, transition to snap state */
            if (APP_GetEvent(APP_SCREEN_EVT_TOUCH_UP) || APP_GetEvent(APP_SCREEN_EVT_TOUCH_DOWN))
            {
                /* Determine if previously moving left or right, and transition to 
                   appropriate snap direction */
                if (lastDeltaPos > 0)
                    appScreenState = APP_SCREEN_SLIDE_SNAP_RIGHT;
                else
                    appScreenState = APP_SCREEN_SLIDE_SNAP_LEFT;
                
                APP_ClearEvents();
            }
            /* Move meds menu screen using gfx canvas based on touch delta x */
            else if (deltaPos != 0)
            {
#ifdef SLIDE_ON_MOVE                
                int x, y, newPos;
                
                gfxcGetWindowPosition(APP_SCREEN_CANVAS_MEDSMENU, &x, &y);
#ifdef MGS_SIM
                newPos = x + deltaPos;

                if (newPos < 0 && newPos > -680)
                {
                    gfxcSetWindowPosition(APP_SCREEN_CANVAS_MEDSMENU, newPos, y);

                    gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id);     
                }
#else                
                newPos = y + deltaPos;

                if (newPos < 0 && newPos > -680)
                {
                    gfxcSetWindowPosition(APP_SCREEN_CANVAS_MEDSMENU, x, newPos);

                    gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id);     
                }
#endif                
#endif                    

                lastDeltaPos = deltaPos;
                
                deltaPos = 0;
            }

            break;
        }
        /* Slide and snap screen to right */
        case APP_SCREEN_SLIDE_SNAP_RIGHT:
        {
            int x, y;
            
            gfxcGetWindowPosition(APP_SCREEN_CANVAS_MEDSMENU, &x, &y);

#ifdef MGS_SIM
            if (x < 0)
            {
                gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id,
                                    GFXC_FX_MOVE_DEC,
                                    x,
                                    y,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.x,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.y,
                                    LAYER_FX_MOVE_DELTA);
            }
#else            
            if (y < 0 )
            {
                gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id,
                                    GFXC_FX_MOVE_DEC,
                                    x,
                                    y,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.x,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.y,
                                    LAYER_FX_MOVE_DELTA);
            }
#endif            
            
            appScreenState = APP_SCREEN_WAIT_SCREEN;
            appNextScreenState = APP_SCREEN_IDLE_MAIN_0;
            
            break;
        }
        /* Slide and snap screen to left */
        case APP_SCREEN_SLIDE_SNAP_LEFT:
        {
            int x, y;
            
            gfxcGetWindowPosition(APP_SCREEN_CANVAS_MEDSMENU, &x, &y);
#ifdef MGS_SIM
            if (x > -680 )
            {
                gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id,
                                    GFXC_FX_MOVE_DEC,
                                    x,
                                    y,
                                    -680,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.y,
                                    LAYER_FX_MOVE_DELTA);
            }
#else
            if (y > -680 )
            {
                gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id,
                                    GFXC_FX_MOVE_DEC,
                                    x,
                                    y,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].showPos.x,
                                    -680,
                                    LAYER_FX_MOVE_DELTA);
            }
#endif            
            
            appScreenState = APP_SCREEN_WAIT_SCREEN;
            appNextScreenState = APP_SCREEN_IDLE_MAIN_1;
            
            break;
        }
        /* Holding state while waiting for screen canvas animation to complete */
        case APP_SCREEN_WAIT_SCREEN:
        {
            if (APP_ScreenCanvasEffectIdle() == true)
            {
                appScreenState = appNextScreenState;
            }
            
            break;
        }
        /* Once a drug is selected, show drug screen */
        case APP_SCREEN_SHOW_DRUG_MAIN:
        {
            if (APP_ScreenCanvasEffectIdle() == true)
            {
                int x, y;
                
                /* slide the main menu and drug menu canvas out of view and show the drug screen */
                gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].id,
                                    GFXC_FX_MOVE_DEC,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].showPos.x,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].showPos.y,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].hidePos.x,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MAINMENU].hidePos.y,                    
                                    LAYER_FX_MOVE_DELTA);

                gfxcGetWindowPosition(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id, &x, &y);
                
                gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].id,
                                    GFXC_FX_MOVE_DEC,
                                    x,
                                    y,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].hidePos.x,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_MEDSMENU].hidePos.y,                    
                                    LAYER_FX_MOVE_DELTA);   



                appScreenState = APP_SCREEN_WAIT_SCREEN;
                appNextScreenState = APP_SCREEN_DRUG_MAIN_READY;
            }
            
            break;
        }
        /* Initialize the drug main screen */
        case APP_SCREEN_DRUG_MAIN_READY:
        {
            /* Enable touch on drug main screen */
            APP_LE_ENABLE_TOUCH(Screen0_DrugScreenPanel, LE_TRUE);
            
            /* Initialize start/stop buttons */
            Screen0_StartButtonAnim->fn->showImage(Screen0_StartButtonAnim, 0);
            Screen0_StartButtonAnim->fn->setVisible(Screen0_StartButtonAnim, LE_TRUE);
                
            Screen0_StopButtonAnim->fn->showImage(Screen0_StopButtonAnim, 0);
            Screen0_StopButtonAnim->fn->setVisible(Screen0_StopButtonAnim, LE_FALSE);            
            
            appScreenState = APP_SCREEN_IDLE_DRUG_MAIN;
            break;
        }
        /* Drug main screen idle state */
        case APP_SCREEN_IDLE_DRUG_MAIN:
        {
#ifdef GLOW_START            
            //Start button animation
            if (appScreenLastTick != appScreenTick)
            {
                Screen0_StartButtonAnim->fn->showNextImage(Screen0_StartButtonAnim);
                appScreenLastTick = appScreenTick;
            } 
#endif            
            /* Check for events */
            if (APP_GetEvent(APP_SCREEN_EVT_BACK))
            {
                /* Disable touch on drug screen and go back to main menu */
                APP_LE_ENABLE_TOUCH(Screen0_DrugScreenPanel, LE_FALSE);
                
                appScreenState = APP_SCREEN_SHOW_MAINMENU;
            }
            else if (APP_GetEvent(APP_SCREEN_EVT_STARTSTOP_PRESSED))
            {
                /* Start pump */
                Screen0_StartButtonAnim->fn->showImage(Screen0_StartButtonAnim, 0);
                
                appScreenState = APP_SCREEN_PREP_DRUG_START;
            }
            else if (APP_GetEvent(APP_SCREEN_EVT_INPUT_NUM_START))
            {
                /* Start numpad input */
                appScreenState = APP_SCREEN_SHOW_INPUT_NUM;
            }
            else if (APP_GetEvent(APP_SCREEN_EVT_INPUT_NUM_DOWN))
            {
                /* Start down button input */
                appScreenState = APP_SCREEN_INPUT_ADJ_DOWN;
            }
            else if (APP_GetEvent(APP_SCREEN_EVT_INPUT_NUM_UP))
            {
                /* Start up button input */
                appScreenState = APP_SCREEN_INPUT_ADJ_UP;
            }
            
            APP_ClearEvents();
            
            break;
        }
        /* Start drug pump */
        case APP_SCREEN_PREP_DRUG_START:
        {
            /* Start button animation */
            if (appScreenLastTick != appScreenTick)
            {
                if (Screen0_StartButtonAnim->fn->getActiveIndex(Screen0_StartButtonAnim) < 4)
                {
                    Screen0_StartButtonAnim->fn->showNextImage(Screen0_StartButtonAnim);
                }
                
                appScreenLastTick = appScreenTick;
            }  
            
            /* When start button is released, switch to pumping GUI state */
            if (APP_GetEvent(APP_SCREEN_EVT_STARTSTOP_RELEASED))
            {
                Screen0_ProgressArrows->fn->showImage(Screen0_ProgressArrows, 0);
                
                /* Toggle start/stop button image to show Stop */
                Screen0_StartButtonAnim->fn->showImage(Screen0_StartButtonAnim, 0);
                Screen0_StartButtonAnim->fn->setVisible(Screen0_StartButtonAnim, LE_FALSE);
                
                Screen0_StopButtonAnim->fn->showImage(Screen0_StopButtonAnim, 0);
                Screen0_StopButtonAnim->fn->setVisible(Screen0_StopButtonAnim, LE_TRUE);
                
                APP_ClearEvents();
                
                timeTicks = 0;

                appScreenState = APP_SCREEN_DRUG_PUMP;
            } 
            
            break;
        }
        /* Pump animation state */
        case APP_SCREEN_DRUG_PUMP:
        {
#ifdef AUTO_PRESSURE_ANIM            
            static uint32_t pressure = PRESSURE_MIN;
            static int32_t delta;            
#endif            
            
            /* Start chevron animation */
            if (appScreenLastTick != appScreenTick)
            {
                uint32_t hr, min, sec;

                Screen0_ProgressArrows->fn->showNextImage(Screen0_ProgressArrows);
                appScreenLastTick = appScreenTick;
                
#ifdef AUTO_PRESSURE_ANIM
                if (timeTicks < timeRemainingTicks)
                {
                    delta = (PRESSURE_MAX_ANIM - pressure)/30;
                    
                    if (delta > 0)
                    {
                        pressure += delta;
                    }
                    else
                    {
                        pressure = (pressure < PRESSURE_MAX_ANIM) ? pressure + 1 : PRESSURE_MAX_ANIM;
                    }
                    
                }
                else
                {
                    delta = (pressure - PRESSURE_MIN)/30;

                    if (delta > 0)
                    {
                        
                        pressure -= delta;
                    }
                    else
                    {
                       pressure = (pressure > PRESSURE_MIN) ? pressure - 1 : PRESSURE_MIN;
                    }
                }
#endif

                /* Update UI based on screen ticks */
                if (appScreenTick % (APP_TIME_TICK_MS/SCREEN_TICK_TIMER_PERIOD_MS))
                {
                    timeTicks++;

                    /* Update time elapsed/left labels */                    
                    APP_GetTimeFromSecs(&hr, &min, &sec, timeTicks);
                    APP_SetTimeElapsedLabel(hr, min, sec);

                    if (timeRemainingTicks > 0)
                    {
                        timeRemainingTicks--;
                        APP_GetTimeFromSecs(&hr, &min, &sec, timeRemainingTicks);
                        APP_SetTimeLeftLabel(hr, min, sec);
                    }

                    /* Update volume left label */
                    volumeLeft = (volumeLeft > volumeTickValue) ?
                                 volumeLeft - volumeTickValue :
                                 0;
                    
                    /* If drug is fully dispensed, show 'success' dialog box */
                    if (volumeLeft == 0)
                    {
                        /* Use canvas to show the success screen */
                        gfxcShowCanvas(appScreenCanvasTable[APP_SCREEN_CANVAS_POPUP_OK].id);
                        gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_POPUP_OK].id);  
                        APP_LE_ENABLE_TOUCH(Screen0_SuccessScreenPanel, LE_TRUE);

                        APP_LE_ENABLE_TOUCH(Screen0_DrugScreenPanel, LE_FALSE);
                        
                        appScreenState = APP_SCREEN_DRUG_PUMP_COMPLETE;

#ifdef AUTO_PRESSURE_ANIM            
                        pressure = PRESSURE_MIN;
#endif
                    }

                    APP_SetVolLeftLabel((uint32_t) volumeLeft);
                }
                
                setPressureValue(pressure);
            }
            
            /* Check if STOP button has been pressed */
            if (APP_GetEvent(APP_SCREEN_EVT_STARTSTOP_PRESSED))
            {
                APP_ClearEvents();
                
                pressure = PRESSURE_MIN;
                
                Screen0_StopButtonAnim->fn->showImage(Screen0_StopButtonAnim, 0);
                
                appScreenState = APP_SCREEN_PREP_DRUG_STOP;
            }   
            
            break;
        }
        /* Pump complete state */
        case APP_SCREEN_DRUG_PUMP_COMPLETE:
        {
            /* Wait for user to close 'success' dialog box */
            if (APP_GetEvent(APP_SCREEN_EVT_SUCCESS_CONFIRM))
            {
                Screen0_ProgressArrows->fn->showImage(Screen0_ProgressArrows, 0);
                
                Screen0_StartButtonAnim->fn->showImage(Screen0_StartButtonAnim, 0);
                Screen0_StartButtonAnim->fn->setVisible(Screen0_StartButtonAnim, LE_TRUE);
                
                Screen0_StopButtonAnim->fn->showImage(Screen0_StopButtonAnim, 0);
                Screen0_StopButtonAnim->fn->setVisible(Screen0_StopButtonAnim, LE_FALSE);
                
                gfxcHideCanvas(appScreenCanvasTable[APP_SCREEN_CANVAS_POPUP_OK].id);
                gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_POPUP_OK].id);  
                APP_LE_ENABLE_TOUCH(Screen0_SuccessScreenPanel, LE_FALSE);
                
                appScreenState = APP_SCREEN_SHOW_MAINMENU;
            }
            break;
        }
        /* Pump was stopped */
        case APP_SCREEN_PREP_DRUG_STOP:
        {
            /* Stop button animation */
            if (appScreenLastTick != appScreenTick)
            {
                if (Screen0_StopButtonAnim->fn->getActiveIndex(Screen0_StopButtonAnim) < 4)
                {
                    Screen0_StopButtonAnim->fn->showNextImage(Screen0_StopButtonAnim);
                }
                
                appScreenLastTick = appScreenTick;
            }
            
            /* Check for stop button to be released */
            if (APP_GetEvent(APP_SCREEN_EVT_STARTSTOP_RELEASED))
            {
                Screen0_ProgressArrows->fn->showImage(Screen0_ProgressArrows, 0);
                
                /* Toggle stop/start button image */
                Screen0_StartButtonAnim->fn->showImage(Screen0_StartButtonAnim, 0);
                Screen0_StartButtonAnim->fn->setVisible(Screen0_StartButtonAnim, LE_TRUE);
                
                Screen0_StopButtonAnim->fn->showImage(Screen0_StopButtonAnim, 0);
                Screen0_StopButtonAnim->fn->setVisible(Screen0_StopButtonAnim, LE_FALSE);
                
                APP_ClearEvents();
                
                /* Go back to main menu */
                appScreenState = APP_SCREEN_IDLE_DRUG_MAIN;
            } 
            
            break;
        }
        /* Show keypad input UI */
        case APP_SCREEN_SHOW_INPUT_NUM:
        {
            /* Check which data to input */
            INPUT_VALUE_ENTRY * valueEntry = APP_GetValueRecord(inputValueEntryId);
            if (valueEntry != NULL)
            {
                leString * textfieldString = (leString *) Screen0_NumEntryTextField->fn->getString(Screen0_NumEntryTextField);

                /* show and slide into view the keypad screen */
                gfxcShowCanvas(appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].id);
                gfxcCanvasUpdate(appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].id);

                gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].id,
                                        GFXC_FX_MOVE_DEC,
                                        appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].hidePos.x,
                                        appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].hidePos.y,                    
                                        appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].showPos.x,
                                        appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].showPos.y,
                                        LAYER_FX_MOVE_DELTA);

                appScreenState = APP_SCREEN_WAIT_SCREEN;
                appNextScreenState = APP_SCREEN_INPUT_NUM_MAIN;

                /* Get the current value and show on the text field */
                textfieldString->fn->setFromString(textfieldString, (*(valueEntry->valueLabel))->string);
                Screen0_NumEntryLabel->fn->setString(Screen0_NumEntryLabel, (*(valueEntry->titleLabel))->fn->getString(*(valueEntry->titleLabel)));
                
                textfieldString->fn->invalidate(textfieldString);
                Screen0_NumEntryTextField->fn->setFocus(Screen0_NumEntryTextField);

                APP_LE_ENABLE_TOUCH(Screen0_NumEditPanel, LE_TRUE);
            }
            else
            {
                appScreenState = APP_SCREEN_IDLE_DRUG_MAIN;
            }
            
            break;
        }
        /* Process keypad input UI */
        case APP_SCREEN_INPUT_NUM_MAIN:
        {
            /* Check if 'enter' key was pressed */
            if (APP_GetEvent(APP_SCREEN_EVT_INPUT_NUM_END))
            {
                /* Get the input value from text field */
                INPUT_VALUE_ENTRY * valueEntry = APP_GetValueRecord(inputValueEntryId);
                leString * textfieldString = (leString *) Screen0_NumEntryTextField->fn->getString(Screen0_NumEntryTextField);
                uint32_t i = 0, length;
                char * ptr;

                /* Check if not empty */
                length = textfieldString->fn->length(textfieldString);
                if (length > 0)
                {
                    /* Convert value and update the data label in the drug main screen */
                    valueNumStr[inputValueEntryId].fn->setFromString(&valueNumStr[inputValueEntryId], textfieldString);
                    (*(valueEntry->valueLabel))->fn->setString(*(valueEntry->valueLabel), (leString *) &valueNumStr[inputValueEntryId]);
                    (*(valueEntry->valueLabel))->fn->invalidate(*(valueEntry->valueLabel));

                    for (i = 0; i < textfieldString->fn->length(textfieldString) && i <= CHAR_LIMIT; i++)
                    {
                        
                        inputValueCharBuff[i] = (unsigned char) textfieldString->fn->charAt(textfieldString, i);
                    }

                    inputValueCharBuff[i] = '\0';

                    valueEntry->value = strtoul(inputValueCharBuff, &ptr, 10);

                    /* Special case for VTBI input */
                    if (inputValueEntryId == APP_INPUT_VTBI)
                    {
                        valueNumStr[APP_INPUT_DOSE_MODE].fn->setFromString(&valueNumStr[APP_INPUT_DOSE_MODE], textfieldString);
                        valueNumStr[APP_INPUT_DOSE_MODE].fn->setFont(&valueNumStr[APP_INPUT_DOSE_MODE], (leFont * ) &MedBoldNum);
                        Screen0_DoseModeValueLabel->fn->setString(Screen0_DoseModeValueLabel, (leString *) &valueNumStr[APP_INPUT_DOSE_MODE]);
                        Screen0_DoseModeValueLabel->fn->invalidate(Screen0_DoseModeValueLabel);

                    }
                }
                
                APP_ClearEvents();
                
                appScreenState = APP_SCREEN_HIDE_INPUT_NUM;
            }            
            
            break;
        }
        /* Slide out the numpad screen */
        case APP_SCREEN_HIDE_INPUT_NUM:
        {
            APP_LE_ENABLE_TOUCH(Screen0_NumEditPanel, LE_FALSE);
            
            /* Use canvas to slide out the numpad */
            gfxcStartEffectMove(appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].id,
                                    GFXC_FX_MOVE_DEC,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].showPos.x,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].showPos.y,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].hidePos.x,
                                    appScreenCanvasTable[APP_SCREEN_CANVAS_NUMENTRY].hidePos.y,                    
                                    LAYER_FX_MOVE_DELTA);
            
            /* Wait for canvas to complete and go back to drug idle screen */
            appScreenState = APP_SCREEN_WAIT_SCREEN;
            appNextScreenState = APP_SCREEN_IDLE_DRUG_MAIN;
            
            break;
        }
        /* Handle data up key press */
        case APP_SCREEN_INPUT_ADJ_UP:
        {
            INPUT_VALUE_ENTRY * valueEntry = APP_GetValueRecord(inputValueEntryId);
            if (valueEntry != NULL)
            {
                switch(inputValueEntryId)
                {
                    case APP_INPUT_VTBI:
                    case APP_INPUT_DOSE_RATE:
                    {
                        if (valueEntry->value < 99)
                        {
                            valueEntry->value += 1;

                            snprintf(inputValueCharBuff, CHAR_LIMIT + 1, "%lu", valueEntry->value);

                            valueNumStr[inputValueEntryId].fn->setFromCStr(&valueNumStr[inputValueEntryId], inputValueCharBuff);
                            (*(valueEntry->valueLabel))->fn->setString(*(valueEntry->valueLabel), (leString *) &valueNumStr[inputValueEntryId]);
                            (*(valueEntry->valueLabel))->fn->invalidate(*(valueEntry->valueLabel));

                            if (inputValueEntryId == APP_INPUT_VTBI)
                            {
                                valueNumStr[APP_INPUT_DOSE_MODE].fn->setFromString(&valueNumStr[APP_INPUT_DOSE_MODE], (const leString *) &valueNumStr[inputValueEntryId]);
                                valueNumStr[APP_INPUT_DOSE_MODE].fn->setFont(&valueNumStr[APP_INPUT_DOSE_MODE], (leFont * ) &MedBoldNum);
                                Screen0_DoseModeValueLabel->fn->setString(Screen0_DoseModeValueLabel, (leString *) &valueNumStr[APP_INPUT_DOSE_MODE]);
                                Screen0_DoseModeValueLabel->fn->invalidate(Screen0_DoseModeValueLabel);

                            }
                        }
                        break;
                    }
                    case APP_INPUT_DOSE_MODE:
                    {
                        valueEntry->value = (valueEntry->value <  MAX_DOSE_MODE - 1) ? valueEntry->value + 1 : 0;
                        leString * str = APP_GetDoseModeString(valueEntry->value);
                        Screen0_DoseModeType->fn->setString(Screen0_DoseModeType, str);                        
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }

            appScreenState = APP_SCREEN_IDLE_DRUG_MAIN;

            break;
        }
        /* Handle data down key press */
        case APP_SCREEN_INPUT_ADJ_DOWN:
        {
            INPUT_VALUE_ENTRY * valueEntry = APP_GetValueRecord(inputValueEntryId);
            if (valueEntry != NULL)
            {
                switch(inputValueEntryId)
                {
                    case APP_INPUT_VTBI:
                    case APP_INPUT_DOSE_RATE:
                    {
                        if (valueEntry->value > 2)
                        {
                            valueEntry->value -= 1;

                            snprintf(inputValueCharBuff, CHAR_LIMIT + 1, "%lu", valueEntry->value);

                            valueNumStr[inputValueEntryId].fn->setFromCStr(&valueNumStr[inputValueEntryId], inputValueCharBuff);
                            (*(valueEntry->valueLabel))->fn->setString(*(valueEntry->valueLabel), (leString *) &valueNumStr[inputValueEntryId]);
                            (*(valueEntry->valueLabel))->fn->invalidate(*(valueEntry->valueLabel));

                            if (inputValueEntryId == APP_INPUT_VTBI)
                            {
                                valueNumStr[APP_INPUT_DOSE_MODE].fn->setFromString(&valueNumStr[APP_INPUT_DOSE_MODE], (const leString*) &valueNumStr[inputValueEntryId]);
                                valueNumStr[APP_INPUT_DOSE_MODE].fn->setFont(&valueNumStr[APP_INPUT_DOSE_MODE], (leFont * ) &MedBoldNum);
                                Screen0_DoseModeValueLabel->fn->setString(Screen0_DoseModeValueLabel, (leString *) &valueNumStr[APP_INPUT_DOSE_MODE]);
                                Screen0_DoseModeValueLabel->fn->invalidate(Screen0_DoseModeValueLabel);

                            }                            


                        }
                        break;
                    }
                    case APP_INPUT_DOSE_MODE:
                    {
                        valueEntry->value = (valueEntry->value == 0) ? MAX_DOSE_MODE - 1 : valueEntry->value - 1;
                        leString * str = APP_GetDoseModeString(valueEntry->value);
                        Screen0_DoseModeType->fn->setString(Screen0_DoseModeType, str);
                        Screen0_DoseModeValueLabel->fn->invalidate(Screen0_DoseModeValueLabel);
                        
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }

            appScreenState = APP_SCREEN_IDLE_DRUG_MAIN;

            break;
        }
        default:
            break;
    }
}

/* UI button event handlers. These functions will set the appropriate event 
   flags for the button event */
void event_Screen0_MedButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(APP_SCREEN_EVT_BACK);
}

void event_Screen0_StartStopButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(APP_SCREEN_EVT_STARTSTOP_PRESSED);
}

void event_Screen0_StartStopButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(APP_SCREEN_EVT_STARTSTOP_RELEASED);
}

void event_Screen0_SetWeightButton_OnReleased(leButtonWidget* btn)
{
    
}

void event_Screen0_SetDoseRateButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_DOSE_RATE;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_START);
}

/* User entry numeric keypad event callback function */
void event_Screen0_NumEntryKeypad_OnKeyClick(leKeyPadWidget* wgt, leButtonWidget* cell, uint32_t row, uint32_t col)
{
    /* Enter button */
    if (row == 3 && col == 3) 
    {
        APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_END);
    }
    /* other buttons, make sure that the # of digits don't exceed char limit */
    else
    {
        const leString * textfieldStr = Screen0_NumEntryTextField->fn->getString(Screen0_NumEntryTextField);
        uint32_t length = textfieldStr->fn->length(textfieldStr);

        //limit the length of input string by removing the last character
        if (length >= CHAR_LIMIT)
        {
            textfieldStr->fn->remove((leString *) textfieldStr, length - 1, 1);
        }
    }
}

void event_Screen0_DownDoseRateButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_DOSE_RATE;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_DOWN);
}

void event_Screen0_UpDoseRateButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_DOSE_RATE;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_UP);
}

void event_Screen0_SetVolButton_OnReleased(leButtonWidget* btn)
{
    
}

void event_Screen0_SetConcButton_OnReleased(leButtonWidget* btn)
{
    
}

void event_Screen0_DownDoseModeButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_DOSE_MODE;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_DOWN);
}

void event_Screen0_UpDoseModeButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_DOSE_MODE;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_UP);
}

void event_Screen0_SetVtbiButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_VTBI;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_START);
}

void event_Screen0_DownVtbiButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_VTBI;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_DOWN);
}

void event_Screen0_UpVtbiButton_OnReleased(leButtonWidget* btn)
{
    inputValueEntryId = APP_INPUT_VTBI;
    APP_SetEvent(APP_SCREEN_EVT_INPUT_NUM_UP);
}

void event_Screen0_SuccessConfirmButtonm_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(APP_SCREEN_EVT_SUCCESS_CONFIRM);
}
