/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
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

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   HeadlightOn
 * Size:   41x41 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage HeadlightOn;

/*********************************
 * Legato Image Asset
 * Name:   battery_charging_full
 * Size:   25x25 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage battery_charging_full;

/*********************************
 * Legato Image Asset
 * Name:   turn_left
 * Size:   43x43 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage turn_left;

/*********************************
 * Legato Image Asset
 * Name:   turn_right
 * Size:   43x43 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage turn_right;

/*********************************
 * Legato Image Asset
 * Name:   straigh
 * Size:   30x44 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage straigh;

/*********************************
 * Legato Image Asset
 * Name:   Directions
 * Size:   322x77 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage Directions;

/*********************************
 * Legato Image Asset
 * Name:   leftoff
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage leftoff;

/*********************************
 * Legato Image Asset
 * Name:   lefton
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage lefton;

/*********************************
 * Legato Image Asset
 * Name:   rightoff
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage rightoff;

/*********************************
 * Legato Image Asset
 * Name:   righton
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage righton;

/*********************************
 * Legato Image Asset
 * Name:   FuelOff
 * Size:   40x40 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage FuelOff;

/*********************************
 * Legato Image Asset
 * Name:   FuelOn
 * Size:   40x40 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage FuelOn;

/*********************************
 * Legato Image Asset
 * Name:   warningoff
 * Size:   40x40 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage warningoff;

/*********************************
 * Legato Image Asset
 * Name:   warningon
 * Size:   40x40 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage warningon;

/*********************************
 * Legato Image Asset
 * Name:   gray_bar
 * Size:   168x8 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage gray_bar;

/*********************************
 * Legato Image Asset
 * Name:   green_bar
 * Size:   168x8 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage green_bar;

/*********************************
 * Legato Image Asset
 * Name:   speedo_back
 * Size:   720x720 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage speedo_back;

/*********************************
 * Legato Image Asset
 * Name:   speed_front
 * Size:   720x720 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage speed_front;

/*********************************
 * Legato Image Asset
 * Name:   mchp_logo
 * Size:   293x40 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage mchp_logo;

/*********************************
 * Legato Image Asset
 * Name:   logo_horizontal_small
 * Size:   117x17 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage logo_horizontal_small;

/*********************************
 * Legato Image Asset
 * Name:   MGS_85_White
 * Size:   316x85 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage MGS_85_White;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         DistanceFont
 * Height:       21
 * Baseline:     18
 * Style:        Antialias
 * Glyph Count:  22
 * Range Count:  13
 * Glyph Ranges: 0x20
                 0x2E
                 0x30-0x39
                 0x4D
                 0x53
                 0x65
                 0x69
                 0x6C
                 0x6F-0x70
                 0x72-0x74
***********************************/
extern leRasterFont DistanceFont;

/*********************************
 * Legato Font Asset
 * Name:         SpeedoFont
 * Height:       21
 * Baseline:     115
 * Style:        Antialias
 * Glyph Count:  10
 * Range Count:  3
 * Glyph Ranges: 0x30-0x39
***********************************/
extern leRasterFont SpeedoFont;

/*********************************
 * Legato Font Asset
 * Name:         DirectionFont
 * Height:       23
 * Baseline:     19
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  17
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont DirectionFont;

/*********************************
 * Legato Font Asset
 * Name:         GearNumFont
 * Height:       21
 * Baseline:     54
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  2
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont GearNumFont;

/*********************************
 * Legato Font Asset
 * Name:         mphFont
 * Height:       21
 * Baseline:     25
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  4
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont mphFont;

/*********************************
 * Legato Font Asset
 * Name:         Font0
 * Height:       37
 * Baseline:     12
 * Style:        Antialias
 * Glyph Count:  96
 * Range Count:  7
 * Glyph Ranges: 0xA
                 0x20-0x7E
***********************************/
extern leRasterFont Font0;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   15
 *****************************************************************************/

// language IDs
#define language_English    0

// string IDs
#define stringID_DistanceStringContinue    0
#define stringID_DirectionStringLeft    1
#define stringID_DirectionStringContinue    2
#define stringID_ModeString    3
#define stringID_MPH_Default    4
#define stringID_RPMString    5
#define stringID_DistanceStringLeft    6
#define stringID_DirectionStringRight    7
#define stringID_RangeValueString    8
#define stringID_GearNumber    9
#define stringID_DistanceStringRight    10
#define stringID_mphString    11
#define stringID_DemoOff    12
#define stringID_DemoOn    13
#define stringID_RangeUnitString    14

extern const leStringTable stringTable;


// string list
extern leTableString string_DistanceStringContinue;
extern leTableString string_DirectionStringLeft;
extern leTableString string_DirectionStringContinue;
extern leTableString string_ModeString;
extern leTableString string_MPH_Default;
extern leTableString string_RPMString;
extern leTableString string_DistanceStringLeft;
extern leTableString string_DirectionStringRight;
extern leTableString string_RangeValueString;
extern leTableString string_GearNumber;
extern leTableString string_DistanceStringRight;
extern leTableString string_mphString;
extern leTableString string_DemoOff;
extern leTableString string_DemoOn;
extern leTableString string_RangeUnitString;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
