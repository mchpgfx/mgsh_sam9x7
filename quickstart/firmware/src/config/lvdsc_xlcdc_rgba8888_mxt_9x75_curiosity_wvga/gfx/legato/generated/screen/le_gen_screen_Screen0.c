#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen0_BaseFillPanel;
leImageWidget* Screen0_ImageWidget0;
leLabelWidget* Screen0_LabelWidget0;
leLabelWidget* Screen0_LabelWidget1;
leLabelWidget* Screen0_LabelWidget2;
leButtonWidget* Screen0_ButtonWidget0;
leDrawSurfaceWidget* Screen0_lePluginQR;

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
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_BaseFillPanel = leWidget_New();
    Screen0_BaseFillPanel->fn->setPosition(Screen0_BaseFillPanel, 0, 0);
    Screen0_BaseFillPanel->fn->setSize(Screen0_BaseFillPanel, 800, 480);
    Screen0_BaseFillPanel->fn->setScheme(Screen0_BaseFillPanel, &LayerScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_BaseFillPanel);

    Screen0_ImageWidget0 = leImageWidget_New();
    Screen0_ImageWidget0->fn->setPosition(Screen0_ImageWidget0, 11, 11);
    Screen0_ImageWidget0->fn->setSize(Screen0_ImageWidget0, 152, 40);
    Screen0_ImageWidget0->fn->setBackgroundType(Screen0_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget0->fn->setBorderType(Screen0_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget0->fn->setImage(Screen0_ImageWidget0, (leImage*)&mchpLogo_light);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget0);

    Screen0_LabelWidget0 = leLabelWidget_New();
    Screen0_LabelWidget0->fn->setPosition(Screen0_LabelWidget0, 390, 145);
    Screen0_LabelWidget0->fn->setSize(Screen0_LabelWidget0, 110, 50);
    Screen0_LabelWidget0->fn->setScheme(Screen0_LabelWidget0, &RedScheme);
    Screen0_LabelWidget0->fn->setBackgroundType(Screen0_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget0->fn->setString(Screen0_LabelWidget0, (leString*)&string_Fast);
    root0->fn->addChild(root0, (leWidget*)Screen0_LabelWidget0);

    Screen0_LabelWidget1 = leLabelWidget_New();
    Screen0_LabelWidget1->fn->setPosition(Screen0_LabelWidget1, 505, 145);
    Screen0_LabelWidget1->fn->setSize(Screen0_LabelWidget1, 120, 50);
    Screen0_LabelWidget1->fn->setScheme(Screen0_LabelWidget1, &GreenScheme);
    Screen0_LabelWidget1->fn->setBackgroundType(Screen0_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget1->fn->setString(Screen0_LabelWidget1, (leString*)&string_Easy);
    root0->fn->addChild(root0, (leWidget*)Screen0_LabelWidget1);

    Screen0_LabelWidget2 = leLabelWidget_New();
    Screen0_LabelWidget2->fn->setPosition(Screen0_LabelWidget2, 630, 145);
    Screen0_LabelWidget2->fn->setSize(Screen0_LabelWidget2, 160, 50);
    Screen0_LabelWidget2->fn->setScheme(Screen0_LabelWidget2, &BlueScheme);
    Screen0_LabelWidget2->fn->setBackgroundType(Screen0_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget2->fn->setString(Screen0_LabelWidget2, (leString*)&string_Smart);
    root0->fn->addChild(root0, (leWidget*)Screen0_LabelWidget2);

    Screen0_ButtonWidget0 = leButtonWidget_New();
    Screen0_ButtonWidget0->fn->setPosition(Screen0_ButtonWidget0, 455, 240);
    Screen0_ButtonWidget0->fn->setSize(Screen0_ButtonWidget0, 260, 120);
    Screen0_ButtonWidget0->fn->setBackgroundType(Screen0_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget0->fn->setBorderType(Screen0_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget0->fn->setPressedImage(Screen0_ButtonWidget0, (leImage*)&QuickstartDown_WVGA);
    Screen0_ButtonWidget0->fn->setReleasedImage(Screen0_ButtonWidget0, (leImage*)&QuickstartUp_WVGA);
    root0->fn->addChild(root0, (leWidget*)Screen0_ButtonWidget0);

    Screen0_lePluginQR = leDrawSurfaceWidget_New();
    Screen0_lePluginQR->fn->setPosition(Screen0_lePluginQR, 45, 85);
    Screen0_lePluginQR->fn->setSize(Screen0_lePluginQR, 320, 320);
    Screen0_lePluginQR->fn->setBackgroundType(Screen0_lePluginQR, LE_WIDGET_BACKGROUND_NONE);
    Screen0_lePluginQR->fn->setDrawCallback(Screen0_lePluginQR, event_Screen0_lePluginQR_OnDraw);
    root0->fn->addChild(root0, (leWidget*)Screen0_lePluginQR);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_BaseFillPanel = NULL;
    Screen0_ImageWidget0 = NULL;
    Screen0_LabelWidget0 = NULL;
    Screen0_LabelWidget1 = NULL;
    Screen0_LabelWidget2 = NULL;
    Screen0_ButtonWidget0 = NULL;
    Screen0_lePluginQR = NULL;


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
        default:
        {
            return NULL;
        }
    }
}

