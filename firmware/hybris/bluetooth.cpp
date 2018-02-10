#include <Arduino.h>
#include <bluefruit.h>

#include "config.h"
#include "bluetooth.h"
#include "keycode.h"

BLEHidAdafruit blehid;
BLEBas blebas;
BLEDis bledis;

void send_report_bluetooth(report_keyboard_t *report) {
  blehid.keyboardReport(report->mods, report->keys[0], report->keys[1], report->keys[2], report->keys[3], report->keys[4], report->keys[5]);
}

void update_battery(uint8_t bat_percentage) {
  blebas.write(bat_percentage);
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
