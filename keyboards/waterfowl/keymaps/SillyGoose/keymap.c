#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
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

[_BASE] = LAYOUT(
 /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_G,                    HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_SC,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
             KC_1,    EMOJI,   LOWER,   CTL_TAB, RAYCAST, KC_MPLY, SFT_BPC, RAISE,   TERM,    KC_4
	      /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
),

[_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_7,    KC_8,    KC_9,    KC_MINS, KC_SLASH,
    L_A,     L_S,     L_D,     SC_LSPO, L_G,                       KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR,
    KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,                   KC_1,    KC_2,    KC_3,    KC_DOT,  KC_EQL,
	         _______, _______, _______, _______, _______, _______, ESC_HYP, ADJ_0,   KC_0,    _______
),

[_RAISE] = LAYOUT(
    CW_TOGG, PRV_TAB, NXT_TAB, BACK,    FORWARD,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,
    R_A,     R_S,     R_D,     R_F ,    R_G,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    XXXXXXX, KC_TILD, KC_PLUS, KC_UNDS, KC_PIPE,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQUO,
	         _______, _______, ADJUST,  ESC_HYP, THINGS, _______, _______, _______, _______, _______
),

[_ADJUST] =  LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  RGB_TOG, KC_BTN3, KC_BTN1, KC_BTN2,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_F12,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, QK_BOOT,
	         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};

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
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(KC_WH_R);
        } else {
            tap_code(KC_WH_L);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code16(S(KC_TAB));
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code16(S(KC_WH_D));
        } else {
            tap_code16(S(KC_WH_U));
        }
    } else if (index == 3) { // Right encoder
        if (layer_state_is(_LOWER)) {
            if (clockwise) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_MNXT);
            }
        } else {
            if (clockwise) {
                tap_code_delay(KC_VOLD, 5);
            } else {
                tap_code_delay(KC_VOLU, 5);
            }
        }
    }

    return false;
}
