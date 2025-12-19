/*
Challenge 04: LED per Webserver schalten
========================================
Ziel: Der ESP32 empfängt Kommandos vom Client (z.B. Laptop/Smartphone) und
schaltet eine LED ein oder aus.

Schritte:
1. Kopiere als Basis deinen Code aus challenge_02_webserver_einrichten.cpp.
2. Definiere den Pin, an dem die LED angeschlossen ist (z.B. GPIO 2).
   Siehe Schaltplan/Breadboard zusatzmaterial\ESP32_LED_XXX
3. Setze den Pin im setup() als OUTPUT.
4. Erzeuge zwei neue Endpoints:
   - /led_ein  → schaltet die LED an
   - /led_aus  → schaltet die LED aus
5. Im Handler für /led_ein: digitalWrite(LED_PIN, HIGH)
6. Im Handler für /led_aus: digitalWrite(LED_PIN, LOW)
7. Sende jeweils eine Bestätigung an den Client (z.B. "LED ist an" oder "LED ist
aus").

Teste die Endpoints im Browser:
- http://<esp32_name>/led_ein
- http://<esp32_name>/led_aus
*/

#include "../wlan_credentials.h"
#include <ESPmDNS.h>
#include <WebServer.h>
#include <WiFi.h>

#define LED_PIN 12
WebServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // LED aus

  WiFi.mode(WIFI_STA);
  WiFi.setHostname(MYHOST);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());

  MDNS.begin(MYHOST);
  Serial.println(MYHOST);

  server.on("/", []() {
    String html = "<h1>ESP32 LED Steuerung</h1>";
    html += "<p>mit 'http://<esp32_name>/led_ein' die LED einschalten</p>";
    html += "<p>mit 'http://<esp32_name>/led_aus' die LED ausschalten</p>";
    server.send(200, "text/html", html);
  });

  server.on("/led_ein", []() {
    digitalWrite(LED_PIN, HIGH);
    server.send(200, "text/html",
                "<p>mit 'http://<esp32_name>/led_aus' die LED ausschalten</p>");
  });

  server.on("/led_aus", []() {
    digitalWrite(LED_PIN, LOW);
    server.send(200, "text/html",
                "mit 'http://<esp32_name>/led_ein' die LED einschalten");
  });

  server.begin();
  Serial.print("http://");
  Serial.println(MYHOST);
}

void loop() { server.handleClient(); }
