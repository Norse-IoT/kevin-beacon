#include "NimBLEDevice.h"

void setup() {
  NimBLEDevice::init("NimBLE");

  NimBLEServer *pServer = NimBLEDevice::createServer();
  NimBLEService *pService = pServer->createService("ABCD");
  NimBLECharacteristic *pCharacteristic = pService->createCharacteristic("1234");

  pService->start();
  pCharacteristic->setValue("Hello BLE");

  NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->addServiceUUID("ABCD");
  pAdvertising->start();
}


void loop() {
}