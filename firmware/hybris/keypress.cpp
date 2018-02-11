#include <Arduino.h>
#include "keypress.h"
#include "config.h"

volatile bool state = false;

bool is_key_pressed() {
    return state;
}

void set_key_pressed(bool new_state) {
    state = new_state;
}

void col_sense_interrupt() {
    set_key_pressed(true);
}

void keypress_init() {
    pinMode(COL_SENSE_PIN, INPUT_PULLDOWN);

    attachInterrupt(digitalPinToInterrupt(COL_SENSE_PIN), col_sense_interrupt, RISING);
}
