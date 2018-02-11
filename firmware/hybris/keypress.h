#ifndef KEYPRESS_H
#define KEYPRESS_H
#include "stdbool.h"

/** Scan for any key being pressed in the matrix
 */
bool is_key_pressed();

/** Set the key press state
 */
void set_key_pressed(bool state);

/** keypress ISR callback
 */
void col_sense_interrupt();

/** keypress interrupt setup
*/
void keypress_init();

#endif
