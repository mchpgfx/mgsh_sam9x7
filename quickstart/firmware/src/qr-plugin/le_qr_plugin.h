/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

#include "qrcodegen.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    // Color formats
    typedef enum {
        FORMAT_RGB565,    // 16-bit RGB (5-6-5)
        FORMAT_RGB888,    // 24-bit RGB (8-8-8)
        FORMAT_ARGB8888,  // 32-bit ARGB (8-8-8-8)
        FORMAT_RGBA8888,  // 32-bit RGBA (8-8-8-8)
        FORMAT_GRAY8      // 8-bit Grayscale
    } ColorFormat;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    uint8_t createQR(void *framebuffer, 
                 int frameWidth, int frameHeight,   // Total frame dimensions
                 int originX, int originY,          // Where to start drawing
                 int containerWidth, int containerHeight, // Container dimensions
                 const char *text,                  // Text to encode
                 ColorFormat format,               // Color format
                 uint32_t colorBackground,         // 32-bit RGBA background color
                 uint32_t colorQR);                 // 32-bit RGBA QR code color

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
