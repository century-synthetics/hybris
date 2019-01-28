#include <Arduino.h>
#include <bluefruit.h>
#include <stdbool.h>
#include "config.h"
#include "keyboard.h"
#include "bluetooth.h"
#include "keypress.h"
#include "encoder.h"
#include "indicators.h"
#include "battery.h"
#include "charger.h"


void setup(void) {
  Serial.begin(115200);
  
  init_bluetooth();
  keypress_init();
  encoder_init();
  keyboard_init();
  indicators_init();
  battery_init();
  charger_init();
  start_advertising();
}

void loop() {
  if (is_encoder_changed()) {
    encoder_task();  
  }
  
  if (is_key_pressed()) {
    keyboard_task();
  }

  charger_task();
  connected_led_task();
  charging_led_task();
  battery_task();
  
  __WFI();
}
