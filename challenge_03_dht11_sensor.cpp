/*
 * Challenge 03: DHT11 Sensor am ESP32 auslesen
 * ============================================
 * Ziel: Temperatur und Luftfeuchtigkeit mit dem DHT11 am ESP32 messen und
 * seriell ausgeben.
 *
 * Schritte:
 * 1. DHT11-Sensor anschließen (z. B. Datenpin an GPIO 4)
 * 2. Bibliothek "DHT sensor library" von Adafruit installieren
 * 3. Sensor initialisieren und Messwerte im loop() ausgeben
 *
 * Test: Werte im seriellen Monitor sehen
 */

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4      // Pin, an dem der DHT11 angeschlossen ist
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 Sensor Test");
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Fehler beim Auslesen des DHT11 Sensors!");
  } else {
    Serial.print("Temperatur: ");
    Serial.print(temp);
    Serial.println(" °C");
    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(hum);
    Serial.println(" %");
  }
  Serial.println();
  delay(2000);
}
