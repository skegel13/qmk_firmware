#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};


/* Thumb Keys */
#define LOWER LT(_LOWER, KC_TAB)
#define RAISE LT(_RAISE, KC_BSPC)
#define GUI_ENT GUI_T(KC_ENT)
#define SFT_SPC SFT_T(KC_SPC)
#define RAISE_D LT(_RAISE, KC_DEL)
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
#define RAY LCMD(KC_SPC)
#define EMOJI C(G(KC_SPC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GRV,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    ESC_CTL,  HOME_A,   HOME_S,   HOME_D,   HOME_F,    HOME_G,             HOME_H,   HOME_J,   HOME_K,   HOME_L,   HOME_SC,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RCTL,
                                            GUI_ENT,   LOWER,    KC_SPC,   RAISE,    SFT_SPC
  ),

  [_LOWER] = LAYOUT(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE,
    _______,  H_MINS,   H_EQL,    H_BSLS,   H_LPRN,    KC_RPRN,            KC_LEFT,  H_DOWN,   H_UP,     H_RGHT,   H_MINS,   KC_BSLS,
    _______,  KC_UNDS,  KC_LBRC,  KC_RBRC,  KC_LCBR,   KC_RCBR,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_UNDS,  _______,
                                            _______,   _______,  KC_ENT,   RAISE_D,  _______
  ),

  [_RAISE] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
    _______,  OSM_CTL,  OSM_ALT,  OSM_GUI,  OSM_SFT,   OSM_HYP,            KC_PLUS,  KC_4,     KC_5,     KC_6,     KC_MNXT,  KC_MPLY,
    _______,  PRV_TAB,  NXT_TAB,  BACK,     FORWARD,   CW_TOGG,            KC_0,     KC_1,     KC_2,     KC_3,     KC_VOLD,  KC_VOLU,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),

  [_ADJUST] = LAYOUT(
    KC_F11,    KC_F1,   KC_F2,    KC_F3,    KC_F4,     KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
    RGB_TOG,   RGB_MOD, XXXXXXX,  KC_BTN3,  KC_BTN1,   KC_BTN2,            KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  QK_BOOT,
    RGB_VAI,   RGB_HUI, RGB_SAI,  RGB_SPI,  XXXXXXX,   XXXXXXX,            KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  XXXXXXX,  KC_RSFT,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

