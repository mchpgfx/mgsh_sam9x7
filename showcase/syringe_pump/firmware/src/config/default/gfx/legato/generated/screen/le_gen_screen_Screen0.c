#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;
static leWidget* root3;
static leWidget* root4;
static leWidget* root5;

leWidget* Screen0_SplashPanel;
leImageWidget* Screen0_ImageWidget_0;
leLabelWidget* Screen0_LabelWidget_1;
leWidget* Screen0_MedsMenuPanel;
leWidget* Screen0_MedsMenuPanelBackground;
leButtonWidget* Screen0_Drug0;
leButtonWidget* Screen0_Drug1;
leButtonWidget* Screen0_Drug2;
leButtonWidget* Screen0_Drug3;
leButtonWidget* Screen0_Drug4;
leButtonWidget* Screen0_Drug5;
leButtonWidget* Screen0_Drug6;
leButtonWidget* Screen0_Drug7;
leButtonWidget* Screen0_Drug8;
leButtonWidget* Screen0_Drug9;
leButtonWidget* Screen0_Drug10;
leButtonWidget* Screen0_Drug11;
leButtonWidget* Screen0_Drug12;
leButtonWidget* Screen0_Drug13;
leButtonWidget* Screen0_Drug14;
leWidget* Screen0_MainMenuPanel;
leWidget* Screen0_MainMenuPanel_0;
leImageWidget* Screen0_ImageWidget_1;
leButtonWidget* Screen0_ButtonWidget_0;
leButtonWidget* Screen0_ButtonWidget_0_0;
leButtonWidget* Screen0_ButtonWidget_0_2;
leButtonWidget* Screen0_ButtonWidget_0_3;
leButtonWidget* Screen0_ButtonWidget_0_4;
leButtonWidget* Screen0_ButtonWidget_0_5;
leButtonWidget* Screen0_ButtonWidget_0_2_0;
leLabelWidget* Screen0_LabelWidget_0;
leWidget* Screen0_DrugScreenPanel;
leImageWidget* Screen0_DrugInfoPressureBox;
leButtonWidget* Screen0_MedButton;
leImageWidget* Screen0_WeightBox;
leImageWidget* Screen0_DoseRateBox;
leImageWidget* Screen0_VolBox;
leImageWidget* Screen0_ConcBox;
leImageWidget* Screen0_BolusBox;
leImageWidget* Screen0_DoseModeBox;
leImageWidget* Screen0_VTBIBox;
leImageWidget* Screen0_ProgressBox;
leButtonWidget* Screen0_StartStopButton;
leWidget* Screen0_TopBarPanel;
leImageSequenceWidget* Screen0_StartButtonAnim;
leImageSequenceWidget* Screen0_StopButtonAnim;
leImageWidget* Screen0_ImageWidget_1_0;
leImageWidget* Screen0_KnobImage;
leLabelWidget* Screen0_LabelWidget_1_1;
leLabelWidget* Screen0_PressureValueLabel;
leLabelWidget* Screen0_LabelWidget_1_1_3;
leLabelWidget* Screen0_TimeElapsedValueLabel;
leWidget* Screen0_PressKnobActiveArea;
leWidget* Screen0_PressKnobArea;
leImageWidget* Screen0_ImageWidget_4;
leLabelWidget* Screen0_WeightLabel;
leLabelWidget* Screen0_WeightValueLabel;
leButtonWidget* Screen0_SetWeightButton;
leLabelWidget* Screen0_DoseRateLabel;
leLabelWidget* Screen0_DoseRateValueLabel;
leButtonWidget* Screen0_SetDoseRateButton;
leButtonWidget* Screen0_DownDoseRateButton;
leButtonWidget* Screen0_UpDoseRateButton;
leLabelWidget* Screen0_VolumeLabel;
leLabelWidget* Screen0_VolValueLabel;
leButtonWidget* Screen0_SetVolButton;
leLabelWidget* Screen0_ConcLabel;
leLabelWidget* Screen0_ConcValueLabel;
leButtonWidget* Screen0_SetConcButton;
leLabelWidget* Screen0_LabelWidget_9;
leLabelWidget* Screen0_DoseModeLabel;
leLabelWidget* Screen0_DoseModeValueLabel;
leLabelWidget* Screen0_DoseModeType;
leLabelWidget* Screen0_LabelWidget_7;
leButtonWidget* Screen0_DownDoseModeButton;
leButtonWidget* Screen0_UpDoseModeButton;
leLabelWidget* Screen0_VtbiLabel;
leLabelWidget* Screen0_VtbiValueLabel;
leButtonWidget* Screen0_SetVtbiButton;
leButtonWidget* Screen0_DownVtbiButton;
leButtonWidget* Screen0_UpVtbiButton;
leImageSequenceWidget* Screen0_ProgressArrows;
leLabelWidget* Screen0_LabelWidget_1_1_1;
leLabelWidget* Screen0_LabelWidget_1_1_2;
leLabelWidget* Screen0_TimeLeftValueLabel;
leLabelWidget* Screen0_VolLeftValueLabel;
leImageWidget* Screen0_WifiIcon;
leImageWidget* Screen0_BatteryIcon;
leLabelWidget* Screen0_BatteryValueLabel;
leLabelWidget* Screen0_TimeValueLabel;
leLabelWidget* Screen0_StartStopLabel;
leLabelWidget* Screen0_StartStopLabel_0;
leWidget* Screen0_NumEditPanel;
leImageWidget* Screen0_NumEntryBox;
leWidget* Screen0_KeypadPanel;
leLabelWidget* Screen0_NumEntryLabel;
leTextFieldWidget* Screen0_NumEntryTextField;
leKeyPadWidget* Screen0_NumEntryKeypad;
leImageWidget* Screen0_NumEntryKeypadImg;
leWidget* Screen0_SuccessScreenPanel;
leImageWidget* Screen0_SuccessPopupImage;
leLabelWidget* Screen0_SuccessTitleLabel;
leLabelWidget* Screen0_SuccessTitleLabel_0;
leButtonWidget* Screen0_SuccessConfirmButtonm;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 1280, 400);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_SplashPanel = leWidget_New();
    Screen0_SplashPanel->fn->setPosition(Screen0_SplashPanel, 0, 0);
    Screen0_SplashPanel->fn->setSize(Screen0_SplashPanel, 1280, 400);
    Screen0_SplashPanel->fn->setScheme(Screen0_SplashPanel, &BaseScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_SplashPanel);

    Screen0_ImageWidget_0 = leImageWidget_New();
    Screen0_ImageWidget_0->fn->setPosition(Screen0_ImageWidget_0, 487, 166);
    Screen0_ImageWidget_0->fn->setSize(Screen0_ImageWidget_0, 293, 40);
    Screen0_ImageWidget_0->fn->setBackgroundType(Screen0_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0->fn->setBorderType(Screen0_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0->fn->setImage(Screen0_ImageWidget_0, (leImage*)&mchp_logo_h);
    Screen0_SplashPanel->fn->addChild(Screen0_SplashPanel, (leWidget*)Screen0_ImageWidget_0);

    Screen0_LabelWidget_1 = leLabelWidget_New();
    Screen0_LabelWidget_1->fn->setPosition(Screen0_LabelWidget_1, 1134, 4);
    Screen0_LabelWidget_1->fn->setSize(Screen0_LabelWidget_1, 135, 25);
    Screen0_LabelWidget_1->fn->setScheme(Screen0_LabelWidget_1, &BaseScheme);
    Screen0_LabelWidget_1->fn->setBackgroundType(Screen0_LabelWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1->fn->setHAlignment(Screen0_LabelWidget_1, LE_HALIGN_RIGHT);
    Screen0_LabelWidget_1->fn->setString(Screen0_LabelWidget_1, (leString*)&string_VersionString);
    Screen0_SplashPanel->fn->addChild(Screen0_SplashPanel, (leWidget*)Screen0_LabelWidget_1);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 1960, 400);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_MedsMenuPanel = leWidget_New();
    Screen0_MedsMenuPanel->fn->setPosition(Screen0_MedsMenuPanel, 0, 0);
    Screen0_MedsMenuPanel->fn->setSize(Screen0_MedsMenuPanel, 1960, 400);
    Screen0_MedsMenuPanel->fn->setScheme(Screen0_MedsMenuPanel, &ClearScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_MedsMenuPanel);

    Screen0_MedsMenuPanelBackground = leWidget_New();
    Screen0_MedsMenuPanelBackground->fn->setPosition(Screen0_MedsMenuPanelBackground, 200, 25);
    Screen0_MedsMenuPanelBackground->fn->setSize(Screen0_MedsMenuPanelBackground, 1760, 375);
    Screen0_MedsMenuPanelBackground->fn->setScheme(Screen0_MedsMenuPanelBackground, &BaseScheme);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_MedsMenuPanelBackground);

    Screen0_Drug0 = leButtonWidget_New();
    Screen0_Drug0->fn->setPosition(Screen0_Drug0, 220, 50);
    Screen0_Drug0->fn->setSize(Screen0_Drug0, 329, 100);
    Screen0_Drug0->fn->setScheme(Screen0_Drug0, &BaseScheme);
    Screen0_Drug0->fn->setBackgroundType(Screen0_Drug0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug0->fn->setBorderType(Screen0_Drug0, LE_WIDGET_BORDER_NONE);
    Screen0_Drug0->fn->setToggleable(Screen0_Drug0, LE_TRUE);
    Screen0_Drug0->fn->setString(Screen0_Drug0, (leString*)&string_Atropine);
    Screen0_Drug0->fn->setPressedImage(Screen0_Drug0, (leImage*)&DrugABackground);
    Screen0_Drug0->fn->setReleasedImage(Screen0_Drug0, (leImage*)&DrugABackground);
    Screen0_Drug0->fn->setImagePosition(Screen0_Drug0, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug0);

    Screen0_Drug1 = leButtonWidget_New();
    Screen0_Drug1->fn->setPosition(Screen0_Drug1, 570, 50);
    Screen0_Drug1->fn->setSize(Screen0_Drug1, 329, 100);
    Screen0_Drug1->fn->setScheme(Screen0_Drug1, &BaseScheme);
    Screen0_Drug1->fn->setBackgroundType(Screen0_Drug1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug1->fn->setBorderType(Screen0_Drug1, LE_WIDGET_BORDER_NONE);
    Screen0_Drug1->fn->setToggleable(Screen0_Drug1, LE_TRUE);
    Screen0_Drug1->fn->setString(Screen0_Drug1, (leString*)&string_Dopamine);
    Screen0_Drug1->fn->setPressedImage(Screen0_Drug1, (leImage*)&DrugBBackground);
    Screen0_Drug1->fn->setReleasedImage(Screen0_Drug1, (leImage*)&DrugBBackground);
    Screen0_Drug1->fn->setImagePosition(Screen0_Drug1, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug1);

    Screen0_Drug2 = leButtonWidget_New();
    Screen0_Drug2->fn->setPosition(Screen0_Drug2, 920, 50);
    Screen0_Drug2->fn->setSize(Screen0_Drug2, 329, 100);
    Screen0_Drug2->fn->setScheme(Screen0_Drug2, &BaseScheme);
    Screen0_Drug2->fn->setBackgroundType(Screen0_Drug2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug2->fn->setBorderType(Screen0_Drug2, LE_WIDGET_BORDER_NONE);
    Screen0_Drug2->fn->setToggleable(Screen0_Drug2, LE_TRUE);
    Screen0_Drug2->fn->setString(Screen0_Drug2, (leString*)&string_Lidocaine);
    Screen0_Drug2->fn->setPressedImage(Screen0_Drug2, (leImage*)&DrugCBackground);
    Screen0_Drug2->fn->setReleasedImage(Screen0_Drug2, (leImage*)&DrugCBackground);
    Screen0_Drug2->fn->setImagePosition(Screen0_Drug2, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug2);

    Screen0_Drug3 = leButtonWidget_New();
    Screen0_Drug3->fn->setPosition(Screen0_Drug3, 220, 161);
    Screen0_Drug3->fn->setSize(Screen0_Drug3, 329, 100);
    Screen0_Drug3->fn->setScheme(Screen0_Drug3, &BaseScheme);
    Screen0_Drug3->fn->setBackgroundType(Screen0_Drug3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug3->fn->setBorderType(Screen0_Drug3, LE_WIDGET_BORDER_NONE);
    Screen0_Drug3->fn->setToggleable(Screen0_Drug3, LE_TRUE);
    Screen0_Drug3->fn->setString(Screen0_Drug3, (leString*)&string_Dobutamine);
    Screen0_Drug3->fn->setPressedImage(Screen0_Drug3, (leImage*)&DrugCBackground);
    Screen0_Drug3->fn->setReleasedImage(Screen0_Drug3, (leImage*)&DrugCBackground);
    Screen0_Drug3->fn->setImagePosition(Screen0_Drug3, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug3);

    Screen0_Drug4 = leButtonWidget_New();
    Screen0_Drug4->fn->setPosition(Screen0_Drug4, 570, 161);
    Screen0_Drug4->fn->setSize(Screen0_Drug4, 329, 100);
    Screen0_Drug4->fn->setScheme(Screen0_Drug4, &BaseScheme);
    Screen0_Drug4->fn->setBackgroundType(Screen0_Drug4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug4->fn->setBorderType(Screen0_Drug4, LE_WIDGET_BORDER_NONE);
    Screen0_Drug4->fn->setToggleable(Screen0_Drug4, LE_TRUE);
    Screen0_Drug4->fn->setString(Screen0_Drug4, (leString*)&string_Midazolam);
    Screen0_Drug4->fn->setPressedImage(Screen0_Drug4, (leImage*)&DrugDBackground);
    Screen0_Drug4->fn->setReleasedImage(Screen0_Drug4, (leImage*)&DrugDBackground);
    Screen0_Drug4->fn->setImagePosition(Screen0_Drug4, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug4);

    Screen0_Drug5 = leButtonWidget_New();
    Screen0_Drug5->fn->setPosition(Screen0_Drug5, 920, 160);
    Screen0_Drug5->fn->setSize(Screen0_Drug5, 329, 100);
    Screen0_Drug5->fn->setScheme(Screen0_Drug5, &BaseScheme);
    Screen0_Drug5->fn->setBackgroundType(Screen0_Drug5, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug5->fn->setBorderType(Screen0_Drug5, LE_WIDGET_BORDER_NONE);
    Screen0_Drug5->fn->setToggleable(Screen0_Drug5, LE_TRUE);
    Screen0_Drug5->fn->setString(Screen0_Drug5, (leString*)&string_Morphine);
    Screen0_Drug5->fn->setPressedImage(Screen0_Drug5, (leImage*)&DrugEBackground);
    Screen0_Drug5->fn->setReleasedImage(Screen0_Drug5, (leImage*)&DrugEBackground);
    Screen0_Drug5->fn->setImagePosition(Screen0_Drug5, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug5);

    Screen0_Drug6 = leButtonWidget_New();
    Screen0_Drug6->fn->setPosition(Screen0_Drug6, 220, 270);
    Screen0_Drug6->fn->setSize(Screen0_Drug6, 329, 100);
    Screen0_Drug6->fn->setScheme(Screen0_Drug6, &BaseScheme);
    Screen0_Drug6->fn->setBackgroundType(Screen0_Drug6, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug6->fn->setBorderType(Screen0_Drug6, LE_WIDGET_BORDER_NONE);
    Screen0_Drug6->fn->setToggleable(Screen0_Drug6, LE_TRUE);
    Screen0_Drug6->fn->setString(Screen0_Drug6, (leString*)&string_Propofol);
    Screen0_Drug6->fn->setPressedImage(Screen0_Drug6, (leImage*)&DrugFBackground);
    Screen0_Drug6->fn->setReleasedImage(Screen0_Drug6, (leImage*)&DrugFBackground);
    Screen0_Drug6->fn->setImagePosition(Screen0_Drug6, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug6);

    Screen0_Drug7 = leButtonWidget_New();
    Screen0_Drug7->fn->setPosition(Screen0_Drug7, 570, 270);
    Screen0_Drug7->fn->setSize(Screen0_Drug7, 329, 100);
    Screen0_Drug7->fn->setScheme(Screen0_Drug7, &BaseScheme);
    Screen0_Drug7->fn->setBackgroundType(Screen0_Drug7, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug7->fn->setBorderType(Screen0_Drug7, LE_WIDGET_BORDER_NONE);
    Screen0_Drug7->fn->setToggleable(Screen0_Drug7, LE_TRUE);
    Screen0_Drug7->fn->setString(Screen0_Drug7, (leString*)&string_Remifentanil);
    Screen0_Drug7->fn->setPressedImage(Screen0_Drug7, (leImage*)&DrugCBackground);
    Screen0_Drug7->fn->setReleasedImage(Screen0_Drug7, (leImage*)&DrugCBackground);
    Screen0_Drug7->fn->setImagePosition(Screen0_Drug7, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug7);

    Screen0_Drug8 = leButtonWidget_New();
    Screen0_Drug8->fn->setPosition(Screen0_Drug8, 919, 271);
    Screen0_Drug8->fn->setSize(Screen0_Drug8, 329, 100);
    Screen0_Drug8->fn->setScheme(Screen0_Drug8, &BaseScheme);
    Screen0_Drug8->fn->setBackgroundType(Screen0_Drug8, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug8->fn->setBorderType(Screen0_Drug8, LE_WIDGET_BORDER_NONE);
    Screen0_Drug8->fn->setToggleable(Screen0_Drug8, LE_TRUE);
    Screen0_Drug8->fn->setString(Screen0_Drug8, (leString*)&string_SodiumNitroprusside);
    Screen0_Drug8->fn->setPressedImage(Screen0_Drug8, (leImage*)&DrugGBackground);
    Screen0_Drug8->fn->setReleasedImage(Screen0_Drug8, (leImage*)&DrugGBackground);
    Screen0_Drug8->fn->setImagePosition(Screen0_Drug8, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug8);

    Screen0_Drug9 = leButtonWidget_New();
    Screen0_Drug9->fn->setPosition(Screen0_Drug9, 1269, 51);
    Screen0_Drug9->fn->setSize(Screen0_Drug9, 329, 100);
    Screen0_Drug9->fn->setScheme(Screen0_Drug9, &BaseScheme);
    Screen0_Drug9->fn->setBackgroundType(Screen0_Drug9, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug9->fn->setBorderType(Screen0_Drug9, LE_WIDGET_BORDER_NONE);
    Screen0_Drug9->fn->setToggleable(Screen0_Drug9, LE_TRUE);
    Screen0_Drug9->fn->setString(Screen0_Drug9, (leString*)&string_Meperidine);
    Screen0_Drug9->fn->setPressedImage(Screen0_Drug9, (leImage*)&DrugGBackground);
    Screen0_Drug9->fn->setReleasedImage(Screen0_Drug9, (leImage*)&DrugGBackground);
    Screen0_Drug9->fn->setImagePosition(Screen0_Drug9, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug9);

    Screen0_Drug10 = leButtonWidget_New();
    Screen0_Drug10->fn->setPosition(Screen0_Drug10, 1269, 160);
    Screen0_Drug10->fn->setSize(Screen0_Drug10, 329, 100);
    Screen0_Drug10->fn->setScheme(Screen0_Drug10, &BaseScheme);
    Screen0_Drug10->fn->setBackgroundType(Screen0_Drug10, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug10->fn->setBorderType(Screen0_Drug10, LE_WIDGET_BORDER_NONE);
    Screen0_Drug10->fn->setToggleable(Screen0_Drug10, LE_TRUE);
    Screen0_Drug10->fn->setString(Screen0_Drug10, (leString*)&string_Dexmedetomidine);
    Screen0_Drug10->fn->setPressedImage(Screen0_Drug10, (leImage*)&DrugABackground);
    Screen0_Drug10->fn->setReleasedImage(Screen0_Drug10, (leImage*)&DrugABackground);
    Screen0_Drug10->fn->setImagePosition(Screen0_Drug10, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug10);

    Screen0_Drug11 = leButtonWidget_New();
    Screen0_Drug11->fn->setPosition(Screen0_Drug11, 1269, 270);
    Screen0_Drug11->fn->setSize(Screen0_Drug11, 329, 100);
    Screen0_Drug11->fn->setScheme(Screen0_Drug11, &BaseScheme);
    Screen0_Drug11->fn->setBackgroundType(Screen0_Drug11, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug11->fn->setBorderType(Screen0_Drug11, LE_WIDGET_BORDER_NONE);
    Screen0_Drug11->fn->setToggleable(Screen0_Drug11, LE_TRUE);
    Screen0_Drug11->fn->setString(Screen0_Drug11, (leString*)&string_Etomidate);
    Screen0_Drug11->fn->setPressedImage(Screen0_Drug11, (leImage*)&DrugCBackground);
    Screen0_Drug11->fn->setReleasedImage(Screen0_Drug11, (leImage*)&DrugCBackground);
    Screen0_Drug11->fn->setImagePosition(Screen0_Drug11, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug11);

    Screen0_Drug12 = leButtonWidget_New();
    Screen0_Drug12->fn->setPosition(Screen0_Drug12, 1619, 51);
    Screen0_Drug12->fn->setSize(Screen0_Drug12, 329, 100);
    Screen0_Drug12->fn->setScheme(Screen0_Drug12, &BaseScheme);
    Screen0_Drug12->fn->setBackgroundType(Screen0_Drug12, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug12->fn->setBorderType(Screen0_Drug12, LE_WIDGET_BORDER_NONE);
    Screen0_Drug12->fn->setToggleable(Screen0_Drug12, LE_TRUE);
    Screen0_Drug12->fn->setString(Screen0_Drug12, (leString*)&string_Dronedarone);
    Screen0_Drug12->fn->setPressedImage(Screen0_Drug12, (leImage*)&DrugEBackground);
    Screen0_Drug12->fn->setReleasedImage(Screen0_Drug12, (leImage*)&DrugEBackground);
    Screen0_Drug12->fn->setImagePosition(Screen0_Drug12, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug12);

    Screen0_Drug13 = leButtonWidget_New();
    Screen0_Drug13->fn->setPosition(Screen0_Drug13, 1619, 160);
    Screen0_Drug13->fn->setSize(Screen0_Drug13, 329, 100);
    Screen0_Drug13->fn->setScheme(Screen0_Drug13, &BaseScheme);
    Screen0_Drug13->fn->setBackgroundType(Screen0_Drug13, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug13->fn->setBorderType(Screen0_Drug13, LE_WIDGET_BORDER_NONE);
    Screen0_Drug13->fn->setToggleable(Screen0_Drug13, LE_TRUE);
    Screen0_Drug13->fn->setString(Screen0_Drug13, (leString*)&string_Amiodarone);
    Screen0_Drug13->fn->setPressedImage(Screen0_Drug13, (leImage*)&DrugGBackground);
    Screen0_Drug13->fn->setReleasedImage(Screen0_Drug13, (leImage*)&DrugGBackground);
    Screen0_Drug13->fn->setImagePosition(Screen0_Drug13, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug13);

    Screen0_Drug14 = leButtonWidget_New();
    Screen0_Drug14->fn->setPosition(Screen0_Drug14, 1619, 270);
    Screen0_Drug14->fn->setSize(Screen0_Drug14, 329, 100);
    Screen0_Drug14->fn->setScheme(Screen0_Drug14, &BaseScheme);
    Screen0_Drug14->fn->setBackgroundType(Screen0_Drug14, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Drug14->fn->setBorderType(Screen0_Drug14, LE_WIDGET_BORDER_NONE);
    Screen0_Drug14->fn->setToggleable(Screen0_Drug14, LE_TRUE);
    Screen0_Drug14->fn->setString(Screen0_Drug14, (leString*)&string_Lorazepam);
    Screen0_Drug14->fn->setPressedImage(Screen0_Drug14, (leImage*)&DrugDBackground);
    Screen0_Drug14->fn->setReleasedImage(Screen0_Drug14, (leImage*)&DrugDBackground);
    Screen0_Drug14->fn->setImagePosition(Screen0_Drug14, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedsMenuPanel->fn->addChild(Screen0_MedsMenuPanel, (leWidget*)Screen0_Drug14);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 1280, 400);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_MainMenuPanel = leWidget_New();
    Screen0_MainMenuPanel->fn->setPosition(Screen0_MainMenuPanel, 0, 0);
    Screen0_MainMenuPanel->fn->setSize(Screen0_MainMenuPanel, 200, 400);
    Screen0_MainMenuPanel->fn->setScheme(Screen0_MainMenuPanel, &DarkBaseScheme);
    root2->fn->addChild(root2, (leWidget*)Screen0_MainMenuPanel);

    Screen0_ImageWidget_1 = leImageWidget_New();
    Screen0_ImageWidget_1->fn->setPosition(Screen0_ImageWidget_1, 24, 6);
    Screen0_ImageWidget_1->fn->setSize(Screen0_ImageWidget_1, 117, 17);
    Screen0_ImageWidget_1->fn->setBackgroundType(Screen0_ImageWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_1->fn->setBorderType(Screen0_ImageWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_1->fn->setImage(Screen0_ImageWidget_1, (leImage*)&logo_horizontal_small);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ImageWidget_1);

    Screen0_ButtonWidget_0 = leButtonWidget_New();
    Screen0_ButtonWidget_0->fn->setPosition(Screen0_ButtonWidget_0, 18, 53);
    Screen0_ButtonWidget_0->fn->setSize(Screen0_ButtonWidget_0, 165, 41);
    Screen0_ButtonWidget_0->fn->setScheme(Screen0_ButtonWidget_0, &BaseScheme);
    Screen0_ButtonWidget_0->fn->setBackgroundType(Screen0_ButtonWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0->fn->setBorderType(Screen0_ButtonWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0->fn->setString(Screen0_ButtonWidget_0, (leString*)&string_Settings);
    Screen0_ButtonWidget_0->fn->setPressedImage(Screen0_ButtonWidget_0, (leImage*)&MainMenuBtnPr);
    Screen0_ButtonWidget_0->fn->setReleasedImage(Screen0_ButtonWidget_0, (leImage*)&MainMenuBtnRel);
    Screen0_ButtonWidget_0->fn->setImagePosition(Screen0_ButtonWidget_0, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ButtonWidget_0);

    Screen0_ButtonWidget_0_0 = leButtonWidget_New();
    Screen0_ButtonWidget_0_0->fn->setPosition(Screen0_ButtonWidget_0_0, 18, 120);
    Screen0_ButtonWidget_0_0->fn->setSize(Screen0_ButtonWidget_0_0, 165, 41);
    Screen0_ButtonWidget_0_0->fn->setScheme(Screen0_ButtonWidget_0_0, &BaseScheme);
    Screen0_ButtonWidget_0_0->fn->setBackgroundType(Screen0_ButtonWidget_0_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0_0->fn->setBorderType(Screen0_ButtonWidget_0_0, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0_0->fn->setString(Screen0_ButtonWidget_0_0, (leString*)&string_All);
    Screen0_ButtonWidget_0_0->fn->setPressedImage(Screen0_ButtonWidget_0_0, (leImage*)&MainMenuBtnPr);
    Screen0_ButtonWidget_0_0->fn->setReleasedImage(Screen0_ButtonWidget_0_0, (leImage*)&MainMenuBtnRel);
    Screen0_ButtonWidget_0_0->fn->setImagePosition(Screen0_ButtonWidget_0_0, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ButtonWidget_0_0);

    Screen0_ButtonWidget_0_2 = leButtonWidget_New();
    Screen0_ButtonWidget_0_2->fn->setPosition(Screen0_ButtonWidget_0_2, 17, 304);
    Screen0_ButtonWidget_0_2->fn->setSize(Screen0_ButtonWidget_0_2, 165, 41);
    Screen0_ButtonWidget_0_2->fn->setScheme(Screen0_ButtonWidget_0_2, &BaseScheme);
    Screen0_ButtonWidget_0_2->fn->setBackgroundType(Screen0_ButtonWidget_0_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0_2->fn->setBorderType(Screen0_ButtonWidget_0_2, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0_2->fn->setString(Screen0_ButtonWidget_0_2, (leString*)&string_Sedative);
    Screen0_ButtonWidget_0_2->fn->setPressedImage(Screen0_ButtonWidget_0_2, (leImage*)&MainMenuBtnPr);
    Screen0_ButtonWidget_0_2->fn->setReleasedImage(Screen0_ButtonWidget_0_2, (leImage*)&MainMenuBtnRel);
    Screen0_ButtonWidget_0_2->fn->setImagePosition(Screen0_ButtonWidget_0_2, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ButtonWidget_0_2);

    Screen0_ButtonWidget_0_3 = leButtonWidget_New();
    Screen0_ButtonWidget_0_3->fn->setPosition(Screen0_ButtonWidget_0_3, 18, 258);
    Screen0_ButtonWidget_0_3->fn->setSize(Screen0_ButtonWidget_0_3, 165, 41);
    Screen0_ButtonWidget_0_3->fn->setScheme(Screen0_ButtonWidget_0_3, &BaseScheme);
    Screen0_ButtonWidget_0_3->fn->setBackgroundType(Screen0_ButtonWidget_0_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0_3->fn->setBorderType(Screen0_ButtonWidget_0_3, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0_3->fn->setString(Screen0_ButtonWidget_0_3, (leString*)&string_AntiArrhythmic);
    Screen0_ButtonWidget_0_3->fn->setPressedImage(Screen0_ButtonWidget_0_3, (leImage*)&MainMenuBtnPr);
    Screen0_ButtonWidget_0_3->fn->setReleasedImage(Screen0_ButtonWidget_0_3, (leImage*)&MainMenuBtnRel);
    Screen0_ButtonWidget_0_3->fn->setImagePosition(Screen0_ButtonWidget_0_3, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ButtonWidget_0_3);

    Screen0_ButtonWidget_0_4 = leButtonWidget_New();
    Screen0_ButtonWidget_0_4->fn->setPosition(Screen0_ButtonWidget_0_4, 18, 212);
    Screen0_ButtonWidget_0_4->fn->setSize(Screen0_ButtonWidget_0_4, 165, 41);
    Screen0_ButtonWidget_0_4->fn->setScheme(Screen0_ButtonWidget_0_4, &BaseScheme);
    Screen0_ButtonWidget_0_4->fn->setBackgroundType(Screen0_ButtonWidget_0_4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0_4->fn->setBorderType(Screen0_ButtonWidget_0_4, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0_4->fn->setString(Screen0_ButtonWidget_0_4, (leString*)&string_Vasoactive);
    Screen0_ButtonWidget_0_4->fn->setPressedImage(Screen0_ButtonWidget_0_4, (leImage*)&MainMenuBtnPr);
    Screen0_ButtonWidget_0_4->fn->setReleasedImage(Screen0_ButtonWidget_0_4, (leImage*)&MainMenuBtnRel);
    Screen0_ButtonWidget_0_4->fn->setImagePosition(Screen0_ButtonWidget_0_4, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ButtonWidget_0_4);

    Screen0_ButtonWidget_0_5 = leButtonWidget_New();
    Screen0_ButtonWidget_0_5->fn->setPosition(Screen0_ButtonWidget_0_5, 18, 166);
    Screen0_ButtonWidget_0_5->fn->setSize(Screen0_ButtonWidget_0_5, 165, 41);
    Screen0_ButtonWidget_0_5->fn->setScheme(Screen0_ButtonWidget_0_5, &BaseScheme);
    Screen0_ButtonWidget_0_5->fn->setBackgroundType(Screen0_ButtonWidget_0_5, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0_5->fn->setBorderType(Screen0_ButtonWidget_0_5, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0_5->fn->setString(Screen0_ButtonWidget_0_5, (leString*)&string_Common);
    Screen0_ButtonWidget_0_5->fn->setPressedImage(Screen0_ButtonWidget_0_5, (leImage*)&MainMenuBtnPr);
    Screen0_ButtonWidget_0_5->fn->setReleasedImage(Screen0_ButtonWidget_0_5, (leImage*)&MainMenuBtnRel);
    Screen0_ButtonWidget_0_5->fn->setImagePosition(Screen0_ButtonWidget_0_5, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ButtonWidget_0_5);

    Screen0_ButtonWidget_0_2_0 = leButtonWidget_New();
    Screen0_ButtonWidget_0_2_0->fn->setPosition(Screen0_ButtonWidget_0_2_0, 17, 350);
    Screen0_ButtonWidget_0_2_0->fn->setSize(Screen0_ButtonWidget_0_2_0, 165, 41);
    Screen0_ButtonWidget_0_2_0->fn->setScheme(Screen0_ButtonWidget_0_2_0, &BaseScheme);
    Screen0_ButtonWidget_0_2_0->fn->setBackgroundType(Screen0_ButtonWidget_0_2_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_0_2_0->fn->setBorderType(Screen0_ButtonWidget_0_2_0, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_0_2_0->fn->setString(Screen0_ButtonWidget_0_2_0, (leString*)&string_Analgesic);
    Screen0_ButtonWidget_0_2_0->fn->setPressedImage(Screen0_ButtonWidget_0_2_0, (leImage*)&MainMenuBtnPr);
    Screen0_ButtonWidget_0_2_0->fn->setReleasedImage(Screen0_ButtonWidget_0_2_0, (leImage*)&MainMenuBtnRel);
    Screen0_ButtonWidget_0_2_0->fn->setImagePosition(Screen0_ButtonWidget_0_2_0, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_ButtonWidget_0_2_0);

    Screen0_LabelWidget_0 = leLabelWidget_New();
    Screen0_LabelWidget_0->fn->setPosition(Screen0_LabelWidget_0, 18, 96);
    Screen0_LabelWidget_0->fn->setSize(Screen0_LabelWidget_0, 100, 22);
    Screen0_LabelWidget_0->fn->setScheme(Screen0_LabelWidget_0, &BaseScheme);
    Screen0_LabelWidget_0->fn->setBackgroundType(Screen0_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_0->fn->setString(Screen0_LabelWidget_0, (leString*)&string_Filters);
    Screen0_MainMenuPanel->fn->addChild(Screen0_MainMenuPanel, (leWidget*)Screen0_LabelWidget_0);

    Screen0_MainMenuPanel_0 = leWidget_New();
    Screen0_MainMenuPanel_0->fn->setPosition(Screen0_MainMenuPanel_0, 200, 0);
    Screen0_MainMenuPanel_0->fn->setSize(Screen0_MainMenuPanel_0, 1080, 400);
    Screen0_MainMenuPanel_0->fn->setEnabled(Screen0_MainMenuPanel_0, LE_FALSE);
    Screen0_MainMenuPanel_0->fn->setVisible(Screen0_MainMenuPanel_0, LE_FALSE);
    Screen0_MainMenuPanel_0->fn->setScheme(Screen0_MainMenuPanel_0, &ClearScheme);
    Screen0_MainMenuPanel_0->fn->setBackgroundType(Screen0_MainMenuPanel_0, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->addChild(root2, (leWidget*)Screen0_MainMenuPanel_0);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGBA_8888);

    // layer 3
    root3 = leWidget_New();
    root3->fn->setSize(root3, 1280, 400);
    root3->fn->setBackgroundType(root3, LE_WIDGET_BACKGROUND_NONE);
    root3->fn->setMargins(root3, 0, 0, 0, 0);
    root3->flags |= LE_WIDGET_IGNOREEVENTS;
    root3->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_DrugScreenPanel = leWidget_New();
    Screen0_DrugScreenPanel->fn->setPosition(Screen0_DrugScreenPanel, 0, 0);
    Screen0_DrugScreenPanel->fn->setSize(Screen0_DrugScreenPanel, 1280, 400);
    Screen0_DrugScreenPanel->fn->setEnabled(Screen0_DrugScreenPanel, LE_FALSE);
    Screen0_DrugScreenPanel->fn->setScheme(Screen0_DrugScreenPanel, &BaseScheme);
    root3->fn->addChild(root3, (leWidget*)Screen0_DrugScreenPanel);

    Screen0_DrugInfoPressureBox = leImageWidget_New();
    Screen0_DrugInfoPressureBox->fn->setPosition(Screen0_DrugInfoPressureBox, 22, 138);
    Screen0_DrugInfoPressureBox->fn->setSize(Screen0_DrugInfoPressureBox, 329, 252);
    Screen0_DrugInfoPressureBox->fn->setBackgroundType(Screen0_DrugInfoPressureBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DrugInfoPressureBox->fn->setBorderType(Screen0_DrugInfoPressureBox, LE_WIDGET_BORDER_NONE);
    Screen0_DrugInfoPressureBox->fn->setImage(Screen0_DrugInfoPressureBox, (leImage*)&DrugPressureTIme);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_DrugInfoPressureBox);

    Screen0_KnobImage = leImageWidget_New();
    Screen0_KnobImage->fn->setPosition(Screen0_KnobImage, 28, 163);
    Screen0_KnobImage->fn->setSize(Screen0_KnobImage, 40, 40);
    Screen0_KnobImage->fn->setEnabled(Screen0_KnobImage, LE_FALSE);
    Screen0_KnobImage->fn->setBackgroundType(Screen0_KnobImage, LE_WIDGET_BACKGROUND_NONE);
    Screen0_KnobImage->fn->setBorderType(Screen0_KnobImage, LE_WIDGET_BORDER_NONE);
    Screen0_KnobImage->fn->setImage(Screen0_KnobImage, (leImage*)&RoundKnob);
    Screen0_DrugInfoPressureBox->fn->addChild(Screen0_DrugInfoPressureBox, (leWidget*)Screen0_KnobImage);

    Screen0_LabelWidget_1_1 = leLabelWidget_New();
    Screen0_LabelWidget_1_1->fn->setPosition(Screen0_LabelWidget_1_1, 114, 27);
    Screen0_LabelWidget_1_1->fn->setSize(Screen0_LabelWidget_1_1, 102, 25);
    Screen0_LabelWidget_1_1->fn->setEnabled(Screen0_LabelWidget_1_1, LE_FALSE);
    Screen0_LabelWidget_1_1->fn->setScheme(Screen0_LabelWidget_1_1, &BaseScheme);
    Screen0_LabelWidget_1_1->fn->setBackgroundType(Screen0_LabelWidget_1_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1_1->fn->setHAlignment(Screen0_LabelWidget_1_1, LE_HALIGN_CENTER);
    Screen0_LabelWidget_1_1->fn->setString(Screen0_LabelWidget_1_1, (leString*)&string_Pressure);
    Screen0_DrugInfoPressureBox->fn->addChild(Screen0_DrugInfoPressureBox, (leWidget*)Screen0_LabelWidget_1_1);

    Screen0_PressureValueLabel = leLabelWidget_New();
    Screen0_PressureValueLabel->fn->setPosition(Screen0_PressureValueLabel, 96, 95);
    Screen0_PressureValueLabel->fn->setSize(Screen0_PressureValueLabel, 130, 70);
    Screen0_PressureValueLabel->fn->setEnabled(Screen0_PressureValueLabel, LE_FALSE);
    Screen0_PressureValueLabel->fn->setScheme(Screen0_PressureValueLabel, &BaseScheme);
    Screen0_PressureValueLabel->fn->setBackgroundType(Screen0_PressureValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_PressureValueLabel->fn->setHAlignment(Screen0_PressureValueLabel, LE_HALIGN_CENTER);
    Screen0_PressureValueLabel->fn->setString(Screen0_PressureValueLabel, (leString*)&string_PressureDefaultValue);
    Screen0_DrugInfoPressureBox->fn->addChild(Screen0_DrugInfoPressureBox, (leWidget*)Screen0_PressureValueLabel);

    Screen0_LabelWidget_1_1_3 = leLabelWidget_New();
    Screen0_LabelWidget_1_1_3->fn->setPosition(Screen0_LabelWidget_1_1_3, 87, 210);
    Screen0_LabelWidget_1_1_3->fn->setSize(Screen0_LabelWidget_1_1_3, 150, 25);
    Screen0_LabelWidget_1_1_3->fn->setEnabled(Screen0_LabelWidget_1_1_3, LE_FALSE);
    Screen0_LabelWidget_1_1_3->fn->setScheme(Screen0_LabelWidget_1_1_3, &BaseScheme);
    Screen0_LabelWidget_1_1_3->fn->setBackgroundType(Screen0_LabelWidget_1_1_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1_1_3->fn->setHAlignment(Screen0_LabelWidget_1_1_3, LE_HALIGN_CENTER);
    Screen0_LabelWidget_1_1_3->fn->setString(Screen0_LabelWidget_1_1_3, (leString*)&string_TimeElapsed);
    Screen0_DrugInfoPressureBox->fn->addChild(Screen0_DrugInfoPressureBox, (leWidget*)Screen0_LabelWidget_1_1_3);

    Screen0_TimeElapsedValueLabel = leLabelWidget_New();
    Screen0_TimeElapsedValueLabel->fn->setPosition(Screen0_TimeElapsedValueLabel, 87, 173);
    Screen0_TimeElapsedValueLabel->fn->setSize(Screen0_TimeElapsedValueLabel, 151, 38);
    Screen0_TimeElapsedValueLabel->fn->setEnabled(Screen0_TimeElapsedValueLabel, LE_FALSE);
    Screen0_TimeElapsedValueLabel->fn->setScheme(Screen0_TimeElapsedValueLabel, &BaseScheme);
    Screen0_TimeElapsedValueLabel->fn->setBackgroundType(Screen0_TimeElapsedValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimeElapsedValueLabel->fn->setHAlignment(Screen0_TimeElapsedValueLabel, LE_HALIGN_CENTER);
    Screen0_TimeElapsedValueLabel->fn->setString(Screen0_TimeElapsedValueLabel, (leString*)&string_TimeElapsedDefault);
    Screen0_DrugInfoPressureBox->fn->addChild(Screen0_DrugInfoPressureBox, (leWidget*)Screen0_TimeElapsedValueLabel);

    Screen0_PressKnobActiveArea = leWidget_New();
    Screen0_PressKnobActiveArea->fn->setPosition(Screen0_PressKnobActiveArea, 27, 47);
    Screen0_PressKnobActiveArea->fn->setSize(Screen0_PressKnobActiveArea, 274, 157);
    Screen0_PressKnobActiveArea->fn->setEnabled(Screen0_PressKnobActiveArea, LE_FALSE);
    Screen0_PressKnobActiveArea->fn->setBackgroundType(Screen0_PressKnobActiveArea, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DrugInfoPressureBox->fn->addChild(Screen0_DrugInfoPressureBox, (leWidget*)Screen0_PressKnobActiveArea);

    Screen0_PressKnobArea = leWidget_New();
    Screen0_PressKnobArea->fn->setPosition(Screen0_PressKnobArea, 47, 67);
    Screen0_PressKnobArea->fn->setSize(Screen0_PressKnobArea, 234, 117);
    Screen0_PressKnobArea->fn->setEnabled(Screen0_PressKnobArea, LE_FALSE);
    Screen0_PressKnobArea->fn->setVisible(Screen0_PressKnobArea, LE_FALSE);
    Screen0_PressKnobArea->fn->setBackgroundType(Screen0_PressKnobArea, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DrugInfoPressureBox->fn->addChild(Screen0_DrugInfoPressureBox, (leWidget*)Screen0_PressKnobArea);

    Screen0_MedButton = leButtonWidget_New();
    Screen0_MedButton->fn->setPosition(Screen0_MedButton, 22, 30);
    Screen0_MedButton->fn->setSize(Screen0_MedButton, 329, 100);
    Screen0_MedButton->fn->setScheme(Screen0_MedButton, &BaseScheme);
    Screen0_MedButton->fn->setBackgroundType(Screen0_MedButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MedButton->fn->setBorderType(Screen0_MedButton, LE_WIDGET_BORDER_NONE);
    Screen0_MedButton->fn->setString(Screen0_MedButton, (leString*)&string_Atropine);
    Screen0_MedButton->fn->setPressedImage(Screen0_MedButton, (leImage*)&DrugABackground);
    Screen0_MedButton->fn->setReleasedImage(Screen0_MedButton, (leImage*)&DrugABackground);
    Screen0_MedButton->fn->setImagePosition(Screen0_MedButton, LE_RELATIVE_POSITION_BEHIND);
    Screen0_MedButton->fn->setReleasedEventCallback(Screen0_MedButton, event_Screen0_MedButton_OnReleased);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_MedButton);

    Screen0_ImageWidget_4 = leImageWidget_New();
    Screen0_ImageWidget_4->fn->setPosition(Screen0_ImageWidget_4, 285, 4);
    Screen0_ImageWidget_4->fn->setSize(Screen0_ImageWidget_4, 39, 37);
    Screen0_ImageWidget_4->fn->setBackgroundType(Screen0_ImageWidget_4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_4->fn->setBorderType(Screen0_ImageWidget_4, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_4->fn->setImage(Screen0_ImageWidget_4, (leImage*)&reply);
    Screen0_MedButton->fn->addChild(Screen0_MedButton, (leWidget*)Screen0_ImageWidget_4);

    Screen0_WeightBox = leImageWidget_New();
    Screen0_WeightBox->fn->setPosition(Screen0_WeightBox, 368, 30);
    Screen0_WeightBox->fn->setSize(Screen0_WeightBox, 140, 100);
    Screen0_WeightBox->fn->setBackgroundType(Screen0_WeightBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_WeightBox->fn->setBorderType(Screen0_WeightBox, LE_WIDGET_BORDER_NONE);
    Screen0_WeightBox->fn->setImage(Screen0_WeightBox, (leImage*)&WeightVolumeBox);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_WeightBox);

    Screen0_WeightLabel = leLabelWidget_New();
    Screen0_WeightLabel->fn->setPosition(Screen0_WeightLabel, 16, 11);
    Screen0_WeightLabel->fn->setSize(Screen0_WeightLabel, 112, 25);
    Screen0_WeightLabel->fn->setEnabled(Screen0_WeightLabel, LE_FALSE);
    Screen0_WeightLabel->fn->setScheme(Screen0_WeightLabel, &BaseScheme);
    Screen0_WeightLabel->fn->setBackgroundType(Screen0_WeightLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_WeightLabel->fn->setString(Screen0_WeightLabel, (leString*)&string_Weight);
    Screen0_WeightBox->fn->addChild(Screen0_WeightBox, (leWidget*)Screen0_WeightLabel);

    Screen0_WeightValueLabel = leLabelWidget_New();
    Screen0_WeightValueLabel->fn->setPosition(Screen0_WeightValueLabel, 20, 35);
    Screen0_WeightValueLabel->fn->setSize(Screen0_WeightValueLabel, 105, 52);
    Screen0_WeightValueLabel->fn->setEnabled(Screen0_WeightValueLabel, LE_FALSE);
    Screen0_WeightValueLabel->fn->setScheme(Screen0_WeightValueLabel, &BaseScheme);
    Screen0_WeightValueLabel->fn->setBackgroundType(Screen0_WeightValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_WeightValueLabel->fn->setString(Screen0_WeightValueLabel, (leString*)&string_WeightDefault);
    Screen0_WeightBox->fn->addChild(Screen0_WeightBox, (leWidget*)Screen0_WeightValueLabel);

    Screen0_SetWeightButton = leButtonWidget_New();
    Screen0_SetWeightButton->fn->setPosition(Screen0_SetWeightButton, 4, 5);
    Screen0_SetWeightButton->fn->setSize(Screen0_SetWeightButton, 131, 89);
    Screen0_SetWeightButton->fn->setBackgroundType(Screen0_SetWeightButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SetWeightButton->fn->setBorderType(Screen0_SetWeightButton, LE_WIDGET_BORDER_NONE);
    Screen0_SetWeightButton->fn->setReleasedEventCallback(Screen0_SetWeightButton, event_Screen0_SetWeightButton_OnReleased);
    Screen0_WeightBox->fn->addChild(Screen0_WeightBox, (leWidget*)Screen0_SetWeightButton);

    Screen0_DoseRateBox = leImageWidget_New();
    Screen0_DoseRateBox->fn->setPosition(Screen0_DoseRateBox, 368, 138);
    Screen0_DoseRateBox->fn->setSize(Screen0_DoseRateBox, 290, 118);
    Screen0_DoseRateBox->fn->setBackgroundType(Screen0_DoseRateBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DoseRateBox->fn->setBorderType(Screen0_DoseRateBox, LE_WIDGET_BORDER_NONE);
    Screen0_DoseRateBox->fn->setImage(Screen0_DoseRateBox, (leImage*)&AdjustButton);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_DoseRateBox);

    Screen0_DoseRateLabel = leLabelWidget_New();
    Screen0_DoseRateLabel->fn->setPosition(Screen0_DoseRateLabel, 16, 11);
    Screen0_DoseRateLabel->fn->setSize(Screen0_DoseRateLabel, 170, 25);
    Screen0_DoseRateLabel->fn->setEnabled(Screen0_DoseRateLabel, LE_FALSE);
    Screen0_DoseRateLabel->fn->setScheme(Screen0_DoseRateLabel, &BaseScheme);
    Screen0_DoseRateLabel->fn->setBackgroundType(Screen0_DoseRateLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DoseRateLabel->fn->setString(Screen0_DoseRateLabel, (leString*)&string_DoseRate);
    Screen0_DoseRateBox->fn->addChild(Screen0_DoseRateBox, (leWidget*)Screen0_DoseRateLabel);

    Screen0_DoseRateValueLabel = leLabelWidget_New();
    Screen0_DoseRateValueLabel->fn->setPosition(Screen0_DoseRateValueLabel, 20, 40);
    Screen0_DoseRateValueLabel->fn->setSize(Screen0_DoseRateValueLabel, 137, 52);
    Screen0_DoseRateValueLabel->fn->setEnabled(Screen0_DoseRateValueLabel, LE_FALSE);
    Screen0_DoseRateValueLabel->fn->setScheme(Screen0_DoseRateValueLabel, &BaseScheme);
    Screen0_DoseRateValueLabel->fn->setBackgroundType(Screen0_DoseRateValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DoseRateValueLabel->fn->setString(Screen0_DoseRateValueLabel, (leString*)&string_DoseRateDefault);
    Screen0_DoseRateBox->fn->addChild(Screen0_DoseRateBox, (leWidget*)Screen0_DoseRateValueLabel);

    Screen0_SetDoseRateButton = leButtonWidget_New();
    Screen0_SetDoseRateButton->fn->setPosition(Screen0_SetDoseRateButton, 1, 7);
    Screen0_SetDoseRateButton->fn->setSize(Screen0_SetDoseRateButton, 184, 101);
    Screen0_SetDoseRateButton->fn->setBackgroundType(Screen0_SetDoseRateButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SetDoseRateButton->fn->setBorderType(Screen0_SetDoseRateButton, LE_WIDGET_BORDER_NONE);
    Screen0_SetDoseRateButton->fn->setReleasedEventCallback(Screen0_SetDoseRateButton, event_Screen0_SetDoseRateButton_OnReleased);
    Screen0_DoseRateBox->fn->addChild(Screen0_DoseRateBox, (leWidget*)Screen0_SetDoseRateButton);

    Screen0_DownDoseRateButton = leButtonWidget_New();
    Screen0_DownDoseRateButton->fn->setPosition(Screen0_DownDoseRateButton, 187, 58);
    Screen0_DownDoseRateButton->fn->setSize(Screen0_DownDoseRateButton, 103, 60);
    Screen0_DownDoseRateButton->fn->setBackgroundType(Screen0_DownDoseRateButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DownDoseRateButton->fn->setBorderType(Screen0_DownDoseRateButton, LE_WIDGET_BORDER_NONE);
    Screen0_DownDoseRateButton->fn->setReleasedEventCallback(Screen0_DownDoseRateButton, event_Screen0_DownDoseRateButton_OnReleased);
    Screen0_DoseRateBox->fn->addChild(Screen0_DoseRateBox, (leWidget*)Screen0_DownDoseRateButton);

    Screen0_UpDoseRateButton = leButtonWidget_New();
    Screen0_UpDoseRateButton->fn->setPosition(Screen0_UpDoseRateButton, 186, 0);
    Screen0_UpDoseRateButton->fn->setSize(Screen0_UpDoseRateButton, 103, 60);
    Screen0_UpDoseRateButton->fn->setBackgroundType(Screen0_UpDoseRateButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_UpDoseRateButton->fn->setBorderType(Screen0_UpDoseRateButton, LE_WIDGET_BORDER_NONE);
    Screen0_UpDoseRateButton->fn->setReleasedEventCallback(Screen0_UpDoseRateButton, event_Screen0_UpDoseRateButton_OnReleased);
    Screen0_DoseRateBox->fn->addChild(Screen0_DoseRateBox, (leWidget*)Screen0_UpDoseRateButton);

    Screen0_VolBox = leImageWidget_New();
    Screen0_VolBox->fn->setPosition(Screen0_VolBox, 518, 30);
    Screen0_VolBox->fn->setSize(Screen0_VolBox, 140, 100);
    Screen0_VolBox->fn->setBackgroundType(Screen0_VolBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VolBox->fn->setBorderType(Screen0_VolBox, LE_WIDGET_BORDER_NONE);
    Screen0_VolBox->fn->setImage(Screen0_VolBox, (leImage*)&WeightVolumeBox);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_VolBox);

    Screen0_VolumeLabel = leLabelWidget_New();
    Screen0_VolumeLabel->fn->setPosition(Screen0_VolumeLabel, 16, 11);
    Screen0_VolumeLabel->fn->setSize(Screen0_VolumeLabel, 115, 25);
    Screen0_VolumeLabel->fn->setEnabled(Screen0_VolumeLabel, LE_FALSE);
    Screen0_VolumeLabel->fn->setScheme(Screen0_VolumeLabel, &BaseScheme);
    Screen0_VolumeLabel->fn->setBackgroundType(Screen0_VolumeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VolumeLabel->fn->setString(Screen0_VolumeLabel, (leString*)&string_Vol);
    Screen0_VolBox->fn->addChild(Screen0_VolBox, (leWidget*)Screen0_VolumeLabel);

    Screen0_VolValueLabel = leLabelWidget_New();
    Screen0_VolValueLabel->fn->setPosition(Screen0_VolValueLabel, 20, 35);
    Screen0_VolValueLabel->fn->setSize(Screen0_VolValueLabel, 105, 52);
    Screen0_VolValueLabel->fn->setEnabled(Screen0_VolValueLabel, LE_FALSE);
    Screen0_VolValueLabel->fn->setScheme(Screen0_VolValueLabel, &BaseScheme);
    Screen0_VolValueLabel->fn->setBackgroundType(Screen0_VolValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VolValueLabel->fn->setString(Screen0_VolValueLabel, (leString*)&string_VolDefault);
    Screen0_VolBox->fn->addChild(Screen0_VolBox, (leWidget*)Screen0_VolValueLabel);

    Screen0_SetVolButton = leButtonWidget_New();
    Screen0_SetVolButton->fn->setPosition(Screen0_SetVolButton, 5, 5);
    Screen0_SetVolButton->fn->setSize(Screen0_SetVolButton, 131, 89);
    Screen0_SetVolButton->fn->setBackgroundType(Screen0_SetVolButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SetVolButton->fn->setBorderType(Screen0_SetVolButton, LE_WIDGET_BORDER_NONE);
    Screen0_SetVolButton->fn->setReleasedEventCallback(Screen0_SetVolButton, event_Screen0_SetVolButton_OnReleased);
    Screen0_VolBox->fn->addChild(Screen0_VolBox, (leWidget*)Screen0_SetVolButton);

    Screen0_ConcBox = leImageWidget_New();
    Screen0_ConcBox->fn->setPosition(Screen0_ConcBox, 670, 138);
    Screen0_ConcBox->fn->setSize(Screen0_ConcBox, 290, 118);
    Screen0_ConcBox->fn->setBackgroundType(Screen0_ConcBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ConcBox->fn->setBorderType(Screen0_ConcBox, LE_WIDGET_BORDER_NONE);
    Screen0_ConcBox->fn->setImage(Screen0_ConcBox, (leImage*)&Box290x118);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_ConcBox);

    Screen0_ConcLabel = leLabelWidget_New();
    Screen0_ConcLabel->fn->setPosition(Screen0_ConcLabel, 16, 11);
    Screen0_ConcLabel->fn->setSize(Screen0_ConcLabel, 170, 25);
    Screen0_ConcLabel->fn->setEnabled(Screen0_ConcLabel, LE_FALSE);
    Screen0_ConcLabel->fn->setScheme(Screen0_ConcLabel, &BaseScheme);
    Screen0_ConcLabel->fn->setBackgroundType(Screen0_ConcLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ConcLabel->fn->setString(Screen0_ConcLabel, (leString*)&string_Concentration);
    Screen0_ConcBox->fn->addChild(Screen0_ConcBox, (leWidget*)Screen0_ConcLabel);

    Screen0_ConcValueLabel = leLabelWidget_New();
    Screen0_ConcValueLabel->fn->setPosition(Screen0_ConcValueLabel, 20, 40);
    Screen0_ConcValueLabel->fn->setSize(Screen0_ConcValueLabel, 137, 52);
    Screen0_ConcValueLabel->fn->setEnabled(Screen0_ConcValueLabel, LE_FALSE);
    Screen0_ConcValueLabel->fn->setScheme(Screen0_ConcValueLabel, &BaseScheme);
    Screen0_ConcValueLabel->fn->setBackgroundType(Screen0_ConcValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ConcValueLabel->fn->setString(Screen0_ConcValueLabel, (leString*)&string_VTBIDefault);
    Screen0_ConcBox->fn->addChild(Screen0_ConcBox, (leWidget*)Screen0_ConcValueLabel);

    Screen0_SetConcButton = leButtonWidget_New();
    Screen0_SetConcButton->fn->setPosition(Screen0_SetConcButton, 11, 2);
    Screen0_SetConcButton->fn->setSize(Screen0_SetConcButton, 268, 109);
    Screen0_SetConcButton->fn->setBackgroundType(Screen0_SetConcButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SetConcButton->fn->setBorderType(Screen0_SetConcButton, LE_WIDGET_BORDER_NONE);
    Screen0_SetConcButton->fn->setReleasedEventCallback(Screen0_SetConcButton, event_Screen0_SetConcButton_OnReleased);
    Screen0_ConcBox->fn->addChild(Screen0_ConcBox, (leWidget*)Screen0_SetConcButton);

    Screen0_BolusBox = leImageWidget_New();
    Screen0_BolusBox->fn->setPosition(Screen0_BolusBox, 974, 138);
    Screen0_BolusBox->fn->setSize(Screen0_BolusBox, 290, 118);
    Screen0_BolusBox->fn->setBackgroundType(Screen0_BolusBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BolusBox->fn->setBorderType(Screen0_BolusBox, LE_WIDGET_BORDER_NONE);
    Screen0_BolusBox->fn->setImage(Screen0_BolusBox, (leImage*)&BolusBox);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_BolusBox);

    Screen0_LabelWidget_9 = leLabelWidget_New();
    Screen0_LabelWidget_9->fn->setPosition(Screen0_LabelWidget_9, 18, 37);
    Screen0_LabelWidget_9->fn->setSize(Screen0_LabelWidget_9, 140, 53);
    Screen0_LabelWidget_9->fn->setScheme(Screen0_LabelWidget_9, &BaseScheme);
    Screen0_LabelWidget_9->fn->setBackgroundType(Screen0_LabelWidget_9, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_9->fn->setHAlignment(Screen0_LabelWidget_9, LE_HALIGN_CENTER);
    Screen0_LabelWidget_9->fn->setString(Screen0_LabelWidget_9, (leString*)&string_Bolus);
    Screen0_BolusBox->fn->addChild(Screen0_BolusBox, (leWidget*)Screen0_LabelWidget_9);

    Screen0_DoseModeBox = leImageWidget_New();
    Screen0_DoseModeBox->fn->setPosition(Screen0_DoseModeBox, 368, 272);
    Screen0_DoseModeBox->fn->setSize(Screen0_DoseModeBox, 290, 118);
    Screen0_DoseModeBox->fn->setBackgroundType(Screen0_DoseModeBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DoseModeBox->fn->setBorderType(Screen0_DoseModeBox, LE_WIDGET_BORDER_NONE);
    Screen0_DoseModeBox->fn->setImage(Screen0_DoseModeBox, (leImage*)&AdjustButton);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_DoseModeBox);

    Screen0_DoseModeLabel = leLabelWidget_New();
    Screen0_DoseModeLabel->fn->setPosition(Screen0_DoseModeLabel, 16, 11);
    Screen0_DoseModeLabel->fn->setSize(Screen0_DoseModeLabel, 170, 25);
    Screen0_DoseModeLabel->fn->setEnabled(Screen0_DoseModeLabel, LE_FALSE);
    Screen0_DoseModeLabel->fn->setScheme(Screen0_DoseModeLabel, &BaseScheme);
    Screen0_DoseModeLabel->fn->setBackgroundType(Screen0_DoseModeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DoseModeLabel->fn->setString(Screen0_DoseModeLabel, (leString*)&string_DoseMode);
    Screen0_DoseModeBox->fn->addChild(Screen0_DoseModeBox, (leWidget*)Screen0_DoseModeLabel);

    Screen0_DoseModeValueLabel = leLabelWidget_New();
    Screen0_DoseModeValueLabel->fn->setPosition(Screen0_DoseModeValueLabel, 20, 74);
    Screen0_DoseModeValueLabel->fn->setSize(Screen0_DoseModeValueLabel, 96, 33);
    Screen0_DoseModeValueLabel->fn->setEnabled(Screen0_DoseModeValueLabel, LE_FALSE);
    Screen0_DoseModeValueLabel->fn->setScheme(Screen0_DoseModeValueLabel, &BaseScheme);
    Screen0_DoseModeValueLabel->fn->setBackgroundType(Screen0_DoseModeValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DoseModeValueLabel->fn->setHAlignment(Screen0_DoseModeValueLabel, LE_HALIGN_RIGHT);
    Screen0_DoseModeValueLabel->fn->setString(Screen0_DoseModeValueLabel, (leString*)&string_DoseModeDefault);
    Screen0_DoseModeBox->fn->addChild(Screen0_DoseModeBox, (leWidget*)Screen0_DoseModeValueLabel);

    Screen0_DoseModeType = leLabelWidget_New();
    Screen0_DoseModeType->fn->setPosition(Screen0_DoseModeType, 20, 36);
    Screen0_DoseModeType->fn->setSize(Screen0_DoseModeType, 139, 34);
    Screen0_DoseModeType->fn->setEnabled(Screen0_DoseModeType, LE_FALSE);
    Screen0_DoseModeType->fn->setScheme(Screen0_DoseModeType, &BaseScheme);
    Screen0_DoseModeType->fn->setBackgroundType(Screen0_DoseModeType, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DoseModeType->fn->setString(Screen0_DoseModeType, (leString*)&string_DoseModeRegular);
    Screen0_DoseModeBox->fn->addChild(Screen0_DoseModeBox, (leWidget*)Screen0_DoseModeType);

    Screen0_LabelWidget_7 = leLabelWidget_New();
    Screen0_LabelWidget_7->fn->setPosition(Screen0_LabelWidget_7, 117, 81);
    Screen0_LabelWidget_7->fn->setSize(Screen0_LabelWidget_7, 50, 25);
    Screen0_LabelWidget_7->fn->setEnabled(Screen0_LabelWidget_7, LE_FALSE);
    Screen0_LabelWidget_7->fn->setScheme(Screen0_LabelWidget_7, &BaseScheme);
    Screen0_LabelWidget_7->fn->setBackgroundType(Screen0_LabelWidget_7, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_7->fn->setString(Screen0_LabelWidget_7, (leString*)&string_UnitML);
    Screen0_DoseModeBox->fn->addChild(Screen0_DoseModeBox, (leWidget*)Screen0_LabelWidget_7);

    Screen0_DownDoseModeButton = leButtonWidget_New();
    Screen0_DownDoseModeButton->fn->setPosition(Screen0_DownDoseModeButton, 189, 58);
    Screen0_DownDoseModeButton->fn->setSize(Screen0_DownDoseModeButton, 103, 60);
    Screen0_DownDoseModeButton->fn->setBackgroundType(Screen0_DownDoseModeButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DownDoseModeButton->fn->setBorderType(Screen0_DownDoseModeButton, LE_WIDGET_BORDER_NONE);
    Screen0_DownDoseModeButton->fn->setReleasedEventCallback(Screen0_DownDoseModeButton, event_Screen0_DownDoseModeButton_OnReleased);
    Screen0_DoseModeBox->fn->addChild(Screen0_DoseModeBox, (leWidget*)Screen0_DownDoseModeButton);

    Screen0_UpDoseModeButton = leButtonWidget_New();
    Screen0_UpDoseModeButton->fn->setPosition(Screen0_UpDoseModeButton, 188, 0);
    Screen0_UpDoseModeButton->fn->setSize(Screen0_UpDoseModeButton, 103, 60);
    Screen0_UpDoseModeButton->fn->setBackgroundType(Screen0_UpDoseModeButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_UpDoseModeButton->fn->setBorderType(Screen0_UpDoseModeButton, LE_WIDGET_BORDER_NONE);
    Screen0_UpDoseModeButton->fn->setReleasedEventCallback(Screen0_UpDoseModeButton, event_Screen0_UpDoseModeButton_OnReleased);
    Screen0_DoseModeBox->fn->addChild(Screen0_DoseModeBox, (leWidget*)Screen0_UpDoseModeButton);

    Screen0_VTBIBox = leImageWidget_New();
    Screen0_VTBIBox->fn->setPosition(Screen0_VTBIBox, 670, 271);
    Screen0_VTBIBox->fn->setSize(Screen0_VTBIBox, 290, 118);
    Screen0_VTBIBox->fn->setBackgroundType(Screen0_VTBIBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VTBIBox->fn->setBorderType(Screen0_VTBIBox, LE_WIDGET_BORDER_NONE);
    Screen0_VTBIBox->fn->setImage(Screen0_VTBIBox, (leImage*)&AdjustButton);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_VTBIBox);

    Screen0_VtbiLabel = leLabelWidget_New();
    Screen0_VtbiLabel->fn->setPosition(Screen0_VtbiLabel, 16, 11);
    Screen0_VtbiLabel->fn->setSize(Screen0_VtbiLabel, 170, 25);
    Screen0_VtbiLabel->fn->setEnabled(Screen0_VtbiLabel, LE_FALSE);
    Screen0_VtbiLabel->fn->setScheme(Screen0_VtbiLabel, &BaseScheme);
    Screen0_VtbiLabel->fn->setBackgroundType(Screen0_VtbiLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VtbiLabel->fn->setString(Screen0_VtbiLabel, (leString*)&string_Vtbi);
    Screen0_VTBIBox->fn->addChild(Screen0_VTBIBox, (leWidget*)Screen0_VtbiLabel);

    Screen0_VtbiValueLabel = leLabelWidget_New();
    Screen0_VtbiValueLabel->fn->setPosition(Screen0_VtbiValueLabel, 20, 40);
    Screen0_VtbiValueLabel->fn->setSize(Screen0_VtbiValueLabel, 137, 52);
    Screen0_VtbiValueLabel->fn->setEnabled(Screen0_VtbiValueLabel, LE_FALSE);
    Screen0_VtbiValueLabel->fn->setScheme(Screen0_VtbiValueLabel, &BaseScheme);
    Screen0_VtbiValueLabel->fn->setBackgroundType(Screen0_VtbiValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VtbiValueLabel->fn->setString(Screen0_VtbiValueLabel, (leString*)&string_VTBIDefault);
    Screen0_VTBIBox->fn->addChild(Screen0_VTBIBox, (leWidget*)Screen0_VtbiValueLabel);

    Screen0_SetVtbiButton = leButtonWidget_New();
    Screen0_SetVtbiButton->fn->setPosition(Screen0_SetVtbiButton, 7, 3);
    Screen0_SetVtbiButton->fn->setSize(Screen0_SetVtbiButton, 185, 110);
    Screen0_SetVtbiButton->fn->setBackgroundType(Screen0_SetVtbiButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SetVtbiButton->fn->setBorderType(Screen0_SetVtbiButton, LE_WIDGET_BORDER_NONE);
    Screen0_SetVtbiButton->fn->setReleasedEventCallback(Screen0_SetVtbiButton, event_Screen0_SetVtbiButton_OnReleased);
    Screen0_VTBIBox->fn->addChild(Screen0_VTBIBox, (leWidget*)Screen0_SetVtbiButton);

    Screen0_DownVtbiButton = leButtonWidget_New();
    Screen0_DownVtbiButton->fn->setPosition(Screen0_DownVtbiButton, 192, 58);
    Screen0_DownVtbiButton->fn->setSize(Screen0_DownVtbiButton, 103, 60);
    Screen0_DownVtbiButton->fn->setBackgroundType(Screen0_DownVtbiButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DownVtbiButton->fn->setBorderType(Screen0_DownVtbiButton, LE_WIDGET_BORDER_NONE);
    Screen0_DownVtbiButton->fn->setReleasedEventCallback(Screen0_DownVtbiButton, event_Screen0_DownVtbiButton_OnReleased);
    Screen0_VTBIBox->fn->addChild(Screen0_VTBIBox, (leWidget*)Screen0_DownVtbiButton);

    Screen0_UpVtbiButton = leButtonWidget_New();
    Screen0_UpVtbiButton->fn->setPosition(Screen0_UpVtbiButton, 191, 0);
    Screen0_UpVtbiButton->fn->setSize(Screen0_UpVtbiButton, 103, 60);
    Screen0_UpVtbiButton->fn->setBackgroundType(Screen0_UpVtbiButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_UpVtbiButton->fn->setBorderType(Screen0_UpVtbiButton, LE_WIDGET_BORDER_NONE);
    Screen0_UpVtbiButton->fn->setReleasedEventCallback(Screen0_UpVtbiButton, event_Screen0_UpVtbiButton_OnReleased);
    Screen0_VTBIBox->fn->addChild(Screen0_VTBIBox, (leWidget*)Screen0_UpVtbiButton);

    Screen0_ProgressBox = leImageWidget_New();
    Screen0_ProgressBox->fn->setPosition(Screen0_ProgressBox, 670, 30);
    Screen0_ProgressBox->fn->setSize(Screen0_ProgressBox, 594, 100);
    Screen0_ProgressBox->fn->setBackgroundType(Screen0_ProgressBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ProgressBox->fn->setBorderType(Screen0_ProgressBox, LE_WIDGET_BORDER_NONE);
    Screen0_ProgressBox->fn->setImage(Screen0_ProgressBox, (leImage*)&ProgressBar);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_ProgressBox);

    Screen0_ProgressArrows = leImageSequenceWidget_New();
    Screen0_ProgressArrows->fn->setPosition(Screen0_ProgressArrows, 22, 30);
    Screen0_ProgressArrows->fn->setSize(Screen0_ProgressArrows, 300, 40);
    Screen0_ProgressArrows->fn->setBackgroundType(Screen0_ProgressArrows, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ProgressArrows->fn->setRepeat(Screen0_ProgressArrows, LE_TRUE);
    Screen0_ProgressArrows->fn->setImageCount(Screen0_ProgressArrows, 18);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 0, &chevron0);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 0, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 1, &chevron1);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 1, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 2, &chevron2);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 2, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 3, &chevron3);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 3, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 4, &chevron4);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 4, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 5, &chevron5);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 5, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 6, &chevron6);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 6, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 7, &chevron7);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 7, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 8, &chevron8);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 8, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 9, &chevron9);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 9, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 10, &chevron10);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 10, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 11, &chevron11);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 11, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 12, &chevron12);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 12, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 13, &chevron13);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 13, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 14, &chevron14);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 14, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 15, &chevron15);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 15, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 16, &chevron16);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 16, 1000);
    Screen0_ProgressArrows->fn->setImage(Screen0_ProgressArrows, 17, &chevron17);
    Screen0_ProgressArrows->fn->setImageDelay(Screen0_ProgressArrows, 17, 1000);
    Screen0_ProgressBox->fn->addChild(Screen0_ProgressBox, (leWidget*)Screen0_ProgressArrows);

    Screen0_LabelWidget_1_1_1 = leLabelWidget_New();
    Screen0_LabelWidget_1_1_1->fn->setPosition(Screen0_LabelWidget_1_1_1, 332, 18);
    Screen0_LabelWidget_1_1_1->fn->setSize(Screen0_LabelWidget_1_1_1, 112, 25);
    Screen0_LabelWidget_1_1_1->fn->setEnabled(Screen0_LabelWidget_1_1_1, LE_FALSE);
    Screen0_LabelWidget_1_1_1->fn->setScheme(Screen0_LabelWidget_1_1_1, &BaseScheme);
    Screen0_LabelWidget_1_1_1->fn->setBackgroundType(Screen0_LabelWidget_1_1_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1_1_1->fn->setHAlignment(Screen0_LabelWidget_1_1_1, LE_HALIGN_CENTER);
    Screen0_LabelWidget_1_1_1->fn->setString(Screen0_LabelWidget_1_1_1, (leString*)&string_TimeLeft);
    Screen0_ProgressBox->fn->addChild(Screen0_ProgressBox, (leWidget*)Screen0_LabelWidget_1_1_1);

    Screen0_LabelWidget_1_1_2 = leLabelWidget_New();
    Screen0_LabelWidget_1_1_2->fn->setPosition(Screen0_LabelWidget_1_1_2, 474, 18);
    Screen0_LabelWidget_1_1_2->fn->setSize(Screen0_LabelWidget_1_1_2, 112, 25);
    Screen0_LabelWidget_1_1_2->fn->setEnabled(Screen0_LabelWidget_1_1_2, LE_FALSE);
    Screen0_LabelWidget_1_1_2->fn->setScheme(Screen0_LabelWidget_1_1_2, &BaseScheme);
    Screen0_LabelWidget_1_1_2->fn->setBackgroundType(Screen0_LabelWidget_1_1_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1_1_2->fn->setHAlignment(Screen0_LabelWidget_1_1_2, LE_HALIGN_CENTER);
    Screen0_LabelWidget_1_1_2->fn->setString(Screen0_LabelWidget_1_1_2, (leString*)&string_VolLeft);
    Screen0_ProgressBox->fn->addChild(Screen0_ProgressBox, (leWidget*)Screen0_LabelWidget_1_1_2);

    Screen0_TimeLeftValueLabel = leLabelWidget_New();
    Screen0_TimeLeftValueLabel->fn->setPosition(Screen0_TimeLeftValueLabel, 328, 44);
    Screen0_TimeLeftValueLabel->fn->setSize(Screen0_TimeLeftValueLabel, 138, 36);
    Screen0_TimeLeftValueLabel->fn->setEnabled(Screen0_TimeLeftValueLabel, LE_FALSE);
    Screen0_TimeLeftValueLabel->fn->setScheme(Screen0_TimeLeftValueLabel, &BaseScheme);
    Screen0_TimeLeftValueLabel->fn->setBackgroundType(Screen0_TimeLeftValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimeLeftValueLabel->fn->setHAlignment(Screen0_TimeLeftValueLabel, LE_HALIGN_RIGHT);
    Screen0_TimeLeftValueLabel->fn->setString(Screen0_TimeLeftValueLabel, (leString*)&string_TimeLeftDefault);
    Screen0_ProgressBox->fn->addChild(Screen0_ProgressBox, (leWidget*)Screen0_TimeLeftValueLabel);

    Screen0_VolLeftValueLabel = leLabelWidget_New();
    Screen0_VolLeftValueLabel->fn->setPosition(Screen0_VolLeftValueLabel, 489, 44);
    Screen0_VolLeftValueLabel->fn->setSize(Screen0_VolLeftValueLabel, 84, 36);
    Screen0_VolLeftValueLabel->fn->setEnabled(Screen0_VolLeftValueLabel, LE_FALSE);
    Screen0_VolLeftValueLabel->fn->setScheme(Screen0_VolLeftValueLabel, &BaseScheme);
    Screen0_VolLeftValueLabel->fn->setBackgroundType(Screen0_VolLeftValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VolLeftValueLabel->fn->setHAlignment(Screen0_VolLeftValueLabel, LE_HALIGN_RIGHT);
    Screen0_VolLeftValueLabel->fn->setString(Screen0_VolLeftValueLabel, (leString*)&string_VolLeftDefault);
    Screen0_ProgressBox->fn->addChild(Screen0_ProgressBox, (leWidget*)Screen0_VolLeftValueLabel);

    Screen0_StartStopButton = leButtonWidget_New();
    Screen0_StartStopButton->fn->setPosition(Screen0_StartStopButton, 974, 273);
    Screen0_StartStopButton->fn->setSize(Screen0_StartStopButton, 290, 118);
    Screen0_StartStopButton->fn->setBackgroundType(Screen0_StartStopButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_StartStopButton->fn->setBorderType(Screen0_StartStopButton, LE_WIDGET_BORDER_NONE);
    Screen0_StartStopButton->fn->setPressedEventCallback(Screen0_StartStopButton, event_Screen0_StartStopButton_OnPressed);
    Screen0_StartStopButton->fn->setReleasedEventCallback(Screen0_StartStopButton, event_Screen0_StartStopButton_OnReleased);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_StartStopButton);

    Screen0_TopBarPanel = leWidget_New();
    Screen0_TopBarPanel->fn->setPosition(Screen0_TopBarPanel, 0, 0);
    Screen0_TopBarPanel->fn->setSize(Screen0_TopBarPanel, 1280, 30);
    Screen0_TopBarPanel->fn->setEnabled(Screen0_TopBarPanel, LE_FALSE);
    Screen0_TopBarPanel->fn->setBackgroundType(Screen0_TopBarPanel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_TopBarPanel);

    Screen0_WifiIcon = leImageWidget_New();
    Screen0_WifiIcon->fn->setPosition(Screen0_WifiIcon, 1205, 6);
    Screen0_WifiIcon->fn->setSize(Screen0_WifiIcon, 16, 16);
    Screen0_WifiIcon->fn->setBackgroundType(Screen0_WifiIcon, LE_WIDGET_BACKGROUND_NONE);
    Screen0_WifiIcon->fn->setBorderType(Screen0_WifiIcon, LE_WIDGET_BORDER_NONE);
    Screen0_WifiIcon->fn->setImage(Screen0_WifiIcon, (leImage*)&wifi_logo_small);
    Screen0_TopBarPanel->fn->addChild(Screen0_TopBarPanel, (leWidget*)Screen0_WifiIcon);

    Screen0_BatteryIcon = leImageWidget_New();
    Screen0_BatteryIcon->fn->setPosition(Screen0_BatteryIcon, 1150, 7);
    Screen0_BatteryIcon->fn->setSize(Screen0_BatteryIcon, 16, 16);
    Screen0_BatteryIcon->fn->setBackgroundType(Screen0_BatteryIcon, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BatteryIcon->fn->setBorderType(Screen0_BatteryIcon, LE_WIDGET_BORDER_NONE);
    Screen0_BatteryIcon->fn->setImage(Screen0_BatteryIcon, (leImage*)&battery);
    Screen0_TopBarPanel->fn->addChild(Screen0_TopBarPanel, (leWidget*)Screen0_BatteryIcon);

    Screen0_BatteryValueLabel = leLabelWidget_New();
    Screen0_BatteryValueLabel->fn->setPosition(Screen0_BatteryValueLabel, 1166, 6);
    Screen0_BatteryValueLabel->fn->setSize(Screen0_BatteryValueLabel, 39, 16);
    Screen0_BatteryValueLabel->fn->setScheme(Screen0_BatteryValueLabel, &BaseScheme);
    Screen0_BatteryValueLabel->fn->setBackgroundType(Screen0_BatteryValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BatteryValueLabel->fn->setString(Screen0_BatteryValueLabel, (leString*)&string_BatteryLevelDefault);
    Screen0_TopBarPanel->fn->addChild(Screen0_TopBarPanel, (leWidget*)Screen0_BatteryValueLabel);

    Screen0_TimeValueLabel = leLabelWidget_New();
    Screen0_TimeValueLabel->fn->setPosition(Screen0_TimeValueLabel, 1221, 6);
    Screen0_TimeValueLabel->fn->setSize(Screen0_TimeValueLabel, 39, 16);
    Screen0_TimeValueLabel->fn->setScheme(Screen0_TimeValueLabel, &BaseScheme);
    Screen0_TimeValueLabel->fn->setBackgroundType(Screen0_TimeValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimeValueLabel->fn->setHAlignment(Screen0_TimeValueLabel, LE_HALIGN_RIGHT);
    Screen0_TimeValueLabel->fn->setString(Screen0_TimeValueLabel, (leString*)&string_TimeDefault);
    Screen0_TopBarPanel->fn->addChild(Screen0_TopBarPanel, (leWidget*)Screen0_TimeValueLabel);

    Screen0_StartButtonAnim = leImageSequenceWidget_New();
    Screen0_StartButtonAnim->fn->setPosition(Screen0_StartButtonAnim, 920, 230);
    Screen0_StartButtonAnim->fn->setSize(Screen0_StartButtonAnim, 399, 202);
    Screen0_StartButtonAnim->fn->setAlphaAmount(Screen0_StartButtonAnim, 252);
    Screen0_StartButtonAnim->fn->setEnabled(Screen0_StartButtonAnim, LE_FALSE);
    Screen0_StartButtonAnim->fn->setBackgroundType(Screen0_StartButtonAnim, LE_WIDGET_BACKGROUND_NONE);
    Screen0_StartButtonAnim->fn->setRepeat(Screen0_StartButtonAnim, LE_TRUE);
    Screen0_StartButtonAnim->fn->setImageCount(Screen0_StartButtonAnim, 8);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 0, &StartButtonImg);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 0, 1000);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 1, &StartButtonImgPr1);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 1, 1000);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 2, &StartButtonImgPr2);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 2, 1000);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 3, &StartButtonImgPr3);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 3, 1000);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 4, &StartButtonImgPr3);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 4, 1000);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 5, &StartButtonImgPr2);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 5, 1000);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 6, &StartButtonImgPr1);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 6, 1000);
    Screen0_StartButtonAnim->fn->setImage(Screen0_StartButtonAnim, 7, &StartButtonImg);
    Screen0_StartButtonAnim->fn->setImageDelay(Screen0_StartButtonAnim, 7, 1000);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_StartButtonAnim);

    Screen0_StartStopLabel = leLabelWidget_New();
    Screen0_StartStopLabel->fn->setPosition(Screen0_StartStopLabel, 77, 76);
    Screen0_StartStopLabel->fn->setSize(Screen0_StartStopLabel, 140, 53);
    Screen0_StartStopLabel->fn->setEnabled(Screen0_StartStopLabel, LE_FALSE);
    Screen0_StartStopLabel->fn->setScheme(Screen0_StartStopLabel, &BaseScheme);
    Screen0_StartStopLabel->fn->setBackgroundType(Screen0_StartStopLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_StartStopLabel->fn->setHAlignment(Screen0_StartStopLabel, LE_HALIGN_CENTER);
    Screen0_StartStopLabel->fn->setString(Screen0_StartStopLabel, (leString*)&string_Start);
    Screen0_StartButtonAnim->fn->addChild(Screen0_StartButtonAnim, (leWidget*)Screen0_StartStopLabel);

    Screen0_StopButtonAnim = leImageSequenceWidget_New();
    Screen0_StopButtonAnim->fn->setPosition(Screen0_StopButtonAnim, 920, 230);
    Screen0_StopButtonAnim->fn->setSize(Screen0_StopButtonAnim, 399, 202);
    Screen0_StopButtonAnim->fn->setAlphaAmount(Screen0_StopButtonAnim, 252);
    Screen0_StopButtonAnim->fn->setEnabled(Screen0_StopButtonAnim, LE_FALSE);
    Screen0_StopButtonAnim->fn->setVisible(Screen0_StopButtonAnim, LE_FALSE);
    Screen0_StopButtonAnim->fn->setBackgroundType(Screen0_StopButtonAnim, LE_WIDGET_BACKGROUND_NONE);
    Screen0_StopButtonAnim->fn->setRepeat(Screen0_StopButtonAnim, LE_TRUE);
    Screen0_StopButtonAnim->fn->setImageCount(Screen0_StopButtonAnim, 8);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 0, &StopButtonImg);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 0, 1000);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 1, &StopButtonImgPr1);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 1, 1000);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 2, &StopButtonImgPr2);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 2, 1000);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 3, &StopButtonImgPr3);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 3, 1000);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 4, &StopButtonImgPr3);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 4, 1000);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 5, &StopButtonImgPr2);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 5, 1000);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 6, &StopButtonImgPr1);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 6, 1000);
    Screen0_StopButtonAnim->fn->setImage(Screen0_StopButtonAnim, 7, &StopButtonImg);
    Screen0_StopButtonAnim->fn->setImageDelay(Screen0_StopButtonAnim, 7, 1000);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_StopButtonAnim);

    Screen0_StartStopLabel_0 = leLabelWidget_New();
    Screen0_StartStopLabel_0->fn->setPosition(Screen0_StartStopLabel_0, 77, 76);
    Screen0_StartStopLabel_0->fn->setSize(Screen0_StartStopLabel_0, 140, 53);
    Screen0_StartStopLabel_0->fn->setEnabled(Screen0_StartStopLabel_0, LE_FALSE);
    Screen0_StartStopLabel_0->fn->setScheme(Screen0_StartStopLabel_0, &BaseScheme);
    Screen0_StartStopLabel_0->fn->setBackgroundType(Screen0_StartStopLabel_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_StartStopLabel_0->fn->setHAlignment(Screen0_StartStopLabel_0, LE_HALIGN_CENTER);
    Screen0_StartStopLabel_0->fn->setString(Screen0_StartStopLabel_0, (leString*)&string_Stop);
    Screen0_StopButtonAnim->fn->addChild(Screen0_StopButtonAnim, (leWidget*)Screen0_StartStopLabel_0);

    Screen0_ImageWidget_1_0 = leImageWidget_New();
    Screen0_ImageWidget_1_0->fn->setPosition(Screen0_ImageWidget_1_0, 24, 6);
    Screen0_ImageWidget_1_0->fn->setSize(Screen0_ImageWidget_1_0, 117, 17);
    Screen0_ImageWidget_1_0->fn->setBackgroundType(Screen0_ImageWidget_1_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_1_0->fn->setBorderType(Screen0_ImageWidget_1_0, LE_WIDGET_BORDER_NONE);
    Screen0_DrugScreenPanel->fn->addChild(Screen0_DrugScreenPanel, (leWidget*)Screen0_ImageWidget_1_0);

    leAddRootWidget(root3, 3);
    leSetLayerColorMode(3, LE_COLOR_MODE_RGBA_8888);

    // layer 4
    root4 = leWidget_New();
    root4->fn->setSize(root4, 1280, 400);
    root4->fn->setBackgroundType(root4, LE_WIDGET_BACKGROUND_NONE);
    root4->fn->setMargins(root4, 0, 0, 0, 0);
    root4->flags |= LE_WIDGET_IGNOREEVENTS;
    root4->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_NumEditPanel = leWidget_New();
    Screen0_NumEditPanel->fn->setPosition(Screen0_NumEditPanel, 0, 0);
    Screen0_NumEditPanel->fn->setSize(Screen0_NumEditPanel, 1280, 400);
    Screen0_NumEditPanel->fn->setEnabled(Screen0_NumEditPanel, LE_FALSE);
    Screen0_NumEditPanel->fn->setScheme(Screen0_NumEditPanel, &TranslucentScheme);
    root4->fn->addChild(root4, (leWidget*)Screen0_NumEditPanel);

    Screen0_NumEntryBox = leImageWidget_New();
    Screen0_NumEntryBox->fn->setPosition(Screen0_NumEntryBox, 284, 140);
    Screen0_NumEntryBox->fn->setSize(Screen0_NumEntryBox, 290, 118);
    Screen0_NumEntryBox->fn->setBackgroundType(Screen0_NumEntryBox, LE_WIDGET_BACKGROUND_NONE);
    Screen0_NumEntryBox->fn->setBorderType(Screen0_NumEntryBox, LE_WIDGET_BORDER_NONE);
    Screen0_NumEntryBox->fn->setImage(Screen0_NumEntryBox, (leImage*)&Box290x118);
    Screen0_NumEditPanel->fn->addChild(Screen0_NumEditPanel, (leWidget*)Screen0_NumEntryBox);

    Screen0_NumEntryLabel = leLabelWidget_New();
    Screen0_NumEntryLabel->fn->setPosition(Screen0_NumEntryLabel, 16, 11);
    Screen0_NumEntryLabel->fn->setSize(Screen0_NumEntryLabel, 170, 25);
    Screen0_NumEntryLabel->fn->setEnabled(Screen0_NumEntryLabel, LE_FALSE);
    Screen0_NumEntryLabel->fn->setScheme(Screen0_NumEntryLabel, &BaseScheme);
    Screen0_NumEntryLabel->fn->setBackgroundType(Screen0_NumEntryLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_NumEntryLabel->fn->setString(Screen0_NumEntryLabel, (leString*)&string_DoseRate);
    Screen0_NumEntryBox->fn->addChild(Screen0_NumEntryBox, (leWidget*)Screen0_NumEntryLabel);

    Screen0_NumEntryTextField = leTextFieldWidget_New();
    Screen0_NumEntryTextField->fn->setPosition(Screen0_NumEntryTextField, 20, 37);
    Screen0_NumEntryTextField->fn->setSize(Screen0_NumEntryTextField, 158, 59);
    Screen0_NumEntryTextField->fn->setScheme(Screen0_NumEntryTextField, &BaseScheme);
    Screen0_NumEntryTextField->fn->setBackgroundType(Screen0_NumEntryTextField, LE_WIDGET_BACKGROUND_NONE);
    Screen0_NumEntryTextField->fn->setBorderType(Screen0_NumEntryTextField, LE_WIDGET_BORDER_NONE);
    Screen0_NumEntryTextField->fn->setHAlignment(Screen0_NumEntryTextField, LE_HALIGN_LEFT);
    Screen0_NumEntryTextField->fn->setString(Screen0_NumEntryTextField, (leString*)&string_DoseRateDefault);
    Screen0_NumEntryTextField->fn->setHintString(Screen0_NumEntryTextField, (leString*)&string_DoseModeDefault);
    Screen0_NumEntryTextField->fn->setFont(Screen0_NumEntryTextField, (leFont*)&BigBoldNum);
    Screen0_NumEntryTextField->fn->setClearValueOnFirstEdit(Screen0_NumEntryTextField, LE_FALSE);
    Screen0_NumEntryBox->fn->addChild(Screen0_NumEntryBox, (leWidget*)Screen0_NumEntryTextField);

    Screen0_KeypadPanel = leWidget_New();
    Screen0_KeypadPanel->fn->setPosition(Screen0_KeypadPanel, 608, 33);
    Screen0_KeypadPanel->fn->setSize(Screen0_KeypadPanel, 390, 337);
    Screen0_KeypadPanel->fn->setScheme(Screen0_KeypadPanel, &TranslucentScheme);
    Screen0_KeypadPanel->fn->setBackgroundType(Screen0_KeypadPanel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_NumEditPanel->fn->addChild(Screen0_NumEditPanel, (leWidget*)Screen0_KeypadPanel);

    Screen0_NumEntryKeypad = leKeyPadWidget_New(4, 4);
    Screen0_NumEntryKeypad->fn->setPosition(Screen0_NumEntryKeypad, 13, 10);
    Screen0_NumEntryKeypad->fn->setSize(Screen0_NumEntryKeypad, 371, 315);
    Screen0_NumEntryKeypad->fn->setAlphaAmount(Screen0_NumEntryKeypad, 127);
    Screen0_NumEntryKeypad->fn->setScheme(Screen0_NumEntryKeypad, &TranslucentScheme);
    Screen0_NumEntryKeypad->fn->setBackgroundType(Screen0_NumEntryKeypad, LE_WIDGET_BACKGROUND_NONE);
    Screen0_NumEntryKeypad->fn->setBorderType(Screen0_NumEntryKeypad, LE_WIDGET_BORDER_LINE);
    leButtonWidget* cell_0_0 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 0, 0);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 0, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 0, 0, (leString*)&string_Key1);
    cell_0_0->fn->setString(cell_0_0, (leString*)&string_KeySpace);
    leButtonWidget* cell_0_1 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 0, 1);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 0, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 0, 1, (leString*)&string_Key2);
    cell_0_1->fn->setString(cell_0_1, (leString*)&string_KeySpace);
    leButtonWidget* cell_0_2 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 0, 2);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 0, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 0, 2, (leString*)&string_Key3);
    cell_0_2->fn->setString(cell_0_2, (leString*)&string_KeySpace);
    leButtonWidget* cell_0_3 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 0, 3);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 0, 3, (leString*)&string_KeySpace);
    cell_0_3->fn->setString(cell_0_3, (leString*)&string_KeySpace);
    leButtonWidget* cell_1_0 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 1, 0);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 1, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 1, 0, (leString*)&string_Key4);
    cell_1_0->fn->setString(cell_1_0, (leString*)&string_KeySpace);
    leButtonWidget* cell_1_1 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 1, 1);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 1, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 1, 1, (leString*)&string_Key5);
    cell_1_1->fn->setString(cell_1_1, (leString*)&string_KeySpace);
    leButtonWidget* cell_1_2 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 1, 2);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 1, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 1, 2, (leString*)&string_Key6);
    cell_1_2->fn->setString(cell_1_2, (leString*)&string_KeySpace);
    leButtonWidget* cell_1_3 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 1, 3);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 1, 3, (leString*)&string_KeyDot);
    cell_1_3->fn->setString(cell_1_3, (leString*)&string_KeySpace);
    leButtonWidget* cell_2_0 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 2, 0);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 2, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 2, 0, (leString*)&string_Key7);
    cell_2_0->fn->setString(cell_2_0, (leString*)&string_KeySpace);
    leButtonWidget* cell_2_1 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 2, 1);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 2, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 2, 1, (leString*)&string_Key8);
    cell_2_1->fn->setString(cell_2_1, (leString*)&string_KeySpace);
    leButtonWidget* cell_2_2 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 2, 2);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 2, 2, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 2, 2, (leString*)&string_Key9);
    cell_2_2->fn->setString(cell_2_2, (leString*)&string_KeySpace);
    leButtonWidget* cell_2_3 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 2, 3);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 2, 3, LE_KEYPAD_CELL_ACTION_BACKSPACE);
    cell_2_3->fn->setString(cell_2_3, (leString*)&string_KeySpace);
    leButtonWidget* cell_3_0 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 3, 0);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 3, 0, LE_KEYPAD_CELL_ACTION_APPEND);
    cell_3_0->fn->setString(cell_3_0, (leString*)&string_KeySpace);
    leButtonWidget* cell_3_1 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 3, 1);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 3, 1, LE_KEYPAD_CELL_ACTION_APPEND);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 3, 1, (leString*)&string_Key0);
    cell_3_1->fn->setString(cell_3_1, (leString*)&string_KeySpace);
    leButtonWidget* cell_3_2 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 3, 2);
    Screen0_NumEntryKeypad->fn->setKeyValue(Screen0_NumEntryKeypad, 3, 2, (leString*)&string_Key0);
    cell_3_2->fn->setString(cell_3_2, (leString*)&string_KeySpace);
    leButtonWidget* cell_3_3 = Screen0_NumEntryKeypad->fn->getCellButton(Screen0_NumEntryKeypad, 3, 3);
    Screen0_NumEntryKeypad->fn->setKeyAction(Screen0_NumEntryKeypad, 3, 3, LE_KEYPAD_CELL_ACTION_ACCEPT);
    cell_3_3->fn->setString(cell_3_3, (leString*)&string_KeySpace);
    Screen0_NumEntryKeypad->fn->setKeyClickEventCallback(Screen0_NumEntryKeypad, event_Screen0_NumEntryKeypad_OnKeyClick);
    Screen0_KeypadPanel->fn->addChild(Screen0_KeypadPanel, (leWidget*)Screen0_NumEntryKeypad);

    Screen0_NumEntryKeypadImg = leImageWidget_New();
    Screen0_NumEntryKeypadImg->fn->setPosition(Screen0_NumEntryKeypadImg, 11, 8);
    Screen0_NumEntryKeypadImg->fn->setSize(Screen0_NumEntryKeypadImg, 375, 319);
    Screen0_NumEntryKeypadImg->fn->setEnabled(Screen0_NumEntryKeypadImg, LE_FALSE);
    Screen0_NumEntryKeypadImg->fn->setBackgroundType(Screen0_NumEntryKeypadImg, LE_WIDGET_BACKGROUND_NONE);
    Screen0_NumEntryKeypadImg->fn->setBorderType(Screen0_NumEntryKeypadImg, LE_WIDGET_BORDER_NONE);
    Screen0_NumEntryKeypadImg->fn->setImage(Screen0_NumEntryKeypadImg, (leImage*)&NumericKeypad);
    Screen0_KeypadPanel->fn->addChild(Screen0_KeypadPanel, (leWidget*)Screen0_NumEntryKeypadImg);

    leAddRootWidget(root4, 4);
    leSetLayerColorMode(4, LE_COLOR_MODE_RGBA_8888);

    // layer 5
    root5 = leWidget_New();
    root5->fn->setSize(root5, 1280, 400);
    root5->fn->setBackgroundType(root5, LE_WIDGET_BACKGROUND_NONE);
    root5->fn->setMargins(root5, 0, 0, 0, 0);
    root5->flags |= LE_WIDGET_IGNOREEVENTS;
    root5->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_SuccessScreenPanel = leWidget_New();
    Screen0_SuccessScreenPanel->fn->setPosition(Screen0_SuccessScreenPanel, 0, 0);
    Screen0_SuccessScreenPanel->fn->setSize(Screen0_SuccessScreenPanel, 1280, 400);
    Screen0_SuccessScreenPanel->fn->setEnabled(Screen0_SuccessScreenPanel, LE_FALSE);
    Screen0_SuccessScreenPanel->fn->setScheme(Screen0_SuccessScreenPanel, &TranslucentScheme);
    root5->fn->addChild(root5, (leWidget*)Screen0_SuccessScreenPanel);

    Screen0_SuccessPopupImage = leImageWidget_New();
    Screen0_SuccessPopupImage->fn->setPosition(Screen0_SuccessPopupImage, 344, 65);
    Screen0_SuccessPopupImage->fn->setSize(Screen0_SuccessPopupImage, 600, 268);
    Screen0_SuccessPopupImage->fn->setBackgroundType(Screen0_SuccessPopupImage, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SuccessPopupImage->fn->setBorderType(Screen0_SuccessPopupImage, LE_WIDGET_BORDER_NONE);
    Screen0_SuccessPopupImage->fn->setImage(Screen0_SuccessPopupImage, (leImage*)&popup_success_crop);
    Screen0_SuccessScreenPanel->fn->addChild(Screen0_SuccessScreenPanel, (leWidget*)Screen0_SuccessPopupImage);

    Screen0_SuccessTitleLabel = leLabelWidget_New();
    Screen0_SuccessTitleLabel->fn->setPosition(Screen0_SuccessTitleLabel, 444, 94);
    Screen0_SuccessTitleLabel->fn->setSize(Screen0_SuccessTitleLabel, 450, 50);
    Screen0_SuccessTitleLabel->fn->setEnabled(Screen0_SuccessTitleLabel, LE_FALSE);
    Screen0_SuccessTitleLabel->fn->setScheme(Screen0_SuccessTitleLabel, &BaseScheme);
    Screen0_SuccessTitleLabel->fn->setBackgroundType(Screen0_SuccessTitleLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SuccessTitleLabel->fn->setString(Screen0_SuccessTitleLabel, (leString*)&string_Complete);
    Screen0_SuccessScreenPanel->fn->addChild(Screen0_SuccessScreenPanel, (leWidget*)Screen0_SuccessTitleLabel);

    Screen0_SuccessTitleLabel_0 = leLabelWidget_New();
    Screen0_SuccessTitleLabel_0->fn->setPosition(Screen0_SuccessTitleLabel_0, 450, 156);
    Screen0_SuccessTitleLabel_0->fn->setSize(Screen0_SuccessTitleLabel_0, 400, 26);
    Screen0_SuccessTitleLabel_0->fn->setEnabled(Screen0_SuccessTitleLabel_0, LE_FALSE);
    Screen0_SuccessTitleLabel_0->fn->setScheme(Screen0_SuccessTitleLabel_0, &BaseScheme);
    Screen0_SuccessTitleLabel_0->fn->setBackgroundType(Screen0_SuccessTitleLabel_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SuccessTitleLabel_0->fn->setString(Screen0_SuccessTitleLabel_0, (leString*)&string_CompleteMessage);
    Screen0_SuccessScreenPanel->fn->addChild(Screen0_SuccessScreenPanel, (leWidget*)Screen0_SuccessTitleLabel_0);

    Screen0_SuccessConfirmButtonm = leButtonWidget_New();
    Screen0_SuccessConfirmButtonm->fn->setPosition(Screen0_SuccessConfirmButtonm, 536, 231);
    Screen0_SuccessConfirmButtonm->fn->setSize(Screen0_SuccessConfirmButtonm, 204, 58);
    Screen0_SuccessConfirmButtonm->fn->setScheme(Screen0_SuccessConfirmButtonm, &DarkBaseScheme);
    Screen0_SuccessConfirmButtonm->fn->setBackgroundType(Screen0_SuccessConfirmButtonm, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SuccessConfirmButtonm->fn->setBorderType(Screen0_SuccessConfirmButtonm, LE_WIDGET_BORDER_NONE);
    Screen0_SuccessConfirmButtonm->fn->setString(Screen0_SuccessConfirmButtonm, (leString*)&string_Confirm);
    Screen0_SuccessConfirmButtonm->fn->setPressedImage(Screen0_SuccessConfirmButtonm, (leImage*)&popup_button_crop);
    Screen0_SuccessConfirmButtonm->fn->setReleasedImage(Screen0_SuccessConfirmButtonm, (leImage*)&popup_button_crop);
    Screen0_SuccessConfirmButtonm->fn->setImagePosition(Screen0_SuccessConfirmButtonm, LE_RELATIVE_POSITION_BEHIND);
    Screen0_SuccessConfirmButtonm->fn->setReleasedEventCallback(Screen0_SuccessConfirmButtonm, event_Screen0_SuccessConfirmButtonm_OnReleased);
    Screen0_SuccessScreenPanel->fn->addChild(Screen0_SuccessScreenPanel, (leWidget*)Screen0_SuccessConfirmButtonm);

    leAddRootWidget(root5, 5);
    leSetLayerColorMode(5, LE_COLOR_MODE_RGBA_8888);

    Screen0_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);
    root3->fn->setSize(root3, root3->rect.width, root3->rect.height);
    root4->fn->setSize(root4, root4->rect.width, root4->rect.height);
    root5->fn->setSize(root5, root5->rect.width, root5->rect.height);

    Screen0_OnUpdate(); // raise event
}

void screenHide_Screen0(void)
{
    Screen0_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_SplashPanel = NULL;
    Screen0_ImageWidget_0 = NULL;
    Screen0_LabelWidget_1 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_MedsMenuPanel = NULL;
    Screen0_MedsMenuPanelBackground = NULL;
    Screen0_Drug0 = NULL;
    Screen0_Drug1 = NULL;
    Screen0_Drug2 = NULL;
    Screen0_Drug3 = NULL;
    Screen0_Drug4 = NULL;
    Screen0_Drug5 = NULL;
    Screen0_Drug6 = NULL;
    Screen0_Drug7 = NULL;
    Screen0_Drug8 = NULL;
    Screen0_Drug9 = NULL;
    Screen0_Drug10 = NULL;
    Screen0_Drug11 = NULL;
    Screen0_Drug12 = NULL;
    Screen0_Drug13 = NULL;
    Screen0_Drug14 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    Screen0_MainMenuPanel = NULL;
    Screen0_MainMenuPanel_0 = NULL;
    Screen0_ImageWidget_1 = NULL;
    Screen0_ButtonWidget_0 = NULL;
    Screen0_ButtonWidget_0_0 = NULL;
    Screen0_ButtonWidget_0_2 = NULL;
    Screen0_ButtonWidget_0_3 = NULL;
    Screen0_ButtonWidget_0_4 = NULL;
    Screen0_ButtonWidget_0_5 = NULL;
    Screen0_ButtonWidget_0_2_0 = NULL;
    Screen0_LabelWidget_0 = NULL;

    leRemoveRootWidget(root3, 3);
    leWidget_Delete(root3);
    root3 = NULL;

    Screen0_DrugScreenPanel = NULL;
    Screen0_DrugInfoPressureBox = NULL;
    Screen0_MedButton = NULL;
    Screen0_WeightBox = NULL;
    Screen0_DoseRateBox = NULL;
    Screen0_VolBox = NULL;
    Screen0_ConcBox = NULL;
    Screen0_BolusBox = NULL;
    Screen0_DoseModeBox = NULL;
    Screen0_VTBIBox = NULL;
    Screen0_ProgressBox = NULL;
    Screen0_StartStopButton = NULL;
    Screen0_TopBarPanel = NULL;
    Screen0_StartButtonAnim = NULL;
    Screen0_StopButtonAnim = NULL;
    Screen0_ImageWidget_1_0 = NULL;
    Screen0_KnobImage = NULL;
    Screen0_LabelWidget_1_1 = NULL;
    Screen0_PressureValueLabel = NULL;
    Screen0_LabelWidget_1_1_3 = NULL;
    Screen0_TimeElapsedValueLabel = NULL;
    Screen0_PressKnobActiveArea = NULL;
    Screen0_PressKnobArea = NULL;
    Screen0_ImageWidget_4 = NULL;
    Screen0_WeightLabel = NULL;
    Screen0_WeightValueLabel = NULL;
    Screen0_SetWeightButton = NULL;
    Screen0_DoseRateLabel = NULL;
    Screen0_DoseRateValueLabel = NULL;
    Screen0_SetDoseRateButton = NULL;
    Screen0_DownDoseRateButton = NULL;
    Screen0_UpDoseRateButton = NULL;
    Screen0_VolumeLabel = NULL;
    Screen0_VolValueLabel = NULL;
    Screen0_SetVolButton = NULL;
    Screen0_ConcLabel = NULL;
    Screen0_ConcValueLabel = NULL;
    Screen0_SetConcButton = NULL;
    Screen0_LabelWidget_9 = NULL;
    Screen0_DoseModeLabel = NULL;
    Screen0_DoseModeValueLabel = NULL;
    Screen0_DoseModeType = NULL;
    Screen0_LabelWidget_7 = NULL;
    Screen0_DownDoseModeButton = NULL;
    Screen0_UpDoseModeButton = NULL;
    Screen0_VtbiLabel = NULL;
    Screen0_VtbiValueLabel = NULL;
    Screen0_SetVtbiButton = NULL;
    Screen0_DownVtbiButton = NULL;
    Screen0_UpVtbiButton = NULL;
    Screen0_ProgressArrows = NULL;
    Screen0_LabelWidget_1_1_1 = NULL;
    Screen0_LabelWidget_1_1_2 = NULL;
    Screen0_TimeLeftValueLabel = NULL;
    Screen0_VolLeftValueLabel = NULL;
    Screen0_WifiIcon = NULL;
    Screen0_BatteryIcon = NULL;
    Screen0_BatteryValueLabel = NULL;
    Screen0_TimeValueLabel = NULL;
    Screen0_StartStopLabel = NULL;
    Screen0_StartStopLabel_0 = NULL;

    leRemoveRootWidget(root4, 4);
    leWidget_Delete(root4);
    root4 = NULL;

    Screen0_NumEditPanel = NULL;
    Screen0_NumEntryBox = NULL;
    Screen0_KeypadPanel = NULL;
    Screen0_NumEntryLabel = NULL;
    Screen0_NumEntryTextField = NULL;
    Screen0_NumEntryKeypad = NULL;
    Screen0_NumEntryKeypadImg = NULL;

    leRemoveRootWidget(root5, 5);
    leWidget_Delete(root5);
    root5 = NULL;

    Screen0_SuccessScreenPanel = NULL;
    Screen0_SuccessPopupImage = NULL;
    Screen0_SuccessTitleLabel = NULL;
    Screen0_SuccessTitleLabel_0 = NULL;
    Screen0_SuccessConfirmButtonm = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen0(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        case 1:
        {
            return root1;
        }
        case 2:
        {
            return root2;
        }
        case 3:
        {
            return root3;
        }
        case 4:
        {
            return root4;
        }
        case 5:
        {
            return root5;
        }
        default:
        {
            return NULL;
        }
    }
}

