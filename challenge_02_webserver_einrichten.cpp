/*
Challenge 02: ESP32 Webserver einrichten
========================================
Ziel:
Einen einfachen Webserver auf dem ESP32 starten und für den Browser am Laptop
oder am Handy erreichbar machen.



Schritte:
1. Vorbereitung: Kopiere als Basis deinen code aus challenge_01b. Damit ist dein ESP im
WLAN als ESP-meinname erreichbar

Erweitere dann den Code
2. include WebServer und ein Objekt 'server' der Klasse WebServer anlegen
   - include <WebServer.h>
   - WebServer server(80);

3a. Einfache Webseite in handleRoot() bereitstellen. Wird von server.on("/") aufgerufen.
  handleRoot() sendet die message  "ESP32 Webserver aktiv!" zurück.

3b. server.on interpretiert die Anfrage und ruft je nach URL den passenden handler auf.
  z.B. bei  "http://esp-meinname/" für die root, also nur ein "/" am Ende der URL, die Funktion handleRoot
    server.on("/", handleRoot);
  

4. Starte den webserver in setup().
    server.begin();

5. In der main loop() regelmässig prüfen, ob eine Anfrage vom Browser kommt. 
   Falls ja, server.on aufrufen.
    server.handleClient()

-----------------------------------------------------------------
Test: Im Browser "http://esp-meinname/" aufrufen und die Seite "ESP32 Webserver aktiv!" sehen.
-----------------------------------------------------------------
 */
