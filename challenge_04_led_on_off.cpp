/*
Challenge 04: LED per Webserver schalten
========================================
Ziel: Der ESP32 empfängt Kommandos vom Browser und
schaltet eine LED ein oder aus.

Schritte:
1. Kopiere als Basis deinen Code aus challenge_04_dht_sensordaten_im_webserver_anzeigen.cpp.
2. Definiere den Pin, an dem die LED angeschlossen ist (z.B. GPIO 12).
3. Setze den Pin im setup() als OUTPUT.
   pinMode(12, OUTPUT);

4. Erzeuge zwei neue Endpoints 'http://ESP-meinname/led_ein' und 'http://ESP-meinname/led_aus' 
mit
'server.on("/led_ein", handleLedEin);' und 
'server.on("/led_aus", handleLedAus);'
In handleLedEin() wird die LED eingeschaltet mit
  digitalWrite(LED_PIN, HIGH);
und an den Browser gesendet mit
  String html = "<p>LED ist an</p>";
  server.send(200, "text/html", html);

In handleLedAus() wird die LED ausgeschaltet mit
  digitalWrite(LED_PIN, LOW);
und an den Browser gesendet mit
  String html = "<p>LED ist aus</p>";
  server.send(200, "text/html", html); 



Teste die Endpoints im Browser:
- http://<esp32_name>/led_ein
- http://<esp32_name>/led_aus
*/

