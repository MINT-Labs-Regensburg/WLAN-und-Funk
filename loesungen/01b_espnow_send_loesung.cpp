#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>


// Ersetze diese MAC-Adresse durch die tatsächliche MAC-Adresse deines Empfängers
// Beispiel-MAC-Adresse des Empfängers: A4 F0 0F 77 7E C0 
uint8_t receiverMac[] = {0xA4, 0xF0, 0x0F, 0x77, 0x7E, 0xC0};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW fail");
    while (true) delay(1000);
  }

  // Erstelle eine Peer-Info-Struktur zur Registrierung des Empfängers
  // peerInfo enthält Informationen über den Empfänger (wie die MAC-Adresse)
  esp_now_peer_info_t peerInfo = {};
  // Kopiere die MAC-Adresse des Empfängers in die Peer-Info-Struktur
  // Dies teilt ESP-NOW mit, wohin die Nachrichten gesendet werden sollen
  memcpy(peerInfo.peer_addr, receiverMac, 6);

  // Registriere den Empfänger als Peer-Gerät in ESP-NOW
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Peer fail");
    while (true) delay(1000);
  }

  Serial.println("ESP-NOW ready");
}

void loop() {
  const char* msg = "hello";
  esp_now_send(receiverMac, (const uint8_t*)msg, strlen(msg) + 1);

  delay(1000);
}
