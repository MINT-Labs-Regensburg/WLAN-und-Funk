/*
Challenge 02: ESP32 Webserver einrichten
========================================
Ziel:
Einen einfachen Webserver auf dem ESP32 starten und für den Browser am Laptop
erreichbar machen.

Schritte:
1. Kopiere als Basis deinen code aus challenge_01. Damit ist dein ESP mit dem
WLAN verbunden

Erweitere dann den Code
2. Webserver laden und ein Objekt 'server' der Klasse WebServer anlegen
   - include <WebServer.h>
   - WebServer server(80);
     Hinweis: server(80) global definieren, also oberhalb von setup()

3. Einfache Webseite in server.on() zum Senden bereitstellen
server.on() wird bei Bedarf von server.handleClient() aufgerufen.

   server.on("/", []() {
       server.send(
           200, "text/html",
          "<h1>ESP32 Webserver aktiv!</h1>");
       });

4. Starte den webserver.
    server.begin();

5. Prüfen, ob Client anfrage gesendet hat.
In der main loop() regelmässig prüfen ob eine Anfrage vom Client kommt

'server.handleClient()'. server.handleClient() liest die
Anfragen vom Client und startet bei Anfragen server.on()


 Test: Im Browser http://<esp32-ip>/ aufrufen und die Seite sehen.
 */

#include "../wlan_credentials.h"
#include <ESPmDNS.h>
#include <WiFi.h>

// Schritt 2: Webserver laden und Instanz 'server' anlegen
// -------------------------------------------------------
#include <WebServer.h>
WebServer server(80);
// -------------------------------------------------------

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.setHostname(MYHOST);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Start connecting ESP32 to WLAN");
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(WiFi.localIP());

  MDNS.begin(MYHOST);
  Serial.println(MYHOST);

  Serial.println(
      "Testen: Öffne die Windows commandline oder Unix bash und gebe ein:");
  Serial.print("ping ");
  Serial.println(MYHOST);
  Serial.print("ping ");
  Serial.println(WiFi.localIP());

  // Schritt 3: Einfache Webseite in server.on() zum Senden bereitstellen
  // --------------------------------------------------------------------
  server.on("/", []() {
    server.send(200, "text/html", "<h1>ESP32 Webserver aktiv!</h1>");
  });
  // --------------------------------------------------------------------

  // Schritt 4: Starte den Webserver
  // -------------------------------
  server.begin();
  // -------------------------------

  Serial.print(
      "Der ESP32-Webserver ist jetzt mit dem Browser erreichbar: http://");
  Serial.println(MYHOST);
}

void loop() {
  // Schritt 5: Prüfen, ob Client anfrage gesendet hat.
  // --------------------------------------------------
  server.handleClient();
  // --------------------------------------------------
}
