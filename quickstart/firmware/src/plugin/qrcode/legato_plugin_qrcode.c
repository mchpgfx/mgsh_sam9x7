#include "legato_plugin_qrcode.h"

// Encode URL Strings
static void urlEncode(const char* src, char* dst, size_t dstSize) {
    const char* hex = "0123456789ABCDEF";
    size_t srcLen = strlen(src);
    size_t i, j = 0;
    
    for(i = 0; i < srcLen && j < dstSize - 4; i++) {
        unsigned char c = src[i];
        if(isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            dst[j++] = c;
        } else if(c == ' ') {
            dst[j++] = '%';
            dst[j++] = '2';
            dst[j++] = '0';
        } else {
            dst[j++] = '%';
            dst[j++] = hex[c >> 4];
            dst[j++] = hex[c & 15];
        }
    }
    dst[j] = '\0';
}

// Generate vCard QR
const char* generateVCardQRText(const char* firstName, 
                                const char* lastName,
                                const char* organization,
                                const char* title,
                                const char* phone,
                                const char* email,
                                const char* address,
                                const char* website,
                                char* buffer,
                                size_t bufferSize)
{
    snprintf(buffer, bufferSize,
             "BEGIN:VCARD\n"
             "VERSION:3.0\n"
             "N:%s;%s;;;\n"
             "FN:%s %s\n"
             "ORG:%s\n"
             "TITLE:%s\n"
             "TEL;TYPE=WORK,VOICE:%s\n"
             "ADR;TYPE=WORK:;;%s\n"
             "EMAIL:%s\n"
             "URL:%s\n"
             "END:VCARD",
             lastName, firstName,
             firstName, lastName,
             organization,
             title,
             phone,
             address,
             email,
             website);
    return buffer;
}

// Generate Email QR (simple)
const char* generateEmailQRText(const char* email, 
                                char* buffer, 
                                size_t bufferSize) 
{
    snprintf(buffer, bufferSize, "mailto:%s", email);
    return buffer;
}

// Generate Email QR (with subject and body)
const char* generateEmailDetailedQRText(const char* email,
                                        const char* subject,
                                        const char* body,
                                        char* buffer,
                                        size_t bufferSize)
{
    char encodedSubject[MAX_QR_TEXT_LENGTH];
    char encodedBody[MAX_QR_TEXT_LENGTH];
    
    urlEncode(subject, encodedSubject, sizeof(encodedSubject));
    urlEncode(body, encodedBody, sizeof(encodedBody));
    
    snprintf(buffer, bufferSize,
             "mailto:%s?subject=%s&body=%s",
             email, encodedSubject, encodedBody);
    return buffer;
}

// Generate SMS QR
const char* generateSMSQRText(const char* phoneNumber,
                              const char* message,
                              char* buffer,
                              size_t bufferSize) 
{
    char encodedMessage[MAX_QR_TEXT_LENGTH];
    urlEncode(message, encodedMessage, sizeof(encodedMessage));
    
    snprintf(buffer, bufferSize,
             "sms:%s?body=%s",
             phoneNumber, encodedMessage);
    return buffer;
}

// Generate Phone Number QR
const char* generatePhoneQRText(const char* phoneNumber,
                                char* buffer,
                                size_t bufferSize)
{
    snprintf(buffer, bufferSize, "tel:%s", phoneNumber);
    return buffer;
}

// Generate WiFi Configuration QR
const char* generateWiFiQRText(const char* ssid,
                               const char* password,
                               const char* securityType,
                               char* buffer,
                               size_t bufferSize) 
{
    snprintf(buffer, bufferSize,
             "WIFI:S:%s;T:%s;P:%s;;",
             ssid, securityType, password);
    return buffer;
}

// Helper function to format date-time for calendar
static void formatDateTime(char* buffer, size_t bufferSize,
                         int year, int month, int day,
                         int hour, int minute) {
    snprintf(buffer, bufferSize,
             "%04d%02d%02dT%02d%02d00Z",
             year, month, day, hour, minute);
}

// Generate Calendar Event QR
const char* generateCalendarQRText(const char* title,
                                   int startYear,
                                   int startMonth,
                                   int startDay,
                                   int startHour,
                                   int startMinute,
                                   int endYear,
                                   int endMonth,
                                   int endDay,
                                   int endHour,
                                   int endMinute,
                                   const char* location,
                                   const char* description,
                                   char* buffer,
                                   size_t bufferSize)
{
    char startTime[32];
    char endTime[32];
    
    formatDateTime(startTime, sizeof(startTime),
                  startYear, startMonth, startDay,
                  startHour, startMinute);
    
    formatDateTime(endTime, sizeof(endTime),
                  endYear, endMonth, endDay,
                  endHour, endMinute);
    
    snprintf(buffer, bufferSize,
             "BEGIN:VEVENT\n"
             "SUMMARY:%s\n"
             "DTSTART:%s\n"
             "DTEND:%s\n"
             "LOCATION:%s\n"
             "DESCRIPTION:%s\n"
             "END:VEVENT",
             title, startTime, endTime, location, description);
    return buffer;
}

leBool lePlugin_QRCode(leDrawSurfaceWidget* sfc, 
                       leRect* bounds,
                       const char* text,
                       leColorName colorBackground,
                       leColorName colorQR)
{
    if (!sfc || !bounds || !text) return LE_FALSE;
    
    leColorMode curMode = leRenderer_CurrentColorMode();
    leColor bgColor =  leColorValue(curMode, colorBackground);
    leColor moduleColor = leColorValue(curMode, colorQR);
    
    // Get widget position
    int originX = sfc->fn->getX(sfc);
    int originY = sfc->fn->getY(sfc);
    
    // Make container square using smallest dimension
    int squareSize = (bounds->width < bounds->height) ? bounds->width : bounds->height;
    
    // QR code generation buffers
    uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    
    // Generate QR code
    bool success = qrcodegen_encodeText(text, tempBuffer, qrcode, qrcodegen_Ecc_LOW,
        qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, 
        qrcodegen_Mask_AUTO, true);
    
    if (!success) return LE_FALSE;
    
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
    
    // Fill background
    if (leRenderer_FillArea(originX, 
                       originY,
                       squareSize, 
                       squareSize,
                       bgColor,
                       255) == LE_FAILURE)
        return LE_FALSE;
    
    // Draw QR code centered in the container
    for (int y = 0; y < qrSize; y++) 
    {
        for (int x = 0; x < qrSize; x++) 
        {
            bool module = qrcodegen_getModule(qrcode, x, y);
            
            if (module) 
            {  
                // Only draw QR modules (not background)
                // Scale up each QR module
                int fbX = originX + offsetX + (x * qrScale);
                int fbY = originY + offsetY + (y * qrScale);
                
                if (leRenderer_FillArea(fbX,
                                  fbY,
                                  qrScale,
                                  qrScale,
                                  moduleColor,
                                  255) == LE_FAILURE)
                return LE_FALSE;
            }
        }
    }
    
    return LE_TRUE;
}
