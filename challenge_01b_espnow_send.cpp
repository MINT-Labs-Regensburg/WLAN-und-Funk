/*
Challenge 01b: ESP-NOW - Nachricht senden
=========================================
Ziel:
Sende mit einem ESP32 regelmaessig eine kurze Nachricht per ESP-NOW an einen
anderen ESP32.

Voraussetzung:
Du kennst die MAC-Adresse des Empfaenger-ESP32 (aus Challenge 01).
*/

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// TODO: Trage hier die MAC-Adresse deines Empfaenger-ESP32 ein.
uint8_t receiverMac[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void setup() {
  // TODO: Serielle Schnittstelle starten

  // TODO: WLAN-Modus auf Station setzen

  // TODO: ESP-NOW initialisieren (esp_now_init)

  // TODO: Empfaenger als Peer hinzufuegen (esp_now_add_peer)

}

void loop() {
  // TODO: Nachricht per esp_now_send senden

  delay(1000);
}
