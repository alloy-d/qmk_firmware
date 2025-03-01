/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EMPTY,
};

enum custom_keycodes {
  // Space Cadet style parens/braces
  SC_LSPR = SAFE_RANGE,
  SC_RSPR,
  SC_LSBR,
  SC_RSBR,
  SC_LSCB,
  SC_RSCB,
  SC_LACB,
  SC_RACB,
  SC_LCBR,
  SC_RCBR,
  SC_LABR,
  SC_RABR,
  SC_LCCB,
  SC_RCCB,

  KEYMAP_SAFE_RANGE,    // for keys in keymaps
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define C_T_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_QUOT,
    C_T_ESC,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    SC_LSPR,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_RSPR,
                                  KC_LGUI,       LOWER,         KC_SPC,         RAISE,         KC_RALT
  ),

  [_LOWER] = LAYOUT(
  S(KC_LBRC), KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_SLASH, KC_7,     KC_8,     KC_9,     S(KC_P),S(KC_RBRC),
    KC_BSPC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,   KC_EQL,             KC_ASTR,  KC_4,     KC_5,     KC_6,     KC_PLUS,  _______,
    SC_LSBR,  _______,  _______,  KC_BSLS,  KC_UNDS,   KC_GRV,             KC_MINUS, KC_1,     KC_2,     KC_3,     KC_DOT,   SC_RSBR,
                                  _______,       _______,     OSM(MOD_HYPR),    _______,       KC_0
  ),

  [_RAISE] = LAYOUT(
    KC_TILD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,     _______,           A(KC_LEFT),KC_PGDN,  KC_PGUP,A(KC_RGHT), _______,  KC_BSLS,
    KC_LBRC,  KC_F5,    KC_F6,    KC_F7,    KC_F8,     _______,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  KC_RBRC,
    SC_LSCB,  KC_F9,    KC_F10,   KC_F11,   KC_F12,    _______,            KC_HOME,  KC_END,   KC_HOME,  KC_END,   _______,  SC_RSCB,
                                  _______,       _______,       _______,        _______,       KC_LALT
  ),

  [_ADJUST] = LAYOUT(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            KC_MPRV,  KC_MPLY,  XXXXXXX,  KC_MNXT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  _______,       _______,       XXXXXXX,        _______,       _______
  ),

  [_EMPTY] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,       _______,       _______,        _______,       _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
      case SC_LSCB:
        perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_LBRC);
        return false;
      case SC_RSCB:
        perform_space_cadet(record, keycode, KC_RSFT, KC_RSFT, KC_RBRC);
        return false;
      case SC_LCBR:
        perform_space_cadet(record, keycode, KC_LCTL, _______, KC_LBRC);
        return false;
      case SC_RCBR:
        perform_space_cadet(record, keycode, KC_RCTL, _______, KC_RBRC);
        return false;
      case SC_LACB:
        perform_space_cadet(record, keycode, KC_LALT, KC_LSFT, KC_LBRC);
        return false;
      case SC_RACB:
        perform_space_cadet(record, keycode, KC_RALT, KC_RSFT, KC_RBRC);
        return false;
      case SC_LCCB:
        perform_space_cadet(record, keycode, KC_LCTL, KC_LSFT, KC_LBRC);
        return false;
      case SC_RCCB:
        perform_space_cadet(record, keycode, KC_RCTL, KC_RSFT, KC_RBRC);
        return false;
      case SC_LABR:
        perform_space_cadet(record, keycode, KC_LALT, _______, KC_LBRC);
        return false;
      case SC_RABR:
        perform_space_cadet(record, keycode, KC_RALT, _______, KC_RBRC);
        return false;
    }

    return true;
}

