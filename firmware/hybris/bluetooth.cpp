#include <Arduino.h>
#include <bluefruit.h>

#include "config.h"
#include "bluetooth.h"
#include "keycode.h"
#include "host_driver.h"
#include "host.h"
#include "keypress.h"

BLEHidAdafruit blehid;
BLEBas blebas;
BLEDis bledis;

static uint8_t keyboard_leds(void);
static void send_keyboard(report_keyboard_t *report);
static void send_mouse(report_mouse_t *report);
static void send_system(uint16_t data);
static void send_consumer(uint16_t data);

static host_driver_t driver = {
        keyboard_leds,
        send_keyboard,
        send_mouse,
        send_system,
        send_consumer
};

host_driver_t *nrf52_driver(void)
{
    return &driver;
}

static uint8_t keyboard_leds(void) {
    return 0;
}

static void send_keyboard(report_keyboard_t *report)
{
    Serial.print("HOST: ");
    Serial.print(report->mods);
    Serial.print(" ");
    Serial.print(report->keys[0]);
    Serial.print("");
    uint32_t sum = report->mods;
    for (uint8_t i = 0; i < 6; i++) {
        sum |= report->keys[i];
    }
    Serial.print(sum);
    Serial.print("\r\n");

    if(sum == 0) {
        set_key_pressed(false);
    }

    blehid.keyboardReport(report->mods, report->keys[0], report->keys[1], report->keys[2], report->keys[3], report->keys[4], report->keys[5]);
}

static void send_mouse(report_mouse_t *report)
{
#ifdef MOUSE_ENABLE
    usb_mouse_send(report->x, report->y, report->v, report->h, report->buttons);
#endif
}

static void send_system(uint16_t data)
{
#ifdef EXTRAKEY_ENABLE
    usb_extra_system_send(data);
#endif
}

static void send_consumer(uint16_t data)
{
#ifdef EXTRAKEY_ENABLE
    usb_extra_consumer_send(data);
#endif
}

void update_battery(uint8_t bat_percentage) {
  blebas.write(bat_percentage);
}

void send_encoder_report(uint16_t usage_code) {
  blehid.consumerKeyPress(usage_code);
  blehid.consumerKeyRelease();
}

bool is_bluetooth_connected() {
  return Bluefruit.connected();
}

void init_bluetooth() {
  Bluefruit.begin();
  Bluefruit.setName(ADVERTISE_NAME);
  Bluefruit.setTxPower(4);
  Bluefruit.autoConnLed(false);

  bledis.setManufacturer(MANUFACTURER_NAME);
  bledis.setModel(MODEL_NAME);
  bledis.begin();

  BLECharacteristic pnp_id = BLECharacteristic(UUID16_CHR_PNP_ID);
  pnp_id.setProperties(CHR_PROPS_READ);
  pnp_id.setFixedLen(7);
  pnp_id.begin();
  uint8_t pnp_id_data[7] = {0x02, 0x11, 0x23, 0xfe, 0xca, 0x01, 0x00};
  pnp_id.write(pnp_id_data, 7);

  blebas.begin();
  blebas.write(100);

  blehid.begin();

  host_set_driver(nrf52_driver());
}

void start_advertising() {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  Bluefruit.Advertising.addService(blehid);
  Bluefruit.Advertising.addService(blebas);

  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode

  Bluefruit.Advertising.addName();

  Bluefruit.ScanResponse.addName();

  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}
