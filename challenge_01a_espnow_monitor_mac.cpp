/*
Challenge 01a: ESP-NOW - Eigene MAC-Adresse anzeigen
====================================================
Ziel:
Zeige die MAC-Adresse deines ESP32 im Seriellen Monitor an.

Schritte:
1. Serielle Schnittstelle starten
2. WLAN-Modus auf Station setzen
3. MAC-Adresse ausgeben
*/

#include <Arduino.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  // TODO: Setze den ESP32 in den WLAN-Station-Modus.
  WiFi.mode(WIFI_STA);

  // TODO: Gib die eigene MAC-Adresse im Seriellen Monitor aus.
  Serial.print("My MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  delay(1000);
}
