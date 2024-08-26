/*******************************************************************************
  System Initialization File

  File Name:
    app_data.c

  Summary:
    This file contains hard-coded data used in the demo.

  Description:
    This file contains hard-coded data used in the demo and helper functions
    for accessing these data.
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include "definitions.h"
#include "app_screen.h"
#include "gfx/legato/generated/le_gen_assets.h"

/* hard coded data for the list of drugs in the main menu */
static DRUG_DATABASE_ENTRY drugDatabase[] = 
{
    {0, &Screen0_Drug0, &string_Atropine, &DrugABackground, true, APP_DRUG_SEDATIVE, 150},
    {1, &Screen0_Drug1, &string_Dopamine, &DrugBBackground, true, APP_DRUG_ANALGESIC, 250},
    {2, &Screen0_Drug2, &string_Lidocaine, &DrugCBackground, true, APP_DRUG_SEDATIVE, 350},
    {3, &Screen0_Drug3, &string_Dobutamine, &DrugCBackground, true, APP_DRUG_ANALGESIC, 200},
    {4, &Screen0_Drug4, &string_Midazolam, &DrugDBackground, true, APP_DRUG_ANTIARRHYTHMIC, 190},
    {5, &Screen0_Drug5, &string_Morphine, &DrugEBackground, true, APP_DRUG_SEDATIVE, 180},
    {6, &Screen0_Drug6, &string_Propofol, &DrugFBackground, true, APP_DRUG_ANTIARRHYTHMIC, 140},
    {7, &Screen0_Drug7, &string_Remifentanil, &DrugCBackground, true, APP_DRUG_SEDATIVE, 210},
    {8, &Screen0_Drug8, &string_SodiumNitroprusside, &DrugGBackground, true, APP_DRUG_ANALGESIC, 155},
    {9, &Screen0_Drug9, &string_Meperidine, &DrugGBackground, true, APP_DRUG_SEDATIVE, 300},
    {10, &Screen0_Drug10, &string_Dexmedetomidine, &DrugABackground, true, APP_DRUG_ANTIARRHYTHMIC, 220},
    {11, &Screen0_Drug11, &string_Etomidate, &DrugCBackground, true, APP_DRUG_SEDATIVE, 260},
    {12, &Screen0_Drug12, &string_Dronedarone, &DrugEBackground, true, APP_DRUG_ANALGESIC, 180},
    {13, &Screen0_Drug13, &string_Amiodarone, &DrugGBackground, true, APP_DRUG_ANTIARRHYTHMIC, 100},
    {14, &Screen0_Drug14, &string_Lorazepam, &DrugDBackground, true, APP_DRUG_VASOACTIVE, 50},
};

/* Hard-coded patient/drug information */
static INPUT_VALUE_ENTRY inputValueRecord[APP_INPUT_MAX] = 
{
    {APP_INPUT_WEIGHT, &Screen0_WeightLabel, &Screen0_WeightValueLabel, (leFont* )&MedBoldNum, 85}, //Weight
    {APP_INPUT_VOLUME, &Screen0_VolumeLabel, &Screen0_VolValueLabel, (leFont* ) &MedBoldNum, 85}, //Volume
    {APP_INPUT_DOSE_RATE, &Screen0_DoseRateLabel, &Screen0_DoseRateValueLabel, (leFont* ) &BigBoldNum, 15}, //Dose Rate
    {APP_INPUT_CONCENTRATION, &Screen0_ConcLabel, &Screen0_ConcValueLabel, (leFont* ) &BigBoldNum, 50}, //Concentration
    {APP_INPUT_DOSE_MODE, &Screen0_DoseModeLabel, &Screen0_DoseModeValueLabel, (leFont* ) &MedBoldNum, 0}, //Dose Mode
    {APP_INPUT_VTBI, &Screen0_VtbiLabel, &Screen0_VtbiValueLabel, (leFont* ) &BigBoldNum, 50}, //VTBI
};

/* String values for dose mode setting */
static leString * doseModeValueText[MAX_DOSE_MODE] = 
{
    (leString *) &string_DoseModeRegular,
    (leString *) &string_DoseModeContinuous
};

/* Helper function for getting dose mode string */
leString * APP_GetDoseModeString(uint32_t index)
{
    if (index < MAX_DOSE_MODE)
    {
        return doseModeValueText[index];
    }

    return NULL;
}

/* Helper function for getting drug button based on touch position */
DRUG_DATABASE_ENTRY * APP_GetDrugButtonFromPosition(lePoint point)
{
    uint32_t i;
    
    for (i = 0; i < sizeof(drugDatabase)/sizeof(DRUG_DATABASE_ENTRY); i++)
    {
        leButtonWidget * button = *(drugDatabase[i].button);
        
        if (button != NULL &&
            button->widget.type == LE_WIDGET_BUTTON && 
            leRectContainsPoint(&button->widget.rect, &point))
        {
            return &drugDatabase[i];
        }
    }
    
    return NULL;
}

/* Helper function for getting values of user-configurable patient/drug settings */
INPUT_VALUE_ENTRY * APP_GetValueRecord(APP_INPUT_RECORD_ID id)
{
    if (id >= APP_INPUT_MAX)
        return NULL;
    
    return &inputValueRecord[id];
}
