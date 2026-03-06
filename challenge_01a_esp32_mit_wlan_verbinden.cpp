/*
Challenge 01a : ESP32 mit WLAN verbinden
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
- if (WiFi.status() =! WL_CONNECTED) In einer Schleife warten, bis die
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
