/**
 * Bluetooth driver from
 * https://github.com/afriggeri/kb
 */
#ifndef BLUETOOTH_H
    #define BLUETOOTH_H

    void init_bluetooth();
    void send_encoder_report(uint16_t usage_code);
    bool is_bluetooth_connected();
    void update_battery(uint8_t bat_percentage);
    void start_advertising();
    void send_report_bluetooth(report_keyboard_t *report);
#endif
