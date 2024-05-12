/* Copyright 2024 Łukasz Pawłowski <lukasz.adam.pawlowski@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _NUMERICAL,
    _FUNCTIONAL,
    _GAMING
};

enum {
  TD_Q_TAB = 0
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_Q_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB)
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,---------------------------------.     ,----------------------------------.
 * |  Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *       |   NO | LCTL | BSpc | Esc  |     | Ent  | Spc  | LAlt | NO    | 
 *      `-------`--------------------'     `--------------------`-------`
 */

[_QWERTY] = LAYOUT_split_3x5_4(
    KC_Q,   KC_W,     KC_E,    KC_R,              KC_T,                         KC_Y,       KC_U,               KC_I,    KC_O,   KC_P,
    KC_A,   KC_S,     KC_D,    KC_F,              KC_G,                         KC_H,       KC_J,               KC_K,    KC_L,   KC_SCLN,
    KC_Z,   KC_X,     KC_C,    KC_V,              KC_B,                         KC_N,       KC_M,               KC_COMM, KC_DOT, KC_RSFT,
            KC_LALT,  KC_RGUI, MO(_QWERTY),    MT(MOD_LCTL,KC_SPACE),        KC_ENTER,   MO(_QWERTY) ,   KC_BSPC, KC_TAB
),
[_QWERTY] = LAYOUT_split_3x5_4(
    KC_1,   KC_2,     KC_3,    KC_4,     KC_5,                         KC_6,       KC_7,          KC_8,    KC_9,   KC_0,
    KC_A,   KC_S,     KC_D,    KC_F,     KC_G,                         KC_H,       KC_J,          KC_K,    KC_L,   KC_SCLN,
    KC_Z,   KC_X,     KC_C,    KC_V,     KC_B,                         KC_N,       KC_M,          KC_COMM, KC_DOT, KC_RSFT,
            KC_LALT,  KC_RGUI, KC_NO,    MT(MOD_LCTL,KC_SPACE),        KC_ENTER,   TO(_QWERTY),   KC_BSPC, KC_TAB
),
// [_NUMERICAL] = LAYOUT_split_3x5_4(
//     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
//     KC_EQL,   KC_MINS,   KC_UP,   KC_LSFT,   KC_LGUI,       KC_RGUI,   KC_BSPC,   KC_SCLN,   KC_QUOT,   KC_BACKSLASH,
//     KC_GRV,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_LALT,       KC_RALT,   KC_LBRC,   KC_RBRC,   KC_SLASH,   KC_RSFT,
//                       KC_NO,   KC_NO, KC_SPACE,     KC_LCTL, KC_TAB, TO(_GAMING)
// ),
// [_FUNCTIONAL] = LAYOUT_split_3x5_4(
//     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
//     KC_F11,   KC_F12,   KC_NO,   KC_NO,   KC_EQL,       KC_LBRC, KC_RBRC,   LSFT(KC_COMM),   LSFT(KC_DOT),   KC_NO,
//     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       LSFT(KC_LBRC), LSFT(KC_RBRC),   LSFT(KC_9),   LSFT(KC_0),   KC_NO,
//                       KC_NO,   KC_ESC, KC_SPACE,     KC_TAB, KC_NO, KC_NO
// ),
// [_GAMING] = LAYOUT_split_3x5_4(
//     KC_TAB,   KC_1,   KC_2,   KC_3,   KC_4,       KC_5,   KC_6,   KC_7,   KC_8,   KC_9,
//     KC_LSFT,   KC_Q,   KC_W,   KC_E,   KC_R,       KC_F, KC_I,   KC_UP,   KC_O,   KC_H,
//     KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_G,       KC_B, KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_M,
//                       KC_NO,   KC_LALT, KC_SPACE,     KC_ENTER, KC_ESC, TO(_QWERTY)
// )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;
    }

    return rotation;
}

void render_logo(void) {
    static const char PROGMEM logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83, 0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80, 0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0, 0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
                                               0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00};
    oled_write_raw_P(logo, sizeof(logo));
}


bool oled_task_user(void) {
    if(!is_keyboard_master()) {
        render_logo();
    }else {
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NUMERICAL:
                oled_write_P(PSTR("NUMERICAL\n"), false);
                break;
            case _FUNCTIONAL:
                oled_write_P(PSTR("FUNCTIONAL\n"), false);
                break;
            case _GAMING:
                oled_write_P(PSTR("GAMING\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
    }
    return false;
}
#endif
