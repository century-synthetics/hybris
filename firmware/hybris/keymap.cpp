#include "keymap_common.h"
#include "config.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0 */
    KEYMAP(
         ESC,         F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F12, PSCR, SLCK, PAUS,                          F11, \
         GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS, BSPC,  INS, HOME, PGUP, NLCK, PSLS, PAST, PMNS,  EQL, \
         TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, BSLS,  DEL,  END, PGDN,   P7,   P8,   P9, PPLS, RBRC, \
        CAPS,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,  ENT,                     P4,   P5,   P6,             \
        LSFT,          Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT,         UP,         P1,   P2,   P3, PENT,       \
        LCTL, LGUI, LALT,                    SPC,             RALT, LGUI, MENU, RCTL, LEFT, DOWN, RGHT,    0,        DEL              ),
    /* layer 1 */
    KEYMAP(
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,             \
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
    /* layer 2 */
    KEYMAP(
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,             \
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
    /* layer 3 */
    KEYMAP(
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,             \
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
    /* layer 4 */
    KEYMAP(
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,             \
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
    /* layer 5 */
    KEYMAP(
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,             \
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
    /* layer 6 */
    KEYMAP(
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,             \
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
    /* layer 7 */
    KEYMAP(
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                         TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                   TRNS, TRNS, TRNS,             \
        TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS, TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS              ),
};

enum macro_id {
    MACRO_0,
    MACRO_1,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5,
    MACRO_6,
    MACRO_7,
};
