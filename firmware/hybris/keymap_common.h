#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "keymap.h"
#include "config.h"

extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

#define KEYMAP( \
    K000,       K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015,                         K020, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,                   K316, K317, K318,             \
    K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,       K414,       K416, K417, K418, K419,       \
    K500, K501, K502,                   K506,             K509, K510, K511, K512, K513, K514, K515, K516,       K518              \
) { \
    { KC_##K000, KC_NO,     KC_##K002, KC_##K003, KC_##K004, KC_##K005, KC_##K006, KC_##K007, KC_##K008, KC_##K009, KC_##K010, KC_##K011, KC_##K012, KC_##K013, KC_##K014, KC_##K015, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_##K020, }, \
    { KC_##K100, KC_##K101, KC_##K102, KC_##K103, KC_##K104, KC_##K105, KC_##K106, KC_##K107, KC_##K108, KC_##K109, KC_##K110, KC_##K111, KC_##K112, KC_##K113, KC_##K114, KC_##K115, KC_##K116, KC_##K117, KC_##K118, KC_##K119, KC_##K120, }, \
    { KC_##K200, KC_##K201, KC_##K202, KC_##K203, KC_##K204, KC_##K205, KC_##K206, KC_##K207, KC_##K208, KC_##K209, KC_##K210, KC_##K211, KC_##K212, KC_##K213, KC_##K214, KC_##K215, KC_##K216, KC_##K217, KC_##K218, KC_##K219, KC_##K220, }, \
    { KC_##K300, KC_##K301, KC_##K302, KC_##K303, KC_##K304, KC_##K305, KC_##K306, KC_##K307, KC_##K308, KC_##K309, KC_##K310, KC_##K311, KC_##K312, KC_NO,     KC_NO,     KC_NO,     KC_##K316, KC_##K317, KC_##K318, KC_NO,     KC_NO,     }, \
    { KC_##K400, KC_NO,     KC_##K402, KC_##K403, KC_##K404, KC_##K405, KC_##K406, KC_##K407, KC_##K408, KC_##K409, KC_##K410, KC_##K411, KC_##K412, KC_NO,     KC_##K414, KC_NO,     KC_##K416, KC_##K417, KC_##K418, KC_##K419, KC_NO,     }, \
    { KC_##K500, KC_##K501, KC_##K502, KC_NO,     KC_NO,     KC_NO,     KC_##K506, KC_NO,     KC_NO,     KC_##K509, KC_##K510, KC_##K511, KC_##K512, KC_##K513, KC_##K514, KC_##K515, KC_##K516, KC_NO,     KC_##K518, KC_NO,     KC_NO,     }, \
}

#endif
