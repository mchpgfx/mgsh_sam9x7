#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Splash_Panel_0;
leImageWidget* Splash_MicrochipLogo;
leImageWidget* Splash_MGSLogo;
leLineWidget* Splash_AnimLine;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Splash(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Splash(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 720, 720);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Splash_Panel_0 = leWidget_New();
    Splash_Panel_0->fn->setPosition(Splash_Panel_0, 0, 0);
    Splash_Panel_0->fn->setSize(Splash_Panel_0, 720, 720);
    Splash_Panel_0->fn->setScheme(Splash_Panel_0, &BackScheme);
    root0->fn->addChild(root0, (leWidget*)Splash_Panel_0);

    Splash_MicrochipLogo = leImageWidget_New();
    Splash_MicrochipLogo->fn->setPosition(Splash_MicrochipLogo, 203, 330);
    Splash_MicrochipLogo->fn->setSize(Splash_MicrochipLogo, 307, 50);
    Splash_MicrochipLogo->fn->setBackgroundType(Splash_MicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    Splash_MicrochipLogo->fn->setBorderType(Splash_MicrochipLogo, LE_WIDGET_BORDER_NONE);
    Splash_MicrochipLogo->fn->setImage(Splash_MicrochipLogo, (leImage*)&Image0);
    root0->fn->addChild(root0, (leWidget*)Splash_MicrochipLogo);

    Splash_MGSLogo = leImageWidget_New();
    Splash_MGSLogo->fn->setPosition(Splash_MGSLogo, 180, 324);
    Splash_MGSLogo->fn->setSize(Splash_MGSLogo, 360, 90);
    Splash_MGSLogo->fn->setScheme(Splash_MGSLogo, &BackScheme);
    Splash_MGSLogo->fn->setBorderType(Splash_MGSLogo, LE_WIDGET_BORDER_NONE);
    Splash_MGSLogo->fn->setHAlignment(Splash_MGSLogo, LE_HALIGN_LEFT);
    Splash_MGSLogo->fn->setVAlignment(Splash_MGSLogo, LE_VALIGN_TOP);
    Splash_MGSLogo->fn->setImage(Splash_MGSLogo, (leImage*)&MGSLogo);
    root0->fn->addChild(root0, (leWidget*)Splash_MGSLogo);

    Splash_AnimLine = leLineWidget_New();
    Splash_AnimLine->fn->setPosition(Splash_AnimLine, 539, 320);
    Splash_AnimLine->fn->setSize(Splash_AnimLine, 3, 100);
    Splash_AnimLine->fn->setScheme(Splash_AnimLine, &WhiteScheme);
    Splash_AnimLine->fn->setBackgroundType(Splash_AnimLine, LE_WIDGET_BACKGROUND_NONE);
    Splash_AnimLine->fn->setEndPoint(Splash_AnimLine, 0, 100);
    root0->fn->addChild(root0, (leWidget*)Splash_AnimLine);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    Splash_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Splash_OnUpdate(); // raise event
}

void screenHide_Splash(void)
{
    Splash_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Splash_Panel_0 = NULL;
    Splash_MicrochipLogo = NULL;
    Splash_MGSLogo = NULL;
    Splash_AnimLine = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Splash(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Splash(uint32_t lyrIdx)
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

