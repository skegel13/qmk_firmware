/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMMOUSE
};

#define LOWER    LT(_LOWER, KC_ENT)
#define RAISE    LT(_RAISE, KC_BSPC)
#define NUMMOUSE LT(_NUMMOUSE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,        KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                            KC_LGUI,   LOWER,    NUMMOUSE, RAISE,    KC_RALT
  ),
  
  [_LOWER] = LAYOUT(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), XXXXXXX, KC_DEL,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,     XXXXXXX,            KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       XXXXXXX, XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,   KC_RGHT,            LGUI(KC_LEFT), KC_PGDN,       KC_PGUP,       LGUI(KC_RGHT), XXXXXXX, _______,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),
  
  [_RAISE] = LAYOUT(
    KC_TILD,  KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,            KC_PERC,            KC_CIRC,  KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,      KC_PIPE,
    KC_GRV,   LSFT_T(KC_1), LCTL_T(KC_2), LALT_T(KC_3), LGUI_T(KC_4),      KC_5,               KC_6,     LSFT_T(KC_7), LCTL_T(KC_8), LALT_T(KC_9), LGUI_T(KC_0), KC_BSLS,
    _______,  KC_MINS,      KC_UNDS,      KC_LPRN,      KC_LBRC,           KC_LCBR,            KC_RCBR,  KC_RBRC,      KC_RPRN,      KC_EQL,       KC_PLUS,      _______,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT(
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,              XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             XXXXXXX,  KC_MPRV,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),

  [_NUMMOUSE] = LAYOUT(
    _______,  KC_WH_D,  KC_MS_U,  KC_WH_U,  XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_SLSH,  KC_7,  KC_8,  KC_9,  KC_MINS,
    _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,   XXXXXXX,            KC_BTN1,  KC_ASTR,  KC_4,  KC_5,  KC_6,  KC_PLUS,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_BTN2,  KC_DOT,   KC_1,  KC_2,  KC_3,  _______,
                                            KC_BTN2,   KC_BTN1,  _______,  XXXXXXX,  KC_0
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

