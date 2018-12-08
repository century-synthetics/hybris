# Firmware Information

This is a port of TMK specifically for the Adafruit BlueFruit NRF52 feather boards. The matrix implementation
uses 3 x 74HC165 shift registers for a total of 24 columns. Additionally, there's a rotary encoder subroutine
to handle some basic media controls. The firmware does not overwrite the Feather's base bootloader, so USB
is used only for programming and charging the battery. The main protocol is Bluetooth LE.

## Installation
* Download and install the Arduino IDE (At least v1.8.x)
* Start the Arduino IDE
* Go into Preferences
* Add https://www.adafruit.com/package_adafruit_index.json as an 'Additional Board Manager URL'
* Restart the Arduino IDE
* Open the Boards Manager from the Tools -> Board menu and install 'Adafruit nRF52 by Adafruit'
* Once the BSP is installed, select 'Adafruit Bluefruit nRF52 Feather' from the Tools -> Board menu, which will
update your system config to use the right compiler and settings for the nRF52.
* Choose your bootloader in Tools -> Bootloader (Mine is 0.5.0)
* Choose the programmer AVRISP II
* clone this repository to you arduino projects folder

## Configuration
You can generate a configuration here: http://kb.sized.io/
Download the raw source files when you're done.
At the time of this writing, the output from the site needs some tweaks to function properly with the
latest version of TMK.

There's two files you're interested in the keyboard(s) directory.

One that looks like this
```
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0 */
    KEYMAP(
         ESC,         F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F12, PSCR, SLCK, PAUS,                          F11, \
         GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS, BSPC,  INS, HOME, PGUP, NLCK, PSLS, PAST, PMNS,  EQL, \
         TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, BSLS,  DEL,  END, PGDN,   P7,   P8,   P9, PPLS, RBRC, \
        CAPS,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,  ENT,                     P4,   P5,   P6,             \
        LSFT,          Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, LSFT,         UP,         P1,   P2,   P3, PENT,       \
        LCTL, LGUI, LALT,                    SPC,             RALT, LGUI, MENU, RCTL, LEFT, DOWN, RGHT,    0,        DEL              ),
```

which you will convert and add to actionmap.cpp

```
const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0 */
     KEYMAP(
          ESC,         F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F12, PSCR, SLCK, PAUS,                          F11, \
          GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS, BSPC,  INS, HOME, PGUP, NLCK, PSLS, PAST, PMNS,  EQL, \
          TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, BSLS,  DEL,  END, PGDN,   P7,   P8,   P9, PPLS, RBRC, \
         CAPS,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,  ENT,                     P4,   P5,   P6,             \
         LSFT,          Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT,         UP,         P1,   P2,   P3, PENT,       \
         LCTL, LGUI, LALT,                    SPC,             RALT, LGUI, MENU, RCTL, LEFT, DOWN, RGHT,   P0,        DEL              ),
```

And another file that looks like this

```
#define KEYMAP( \
    K000,       K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015,                         K020, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,                   K316, K317, K318,             \
    K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,       K414,       K416, K417, K418, K419,       \
    K500, K501, K502,                   K506,             K509, K510, K511, K512, K513, K514, K515, K516,       K518              \
) { \
    { KC_##K000, KC_NO,     KC_##K002, KC_##K003, KC_##K004, KC_##K005, KC_##K006, KC_##K007, KC_##K008, KC_##K009, KC_##K010, KC_##K011, KC_##K012, KC_##K013, KC_##K014, KC_##K015, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_##K020, }, \
    { KC_##K100, KC_##K101, KC_##K102, KC_##K103, KC_##K104, KC_##K105, KC_##K106, KC_##K107, KC_##K108, KC_##K109, KC_##K110, KC_##K111, KC_##K112, KC_##K113, KC_##K114, KC_##K115, KC_##K116, KC_##K117, KC_##K118, KC_##K119, KC_##K120, }, \
    { KC_##K200, KC_##K201, KC_##K202, KC_##K203, KC_##K204, KC_##K205, KC_##K206, KC_##K207, KC_##K208, KC_##K209, KC_##K210, KC_##K211, KC_##K212, KC_##K213, KC_##K214, KC_##K215, KC_##K216, KC_##K217, KC_##K218, KC_##K219, KC_##K220, }, \
    { KC_##K300, KC_##K301, KC_##K302, KC_##K303, KC_##K304, KC_##K305, KC_##K306, KC_##K307, KC_##K308, KC_##K309, KC_##K310, KC_##K311, KC_##K312, KC_NO,     KC_NO,     KC_NO,     KC_##K316, KC_##K317, KC_##K318, KC_NO,     KC_NO,     }, \
    { KC_##K400, KC_NO,     KC_##K402, KC_##K403, KC_##K404, KC_##K405, KC_##K406, KC_##K407, KC_##K408, KC_##K409, KC_##K410, KC_##K411, KC_##K412, KC_NO,     KC_##K414, KC_NO,     KC_##K416, KC_##K417, KC_##K418, KC_##K419, KC_NO,     }, \
    { KC_##K500, KC_##K501, KC_##K502, KC_NO,     KC_NO,     KC_NO,     KC_##K506, KC_NO,     KC_NO,     KC_##K509, KC_##K510, KC_##K511, KC_##K512, KC_##K513, KC_##K514, KC_##K515, KC_##K516, KC_NO,     KC_##K518, KC_NO,     KC_NO,     }, \
}
```

which you will convert (not the AC_ prefix) and add to actionmap.cpp

```
#define KEYMAP( \
    K000,       K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015,                         K020, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,                   K316, K317, K318,             \
    K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,       K414,       K416, K417, K418, K419,       \
    K500, K501, K502,                   K506,             K509, K510, K511, K512, K513, K514, K515, K516,       K518              \
) { \
    { AC_##K000, AC_NO,     AC_##K002, AC_##K003, AC_##K004, AC_##K005, AC_##K006, AC_##K007, AC_##K008, AC_##K009, AC_##K010, AC_##K011, AC_##K012, AC_##K013, AC_##K014, AC_##K015, AC_NO,     AC_NO,     AC_NO,     AC_NO,     AC_##K020, }, \
    { AC_##K100, AC_##K101, AC_##K102, AC_##K103, AC_##K104, AC_##K105, AC_##K106, AC_##K107, AC_##K108, AC_##K109, AC_##K110, AC_##K111, AC_##K112, AC_##K113, AC_##K114, AC_##K115, AC_##K116, AC_##K117, AC_##K118, AC_##K119, AC_##K120, }, \
    { AC_##K200, AC_##K201, AC_##K202, AC_##K203, AC_##K204, AC_##K205, AC_##K206, AC_##K207, AC_##K208, AC_##K209, AC_##K210, AC_##K211, AC_##K212, AC_##K213, AC_##K214, AC_##K215, AC_##K216, AC_##K217, AC_##K218, AC_##K219, AC_##K220, }, \
    { AC_##K300, AC_##K301, AC_##K302, AC_##K303, AC_##K304, AC_##K305, AC_##K306, AC_##K307, AC_##K308, AC_##K309, AC_##K310, AC_##K311, AC_##K312, AC_NO,     AC_NO,     AC_NO,     AC_##K316, AC_##K317, AC_##K318, AC_NO,     AC_NO,     }, \
    { AC_##K400, AC_NO,     AC_##K402, AC_##K403, AC_##K404, AC_##K405, AC_##K406, AC_##K407, AC_##K408, AC_##K409, AC_##K410, AC_##K411, AC_##K412, AC_NO,     AC_##K414, AC_NO,     AC_##K416, AC_##K417, AC_##K418, AC_##K419, AC_NO,     }, \
    { AC_##K500, AC_##K501, AC_##K502, AC_NO,     AC_NO,     AC_NO,     AC_##K506, AC_NO,     AC_NO,     AC_##K509, AC_##K510, AC_##K511, AC_##K512, AC_##K513, AC_##K514, AC_##K515, AC_##K516, AC_NO,     AC_##K518, AC_NO,     AC_NO,     }, \
}
```

## Electrical Config
* Note: If you're using the shift registers, the diodes face row to column. Matrix ghosting should be enabled for this configuration.

Pinout:
```
A0   - Row 1
A1   - Row 2
A2   - Row 3
A3   - Row 4
A4   - Row 5
A5   - Row 6
SCK  - Shift Register CLK
MOSI - Shift Register Data IN
16   - Encoder OUT B
15   - Encoder OUT A
7    - Wake sense
11   - Shift Register LATCH (active low)
31   - BAT ADC (N/C)
17   - Charging indicator LED
27   - Connection indicator LED
```
