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
