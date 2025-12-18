# Challenge 00: VS Code & PlatformIO für ESP32 einrichten

## Ziel
Die Entwicklungsumgebung Visual Studio Code (VS Code) mit PlatformIO so einrichten, dass du Programme für den ESP32 kompilieren und hochladen kannst.

## Was du lernen wirst
- PlatformIO in VS Code installieren
- Ein ESP32-Projekt mit PlatformIO anlegen
- Das richtige Board auswählen
- Programme kompilieren und auf den ESP32 hochladen

## Schritt-für-Schritt-Anleitung

1. **VS Code installieren**
   - Lade Visual Studio Code von https://code.visualstudio.com/ herunter und installiere es.

2. **PlatformIO Extension installieren**
   - Öffne VS Code.
   - Gehe zum Extensions-Panel (links, Symbol: Vier Quadrate).
   - Suche nach `PlatformIO IDE` und installiere die Erweiterung.

3. **Neues ESP32-Projekt anlegen**
   - Klicke links unten auf das PlatformIO-Haus-Symbol.
   - Wähle "New Project".
   - Gib einen Projektnamen ein (z.B. `esp32-test`).
   - Wähle als Board z.B. `Espressif ESP32 Dev Module`.
   - Framework: Arduino.
   - Speicherort auswählen und auf "Finish" klicken.

4. **Projekt öffnen und Code schreiben**
   - PlatformIO erstellt die Ordnerstruktur automatisch.
   - Schreibe deinen Code in die Datei `src/main.cpp`.

5. **Kompilieren und Hochladen**
   - Klicke auf das Häkchen ("Build") unten in der blauen Leiste, um zu kompilieren.
   - Klicke auf den Pfeil ("Upload"), um das Programm auf den ESP32 zu laden.

6. **Seriellen Monitor öffnen**
   - Klicke auf das Steckersymbol ("Monitor") unten in der blauen Leiste, um serielle Ausgaben zu sehen.

## Hinweis
Mit PlatformIO und VS Code hast du eine moderne, leistungsfähige Entwicklungsumgebung für den ESP32. Du kannst jetzt mit den Challenges starten!