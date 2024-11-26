/*******************************************************************************
  Legato Plug-in - QR Code

  Company:
    Microchip Technology Inc.

  File Name:
    legato_plugin_qrcode.h

  Summary:
    This file contains the declarations of the QR code plug-in for Legato.

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

/*******************************************************************************
  Code Example:
    // Pre-allocate a buffer as needed.
    char qrText[1024] = {0};

    // Create a Draw Surface widget in Composer and enable the On Draw Event.
    leBool event_Screen0_DrawSurfaceWidget_0_OnDraw(leDrawSurfaceWidget* sfc, leRect* bounds)
    {
        qrResult result;

        // Use one of the following generators, or just pass plain text.

        result = generateVCardQRText("John", "Doe",
                            "Company", "Title",
                            "+1234567890",
                            "john.doe@domain.com",
                            "Earth",
                            "https://www.w3.org/",
                            qrText,
                            sizeof(qrText));

        result = generateEmailQRText("example@domain.com", qrText, sizeof(qrText));

        result = generateEmailDetailedQRText("example@domain.com",
                                             "Meeting Tomorrow",
                                             "Let's meet at 2 PM",
                                             qrText,
                                             sizeof(qrText));

        result = generateSMSQRText("+1234567890",
                                   "Hello there!",
                                   qrText,
                                   sizeof(qrText));

        result = generatePhoneQRText("+1234567890", qrText, sizeof(qrText));;

        result = generateWiFiQRText("NetworkName",
                                    "Password123",
                                    "WPA",
                                    qrText,
                                    sizeof(qrText));

        result = generateCalendarQRText("Meeting",
                                        2024,
                                        1,
                                        25,
                                        10,
                                        0,
                                        2024,
                                        1,
                                        25,
                                        11,
                                        0,
                                        "Office",
                                        "Team Meeting",
                                        qrText,
                                        sizeof(qrText));

        result = generateUPIQRText("username@bankid",
                          "User",
                          "1.00",
                          "INR",
                          "UPI Test",
                          qrText,
                          sizeof(qrText));

        if (result != QR_SUCCESS)
        {
            return LE_FALSE;
        }
        else
        {
            return lePlugin_QRCode(sfc,
                                   bounds,
                                   qrText,
                                   LE_COLOR_WHITE,
                                   LE_COLOR_BLACK);
        }
    }
*******************************************************************************/
//DOM-IGNORE-END

#include "lib/qrcodegen.h"
#include "gfx/legato/legato.h"
#include "ctype.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Maximum buffer size for QR text generators.
#define MAX_QR_TEXT_LENGTH 1024

typedef enum {
    QR_SUCCESS = 0,            // Operation was successful
    QR_ERR_NULL_INPUT,         // One or more input strings are NULL
    QR_ERR_BUFFER_NULL,        // The output buffer is NULL
    QR_ERR_BUFFER_TOO_SMALL,   // The buffer size is insufficient
    QR_ERR_ENCODING_FAILURE    // Failed due to encoding issues
} qrResult;

/*******************************************************************************
  Function:
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
  Summary:
    Generates a QR code string for vCard contact information.
  Description:
    Formats contact information into a vCard 3.0 format string suitable for QR code
    generation.
  Precondition:
    Buffer must be allocated with sufficient size (recommended MAX_QR_TEXT_LENGTH).
  Parameters:
    firstName - Contact's first name
    lastName - Contact's last name
    organization - Company or organization name
    title - Job title or position
    phone - Phone number (preferably in international format)
    email - Email address
    address - Physical address
    website - Website URL
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    Generated string follows vCard 3.0 specification.
*/
qrResult generateVCardQRText(const char* firstName,
                             const char* lastName,
                             const char* organization,
                             const char* title,
                             const char* phone,
                             const char* email,
                             const char* address,
                             const char* website,
                             char* buffer,
                             size_t bufferSize);

/*******************************************************************************
  Function:
    qrResult generateEmailQRText(const char* email,
                                char* buffer,
                                size_t bufferSize)
  Summary:
    Generates a QR code string for simple email address.
  Description:
    Creates a mailto: URL format string suitable for QR code generation.
  Precondition:
    Buffer must be allocated with sufficient size.
  Parameters:
    email - Target email address
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    For email with subject and body, use generateEmailDetailedQR instead.
*/
qrResult generateEmailQRText(const char* email,
                             char* buffer,
                             size_t bufferSize);

/*******************************************************************************
  Function:
    qrResult generateEmailDetailedQRText(const char* email,
                                        const char* subject,
                                        const char* body,
                                        char* buffer,
                                        size_t bufferSize)
  Summary:
    Generates a QR code string for email with subject and body.
  Description:
    Creates a mailto: URL with subject and body parameters, properly URL encoded.
  Precondition:
    Buffer must be allocated with sufficient size (recommended MAX_QR_TEXT_LENGTH).
  Parameters:
    email - Target email address
    subject - Email subject line
    body - Email body text
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    Special characters in subject and body are automatically URL encoded.
*/
qrResult generateEmailDetailedQRText(const char* email,
                                     const char* subject,
                                     const char* body,
                                     char* buffer,
                                     size_t bufferSize);

/*******************************************************************************
  Function:
    qrResult generateSMSQRText(const char* phoneNumber,
                              const char* message,
                              char* buffer,
                              size_t bufferSize)
  Summary:
    Generates a QR code string for SMS message.
  Description:
    Creates an SMS URL with optional message body, suitable for QR code generation.
  Precondition:
    Buffer must be allocated with sufficient size.
  Parameters:
    phoneNumber - Target phone number (preferably in international format)
    message - SMS message text
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    Message text is automatically URL encoded.
*/
qrResult generateSMSQRText(const char* phoneNumber,
                           const char* message,
                           char* buffer,
                           size_t bufferSize);

/*******************************************************************************
  Function:
    qrResult generatePhoneQRText(const char* phoneNumber,
                                char* buffer,
                                size_t bufferSize)
  Summary:
    Generates a QR code string for phone number.
  Description:
    Creates a tel: URL format string suitable for QR code generation.
  Precondition:
    Buffer must be allocated with sufficient size.
  Parameters:
    phoneNumber - Phone number (preferably in international format)
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    None.
*/
qrResult generatePhoneQRText(const char* phoneNumber,
                            char* buffer,
                            size_t bufferSize);

/*******************************************************************************
  Function:
    qrResult generateWiFiQRText(const char* ssid,
                                const char* password,
                                const char* securityType,
                                char* buffer,
                                size_t bufferSize)
  Summary:
    Generates a QR code string for WiFi network configuration.
  Description:
    Creates a WIFI: format string containing network credentials.
  Precondition:
    Buffer must be allocated with sufficient size.
  Parameters:
    ssid - Network SSID
    password - Network password
    securityType - Security type ("WEP", "WPA", or "" for no password)
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    Follows WiFi Alliance QR code format specification.
*/
qrResult generateWiFiQRText(const char* ssid,
                            const char* password,
                            const char* securityType,
                            char* buffer,
                            size_t bufferSize);

/*******************************************************************************
  Function:
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
  Summary:
    Generates a QR code string for calendar event.
  Description:
    Creates an iCalendar format string suitable for QR code generation.
  Precondition:
    Buffer must be allocated with sufficient size (recommended MAX_QR_TEXT_LENGTH).
  Parameters:
    title - Event title
    startYear - Event start year (e.g., 2024)
    startMonth - Event start month (1-12)
    startDay - Event start day (1-31)
    startHour - Event start hour (0-23)
    startMinute - Event start minute (0-59)
    endYear - Event end year (e.g., 2024)
    endMonth - Event end month (1-12)
    endDay - Event end day (1-31)
    endHour - Event end hour (0-23)
    endMinute - Event end minute (0-59)
    location - Event location
    description - Event description
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    Times are formatted in UTC timezone.
*/
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
                                size_t bufferSize);

/*******************************************************************************
  Function:
    qrResult generateUPIQRText(const char* payeeAddress,
                               const char* payeeName,
                               const char* amount,
                               const char* currency,
                               const char* transactionNote,
                               char* buffer,
                               size_t bufferSize)
  Summary:
    Generates a QR code string for UPI payment transactions.
  Description:
    Creates a UPI: format string containing payment details.
  Precondition:
    Buffer must be allocated with sufficient size.
  Parameters:
    payeeAddress - UPI ID of the recipient (e.g., "username@bankid")
    payeeName - Name of the payee or business i.e. recipient.
    amount - Transaction amount as a string (e.g., "100.50")
    currency - Currency type (e.g., "INR")
    transactionNote - Note or message for the transaction
    buffer - Pre-allocated buffer to store the formatted string
    bufferSize - Size of the provided buffer
  Returns:
    qrResult - Check the enumerated constants for more details.
  Remarks:
    Follows UPI QR code format specification.
*/
qrResult generateUPIQRText(const char* payeeAddress,
                           const char* payeeName,
                           const char* amount,
                           const char* currency,
                           const char* transactionNote,
                           char* buffer,
                           size_t bufferSize);

/*******************************************************************************
  Plug-in Interface Function:
    leBool lePlugin_QRCode(leDrawSurfaceWidget* sfc,
                           leRect* bounds,
                           const char* text,
                           leColorName colorBackground,
                           leColorName colorQR)
  Summary:
    Generates a QR code using the provided string buffer.
  Description:
    Can be used to display a QR code on the selected draw surface.
    Will scale to the largest possible square in the provided bounds.
  Parameters:
    sfc - The target draw surface widget.
    bounds - The target draw surface widget dimensions.
    text - Size of the provided buffer
    colorBackground - The background color of the QR code.
    colorQR - The module color of the QR code.
  Returns:
    LE_TRUE on success. LE_FALSE on failure.
  Remarks:
    This is meant to be called from the draw surface event callback!
    Use the text generators provided above if you want to format the
    string in any particular way. For plain text, use it as is.
    For available colors, check the enumerated constants in leColorName.
*/
leBool lePlugin_QRCode(leDrawSurfaceWidget* sfc,
                       leRect* bounds,
                       const char* text,
                       leColorName colorBackground,
                       leColorName colorQR);

#ifdef __cplusplus
}
#endif
