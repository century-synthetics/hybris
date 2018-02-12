#include <Arduino.h>
#include <bluefruit.h>
#include <stdbool.h>
#include "config.h"
#include "keyboard.h"
#include "bluetooth.h"
#include "keypress.h"
#include "encoder.h"

void setup(void) {
  Serial.begin(115200);
  //NRF_TWIM1 ->ENABLE = 0; //disable TWI Master
  //NRF_TWIS1 ->ENABLE = 0; //disable TWI Slave
  sd_power_mode_set(NRF_POWER_MODE_LOWPWR);
  sd_power_dcdc_mode_set(NRF_POWER_DCDC_DISABLE);
  
  init_bluetooth();
  keypress_init();
  encoder_init();
  keyboard_init();
  start_advertising();
}

void loop() {
  if (is_encoder_changed()) {
    encoder_task();  
  }
  
  if (is_key_pressed()) {
    keyboard_task();
  }
  __WFI();
}
