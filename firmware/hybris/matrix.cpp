#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "matrix.h"
#include "config.h"

static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t matrix_reversed[MATRIX_COLS];
static matrix_row_t matrix_reversed_debouncing[MATRIX_COLS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_COLS; i++) {
        select_row(i);
        delayMicroseconds(30);  // without this wait read unstable value.
        matrix_row_t rows = read_cols();
        if (matrix_reversed_debouncing[i] != rows) {
            matrix_reversed_debouncing[i] = rows;
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            delay(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_COLS; i++) {
                matrix_reversed[i] = matrix_reversed_debouncing[i];
            }
        }
    }

    for (uint8_t y = 0; y < MATRIX_ROWS; y++) {
        matrix_row_t row = 0;
        for (uint8_t x = 0; x < MATRIX_COLS; x++) {
            row |= ((matrix_reversed[x] & (1<<y)) >> y) << x;
        }
        matrix[y] = row;
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
}

uint8_t matrix_key_count(void)
{
}

static void init_cols(void) {
}

static matrix_row_t read_cols(void) {
}

static void unselect_rows(void) {
}

static void select_row(uint8_t row) {
}
