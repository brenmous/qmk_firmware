#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _GAME,
    _ARROWS,
    _FN,
    _META,
};

enum custom_keycodes {
    KC_FN = MO(_FN),
    KC_ARROWS = MO(_ARROWS),
    KC_META = MO(_META),
    KC_GAME = TG(_GAME)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
      KC_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQUAL, \
      KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MINUS, \
      KC_LBRACKET,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOTE, \
      KC_RBRACKET,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,       XXXXXXX,KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLASH, \
                      KC_LALT, KC_LGUI, KC_LCTRL, KC_LSFT, KC_SPC,      KC_ENT,  KC_BSPACE, KC_ARROWS, KC_FN, KC_META \
    ),
    [_GAME] = LAYOUT( \
      KC_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, \
      KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_RBRACKET, \
      KC_LBRACKET,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOTE, \
      KC_RBRACKET,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,       XXXXXXX,KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLASH, \
                    KC_LALT, KC_LGUI, KC_LCTRL, KC_LSFT, KC_SPC,                   KC_ENT, KC_BSPACE, KC_ARROWS, KC_FN, KC_META \
    ),
    [_ARROWS] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,\
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      	     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX \
    ),
    [_FN] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX \
    ),
    [_META] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GAME, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______ \
    ),
};


#ifdef RGBLIGHT_ENABLE

#define COLOR_MAIN 173, 255, 128
//#define COLOR_ALT 31, 255, 73
#define COLOR_ALT 11, 176, 255

extern rgblight_config_t rgblight_config;

/* LED LAYOUT
        11, 12, 21, 22, 31, 32,          68, 67, 58, 57, 48, 47, \
        10, 13, 20, 23, 30, 33,          69, 66, 59, 56, 49, 46, \
        9,  14, 19, 24, 29, 34,  0   36, 70, 65, 60, 55, 50, 45, \
        8,  15, 18, 25, 28, 35,          71, 64, 61, 54, 51, 44, \
          7, 16, 17, 26, 27,              63, 62, 53, 52, 43, \

	             Back lights
       , 1, 2, 3, 4, 5, 6, 42, 41, 40, 39, 38, 37 \
*/
#define LHS_BACKLIGHT {1, 6, COLOR_MAIN}
#define RHS_BACKLIGHT {37, 6, COLOR_MAIN}
const rgblight_segment_t PROGMEM main_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {7, 29, COLOR_MAIN},
     {43, 29, COLOR_MAIN}
);

const rgblight_segment_t PROGMEM game_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     //RHS_BACKLIGHT,
     {7, 29, COLOR_MAIN},
     {19, 1, COLOR_ALT},
     {23, 2, COLOR_ALT},
     {29, 1, COLOR_ALT}
     //{37, 35, COLOR_MAIN}
);

const rgblight_segment_t PROGMEM arrow_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {70, 1, COLOR_MAIN},
     {65, 1, COLOR_MAIN},
     {60, 1, COLOR_MAIN},
     {55, 1, COLOR_MAIN},
     {53, 1, COLOR_ALT}
);

const rgblight_segment_t PROGMEM fn_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {46, 4, COLOR_MAIN},
     {56, 4, COLOR_MAIN},
     {66, 4, COLOR_MAIN},
     {52, 1, COLOR_ALT}
);

const rgblight_segment_t PROGMEM meta_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {43, 1, COLOR_ALT},
     {46, 2, COLOR_MAIN},
     {51, 1, COLOR_MAIN},
     {54, 1, COLOR_MAIN},
     {61, 1, COLOR_MAIN}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    main_lights,
    game_lights,
    arrow_lights,
    fn_lights,
    meta_lights
);

//layer_state_t default_layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
//    return state;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(2, layer_state_cmp(state, _ARROWS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(4, layer_state_cmp(state, _META));
    return state;
}
#endif

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(0, true);
    // Will blank out any LEDs not specified in layers.
    rgblight_config.hue = 0;
    rgblight_config.sat = 0;
    rgblight_config.val = 0;
#endif
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
	oled_write_P(PSTR("sup"), false);
    } else {
        oled_write_P(PSTR("dude"), false);
    }
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
	/* Nice to have, unfortunately layers have to read
	 * from a global 'v' value, which means if we want
	 * to be able to change their brightness we also
	 * need to be happy having a default colour.
	 * (Requires ...RETAIN_VAL set in config)
	if (layer_state_is(_META)) {
	    if (clockwise) {
	        rgblight_decrease_val();
	    } else {
	        rgblight_increase_val();
	    }
        } else {
	*/
            if (clockwise) {
		register_code(KC_LSFT);
		register_code(KC_TAB);
		unregister_code(KC_TAB);
		unregister_code(KC_LSFT);
            } else {
		register_code(KC_LSFT);
		register_code(KC_LALT);
		register_code(KC_TAB);
		unregister_code(KC_TAB);
		unregister_code(KC_LALT);
		unregister_code(KC_LSFT);
            }
        //}
    }
    return true;
}
#endif
