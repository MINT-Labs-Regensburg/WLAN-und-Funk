# 🌐 IoT-Internet of Things mir dem ESP32

# Was dich erwartet

Du bist 14 Jahre alt oder älter und hast bereits Erfahrung in der Arduino-Welt? Du willst einen Microcontroller ins WLAN bringen und ihn über dein Handy steuern?   
Dann bist du hier richtig im Kurs **Internet of Things – ESP32 im WLAN**!  

In drei Stunden lernst du, wie du mit dem ESP32 ein eigenes IoT-Gerät entwickelst, das Sensordaten misst und im WLAN bereitstellt.  
Du programmierst einen ESP32-Webserver, der live Temperatur- und Feuchtigkeitswerte von einem Sensor liefert. Diese Werte kannst du direkt auf dem Browser deines Smartphones ode Laptops anschauen.  
Außerdem wirst du LEDs und LED-Streifen über dein Smartphone fernsteuern.

---

## 🧰 Material
- 1 × ESP32 DevKit
- 1 × Sensor (BME280 oder DHT22)
- Jumperkabel, Breadboard
- LEDs, Widerstände
- RGB LED
- WLAN-Zugangsdaten (SSID + Passwort)
- Laptop mit Visual Studio Code und Extension PlatformIO
- Smartphone/Laptop mit Browser

---


## 📅 Internet of Things IoT: Was macht ein IoT-Client ?
Ein IoT-Client ist ein Gerät, das Sensordaten erfasst (z. B. Temperatur, Feuchte) und/oder Aktuatoren steuert (z. B. LEDs, Relais).  
Der ESP32 kommuniziert über das Netzwerk mit anderen Geräten (z. B. deinem Handy oder Laptop), um Daten zu senden oder Befehle zu empfangen.

### 🛰️ ESP32: STATION- oder AP-Modus?
Der ESP32 kann auf zwei Arten mit WLAN arbeiten:
- **STATION Mode (STA):** Der ESP32 verbindet sich als Client mit deinem Heimnetzwerk (wie ein Handy oder Laptop). Er bekommt eine IP-Adresse vom Router zugewiesen und ist für alle Geräte im WLAN erreichbar. Das ist der Standard für IoT-Anwendungen.
- **Access Point Mode (AP):** Der ESP32 eröffnet ein eigenes WLAN, mit dem sich andere Geräte direkt verbinden können. Das ist praktisch ohne Router, aber im Alltag meist weniger komfortabel.

👉 **Wir nutzen im Kurs den STATION Mode!** Dein ESP32 meldet sich im Heimnetz an und ist von allen Geräten im WLAN erreichbar.

<br>

---


# Jetzt kann es losgehen: Der ESP32 als IoT Client - Schritt für Schritt
1. ESP32 ist mit dem WLAN verbunden
2. ESP32 stellt einen Webserver zur Verfügung
3. ESP32 misst Sensordaten und stellt sie über seinen Webserver bereit
4. ESP32 empfängt Befehle und steuert Aktuatoren

## 📅 1. Den ESP32 mit dem WLAN verbinden
Zunächst muss der ESP32 mit dem Netz verbunden werden.  
Wir melden den ESP32 im WLAN an und brauchen dafür das WLAN passwort.   
Dein ESP32 kann dann über seinen Namen oder seine IP-Adresse angesprochen werden.   

[challenge_01_esp32_mit_wlan_verbinden.cpp](challenge_01_esp32_mit_wlan_verbinden.cpp)

---

## 📅 2. Der ESP32 stellt einen Webserver zur Vefügung
Nachdem dein ESP32 mit dem WLAN verbunden ist, installieren wir einen einfachen Webserver auf dem ESP32.  
Der Webserver antwortet nur mit einer einfachen Meldung `ESP32 Webserver aktiv!`.
- der Webserver 'lauscht' im WLAN, ob ein Anfrage an ihn gestellt wurde.   
  Bespiel: Der Browser im Laptop hat  `http://esp32_name/` an den ESP32 gesendet.
- Als Antwort sendet der Webserver eine einfache html-Webseite mit der Meldung `ESP32 Webserver aktiv!`
  
[challenge_02_webserver_einrichten.cpp](challenge_02_webserver_einrichten.cpp)

---

## 📅 3. Der ESP32 misst Sensordaten und stellt sie über seinen Webserver bereit
Jetzt füllen wir die Webseite die bisher nur mit `ESP32 Webserver aktiv!` geantwortet hat mit echten Messdaten.  
Für die Messung wird ein Sensor, der DHT11 per I2C Bus an den ESP32 angeschlossen. Der Sensor kann die Temperatur und die Luftfeuchtigkeit messen.  


So wird der Sensor an den ESP32 angeschlossen:
- [ESP32 und DHT11 Steckbrett](zusatzmaterial/ESP32_DHT11_bb.png)
- [ESP32 und DHT11 Schaltplan](zusatzmaterial/ESP32_DHT11_schem.png)
- [DHT11 Pinout](zusatzmaterial/dht11_pinout.jpg)



Um die Messdaten abrufbar zu machen, programmieren wir zwei neue Endpoints:
- http://<mein_server>/temp
- http://<mein_server>/hum  
  
Wird einer dieser beiden Endpoints vom Client angefragt, liest der ESP32 zunächst den dazugehörigen Sensor-Messwert und schickt dann den Messwert an den Client zurück.

[challenge_03_dht_sensordaten_im_webserver_anzeigen.cpp](challenge_03_dht_sensordaten_im_webserver_anzeigen.cpp)

---


## 4. Der ESP32 empfängt Befehle vom Client und steuert Aktuatoren
Es geht auch in die andere Richtung:  
Der ESP32 schaltet eine LED. Dazu wird die LED über einen Vorwiderstand mit einem ESP32-Ausgang verbunden.  
Wichtig: Ein Vorwiderstand ist nötig, um die LED vor zu viel Strom zu schützen.   
Wie du die LED an den ESP32 anschließt, siehst du hier
- [ESP und LED Steckbrett](zusatzmaterial/ESP32_LED_bb.png)
- [ESP und LED Schaltplan](zusatzmaterial/ESP32_LED_schem.png)

Der Laptop schickt ein Kommando an den ESP32 und der ESP32 schaltet dann einen Aktuator, zum Beispiel die Leuchtdiode.  
Dazu programmieren wir zwei neue Endpoints `led_ein`  und `led_aus`.   

Die neuen Endpoints können dann vom Browser aufgerufen werden mit
- http://<mein_server>/led_ein
- http://<mein_server>/led_aus

[challenge_04_led_on_off.cpp](challenge_04_led_on_off.cpp)

---


## 5. Jetzt wird's bunt: RGB-LED mit dem Handy steuern


In dieser Challenge steuerst du eine RGB-LED.
Wie du die RGB LED an den ESP32 anschließt, findest du hier:
- [ESP32 und RGB-LED Steckbrett](zusatzmaterial/ESP32_RGB_bb.png)
- [ESP32 und RGB-LED Schaltplan](zusatzmaterial/ESP32_RGB_schem.png)

Du steuerst die RGB LED über den Webbrowser:
- Im Browser kannst du die Werte für Rot, Grün und Blau einstellen mit drei Schiebereglern oder Eingabefeldern.
- Der ESP32 empfängt die Werte und steuert damit die drei Farben der RGB-LED.


Du programmierst einen neuen Endpoint `/set_rgb`, der drei Parameter für die Farben erhält:

- http://<mein_server>/set_rgb?r=255&g=0&b=128

[challenge_05_rgb_led.cpp](challenge_05_rgb_led.cpp)


## ℹ️ Zusätzliche Informationen
Weitere Details und technische Informationen zum ESP32 DevKitC findest du in der offiziellen Dokumentation:  
[ESP32-DevKitC Dokumentation (Espressif)](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-devkitc/index.html#esp32-devkitc)


## 📞 Kontakt

Bei Fragen zum Kurs oder Material:  
**MINT-Labs Regensburg**  
🌐 [https://www.mint-labs-regensburg.de/](https://www.mint-labs-regensburg.de/)

## Mehr Projekte und Anleitungen findest du [hier](https://wiki.mint-labs.de/)
