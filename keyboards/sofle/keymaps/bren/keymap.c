#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _GAME,
    _SYM,
    _ARR,
    _FN
};

enum custom_keycodes {
    KC_FN = MO(_FN),
    KC_SYM = MO(_SYM),
    KC_ARROW = MO(_ARR),
    KC_GAME = TG(_GAME)
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD
} td_state_t;

enum {
    SYM_SHIFT
 };

td_state_t cur_dance(qk_tap_dance_state_t *state);

void sym_shift_finished(qk_tap_dance_state_t *state, void *user_data);
void sym_shit_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
      KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRAVE, \
      KC_DELETE,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_HOME, \
      KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOTE, \
      KC_LCTRL,  KC_Z,   KC_X,    KC_C,   KC_V,    KC_B, KC_MUTE,       XXXXXXX,KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_END, \
                      KC_LALT, KC_LGUI, KC_ARROW, TD(SYM_SHIFT), KC_SPC,      KC_ENT,  KC_BSPC, KC_FN, KC_PGDOWN, KC_PGUP \
    ),
    [_GAME] = LAYOUT( \
      KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRAVE, \
      KC_DELETE,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_HOME, \
      KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOTE, \
      KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,       XXXXXXX,KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_END, \
                    KC_LALT, KC_LGUI, KC_ARROW, KC_LSFT, KC_SPC,                   KC_ENT, KC_BSPC, KC_FN, KC_PGDOWN, KC_PGUP \
    ),
    [_SYM] = LAYOUT( \
      XXXXXXX, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILDE, \
      XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      XXXXXXX, KC_UNDS, KC_LBRC, KC_RBRC, KC_EQUAL, KC_PLUS,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLON, KC_DQUO,\
      KC_LCTRL, KC_MINUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, KC_QUES, XXXXXXX, \
      	     KC_LALT, KC_LGUI, XXXXXXX, _______, KC_SPC,                            KC_ENT, KC_BSPC, XXXXXXX, KC_PGDOWN, KC_PGUP \
    ),
    [_ARR] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, KC_RIGHT, KC_DOWN, KC_LEFT, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX, \
      KC_LCTRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
              KC_LALT, KC_LGUI, _______, KC_LSFT, KC_SPC,                       KC_ENT, KC_BSPC, XXXXXXX, KC_PGDOWN, KC_PGUP \
    ),
    [_FN] = LAYOUT( \
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                 KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
      XXXXXXX, KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                     XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GAME,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      KC_LCTRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
              KC_LALT, KC_LGUI, XXXXXXX, KC_LSFT, KC_SPC,                       KC_ENT, KC_BSPC, _______, KC_PGDOWN, KC_PGUP \
    )
};

#ifdef RGBLIGHT_ENABLE
#define COLOR_MAIN 173, 255, 128 //midnight blue
#define COLOR_ALT 11, 176, 255 // coral pink
#define COLOR_WARN 14, 255, 255 // orange
#define COLOR_BACKLIGHT 11, 176, 255

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

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
	    return TD_SINGLE_TAP;
	} else {
	    return TD_SINGLE_HOLD;
	}
    }
    return TD_UNKNOWN;
}

static td_state_t sym_shift_state;

void sym_shift_finished(qk_tap_dance_state_t *state, void *user_data) {
    sym_shift_state = cur_dance(state);
    switch (sym_shift_state) {
        case TD_SINGLE_TAP:
	    if (layer_state_is(_SYM)) {
		both_ind(0, 0, 0);
		layer_off(_SYM);
	    } else {
		both_ind(COLOR_ALT);
		layer_on(_SYM);
	    }
	    break;
	case TD_SINGLE_HOLD:
	    both_ind(COLOR_MAIN);
	    register_code(KC_LSFT);
	    break;
	default:
	    break;
    }
}

void sym_shift_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (sym_shift_state) {
        case TD_SINGLE_TAP:
	    if (layer_state_is(_SYM)) {
		both_ind(0, 0, 0);
	        layer_off(_SYM);
	    }
            break;
	case TD_SINGLE_HOLD:
            both_ind(0, 0, 0);
	    unregister_code(KC_LSFT);
	    break;
	default:
	    break;
    }
    sym_shift_state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [SYM_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_shift_finished, sym_shift_reset)
};

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
#define LHS_BACKLIGHT {1, 6, COLOR_BACKLIGHT}
#define RHS_BACKLIGHT {37, 6, COLOR_BACKLIGHT}
const rgblight_segment_t PROGMEM main_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {7, 29, COLOR_MAIN},
     {43, 29, COLOR_MAIN}
);

const rgblight_segment_t PROGMEM game_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     {7, 29, COLOR_MAIN},
     {19, 1, COLOR_ALT},
     {23, 2, COLOR_ALT},
     {29, 1, COLOR_ALT}
);

const rgblight_segment_t PROGMEM arr_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     {70, 1, COLOR_MAIN},
     {65, 1, COLOR_MAIN},
     {60, 1, COLOR_MAIN},
     {55, 1, COLOR_MAIN},
     {19, 1, COLOR_MAIN},
     {23, 2, COLOR_MAIN},
     {29, 1, COLOR_MAIN},
     {17, 1, COLOR_ALT}
);

const rgblight_segment_t PROGMEM fn_lights[] = RGBLIGHT_LAYER_SEGMENTS(
     LHS_BACKLIGHT,
     RHS_BACKLIGHT,
     {11, 2, COLOR_MAIN},
     {21, 2, COLOR_MAIN},
     {31, 2, COLOR_MAIN},
     {67, 2, COLOR_MAIN},
     {57, 2, COLOR_MAIN},
     {47, 2, COLOR_MAIN},
     {33, 2, COLOR_MAIN},
     {56, 1, COLOR_MAIN},
     {49, 1, COLOR_MAIN},
     {46, 1, COLOR_MAIN},
     {8, 1, COLOR_MAIN},
     {13, 1, COLOR_WARN},
     {53, 1, COLOR_ALT}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    main_lights,
    game_lights,
    arr_lights,
    fn_lights
);

//layer_state_t default_layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
//    return state;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY) || layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(2, layer_state_cmp(state, _ARR));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN));
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
