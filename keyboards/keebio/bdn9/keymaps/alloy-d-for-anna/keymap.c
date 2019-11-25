/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum custom_keycodes {
    SHIFT_ESC = SAFE_RANGE,
    SIG
};

enum layers {
    BASE = 0,
};

#define COPY    C(KC_C)
#define REOPTAB C(S(KC_T))
#define PSTWOFM C(S(KC_V))
#define LSTCELL C(KC_END)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC__MUTE,XXXXXXX, XXXXXXX,
        COPY,    SIG,     XXXXXXX,
        PSTWOFM, REOPTAB, LSTCELL
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
    } else {
        if (clockwise) {
            tap_code(KC_WH_L);
        } else {
            tap_code(KC_WH_R);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // We'll only operate on the press event below, so let's save
    // ourselves a bunch of repeated if statements.
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case SIG:
            SEND_STRING("Anna Olechowska\nEditorial Assistant");
            return false;

        default:
            return true;
    }
}
