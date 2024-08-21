#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
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
#define HOME_G ALL_T(KC_G)
#define H_CIRC CTL_T(KC_CIRC)
#define H_AMPR OPT_T(KC_AMPR)
#define H_ASTR CMD_T(KC_ASTR)
#define H_LPRN SFT_T(KC_LPRN)

// Right-hand home row mods
#define HOME_H ALL_T(KC_H)
#define HOME_J SFT_T(KC_J)
#define HOME_K CMD_T(KC_K)
#define HOME_L OPT_T(KC_L)
#define HOME_SC CTL_T(KC_SCLN)
#define H_4 SFT_T(KC_4)
#define H_5 CMD_T(KC_5)
#define H_6 OPT_T(KC_6)
#define H_MINS CTL_T(KC_MINS)

#define GUITAB LGUI_T(KC_TAB)
#define CTLTAB LCTL_T(KC_TAB)
#define SFTBPC SFT_T(KC_BSPC)
#define SFTDEL SFT_T(KC_DEL)
#define SFTQUOT SFT_T(KC_QUOT)
#define EMOJI C(G(KC_SPC))
#define M_HOME G(KC_LEFT)
#define M_END G(KC_RGHT)
#define THINGS C(A(KC_SPC))

// Nav
#define BACK G(KC_LBRC)
#define FORWARD G(KC_RBRC)
#define PRV_TAB S(G(KC_LBRC))
#define NXT_TAB S(G(KC_RBRC))

// OSM
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
//XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  ESC_CTL, HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_G,  HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_SC, SFTQUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
  KC_LGUI, KC_LCTL, KC_LOPT, GUITAB,  LOWER,   CTLTAB,  SFTBPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
//XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSLS,
  _______, H_CIRC,  H_AMPR,  H_ASTR,  H_LPRN,  KC_RPRN, KC_ASTR, H_4,     H_5,     H_6,     H_MINS,  KC_PIPE,
  _______, KC_UNDS, KC_LCBR, KC_RBRC, KC_LCBR, KC_RCBR, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_planck_grid(
//XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  _______, OSM_CTL, OSM_ALT, OSM_GUI, OSM_SFT, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LCTL, KC_ESC,
  _______, PRV_TAB, NXT_TAB, BACK,    FORWARD, KC_BSLS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] = LAYOUT_planck_grid(
//XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  RGB_TOG, RGB_VAI, RGB_VAD, RGB_SPI, KC_WH_U, XXXXXXX, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, XXXXXXX, XXXXXXX,
  RGB_MOD, RGB_HUI, RGB_HUD, KC_BTN3, KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, QK_BOOT,
  _______, RGB_SAI, RGB_SAD, RGB_SPD, KC_WH_D, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
