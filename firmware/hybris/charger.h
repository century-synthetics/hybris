#ifndef CHARGER_H
#define CHARGER

// Charger input pin
#define CHARGER_PRESENCE_PIN          (30)

// main loop task
void charger_task();

// true if the usb charger is plugged in
bool charger_present();

// init the interrupt for listening to USB presence
void charger_init();

#endif
