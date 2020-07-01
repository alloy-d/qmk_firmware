#include QMK_KEYBOARD_H

#define HOME 0
#define SHORTCUTS 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, MT(MOD_LSFT, KC_QUOTE),
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
		KC_Z, KC_X, KC_C, KC_V, LT(SHORTCUTS, KC_SPC), KC_B, KC_N, KC_M),

    // I get one commonly used shortcut per letter.  Probably either
    // ctrl or GUI (cmd).  It's extra complicated because I use software
    // Colemak, so these keys are not what they seem.
    //
    // These are mostly optimized for Apple-style shortcuts, since
    // I expect to mostly use this keyboard with an iPad.
    [SHORTCUTS] = LAYOUT(
        C(KC_Q), C(KC_W),       G(KC_E)/*F*/,   C(KC_R)/*P*/,   C(KC_T)/*G*/,   KC_NO/*J*/, C(KC_U)/*L*/,   KC_NO/*U*/,     KC_NO/*Y*/, S(KC_QUOTE)/*Enter*/,
        C(KC_A), RESET/*R*/,    G(KC_D)/*S*/,   KC_NO/*T*/,     KC_NO/*D*/,     KC_BSPC,    C(KC_J)/*N*/,   C(KC_K)/*E*/,   KC_NO/*I*/, KC_NO/*O*/,
        G(KC_Z), G(KC_X),       G(KC_C),        G(KC_V),        _______,        C(KC_B),    C(KC_N)/*K*/,   KC_ENTER/*M*/)
};

// All adjusted for software Colemak.
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM scl_combo[] = {KC_D, KC_C, KC_U, COMBO_END};
const uint16_t PROGMEM col_combo[] = {KC_C, KC_SCLN, KC_U, COMBO_END};
const uint16_t PROGMEM pd_combo[] = {KC_R, KC_G, COMBO_END};
const uint16_t PROGMEM qm_combo[] = {KC_Q, KC_M, COMBO_END};
const uint16_t PROGMEM exc_combo[] = {KC_K, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM und_combo[] = {KC_I, KC_J, KC_G, COMBO_END};
const uint16_t PROGMEM dsh_combo[] = {KC_G, KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM nds_combo[] = {KC_J, KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM mds_combo[] = {KC_M, KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM sq_combo[] = {KC_D, KC_Q, COMBO_END};
const uint16_t PROGMEM dq_combo[] = {KC_G, KC_Q, COMBO_END};

enum combos {
    CM_COMMA,
    SCL_SEMICOLON,
    COL_COLON,
    PD_PERIOD,
    QM_QUESTION,
    EXC_EXCLAMATION,
    UND_UNDERSCORE,
    DSH_DASH,
    NDS_ENDASH,
    MDS_EMDASH,
    SQ_SINGLEQUOTE,
    DQ_DOUBLEQUOTE
};


combo_t key_combos[COMBO_COUNT] = {
    [CM_COMMA]          = COMBO(cm_combo,   KC_COMMA),
    [SCL_SEMICOLON]     = COMBO(scl_combo,  KC_P),
    [COL_COLON]         = COMBO(col_combo,  S(KC_P)),
    [PD_PERIOD]         = COMBO(pd_combo,   KC_DOT),
    [QM_QUESTION]       = COMBO(qm_combo,   S(KC_SLASH)),
    [EXC_EXCLAMATION]   = COMBO(exc_combo,  S(KC_1)),
    [UND_UNDERSCORE]    = COMBO(und_combo,  S(KC_MINS)),
    [DSH_DASH]          = COMBO(dsh_combo,  KC_MINS),
    [NDS_ENDASH]        = COMBO(nds_combo,  A(KC_MINS)),
    [MDS_EMDASH]        = COMBO(mds_combo,  S(A(KC_MINS))),
    [SQ_SINGLEQUOTE]    = COMBO(sq_combo,   KC_QUOTE),
    [DQ_DOUBLEQUOTE]    = COMBO(dq_combo,   S(KC_QUOTE))
};
