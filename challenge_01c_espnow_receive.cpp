/*
Challenge 01c: ESP-NOW - Nachricht empfangen
===========================================
Ziel:
Empfange ESP-NOW Daten und gib Absender-MAC sowie Nutzdaten im Seriellen
Monitor aus.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// TODO: Callback-Funktion schreiben, die bei empfangenen Daten aufgerufen wird.
// Signatur: void onDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len)
// - Absender-MAC aus info->src_addr ausgeben
// - Nutzdaten als Text ausgeben

void setup() {
  // TODO: Serielle Schnittstelle starten

  // TODO: WLAN-Modus auf Station setzen

  // TODO: Eigene MAC-Adresse ausgeben

  // TODO: ESP-NOW initialisieren (esp_now_init)

  // TODO: Empfangs-Callback registrieren (esp_now_register_recv_cb)
}

void loop() {
  delay(1000);
}
