#include "gfx/legato/generated/screen/le_gen_screen_Help.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;
static leWidget* root3;

leWidget* Help_BackgroundPanel_2;
leLabelWidget* Help_LabelWidget_2;
leWidget* Help_BackgroundPanel_1;
leLabelWidget* Help_LabelWidget_1;
leWidget* Help_BackgroundPanel_0;
leLabelWidget* Help_LabelWidget_0;
leWidget* Help_BackgroundPanel;
leImageWidget* Help_ImageWidgetMCHPLogo;
leLabelWidget* Help_LabelWidgetHelp;
leImageWidget* Help_ImageWidgetQRCode;
leImageWidget* Help_ImageWidgetMGSLogo;
leButtonWidget* Help_ButtonWidgetGoHome;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Help(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Help(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 240, 240);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Help_BackgroundPanel_2 = leWidget_New();
    Help_BackgroundPanel_2->fn->setPosition(Help_BackgroundPanel_2, 0, 0);
    Help_BackgroundPanel_2->fn->setSize(Help_BackgroundPanel_2, 240, 240);
    Help_BackgroundPanel_2->fn->setScheme(Help_BackgroundPanel_2, &WhiteScheme_0);
    root0->fn->addChild(root0, (leWidget*)Help_BackgroundPanel_2);

    Help_LabelWidget_2 = leLabelWidget_New();
    Help_LabelWidget_2->fn->setPosition(Help_LabelWidget_2, 0, 67);
    Help_LabelWidget_2->fn->setSize(Help_LabelWidget_2, 240, 100);
    Help_LabelWidget_2->fn->setScheme(Help_LabelWidget_2, &GreenScheme_0);
    Help_LabelWidget_2->fn->setBackgroundType(Help_LabelWidget_2, LE_WIDGET_BACKGROUND_NONE);
    Help_LabelWidget_2->fn->setHAlignment(Help_LabelWidget_2, LE_HALIGN_CENTER);
    Help_LabelWidget_2->fn->setString(Help_LabelWidget_2, (leString*)&string_strSmart);
    root0->fn->addChild(root0, (leWidget*)Help_LabelWidget_2);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 240, 240);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Help_BackgroundPanel_1 = leWidget_New();
    Help_BackgroundPanel_1->fn->setPosition(Help_BackgroundPanel_1, 0, 0);
    Help_BackgroundPanel_1->fn->setSize(Help_BackgroundPanel_1, 240, 240);
    Help_BackgroundPanel_1->fn->setScheme(Help_BackgroundPanel_1, &WhiteScheme_0);
    root1->fn->addChild(root1, (leWidget*)Help_BackgroundPanel_1);

    Help_LabelWidget_1 = leLabelWidget_New();
    Help_LabelWidget_1->fn->setPosition(Help_LabelWidget_1, 20, 67);
    Help_LabelWidget_1->fn->setSize(Help_LabelWidget_1, 198, 100);
    Help_LabelWidget_1->fn->setScheme(Help_LabelWidget_1, &BlueScheme_0);
    Help_LabelWidget_1->fn->setBackgroundType(Help_LabelWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Help_LabelWidget_1->fn->setHAlignment(Help_LabelWidget_1, LE_HALIGN_CENTER);
    Help_LabelWidget_1->fn->setString(Help_LabelWidget_1, (leString*)&string_strEasy);
    root1->fn->addChild(root1, (leWidget*)Help_LabelWidget_1);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGB_565);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 240, 240);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    Help_BackgroundPanel_0 = leWidget_New();
    Help_BackgroundPanel_0->fn->setPosition(Help_BackgroundPanel_0, 0, 0);
    Help_BackgroundPanel_0->fn->setSize(Help_BackgroundPanel_0, 240, 240);
    Help_BackgroundPanel_0->fn->setScheme(Help_BackgroundPanel_0, &WhiteScheme_0);
    root2->fn->addChild(root2, (leWidget*)Help_BackgroundPanel_0);

    Help_LabelWidget_0 = leLabelWidget_New();
    Help_LabelWidget_0->fn->setPosition(Help_LabelWidget_0, 25, 68);
    Help_LabelWidget_0->fn->setSize(Help_LabelWidget_0, 188, 100);
    Help_LabelWidget_0->fn->setScheme(Help_LabelWidget_0, &OrangeScheme_0);
    Help_LabelWidget_0->fn->setBackgroundType(Help_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Help_LabelWidget_0->fn->setHAlignment(Help_LabelWidget_0, LE_HALIGN_CENTER);
    Help_LabelWidget_0->fn->setString(Help_LabelWidget_0, (leString*)&string_strFast);
    root2->fn->addChild(root2, (leWidget*)Help_LabelWidget_0);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGB_565);

    // layer 3
    root3 = leWidget_New();
    root3->fn->setSize(root3, LE_DEFAULT_SCREEN_WIDTH, LE_DEFAULT_SCREEN_HEIGHT);
    root3->fn->setBackgroundType(root3, LE_WIDGET_BACKGROUND_NONE);
    root3->fn->setMargins(root3, 0, 0, 0, 0);
    root3->flags |= LE_WIDGET_IGNOREEVENTS;
    root3->flags |= LE_WIDGET_IGNOREPICK;

    Help_BackgroundPanel = leWidget_New();
    Help_BackgroundPanel->fn->setPosition(Help_BackgroundPanel, 0, 0);
    Help_BackgroundPanel->fn->setSize(Help_BackgroundPanel, 800, 480);
    Help_BackgroundPanel->fn->setScheme(Help_BackgroundPanel, &WhiteScheme_0);
    root3->fn->addChild(root3, (leWidget*)Help_BackgroundPanel);

    Help_ImageWidgetMCHPLogo = leImageWidget_New();
    Help_ImageWidgetMCHPLogo->fn->setPosition(Help_ImageWidgetMCHPLogo, 578, 16);
    Help_ImageWidgetMCHPLogo->fn->setSize(Help_ImageWidgetMCHPLogo, 206, 48);
    Help_ImageWidgetMCHPLogo->fn->setBackgroundType(Help_ImageWidgetMCHPLogo, LE_WIDGET_BACKGROUND_NONE);
    Help_ImageWidgetMCHPLogo->fn->setBorderType(Help_ImageWidgetMCHPLogo, LE_WIDGET_BORDER_NONE);
    Help_ImageWidgetMCHPLogo->fn->setImage(Help_ImageWidgetMCHPLogo, (leImage*)&mchpBlackLogo);
    root3->fn->addChild(root3, (leWidget*)Help_ImageWidgetMCHPLogo);

    Help_LabelWidgetHelp = leLabelWidget_New();
    Help_LabelWidgetHelp->fn->setPosition(Help_LabelWidgetHelp, 119, 72);
    Help_LabelWidgetHelp->fn->setSize(Help_LabelWidgetHelp, 560, 50);
    Help_LabelWidgetHelp->fn->setBackgroundType(Help_LabelWidgetHelp, LE_WIDGET_BACKGROUND_NONE);
    Help_LabelWidgetHelp->fn->setString(Help_LabelWidgetHelp, (leString*)&string_srtHelp);
    root3->fn->addChild(root3, (leWidget*)Help_LabelWidgetHelp);

    Help_ImageWidgetQRCode = leImageWidget_New();
    Help_ImageWidgetQRCode->fn->setPosition(Help_ImageWidgetQRCode, 272, 132);
    Help_ImageWidgetQRCode->fn->setSize(Help_ImageWidgetQRCode, 256, 256);
    Help_ImageWidgetQRCode->fn->setBackgroundType(Help_ImageWidgetQRCode, LE_WIDGET_BACKGROUND_NONE);
    Help_ImageWidgetQRCode->fn->setBorderType(Help_ImageWidgetQRCode, LE_WIDGET_BORDER_NONE);
    Help_ImageWidgetQRCode->fn->setImage(Help_ImageWidgetQRCode, (leImage*)&QR);
    root3->fn->addChild(root3, (leWidget*)Help_ImageWidgetQRCode);

    Help_ImageWidgetMGSLogo = leImageWidget_New();
    Help_ImageWidgetMGSLogo->fn->setPosition(Help_ImageWidgetMGSLogo, 16, 397);
    Help_ImageWidgetMGSLogo->fn->setSize(Help_ImageWidgetMGSLogo, 240, 67);
    Help_ImageWidgetMGSLogo->fn->setBackgroundType(Help_ImageWidgetMGSLogo, LE_WIDGET_BACKGROUND_NONE);
    Help_ImageWidgetMGSLogo->fn->setBorderType(Help_ImageWidgetMGSLogo, LE_WIDGET_BORDER_NONE);
    Help_ImageWidgetMGSLogo->fn->setImage(Help_ImageWidgetMGSLogo, (leImage*)&mgsLogo);
    root3->fn->addChild(root3, (leWidget*)Help_ImageWidgetMGSLogo);

    Help_ButtonWidgetGoHome = leButtonWidget_New();
    Help_ButtonWidgetGoHome->fn->setPosition(Help_ButtonWidgetGoHome, 544, 397);
    Help_ButtonWidgetGoHome->fn->setSize(Help_ButtonWidgetGoHome, 240, 67);
    Help_ButtonWidgetGoHome->fn->setBackgroundType(Help_ButtonWidgetGoHome, LE_WIDGET_BACKGROUND_NONE);
    Help_ButtonWidgetGoHome->fn->setBorderType(Help_ButtonWidgetGoHome, LE_WIDGET_BORDER_NONE);
    Help_ButtonWidgetGoHome->fn->setString(Help_ButtonWidgetGoHome, (leString*)&string_strBack);
    Help_ButtonWidgetGoHome->fn->setPressedImage(Help_ButtonWidgetGoHome, (leImage*)&imgButton1);
    Help_ButtonWidgetGoHome->fn->setReleasedImage(Help_ButtonWidgetGoHome, (leImage*)&imgButton2);
    Help_ButtonWidgetGoHome->fn->setImagePosition(Help_ButtonWidgetGoHome, LE_RELATIVE_POSITION_BEHIND);
    Help_ButtonWidgetGoHome->fn->setPressedOffset(Help_ButtonWidgetGoHome, 0);
    Help_ButtonWidgetGoHome->fn->setReleasedEventCallback(Help_ButtonWidgetGoHome, event_Help_ButtonWidgetGoHome_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Help_ButtonWidgetGoHome);

    leAddRootWidget(root3, 3);
    leSetLayerColorMode(3, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Help(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);
    root3->fn->setSize(root3, root3->rect.width, root3->rect.height);
}

void screenHide_Help(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Help_BackgroundPanel_2 = NULL;
    Help_LabelWidget_2 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Help_BackgroundPanel_1 = NULL;
    Help_LabelWidget_1 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    Help_BackgroundPanel_0 = NULL;
    Help_LabelWidget_0 = NULL;

    leRemoveRootWidget(root3, 3);
    leWidget_Delete(root3);
    root3 = NULL;

    Help_BackgroundPanel = NULL;
    Help_ImageWidgetMCHPLogo = NULL;
    Help_LabelWidgetHelp = NULL;
    Help_ImageWidgetQRCode = NULL;
    Help_ImageWidgetMGSLogo = NULL;
    Help_ButtonWidgetGoHome = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Help(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Help(uint32_t lyrIdx)
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
        default:
        {
            return NULL;
        }
    }
}

