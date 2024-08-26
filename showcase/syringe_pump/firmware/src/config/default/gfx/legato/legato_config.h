/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_config.h

  Summary:
    Autogenerated configuration file for the Legato graphics library.


  Description:
    Autogenerated configuration file for the Legato graphics library.

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

#ifndef LE_CONFIG_H
#define LE_CONFIG_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END


#include <toolchain_specifics.h>

#define LE_COHERENT_ATTR                     CACHE_ALIGN
#define LE_COHERENT_MEMORY                   LE_COHERENT_ATTR


#define LE_DEFAULT_COLOR_MODE                LE_COLOR_MODE_RGBA_8888
#define LE_TOUCH_ORIENTATION                 0
#define LE_RENDER_ORIENTATION                90
#define LE_DRIVER_LAYER_MODE                 1
#define LE_DYNAMIC_VTABLES                   0

#define LE_ASSERT_ENABLE                     0
#define LE_DEBUG                             0 // internal use only, do not change
#define LE_DEBUG_RENDERER                    0 // internal use only, do not change

// image decoder configuration
#define LE_ENABLE_RAW_DECODER                1
#define LE_ENABLE_JPEG_DECODER               1
#define LE_ENABLE_PNG_DECODER                1
#define LE_PNG_USE_SCRATCH                   0
#define LE_ENABLE_MONO_DECODER               1

#define LE_PREEMPTION_LEVEL                  0
#define LE_STREAMING_ENABLED                 0

#if LE_STREAMING_ENABLED == 1
#define LE_ASSET_DECODER_PIXEL_CACHE_SIZE    128
#define LE_ASSET_DECODER_PALETTE_CACHE_SIZE  128
#define LE_ASSET_DECODER_MASK_CACHE_SIZE     128
#define LE_ASSET_DECODER_BLEND_CACHE_SIZE    128
#define LE_JPEG_DECODER_CACHE_SIZE           2048
#define LE_RASTERFONT_GLYPH_CACHE_SIZE       256
#endif

// default Font Support
#define LE_INCLUDE_DEFAULT_1BPP_FONT         0
#define LE_INCLUDE_DEFAULT_8BPP_FONT         0

// widget inclusion
#define LE_ARC_WIDGET_ENABLED              0
#define LE_BARGRAPH_WIDGET_ENABLED         0
#define LE_BUTTON_WIDGET_ENABLED           1
#define LE_CHECKBOX_WIDGET_ENABLED         0
#define LE_CIRCLE_WIDGET_ENABLED           0
#define LE_CIRCULARGAUGE_WIDGET_ENABLED    0
#define LE_CIRCULARSLIDER_WIDGET_ENABLED   0
#define LE_DRAWSURFACE_WIDGET_ENABLED      0
#define LE_GRADIENT_WIDGET_ENABLED         0
#define LE_GROUPBOX_WIDGET_ENABLED         0
#define LE_IMAGE_WIDGET_ENABLED            1
#define LE_IMAGEROTATE_WIDGET_ENABLED      0
#define LE_IMAGESCALE_WIDGET_ENABLED       0
#define LE_IMAGESEQUENCE_WIDGET_ENABLED    1
#define LE_KEYPAD_WIDGET_ENABLED           1
#define LE_LABEL_WIDGET_ENABLED            1
#define LE_LINE_WIDGET_ENABLED             0
#define LE_LINEGRAPH_WIDGET_ENABLED        0
#define LE_LIST_WIDGET_ENABLED             0
#define LE_LISTWHEEL_WIDGET_ENABLED        0
#define LE_PIECHART_WIDGET_ENABLED         0
#define LE_PROGRESSBAR_WIDGET_ENABLED      0
#define LE_RADIALMENU_WIDGET_ENABLED       0
#define LE_RADIOBUTTON_WIDGET_ENABLED      0
#define LE_RECTANGLE_WIDGET_ENABLED        0
#define LE_SCROLLBAR_WIDGET_ENABLED        0
#define LE_SLIDER_WIDGET_ENABLED           0
#define LE_TEXTFIELD_WIDGET_ENABLED        1
#define LE_TOUCHTEST_WIDGET_ENABLED        0
#define LE_WINDOW_WIDGET_ENABLED           0

// memory configuration
#define LE_MEMORY_MANAGER_ENABLE           1
#define LE_USE_DEBUG_ALLOCATOR             0
#define LE_MALLOC_ZEROIZE                  0

#define LE_USE_ALLOCATION_TRACKING         0

// variable heap configuration
#define LE_VARIABLEHEAP_DEBUGLEVEL         0
#define LE_VARIABLEHEAP_SIZE               524288
#define LE_VARIABLEHEAP_MINALLOCSIZE       32
#define LE_VARIABLEHEAP_ALIGNMENT          4
#define LE_VARIABLEHEAP_BESTFIT            1

// fixed heap configuration
#define LE_FIXEDHEAP_ENABLE                1
#define LE_FIXEDHEAP_DEBUG                 0
#define LE_FIXEDHEAP_SIZE_16               400
#define LE_FIXEDHEAP_SIZE_32               380
#define LE_FIXEDHEAP_SIZE_64               300
#define LE_FIXEDHEAP_SIZE_128              200
#define LE_FIXEDHEAP_SIZE_196              150
#define LE_FIXEDHEAP_SIZE_256              150

// renderer configuration
//#define LE_VSYNC_STALL

#define LE_LAYER_COUNT                     6

#define LE_WIDGET_MAX_EVENT_FILTERS        2

// renderer config
#define LE_ALPHA_BLENDING_ENABLED          1
#define LE_SCRATCH_BUFFER_COUNT            1
#define LE_SCRATCH_BUFFER_SIZE_KB          2048
#define LE_SCRATCH_BUFFER_PADDING          0
#define LE_SCRATCH_BIG_ENDIAN              0
#define LE_USE_ARC_SCAN_FILL               1
#define LE_ARC_SMOOTH_EDGE                 LE_FALSE

#define LE_MONOCHROME_ON                   1


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_CONFIG_H
