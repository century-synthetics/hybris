#include "timer.h"
#include <stdint.h>
#include <Arduino.h>

uint16_t timer_read(void) {
    return (uint32_t) micros;
}
