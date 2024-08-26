#ifndef LE_GEN_SCREEN_SCREEN0_H
#define LE_GEN_SCREEN_SCREEN0_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen0_SplashPanel;
extern leImageWidget* Screen0_ImageWidget_0;
extern leLabelWidget* Screen0_LabelWidget_1;
extern leWidget* Screen0_MedsMenuPanel;
extern leWidget* Screen0_MedsMenuPanelBackground;
extern leButtonWidget* Screen0_Drug0;
extern leButtonWidget* Screen0_Drug1;
extern leButtonWidget* Screen0_Drug2;
extern leButtonWidget* Screen0_Drug3;
extern leButtonWidget* Screen0_Drug4;
extern leButtonWidget* Screen0_Drug5;
extern leButtonWidget* Screen0_Drug6;
extern leButtonWidget* Screen0_Drug7;
extern leButtonWidget* Screen0_Drug8;
extern leButtonWidget* Screen0_Drug9;
extern leButtonWidget* Screen0_Drug10;
extern leButtonWidget* Screen0_Drug11;
extern leButtonWidget* Screen0_Drug12;
extern leButtonWidget* Screen0_Drug13;
extern leButtonWidget* Screen0_Drug14;
extern leWidget* Screen0_MainMenuPanel;
extern leWidget* Screen0_MainMenuPanel_0;
extern leImageWidget* Screen0_ImageWidget_1;
extern leButtonWidget* Screen0_ButtonWidget_0;
extern leButtonWidget* Screen0_ButtonWidget_0_0;
extern leButtonWidget* Screen0_ButtonWidget_0_2;
extern leButtonWidget* Screen0_ButtonWidget_0_3;
extern leButtonWidget* Screen0_ButtonWidget_0_4;
extern leButtonWidget* Screen0_ButtonWidget_0_5;
extern leButtonWidget* Screen0_ButtonWidget_0_2_0;
extern leLabelWidget* Screen0_LabelWidget_0;
extern leWidget* Screen0_DrugScreenPanel;
extern leImageWidget* Screen0_DrugInfoPressureBox;
extern leButtonWidget* Screen0_MedButton;
extern leImageWidget* Screen0_WeightBox;
extern leImageWidget* Screen0_DoseRateBox;
extern leImageWidget* Screen0_VolBox;
extern leImageWidget* Screen0_ConcBox;
extern leImageWidget* Screen0_BolusBox;
extern leImageWidget* Screen0_DoseModeBox;
extern leImageWidget* Screen0_VTBIBox;
extern leImageWidget* Screen0_ProgressBox;
extern leButtonWidget* Screen0_StartStopButton;
extern leWidget* Screen0_TopBarPanel;
extern leImageSequenceWidget* Screen0_StartButtonAnim;
extern leImageSequenceWidget* Screen0_StopButtonAnim;
extern leImageWidget* Screen0_ImageWidget_1_0;
extern leImageWidget* Screen0_KnobImage;
extern leLabelWidget* Screen0_LabelWidget_1_1;
extern leLabelWidget* Screen0_PressureValueLabel;
extern leLabelWidget* Screen0_LabelWidget_1_1_3;
extern leLabelWidget* Screen0_TimeElapsedValueLabel;
extern leWidget* Screen0_PressKnobActiveArea;
extern leWidget* Screen0_PressKnobArea;
extern leImageWidget* Screen0_ImageWidget_4;
extern leLabelWidget* Screen0_WeightLabel;
extern leLabelWidget* Screen0_WeightValueLabel;
extern leButtonWidget* Screen0_SetWeightButton;
extern leLabelWidget* Screen0_DoseRateLabel;
extern leLabelWidget* Screen0_DoseRateValueLabel;
extern leButtonWidget* Screen0_SetDoseRateButton;
extern leButtonWidget* Screen0_DownDoseRateButton;
extern leButtonWidget* Screen0_UpDoseRateButton;
extern leLabelWidget* Screen0_VolumeLabel;
extern leLabelWidget* Screen0_VolValueLabel;
extern leButtonWidget* Screen0_SetVolButton;
extern leLabelWidget* Screen0_ConcLabel;
extern leLabelWidget* Screen0_ConcValueLabel;
extern leButtonWidget* Screen0_SetConcButton;
extern leLabelWidget* Screen0_LabelWidget_9;
extern leLabelWidget* Screen0_DoseModeLabel;
extern leLabelWidget* Screen0_DoseModeValueLabel;
extern leLabelWidget* Screen0_DoseModeType;
extern leLabelWidget* Screen0_LabelWidget_7;
extern leButtonWidget* Screen0_DownDoseModeButton;
extern leButtonWidget* Screen0_UpDoseModeButton;
extern leLabelWidget* Screen0_VtbiLabel;
extern leLabelWidget* Screen0_VtbiValueLabel;
extern leButtonWidget* Screen0_SetVtbiButton;
extern leButtonWidget* Screen0_DownVtbiButton;
extern leButtonWidget* Screen0_UpVtbiButton;
extern leImageSequenceWidget* Screen0_ProgressArrows;
extern leLabelWidget* Screen0_LabelWidget_1_1_1;
extern leLabelWidget* Screen0_LabelWidget_1_1_2;
extern leLabelWidget* Screen0_TimeLeftValueLabel;
extern leLabelWidget* Screen0_VolLeftValueLabel;
extern leImageWidget* Screen0_WifiIcon;
extern leImageWidget* Screen0_BatteryIcon;
extern leLabelWidget* Screen0_BatteryValueLabel;
extern leLabelWidget* Screen0_TimeValueLabel;
extern leLabelWidget* Screen0_StartStopLabel;
extern leLabelWidget* Screen0_StartStopLabel_0;
extern leWidget* Screen0_NumEditPanel;
extern leImageWidget* Screen0_NumEntryBox;
extern leWidget* Screen0_KeypadPanel;
extern leLabelWidget* Screen0_NumEntryLabel;
extern leTextFieldWidget* Screen0_NumEntryTextField;
extern leKeyPadWidget* Screen0_NumEntryKeypad;
extern leImageWidget* Screen0_NumEntryKeypadImg;
extern leWidget* Screen0_SuccessScreenPanel;
extern leImageWidget* Screen0_SuccessPopupImage;
extern leLabelWidget* Screen0_SuccessTitleLabel;
extern leLabelWidget* Screen0_SuccessTitleLabel_0;
extern leButtonWidget* Screen0_SuccessConfirmButtonm;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen0_MedButton_OnReleased(leButtonWidget* btn);
void event_Screen0_StartStopButton_OnPressed(leButtonWidget* btn);
void event_Screen0_StartStopButton_OnReleased(leButtonWidget* btn);
void event_Screen0_SetWeightButton_OnReleased(leButtonWidget* btn);
void event_Screen0_SetDoseRateButton_OnReleased(leButtonWidget* btn);
void event_Screen0_DownDoseRateButton_OnReleased(leButtonWidget* btn);
void event_Screen0_UpDoseRateButton_OnReleased(leButtonWidget* btn);
void event_Screen0_SetVolButton_OnReleased(leButtonWidget* btn);
void event_Screen0_SetConcButton_OnReleased(leButtonWidget* btn);
void event_Screen0_DownDoseModeButton_OnReleased(leButtonWidget* btn);
void event_Screen0_UpDoseModeButton_OnReleased(leButtonWidget* btn);
void event_Screen0_SetVtbiButton_OnReleased(leButtonWidget* btn);
void event_Screen0_DownVtbiButton_OnReleased(leButtonWidget* btn);
void event_Screen0_UpVtbiButton_OnReleased(leButtonWidget* btn);
void event_Screen0_NumEntryKeypad_OnKeyClick(leKeyPadWidget* wgt, leButtonWidget* cell, uint32_t row, uint32_t col);
void event_Screen0_SuccessConfirmButtonm_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen0(void); // called when Legato is initialized
leResult screenShow_Screen0(void); // called when screen is shown
void screenHide_Screen0(void); // called when screen is hidden
void screenDestroy_Screen0(void); // called when Legato is destroyed
void screenUpdate_Screen0(void); // called when Legato is updating

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen0_OnShow(void); // called when this screen is shown
void Screen0_OnHide(void); // called when this screen is hidden
void Screen0_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN0_H
