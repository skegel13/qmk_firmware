#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NAV 4

#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_SPC)
#define ADJUST MO(_ADJUST)
#define NAVENT LT(_NAV, KC_ENT)
#define NAVSPC LT(_NAV, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwerty */
 // KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS ,
    ALL_T(KC_TAB), KC_Q, KC_W,  KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC), KC_A, KC_S,  KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
    KC_MINS,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   NAVSPC,  G(KC_SPC), KC_ENT,  NAVENT,  RAISE,   KC_RALT, KC_LBRC, KC_RBRC, KC_EQL
 // KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_LOWER] = LAYOUT(
    KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_PIPE,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TILD, KC_PIPE,
    _______,  KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_TILD,                     KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    KC_UNDS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, C(G(KC_SPC)), KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PLUS
  ),

  [_RAISE] = LAYOUT(
    KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______,  KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_BSLS,                     KC_LEFT, SFT_T(KC_DOWN), CTL_T(KC_UP), ALT_T(KC_RGHT), GUI_T(KC_GRV), KC_BSLS,
    _______,  KC_LCBR, KC_RCBR, KC_MINS, KC_EQL,  KC_GRV,                      KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    KC_UNDS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, C(G(KC_SPC)), KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PLUS
  ),

  [_ADJUST] = LAYOUT(
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    _______,  RGB_TOG, XXXXXXX, KC_BTN3, KC_BTN1, KC_BTN2,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, QK_BOOT,
    _______,  RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT(
    LSG(KC_LBRC), G(KC_LBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(KC_RBRC), LSG(KC_RBRC),
    LSG(KC_LBRC), G(KC_LBRC), KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(KC_RBRC), LSG(KC_RBRC),
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
