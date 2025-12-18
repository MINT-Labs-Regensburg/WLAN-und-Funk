/*
Challenge 01 : ESP32 mit WLAN verbinden
======================================
Ziel:
Schreibe ein Programm, das den ESP32 im WLAN anmeldet.
Der ESP32 soll im WLAN unter seinem Hostnamen z.B "esp32_leonie" erreichbar
sein.

Tipp:
Alle Programmschritte erfolgen in setup() beim Programmstart.

Schritt 1: ESP32 am WLAN Router anmelden
----------------------------------------

- Definiere in der Datei wlan_credentials.h  MYHOST, WLAN_SSID und WLAN_PASS
- Lade die WLAN Definitionen mit #include "../wlan_credentials.h"
- #include <WiFi.h>
- #include <ESPmDNS.h> Wird für die Namensvergabe MDNS gebraucht
- #include "../wlan_credentials.h" um die WLAN Zugansdaten zu laden
- Serial.begin(115200); Brauchts für spätere Serial.print() Befehle
- WiFi.mode(WIFI_STA); Modus definieren. ESP32 anmelden in bestehendem WLAN als
STATION
- WiFi.setHostname(MYHOST); Der ESP32 bekommt den Hostnamen den du in MYHOST
definiert hast
- WiFi.begin(WIFI_SSID, WIFI_PASS); Starten Verbindungsaufbau mit deinen
Zugansdaten
- if (WiFi.status() =! WL_CONNECTED) In einer Schleife warten, bis die
Verbindung hergestellt ist
- MDNS.begin(MYHOST); Damit machst du MYHOST im WLAN bekannt

- Serial.print(WiFi.localIP()); Ausgeben der vom WLAN Router zugewiesenen IP
Adresse.


TESTEN
Öffne den 'Seriellen Monitor'
----------------------------------------
- In der PlatformIO Statusleiste (unten) den Seriellen Monitor öffnen
- print Ausgaben monitoren.

Test im 'Terminal', ob der ESP32 als 'esp32_meiner' oder über seine
IP Adresse auf das ping command antwortet
---------------------------------------------------------------------------------------
- Öffne in PlatformIO in der Statusleiste New Terminal.
- 'ping esp_deinname' eingeben
- 'ping IP' eingeben
*/

// Jetzt gehts los. Happy coding!
#include <ESPmDNS.h>
#include <WiFi.h>

#include "../wlan_credentials.h" // Laden deiner WLAN Zugangsdaten

void setup() {

  Serial.begin(115200);
  Serial.println();

  // Schritt 1 : ESP32 als Station am WLAN Router anmelden
  WiFi.mode(WIFI_STA); // Modus: ESP32 als STATION im WLAN Router

  WiFi.setHostname(
      MYHOST); // Name, unter dem dein ESP32 im WLAN angemeldet wird

  WiFi.begin(WIFI_SSID, WIFI_PASS); // Anmeldung im WLAN starten
  Serial.print("Start connecting ESP32 to WLAN");

  // Warten bis der ESP32 angemeldet ist
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(WiFi.localIP()); // Zeige IP Adresse, die dem ESP32 vom Router
                                  // zugewiesen wurde

  // Schritt 2: Namen deines ESP32 im WLAN
  MDNS.begin(MYHOST);
  Serial.println(MYHOST);

  // Schritt 3: Test ob der ESP32 unter deinem ESP32 Namen und auch über seine
  // IP Adresse auf das ping command antwortet
  Serial.println("Testen im Terminal:");
  Serial.print("ping ");
  Serial.println(MYHOST);
  Serial.print("ping ");
  Serial.println(WiFi.localIP());
}

void loop() {}
