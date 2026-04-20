# Challenge 00: Arduino IDE für ESP32 erweitern

## Ziel
Die Arduino IDE so einrichten, dass sie Programme für den ESP32 kompilieren und hochladen kann.

## Was du lernen wirst
- Die Boardverwalter-URL für ESP32 hinzufügen
- Das ESP32-Board in der Arduino IDE installieren
- Das richtige Board auswählen

## Schritt-für-Schritt-Anleitung

1. **Arduino IDE öffnen**
2. Gehe zu `Datei > Voreinstellungen`.
3. Füge folgende URL bei "Zusätzliche Boardverwalter-URLs" ein:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
4. Öffne `Werkzeuge > Board > Boardverwalter`.
5. Suche nach "ESP32" und installiere "esp32 von Espressif Systems".
6. Wähle unter `Werkzeuge > Board` das passende ESP32-Board aus (z.B. ESP32 Dev Module).

## Hinweis
Ohne diese Erweiterung kann die Arduino IDE keine Programme für den ESP32 kompilieren oder hochladen. Nach der Installation kannst du mit den Challenges starten!

<a id="arduino-ide-esp32"></a>
### Erweitern der Arduino IDE für den ESP32
▶️ [YouTube: Arduino IDE und ESP32](https://youtu.be/RbEGBOytZzc?si=KouAGV5stZRRLF-T)
