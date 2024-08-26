/*******************************************************************************
  Application Header

  File Name:
    app_screen.h

  Summary:
    code for the screen application

  Description:
    code for the screen application
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*****************************************************************************
 Copyright (C) 2012-2018 Microchip Technology Inc. and its subsidiaries.

Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software 
and any derivatives exclusively with Microchip products. It is your 
responsibility to comply with third party license terms applicable to your 
use of third party software (including open source software) that may 
accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR 
PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE 
FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN 
ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, 
THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************/
//DOM-IGNORE-END

#ifndef _APP_SCREEN_H    /* Guard against multiple inclusion */
#define _APP_SCREEN_H

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    
#define SLIDE_ON_MOVE 1
#define AUTO_PRESSURE_ANIM 1
    
#define LAYER_FX_MOVE_DELTA 6
#define LAYER_FX_MOVE_DELTA_FAST 2
#define LAYER_FX_FADE_DELTA 20
    
#define TOUCH_SLIDE_DELTA_PX 10

#define DISPLAY_ROTATE 90
#define DISPLAY_WIDTH 400
#define DISPLAY_HEIGHT 1280    
    
#define SCREEN_TICK_TIMER_PERIOD_MS 100

#define APP_TIME_TICK_MS 300
    
    
#define CHAR_LIMIT 2
#define PRESSURE_MAX_DIGITS 3
#define VOL_MAX_DIGITS 3
#define TIME_MAX_CHARS 8
    
#define CENTERX 186
#define CENTERY 322
#define RADMIN 47
#define RADMAX 157
#define RADMID 117

#define PRESSURE_MIN 30
#define PRESSURE_MAX 400
#define PRESSURE_MAX_ANIM 300

#define MAX_DOSE_MODE 2

#define MAX_VOL 300

#define DEF_TIME_TICKS_LEFT 180 //7200

//These should match the number and order of canvas and composer layers
typedef enum
{
    APP_SCREEN_CANVAS_SPLASH,
    APP_SCREEN_CANVAS_MEDSMENU,
    APP_SCREEN_CANVAS_MAINMENU,
    APP_SCREEN_CANVAS_DRUGMAIN,
    APP_SCREEN_CANVAS_NUMENTRY,
    APP_SCREEN_CANVAS_POPUP_OK,
    APP_SCREEN_CANVAS_MAX,
} APP_SCREEN_CANVAS_ID;

typedef enum
{
    APP_INPUT_WEIGHT,
    APP_INPUT_VOLUME,
    APP_INPUT_DOSE_RATE,
    APP_INPUT_CONCENTRATION,
    APP_INPUT_DOSE_MODE,
    APP_INPUT_VTBI,
    APP_INPUT_MAX,
} APP_INPUT_RECORD_ID;

typedef enum
{
    APP_DRUG_VASOACTIVE,
    APP_DRUG_SEDATIVE,
    APP_DRUG_ANALGESIC,
    APP_DRUG_ANTIARRHYTHMIC,
} APP_DRUG_CATEGORY;

typedef enum
{
    APP_SCREEN_SHOW_SPLASH,
    APP_SCREEN_WAIT_SPLASH,
    APP_SCREEN_DRAW_SCREENS,
    APP_SCREEN_INIT,
    APP_SCREEN_SHOW_MAINMENU,
    APP_SCREEN_SHOW_MAIN,
    APP_SCREEN_MAIN_READY,
    APP_SCREEN_IDLE_MAIN_0,
    APP_SCREEN_IDLE_MAIN_1,
    APP_SCREEN_WAIT_SCREEN,
    APP_SCREEN_SLIDE_MOVE,
    APP_SCREEN_SLIDE_SNAP_RIGHT,
    APP_SCREEN_SLIDE_SNAP_LEFT,
    APP_SCREEN_SHOW_DRUG_MAIN,
    APP_SCREEN_DRUG_MAIN_READY,
    APP_SCREEN_IDLE_DRUG_MAIN,
    APP_SCREEN_PREP_DRUG_START,
    APP_SCREEN_DRUG_PUMP,
    APP_SCREEN_DRUG_PUMP_COMPLETE,
    APP_SCREEN_PREP_DRUG_STOP,
    APP_SCREEN_SHOW_INPUT_NUM,
    APP_SCREEN_INPUT_NUM_MAIN, //22
    APP_SCREEN_HIDE_INPUT_NUM,
    APP_SCREEN_INPUT_ADJ_UP,
    APP_SCREEN_INPUT_ADJ_DOWN,
} APP_SCREEN_STATE;

typedef enum
{
    APP_SCREEN_EVT_TOUCH_DOWN,
    APP_SCREEN_EVT_TOUCH_UP,
    APP_SCREEN_EVT_TOUCH_SLIDE_LEFT,
    APP_SCREEN_EVT_TOUCH_SLIDE_RIGHT,
    APP_SCREEN_EVT_BACK,
    APP_SCREEN_EVT_STARTSTOP_PRESSED,
    APP_SCREEN_EVT_STARTSTOP_RELEASED,
    APP_SCREEN_EVT_SUCCESS_CONFIRM,
    APP_SCREEN_EVT_INPUT_NUM_START,
    APP_SCREEN_EVT_INPUT_NUM_END,  
    APP_SCREEN_EVT_INPUT_NUM_UP,
    APP_SCREEN_EVT_INPUT_NUM_DOWN,
} APP_SCREEN_EVT;

typedef struct
{
    int32_t x;
    int32_t y;
} APP_SCREEN_POINT;

typedef struct
{
    uint32_t width;
    uint32_t height;
} APP_SCREEN_SIZE;

typedef struct
{
    APP_SCREEN_CANVAS_ID id;
    leWidget ** panel;
    uint32_t lcdLayer;
    APP_SCREEN_SIZE size;
    APP_SCREEN_POINT showPos;
    APP_SCREEN_POINT hidePos;
} APP_SCREEN_CANVAS_OBJ;

typedef struct
{
    uint32_t drugIndex;
    leButtonWidget ** button;
    leTableString * drugString;
    leImage * drugButtonImg;
    bool enabled;
    uint32_t category;
    uint32_t mlVol;
} DRUG_DATABASE_ENTRY;

typedef struct
{
    APP_INPUT_RECORD_ID entryId;
    leLabelWidget ** titleLabel;
    leLabelWidget ** valueLabel;
    leFont * font;
    uint32_t value;
} INPUT_VALUE_ENTRY;

DRUG_DATABASE_ENTRY * APP_GetDrugButtonFromPosition(lePoint point);
INPUT_VALUE_ENTRY * APP_GetValueRecord(APP_INPUT_RECORD_ID id);
leString * APP_GetDoseModeString(uint32_t index);
    
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_SCREEN_H */
