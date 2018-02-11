#include "keypress.h"

volatile bool state = false;

bool is_key_pressed() {
    return state;
}

void set_key_pressed(bool new_state) {
    state = new_state;
}
