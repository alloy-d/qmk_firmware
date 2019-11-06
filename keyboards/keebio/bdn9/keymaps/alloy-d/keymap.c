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
#include <sendstring_colemak.h>

#undef TEMPO_DEFAULT
#define TEMPO_DEFAULT 10

#define BALL_GAME       \
    H__NOTE(_D5),       \
    Q__NOTE(_D6),       \
    Q__NOTE(_B6),       \
    Q__NOTE(_A6),       \
    Q__NOTE(_FS5),      \
    HD_NOTE(_A6),       \
    HD_NOTE(_E5),       \
    H__NOTE(_D5),       \
    Q__NOTE(_D6),       \
    Q__NOTE(_B6),       \
    Q__NOTE(_A6),       \
    Q__NOTE(_FS5),      \
    HD_NOTE(_A6),       \
    H__NOTE(_A6),


float song1[][2] = SONG(MUSIC_SCALE_SOUND);
float song4[][2] = SONG(BALL_GAME);

#define SEND_SLACK_REACTION(emoji) SEND_STRING("+" emoji SS_TAP(X_ENTER))

#define TMUX_PREFIX SS_LCTRL("x")
#define SEND_TMUX_PREFIX SEND_STRING(TMUX_PREFIX)
#define SEND_TMUX_COMMAND(cmd) SEND_STRING(TMUX_PREFIX cmd)

#define EMOJI1 ":ok_fidget_1080p:"
#define EMOJI2 ":nuggets:"
#define EMOJI3 ":no_horse_talk:"
#define EMOJI4 ":complex_smile:"
#define EMOJI5 ":peek:"
#define EMOJI6 ":drumroll:"
#define EMOJI7 ":pahoinvointi:"

enum custom_keycodes {
    SHIFT_ESC = SAFE_RANGE,
    LOCK,

    SEMOJI1,
    SEMOJI2,
    SEMOJI3,
    SEMOJI4,
    SEMOJI5,
    SEMOJI6,
    SEMOJI7,

    TMUX_ENTER_COPY_MODE,
    TMUX_UP,
    TMUX_DOWN,
    TMUX_LEFT,
    TMUX_RIGHT,
    TMUX_NEXT_PANE,
    TMUX_PREV_PANE
};

enum layers {
    BASE = 0,
    TMUX,
    SLACK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [BASE] = LAYOUT(
        KC__MUTE,       KC_PGUP,        TMUX_ENTER_COPY_MODE,
        SHIFT_ESC,      KC_PGDN,        KC_ESC,
        MO(TMUX),       MO(SLACK),      LOCK
    ),

    [TMUX] = LAYOUT(
        _______,        TMUX_UP,        _______,
        TMUX_LEFT,      TMUX_DOWN,      TMUX_RIGHT,
        _______,        TMUX_PREV_PANE, TMUX_NEXT_PANE
    ),

    [SLACK] = LAYOUT(
        _______,        SEMOJI1,        SEMOJI2,
        SEMOJI3,        SEMOJI4,        SEMOJI5,
        SEMOJI6,        _______,        SEMOJI7
    ),

    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    /*[1] = LAYOUT(*/
        /*RESET  , BL_STEP, KC_STOP,*/
        /*_______, KC_HOME, RGB_MOD,*/
        /*KC_MPRV, KC_END , KC_MNXT*/
    /*),*/
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC__VOLDOWN);
        } else {
            tap_code(KC__VOLUP);
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
        case LOCK:
            SEND_STRING(SS_LGUI(SS_LCTRL("q")));
            return false;
        case SHIFT_ESC:
            register_code(KC_LSHIFT);
            tap_code(KC_ESCAPE);
            unregister_code(KC_LSHIFT);
            return false;

        case TMUX_ENTER_COPY_MODE:
            SEND_TMUX_COMMAND("[");
            return false;

        case TMUX_UP:
            SEND_TMUX_PREFIX;
            tap_code(KC_UP);
            return false;
        case TMUX_DOWN:
            SEND_TMUX_PREFIX;
            tap_code(KC_DOWN);
            return false;
        case TMUX_LEFT:
            SEND_TMUX_PREFIX;
            tap_code(KC_LEFT);
            return false;
        case TMUX_RIGHT:
            SEND_TMUX_PREFIX;
            tap_code(KC_RIGHT);
            return false;

        case TMUX_NEXT_PANE:
            SEND_TMUX_PREFIX;
            tap_code(KC_SPACE);
            return false;
        case TMUX_PREV_PANE:
            SEND_TMUX_PREFIX;
            tap_code(KC_BSPACE);
            return false;

        case SEMOJI1:
            SEND_SLACK_REACTION(EMOJI1);
            return false;
        case SEMOJI2:
            SEND_SLACK_REACTION(EMOJI2);
            return false;
        case SEMOJI3:
            SEND_SLACK_REACTION(EMOJI3);
            return false;
        case SEMOJI4:
            SEND_SLACK_REACTION(EMOJI4);
            return false;
        case SEMOJI5:
            SEND_SLACK_REACTION(EMOJI5);
            return false;
        case SEMOJI6:
            SEND_SLACK_REACTION(EMOJI6);
            return false;
        case SEMOJI7:
            SEND_SLACK_REACTION(EMOJI7);
            return false;

        default:
            return true;
    }
}
