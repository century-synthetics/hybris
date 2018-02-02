#ifndef CONFIG_H
    #define CONFIG_H

    #include <stdint.h>
    #include <stdbool.h>
    #include "report.h"
    
    #define ADVERTISE_NAME    "Hybris"
    #define MANUFACTURER_NAME "Century Synthetics"
    #define MODEL_NAME        "Hybris Mechanical Keyboard"

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

    #define CAPS_LED 25

    #define DEBOUNCE 10

    #define _delay_us(us) delayMicroseconds(us)
    #define _delay(ms) delay(ms)

    /* key matrix position */
    typedef struct {
        uint8_t row;
        uint8_t col;
    } keypos_t;
    
    /* key event */
    typedef struct {
        keypos_t key;
        bool     pressed;
        uint16_t time;
    } keyevent_t;

    typedef struct {
        uint8_t (*keyboard_leds)(void);
        void (*send_keyboard)(report_keyboard_t *);
        void (*send_mouse)(report_mouse_t *);
        void (*send_system)(uint16_t);
        void (*send_consumer)(uint16_t);
    } host_driver_t;
    
    /* equivalency test of keypos_t */
    #define KEYEQ(keya, keyb)       ((keya).row == (keyb).row && (keya).col == (keyb).col)
    
    /* Rules for No Event:
     * 1) (time == 0) to handle (keyevent_t){} as empty event
     * 2) Matrix(255, 255) to make TICK event available
     */
    static inline bool IS_NOEVENT(keyevent_t event) { return event.time == 0 || (event.key.row == 255 && event.key.col == 255); }
    static inline bool IS_PRESSED(keyevent_t event) { return (!IS_NOEVENT(event) && event.pressed); }
    static inline bool IS_RELEASED(keyevent_t event) { return (!IS_NOEVENT(event) && !event.pressed); }
    
    /* Tick event */
    #define TICK                    (keyevent_t){           \
        .key = (keypos_t){ .row = 255, .col = 255 },        \
        .pressed = false,                                   \
        .time = (timer_read() | 1)                          \
    }

    #define TIMER_DIFF(a, b, max)   ((a) >= (b) ?  (a) - (b) : (max) - (b) + (a))
    #define TIMER_DIFF_8(a, b)      TIMER_DIFF(a, b, UINT8_MAX)
    #define TIMER_DIFF_16(a, b)     TIMER_DIFF(a, b, UINT16_MAX)
    #define TIMER_DIFF_32(a, b)     TIMER_DIFF(a, b, UINT32_MAX)
    #define TIMER_DIFF_RAW(a, b)    TIMER_DIFF_8(a, b)
#endif
