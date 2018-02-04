#include <Arduino.h>
#include <bluefruit.h>
#include "config.h"
#include "keyboard.h"
#include "bluetooth.h"

void setup(void) {
  Serial.begin(115200);
  init_bluetooth();
  keyboard_init();
  start_advertising();
}

void loop() {
  keyboard_task();
  waitForEvent();
}
