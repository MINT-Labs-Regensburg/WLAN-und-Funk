/*
Challenge 02: "Webserver LED schalten" - MUSTERLÖSUNG
=====================================================
*/

// WLAN-Zugangsdaten (SSID & Passwort)
#include <WebServer.h>
#include <WiFi.h>

#include "../wlan_credentials.h"
#include <ESPmDNS.h> // Für mDNS (hostname.local)

// Erstelle Webserver auf Port 80
WebServer server(80);

// Merke LED-Zustand und Pin
String statePin12 = "off";
const int ledPin12 = 12;

void setup() {

  Serial.begin(115200); // Starte seriellen Monitor

  pinMode(ledPin12, OUTPUT);   // Setze LED-Pin als Ausgang
  digitalWrite(ledPin12, LOW); // LED zu Beginn aus

  // Mit WLAN im Station-Modus verbinden
  WiFi.mode(WIFI_STA);
  WiFi.setHostname(MYHOST); // mDNS-Hostname setzen (allein nicht ausreichend
                            // für Browser-Zugriff)
  WiFi.begin(WIFI_SSID, WIFI_PASS); // Anmeldung im WLAN starten
  Serial.println("");
  Serial.print("Verbinde mit WLAN");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // mDNS-Responder starten, damit http://esp32.local/ funktioniert
  if (!MDNS.begin(MYHOST)) {
    Serial.println("Fehler beim Starten von mDNS");
  }

  Serial.println("\nVerbunden! IP-Adresse: ");
  Serial.println(WiFi.localIP());
  Serial.print("Hostname: ");
  Serial.println(WiFi.getHostname());

  // Hauptseite: Zeige AN/AUS-Button je nach LED-Zustand
  server.on("/", []() {
    String html = R"(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html { font-family: monospace; display: inline-block; margin: 0px auto; text-align: center; }
    .button { background-color: yellowgreen; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 32px; margin: 2px; cursor: pointer; }
  </style>
</head>
<body>
  <h1>ESP32 Web Server</h1>
  <p>Control LED State</p>
)";
    if (statePin12 == "off") {
      html += R"(<p><a href="on"><button class="button">AN</button></a></p>)";
    } else {
      html += R"(<p><a href="off"><button class="button">AUS</button></a></p>)";
    }
    html += R"(</body></html>)";
    server.send(200, "text/html", html);
  });

  // Handler für LED AN
  server.on("/on", []() {
    statePin12 = "on";
    digitalWrite(ledPin12, HIGH);
    server.sendHeader("Location", "/"); // Zurück zur Hauptseite
    server.send(303);
  });

  // Handler für LED AUS
  server.on("/off", []() {
    statePin12 = "off";
    digitalWrite(ledPin12, LOW);
    server.sendHeader("Location", "/"); // Zurück zur Hauptseite
    server.send(303);
  });

  server.begin(); // Webserver starten
  Serial.println("Webserver gestartet.");
}

// Bearbeite eingehende HTTP-Anfragen
void loop() { server.handleClient(); }