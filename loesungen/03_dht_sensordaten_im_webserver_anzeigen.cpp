#include <WiFi.h>
#include <ESPmDNS.h>

const char *ssid = "FRITZ!Box 75902";
const char *password = "04562358016988474025";

const char *espname = "ESP-meiner";  // Mein ESP32 Name


#include <WebServer.h>
WebServer server(80);

// Schritt 2: Füge die library für den DHT11 Sensor ein
// ----------------------------------------------------
#include <DHT.h>

// Schritt 3: Erzeuge das Sensor Objekt 'dht' der Klasse DHT
// Datenpin GPIO4 und DHT Typ11
// ---------------------------------------------------------
DHT dht(4, DHT11);  // GPIO4, DHT Typ 11
// ---------------------------------------------------------


void handleRoot() {
  server.send(200, "text/html", "<h1>ESP32 Webserver aktiv!</h1>");
}

// Schritt 5b: handleTemp wird aufgerufen bei URL "/temp"
// -------------------------------------------------------
void handleTemp() {
  float temp = dht.readTemperature();
  String html = "<h1>Temperatur: " + String(temp) + " C</h1>";
  server.send(200, "text/html", html);
}

// Schritt 6b: handleHum wird aufgerufen bei URL "/hum"
// -------------------------------------------------------
void handleHum() {
  float hum = dht.readHumidity();
  String html = "<h1>Luftfeuchtigkeit: " + String(hum) + " %</h1>";
  server.send(200, "text/html", html);
}



void setup() {
  Serial.begin(115200);
  Serial.println("+++ START +++");

  // Schritt 4: Starte den DHT sensor
  // ----------------------------
  dht.begin();
  // ----------------------------


  WiFi.setHostname(espname);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Mit WiFi verbunden");
  Serial.print("IP= ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(espname)) {
    Serial.print("Du kannst den ESP32 erreichen mit:  ping ");
    Serial.print(espname);
    Serial.println(".local");
  } else {
    Serial.println("FEHLER: mDNS konnte nicht gestartet werden");
  }

  server.on("/", handleRoot);

  // Schritt 5a: Neuer Endpoint '/temp' für die Messung der Temperatur
  // -----------------------------------------------------------------
  server.on("/temp", handleTemp);

  // Schritt 6a: Neuer Endpoint '/hum' für die Messung der Luftfeuchtigkeit
  // ---------------------------------------------------------------------
  server.on("/hum", handleHum);


  server.begin();

  Serial.print(
    "Der ESP32-Webserver ist jetzt mit dem Browser erreichbar: http://");
  Serial.println(espname);
}

void loop() {
  server.handleClient();
}
