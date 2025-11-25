#ifndef LE_GEN_SCREEN_HOME_H
#define LE_GEN_SCREEN_HOME_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Home_BackgroundPanel0;
extern leLabelWidget* Home_LabelWidget0;
extern leWidget* Home_BackgroundPanel1;
extern leLabelWidget* Home_LabelWidget1;
extern leWidget* Home_BackgroundPanel2;
extern leLabelWidget* Home_LabelWidget2;
extern leWidget* Home_BackgroundPanel;
extern leImageWidget* Home_ImageWidgetMCHPLogo;
extern leImageWidget* Home_ImageWidgetMGSLogo;
extern leButtonWidget* Home_ButtonWidgetQuickStart;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Home_ButtonWidgetQuickStart_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Home(void); // called when Legato is initialized
leResult screenShow_Home(void); // called when screen is shown
void screenHide_Home(void); // called when screen is hidden
void screenDestroy_Home(void); // called when Legato is destroyed
void screenUpdate_Home(void); // called when Legato is updating

leWidget* screenGetRoot_Home(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_HOME_H
