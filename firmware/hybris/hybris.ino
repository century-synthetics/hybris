#include <Arduino.h>
#include <bluefruit.h>
#include "config.h"
#include "bluetooth.h"
#include "matrix.h"

uint8_t row_pins[MATRIX_ROWS] = ROW_PINS;

void setup(void) {
  Serial.begin(115200);

  init_bluetooth();

  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    pinMode(row_pins[row], OUTPUT);
    digitalWrite(row_pins[row], LOW);
  }

  pinMode(COL_SENSE_PIN, INPUT_PULLDOWN);
  pinMode(COL_CLK_PIN, OUTPUT);
  pinMode(COL_SHIFT_PIN, OUTPUT);
  pinMode(COL_DATA_PIN, INPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(COL_CLK_PIN, LOW);
  digitalWrite(COL_SHIFT_PIN, HIGH);

  start_advertising();
}

void loop() {

  waitForEvent();
}
