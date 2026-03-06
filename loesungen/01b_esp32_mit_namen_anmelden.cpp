#include <WiFi.h>

#include <ESPmDNS.h> // Für mDNS

const char *ssid = "FRITZ!Box 75902";
const char *password = "04562358016988474025";

const char *espname = "ESP-meiner"; // Mein ESP32 Name

void setup()
{
    Serial.begin(115200);
    Serial.println("+++ START +++");

    WiFi.setHostname(espname); // Name, unter dem dein ESP32 im WLAN angemeldet wird

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("Mit WiFi verbunden");
    Serial.print("IP= ");
    Serial.println(WiFi.localIP());

    // mDNS starten
    if (MDNS.begin(espname))
    { // Name im Netzwerk festlegen
        Serial.print("Du kannst den ESP32 erreichen mit:  ping ");
        Serial.print(espname);
        Serial.println(".local");
    }
    else
    {
        Serial.println("FEHLER: mDNS konnte nicht gestartet werden");
    }
}

void loop()
{
}
