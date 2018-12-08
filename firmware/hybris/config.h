#ifndef CONFIG_H
    #define CONFIG_H
    #include <Arduino.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include "report.h"

    #define ADVERTISE_NAME    "Hybris"
    #define MANUFACTURER_NAME "Century Synthetics"
    #define MODEL_NAME        "Hybris Mechanical Keyboard"

    #define NO_ACTION_TAPPING true
    #define MATRIX_HAS_GHOST true
    #define EXTRAKEY_ENABLE true

    /* key matrix size */
    #define MATRIX_ROWS 6
    #define MATRIX_COLS 24

    #define ENCODER_A_PIN 15
    #define ENCODER_C_PIN 16

    #define COL_SENSE_PIN 7
    #define COL_LATCH_PIN 11
    #define COL_PULSE_WIDTH_USEC 5
    #define ROW_PINS { A0, A1, A2, A3, A4, A5 }

    #define CONNECTED_INDICATOR_LED_PIN 27
    #define CHARGE_INDICATOR_LED_PIN 17

    #define DEBOUNCE 5

    #define _delay_us(us) delayMicroseconds(us)
    #define _delay_ms(ms) delay(ms)
    #define _delay(ms) delay(ms)
#endif
