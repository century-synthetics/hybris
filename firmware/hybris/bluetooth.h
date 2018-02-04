/**
 * Bluetooth driver from
 * https://github.com/afriggeri/kb
 */
#ifndef BLUETOOTH_H
    #define BLUETOOTH_H

    #define IN_KEYBOARD_RANGE(kc) ((kc >> 12) == 0)
    #define IN_CONSUMER_RANGE(kc) ((kc >> 12) == 1)
    #define IN_SPECIAL_RANGE(kc)  ((kc >> 12) == 2)

    void send_report_keyboard();
    void register_keydown(uint16_t keycode);
    void register_keyup(uint16_t keycode);
    void init_bluetooth();
    bool is_bluetooth_connected();
    void update_battery(uint8_t bat_percentage);
    void start_advertising();
    void send_report_bluetooth(report_keyboard_t *report);
#endif
