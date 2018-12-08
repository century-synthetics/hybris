/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <Arduino.h>
#include <stdint.h>
#include "action_code.h"
#include "actionmap.h"
#include "config.h"

#define KEYMAP( \
    K000,       K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015,                         K020, K521, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,                   K316, K317, K318,                   \
    K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,       K414,       K416, K417, K418, K419,             \
    K500, K501, K502,                   K506,             K509, K510, K511, K512, K513, K514, K515, K516,       K518                    \
) { \
    { AC_##K000, AC_NO,     AC_##K002, AC_##K003, AC_##K004, AC_##K005, AC_##K006, AC_##K007, AC_##K008, AC_##K009, AC_##K010, AC_##K011, AC_##K012, AC_##K013, AC_##K014, AC_##K015, AC_NO,     AC_NO,     AC_NO,     AC_NO,     AC_##K020, AC_##K521, }, \
    { AC_##K100, AC_##K101, AC_##K102, AC_##K103, AC_##K104, AC_##K105, AC_##K106, AC_##K107, AC_##K108, AC_##K109, AC_##K110, AC_##K111, AC_##K112, AC_##K113, AC_##K114, AC_##K115, AC_##K116, AC_##K117, AC_##K118, AC_##K119, AC_##K120, AC_NO,     }, \
    { AC_##K200, AC_##K201, AC_##K202, AC_##K203, AC_##K204, AC_##K205, AC_##K206, AC_##K207, AC_##K208, AC_##K209, AC_##K210, AC_##K211, AC_##K212, AC_##K213, AC_##K214, AC_##K215, AC_##K216, AC_##K217, AC_##K218, AC_##K219, AC_##K220, AC_NO,     }, \
    { AC_##K300, AC_##K301, AC_##K302, AC_##K303, AC_##K304, AC_##K305, AC_##K306, AC_##K307, AC_##K308, AC_##K309, AC_##K310, AC_##K311, AC_##K312, AC_NO,     AC_NO,     AC_NO,     AC_##K316, AC_##K317, AC_##K318, AC_NO,     AC_NO,     AC_NO,     }, \
    { AC_##K400, AC_NO,     AC_##K402, AC_##K403, AC_##K404, AC_##K405, AC_##K406, AC_##K407, AC_##K408, AC_##K409, AC_##K410, AC_##K411, AC_##K412, AC_NO,     AC_##K414, AC_NO,     AC_##K416, AC_##K417, AC_##K418, AC_##K419, AC_NO,     AC_NO,     }, \
    { AC_##K500, AC_##K501, AC_##K502, AC_NO,     AC_NO,     AC_NO,     AC_##K506, AC_NO,     AC_NO,     AC_##K509, AC_##K510, AC_##K511, AC_##K512, AC_##K513, AC_##K514, AC_##K515, AC_##K516, AC_NO,     AC_##K518, AC_NO,     AC_NO,     AC_NO,     }, \
}


/* Keymapping with 16bit action codes */
const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0 */
     KEYMAP(
          ESC,         F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F12, PSCR, SLCK, PAUS,                          F11, MUTE, \
          GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS, BSPC,  INS, HOME, PGUP, NLCK, PSLS, PAST, PMNS,  EQL,       \
          TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, BSLS,  DEL,  END, PGDN,   P7,   P8,   P9, PPLS, RBRC,       \
         CAPS,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,  ENT,                     P4,   P5,   P6,                   \
         LSFT,          Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT,         UP,         P1,   P2,   P3, PENT,             \
         LCTL, LGUI, LALT,                    SPC,             RALT, LGUI, MENU, RCTL, LEFT, DOWN, RGHT,   P0,        KP_DOT           ),
     /* layer 1 */
     KEYMAP(
         TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, TRNS, \
         TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       \
         TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       \
         TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,                   \
         TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,             \
         TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
};

/* Converts key to action */
__attribute__ ((weak))
action_t action_for_key(uint8_t layer, keypos_t key)
{
    return (action_t) actionmaps[(layer)][(key.row & 0x7)][(key.col)];
}

/* Macro */
__attribute__ ((weak))
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    return MACRO_NONE;
}

/* Function */
__attribute__ ((weak))
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
}
