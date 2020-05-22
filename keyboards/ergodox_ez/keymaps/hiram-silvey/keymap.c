#include QMK_KEYBOARD_H
#include "version.h"

#define PERMISSIVE_HOLD

#define BASE     0 // default layer
#define NUM      1 // numpad
#define NAV      2 // navigation
#define FN       3 // function key numpad
#define MDIA     4 // media
#define GAME     5 // gaminzg

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
	EPRM = EZ_SAFE_RANGE,
#else
	EPRM = SAFE_RANGE,
#endif
	VRSN,
  LCLR,
	E_VSLZ,
	E_UNDO,
	E_REDO,
	T_PREV,
	T_NEXT,
	T_PRFX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
	// left hand
	KC_ESC, KC_AT, KC_EXLM, KC_EQL, KC_LPRN, KC_AMPR, KC_GRV,
	KC_LALT, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_PERC,
  KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I,
	KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_CAPS,
	E_VSLZ, MO(NUM), MO(NAV), MO(FN), MO(MDIA),
	LCTL(KC_LALT), KC_MEH,
  TG(GAME),
	KC_SPC, KC_TAB, KC_LGUI,
	// right hand
	KC_CIRC, KC_ASTR, KC_RPRN, KC_LBRC, KC_RBRC, KC_HASH, KC_BSLS,
	KC_DLR, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
	KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
	KC_DEL, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT,
	T_PREV, T_NEXT, E_UNDO, E_REDO, T_PRFX,
	KC_HYPR, RGUI(KC_RSFT),
	LCLR,
	KC_RGUI, KC_ENT, KC_BSPC
),
[NUM] = LAYOUT_ergodox(
	// left hand
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS,
	// right hand
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS,
	KC_DLR,  KC_4,    KC_5,    KC_6,    KC_PAST, KC_TRNS,
	KC_TRNS, KC_PERC, KC_1,    KC_2,    KC_3,    KC_PSLS, KC_TRNS,
	KC_0,    KC_PMNS, KC_PPLS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS
),
[NAV] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_PGUP, KC_UP,   KC_HOME, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_END, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
[FN] = LAYOUT_ergodox(
	// left hand
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,
	// right hand
	KC_TRNS, KC_TRNS, KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_TRNS, KC_TRNS,
	KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS
),
[MDIA] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_SLEP, KC_WAKE, KC_PWR,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
[GAME] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS,
  KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G,
  KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,
  KC_6, KC_7, KC_8, KC_9, KC_0,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
  KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,
  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_TRNS,
  KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			case EPRM:
				eeconfig_init();
				return false;
			case VRSN:
				SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
				return false;
      case LCLR:
        layer_clear();
        return false;
			case E_UNDO:
				SEND_STRING(SS_LCTL("/"));
				break;
			case E_REDO:
				SEND_STRING(SS_LALT(SS_LSFT("-")));
				break;
			case E_VSLZ:
				SEND_STRING(SS_LCTL("u")"u");
				break;
			case T_PREV:
				SEND_STRING(SS_TAP(X_F9)"p");
				break;
			case T_NEXT:
				SEND_STRING(SS_TAP(X_F9)"n");
				break;
			case T_PRFX:
				SEND_STRING(SS_TAP(X_F9));
				break;
		}
	}
	return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
	rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();

	uint8_t layer = get_highest_layer(state);
	switch (layer) {
			case 0:
				#ifdef RGBLIGHT_COLOR_LAYER_0
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
				#else
				#ifdef RGBLIGHT_ENABLE
					rgblight_init();
				#endif
				#endif
				break;
			case 1:
				ergodox_right_led_1_on();
				#ifdef RGBLIGHT_COLOR_LAYER_1
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
				#endif
				break;
			case 2:
				ergodox_right_led_2_on();
				#ifdef RGBLIGHT_COLOR_LAYER_2
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
				#endif
				break;
			case 3:
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_3
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
				#endif
				break;
			case 4:
				ergodox_right_led_1_on();
				ergodox_right_led_2_on();
				#ifdef RGBLIGHT_COLOR_LAYER_4
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
				#endif
				break;
			case 5:
				ergodox_right_led_1_on();
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_5
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
				#endif
				break;
			case 6:
				ergodox_right_led_2_on();
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_6
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
				#endif
				break;
			case 7:
				ergodox_right_led_1_on();
				ergodox_right_led_2_on();
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_7
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
				#endif
				break;
			default:
				break;
		}

	return state;
};
