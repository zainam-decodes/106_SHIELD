#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

SoftwareSerial gpsSerial(4, 3);
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("Waiting for GPS...");
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
    if (gps.location.isUpdated()) {
      Serial.println(" Hippiee GPS got signal!");
      Serial.print("Lat: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Long: ");
      Serial.println(gps.location.lng(), 6);
      Serial.println("-----");
    }
  }
}