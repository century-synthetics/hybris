/*
Copyright 2013,2016 Jun Wako <wakojun@gmail.com>

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
#include "keymap.h"
#include "keycode.h"
#include <avr/pgmspace.h>

/* key matrix position */
static action_t keycode_to_action(uint8_t keycode);


/* converts key to action */
__attribute__ ((weak))
action_t action_for_key(uint8_t layer, keypos_t key)
{
    uint8_t keycode = keymap_key_to_keycode(layer, key);
    switch (keycode) {
        case KC_FN0 ... KC_FN31:
            return keymap_fn_to_action(keycode);

        default:
            return keycode_to_action(keycode);
    }
}


/* Macro */
__attribute__ ((weak))
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    (void)record;
    (void)id;
    (void)opt;
    return MACRO_NONE;
}

/* Function */
__attribute__ ((weak))
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    (void)record;
    (void)id;
    (void)opt;
}



/* translates keycode to action */
static action_t keycode_to_action(uint8_t keycode)
{

}



#ifdef USE_LEGACY_KEYMAP
/*
 * Legacy keymap support
 *      Consider using new keymap API instead.
 */
extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint8_t fn_layer[];
extern const uint8_t fn_keycode[];

__attribute__ ((weak))
uint8_t keymap_get_keycode(uint8_t layer, uint8_t row, uint8_t col)
{
    return pgm_read_byte(&keymaps[(layer)][(row)][(col)]);
}

__attribute__ ((weak))
uint8_t keymap_fn_layer(uint8_t index)
{
    return pgm_read_byte(&fn_layer[index]);
}

__attribute__ ((weak))
uint8_t keymap_fn_keycode(uint8_t index)
{
    return pgm_read_byte(&fn_keycode[index]);
}

__attribute__ ((weak))
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    return keymap_get_keycode(layer, key.row, key.col);
}


/* Legacy keymap support */
__attribute__ ((weak))
action_t keymap_fn_to_action(uint8_t keycode)
{
    switch (keycode) {
        case KC_FN0 ... KC_FN31:
            {
                uint8_t layer = keymap_fn_layer(FN_INDEX(keycode));
                uint8_t key = keymap_fn_keycode(FN_INDEX(keycode));
                if (key) {
                    return (action_t)ACTION_LAYER_TAP_KEY(layer, key);
                } else {
                    return (action_t)ACTION_LAYER_MOMENTARY(layer);
                }
            }
            return (action_t)ACTION_NO;
        default:
            return (action_t)ACTION_NO;
    }
}

#else

/* user keymaps should be defined somewhere */
extern const action_t fn_actions[];

__attribute__ ((weak))
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{

}

__attribute__ ((weak))
action_t keymap_fn_to_action(uint8_t keycode)
{

}

#endif
