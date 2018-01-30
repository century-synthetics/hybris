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
  matrix_scan();
  Serial.print(matrix_get_row(1));
  waitForEvent();
}
