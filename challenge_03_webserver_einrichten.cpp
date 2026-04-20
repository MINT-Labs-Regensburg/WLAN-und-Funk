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

3a. Einfache Webseite in antwortRoot() bereitstellen. Wird von server.on("/") aufgerufen.
  antwortRoot() sendet die message  "ESP32 Webserver von DEINNAME aktiv!" zurück.
  Als HTML Antwort: 
  server.send(200, "text/html", "<h1>ESP32 Webserver von DEINNAME aktiv!</h1>");


3b. server.on interpretiert die Anfrage und ruft je nach URL den passenden handler auf.
  z.B. bei  "http://esp-meinname/" für die root, also nur ein "/" am Ende der URL, die Funktion antwortRoot
    server.on("/", antwortRoot);
  

4. Starte den webserver in setup().
    server.begin();

5. In der main loop() regelmässig prüfen, ob eine Anfrage vom Browser kommt. 
   Falls ja, server.on aufrufen.
    server.handleClient()

-----------------------------------------------------------------
Test: Im Browser "http://esp-meinname/" aufrufen und die Seite "ESP32 Webserver von DEINNAME aktiv!" sehen.
-----------------------------------------------------------------
 */
