#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_HELP"); // Name of the Bluetooth device
  Serial.println("Bluetooth is on. Waiting for a connection...");

  // Wait for a device to connect
  while (!SerialBT.hasClient()) {
    delay(100);
  }

  Serial.println("Device connected! Sending help message...");

  // Send help message
  SerialBT.println("🚨 HELP! I need help right now!");
  SerialBT.println("📍 Location: ");
  SerialBT.println("📞 Contact: "+91 7207179471");
}

void loop() {
  //more to go //
}