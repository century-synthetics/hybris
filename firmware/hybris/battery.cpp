#include <Arduino.h>
#include <stdint.h>
#include "battery.h"
#include "bluetooth.h"

uint8_t counter = 0;

uint8_t mvToPercent(float mvolts) {
    uint8_t battery_level;

    // Adding a constant since the full charge on lipo is 4.2V
    mvolts = mvolts - 940;

    if (mvolts >= 3000)
    {
        battery_level = 100;
    }
    else if (mvolts > 2900)
    {
        battery_level = 100 - ((3000 - mvolts) * 58) / 100;
    }
    else if (mvolts > 2740)
    {
        battery_level = 42 - ((2900 - mvolts) * 24) / 160;
    }
    else if (mvolts > 2440)
    {
        battery_level = 18 - ((2740 - mvolts) * 12) / 300;
    }
    else if (mvolts > 2100)
    {
        battery_level = 6 - ((2440 - mvolts) * 6) / 340;
    }
    else
    {
        battery_level = 0;
    }

    return battery_level;
}

void battery_tick() {
    counter++;
}

void battery_task() {
    if(counter == 0) {
        int raw = analogRead(VBAT_PIN);

        delay(1);

        Serial.print("Battery Update: ");
        Serial.print(raw);
        Serial.print(" ");
        Serial.print(mvToPercent(raw));
        Serial.print("\r\n");

        update_battery(mvToPercent(raw));

        counter++;
    }
}

void battery_init() {
    // Set the analog reference to 3.0V (default = 3.6V)
    analogReference(AR_INTERNAL_3_0);

    // Set the resolution to 12-bit (0..4095)
    analogReadResolution(12); // Can be 8, 10, 12 or 14

    // pinMode is already set by the framework
}
