/*
Challenge 02a : ESP32 mit WLAN verbinden
========================================
Ziel:
Schreibe ein Programm, das den ESP32 im WLAN anmeldet.

Tipp:
Alle Programmschritte erfolgen in setup() beim Programmstart.

Schritt 1: ESP32 am WLAN Router anmelden
----------------------------------------

- Du brauchst die Zugangsdaten für das WLAN. 
  - ssid="???" password="????"
- #include <WiFi.h>
- Serial.begin(115200); Braucht es für spätere Serial.print() Befehle
- WiFi.begin(ssid, password); Starten Verbindungsaufbau mit deinen Zugansdaten
- while (WiFi.status() =! WL_CONNECTED) In einer Schleife warten, bis die
  Verbindung hergestellt ist
- Serial.print(WiFi.localIP()); Ausgeben der vom WLAN Router zugewiesenen IP Adresse.


TESTEN
Öffne den 'Seriellen Monitor' um die IP Adresse deines ESP32 zu sehen
---------------------------------------------------------------------
- Dazu in der Arduino IDE Statusleiste Tools|Serial Monitor auswählen
- Reset Taster am ESP32 drücken. Im Seriellen Monitor siehst du die <IP Adresse> deines ESP32.

Test im 'Terminal' des Laptops, ob der ESP32 im WLAN zu sehen ist und auf das ping command antwortet
----------------------------------------------------------------------------------------------------
- Öffne das Terminal deines Laptops. Unter Windows: Windows-Taste + R, dann "cmd" eingeben und Enter drücken. Unter MacOS: Spotlight Suche (Cmd + Space) öffnen, "Terminal" eingeben und Enter drücken.
- 'ping <IP Adresse>' eingeben
*/

// Jetzt gehts los. Happy coding!
#include <WiFi.h>

#include "../wlan_credentials.h" // Laden deiner WLAN Zugangsdaten

void setup() {
  // TODO: Serielle Schnittstelle starten

  // TODO: WLAN-Modus auf Station setzen (WiFi.mode)

  // TODO: Verbindung starten (WiFi.begin mit WIFI_SSID und WIFI_PASS)

  // TODO: Warten bis verbunden (while WiFi.status() != WL_CONNECTED)

  // TODO: IP-Adresse im Seriellen Monitor ausgeben (WiFi.localIP())
}

void loop() {}
