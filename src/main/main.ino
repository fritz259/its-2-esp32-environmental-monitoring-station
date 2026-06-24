#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_PIN 4
#define MQ135_PIN 34

#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 33
#define RED_LED_PIN 25
#define ACTIVE_BUZZER_PIN 26

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(ACTIVE_BUZZER_PIN, OUTPUT);

  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  dht.begin();

  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println("ESP32 Environmental Monitoring Station");
  display.setTextSize(1);
  display.setCursor(0, 50);
  display.println("Sensor wird warm...");
  display.display();

  delay(30000);
}

void loop() {
  
}
