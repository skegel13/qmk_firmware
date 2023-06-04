#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, */
  [_BASE] = LAYOUT(
    ALL_T(KC_TAB), KC_Q, KC_W,    KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC), KC_A, KC_S,   KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_SENT,
                                            KC_LGUI,   LOWER,    KC_SPC,   RAISE,    KC_RALT
  ),

  [_LOWER] = LAYOUT(
    _______,  KC_WH_D,  KC_MS_U,  KC_WH_U,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MINS,  KC_EQL,   KC_DEL,
    _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_UP,     XXXXXXX,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  _______,
    _______,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,   KC_RGHT,            KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   XXXXXXX,  _______,
                                            _______,   _______,  KC_ENT,   _______,  KC_BTN1
  ),

  [_RAISE] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,              KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_PIPE,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,             KC_F12,   KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  _______,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),

  [_ADJUST] = LAYOUT(
    KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BTN3,  KC_BTN1,   KC_BTN2,            KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_MNXT,  QK_BOOT,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,   RGB_SPI,            KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_MPLY,  _______,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

