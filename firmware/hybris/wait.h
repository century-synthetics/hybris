#ifndef WAIT_H
#define WAIT_H

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define wait_ms(ms)  _delay_ms(ms)
#define wait_us(us)  _delay_us(us)

#ifdef __cplusplus
}
#endif

#endif
