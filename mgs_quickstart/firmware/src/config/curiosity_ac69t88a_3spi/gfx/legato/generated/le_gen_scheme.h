#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme WhiteScheme;
extern const leScheme BlueScheme;
extern const leScheme OrangeScheme;
extern const leScheme GreenScheme;
extern const leScheme BlackWhite;
extern const leScheme Scheme1;
extern const leScheme panel_whitesmoke;
extern const leScheme panel_white;
extern const leScheme text_silver;
extern const leScheme text_darkcyan;
extern const leScheme panel_black;
extern const leScheme text_darkgray;
extern const leScheme text_white;
extern const leScheme WhiteScheme_0;
extern const leScheme BlueScheme_0;
extern const leScheme OrangeScheme_0;
extern const leScheme GreenScheme_0;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

void legato_initialize_schemes(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_SCHEME_H
