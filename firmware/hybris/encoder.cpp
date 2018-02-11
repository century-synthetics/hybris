#include <Arduino.h>
#include <stdbool.h>
#include "encoder.h"
#include "config.h"

volatile bool encoder_state = false;

void encoder_interrupt(void) {
    if(!is_encoder_changed()) {
        set_encoder_changed(true);
    }
}

bool is_encoder_changed() {
    return encoder_state;
}

void set_encoder_changed(bool new_state) {
    encoder_state = new_state;
}

void encoder_init(void) {
    pinMode(ENCODER_A_PIN, INPUT_PULLUP);
    pinMode(ENCODER_C_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(ENCODER_C_PIN), encoder_interrupt, FALLING);
}

void encoder_task() {
    delayMicroseconds(128);

    if(digitalRead(ENCODER_C_PIN) == LOW) {
        if(digitalRead(ENCODER_A_PIN) == LOW) {
            Serial.print("UP");
        } else {
            Serial.print("DOWN");
        }
    }

    set_encoder_changed(false);
}
