#include <Arduino.h>

// HC-SR501 PIR motion sensor wiring for ESP32 DevKit:
// VCC -> 5V
// GND -> GND
// OUT -> GPIO27

const int PIR_PIN = 27;

bool lastMotionState = false;

void setup() {
	Serial.begin(115200);
	pinMode(PIR_PIN, INPUT);

	Serial.println();
	Serial.println("HC-SR501 Bewegungssensor bereit");
	Serial.println("Warte auf Bewegung...");
}

void loop() {
	const bool motionDetected = digitalRead(PIR_PIN) == HIGH;

	if (motionDetected != lastMotionState) {
		if (motionDetected) {
			Serial.println("Bewegung erkannt");
		} else {
			Serial.println("Keine Bewegung mehr");
		}
		lastMotionState = motionDetected;
	}

	delay(50);
}
