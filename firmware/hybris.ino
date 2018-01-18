#include <Arduino.h>

#include "config.h"
#include "keycode.h"
#include "keymap.h"
#include "bluetooth.h"

void setup(void) {
  Serial.begin(115200);

  init_bluetooth();

  for (uint8_t row = 0; row < ROWS; row++) {
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

}
