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
'#include <DHT.h>'. 
Eventuell muss die Adafruit DHT Sensor Library über den Library Manager in der Arduino IDE installiert werden.

3. Erzeuge das Objekt 'dht' der Klasse DHT mit den Parametern Datenpin und
Sensortyp
'DHT dht(DHTPIN, DHTTYPE);' Beispiel: DHTPIN=4, DHTTYPE=DHT11

4. Starte den sensor mit 'dht.begin();'

5. Erzeuge neuen Temperatur-Endpoint 'http://ESP-meinname/temp' mit
'server.on("/temp", handleTemp);'
In handleTemp() wird die Temperatur aus dem Sensor gelesen mit
  float temp = dht.readTemperature();
und an den Browser gesendet mit
  String html = "<p>Temperatur: " + String(temp) + " C</p>";
  server.send(200, "text/html", html);

6. Erzeuge neuen Luftfeuchtigkeit-Endpoint 'http://ESP-meinname/hum' mit
'server.on("/hum", handleHum);'
In handleHum() wird die Luftfeuchtigkeit aus dem Sensor gelesen mit
  float hum = dht.readHumidity();
und an den Browser gesendet mit
  String html = "<p>Luftfeuchtigkeit: " + String(hum) + " %</p>";
  server.send(200, "text/html", html);


Teste die neuen Endpoints mit 'http://ESP-meinname/temp' und
'http://ESP-meinname/hum'
*/

