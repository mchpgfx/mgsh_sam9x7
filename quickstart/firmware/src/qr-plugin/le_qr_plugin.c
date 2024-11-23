#include "le_qr_plugin.h"

// Helper function to convert 32-bit RGBA to target format
static uint32_t convertColor(uint32_t color32, ColorFormat format) {
    // Extract components assuming RGBA input
    uint8_t r = (color32 >> 24) & 0xFF;
    uint8_t g = (color32 >> 16) & 0xFF;
    uint8_t b = (color32 >> 8) & 0xFF;
    uint8_t a = color32 & 0xFF;
    
    switch(format) {
        case FORMAT_RGB565:
            // Convert to RGB565 (5-6-5)
            return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
            
        case FORMAT_RGB888:
            // Convert to RGB888
            return (r << 16) | (g << 8) | b;
            
        case FORMAT_ARGB8888:
            // Convert RGBA to ARGB
            return (a << 24) | (r << 16) | (g << 8) | b;
            
        case FORMAT_RGBA8888:
            // Keep original RGBA
            return color32;
            
        case FORMAT_GRAY8:
            // Convert to grayscale using standard luminance formula
            return (uint8_t)(0.299f * r + 0.587f * g + 0.114f * b);
            
        default:
            return color32;
    }
}

// Helper function to set pixel in framebuffer with correct format
static void setPixel(void* framebuffer, int x, int y, int frameWidth, 
                     ColorFormat format, uint32_t color) {
    uint32_t convertedColor = convertColor(color, format);
    int pos = y * frameWidth + x;
    
    switch(format) {
        case FORMAT_RGB565:
            ((uint16_t*)framebuffer)[pos] = (uint16_t)convertedColor;
            break;
            
        case FORMAT_RGB888:
            {
                uint8_t* ptr = (uint8_t*)framebuffer + pos * 3;
                ptr[0] = (convertedColor >> 16) & 0xFF; // R
                ptr[1] = (convertedColor >> 8) & 0xFF;  // G
                ptr[2] = convertedColor & 0xFF;         // B
            }
            break;
            
        case FORMAT_ARGB8888:
            ((uint32_t*)framebuffer)[pos] = convertedColor;
            break;
            
        case FORMAT_RGBA8888:
            ((uint32_t*)framebuffer)[pos] = convertedColor;
            break;
            
        case FORMAT_GRAY8:
            ((uint8_t*)framebuffer)[pos] = (uint8_t)convertedColor;
            break;
    }
}

uint8_t createQR(void *framebuffer, 
             int frameWidth, int frameHeight,   // Total frame dimensions
             int originX, int originY,          // Where to start drawing
             int containerWidth, int containerHeight, // Container dimensions
             const char *text,                  // Text to encode
             ColorFormat format,               // Color format
             uint32_t colorBackground,         // 32-bit RGBA background color
             uint32_t colorQR)                 // 32-bit RGBA QR code color
{
    // Input validation
    if (!framebuffer || !text) return 1;
    
    // Make container square using smallest dimension
    int squareSize = (containerWidth < containerHeight) ? containerWidth : containerHeight;
    
    // QR code generation buffers
    uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    
    // Generate QR code
    bool success = qrcodegen_encodeText(text, tempBuffer, qrcode, qrcodegen_Ecc_LOW,
        qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, 
        qrcodegen_Mask_AUTO, true);
    
    if (!success) return 1;
    
    // Get QR base size
    int qrSize = qrcodegen_getSize(qrcode);
    
    // Calculate scale factor to fit in square
    int qrScale = squareSize / qrSize;
    if (qrScale < 1) qrScale = 1;
    
    // Calculate actual QR size after scaling
    int actualQrSize = qrSize * qrScale;
    
    // Calculate centering offsets within the square container
    int offsetX = (squareSize - actualQrSize) / 2;
    int offsetY = (squareSize - actualQrSize) / 2;
    
    // Ensure we don't draw outside the framebuffer
    if (originX + squareSize > frameWidth || 
        originY + squareSize > frameHeight) {
        return 1;
    }
    
    // Fill entire container with background color
    for (int y = 0; y < squareSize; y++) {
        for (int x = 0; x < squareSize; x++) {
            setPixel(framebuffer, 
                    originX + x, 
                    originY + y, 
                    frameWidth, 
                    format, 
                    colorBackground);
        }
    }
    
    // Draw QR code centered in the container
    for (int y = 0; y < qrSize; y++) {
        for (int x = 0; x < qrSize; x++) {
            bool module = qrcodegen_getModule(qrcode, x, y);
            
            // Scale up each QR module
            for (int scaleY = 0; scaleY < qrScale; scaleY++) {
                for (int scaleX = 0; scaleX < qrScale; scaleX++) {
                    int fbX = originX + offsetX + (x * qrScale) + scaleX;
                    int fbY = originY + offsetY + (y * qrScale) + scaleY;
                    
                    setPixel(framebuffer, fbX, fbY, frameWidth, format,
                            module ? colorQR : colorBackground);
                }
            }
        }
    }
    
    return 0;
}
