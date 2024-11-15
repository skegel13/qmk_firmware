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

#define L_A LCTL_T(KC_F1)
#define L_S LALT_T(KC_F1)
#define L_D LGUI_T(KC_F1)
#define L_G ALL_T(KC_F1)

/* Thumb Keys */
#define LOWER LT(_LOWER, KC_ENT)
#define RAISE LT(_RAISE, KC_SPC)
#define GUI_TAB GUI_T(KC_TAB)
#define CTL_TAB GUI_T(KC_TAB)
#define SFT_BPC SFT_T(KC_BSPC)
#define SFT_DEL SFT_T(KC_DEL)
#define ADJUST MO(_ADJUST)
#define ESC_HYP ALL_T(KC_ESC)
#define ADJ_0 LT(_ADJUST, KC_0)
#define ADJUST MO(_ADJUST)

/* Tab and Control Modifiers */
#define TAB_ALL ALL_T(KC_TAB)
#define ESC_CTL CTL_T(KC_ESC)

/* Home Row Modifiers */

// Left
#define HOME_A CTL_T(KC_A)
#define HOME_S OPT_T(KC_S)
#define HOME_D CMD_T(KC_D)
#define HOME_F SFT_T(KC_F)
#define HOME_G ALL_T(KC_G)
#define H_MINS CTL_T(KC_MINS)
#define H_EQL OPT_T(KC_EQL)
#define H_BSLS CMD_T(KC_BSLS)
#define H_LPRN SC_LSPO
#define R_A CTL_T(KC_ESC)
#define R_S OPT_T(KC_GRV)
#define R_D CMD_T(KC_EQL)
#define R_F SFT_T(KC_MINS)
#define R_G ALL_T(KC_BSLS)

// Right
#define HOME_H ALL_T(KC_H)
#define HOME_J SFT_T(KC_J)
#define HOME_K CMD_T(KC_K)
#define HOME_L OPT_T(KC_L)
#define HOME_SC CTL_T(KC_SCLN)
#define H_DOWN SFT_T(KC_DOWN)
#define H_UP CMD_T(KC_UP)
#define H_RGHT OPT_T(KC_RGHT)

/* Navigation Modifiers */
#define BACK G(KC_LBRC)
#define FORWARD G(KC_RBRC)
#define PRV_TAB S(G(KC_LBRC))
#define NXT_TAB S(G(KC_RBRC))

/* One-Shot Modifiers */
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_HYP OSM(MOD_HYPR)

/* Miscellaneous Modifiers */
#define RAYCAST LCMD(KC_SPC)
#define EMOJI C(G(KC_SPC))
#define THINGS C(A(KC_SPC))
#define THINGSC C(KC_SPC)
#define TERM C(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_G,  TERM,    EMOJI,   HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_SC,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RAYCAST, THINGS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC,  KC_UNDS, KC_MINS, LOWER,   CTL_TAB, KC_SPC,  KC_SPC,  SFT_BPC, RAISE,   KC_GRV,  KC_TILD, KC_ENT
),


[_LOWER] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_MINS, KC_SLASH,
    L_A,     L_S,     L_D,     SC_LSPO, L_G,     XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR,
    KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_EQL,
    _______, _______, _______, _______, _______, _______, _______, ESC_HYP, ADJ_0,   _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    CW_TOGG, PRV_TAB, NXT_TAB, BACK,    FORWARD, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,
    R_A,     R_S,     R_D,     R_F ,    R_G,     XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    XXXXXXX, KC_TILD, KC_PLUS, KC_UNDS, KC_PIPE, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQUO,
    _______, _______, _______, ADJUST,  ESC_HYP, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RGB_TOG, RGB_MOD, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  RGB_TOG, KC_BTN3, KC_BTN1, KC_BTN2, RGB_HUI, RGB_VAI, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_F12,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAI, RGB_SPI, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, QK_BOOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, AU_ON,   MU_ON,   _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case L_A:  // Ctrl on hold, toggle NAV layer on tap.
      if (record->tap.count > 0) {  // On tap.
        if (record->event.pressed) {  // On press.
            register_code16(KC_CIRC);
        }
        unregister_code16(KC_CIRC);
        return false;  // Skip default handling on tap.
      }
      return true;  // Continue default handling on hold.
    case L_S:  // Ctrl on hold, toggle NAV layer on tap.
      if (record->tap.count > 0) {  // On tap.
        if (record->event.pressed) {  // On press.
            register_code16(KC_AMPR);
        }
        unregister_code16(KC_AMPR);
        return false;  // Skip default handling on tap.
      }
      return true;  // Continue default handling on hold.
    case L_D:  // Ctrl on hold, toggle NAV layer on tap.
      if (record->tap.count > 0) {  // On tap.
        if (record->event.pressed) {  // On press.
            register_code16(KC_ASTR);
        }
        unregister_code16(KC_ASTR);
        return false;  // Skip default handling on tap.
      }
      return true;  // Continue default handling on hold.
    case L_G:  // Ctrl on hold, toggle NAV layer on tap.
      if (record->tap.count > 0) {  // On tap.
        if (record->event.pressed) {  // On press.
            register_code16(KC_RPRN);
        }
        unregister_code16(KC_RPRN);
        return false;  // Skip default handling on tap.
      }
      return true;  // Continue default handling on hold.
  }

  return true;  // Continue default handling.
}

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
