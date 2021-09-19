#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM 72
#define RGB_DI_PIN D3
#define RGBLED_SPLIT {36,36}
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LIMIT_VAL 120
#endif

#ifdef ENCODER_ENABLE
#define ENCODER_DIRECTION_FLIP
#ifdef ENCODER_RESOLUTION
#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4
#endif
#endif

/* Not working
 * Lookup in rgblight.c outputs garbage
#define RGBLIGHT_LED_MAP { \
    11, 12, 21, 22, 31, 32, 68, 67, 58, 57, 48, 47, \
    10, 13, 20, 23, 30, 33, 69, 66, 59, 56, 49, 46, \
    9, 14, 19, 24, 29, 34, 70, 65, 60, 55, 50, 45, \
    8, 15, 18, 25, 28, 35, 71, 64, 61, 54, 51, 44, \
    7, 16, 17, 26, 27, 63, 62, 53, 52, 43, \
    0, 36, 1, 2, 3, 4, 5, 6, 42, 41, 40, 39, 38, 37 \
 }
 */
