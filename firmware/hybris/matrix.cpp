#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "matrix.h"
#include "config.h"

static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

uint8_t row_pins[MATRIX_ROWS] = ROW_PINS;

void matrix_init(void)
{
  for (uint8_t row = 0; row < MATRIX_ROWS; row++)
  {
    pinMode(row_pins[row], OUTPUT);
  }

  pinMode(COL_SENSE_PIN, INPUT_PULLDOWN);
  pinMode(COL_CLK_PIN, OUTPUT);
  pinMode(COL_SHIFT_PIN, OUTPUT);
  pinMode(COL_DATA_PIN, INPUT);

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
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        delayMicroseconds(5);
        matrix_row_t rows = read_cols();
        if (matrix_debouncing[i] != rows) {
            matrix_debouncing[i] = rows;
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            delay(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }
    
    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}


bool matrix_is_on(uint8_t row, uint8_t col)
{
}


matrix_row_t matrix_get_row(uint8_t row) 
{
    return matrix[row];
}

static void init_cols(void)
{
  digitalWrite(COL_CLK_PIN, LOW);
  digitalWrite(COL_SHIFT_PIN, HIGH);
}

static matrix_row_t read_cols(void)
{
  matrix_row_t row_read = 0; 
  
  digitalWrite(COL_SHIFT_PIN, LOW);
  delayMicroseconds(COL_PULSE_WIDTH_USEC);
  digitalWrite(COL_SHIFT_PIN, HIGH);

  for (uint8_t col = 0; col < COL_DATA_WIDTH; col++) {
    if (digitalRead(COL_DATA_PIN) == HIGH) {
      row_read |= 1 << col;
    }

    // Pulse the Clock (rising edge shifts the next bit)
    digitalWrite(COL_CLK_PIN, HIGH);
    delayMicroseconds(COL_PULSE_WIDTH_USEC);
    digitalWrite(COL_CLK_PIN, LOW);
    delayMicroseconds(COL_PULSE_WIDTH_USEC);
  }

  return row_read;
}

static void unselect_rows(void)
{
  for (uint8_t row = 0; row < MATRIX_ROWS; row++)
  {
    digitalWrite(row_pins[row], LOW);
  }
}

static void select_row(uint8_t row)
{
  digitalWrite(row_pins[row], HIGH);
}
