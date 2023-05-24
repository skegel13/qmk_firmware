#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMMOUSE,
};

#define LOWER   LT(_LOWER, KC_ENT)
#define RAISE   LT(_RAISE, KC_BSPC)
#define NUM_ENT LT(_NUMMOUSE, KC_ENT)
#define NUM_SPC LT(_NUMMOUSE, KC_SPC)

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
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H,    LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LGUI(KC_LEFT),    LGUI(KC_RGHT), KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   NUM_ENT,                   NUM_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), XXXXXXX, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,          KC_RPRN, LGUI(KC_LEFT), KC_PGDN, KC_PGUP, LGUI(KC_RGHT), XXXXXXX, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  LGUI_T(KC_1), LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4), KC_5,           KC_6,    LSFT_T(KC_7), LCTL_T(KC_8), LALT_T(KC_9), LGUI_T(KC_0), KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MINS, KC_UNDS, KC_LPRN, KC_LBRC, KC_LCBR, KC_DEL,          _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_EQL,  KC_PLUS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_BSPC,                   KC_BSPC, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, XXXXXXX, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMMOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                            KC_BTN1, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN,          KC_RPRN, KC_BTN2, KC_DOT,  KC_1,    KC_2,    KC_3,    _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_BTN2, KC_BTN1, _______,                   _______, _______, KC_0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
