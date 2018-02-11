#include <Arduino.h>
#include <bluefruit.h>
#include <stdbool.h>
#include "config.h"
#include "keyboard.h"
#include "bluetooth.h"
#include "keypress.h"

void col_sense_interrupt() {
  set_key_pressed(true);
}

void setup(void) {
  Serial.begin(115200);
  NRF_PWM0  ->ENABLE = 0; //disable all pwm instance
  NRF_PWM1  ->ENABLE = 0;
  NRF_PWM2  ->ENABLE = 0;
  NRF_TWIM1 ->ENABLE = 0; //disable TWI Master
  NRF_TWIS1 ->ENABLE = 0; //disable TWI Slave
  //NRF_UARTE0->ENABLE = 0; //disable UART
  sd_power_mode_set(NRF_POWER_MODE_LOWPWR);
  sd_power_dcdc_mode_set(NRF_POWER_DCDC_DISABLE);
  init_bluetooth();
  keyboard_init();
  start_advertising();

  attachInterrupt(digitalPinToInterrupt(COL_SENSE_PIN), col_sense_interrupt, RISING);
}

void loop() {
  if (is_key_pressed()) {
    keyboard_task();
  }
  __WFI();
}
