#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMMOUSE,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
};

#define LOWER    LT(_LOWER, KC_ENT)
#define RAISE    LT(_RAISE, KC_BSPC)
#define NUMMOUSE LT(_NUMMOUSE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,     KC_Y,     KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
    LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,     KC_H,     LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
    KC_LSFT,        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,     KC_N,     KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         RSFT_T(KC_ENT),
    BACKLIT,        KC_LCTL,      KC_LALT,      KC_LGUI,      LOWER,        NUMMOUSE, NUMMOUSE, RAISE,        KC_LEFT,      KC_DOWN,      KC_UP,           KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SGUI(KC_LBRC), SGUI(KC_RBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), XXXXXXX, KC_DEL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, LGUI(KC_LEFT), KC_PGDN,       KC_PGUP,       LGUI(KC_RGHT), XXXXXXX, _______,
    _______, _______, _______, _______, _______, KC_ENT,  KC_ENT,         _______,      KC_MNXT,       KC_VOLD,       KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,      KC_PIPE,
    KC_GRV,  LGUI_T(KC_1), LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4), KC_5,    KC_6,    LSFT_T(KC_7), LCTL_T(KC_8), LALT_T(KC_9), LGUI_T(KC_0), KC_BSLS,
    _______, KC_MINS,      KC_UNDS,      KC_LPRN,      KC_LBRC,      KC_LCBR, KC_RCBR, KC_RBRC,      KC_RPRN,      KC_EQL,       KC_PLUS,      _______,
    _______, _______,      _______,      _______,      _______,      KC_BSPC, KC_BSPC, _______,      KC_MNXT,      KC_VOLD,      KC_VOLU,      KC_MPLY
),

[_ADJUST] = LAYOUT_planck_grid(
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUMMOUSE] = LAYOUT_planck_grid(
    _______, KC_WH_D, KC_MS_U, KC_WH_U, RGB_HUI, RGB_SPI, XXXXXXX, KC_SLSH, KC_7,   KC_8,     KC_9,    KC_MINS,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_ASTR, KC_4,   KC_5,     KC_6,    KC_PLUS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2, KC_DOT,  KC_1,   KC_2,     KC_3,    _______,
    KC_ESC,  _______, _______, KC_BTN2, KC_BTN1, _______, _______, _______, KC_0,   KC_0,     KC_DOT,  KC_ESC
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
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

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

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
