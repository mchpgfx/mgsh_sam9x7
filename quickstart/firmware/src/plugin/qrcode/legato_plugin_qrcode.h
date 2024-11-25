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

/*******************************************************************************
  Function:
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
    Pointer to the formatted string in buffer. NULL if operation fails.
  Remarks:
    Generated string follows vCard 3.0 specification.
*/
const char* generateVCardQRText(const char* firstName, 
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
    const char* generateEmailQRText(const char* email, 
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
    Pointer to the formatted string in buffer. NULL if operation fails.
  Remarks:
    For email with subject and body, use generateEmailDetailedQR instead.
*/
const char* generateEmailQRText(const char* email, 
                                char* buffer, 
                                size_t bufferSize);

/*******************************************************************************
  Function:
    const char* generateEmailDetailedQRText(const char* email,
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
    Pointer to the formatted string in buffer. NULL if operation fails.
  Remarks:
    Special characters in subject and body are automatically URL encoded.
*/
const char* generateEmailDetailedQRText(const char* email,
                                        const char* subject,
                                        const char* body,
                                        char* buffer,
                                        size_t bufferSize);

/*******************************************************************************
  Function:
    const char* generateSMSQRText(const char* phoneNumber,
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
    Pointer to the formatted string in buffer. NULL if operation fails.
  Remarks:
    Message text is automatically URL encoded.
*/
const char* generateSMSQRText(const char* phoneNumber,
                              const char* message,
                              char* buffer,
                              size_t bufferSize);

/*******************************************************************************
  Function:
    const char* generatePhoneQRText(const char* phoneNumber,
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
    Pointer to the formatted string in buffer. NULL if operation fails.
  Remarks:
    None.
*/
const char* generatePhoneQRText(const char* phoneNumber,
                                char* buffer,
                                size_t bufferSize);

/*******************************************************************************
  Function:
    const char* generateWiFiQRText(const char* ssid,
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
    Pointer to the formatted string in buffer. NULL if operation fails.
  Remarks:
    Follows WiFi Alliance QR code format specification.
*/
const char* generateWiFiQRText(const char* ssid,
                               const char* password,
                               const char* securityType,
                               char* buffer,
                               size_t bufferSize);

/*******************************************************************************
  Function:
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
    Pointer to the formatted string in buffer. NULL if operation fails.
  Remarks:
    Times are formatted in UTC timezone.
  Example:
    char qrText[MAX_QR_TEXT_LENGTH];
    generateCalendarQR("Meeting", 2034, 1, 25, 10, 0, 2034, 1, 25, 11, 0,
                  "Office", "Team Meeting", qrText, sizeof(qrText));
*/
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
                                   size_t bufferSize);

/*******************************************************************************
  Plug-in Interface Function:
    leBool lePlugin_QRCode(leDrawSurfaceWidget* sfc, 
                       leRect* bounds,
                       const char* text,
                       uint32_t colorBackground,
                       uint32_t colorQR)
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
    Use the generators provided below if you want to format the string
    in any particular way. For plain text, use as is.
*/
leBool lePlugin_QRCode(leDrawSurfaceWidget* sfc, 
                       leRect* bounds,
                       const char* text,
                       leColorName colorBackground,
                       leColorName colorQR);

#ifdef __cplusplus
}
#endif
