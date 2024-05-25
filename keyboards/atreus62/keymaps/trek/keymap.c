#include QMK_KEYBOARD_H

enum layers {
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
#define HOME_G ALL_T(KC_H)

// Right-hand home row mods
#define HOME_J SFT_T(KC_J)
#define HOME_K CMD_T(KC_K)
#define HOME_L OPT_T(KC_L)
#define HOME_SC CTL_T(KC_SCLN)
#define HOME_H ALL_T(KC_G)

// Raycast
#define RAYCAST LCMD(KC_SPC)

#define GUITAB GUI_T(KC_TAB)
#define SFTBPC SFT_T(KC_BSPC)
#define SFTDEL SFT_T(KC_DEL)
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

enum {
  TD_CUT,
  TD_COPY,
  TD_PSTE,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_CUT]  = ACTION_TAP_DANCE_DOUBLE(KC_X, LGUI(KC_X)),
  [TD_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, LGUI(KC_C)),
  [TD_PSTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, LGUI(KC_V)),
};

// Cut, Copy, Paste
#define CUT_X TD(TD_CUT)
#define COPY_C TD(TD_COPY)
#define PASTE_V TD(TD_PSTE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    ESC_CTL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_H,                      HOME_G,  HOME_J,  HOME_K,  HOME_L,  HOME_SC, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    COPY_C,  PASTE_V, KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
    KC_ESC,   KC_LOPT, KC_LCBR, KC_RCBR, LOWER,   GUITAB,   RAYCAST, THINGS,   SFTBPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
 // _______,  _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
  ),

  [_LOWER] = LAYOUT(
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    XXXXXXX,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS, XXXXXXX,
    _______,  KC_LCTL, KC_LOPT, KC_LGUI, KC_LSFT, KC_CIRC,                     KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, XXXXXXX,
    _______,  KC_LT,   KC_GT, KC_BSLS,   KC_PIPE, KC_AMPR,                     KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS, _______,
    _______,  _______, _______, _______, _______, _______,  _______, EMOJI,    _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, QK_BOOT,
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    _______,  OSM_CTL, OSM_ALT, OSM_GUI, OSM_SFT, KC_HYPR,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    _______,  XXXXXXX, BACK,    FORWARD, PRV_TAB, NXT_TAB,                     M_HOME,  KC_PGDN, KC_PGUP, M_END,   XXXXXXX, XXXXXXX,
    _______,  _______, _______, _______, _______, _______,  EMOJI,   _______,  _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _______,
    _______,  RGB_TOG, RGB_MOD, _______, KC_WH_U, _______,                     _______, _______, _______, _______, _______, _______,
    _______,  RGB_VAI, RGB_HUI, KC_BTN3, KC_BTN1, KC_BTN2,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, QK_BOOT,
    _______,  RGB_SAI, RGB_SPI, _______, KC_WH_D, _______,                     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
    _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
