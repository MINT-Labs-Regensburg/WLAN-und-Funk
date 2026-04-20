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

// Callback wird bei empfangenen ESP-NOW Daten aufgerufen.
void onDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len) {
  Serial.print("From: ");

  // TODO: Absender-MAC ausgeben.
  for (int i = 0; i < 6; i++) {
    Serial.printf("%02X", info->src_addr[i]);
    if (i < 5)
      Serial.print(":");
  }

  Serial.print(" | Data: ");

  // TODO: Nutzdaten als Text ausgeben.
  for (int i = 0; i < len; i++) {
    if (data[i] == '\0')
      break;
    Serial.print((char)data[i]);
  }

  Serial.println();
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  Serial.print("My MAC: ");
  Serial.println(WiFi.macAddress());

  // TODO: ESP-NOW initialisieren.
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW fail");
    while (true)
      delay(1000);
  }

  // TODO: Empfangs-Callback registrieren.
  esp_now_register_recv_cb(onDataRecv);
  Serial.println("Receive ready");
}

void loop() {
  delay(1000);
}
