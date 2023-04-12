#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ALT,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  ADJUST
};

#define LOWER LT(_LOWER, KC_ENT)
#define RAISE LT(_RAISE, KC_BSPC)
#define ALT   LT(_ALT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A, KC_S, KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT ,
    CW_TOGG, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   ALT,     ALT,     RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    KC_BSPC,       KC_DEL,        SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), LCTL(KC_GRV),  KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,
    KC_LSFT,       KC_LCTL,       KC_LALT,       KC_LGUI,       KC_UP,         KC_PGUP,       OSM(MOD_HYPR), KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,
    LGUI(KC_LEFT), LGUI(KC_RGHT), KC_PGDN,       KC_LEFT,       KC_DOWN,       KC_RGHT,       _______,       KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,
    _______,       _______,       _______,       _______,       _______,       _______,       _______,       ADJUST,  KC_0,    KC_DOT,  _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______, SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), KC_DEL,  KC_BSPC,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______, KC_MS_BTN1,    KC_MS_U,       KC_LGUI,       KC_LALT,       KC_LCTL, KC_LSFT,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, KC_MS_L,       KC_MS_D,       KC_MS_R,       KC_MS_BTN2,    KC_WH_U, KC_WH_D,
    _______, _______, _______, KC_RPRN, ADJUST,  _______, _______,       _______,       KC_MNXT,       KC_VOLD,       KC_VOLU, KC_MPLY
),

[_ADJUST] = LAYOUT_planck_grid(
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI, _______, _______, _______, _______, _______, QK_BOOT,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ALT] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    _______, KC_MINS, KC_UNDS, KC_LPRN, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_RPRN, KC_EQL,  KC_PLUS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

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

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
