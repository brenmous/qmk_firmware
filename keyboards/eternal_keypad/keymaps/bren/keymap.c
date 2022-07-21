/* Copyright 2021 duckyb
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _CFG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
		         KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 
                         KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, 
		KC_VOLU, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H,
		KC_MUTE, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,
		KC_VOLD, KC_SLSH, MO(_CFG), KC_LALT, KC_SPC, KC_PLUS
    ),
    [_CFG] = LAYOUT(
		                _______, _______, _______, _______, _______, _______, _______,
		                _______, _______, _______, _______, _______, _______, _______, 
		_______,        _______, _______, _______, _______, _______, _______, _______, 
		QK_BOOTLOADER,  _______, _______, _______, _______, _______, _______, _______, 
		_______,        _______, _______, _______, _______, _______
    ),
};
