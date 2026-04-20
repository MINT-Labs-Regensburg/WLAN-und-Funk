#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// Change this to receiver MAC address.


// 24:DC:C3:C1:DA:94
uint8_t receiverMac[] = {0x24, 0xDC, 0xC3, 0xC1, 0xDA, 0x94};

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
