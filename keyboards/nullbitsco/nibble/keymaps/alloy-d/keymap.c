/* Copyright 2018 Jack Humbert
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *caterina GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define BASE 0
#define _FN 1

#define C_T_ESC LCTL_T(KC_ESC)

enum custom_keycodes {
  SC_LSPR,
  SC_RSPR,
  SC_LSBR,
  SC_RSBR
};

// TODO
// - encoder
// - colemak layer
// - mute keys on left side?
// - right super key?

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ansi(
               KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
    KC_F13,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,  \
    KC_SYSREQ, C_T_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
    KC_INS,    SC_LSPR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPR,          KC_UP,   KC_PGDN, \
    KC_HYPR,   KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                    MO(_FN), KC_RALT, KC_RCTL, KC_LEFT,          KC_DOWN, KC_RIGHT  \
  ),
  [_FN] = LAYOUT_ansi(
             _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______, \
    _______, KC_LCBR, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,A(KC_LEFT),KC_PGDN,KC_PGUP,A(KC_RGHT),_______,_______, _______, KC_RCBR, _______, \
    _______, KC_BSPC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______, \
    _______, SC_LSBR, _______, _______, KC_BSLS, KC_UNDS, KC_GRV,  _______, KC_END,  KC_HOME, _______, _______, SC_RSBR,          _______, _______, \
    _______, _______, _______, _______,                   _______,                   _______, _______, _______, KC_MPRV,          KC_MPLY, KC_MNXT  \
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case SC_LSPR:
        perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
        return false;
    case SC_RSPR:
        perform_space_cadet(record, keycode, KC_RSFT, KC_RSFT, KC_0);
        return false;
    case SC_LSBR:
        perform_space_cadet(record, keycode, KC_LSFT, _______, KC_LBRC);
        return false;
    case SC_RSBR:
        perform_space_cadet(record, keycode, KC_RSFT, _______, KC_RBRC);
        return false;
  }
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
