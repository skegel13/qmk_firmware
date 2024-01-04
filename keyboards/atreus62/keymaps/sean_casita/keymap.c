#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER LT(_LOWER, KC_ENT)
#define RAISE LT(_RAISE, KC_SPC)
#define ADJUST MO(_ADJUST)

#define TAB ALL_T(KC_TAB)
#define ESC_CTL CTL_T(KC_ESC)

// Left-hand home row mods
#define HOME_A CTL_T(KC_A)
#define HOME_S OPT_T(KC_S)
#define HOME_D CMD_T(KC_D)
#define HOME_F SFT_T(KC_F)

// Right-hand home row mods
#define HOME_J SFT_T(KC_J)
#define HOME_K CMD_T(KC_K)
#define HOME_L OPT_T(KC_L)
#define HOME_SC CTL_T(KC_SCLN)

// Raycast
#define RAY LCMD(KC_SPC)

#define CTLTAB CTL_T(KC_TAB)
#define SFTBPC SFT_T(KC_BSPC)
#define EMOJI C(G(KC_SPC))
#define M_HOME G(KC_LEFT)
#define M_END G(KC_RGHT)
#define THINGS C(A(KC_SPC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    ESC_CTL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                        KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SC, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
    KC_ESC,   KC_LCTL, KC_LOPT, KC_LCMD, LOWER,   CTLTAB,   RAY,     THINGS,   SFTBPC,  RAISE,   KC_MINS, KC_PLUS, KC_UNDS, KC_EQL
 // _______,  _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
  ),

  [_LOWER] = LAYOUT(
    KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______,  KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_UNDS,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    _______,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PLUS,                     M_HOME,   KC_PGDN, KC_PGUP, M_END,  KC_RCBR, _______,
    _______,  _______, _______, _______, _______, _______,  _______, EMOJI,    _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______,  KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_PIPE,                     KC_MINS, KC_LSFT, KC_LCMD, KC_LOPT, KC_LCTL, KC_ESC,
    _______,  KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSLS,                     KC_EQL,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______,
    _______,  _______, _______, _______, _______, _______,  EMOJI,   _______,  _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    _______,  RGB_TOG, XXXXXXX, KC_BTN3, KC_BTN1, KC_BTN2,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, QK_BOOT,
    _______,  RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
    _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
