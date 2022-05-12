#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _NAV,
    _FN
};

enum custom_keycodes {
    KC_FN = MO(_FN),
    KC_NAV = MO(_NAV),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
      KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DELETE, \
      KC_LBRC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_RBRC  , \
      KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOTE, \
      KC_LCTRL,  KC_Z,   KC_X,    KC_C,   KC_V,    KC_B, KC_MUTE,       XXXXXXX,KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RCTRL, \
                      KC_LGUI, KC_LALT, KC_NAV, KC_LSFT, KC_ENT,      KC_SPC,  KC_BSPC, KC_FN, KC_RALT, KC_RGUI \
    ),
    [_NAV] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, \
      KC_LCTRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTRL, \
              KC_LGUI, KC_LALT, _______, KC_LSFT, KC_ENT,                       KC_SPC, KC_BSPC, XXXXXXX, KC_RALT, KC_RGUI \
    ),
    [_FN] = LAYOUT( \
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                 KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
      XXXXXXX, XXXXXXX, XXXXXXX, KC_EQUAL, XXXXXXX, RGB_TOG,                    XXXXXXX, KC_UNDS, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, \
      XXXXXXX, KC_PLUS, XXXXXXX, KC_MINUS, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      KC_LCTRL, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_RCTRL, \
              KC_LGUI, KC_LALT, XXXXXXX, KC_LSFT, KC_ENT,                       KC_SPC, KC_BSPC, _______, KC_RALT, KC_RGUI \
    )
};

#ifdef RGBLIGHT_ENABLE
#define COLOR_GREEN 85, 250, 255
#define COLOR_PINK 222, 250, 255
#define COLOR_ORANGE 14, 255, 255
#define COLOR_BLUE 171, 250, 255

void lhs_ind(uint8_t h, uint8_t s, uint8_t v) {
    rgblight_sethsv_at(h, s, v, 0);
}

void rhs_ind(uint8_t h, uint8_t s, uint8_t v) {
    rgblight_sethsv_at(h, s, v, 36);
}

void both_ind(uint8_t h, uint8_t s, uint8_t v) {
    lhs_ind(h, s, v);
    rhs_ind(h, s, v);
}
#endif

#ifdef RGBLIGHT_ENABLE

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
#define LHS_BACKLIGHT {1, 6, COLOR_GREEN}
#define RHS_BACKLIGHT {37, 6, COLOR_GREEN}
const rgblight_segment_t PROGMEM main_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {7, 29, COLOR_GREEN},
     {43, 29, COLOR_GREEN}
);

const rgblight_segment_t PROGMEM arr_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {59, 2, COLOR_PINK},
     {65, 1, COLOR_PINK},
     {55, 1, COLOR_PINK},
     {17, 1, COLOR_PINK}
);

const rgblight_segment_t PROGMEM fn_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {11, 2, COLOR_BLUE},
     {21, 2, COLOR_BLUE},
     {31, 2, COLOR_BLUE},
     {67, 2, COLOR_BLUE},
     {57, 2, COLOR_BLUE},
     {47, 2, COLOR_BLUE},
     {14, 1, COLOR_ORANAGE},
     {19, 2, COLOR_ORANGE},
     {28, 1, COLOR_ORANGE},
     {66, 1, COLOR_ORANGE},
     {46, 1, COLOR_ORANGE},
     {49, 1, COLOR_ORANGE},
     {56, 1, COLOR_ORANGE},
     {51, 1, COLOR_ORANGE},
     {53, 1, COLOR_ORANGE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    main_lights,
    arr_lights,
    fn_lights
);

//layer_state_t default_layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
//    return state;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
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

bool alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
    if (alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 800) {
	    unregister_code(KC_LALT);
	    alt_tab_active = false;
	}
    }
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
	oled_write_P(PSTR("hi\nzena"), false);
    } else {
	switch(get_highest_layer(layer_state)) {
		case _QWERTY:
			oled_write_P(PSTR("Def"), false);
			break;
		case _NAV:
			oled_write_P(PSTR("Nav"), false);
			break;
		case _FN:
			oled_write_P(PSTR("FN"), false);
			break;
		default:
			oled_write_P(PSTR("undef"), false);
	}
    }
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else {
	alt_tab_active = true;
	alt_tab_timer = timer_read();
	register_code(KC_LALT);
        if (clockwise) {
	    tap_code(KC_TAB);
	} else {
	    tap_code16(S(KC_TAB));
	}
	   
    }
    return true;
}
#endif
