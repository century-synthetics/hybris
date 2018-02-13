#ifndef BATTERY_H
#define BATTERY

/** @see https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/Bluefruit52Lib/examples/Hardware/adc_vbat/adc_vbat.ino
 */
#define VBAT_PIN          (A7)
#define VBAT_MV_PER_LSB   (0.73242188F)   // 3.0V ADC range and 12-bit ADC resolution = 3000mV/4096
#define VBAT_DIVIDER      (0.71275837F)   // 2M + 0.806M voltage divider on VBAT = (2M / (0.806M + 2M))
#define VBAT_DIVIDER_COMP (1.403F)        // Compensation factor for the VBAT divider

uint8_t mvToPercent(float mvolts);

// main loop task
void battery_task();

// tick with each keypress. On overflow, update the battery level
void battery_tick();

// init the ADC to work with the math provided in the vendor example
void battery_init();

#endif
