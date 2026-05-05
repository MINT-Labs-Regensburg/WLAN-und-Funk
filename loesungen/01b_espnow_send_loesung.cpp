#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// Diese MAC-Adresse muss zur MAC deines Empfängers passen.
uint8_t empfaengerMac[] = {0x24, 0xDC, 0xC3, 0xC1, 0xDA, 0x94};

void stopMitFehler(const char *text)
{
  Serial.println(text);
  while (true)
    delay(1000);
}

void setup()
{
  Serial.begin(115200);
  // ESP-NOW braucht den Station-Modus.
  WiFi.mode(WIFI_STA);

  // Eigene MAC anzeigen (praktisch zum Kopieren).
  Serial.print("Sender MAC: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK)
    stopMitFehler("Fehler: ESP-NOW konnte nicht gestartet werden.");

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, empfaengerMac, 6);

  if (esp_now_add_peer(&peerInfo) != ESP_OK)
    stopMitFehler("Fehler: Empfaenger konnte nicht hinzugefuegt werden.");

  Serial.println("ESP-NOW ready");
}

void loop()
{
  esp_now_send(empfaengerMac, (const uint8_t *)"hello von Peter", sizeof("hello von Peter"));
  Serial.println("hello von Peter gesendet");

  delay(1000);
}
