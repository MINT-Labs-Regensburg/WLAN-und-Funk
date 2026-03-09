/*
Challenge 05: RGB-LED per Webserver steuern
===========================================
Ziel: Die Farbe einer RGB-LED kann live über den Browser eingestellt werden.

Schritte:
1. Schließe eine RGB-LED (gemeinsame Kathode oder Anode) mit Vorwiderständen an
drei PWM-fähige Pins des ESP32 an (z.B. GPIO 13, 12, 14). Siehe
zusatzmaterial/ESP32_LED...
2. Im Webbrowser gibt es drei Schieberegler (Rot, Grün, Blau) oder
Eingabefelder.
3. Die Werte werden per HTTP-Request (z.B. /set_rgb?r=255&g=0&b=128) an den
ESP32 gesendet.
4. Der ESP32 setzt die PWM-Werte entsprechend und steuert die LED-Farbe.

*/

