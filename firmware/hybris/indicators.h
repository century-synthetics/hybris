#ifndef INDICATORS_H
#define INDICATORS_H

#include <Arduino.h>
#include <math.h>

// Pulsating LED formula
// @see http://sean.voisen.org/blog/2011/10/breathing-led-with-arduino/
#define get_level() (1 + (exp(sin(millis()/2000.0*PI)) - 0.36787944) * 107.0)
#define LED_OFF 0
#define LED_ON 1

/** Watcher tasks for USB charging events
*/
void charging_led_task();

/** Watcher tasks for bluetooth connection events
*/
void connected_led_task();

/** Initializer
*/
void indicators_init();

#endif
