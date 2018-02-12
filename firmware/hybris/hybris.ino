#include <Arduino.h>
#include <bluefruit.h>
#include <stdbool.h>
#include "config.h"
#include "keyboard.h"
#include "bluetooth.h"
#include "keypress.h"
#include "encoder.h"
#include <math.h>

void setup(void) {
  Serial.begin(115200);
  //NRF_TWIM1 ->ENABLE = 0; //disable TWI Master
  //NRF_TWIS1 ->ENABLE = 0; //disable TWI Slave
  sd_power_mode_set(NRF_POWER_MODE_LOWPWR);
  sd_power_dcdc_mode_set(NRF_POWER_DCDC_DISABLE);
  pinMode(27, OUTPUT);
  analogWrite(27, 0);
  
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

  if(!is_bluetooth_connected()) {
    float val = 1 + (exp(sin(millis()/2000.0*PI)) - 0.36787944) * 107.0;

    analogWrite(27, val);

    delayMicroseconds(50);

    if(is_bluetooth_connected()) {
      analogWrite(27, 0);
    }
  }
  
  __WFI();
}
