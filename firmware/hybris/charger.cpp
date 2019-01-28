#include <Arduino.h>
#include <stdint.h>
#include "battery.h"
#include "charger.h"

volatile bool charger_state = false;

void charger_interrupt() {
    charger_state = digitalRead(CHARGER_PRESENCE_PIN);
}

void charger_init() {
    pinMode(CHARGER_PRESENCE_PIN, INPUT);

    attachInterrupt(digitalPinToInterrupt(CHARGER_PRESENCE_PIN), charger_interrupt, CHANGE);
}

bool charger_present() {
    return charger_state;
}

void charger_task() {
    if (millis() % 10) {
        battery_tick();
    }
}
