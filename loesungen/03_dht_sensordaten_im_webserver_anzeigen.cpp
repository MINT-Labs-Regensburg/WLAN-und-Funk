/*
Challenge 03: DHT Sensordaten im Webserver ausgeben
===================================================
Ziel:
Luftfeuchtigkeit und Temperatur mit dem Sensor DHT11 messen.
Es werden zwei neue Endpunkte erzeugt '/temp' und '/hum'. Sie messen
Temperatur und Luftfeuchtigkeit und senden sie an den Client.

Der Sensor hat 3 Pins:
- +5 Volt
- GND
- Die einzige Datenleitung der I2C Schnittstelle wird an den Pin 4 des ESP32
angeschlossen.


Schritte:
1. Kopiere als Basis deinen code aus challenge_02. Damit ist dein ESP bereits
als Webserver aktiv.

Erweitere dann den Code
2. Füge die library für den DHT11 Sensor ein
'#include <DHT.h>'

3. Erzeuge das Objekt 'dht' der Klasse DHT mit den Parametern Datenpin und
Sensortyp
'DHT dht(DHTPIN, DHTTYPE);'

4. Starte den sensor mit 'dht.begin();'

5. Erzeuge neuen Endpoint 'http://<esp32_name>/temp' mit
'server.on("/temp", []()'
Lies die Temperatur aus dem Sensor mit
'float temp = dht.readTemperature();'
und sende die Temperatur an den Client

6. Erzeuge neuen Endpoint 'http://<esp32_name>/hum' mit
'server.on("/hum", []()'
Lies die Luftfeuchtigkeit aus dem Sensor mit
'float hum = dht.readHumidity();'
und sende die Luftfeuchtigkeit an den Client

Teste die neuen Endpoints mit 'http://<esp32_name>/temp' und
'http://<esp32_name>/hum'
*/

#include "../wlan_credentials.h"
#include <ESPmDNS.h>
#include <WiFi.h>

// Schritt 2: Füge include für den Sensor DHT11 ein
// -------------------------------------------------------
#include <DHT.h>
// -------------------------------------------------------

// Schritt 3: Erzeuge das Sensor Objekt 'dht' der Klasse DHT
// ---------------------------------------------------------------------
#define DHTPIN 4      // Pin, an dem der DHT11 angeschlossen ist
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
// ---------------------------------------------------------------------

#include <WebServer.h>
WebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();

  // Schritt 4: Starte den sensor
  // ----------------------------
  dht.begin();
  // ----------------------------

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

  server.on("/", []() {
    String html = "<h1>ESP32 Webserver aktiv!</h1>";
    html += "<p>'/temp' zeigt die Temperatur</p>";
    html += "<p>'/hum' zeigt die Luftfeuchtigkeit</p>";

    server.send(200, "text/html", html);
  });

  // Schritt 5: Neuer Endpoint '/temp' liest die Temperatur und sendet sie
  // ---------------------------------------------------------------------
  server.on("/temp", []() {
    float temp = dht.readTemperature();
    String html = "<p>Temperatur: " + String(temp) + " C</p>";
    server.send(200, "text/html", html);
  });
  // ---------------------------------------------------------------------

  // Schritt 6: Neuer Endpoint '/hum' liest die Luftfeuchtigkeit und sendet sie
  // --------------------------------------------------------------------------
  server.on("/hum", []() {
    float hum = dht.readHumidity();
    String html = "<p>Luftfeuchtigkeit: " + String(hum) + " %</p>";
    server.send(200, "text/html", html);
  });
  // --------------------------------------------------------------------------

  server.begin();
  Serial.print("http://");
  Serial.println(MYHOST);
}

void loop() { server.handleClient(); }
