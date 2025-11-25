#include "gfx/legato/generated/screen/le_gen_screen_Home.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;
static leWidget* root3;

leWidget* Home_BackgroundPanel0;
leLabelWidget* Home_LabelWidget0;
leWidget* Home_BackgroundPanel1;
leLabelWidget* Home_LabelWidget1;
leWidget* Home_BackgroundPanel2;
leLabelWidget* Home_LabelWidget2;
leWidget* Home_BackgroundPanel;
leImageWidget* Home_ImageWidgetMCHPLogo;
leImageWidget* Home_ImageWidgetMGSLogo;
leButtonWidget* Home_ButtonWidgetQuickStart;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Home(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Home(void)
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

    Home_BackgroundPanel0 = leWidget_New();
    Home_BackgroundPanel0->fn->setPosition(Home_BackgroundPanel0, 0, 0);
    Home_BackgroundPanel0->fn->setSize(Home_BackgroundPanel0, 240, 240);
    Home_BackgroundPanel0->fn->setScheme(Home_BackgroundPanel0, &WhiteScheme_0);
    root0->fn->addChild(root0, (leWidget*)Home_BackgroundPanel0);

    Home_LabelWidget0 = leLabelWidget_New();
    Home_LabelWidget0->fn->setPosition(Home_LabelWidget0, 21, 67);
    Home_LabelWidget0->fn->setSize(Home_LabelWidget0, 198, 100);
    Home_LabelWidget0->fn->setScheme(Home_LabelWidget0, &BlueScheme_0);
    Home_LabelWidget0->fn->setBackgroundType(Home_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Home_LabelWidget0->fn->setHAlignment(Home_LabelWidget0, LE_HALIGN_CENTER);
    Home_LabelWidget0->fn->setString(Home_LabelWidget0, (leString*)&string_strEasy);
    root0->fn->addChild(root0, (leWidget*)Home_LabelWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 240, 240);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Home_BackgroundPanel1 = leWidget_New();
    Home_BackgroundPanel1->fn->setPosition(Home_BackgroundPanel1, 0, 0);
    Home_BackgroundPanel1->fn->setSize(Home_BackgroundPanel1, 240, 240);
    Home_BackgroundPanel1->fn->setScheme(Home_BackgroundPanel1, &WhiteScheme_0);
    root1->fn->addChild(root1, (leWidget*)Home_BackgroundPanel1);

    Home_LabelWidget1 = leLabelWidget_New();
    Home_LabelWidget1->fn->setPosition(Home_LabelWidget1, 29, 68);
    Home_LabelWidget1->fn->setSize(Home_LabelWidget1, 188, 100);
    Home_LabelWidget1->fn->setScheme(Home_LabelWidget1, &OrangeScheme_0);
    Home_LabelWidget1->fn->setBackgroundType(Home_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    Home_LabelWidget1->fn->setHAlignment(Home_LabelWidget1, LE_HALIGN_CENTER);
    Home_LabelWidget1->fn->setString(Home_LabelWidget1, (leString*)&string_strFast);
    root1->fn->addChild(root1, (leWidget*)Home_LabelWidget1);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGB_565);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 240, 240);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    Home_BackgroundPanel2 = leWidget_New();
    Home_BackgroundPanel2->fn->setPosition(Home_BackgroundPanel2, 0, 0);
    Home_BackgroundPanel2->fn->setSize(Home_BackgroundPanel2, 240, 240);
    Home_BackgroundPanel2->fn->setScheme(Home_BackgroundPanel2, &WhiteScheme_0);
    root2->fn->addChild(root2, (leWidget*)Home_BackgroundPanel2);

    Home_LabelWidget2 = leLabelWidget_New();
    Home_LabelWidget2->fn->setPosition(Home_LabelWidget2, 0, 67);
    Home_LabelWidget2->fn->setSize(Home_LabelWidget2, 240, 100);
    Home_LabelWidget2->fn->setScheme(Home_LabelWidget2, &GreenScheme_0);
    Home_LabelWidget2->fn->setBackgroundType(Home_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    Home_LabelWidget2->fn->setHAlignment(Home_LabelWidget2, LE_HALIGN_CENTER);
    Home_LabelWidget2->fn->setString(Home_LabelWidget2, (leString*)&string_strSmart);
    root2->fn->addChild(root2, (leWidget*)Home_LabelWidget2);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGB_565);

    // layer 3
    root3 = leWidget_New();
    root3->fn->setSize(root3, LE_DEFAULT_SCREEN_WIDTH, LE_DEFAULT_SCREEN_HEIGHT);
    root3->fn->setBackgroundType(root3, LE_WIDGET_BACKGROUND_NONE);
    root3->fn->setMargins(root3, 0, 0, 0, 0);
    root3->flags |= LE_WIDGET_IGNOREEVENTS;
    root3->flags |= LE_WIDGET_IGNOREPICK;

    Home_BackgroundPanel = leWidget_New();
    Home_BackgroundPanel->fn->setPosition(Home_BackgroundPanel, 0, 0);
    Home_BackgroundPanel->fn->setSize(Home_BackgroundPanel, 800, 480);
    Home_BackgroundPanel->fn->setScheme(Home_BackgroundPanel, &WhiteScheme_0);
    root3->fn->addChild(root3, (leWidget*)Home_BackgroundPanel);

    Home_ImageWidgetMCHPLogo = leImageWidget_New();
    Home_ImageWidgetMCHPLogo->fn->setPosition(Home_ImageWidgetMCHPLogo, 578, 16);
    Home_ImageWidgetMCHPLogo->fn->setSize(Home_ImageWidgetMCHPLogo, 206, 48);
    Home_ImageWidgetMCHPLogo->fn->setBackgroundType(Home_ImageWidgetMCHPLogo, LE_WIDGET_BACKGROUND_NONE);
    Home_ImageWidgetMCHPLogo->fn->setBorderType(Home_ImageWidgetMCHPLogo, LE_WIDGET_BORDER_NONE);
    Home_ImageWidgetMCHPLogo->fn->setImage(Home_ImageWidgetMCHPLogo, (leImage*)&mchpBlackLogo);
    root3->fn->addChild(root3, (leWidget*)Home_ImageWidgetMCHPLogo);

    Home_ImageWidgetMGSLogo = leImageWidget_New();
    Home_ImageWidgetMGSLogo->fn->setPosition(Home_ImageWidgetMGSLogo, 0, 0);
    Home_ImageWidgetMGSLogo->fn->setSize(Home_ImageWidgetMGSLogo, 240, 67);
    Home_ImageWidgetMGSLogo->fn->setBackgroundType(Home_ImageWidgetMGSLogo, LE_WIDGET_BACKGROUND_NONE);
    Home_ImageWidgetMGSLogo->fn->setBorderType(Home_ImageWidgetMGSLogo, LE_WIDGET_BORDER_NONE);
    Home_ImageWidgetMGSLogo->fn->setImage(Home_ImageWidgetMGSLogo, (leImage*)&mgsLogo);
    root3->fn->addChild(root3, (leWidget*)Home_ImageWidgetMGSLogo);

    Home_ButtonWidgetQuickStart = leButtonWidget_New();
    Home_ButtonWidgetQuickStart->fn->setPosition(Home_ButtonWidgetQuickStart, 286, 219);
    Home_ButtonWidgetQuickStart->fn->setSize(Home_ButtonWidgetQuickStart, 240, 67);
    Home_ButtonWidgetQuickStart->fn->setBackgroundType(Home_ButtonWidgetQuickStart, LE_WIDGET_BACKGROUND_NONE);
    Home_ButtonWidgetQuickStart->fn->setBorderType(Home_ButtonWidgetQuickStart, LE_WIDGET_BORDER_NONE);
    Home_ButtonWidgetQuickStart->fn->setString(Home_ButtonWidgetQuickStart, (leString*)&string_strQuickstart);
    Home_ButtonWidgetQuickStart->fn->setPressedImage(Home_ButtonWidgetQuickStart, (leImage*)&imgButton1);
    Home_ButtonWidgetQuickStart->fn->setReleasedImage(Home_ButtonWidgetQuickStart, (leImage*)&imgButton2);
    Home_ButtonWidgetQuickStart->fn->setImagePosition(Home_ButtonWidgetQuickStart, LE_RELATIVE_POSITION_BEHIND);
    Home_ButtonWidgetQuickStart->fn->setPressedOffset(Home_ButtonWidgetQuickStart, 0);
    Home_ButtonWidgetQuickStart->fn->setReleasedEventCallback(Home_ButtonWidgetQuickStart, event_Home_ButtonWidgetQuickStart_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Home_ButtonWidgetQuickStart);

    leAddRootWidget(root3, 3);
    leSetLayerColorMode(3, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Home(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);
    root3->fn->setSize(root3, root3->rect.width, root3->rect.height);
}

void screenHide_Home(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Home_BackgroundPanel0 = NULL;
    Home_LabelWidget0 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Home_BackgroundPanel1 = NULL;
    Home_LabelWidget1 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    Home_BackgroundPanel2 = NULL;
    Home_LabelWidget2 = NULL;

    leRemoveRootWidget(root3, 3);
    leWidget_Delete(root3);
    root3 = NULL;

    Home_BackgroundPanel = NULL;
    Home_ImageWidgetMCHPLogo = NULL;
    Home_ImageWidgetMGSLogo = NULL;
    Home_ButtonWidgetQuickStart = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Home(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Home(uint32_t lyrIdx)
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

