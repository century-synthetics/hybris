#ifndef KEYPRESS_H
#define KEYPRESS_H
#include "stdbool.h"

/** Scan for any key being pressed in the matrix
 */
bool is_key_pressed();

/** Set the key press state
 */
void set_key_pressed(bool state);

#endif
