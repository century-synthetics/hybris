#ifndef ENCODER_H
#define ENCODER_H

#define ENCODER_DIRECTION_UP 1
#define ENCODER_DIRECTION_DOWN 0

/** encoder ISR callback
 */
void encoder_interrupt(void);

/** Test if the encoder value has changed
*/
bool is_encoder_changed();

/** Set the encoder's current state (volatile)
*/
void set_encoder_changed(bool new_state);

/** Initialize the rotary encoder
 */
void encoder_init(void);

/** The main encoder task
*/
void encoder_task();

#endif
