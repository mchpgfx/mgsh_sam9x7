/*******************************************************************************
 Multi interface application file

  Company:
    Microchip Technology Inc.

  File Name:
    app_multi_intf.c

  Summary:
    This file provides multiple display interface support for a display using the 
    on-chip display controller and 3x external controller based displays.

  Description:
 * Creates a custom display interface for the MGS library for supporting multiple
 * displays. This overrides the default display interfaces and provides a way
 * to direct layer-specific calls from the library to a specific display. For this
 * specific application, layers 0 - 2 are for the 3x SPI displays and layer 3 is 
 * for the display thru the XLCDC controller, which is LVDS for this example.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2025 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/interface/drv_gfx_disp_intf.h"
#include "gfx/driver/controller/external_controller/drv_gfx_external_controller.h"
#include "gfx/driver/controller/xlcdc/drv_gfx_xlcdc.h"
#include "system/time/sys_time.h"

#define MAX_DISPLAY_WIDTH 800
#define MAX_DISPLAY_HEIGHT 480

typedef enum
{
    DISPLAY_EXT_0 = 0,
    DISPLAY_EXT_1,
    DISPLAY_EXT_2,
    DISPLAY_XLCDC,
    TOTAL_DISPLAY_LAYERS,
} DISPLAY_LAYER_ID;

static uint32_t activeLayer = 0;

/* This provides a multi-display interface for the blit buffer function */
gfxResult DRV_MultiInterface_BlitBuffer(int32_t x,
                                     int32_t y,
                                     gfxPixelBuffer* buf)
{
    switch (activeLayer)
    {
        /* Layers 0 - 2 for 3x displays with external controller */
        case DISPLAY_EXT_0:
        case DISPLAY_EXT_1:
        case DISPLAY_EXT_2:
        {

            gfxDriverEXTInterface.blitBuffer(x, y, buf);
            break;
        }
        /* Layer 3 for 1x display using XLCDC display controller */
        case DISPLAY_XLCDC:
        {
            gfxDriverXLCDCInterface.blitBuffer(x, y, buf);
            break;
        }
        default:
            break;
    }
    
    return GFX_SUCCESS;
}

gfxDriverIOCTLResponse DRV_MultiInterface_IOCTL(
                                    gfxDriverIOCTLRequest request,
                                    void* arg)
{
    gfxIOCTLArg_Value* val;
    
    switch(request)
    {
        case GFX_IOCTL_GET_COLOR_MODE:
        case GFX_IOCTL_GET_BUFFER_COUNT:
        {
            return (activeLayer == DISPLAY_XLCDC) ?
                    gfxDriverXLCDCInterface.ioctl(request, arg) :
                    gfxDriverEXTInterface.ioctl(request, arg);
        }
        case GFX_IOCTL_GET_DISPLAY_SIZE:
        {
            gfxIOCTLArg_DisplaySize * disp = (gfxIOCTLArg_DisplaySize*)arg;

            /* give the max display size */
            disp->width = MAX_DISPLAY_WIDTH;
            disp->height = MAX_DISPLAY_HEIGHT;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_ACTIVE_LAYER:
        {
            val = (gfxIOCTLArg_Value *)arg;

            activeLayer = val->value.v_uint;
            
            if (activeLayer == DISPLAY_XLCDC)
            {
                /* offset layer value for XLCDC */
                val->value.v_uint = val->value.v_uint - DISPLAY_XLCDC;
                
                gfxDriverXLCDCInterface.ioctl(request, arg);
            }
            else
            {
                val->value.v_uint = val->value.v_uint;
                
                return gfxDriverEXTInterface.ioctl(request, arg);
            }    
            
            
            break;
        }        
        case GFX_IOCTL_GET_LAYER_COUNT:
        {
            val = (gfxIOCTLArg_Value*)arg;

            val->value.v_uint = LE_LAYER_COUNT;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_ACTIVE_LAYER:
        {
            val = (gfxIOCTLArg_Value*)arg;

            val->value.v_uint = activeLayer;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_LAYER_LOCK:
        case GFX_IOCTL_GET_LAYER_ENABLED:
        case GFX_IOCTL_SET_LAYER_ENABLED:
        case GFX_IOCTL_SET_LAYER_UNLOCK:
        case GFX_IOCTL_GET_LAYER_RECT:
        case GFX_IOCTL_SET_LAYER_POSITION:
        case GFX_IOCTL_SET_LAYER_SIZE:
        case GFX_IOCTL_SET_LAYER_WINDOW_SIZE:
        case GFX_IOCTL_SET_LAYER_ALPHA:
        case GFX_IOCTL_SET_LAYER_BASE_ADDRESS:
        case GFX_IOCTL_SET_LAYER_COLOR_MODE:
        {
            gfxIOCTLArg_LayerArg * layer = (gfxIOCTLArg_LayerArg * ) arg;
            switch(layer->id)
            {
                case DISPLAY_EXT_0:
                case DISPLAY_EXT_1:
                case DISPLAY_EXT_2:
                {
                    return gfxDriverEXTInterface.ioctl(request, arg);
                }
                case DISPLAY_XLCDC:
                {
                    /* offset layer */
                    layer->id = layer->id - DISPLAY_XLCDC;

                    return gfxDriverXLCDCInterface.ioctl(request, arg);
                }
                default:
                    break;
            }
            break;
        }
        default:
        { 
            break;
        }
    }    
    
    return GFX_IOCTL_UNSUPPORTED;
}

void DRV_MultiInterface_Update(void)
{
    DRV_XLCDC_Update();
    DRV_ExternalController_Update();
}

const gfxDisplayDriver gfxDriverMultiInterface =
{
    .update = DRV_MultiInterface_Update,				       
    .blitBuffer = DRV_MultiInterface_BlitBuffer,			   
	.ioctl = DRV_MultiInterface_IOCTL,                
};
