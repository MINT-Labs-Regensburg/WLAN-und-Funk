/*
Challenge 05: RGB-LED per Webserver steuern
===========================================
Ziel: Die Farbe einer RGB-LED kann live über den Browser eingestellt werden.
*/


#include <ESPmDNS.h>
#include <WebServer.h>
#include <WiFi.h>
const char *ssid = "FRITZ!Box 75902";
const char *password = "04562358016988474025";

const char *espname = "ESP-meiner";  // Mein ESP32 Name


#define PIN_R 13
#define PIN_G 12
#define PIN_B 14

WebServer server(80);

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B, b);
}



// Separater Handler für die Root-Seite
void antwortRoot() {
  String html = "<h1>RGB-LED Steuerung</h1>";

  html += "<form action='/set_rgb' method='get'>";
  html +=
    "Rot: <input type='range' min='0' max='255' name='r' value='0'><br>";
  html +=
    "Gruen: <input type='range' min='0' max='255' name='g' value='0'><br>";
  html +=
    "Blau: <input type='range' min='0' max='255' name='b' value='0'><br>";
    
  html += "<input type='submit' value='Farbe setzen'>";
  html += "</form>";
  server.send(200, "text/html", html);
}

// Neue separate Handler-Funktion
void handleSetRgb() {
  int r = server.hasArg("r") ? server.arg("r").toInt() : 0;
  int g = server.hasArg("g") ? server.arg("g").toInt() : 0;
  int b = server.hasArg("b") ? server.arg("b").toInt() : 0;
  setColor(r, g, b);
  String html = "<p>Farbe gesetzt: R=" + String(r) + ", G=" + String(g) + ", B=" + String(b) + "</p>";
  html += "<a href='/'>Zurueck</a>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  setColor(0, 0, 0);  // LED aus

  WiFi.mode(WIFI_STA);
  WiFi.setHostname(espname);
  WiFi.begin(ssid, password);  // Anmeldung im WLAN starten
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());
  MDNS.begin(espname);
  Serial.println(espname);

  // Verwende die neue Funktion als Handler für die Root-Route
  server.on("/", antwortRoot);

  // Verwende die neue Funktion als Handler
  server.on("/set_rgb/", handleSetRgb);

  server.begin();
  Serial.print("http://");
  Serial.println(espname);
}

void loop() {
  server.handleClient();
}
