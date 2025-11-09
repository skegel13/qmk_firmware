#include QMK_KEYBOARD_H

enum layer_names {
  _MAIN,
  _NUMBERS,
  _SYMBOLS,
  _NAV,
  _MOUSE,
};

/* Thumb Keys */
#define NUMBER LT(_NUMBERS, KC_ENT)
#define SYMBOL LT(_SYMBOLS, KC_TAB)
#define NAV LT(_NAV, KC_SPC)
#define SFT_BSP SFT_T(KC_BSPC)
#define SFT_DEL SFT_T(KC_DEL)
#define MOUSE_L MO(_MOUSE)
#define MOUSE_R LT(_MOUSE, KC_0)

#define NUMQUOT LT(_NUMBERS, KC_QUOT)

/* Tab and Control Modifiers */
#define TAB ALL_T(KC_TAB)
#define ESC_CTL CTL_T(KC_ESC)

/* Home Row Modifiers */

// Left
#define HOME_A CTL_T(KC_A)
#define HOME_S OPT_T(KC_S)
#define HOME_D CMD_T(KC_D)
#define HOME_F SFT_T(KC_F)
#define HOME_G ALL_T(KC_G)

// Right
#define HOME_H ALL_T(KC_H)
#define HOME_J SFT_T(KC_J)
#define HOME_K CMD_T(KC_K)
#define HOME_L OPT_T(KC_L)
#define HOME_SC CTL_T(KC_SCLN)

/* Navigation Modifiers */
#define BACK G(KC_LBRC)
#define FORWARD G(KC_RBRC)
#define PRV_TAB S(G(KC_LBRC))
#define NXT_TAB S(G(KC_RBRC))

/* One-Shot Modifiers */
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_HYP OSM(MOD_HYPR)

/* Miscellaneous Modifiers */
#define RAYCAST LCMD(KC_SPC)
#define EMOJI C(G(KC_SPC))
#define EMOJI2 C(G(KC_E))
#define THINGS C(A(KC_SPC))
#define THINGSC C(KC_SPC)
#define TERM C(KC_GRV)
#define CLIP C(G(KC_V))
#define PRV_WS G(S(KC_TAB))
#define NXT_WS G(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
     /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_G,                    HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_SC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                 KC_1,    NUMBER,  SYMBOL,  KC_ESC,  RAYCAST,  CLIP,   KC_ESC,  SFT_BSP, NAV,     KC_4
              /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
    ),

    [_NUMBERS] = LAYOUT(
     /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, OS_HYPR,                   KC_UNDS, KC_4,    KC_5,    KC_6,    KC_QUOT,
        KC_F11,  KC_F12,  _______, _______, KC_ESC,                    KC_0,    KC_1,    KC_2,    KC_3,    KC_UNDS,
                 KC_1,    _______, _______, _______, _______, TERM,    SFT_DEL, SFT_DEL, MOUSE_R, KC_4
              /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
    ),

    [_SYMBOLS] = LAYOUT(
     /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL,
        OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, OS_HYPR,                   KC_MINS, KC_LPRN, KC_LCBR, KC_LBRC, KC_QUOT,
        KC_BSLS, KC_PIPE, KC_TILD, KC_GRV,  KC_ESC,                    KC_UNDS, KC_RPRN, KC_RCBR, KC_RBRC, KC_DQUO,
                 KC_1,    _______, _______, _______, _______, TERM,    SFT_DEL, SFT_DEL, KC_ESC,  KC_4
              /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
    ),

    [_NAV] = LAYOUT(
     /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
        KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______,                   PRV_TAB, BACK,    FORWARD, NXT_TAB, _______,
        OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, OS_HYPR,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
        _______, _______, _______, _______, KC_ESC,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQUO,
                 KC_1,    MOUSE_L, KC_ESC,  KC_ESC,  EMOJI2,  TERM,    _______, _______, _______, KC_4
              /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
    ),

    [_MOUSE] = LAYOUT(
     /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_F12,  MS_BTN3, MS_BTN1, MS_BTN2,                   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
        OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, OS_HYPR,                   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, QK_BOOT,
                 KC_1,    _______, _______, _______, _______, _______, _______, _______, _______, KC_4
              /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(MS_WHLR);
        } else {
            tap_code(MS_WHLL);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code16(S(KC_TAB));
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code16(S(MS_WHLD));
        } else {
            tap_code16(S(MS_WHLU));
        }
    } else if (index == 3) { // Right encoder
        if (layer_state_is(_NUMBERS)) {
            if (clockwise) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_MNXT);
            }
        } else {
            if (clockwise) {
                tap_code_delay(KC_VOLD, 5);
            } else {
                tap_code_delay(KC_VOLU, 5);
            }
        }
    }

    return false;
}
