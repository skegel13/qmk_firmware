/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _BASE,
  _NAV,
  _MOUSE,
  _MEDIA,
  _NUMBER,
  _SYMBOL,
  _FUNCTION,
  _MISC
};

#define NAV LT(_NAV, KC_SPC)
#define MOUSE LT(_MOUSE, KC_TAB)
#define MEDIA LT(_MEDIA, KC_ESC)
#define NUMBER LT(_NUMBER, KC_BSPC)
#define SYMBOL LT(_SYMBOL, KC_ENT)
#define FUNCTION LT(_FUNCTION, KC_DEL)
#define MISC LT(_MISC, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,  _______, _______, KC_Y,   KC_U,         KC_I,         KC_O,           KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,  _______, _______, KC_H,   LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L),   LGUI_T(KC_QUOT),
    KC_Z,         RALT_T(KC_X), KC_C,         KC_V,         KC_B,  _______, _______, KC_N,   KC_M,         KC_COMM,      RALT_T(KC_DOT), KC_SLSH,
    KC_ESC,       _______,      MEDIA,        NAV,          MOUSE, MISC,    MISC,    SYMBOL, NUMBER,       FUNCTION,     _______,        _______
),

[_MEDIA] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    _______, KC_RALT, _______, _______, _______, _______, _______, KC_HOME, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,
    _______, _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______
),

[_NAV] = LAYOUT_planck_grid(
    KC_ESC,  _______, _______, _______, _______, _______, _______, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_BSPC,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, KC_RALT, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_ENT,
    _______, _______, _______, _______, _______, _______, _______, KC_ENT, KC_BSPC,  KC_DEL,  _______, _______
),

[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, SGUI(KC_Z), LGUI(KC_V), LGUI(KC_C), LGUI(KC_X), LGUI(KC_Z),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______, KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    _______,
    KC_ACL0, KC_RALT, KC_ACL1, KC_ACL2, _______, _______, _______, KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    _______,
    _______, _______, _______, _______, _______, _______, _______, KC_BTN2,    KC_BTN1,    KC_BTN3,    _______,    _______
),

[_SYMBOL] = LAYOUT_planck_grid(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______, _______, _______, _______, _______, _______, _______,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______, _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, KC_RALT, _______,
    _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______, _______, _______
),

[_NUMBER] = LAYOUT_planck_grid(
    KC_LBRC, KC_7,    KC_8,   KC_9, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,
    KC_SCLN, KC_4,    KC_5,   KC_6, KC_EQL,  _______, _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS, _______, _______, _______, _______, _______, KC_RALT, _______,
    _______, _______, KC_DOT, KC_0, KC_MINS, _______, _______, _______, _______, _______, _______, _______
),

[_FUNCTION] = LAYOUT_planck_grid(
    KC_F12, KC_F7,    KC_F8,   KC_F9,  _______, _______, _______, _______, _______, _______, _______, _______,
    KC_F11, KC_F4,    KC_F5,   KC_F6,  _______, _______, _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10, KC_F1,    KC_F2,   KC_F3,  _______, _______, _______, _______, _______, _______, KC_RALT, _______,
    _______, _______, KC_MENU, KC_SPC, KC_TAB,  _______, _______, _______, _______, _______, _______, _______
),

[_MISC] = LAYOUT_planck_grid(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}
