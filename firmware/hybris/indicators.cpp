#include <Arduino.h>
#include <stdbool.h>
#include "indicators.h"
#include "bluetooth.h"
#include "config.h"
#include "charger.h"

bool connected_state = false;
bool charging_state = false;

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

void charging_led_task() {
    charging_state = charger_present();
    int battery_level = battery_get_percentage();

    // When USB is present and the battery is not at full charge, animate the LED
    // When USB is present and the battery is fully charged, turn the LED on solid
    // When USB is not present set the LED to off
    if(current_state == true && battery_level !== 100) {
        analogWrite(CONNECTED_INDICATOR_LED_PIN, get_level());
    } else if(current_state == true) {
        charging_state = true;
        analogWrite(CONNECTED_INDICATOR_LED_PIN, LED_ON);
    } else if (current_state != charging_state) {
        charging_state = false;
        analogWrite(CONNECTED_INDICATOR_LED_PIN, LED_OFF);
    }
}

void indicators_init() {
    pinMode(CONNECTED_INDICATOR_LED_PIN, OUTPUT);
    analogWrite(CONNECTED_INDICATOR_LED_PIN, LED_OFF);

    pinMode(CHARGE_INDICATOR_LED_PIN, OUTPUT);
    analogWrite(CHARGE_INDICATOR_LED_PIN, LED_OFF);
}
