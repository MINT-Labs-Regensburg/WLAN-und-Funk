#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>



void onDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len)
{
    Serial.print("From: ");

    // sender MAC address
    for (int i = 0; i < 6; i++)
    {
        Serial.printf("%02X", info->src_addr[i]);
        if (i < 5) Serial.print(":");
    }

    Serial.print(" | Data: ");

    for (int i = 0; i < len; i++)
    {
        if (data[i] == '\0') break;
        Serial.print((char)data[i]);
    }

    Serial.println();
}

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    Serial.print("My MAC: ");
    Serial.println(WiFi.macAddress());

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW fail");
        while (true)
            delay(1000);
    }

    esp_now_register_recv_cb(onDataRecv);
    Serial.println("Receive ready");
}

void loop()
{
    delay(1000);
}
