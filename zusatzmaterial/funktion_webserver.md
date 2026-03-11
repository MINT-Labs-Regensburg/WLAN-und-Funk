# Webserver Funktionsweise

## Ablauf einer Anfrage

1. **Browser sendet Request**
   - Der Browser des Benutzers sendet eine HTTP-Anfrage an den Webserver (z. B. d ` /`) wie in http://esp-meinname/  das ` /` am Ende

2. **Webserver sieht den Request in der Loop**
   - In der `loop()`-Funktion wird ständig `server.handleClient()` aufgerufen
   - Dies ist ein Polling-Mechanismus: die Funktion prüft in jedem Loop-Durchlauf, ob ein neuer Request angekommen ist

3. **Webserver verteilt Request an Handler**
   - Wenn `handleClient()` einen Request empfängt, prüft es den Request-Pfad (z. B. `/` für die root oder `/LED_ON`)
   - Der Webserver vergleicht den Pfad mit den registrierten Routen aus `server.on()`
   - Der entsprechende Handler wird aufgerufen
   - Beispiele:    
     `server.on("/", antwortRoot);` → ruft `antwortRoot()` auf   
     `server.on("LED_ON", handleLedOn);` → ruft `handleLedOn()` auf 



## Ablauf-Diagramm

```
┌─────────────┐
│  Browser    │
└──────┬──────┘
       │ http://esp-meinname/LED_ON
       ▼
┌─────────────────────┐
│   ESP32 Webserver   │
│                     │
│  loop()             │
│    handleClient()   │
│ (Polling)           │
│ prüft auf Requests  │
└──────┬──────────────┘
       │ Request "/LED_ON" erkannt
       ▼
┌─────────────────────┐
│ server.on()         │
│ Routing             │
│ vergleicht Path     │
└──────┬──────────────┘
       │ Match: "/LED_ON"
       ▼
┌─────────────────────┐
│ handleLedOn()       │
│ Handler wird        │
│ aufgerufen          │
└──────┬──────────────┘
       │
       ▼
┌─────────────────────┐
│  LED einschalten    │
│  Response senden    │
└─────────────────────┘
```


## Beispiel: LED-Steuerung

```cpp
// Routen registrieren (in setup())
server.on("/", antwortRoot);        // "/" → antwortRoot aufrufen
server.on("/LED_ON", handleLedOn);   // "/LED_ON" → LED einschalten
server.on("/LED_OFF", handleLedOff); // "/LED_OFF" → LED ausschalten

// Handler-Funktionen
void antwortRoot() {
  server.send(200, "text/html", "<h1>LED Steuerung</h1>");
}

void handleLedOn() {
  digitalWrite(LED_PIN, HIGH);  // LED einschalten
  server.send(200, "text/plain", "LED ist AN");
}

void handleLedOff() {
  digitalWrite(LED_PIN, LOW);   // LED ausschalten
  server.send(200, "text/plain", "LED ist AUS");
}

// Polling in der Loop
void loop() {
  server.handleClient();  // Prüft auf neue Requests und ruft Handler auf
  // z. B. Browser öffnet: http://ESP-meiner.local/LED_ON → LED geht an
}
```
