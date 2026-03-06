/*
Challenge 02: ESP32 Webserver einrichten
========================================
Ziel:
Einen einfachen Webserver auf dem ESP32 starten und für den Browser am Laptop
oder am Handy erreichbar machen.

Grafik: So läuft der Webserver im Code
--------------------------------------
Arduino main()
    |
    +--> setup()                          (einmal beim Start)
    |      |
    |      +--> WebServer server(80);     // Webserver initialisieren
    |      +--> server.on("/", ...);      // Route/Endpoint bereitstellen
    |      +--> server.begin();            // Webserver starten
    |
    +--> loop()                           (dauerhaft wiederholt)
                 |
                 +--> server.handleClient();    // Client-Anfragen verarbeiten

Schritte:
1. Kopiere als Basis deinen code aus challenge_01b. Damit ist dein ESP mit dem
WLAN als ESP-meinname verbunden

Erweitere dann den Code
2. WebServer laden und ein Objekt 'server' der Klasse WebServer anlegen
   - include <WebServer.h>
   - WebServer server(80);


3. Einfache Webseite in server.on() zum Senden bereitstellen.
  server.on() wird bei Bedarf von server.handleClient() aufgerufen. 
  Am Ende von setup() hinzufügen:
  server.on("/", []()
            { server.send(200, "text/html", "<h1>ESP32 Webserver aktiv!</h1>"); });


4. Starte den webserver in setup().
    server.begin();

5. In der main loop() prüfen ob eine Anfrage vom Client kommt
    server.handleClient()


Test: Im Browser http://<esp32-ip>/ aufrufen und die Seite sehen.
 -----------------------------------------------------------------
 */
