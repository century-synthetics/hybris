#include <Arduino.h>
#include <bluefruit.h>
#include "config.h"
#include "keyboard.h"
#include "bluetooth.h"

void setup(void) {
  //Serial.begin(115200);
  NRF_PWM0  ->ENABLE = 0; //disable all pwm instance
  NRF_PWM1  ->ENABLE = 0;
  NRF_PWM2  ->ENABLE = 0;
  NRF_TWIM1 ->ENABLE = 0; //disable TWI Master
  NRF_TWIS1 ->ENABLE = 0; //disable TWI Slave
  NRF_UARTE0->ENABLE = 0; //disable UART
  sd_power_mode_set(NRF_POWER_MODE_LOWPWR);
  sd_power_dcdc_mode_set(NRF_POWER_DCDC_DISABLE);
  init_bluetooth();
  keyboard_init();
  start_advertising();
}

void loop() {
  keyboard_task();
  __WFI();
}
