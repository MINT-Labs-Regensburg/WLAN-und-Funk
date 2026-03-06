/*
Challenge 01b : ESP32 mit mDNS Namen anmelden
=============================================
Ziel:
Erweitere das Programm so, dass der ESP32 im WLAN angemeldet wird und ihm ein mDNS Name zugewiesen wird.


Erweitere das Programm aus Challenge 01a mit folgenden Schritten:
----------------------------------------------------------------

- #include <ESPmDNS.h> 
- Lege den Namen für deinen ESP32 im Netz fest. Mit 'const char *espname = "ESP-meiner"'
- Vor WiFi.begin():
- WiFi.setHostname(espname); // Name, unter dem dein ESP32 im WLAN angemeldet wird
- Nachdem der ESP32 im WLAN angemeldet ist, starte mDNS mit 
- MDNS.begin(espname); // Name im Netzwerk festlegen


Test ob der ESP32 auch unter deinem ESP32 Namen auf das ping command antwortet
------------------------------------------------------------------------------
- In der commandline 'ping <ESP32 Name>.local' eingeben
*/
