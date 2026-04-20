#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// Change this to receiver MAC address.


// A4 F0 0F 77 7E C0 
uint8_t receiverMac[] = {0xA4, 0xF0, 0x0F, 0x77, 0x7E, 0xC0};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW fail");
    while (true) delay(1000);
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMac, 6);

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
