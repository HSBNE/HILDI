/* Copyright 2021 Dave Seff
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMK_AT,
    QMK_HASH,
    QMK_GT,
    QMK_LT,
    QMK_RLD,
    QMK_CLR,
    QMK_NONE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
    /*  1         2        3        4          5        6        7        8        9   */
/* A */ KC_G,     KC_N,    KC_F,    KC_X,      KC_S,    KC_Y,    KC_M,    KC_Z,    KC_F8,
/* B */ KC_1,     KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,
/* C */ KC_T,     KC_D,    KC_BSPC, KC_I,      KC_J,    KC_K,    KC_L,    KC_P,    KC_R,
/* D */ KC_C,     KC_UP,   KC_PGUP, KC_LEFT,   KC_I,    KC_RIGHT,KC_DOWN, KC_PGDN, KC_F12,
/* E */ QMK_AT,   QMK_HASH,KC_F22,  KC_R,      KC_F11,  KC_COMM, KC_DOT,  KC_ESC,  KC_P,
/* F */ KC_F13,   KC_F14,  KC_F15,  KC_F16,    KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,
/* G */ KC_F3,    KC_F5,   KC_O,    QMK_RLD,   QMK_CLR, KC_F10,  KC_F23,  KC_F9,   KC_F24,
/* H */ KC_DOT,   KC_0,    KC_MINS, KC_B,      KC_C,    KC_SPC,  KC_ENT  ,KC_HOME, QMK_NONE
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMK_AT:   if (record->event.pressed) { SEND_STRING("@"); } break;
        case QMK_HASH: if (record->event.pressed) { SEND_STRING("#"); } break;
        case QMK_GT:   if (record->event.pressed) { SEND_STRING(">"); } break;
        case QMK_LT:   if (record->event.pressed) { SEND_STRING("<"); } break;
        case QMK_RLD:  if (record->event.pressed) { SEND_STRING(SS_LCTL("r")); } break;
        case QMK_CLR:  if (record->event.pressed) { SEND_STRING(SS_LCTL("k")); } break;
        case QMK_NONE: if (record->event.pressed) { SEND_STRING(" "); } break;
    }
    return true;
}
