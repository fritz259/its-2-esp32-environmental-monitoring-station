# ESP32 Environmental Monitoring Station

A simple environmental monitoring project built with an ESP32, featuring temperature/humidity sensing, air quality detection, an OLED display, and visual/audio alerts.

## Features

- 🌡️ Temperature & humidity readings via DHT11 sensor
- 💨 Air quality monitoring via MQ135 gas sensor
- 📟 Live readings on a 128x64 OLED display (SSD1306)
- 🚦 Status LEDs (green/yellow/red) based on air quality
- 🔔 Active buzzer alarm when the air quality changes

## Hardware

| Component | Pin (ESP32) |
|---|---|
| OLED Display (SSD1306, I2C) | SDA/SCL (default I2C pins) |
| DHT11 Sensor | GPIO 4 |
| MQ135 Gas Sensor (AOUT) | GPIO 34 (via voltage divider) |
| Red LED | GPIO 25 |
| Yellow LED | GPIO 33 |
| Green LED | GPIO 27 |
| Active Buzzer | GPIO 26 |

> ⚠️ The MQ135 outputs a 5V analog signal. A voltage divider (e.g. 2× 10kΩ or 1× 10kΩ + 2× 10kΩ parallel) is required to safely bring this down to ≤3.3V for the ESP32 ADC input.

## Wiring Notes

- MQ135 `VCC` → ESP32 `Vin` (5V)
- MQ135 `GND` → ESP32 `GND`
- MQ135 `AOUT` → voltage divider → ESP32 `GPIO 34`
- DHT11, LEDs, and buzzer connect directly to their respective GPIOs

## Libraries Required

Install via Arduino IDE Library Manager:
- `Adafruit GFX Library`
- `Adafruit SSD1306`
- `Adafruit Sensor`
- `DHT sensor library` (by Adafruit)

## How It Works

1. On startup, the OLED displays a welcome message and the MQ135 sensor warms up (~30s).
2. The DHT11 reads temperature and humidity every 2 seconds.
3. The MQ135 reads air quality as a raw analog value.
4. Based on the air quality reading:
   - **Good** → Green LED
   - **Moderate** → Yellow LED
   - **Poor** → Red LED + buzzer alarm
5. All readings are shown on the OLED display and printed to the Serial Monitor.

## Getting Started

1. Wire the components according to the table above.
2. Install the required libraries.
3. Open the `.ino` file in Arduino IDE.
4. Select your ESP32 board and COM port.
5. Upload and open the Serial Monitor at `115200` baud.

## License

MIT