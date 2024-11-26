/*******************************************************************************
  Legato Plug-in - QR Code

  Company:
    Microchip Technology Inc.

  File Name:
    legato_plugin_qrcode.c

  Summary:
    This file contains the implementation of the QR code plug-in for Legato.

  Description:
    Provides a way to encode and display plain text as a QR Code.
    Also provides QR text generators for common uses cases,
    use them to create QR codes for vCard, UPI payments and more.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#include "legato_plugin_qrcode.h"

// Generate vCard QR
qrResult generateVCardQRText(const char* firstName,
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
    qrResult result = QR_SUCCESS;

    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 128)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    int ret = snprintf(buffer, bufferSize,
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

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return result;
}

// Generate Email QR (simple)
qrResult generateEmailQRText(const char* email,
                             char* buffer,
                             size_t bufferSize)
{
    qrResult result = QR_SUCCESS;

    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 8)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    int ret = snprintf(buffer, bufferSize,
                       "mailto:%s",
                       email);

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return result;
}

// Generate Email QR (with subject and body)
qrResult generateEmailDetailedQRText(const char* email,
                                     const char* subject,
                                     const char* body,
                                     char* buffer,
                                     size_t bufferSize)
{
    qrResult result = QR_SUCCESS;

    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 23)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    int ret = snprintf(buffer, bufferSize,
                       "mailto:%s?subject=%s&body=%s",
                       email, subject, body);

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return result;
}

// Generate SMS QR
qrResult generateSMSQRText(const char* phoneNumber,
                           const char* message,
                           char* buffer,
                           size_t bufferSize)
{
    qrResult result = QR_SUCCESS;

    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 11)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    int ret = snprintf(buffer, bufferSize,
                       "sms:%s?body=%s",
                       phoneNumber, message);

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return result;
}

// Generate Phone Number QR
qrResult generatePhoneQRText(const char* phoneNumber,
                            char* buffer,
                            size_t bufferSize)
{
    qrResult result = QR_SUCCESS;

    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 5)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    int ret = snprintf(buffer, bufferSize,
                       "tel:%s",
                       phoneNumber);

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return result;
}

// Generate WiFi Configuration QR
qrResult generateWiFiQRText(const char* ssid,
                            const char* password,
                            const char* securityType,
                            char* buffer,
                            size_t bufferSize)
{
    qrResult result = QR_SUCCESS;

    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 14)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    int ret = snprintf(buffer, bufferSize,
                       "WIFI:S:%s;T:%s;P:%s;;",
                       ssid, securityType, password);

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return result;
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
qrResult generateCalendarQRText(const char* title,
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
    qrResult result = QR_SUCCESS;

    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 117)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    char startTime[21];
    char endTime[21];

    formatDateTime(startTime, sizeof(startTime),
                   startYear, startMonth, startDay,
                   startHour, startMinute);

    formatDateTime(endTime, sizeof(endTime),
                   endYear, endMonth, endDay,
                   endHour, endMinute);

    int ret = snprintf(buffer, bufferSize,
                       "BEGIN:VEVENT\n"
                       "SUMMARY:%s\n"
                       "DTSTART:%s\n"
                       "DTEND:%s\n"
                       "LOCATION:%s\n"
                       "DESCRIPTION:%s\n"
                       "END:VEVENT",
                       title,
                       startTime,
                       endTime,
                       location,
                       description);

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return result;
}

// Generate UPI Payment QR
qrResult generateUPIQRText(const char* payeeAddress,
                           const char* payeeName,
                           const char* amount,
                           const char* currency,
                           const char* transactionNote,
                           char* buffer,
                           size_t bufferSize)
{
    if (!buffer)
    {
        return QR_ERR_NULL_INPUT;
    }
    else if (bufferSize < 30)
    {
        return QR_ERR_BUFFER_TOO_SMALL;
    }

    int ret = snprintf(buffer, bufferSize,
                       "upi://pay?pa=%s&pn=%s&am=%s&cu=%s&tn=%s",
                       payeeAddress,
                       payeeName,
                       amount,
                       currency,
                       transactionNote);

    if (ret >= bufferSize) {
        return QR_ERR_BUFFER_TOO_SMALL;
    }
    else if (ret < 0) {
        return QR_ERR_ENCODING_FAILURE;
    }

    return QR_SUCCESS;
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
