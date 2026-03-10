#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED 128x64 (I2C) wiring for ESP32 DevKit:
// GND -> GND
// VCC -> 3V3
// SCL -> GPIO22
// SDA -> GPIO21

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
	Wire.begin();

	if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
		while (true) {
			delay(100);
		}
	}

	display.clearDisplay();
	display.setTextSize(2);
	display.setTextColor(SSD1306_WHITE);
	display.setCursor(0, 24);
	display.println("Hello !");
	display.display();
}

void loop() {
	
}
