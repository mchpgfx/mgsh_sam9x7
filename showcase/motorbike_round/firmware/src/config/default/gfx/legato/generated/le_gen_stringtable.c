#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   15
 *****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned short - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned byte[3] - the offset of the string codepoint data in
 *                      the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 *     unsigned short - length of the string in bytes (encoding dependent)
 *     codepoint data - the string data
 ****************************************************************************/

const uint8_t stringTable_data[234] =
{
    0x0F,0x00,0x01,0x00,0x00,0x40,0x00,0x00,0x02,0x4A,0x00,0x00,0x02,0x60,0x00,0x00,
    0x00,0x78,0x00,0x00,0x01,0x80,0x00,0x00,0x05,0x86,0x00,0x00,0x00,0x92,0x00,0x00,
    0x02,0x9E,0x00,0x00,0x00,0xB4,0x00,0x00,0x03,0xBA,0x00,0x00,0x00,0xBE,0x00,0x00,
    0x04,0xC8,0x00,0x00,0x02,0xCE,0x00,0x00,0x02,0xD8,0x00,0x00,0x00,0xE2,0x00,0x00,
    0x08,0x00,0x35,0x31,0x20,0x4D,0x69,0x6C,0x65,0x73,0x13,0x00,0x45,0x78,0x69,0x74,
    0x20,0x32,0x30,0x3A,0x20,0x49,0x2D,0x31,0x37,0x20,0x53,0x6F,0x75,0x74,0x68,0x00,
    0x16,0x00,0x43,0x6F,0x6E,0x74,0x69,0x6E,0x75,0x65,0x20,0x6F,0x6E,0x20,0x49,0x2D,
    0x31,0x37,0x20,0x53,0x6F,0x75,0x74,0x68,0x05,0x00,0x53,0x70,0x6F,0x72,0x74,0x00,
    0x03,0x00,0x31,0x34,0x30,0x00,0x09,0x00,0x52,0x50,0x4D,0x0A,0x78,0x31,0x30,0x30,
    0x30,0x00,0x0A,0x00,0x31,0x34,0x2E,0x31,0x20,0x4D,0x69,0x6C,0x65,0x73,0x14,0x00,
    0x45,0x78,0x69,0x74,0x20,0x31,0x34,0x3A,0x20,0x49,0x2D,0x32,0x38,0x35,0x20,0x4E,
    0x6F,0x72,0x74,0x68,0x03,0x00,0x32,0x38,0x31,0x00,0x01,0x00,0x31,0x00,0x08,0x00,
    0x31,0x32,0x20,0x4D,0x69,0x6C,0x65,0x73,0x03,0x00,0x6D,0x70,0x68,0x00,0x08,0x00,
    0x44,0x65,0x6D,0x6F,0x20,0x4F,0x66,0x66,0x07,0x00,0x44,0x65,0x6D,0x6F,0x20,0x4F,
    0x6E,0x00,0x05,0x00,0x4D,0x69,0x6C,0x65,0x73,0x00,
};

/* font asset pointer list */
leFont* fontList[6] =
{
    (leFont*)&DistanceFont,
    (leFont*)&SpeedoFont,
    (leFont*)&DirectionFont,
    (leFont*)&GearNumFont,
    (leFont*)&mphFont,
    (leFont*)&Font0,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        234, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_DistanceStringContinue;
leTableString string_DirectionStringLeft;
leTableString string_DirectionStringContinue;
leTableString string_ModeString;
leTableString string_MPH_Default;
leTableString string_RPMString;
leTableString string_DistanceStringLeft;
leTableString string_DirectionStringRight;
leTableString string_RangeValueString;
leTableString string_GearNumber;
leTableString string_DistanceStringRight;
leTableString string_mphString;
leTableString string_DemoOff;
leTableString string_DemoOn;
leTableString string_RangeUnitString;

void initializeStrings(void)
{
    leTableString_Constructor(&string_DistanceStringContinue, stringID_DistanceStringContinue);
    leTableString_Constructor(&string_DirectionStringLeft, stringID_DirectionStringLeft);
    leTableString_Constructor(&string_DirectionStringContinue, stringID_DirectionStringContinue);
    leTableString_Constructor(&string_ModeString, stringID_ModeString);
    leTableString_Constructor(&string_MPH_Default, stringID_MPH_Default);
    leTableString_Constructor(&string_RPMString, stringID_RPMString);
    leTableString_Constructor(&string_DistanceStringLeft, stringID_DistanceStringLeft);
    leTableString_Constructor(&string_DirectionStringRight, stringID_DirectionStringRight);
    leTableString_Constructor(&string_RangeValueString, stringID_RangeValueString);
    leTableString_Constructor(&string_GearNumber, stringID_GearNumber);
    leTableString_Constructor(&string_DistanceStringRight, stringID_DistanceStringRight);
    leTableString_Constructor(&string_mphString, stringID_mphString);
    leTableString_Constructor(&string_DemoOff, stringID_DemoOff);
    leTableString_Constructor(&string_DemoOn, stringID_DemoOn);
    leTableString_Constructor(&string_RangeUnitString, stringID_RangeUnitString);
}
