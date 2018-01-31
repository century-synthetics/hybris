#include <Arduino.h>
#include <bluefruit.h>
#include "config.h"
#include "bluetooth.h"
#include "matrix.h"



void setup(void) {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  init_bluetooth();
  matrix_init();


  start_advertising();
}

void loop() {
    static matrix_row_t matrix_prev[MATRIX_ROWS];
    static uint8_t led_status = 0;
    matrix_row_t matrix_row = 0;
    matrix_row_t matrix_change = 0;

    matrix_scan();
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        matrix_row = matrix_get_row(r);
        matrix_change = matrix_row ^ matrix_prev[r];
        if (matrix_change) {
            matrix_row_t col_mask = 1;
            for (uint8_t c = 0; c < MATRIX_COLS; c++, col_mask <<= 1) {
                if (matrix_change & col_mask) {
                    Serial.print(r);
                    Serial.print(" ");
                    Serial.print(c);
                    Serial.print(" ");
                    Serial.print(matrix_row & col_mask);
                    Serial.print("\r\n");
                    
                    keyevent_t e = (keyevent_t){
                        .key = (keypos_t){ .row = r, .col = c },
                        .pressed = (matrix_row & col_mask),
                        .time = (millis() | 1) 
                    };/*
                    action_exec(e);
                    hook_matrix_change(e);
                    // record a processed key
                    matrix_prev[r] ^= col_mask;
                    */
                }
            }
        }
    }
  waitForEvent();
}
