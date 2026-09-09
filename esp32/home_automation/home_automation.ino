#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "GBPIET_WiFi";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "ESP32 Home Automation is working!");
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi connected!");

  Serial.print("ESP32 IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  server.handleClient();
}