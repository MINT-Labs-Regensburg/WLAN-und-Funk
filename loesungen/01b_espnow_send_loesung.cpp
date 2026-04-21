#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// Ersetze diese MAC-Adresse durch die tatsächliche MAC-Adresse deines Empfängers
// Beispiel-MAC-Adresse des Empfängers: 24:DC:C3:C1:DA:94
uint8_t receiverMac[] = {0x24, 0xDC, 0xC3, 0xC1, 0xDA, 0x94};

void setup()
{
  Serial.begin(115200);
  // Setze den WiFi-Modus auf Station (Empfänger-Modus)
  WiFi.mode(WIFI_STA);
  // Starte den WiFi in Station-Modus
  WiFi.STA.begin();
  // Zur Information: Die MAC-Adresse des ESP32 wird hier ausgegeben, damit du sie für den Sender verwenden kannst
  Serial.print("Sender MAC: ");
  Serial.println(WiFi.macAddress());
  
  
  if (esp_now_init() != ESP_OK)
  {
    Serial.println("ESP-NOW fail");
    while (true)
      delay(1000);
  }

  // Erstelle eine Peer-Info-Struktur zur Registrierung des Empfängers
  // peerInfo enthält Informationen über den Empfänger (wie die MAC-Adresse)
  esp_now_peer_info_t peerInfo = {};
  // Kopiere die MAC-Adresse des Empfängers in die Peer-Info-Struktur
  // Dies teilt ESP-NOW mit, wohin die Nachrichten gesendet werden sollen
  memcpy(peerInfo.peer_addr, receiverMac, 6);

  // Registriere den Empfänger als Peer-Gerät in ESP-NOW
  if (esp_now_add_peer(&peerInfo) != ESP_OK)
  {
    Serial.println("Peer fail");
    while (true)
      delay(1000);
  }

  Serial.println("ESP-NOW ready");
}

void loop()
{
  const char *msg = "hello";
  esp_now_send(receiverMac, (const uint8_t *)msg, strlen(msg) + 1);

  delay(1000);
}
