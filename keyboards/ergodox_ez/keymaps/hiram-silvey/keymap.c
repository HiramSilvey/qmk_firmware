#include QMK_KEYBOARD_H
#include "version.h"

#define PREVENT_STUCK_MODIFIERS

#define BASE 0
#define NUM  1
#define FN   2
#define GAME 3

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
	EPRM = EZ_SAFE_RANGE,
#else
	EPRM = SAFE_RANGE,
#endif
	VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE layer # ^
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |  @   |  !   |  ?   |  (   |  *   |  #   |           |   ^  |   &  |   )  |   [  |   ]  |   =  |    Del |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Tab    |  '   |  ,   |  .   |  P   |  Y   |  /   |           |   \  |   F  |   G  |   C  |   R  |   L  |  Enter |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | MO(L1) |  A   |  O   |  E   |  U   |  I   |------|           |------|   D  |   H  |   T  |   N  |   S  |    -   |
 * |--------+------+------+------+------+------|  `   |           |   %  |------+------+------+------+------+--------|
 * | Lshift |  ;   |  Q   |  J   |  K   |  X   |      |           |      |   B  |   M  |   W  |   V  |   Z  | Rshift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |CpsLck| Home | PgUp | PgDn | End  |                                       | Left |  Up  | Down | Right| PrtSc|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |VolDn |VolUp |       |PTrack|NTrack|
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      | Mute |       | Play |      |      |
 *                                 |Space | Left |------|       |------|Right |Back- |
 *                                 |      | Alt  | Meta |       | Meta | Ctrl | space|
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
	// Left hand
  KC_ESC,   KC_AT,   KC_EXLM, KC_QUES, KC_LPRN, KC_ASTR, KC_HASH,
  KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_SLSH,
  MO(NUM),  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
  KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_GRV,
  KC_CAPS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,
	                                              KC_VOLD, KC_VOLU,
                                                         KC_MUTE,
                      	                KC_SPC, KC_LALT, KC_LGUI,
	// Right hand
	KC_CIRC, KC_AMPR, KC_RPRN, KC_LBRC, KC_RBRC, KC_EQL,  KC_DEL,
	KC_BSLS, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_ENT,
	         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
	KC_PERC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
	                  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_PSCR,
	KC_MPRV, KC_MNXT,
	KC_MPLY,
	KC_RGUI, KC_RCTL, KC_BSPC
),
/* NUM layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   *  |   7  |   8  |   9  |   /  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |TG(L3)|MO(L2)|      |------|           |------|   +  |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   $  |   1  |   2  |   3  |   .  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUM] = LAYOUT_ergodox(
	// Left hand
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME), MO(FN),  KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
	                                              KC_TRNS, KC_TRNS,
	                                                       KC_TRNS,
	                                     KC_TRNS, KC_TRNS, KC_TRNS,
	// Right hand
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_PAST, KC_7,    KC_8,    KC_9,    KC_PSLS, KC_TRNS,
	         KC_PPLS, KC_4,    KC_5,    KC_6,    KC_PMNS, KC_TRNS,
	KC_TRNS, KC_DLR,  KC_1,    KC_2,    KC_3,    KC_PDOT, KC_TRNS,
	                  KC_0,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS
),
/* FN layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  F10 |  F11 |  F12 |      |  EPRM  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   F7 |   F8 |   F9 |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   F4 |   F5 |   F6 |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   F1 |   F2 |   F3 |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FN] = LAYOUT_ergodox(
	// Left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
	// Right hand
	KC_TRNS, KC_TRNS, KC_F10,  KC_F11,  KC_F12,  KC_TRNS, EPRM,
	KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_TRNS, KC_TRNS,
	         KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_TRNS, KC_TRNS,
	                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS,
	KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS
),
/* GAME layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |  0   |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  Q   |  W   |  E   |  R   |  T   | Del  |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |  A   |  S   |  D   |  F   |  G   |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------| LAlt |           |      |------+------+------+------+------+--------|
 * |        |  Z   |  X   |  C   |  V   |  B   |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  6   |  7   |  8   |  9   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                    ,----------------.         ,-------------.
 *                                    |      |         |         |      |      |
 *                             ,------|------|---------|         |------+------+------.
 *                             |      |      |         |         |      |      |      |
 *                             |      | Left |---------|         |------|      |      |
 *                             |      | Ctrl | TG(GAME)|         |      |      |      |
 *                             `-----------------------'         `--------------------'
 */
[GAME] = LAYOUT_ergodox(
  // Left hand
  KC_TRNS, KC_1, KC_2, KC_3, KC_4,    KC_5,    KC_0,
  KC_TRNS, KC_Q, KC_W, KC_E, KC_R,    KC_T,    KC_DEL,
  KC_LCTL, KC_A, KC_S, KC_D, KC_F,    KC_G,
  KC_TRNS, KC_Z, KC_X, KC_C, KC_V,    KC_B,    KC_LALT,
  KC_TRNS, KC_6, KC_7, KC_8, KC_9,
                                      KC_TRNS, KC_TRNS,
                                               KC_TRNS,
                             KC_TRNS, KC_LCTL, TG(GAME),
  // Right hand
  KC_TRNS, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  KC_TRNS, KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
           KC_H, KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
  KC_TRNS, KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
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
