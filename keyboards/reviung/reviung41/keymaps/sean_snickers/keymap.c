#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,        KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                            KC_LGUI,   LOWER,    KC_SPC,   RAISE,    KC_RALT
  ),

  [_LOWER] = LAYOUT(
    KC_BSPC,       KC_DEL,        SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC),  LCTL(KC_GRV),  KC_LBRC, KC_7,  KC_8,  KC_9,  KC_RBRC,
    KC_LSFT,       KC_LCTL,       KC_LALT,       KC_LGUI,       KC_UP,         KC_PGUP,        OSM(MOD_HYPR), KC_EQL,  KC_4,  KC_5,  KC_6,  KC_SCLN,
    LGUI(KC_LEFT), LGUI(KC_RGHT), KC_LEFT,       KC_RIGHT,      KC_DOWN,       KC_PGDN,         _______,      KC_BSLS, KC_1,  KC_2,  KC_3,  KC_GRV,
                                            _______,   _______,  KC_ENT,   ADJUST,  KC_0
  ),

  [_RAISE] = LAYOUT(
    KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,  _______,           SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), KC_DEL,  KC_BSPC,
    KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,  _______,           KC_WH_U,       KC_MS_U,       KC_LGUI,       KC_LALT,       KC_LCTL, KC_LSFT,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,  _______,           KC_WH_D,       KC_MS_D,       KC_MS_L,       KC_MS_R,       KC_BTN1, KC_BTN2,
                                            KC_RPRN,  ADJUST,  KC_BSPC,  _______,  _______
  ),

  [_ADJUST] = LAYOUT(
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI,                  _______, _______, _______, _______, _______, QK_BOOT,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                    _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                   _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t my_hash_timer;

  switch (keycode) {
    case ADJUST:
      if (layer_state_is(_LOWER)) {
        if(record->event.pressed) {
          my_hash_timer = timer_read();
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);

          if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
            tap_code16(KC_MINS);
          }
        }
      } else if (layer_state_is(_RAISE)) {
        if(record->event.pressed) {
          my_hash_timer = timer_read();
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);

          if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
            tap_code16(KC_UNDS);
          }
        }
      } else {
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
      }

      return false;
      break;
  }
  return true;
}
