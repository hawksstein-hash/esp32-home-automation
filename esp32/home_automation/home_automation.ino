#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "GBPIET_WiFi";

WebServer server(80);

const int LIGHT1_PIN = 2;
const int RELAY_PIN = 23;


// Add CORS permission to every response
void addCORS() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
}


// Home page
void handleRoot() {
  addCORS();
  server.send(200, "text/plain", "ESP32 Home Automation is working!");
}


// Light 1 ON
void handleLight1On() {
  digitalWrite(LIGHT1_PIN, HIGH);

  addCORS();
  server.send(200, "text/plain", "Light 1 is ON");
}


// Light 1 OFF
void handleLight1Off() {
  digitalWrite(LIGHT1_PIN, LOW);

  addCORS();
  server.send(200, "text/plain", "Light 1 is OFF");
}


// Relay ON
void handleRelayOn() {
  digitalWrite(RELAY_PIN, LOW);

  addCORS();
  server.send(200, "text/plain", "Relay is ON");
}


// Relay OFF
void handleRelayOff() {
  digitalWrite(RELAY_PIN, HIGH);

  addCORS();
  server.send(200, "text/plain", "Relay is OFF");
}


// Handle browser preflight request
void handleOptions() {
  addCORS();
  server.send(204);
}


void setup() {

  Serial.begin(115200);

  pinMode(LIGHT1_PIN, OUTPUT);
  digitalWrite(LIGHT1_PIN, LOW);

  pinMode(RELAY_PIN, OUTPUT);

  // Relay OFF initially
  digitalWrite(RELAY_PIN, HIGH);


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


  // Routes
  server.on("/", HTTP_GET, handleRoot);

  server.on("/light1/on", HTTP_GET, handleLight1On);
  server.on("/light1/off", HTTP_GET, handleLight1Off);

  server.on("/relay/on", HTTP_GET, handleRelayOn);
  server.on("/relay/off", HTTP_GET, handleRelayOff);

  server.on("/light1/on", HTTP_OPTIONS, handleOptions);
  server.on("/light1/off", HTTP_OPTIONS, handleOptions);

  server.on("/relay/on", HTTP_OPTIONS, handleOptions);
  server.on("/relay/off", HTTP_OPTIONS, handleOptions);


  server.begin();

  Serial.println("Web server started!");
}


void loop() {
  server.handleClient();
}