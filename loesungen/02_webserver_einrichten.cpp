#include <WiFi.h>

#include <ESPmDNS.h>

const char *ssid = "FRITZ!Box 75902";
const char *password = "04562358016988474025";

const char *espname = "ESP-meiner"; // Mein ESP32 Name

// Schritt 2: Webserver laden und Instanz 'server' anlegen
// -------------------------------------------------------
#include <WebServer.h>
WebServer server(80);
// -------------------------------------------------------


// Schritt 3a: handleRoot wird von server.on("/") aufgerufen
// -------------------------------------------------------
void handleRoot()
{
  server.send(200, "text/html", "<h1>ESP32 Webserver aktiv!</h1>");
}
// -------------------------------------------------------

void setup()
{
  Serial.begin(115200);
  Serial.println("+++ START +++");

  WiFi.setHostname(espname);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Mit WiFi verbunden");
  Serial.print("IP= ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(espname))
  {
    Serial.print("Du kannst den ESP32 erreichen mit:  ping ");
    Serial.print(espname);
    Serial.println(".local");
  }
  else
  {
    Serial.println("FEHLER: mDNS konnte nicht gestartet werden");
  }

  // Schritt 3b: Wenn der Server "/" empfängt, die Funktion handleRoot aufrufen
  // --------------------------------------------------------------------
  server.on("/", handleRoot);
  // --------------------------------------------------------------------

  // Schritt 4: Starte den Webserver
  // -------------------------------
  server.begin();
  // -------------------------------

  Serial.print(
      "Der ESP32-Webserver ist jetzt mit dem Browser erreichbar: http://");
  Serial.println(espname);
}

void loop()
{
  // Schritt 5: Prüfen, ob der Browser eine Anfrage gesendet hat. 
  // Wenn ja, wird die Funktion server.on aufgerufen.
  // --------------------------------------------------
  server.handleClient();
  // --------------------------------------------------
}
