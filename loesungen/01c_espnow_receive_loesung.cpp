#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// Callback-Funktion, die automatisch aufgerufen wird, wenn eine ESP-NOW-Nachricht empfangen wird
// Sie erhält Informationen über den Sender (info) und die empfangenen Daten (data)
void onDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len)
{
    // Gib "From: " aus, gefolgt von der MAC-Adresse des Senders
    Serial.print("From: ");

    // MAC address des Senders ausgeben
    for (int i = 0; i < 6; i++)
    {
        Serial.printf("%02X", info->src_addr[i]);
        if (i < 5)
            Serial.print(":");
    }

    // Daten vom Sender ausgeben
    Serial.print(" | Data: ");
    // Schleife durch alle empfangenen Bytes vom Sender
    for (int i = 0; i < len; i++)
    {
        // Breche ab, wenn ein Null-Terminator (Ende-Zeichen) gefunden wird
        if (data[i] == '\0')
            break;
        // Gib das Byte als Zeichen aus
        Serial.print((char)data[i]);
    }

    Serial.println();
}

// Initialisierung des ESP32
void setup()
{
    Serial.begin(115200);
    // Setze den WiFi-Modus auf Station (Empfänger-Modus)
    WiFi.mode(WIFI_STA);
    // Starte den WiFi in Station-Modus
    WiFi.STA.begin();
    // Zur Information: Die MAC-Adresse des ESP32 wird hier ausgegeben, damit du sie für den Sender verwenden kannst
    Serial.print("My MAC: ");
    Serial.println(WiFi.macAddress());

    // Initialiere ESP-NOW
    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW fail");
        while (true)
            delay(1000);
    }

    // Registriere die Callback-Funktion, die aufgerufen wird, wenn Daten empfangen werden
    // onDataRecv wird automatisch aufgerufen, wenn eine ESP-NOW-Nachricht ankommt
    esp_now_register_recv_cb(onDataRecv);

    // Bestätige, dass der Empfänger bereit ist
    Serial.println("Receive ready");
}

void loop()
{
    delay(1000);
}
