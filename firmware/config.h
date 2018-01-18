#ifndef CONFIG_H
    #define CONFIG_H

    #define ADVERTISE_NAME    Hybris
    #define MANUFACTURER_NAME Century Synthetics
    #define MODEL_NAME        Hybris Mechanical Keyboard

    /* key matrix size */
    #define MATRIX_ROWS 6
    #define MATRIX_COLS 21

    #define VBAT 31
    #define LED 17

    #define COL_SENSE_PIN 11
    #define COL_CLK_PIN 30
    #define COL_SHIFT_PIN 27
    #define COL_DATA_PIN 26
    #define COL_PULSE_WIDTH_USEC 5
    #define COL_DATA_WIDTH 24
    #define ROW_PINS { A0, A1, A2, A3, A4, A5 }
    #define ROWS 6

    #define CAPS_LED 25

    #define DEBOUNCE 10
#endif
