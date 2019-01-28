#ifndef CHARGER_H
#define CHARGER

// Charger input pin
#define CHARGER_PRESENCE_PIN          (30)

// main loop task
void charger_task();

// tick with each keypress. On overflow, update the battery level
bool charger_present();

// init the interrupt for listening to USB presence
void charger_init();

#endif
