/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "ortho.h"

extern keymap_config_t keymap_config;

enum ortho_layers {
  _BASE,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _SYM,
  _NUM,
  _NAV,
  _ADJUST
};

enum custom_keycodes {
  CMK_ON = SAFE_RANGE,
  CMK_OFF,
  PLOVER,
  EXT_PLV,
  TMUXCPY,

  // Space Cadet style parens/braces
  SC_LSPR,
  SC_RSPR,
  SC_LSBR,
  SC_RSBR,
  SC_LSCB,
  SC_RSCB,

  KEYMAP_SAFE_RANGE,    // for keys in keymaps
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define C_T_ESC LCTL_T(KC_ESC)
#define S_T_QUO RSFT_T(KC_QUOT)
#define SCRSHOT G(S(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | C/Esc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sft/(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper| Ctrl | Alt  | GUI  |Lower | Space|Space |Raise | GUI  | Alt  | Ctrl |Hyper |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    C_T_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    SC_LSPR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPR,
    KC_HYPR, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  RAISE,   KC_SPC,  KC_RGUI, KC_RALT, KC_RCTL, KC_HYPR
),

/* Colemak overrides
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |      |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower -- almost entirely overridden by NAV and SYM.
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |   =  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   [  |   ]  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Sft/[ |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  | ]/Sft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho(
    _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______, _______, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,     KC_ASTR,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_BSPC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,     KC_PLUS,    KC_LBRC, KC_RBRC, KC_QUOT,
    SC_LSBR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS),  S(KC_NUBS), KC_HOME, KC_END,  SC_RSBR,
    _______, _______, _______, _______, _______, _______, _______, _______,     KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise -- composed with NAV
 * ,-----------------------------------------------------------------------------------.
 * | Ins  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |SysReq|
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |   `  |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Sft/{ |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      | }/Sft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |TG NAV|      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho(
    KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_SYSREQ,
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, KC_BSLS,
    KC_BSPC, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
    SC_LSCB, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, SC_RSCB,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Symbols (&c) -- composed with LOWER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   ^  |   &  |   *  |   -  |   =  |      |      |      |      |      |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Sft/[ |G-S-F4|  F5  |   \  |   _  |   `  |      |      |      |      |      | ]/Sft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |  Ins |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_ortho(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, _______, _______, _______,
    KC_BSPC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______, _______, _______, _______, _______, KC_QUOT,
    SC_LSBR, SCRSHOT, KC_F5,   KC_BSLS, KC_UNDS, KC_GRV,  _______, _______, _______, _______, _______, SC_RSBR,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS
),

/* Num -- composed with LOWER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |      |      |      |      |      |      |  /   |  7   |  8   |  9   |  :   |      | (S-P == colon under software Colemak.)
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  *   |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  -   |  1   |  2   |  3   | Entr |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |  .   | Entr |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_ortho(
    _______, _______, _______, _______, _______, _______, _______,      _______,_______,_______,_______,    _______,
    _______, _______, _______, _______, _______, _______, KC_SLASH,     KC_7,   KC_8,   KC_9,   S(KC_P),    _______,
    _______, _______, _______, _______, _______, _______, KC_ASTERISK,  KC_4,   KC_5,   KC_6,   KC_PLUS,    _______,
    _______, _______, _______, _______, _______, _______, KC_MINUS,     KC_1,   KC_2,   KC_3,   KC_ENTER,   _______,
    _______, _______, _______, _______, _______, _______, _______,      _______,KC_0,   KC_DOT, KC_ENTER,   _______
),

/* Nav -- composed with RAISE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |      |      |      |      |      |      | M-Lft| PgDn | PgUp |M-Rgt |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down |  Up  |Right |      |tmuxcp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | End  | Home |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_ortho(
    _______, _______, _______, _______, _______, _______, _______,      _______,    _______,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, A(KC_LEFT),   KC_PGDN,    KC_PGUP, A(KC_RGHT), _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT,      KC_DOWN,    KC_UP  ,    KC_RGHT, _______, TMUXCPY,
    _______, _______, _______, _______, _______, _______, _______,      KC_END,     KC_HOME,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______,    _______,    _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_ortho(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - +- - - |
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |KeyLck|      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    KC_LOCK, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, CMK_OFF, CMK_ON,   _______, PLOVER,  _______,
    KC_CAPS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    // Compose lower with the SYM and NUM layers.
    if (state & (1UL << _LOWER)) {
        state |= (1UL << _SYM) | (1UL << _NUM);
    } else {
        state &= ~((1UL << _SYM) | (1UL << _NUM));
    }

    // Compose raise with the NAV layer.
    if (state & (1UL << _RAISE)) {
        state |= (1UL << _NAV);
    } else {
        state &= ~(1UL << _NAV);
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case SC_LSPR:
        perform_space_cadet(record, KC_LSFT, KC_LSFT, KC_9);
        return false;
      case SC_RSPR:
        perform_space_cadet(record, KC_RSFT, KC_RSFT, KC_0);
        return false;
      case SC_LSBR:
        perform_space_cadet(record, KC_LSFT, _______, KC_LBRC);
        return false;
      case SC_RSBR:
        perform_space_cadet(record, KC_RSFT, _______, KC_RBRC);
        return false;
      case SC_LSCB:
        perform_space_cadet(record, KC_LSFT, KC_LSFT, KC_LBRC);
        return false;
      case SC_RSCB:
        perform_space_cadet(record, KC_RSFT, KC_RSFT, KC_RBRC);
        return false;

      case TMUXCPY:
        // Enter copy mode in tmux.
        send_string(SS_LCTRL("x")"[");
        return false;

      case CMK_OFF:
        if (record->event.pressed) {
            layer_off(_COLEMAK);
        }
        return false;
      case CMK_ON:
        if (record->event.pressed) {
            layer_on(_COLEMAK);
        }
        return false;

      case PLOVER:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(plover_song);
#endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(_PLOVER);
            if (!eeconfig_is_enabled()) {
                eeconfig_init();
            }
            keymap_config.raw = eeconfig_read_keymap();
            keymap_config.nkro = 1;
            eeconfig_update_keymap(keymap_config.raw);
        }
        return false;
        break;
      case EXT_PLV:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(plover_gb_song);
#endif
            layer_off(_PLOVER);
        }
        return false;
        break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
