#include <Arduino.h>
#include <stdbool.h>
#include "indicators.h"
#include "bluetooth.h"
#include "config.h"

bool connected_state = false;
bool charging_state = false;

void charging_led_task() {
}

void connected_led_task() {
    bool current_state = is_bluetooth_connected();

    // When connection state changes, disable the LED.
    // While disconnected, set the LED to breathe
    if (current_state != connected_state) {
        analogWrite(CONNECTED_INDICATOR_LED_PIN, LED_OFF);
    } else if (current_state == false) {
        analogWrite(CONNECTED_INDICATOR_LED_PIN, get_level());
    }

    connected_state = current_state;
}

void indicators_init() {
    pinMode(CHARGE_INDICATOR_LED_PIN, OUTPUT);
    analogWrite(CHARGE_INDICATOR_LED_PIN, LED_OFF);

    pinMode(CONNECTED_INDICATOR_LED_PIN, OUTPUT);
    analogWrite(CONNECTED_INDICATOR_LED_PIN, LED_OFF);
}
