#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include <SPI.h>
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
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));

  for (uint8_t row = 0; row < MATRIX_ROWS; row++)
  {
    pinMode(row_pins[row], OUTPUT);
  }

  pinMode(COL_LATCH_PIN, OUTPUT);

  // initialize row and col
  select_all_rows();
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
        unselect_rows();
        select_row(i);
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

matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

static void init_cols(void)
{
  digitalWrite(COL_LATCH_PIN, HIGH);
}

static matrix_row_t read_cols(void)
{
  matrix_row_t row_read = 0;

  //Latch the shift registers
  digitalWrite(COL_LATCH_PIN, LOW);
  delayMicroseconds(COL_PULSE_WIDTH_USEC);
  digitalWrite(COL_LATCH_PIN, HIGH);

  // Transfer the data from SPI
  uint8_t register1 = SPI.transfer(0);
  uint8_t register2 = SPI.transfer(0);
  uint8_t register3 = SPI.transfer(0);

  row_read = register1 << 16 | register2 << 8 | register3;

  return row_read;
}

static void unselect_rows(void)
{
  for (uint8_t row = 0; row < MATRIX_ROWS; row++)
  {
    digitalWrite(row_pins[row], LOW);
  }

  delayMicroseconds(ROW_SETTLE_TIME_US);
}

void select_all_rows(void)
{
    for (uint8_t row = 0; row < MATRIX_ROWS; row++)
    {
      digitalWrite(row_pins[row], HIGH);
    }

    delayMicroseconds(ROW_SETTLE_TIME_US);
}

static void select_row(uint8_t row)
{
  digitalWrite(row_pins[row], HIGH);

  delayMicroseconds(ROW_SETTLE_TIME_US);
}

void matrix_print(void)
{
}
