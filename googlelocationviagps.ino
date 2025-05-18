#include <WiFi.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <ESP_Mail_Client.h>

// WiFi details
const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

// Gmail SMTP
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

#define SENDER_EMAIL "your_email@gmail.com"
#define SENDER_PASS "your_app_password"
#define TO_EMAIL "recipient@example.com"

TinyGPSPlus gps;
HardwareSerial gpsSerial(1);

// Email stuff
SMTPSession smtp;
SMTP_Message msg;
ESP_Mail_Session emailSession;

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, 13, -1); // RX pin = 13
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  // Email setup
  emailSession.server.host_name = SMTP_HOST;
  emailSession.server.port = SMTP_PORT;
  emailSession.login.email = SENDER_EMAIL;
  emailSession.login.password = SENDER_PASS;

  msg.sender.name = "ESP32 GPS";
  msg.sender.email = SENDER_EMAIL;
  msg.subject = "Location Alert";
  msg.addRecipient("User", TO_EMAIL);
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());

    if (gps.location.isUpdated()) {
      float lat = gps.location.lat();
      float lng = gps.location.lng();

      String link = "https://www.google.com/maps?q=" + String(lat, 6) + "," + String(lng, 6);
      Serial.println("Sending: " + link);

      msg.text.content = "Location:\n" + link;

      smtp.debug(1);
      if (!smtp.connect(&emailSession)) {
        Serial.println("SMTP connection failed");
        return;
      }

      if (!MailClient.sendMail(&smtp, &msg)) {
        Serial.println("Error: " + smtp.errorReason());
      } else {
        Serial.println("Email sent!");
      }

      smtp.closeSession(); // important!

      delay(60000); // 1 min wait
    }
  }
}
