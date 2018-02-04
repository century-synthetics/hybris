#include <stdbool.h>
#include "debug.h"

#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

debug_config_t debug_config = {
    {
        false,  // .enable
        false,  // .matrix
        false,  // .keyboard
        false,  // .mouse
        0       // .reserved
    }
};
