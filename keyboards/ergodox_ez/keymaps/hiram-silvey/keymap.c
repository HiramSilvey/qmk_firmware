#include QMK_KEYBOARD_H
#include "version.h"

#define PERMISSIVE_HOLD

#define BASE     0 // default layer
#define NAV_NUM  1 // navigation & numpad
#define FN_MDIA  2 // Function numpad & media

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
	EPRM = EZ_SAFE_RANGE,
#else
	EPRM = SAFE_RANGE,
#endif
	VRSN,
	LCLR,
	E_VSLZ,
	E_HOME,
	E_END,
	E_UNDO,
	E_REDO,
	T_PREV,
	T_NEXT,
	T_PRFX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
	// left hand
	KC_ESC, KC_AT, KC_EXLM, KC_EQL, KC_LPRN, KC_ASTR, KC_PERC,
	OSL(FN_MDIA), KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, DM_RSTP,
	OSL(NAV_NUM), KC_A, KC_O, KC_E, KC_U, KC_I,
	OSM(MOD_LSFT), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, MT(MOD_LCTL | MOD_LALT, KC_CAPS),
	E_VSLZ, E_HOME, E_END, E_UNDO, E_REDO,
	DM_PLY1, DM_REC1,
	KC_LGUI,
	KC_SPC, MT(MOD_LCTL, KC_TAB), KC_LALT,
	// right hand
	KC_DLR, KC_AMPR, KC_RPRN, KC_LBRC, KC_RBRC, KC_HASH, KC_BSLS,
	TG(NAV_NUM), KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
	KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
	KC_DEL, KC_B, KC_M, KC_W, KC_V, KC_Z, OSM(MOD_RSFT),
	T_PREV, T_NEXT, T_PRFX, KC_GRV, KC_CIRC,
	DM_REC2, DM_PLY2,
	KC_RGUI,
	KC_RALT, MT(MOD_RCTL, KC_ENT), KC_BSPC
),
[NAV_NUM] = LAYOUT_ergodox(
	// left hand
	EPRM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_PGUP, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_PGDN, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS,
	// right hand
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_PAST, KC_7,    KC_8,    KC_9,    KC_DLR, KC_TRNS,
	KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PERC, KC_TRNS,
	KC_TRNS, KC_PMNS, KC_1,    KC_2,    KC_3,    KC_PPLS, KC_TRNS,
	KC_0,    KC_TRNS, KC_TRNS, KC_TRNS, LCLR,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS
),
[FN_MDIA] = LAYOUT_ergodox(
	// left hand
	VRSN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS,
	// right hand
	KC_TRNS, KC_TRNS, KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_TRNS, KC_TRNS,
	KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_PPLS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCLR,
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
			case E_HOME:
				SEND_STRING(SS_LALT(SS_LSFT(",")));
				break;
			case E_END:
				SEND_STRING(SS_LALT(SS_LSFT(".")));
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
