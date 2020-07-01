#include QMK_KEYBOARD_H

#define HOME 0
#define SHORTCUTS 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_ENTER,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
		KC_Z, KC_X, KC_C, KC_V, LT(SHORTCUTS, KC_SPC), KC_B, KC_N, KC_M),

    // I get one commonly used shortcut per letter.  Probably either
    // ctrl or GUI (cmd).  It's extra complicated because I use software
    // Colemak, so these keys are not what they seem.
    //
    // These are mostly optimized for Apple-style shortcuts, since
    // I expect to mostly use this keyboard with an iPad.
    [SHORTCUTS] = LAYOUT(
        C(KC_Q), C(KC_W),       G(KC_E)/*F*/,   KC_NO/*P*/, C(KC_T)/*G*/,   KC_NO/*J*/, C(KC_U)/*L*/,   KC_NO/*U*/,     KC_NO/*Y*/, KC_BSPC/*Enter*/,
        C(KC_A), RESET/*R*/,    G(KC_D)/*S*/,   KC_NO/*T*/, KC_NO/*D*/,     C(KC_H),    C(KC_J)/*N*/,   C(KC_K)/*E*/,   KC_NO/*I*/, KC_NO/*O*/,
        G(KC_Z), G(KC_X),       G(KC_C),        G(KC_V),    _______,        C(KC_B),    C(KC_N)/*K*/,   C(KC_M))
};

enum combos {
    CM_COMMA,
    SCL_SEMICOLON,
    COL_COLON,
    PD_PERIOD
};

// All adjusted for software Colemak.
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM scl_combo[] = {KC_D, KC_C, KC_U, COMBO_END};
const uint16_t PROGMEM col_combo[] = {KC_C, KC_SCLN, KC_U, COMBO_END};
const uint16_t PROGMEM pd_combo[] = {KC_R, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CM_COMMA] = COMBO(cm_combo, KC_COMMA),
    [SCL_SEMICOLON] = COMBO(scl_combo, KC_P),
    [COL_COLON] = COMBO(col_combo, S(KC_P)),
    [PD_PERIOD] = COMBO(pd_combo, KC_DOT)
};
