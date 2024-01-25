#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(KC_ESC, KC_GRV, KC_EXLM, KC_QUES, KC_LPRN, KC_SLSH, XXXXXXX, KC_MUTE, KC_PERC, KC_RPRN, KC_LBRC, KC_RBRC, KC_EQL, KC_BSLS, KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_ENT, MO(1), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_MPRV, KC_MNXT, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, KC_MPLY, KC_LGUI, KC_LALT, KC_SPC, KC_BSPC, KC_RCTL, KC_RGUI, KC_PSCR),

                                                              [1] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG(3), _______, _______, KC_PGUP, KC_UP, KC_PGDN, _______, _______, KC_7, KC_8, KC_9, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_4, KC_5, KC_6, _______, _______, _______, _______, _______, _______, MO(2), _______, _______, _______, KC_0, KC_1, KC_2, KC_3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

                                                              [2] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

                                                              [3] = LAYOUT(_______, KC_1, KC_2, KC_3, KC_4, KC_5, _______, _______, KC_6, KC_7, KC_8, KC_9, KC_0, TG(3), _______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, _______, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, _______, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

const key_override_t circ_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_CIRC);
const key_override_t at_key_override   = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_AT);
const key_override_t dlr_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_DLR);
const key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_ASTR);
const key_override_t hash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_HASH);
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PERC, KC_TILD);
const key_override_t ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_AMPR);
const key_override_t del_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used.
const key_override_t **key_overrides = (const key_override_t *[]){
    &circ_key_override,
    &at_key_override,
    &dlr_key_override,
    &astr_key_override,
    &hash_key_override,
    &tild_key_override,
    &ampr_key_override,
    &del_key_override,
    NULL // Null terminate the array of overrides!
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}};
#endif

#ifdef OLED_ENABLE
static void print_status(void) {
    // Print current layer
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Dvorak\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("Caps-lock"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    // Render the OLED
    print_status();
    return false;
}
#endif
