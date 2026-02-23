#include <ArduinoBLE.h>
#include <R200.h>

BLEService rfidService("180C");
BLECharacteristic rfidCharacteristic("2A56", BLERead | BLENotify, 50);

R200 rfid;
const uint8_t UID_VACIO[12] = {0};

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial2.begin(115200, SERIAL_8N1, 9, 10);
  rfid.begin(&Serial2, 115200, 7, 6);
  delay(100);
  rfid.dumpModuleInfo();

  if (!BLE.begin()) {
    Serial.println("Error al iniciar BLE!");
    while (1);
  }

  BLE.setLocalName("NanoESP32_RFID");
  BLE.setAdvertisedService(rfidService);
  rfidService.addCharacteristic(rfidCharacteristic);
  BLE.addService(rfidService);
  rfidCharacteristic.writeValue("Esperando tag RFID");
  BLE.advertise();

  Serial.println("Bluetooth BLE iniciado, esperando conexión...");
}

void loop() {
  BLE.poll();
  BLEDevice central = BLE.central();
  if (!central) return;

  Serial.print("Conectado a: ");
  Serial.println(central.address());

  while (central.connected()) {
    static unsigned long ultimaLectura = 0;

    if (millis() - ultimaLectura >= 30) { // cada 30 ms = ~33 lecturas/s
      rfid.poll();
      delay(2);  // Espera corta para asegurar recepción completa
      rfid.loop();  // procesa inmediatamente tras el poll

      if (memcmp(rfid.uid, UID_VACIO, 12) != 0) {  // etiqueta válida
        String ID = "ID:";
        for (uint8_t i = 0; i < 12; i++) {
          if (rfid.uid[i] < 0x10) ID += "0";
          ID += String(rfid.uid[i], HEX);
        }
        ID.toUpperCase();

        int rssi = rfid.getRSSI();
        String potencia = " Potencia:" + String(rssi) + "dBm";

        Serial.println(ID + potencia);
        rfidCharacteristic.writeValue((ID + potencia).c_str());
      }
      ultimaLectura = millis();
    }
    delay(1); // necesario para estabilidad mínima
  }

  Serial.println("Desconectado.");
}
