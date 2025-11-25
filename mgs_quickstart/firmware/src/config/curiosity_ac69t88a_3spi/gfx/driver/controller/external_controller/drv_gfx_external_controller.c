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

/*******************************************************************************
  Custom ExternalControllerDisplay Top-Level Driver Source File

  File Name:
    drv_gfx_custom_external.c

  Summary:
    Top level driver for ExternalController.

  Description:
    Build-time generated implementation for the ExternalControllerDriver.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/




#include "definitions.h"

#include "gfx/interface/drv_gfx_disp_intf.h"
#include "drv_gfx_external_controller.h"

#include "system/time/sys_time.h"

// Default max width/height of ExternalControllerframe
#define DISPLAY_DEFAULT_WIDTH   480
#define DISPLAY_DEFAULT_HEIGHT  800

#define DISPLAY_WIDTH   240
#define DISPLAY_HEIGHT  240

#define PIXEL_BUFFER_COLOR_MODE GFX_COLOR_MODE_RGB_565
#define SCREEN_WIDTH DISPLAY_WIDTH
#define SCREEN_HEIGHT DISPLAY_HEIGHT

#ifdef GFX_DISP_INTF_PIN_RESET_Clear
#define DRV_ExternalController_Reset_Assert()      GFX_DISP_INTF_PIN_RESET_Clear()
#define DRV_ExternalController_Reset_Deassert()    GFX_DISP_INTF_PIN_RESET_Set()
#else
#error "ERROR: GFX_DISP_INTF_PIN_RESET not defined. Please define in Pin Manager."
#define DRV_ExternalController_Reset_Assert()
#define DRV_ExternalController_Reset_Deassert()
#endif


#define DISPLAY_COUNT 3

#define PIXEL_BUFFER_BYTES_PER_PIXEL 2

typedef enum
{
    INIT = 0,
    RUN,
    ERROR,
} DRV_STATE;

typedef struct ILI9488_DRV
{
    /* Driver state */
    DRV_STATE state;

    /* Port-specific private data */
    void *port_priv;
} ExternalController_DRV;

ExternalController_DRV drv;

static uint32_t activeDisplay = 0;

static uint32_t swapCount = 0;


/* ************************************************************************** */

/**
  Function:
    static void DRV_ExternalController_DelayMS(int ms)

  Summary:
    Delay helper function.

  Description:
    This is a helper function for delay using the system tick timer.

  Parameters:
    ms      - Delay in milliseconds

  Returns:
    None.

*/

static inline void DRV_ExternalController_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}

/**
  Function:
    static void DRV_ExternalController_Reset(void)

  Summary:
    Toggles the hardware reset to the ExternalController.

  Description:
    This function toggles the GPIO pin for asserting reset to the ExternalController.

  Parameters:
    None

  Returns:
    None

*/
static void DRV_ExternalController_Reset(void)
{
    DRV_ExternalController_Reset_Assert();
    DRV_ExternalController_DelayMS(10);
    DRV_ExternalController_Reset_Deassert();
    DRV_ExternalController_DelayMS(10);
}

int DRV_ExternalController_Initialize(void)
{
    drv.state = INIT;

    return 0;
}

static int DRV_ExternalController_Configure(ExternalController_DRV *drvPtr)
{
    GFX_Disp_Intf intf = (GFX_Disp_Intf) drvPtr->port_priv;
    uint8_t cmd;
    uint8_t parms[16];

    GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS, GFX_DISP_INTF_PIN_CLEAR);
    GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS1, GFX_DISP_INTF_PIN_CLEAR);
    GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS2, GFX_DISP_INTF_PIN_CLEAR);

    cmd = 0xef;
    GFX_Disp_Intf_WriteCommand(intf, cmd);

    cmd = 0xeb;
    parms[0] = 0x14;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xfe;
    GFX_Disp_Intf_WriteCommand(intf, cmd);

    cmd = 0xef;
    GFX_Disp_Intf_WriteCommand(intf, cmd);

    cmd = 0xeb;
    parms[0] = 0x14;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x84;
    parms[0] = 0x40;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x85;
    parms[0] = 0xff;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x86;
    parms[0] = 0xff;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x87;
    parms[0] = 0xff;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x88;
    parms[0] = 0xa;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x89;
    parms[0] = 0x21;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x8a;
    parms[0] = 0x0;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x8b;
    parms[0] = 0x80;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x8c;
    parms[0] = 0x1;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x8d;
    parms[0] = 0x1;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x8e;
    parms[0] = 0xff;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x8f;
    parms[0] = 0xff;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xb6;
    parms[0] = 0x0;
    parms[1] = 0x20;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 2);

    cmd = 0x36;
    parms[0] = 0x5e;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x3a;
    parms[0] = 0x5;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x90;
    parms[0] = 0x8;
    parms[1] = 0x8;
    parms[2] = 0x8;
    parms[3] = 0x8;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 4);

    cmd = 0xbd;
    parms[0] = 0x6;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xbc;
    parms[0] = 0x0;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xff;
    parms[0] = 0x60;
    parms[1] = 0x1;
    parms[2] = 0x4;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 3);

    cmd = 0xc3;
    parms[0] = 0x13;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xc4;
    parms[0] = 0x13;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xc9;
    parms[0] = 0x22;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xbe;
    parms[0] = 0x11;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xe1;
    parms[0] = 0x10;
    parms[1] = 0xe;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 2);

    cmd = 0xdf;
    parms[0] = 0x21;
    parms[1] = 0xc;
    parms[2] = 0x2;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 3);

    cmd = 0xf0;
    parms[0] = 0x45;
    parms[1] = 0x9;
    parms[2] = 0x8;
    parms[3] = 0x8;
    parms[4] = 0x26;
    parms[5] = 0x2a;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 6);

    cmd = 0xf1;
    parms[0] = 0x43;
    parms[1] = 0x70;
    parms[2] = 0x72;
    parms[3] = 0x36;
    parms[4] = 0x37;
    parms[5] = 0x6f;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 6);

    cmd = 0xf2;
    parms[0] = 0x45;
    parms[1] = 0x9;
    parms[2] = 0x8;
    parms[3] = 0x8;
    parms[4] = 0x26;
    parms[5] = 0x2a;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 6);

    cmd = 0xf3;
    parms[0] = 0x43;
    parms[1] = 0x70;
    parms[2] = 0x72;
    parms[3] = 0x36;
    parms[4] = 0x37;
    parms[5] = 0x6f;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 6);

    cmd = 0xed;
    parms[0] = 0x1b;
    parms[1] = 0xb;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 2);

    cmd = 0xae;
    parms[0] = 0x77;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0xcd;
    parms[0] = 0x63;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x70;
    parms[0] = 0x7;
    parms[1] = 0x7;
    parms[2] = 0x4;
    parms[3] = 0xe;
    parms[4] = 0xf;
    parms[5] = 0x9;
    parms[6] = 0x7;
    parms[7] = 0x8;
    parms[8] = 0x3;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 9);

    cmd = 0xe8;
    parms[0] = 0x34;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    cmd = 0x62;
    parms[0] = 0x18;
    parms[1] = 0xd;
    parms[2] = 0x71;
    parms[3] = 0xed;
    parms[4] = 0x70;
    parms[5] = 0x70;
    parms[6] = 0x18;
    parms[7] = 0xf;
    parms[8] = 0x71;
    parms[9] = 0xef;
    parms[10] = 0x70;
    parms[11] = 0x70;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 12);

    cmd = 0x63;
    parms[0] = 0x18;
    parms[1] = 0x11;
    parms[2] = 0x71;
    parms[3] = 0xf1;
    parms[4] = 0x70;
    parms[5] = 0x70;
    parms[6] = 0x18;
    parms[7] = 0x13;
    parms[8] = 0x71;
    parms[9] = 0xf3;
    parms[10] = 0x70;
    parms[11] = 0x70;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 12);

    cmd = 0x64;
    parms[0] = 0x28;
    parms[1] = 0x29;
    parms[2] = 0xf1;
    parms[3] = 0x1;
    parms[4] = 0xf1;
    parms[5] = 0x0;
    parms[6] = 0x7;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 7);

    cmd = 0x66;
    parms[0] = 0x3c;
    parms[1] = 0x0;
    parms[2] = 0xcd;
    parms[3] = 0x67;
    parms[4] = 0x45;
    parms[5] = 0x45;
    parms[6] = 0x10;
    parms[7] = 0x0;
    parms[8] = 0x0;
    parms[9] = 0x0;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 10);

    cmd = 0x67;
    parms[0] = 0x0;
    parms[1] = 0x3c;
    parms[2] = 0x0;
    parms[3] = 0x0;
    parms[4] = 0x0;
    parms[5] = 0x1;
    parms[6] = 0x54;
    parms[7] = 0x10;
    parms[8] = 0x32;
    parms[9] = 0x98;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 10);

    cmd = 0x74;
    parms[0] = 0x10;
    parms[1] = 0x85;
    parms[2] = 0x80;
    parms[3] = 0x0;
    parms[4] = 0x0;
    parms[5] = 0x4e;
    parms[6] = 0x0;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 7);

    cmd = 0x98;
    parms[0] = 0x3e;
    parms[1] = 0x7;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 2);

    cmd = 0x35;
    GFX_Disp_Intf_WriteCommand(intf, cmd);

    cmd = 0x21;
    GFX_Disp_Intf_WriteCommand(intf, cmd);

    cmd = 0x11;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    DRV_ExternalController_DelayMS(120);

    cmd = 0x29;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    DRV_ExternalController_DelayMS(20);


    GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS, GFX_DISP_INTF_PIN_SET);
    GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS1, GFX_DISP_INTF_PIN_SET);
    GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS2, GFX_DISP_INTF_PIN_SET);

    return 0;
}


/**
  Function:
    static void DRV_ExternalController_Update(void)

  Summary:
    Driver-specific implementation of GFX HAL update function.

  Description:
    On GFX update, this function flushes any pending pixels to the ExternalController.

  Parameters:
    None.

  Returns:
    * GFX_SUCCESS       - Operation successful
    * GFX_FAILURE       - Operation failed

*/
void DRV_ExternalController_Update(void)
{
    uint32_t openVal;

    if(drv.state == INIT)
    {
        openVal = GFX_Disp_Intf_Open();

        drv.port_priv = (void *)openVal;

        if (drv.port_priv == 0)
        {
            drv.state = ERROR;
            return;
        }

        DRV_ExternalController_Reset();

        DRV_ExternalController_Configure(&drv);

        drv.state = RUN;
    }
}



gfxResult DRV_ExternalController_BlitBuffer(int32_t x,
                                           int32_t y,
                                           gfxPixelBuffer* buf)
{
/* Custom code - do not modify/remove */     
    uint8_t parm[4];
/* Custom code - do not modify/remove */    

    GFX_Disp_Intf intf;

    if (drv.state != RUN)
        return GFX_FAILURE;

    intf = (GFX_Disp_Intf) drv.port_priv;

    switch(activeDisplay)
    {
        case 0:
        {
            GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS, GFX_DISP_INTF_PIN_CLEAR);
            
            break;
        }
        case 1:
        {
            GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS1, GFX_DISP_INTF_PIN_CLEAR);
            
            break;
        }
        case 2:
        {
            GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS2, GFX_DISP_INTF_PIN_CLEAR);
            
            break;
        }
        default:
        {
            return GFX_SUCCESS;
        }
    }

    //Write X/Column Address
    parm[0] = x>>8;
    parm[1] = x;
    parm[2] = (x + buf->size.width - 1) >>8;
    parm[3] = (x + buf->size.width - 1);
    GFX_Disp_Intf_WriteCommand(intf, 0x2a);
    GFX_Disp_Intf_WriteData(intf, parm, 4);

    //Write Y/Page Address
    parm[0] = y>>8;
    parm[1] = y;
    parm[2] = (y + buf->size.height - 1)>>8;
    parm[3] = (y + buf->size.height - 1);
    GFX_Disp_Intf_WriteCommand(intf, 0x2b);
    GFX_Disp_Intf_WriteData(intf, parm, 4);

    //Start Memory Write
    GFX_Disp_Intf_WriteCommand(intf, 0x2c);
/* Custom code - do not modify/remove */    
    {
        uint16_t* ptr;        
        uint32_t i;
        ptr =  gfxPixelBufferOffsetGet_Unsafe(buf, 0, 0);
        
        for (i = 0; i < buf->size.height * buf->size.width; i++)
        {
            ptr[i] = __builtin_bswap16(ptr[i]);
        }
        
        ptr =  gfxPixelBufferOffsetGet_Unsafe(buf, 0, 0);
        
        GFX_Disp_Intf_WriteData(intf,
                            (uint8_t *) ptr,
                            PIXEL_BUFFER_BYTES_PER_PIXEL *
                            buf->size.width *
                            buf->size.height);
    }
/* Custom code - do not modify/remove */    
    
    switch(activeDisplay)
    {
        case 0:
        {
            GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS, GFX_DISP_INTF_PIN_SET);
            
            break;
        }
        case 1:
        {
            GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS1, GFX_DISP_INTF_PIN_SET);
            
            break;
        }
        case 2:
        {
            GFX_Disp_Intf_PinControl(intf, GFX_DISP_INTF_PIN_CS2, GFX_DISP_INTF_PIN_SET);
            
            break;
        }
        default:
        {
            return GFX_SUCCESS;
        }
    }


    return GFX_SUCCESS;
}

gfxDriverIOCTLResponse DRV_ExternalController_IOCTL(gfxDriverIOCTLRequest request,
                                     void* arg)
{
    gfxIOCTLArg_Value* val;
    gfxIOCTLArg_DisplaySize* disp;
    gfxIOCTLArg_LayerRect* rect;

    switch(request)
    {
        case GFX_IOCTL_FRAME_END:
        {
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_ACTIVE_LAYER:
        {
            gfxDriverIOCTLResponse response = GFX_IOCTL_OK;

            val = (gfxIOCTLArg_Value *)arg;

            activeDisplay = val->value.v_uint;
            
            return response;
        }        
        case GFX_IOCTL_GET_COLOR_MODE:
        {
            val = (gfxIOCTLArg_Value*)arg;

            val->value.v_colormode = PIXEL_BUFFER_COLOR_MODE;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_BUFFER_COUNT:
        {
            val = (gfxIOCTLArg_Value*)arg;

            val->value.v_uint = 1;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_DISPLAY_SIZE:
        {
            disp = (gfxIOCTLArg_DisplaySize*)arg;

            disp->width = DISPLAY_WIDTH;
            disp->height = DISPLAY_HEIGHT;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_LAYER_COUNT:
        {
            val = (gfxIOCTLArg_Value*)arg;

            val->value.v_uint = 1;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_ACTIVE_LAYER:
        {
            val = (gfxIOCTLArg_Value*)arg;

            val->value.v_uint = 0;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_LAYER_RECT:
        {
            rect = (gfxIOCTLArg_LayerRect*)arg;

            rect->layer.id = 0;
            rect->x = 0;
            rect->y = 0;
            rect->width = DISPLAY_WIDTH;
            rect->height = DISPLAY_HEIGHT;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_VSYNC_COUNT:
        {
            val = (gfxIOCTLArg_Value*)arg;

            val->value.v_uint = swapCount;

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_STATUS:
		{
            val = (gfxIOCTLArg_Value*)arg;

            if (drv.state == RUN)
                val->value.v_uint = 0;
            else
                val->value.v_uint = 1;

            return GFX_IOCTL_OK;
	    }
        default:
        { }
    }

    return GFX_IOCTL_UNSUPPORTED;
}

