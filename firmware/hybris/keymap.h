/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

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

#ifndef KEYMAP_H
#define KEYMAP_H

#include <stdint.h>
#include <stdbool.h>
#include "config.h"

/* macros */
typedef uint8_t macro_t;
#define MACRO_NONE      0
#define MACRO(...)      ({ static const macro_t __m[] PROGMEM = { __VA_ARGS__ }; &__m[0]; })
#define MACRO_GET(p)    pgm_read_byte(p)

/* Key event container for recording */
typedef struct {
    keyevent_t  event;
} keyrecord_t;

typedef union {
    uint16_t code;
    struct action_kind {
        uint16_t param  :12;
        uint8_t  id     :4;
    } kind;
    struct action_key {
        uint8_t  code   :8;
        uint8_t  mods   :4;
        uint8_t  kind   :4;
    } key;
    struct action_layer_bitop {
        uint8_t  bits   :4;
        uint8_t  xbit   :1;
        uint8_t  part   :3;
        uint8_t  on     :2;
        uint8_t  op     :2;
        uint8_t  kind   :4;
    } layer_bitop;
    struct action_layer_tap {
        uint8_t  code   :8;
        uint8_t  val    :5;
        uint8_t  kind   :3;
    } layer_tap;
    struct action_usage {
        uint16_t code   :10;
        uint8_t  page   :2;
        uint8_t  kind   :4;
    } usage;
    struct action_backlight {
        uint8_t  level  :8;
        uint8_t  opt    :4;
        uint8_t  kind   :4;
    } backlight;
    struct action_command {
        uint8_t  id     :8;
        uint8_t  opt    :4;
        uint8_t  kind   :4;
    } command;
    struct action_function {
        uint8_t  id     :8;
        uint8_t  opt    :4;
        uint8_t  kind   :4;
    } func;
} action_t;



/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key);

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode);

#endif
