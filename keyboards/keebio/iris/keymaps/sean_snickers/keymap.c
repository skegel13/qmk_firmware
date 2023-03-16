#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

bool is_mod_tab_active = false;
uint16_t mod_tab_timer = 0;

void matrix_scan_user(void) {
  if (is_mod_tab_active) {
    if (timer_elapsed(mod_tab_timer) > 750) {
      unregister_code(KC_LGUI);
      unregister_code(KC_LCTL);
      is_mod_tab_active = false;
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL_T(KC_ESC), KC_A, KC_S, KC_D,   KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LGUI(KC_LEFT),    LGUI(KC_RGHT), KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, MO(1),   KC_ENT,                    KC_SPC,  MO(2),   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_DEL,  SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC),    LCTL(KC_GRV), KC_LBRC, KC_7, KC_8,  KC_9,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_UP,   KC_PGUP,                            OSM(MOD_HYPR), KC_EQL, KC_4, KC_5,  KC_6,    KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LGUI(KC_LEFT), LGUI(KC_RGHT), KC_LEFT, KC_RIGHT, KC_DOWN, KC_PGDN, KC_LPRN, KC_RPRN, _______, KC_BSLS, KC_1, KC_2,   KC_3,    KC_GRV,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  ADJUST,  KC_0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,                            SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), KC_DEL, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,                            KC_WH_U, KC_MS_U, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, KC_LPRN,          KC_RPRN, KC_WH_D, KC_MS_D, KC_MS_L, KC_MS_R, KC_BTN1, KC_BTN2,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RPRN, ADJUST,  _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI,                            _______, _______, _______, _______, _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
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

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(_QWERTY)) {
        if (clockwise) {
            if (!is_mod_tab_active) {
                is_mod_tab_active = true;
                register_code(KC_LGUI);
            }
            mod_tab_timer = timer_read();
            tap_code16(KC_TAB);
        } else {
            if (!is_mod_tab_active) {
                is_mod_tab_active = true;
                register_code(KC_LGUI);
            }
            mod_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
        }
    } else if (layer_state_is(_ADJUST)) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (layer_state_is(_LOWER)) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (layer_state_is(_RAISE)) {
        if (clockwise) {
            if (!is_mod_tab_active) {
                is_mod_tab_active = true;
                register_code(KC_LCTL);
            }
            mod_tab_timer = timer_read();
            tap_code16(KC_TAB);
        } else {
            if (!is_mod_tab_active) {
                is_mod_tab_active = true;
                register_code(KC_LCTL);
            }
            mod_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
        }
    }

    return false;
}
