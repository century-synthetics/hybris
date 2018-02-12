#include <Arduino.h>
#include <stdbool.h>
#include <bluefruit.h>
#include "encoder.h"
#include "config.h"
#include "keycode.h"
#include "bluetooth.h"

volatile bool encoder_state = false;
volatile uint8_t encoder_direction;

void encoder_interrupt(void) {
    if(!is_encoder_changed()) {
        set_encoder_changed(true);

        if(digitalRead(ENCODER_C_PIN) == LOW) {
            if(digitalRead(ENCODER_A_PIN) == LOW) {
                encoder_direction = ENCODER_DIRECTION_UP;
            } else {
                encoder_direction = ENCODER_DIRECTION_DOWN;
            }
        }
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
    uint8_t encoderPin = digitalRead(ENCODER_A_PIN);

    delayMicroseconds(512);

    if(encoderPin == LOW && encoder_direction == ENCODER_DIRECTION_UP) {
        Serial.print("UP");
        send_encoder_report(HID_USAGE_CONSUMER_VOLUME_INCREMENT);
    } else if(encoderPin == HIGH && encoder_direction == ENCODER_DIRECTION_DOWN) {
        Serial.print("DOWN");
        send_encoder_report(HID_USAGE_CONSUMER_VOLUME_DECREMENT);
    }

    delay(2);

    set_encoder_changed(false);
}
