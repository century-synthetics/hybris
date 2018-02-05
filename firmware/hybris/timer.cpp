/*
 * gluecode.c
 *
 * Copyright 2014 Benjamin Gould <bgould@github.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */
#include "timer.h"
#include <stdint.h>
#include <Arduino.h>

volatile unsigned long timer_count = 0;

void timer_init() {
	timer_count = millis();
}

void timer_clear(void) {
	timer_count = millis();
}

uint16_t timer_read(void) {
	unsigned long t = millis() - timer_count;
    return (t & 0xFFFF);
}

uint32_t timer_read32(void) {
	return millis() - timer_count;
}

uint16_t timer_elapsed(uint16_t last) {
	uint32_t t;
    t = millis() - timer_count;
    return TIMER_DIFF_16((t & 0xFFFF), last);
}

uint32_t timer_elapsed32(uint32_t last) {
	uint32_t t;
    t = millis() - timer_count;
    return TIMER_DIFF_32(t, last);
}

void print_set_sendchar(int8_t (*print_sendchar_func)(uint8_t)) {
	//xdev_out(print_sendchar_func);
}
