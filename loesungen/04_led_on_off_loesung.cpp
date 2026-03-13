#include <WiFi.h>

#include <ESPmDNS.h>


const char *ssid = "MINT-Labs";
const char *password = "int3rn3tofthings";

const char *espname = "ESP-meiner";  // Mein ESP32 Name

// LED ist an GPIO 12 angeschlossen
// -------------------------------------------------
const int LEDPIN = 12;  // GPIO12, LED Pin
// -------------------------------------------------

#include <WebServer.h>
WebServer server(80);

#include <DHT.h>

DHT dht(4, DHT11);  // GPIO4, DHT Typ 11

void antwortRoot() {
  server.send(200, "text/html", "<h1>ESP32 Webserver aktiv!</h1>");
}

void handleTemp() {
  float temp = dht.readTemperature();
  String html = "<h1>Temperatur: " + String(temp) + " C</h1>";
  server.send(200, "text/html", html);
}

void handleHum() {
  float hum = dht.readHumidity();
  String html = "<h1>Luftfeuchtigkeit: " + String(hum) + " %</h1>";
  server.send(200, "text/html", html);
}
// Schritt 4b: handleLedEin bzw. handleLedAus wird aufgerufen bei URL '/led_ein' bzw. '/led_aus'
// --------------------------------------------

void handleLedEin() {
  digitalWrite(LEDPIN, 1);
  server.send(200, "text/html", "<h1>LED ist an</h1>");
}

void handleLedAus() {
  digitalWrite(LEDPIN, 0);
  server.send(200, "text/html", "<h1>LED ist aus</h1>");
}
// -------------------------------------------------

void setup() {
  Serial.begin(115200);
  Serial.println("+++ START +++");

  dht.begin();
  WiFi.setHostname(espname);

  WiFi.begin(ssid, password);

  // Schritt 3: Setze LED Pin als OUTPUT. Wir vewenden GPIO12 als LEDPIN
  // -------------------------------------------------
  pinMode(LEDPIN, OUTPUT);
  // -------------------------------------------------


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

  server.on("/", antwortRoot);
  server.on("/temp", handleTemp);
  server.on("/hum", handleHum);

  // // Schritt 4a: Neue Endpoints '/led_ein' und '/led_aus' zur Steuerung der LED
  // -----------------------------------------------------------------
  server.on("/led_ein", handleLedEin);
  server.on("/led_aus", handleLedAus);
  // -----------------------------------------------------------------

  server.begin();

  Serial.print(
    "Der ESP32-Webserver ist jetzt mit dem Browser erreichbar: http://");
  Serial.println(espname);
}

void loop() {
  server.handleClient();
}
