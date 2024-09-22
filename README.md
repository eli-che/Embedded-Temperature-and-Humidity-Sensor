# Embedded Temperature and Humidity Sensor

This project demonstrates how to interface the ESP32 microcontroller with a DHT11 sensor to measure temperature and humidity. The sensor data is displayed both on a serial monitor and a 16x2 I2C LCD.

## Features
- **Temperature Measurement**: Reads the temperature from the DHT11 sensor and displays it in Celsius.
- **Humidity Measurement**: Reads the humidity from the DHT11 sensor and displays it as a percentage.
- **LCD Display**: Shows the temperature and humidity on a 16x2 I2C LCD.
- **Serial Output**: Outputs the readings to the serial monitor for easy debugging.

## Components
- **ESP32 (ESP32-S3-WROOM)**
- **DHT11 Temperature and Humidity Sensor**
- **16x2 I2C LCD**
- **Wires & Breadboard**

## Pin Configuration

| Component           | GPIO Pin      | Function          |
|---------------------|---------------|-------------------|
| DHT11 Data Pin      | GPIO 4        | Reads temperature and humidity |
| LCD SDA Pin         | GPIO 5        | I2C Data Line      |
| LCD SCL Pin         | GPIO 6        | I2C Clock Line     |

## Circuit Diagram
- Connect the DHT11 sensor’s data pin to GPIO 4.
- Connect the I2C LCD's SDA to GPIO 5 and SCL to GPIO 6.
  
## Code Explanation
The code uses the following libraries:
- **DHT Library**: For reading temperature and humidity from the DHT11 sensor.
- **LiquidCrystal_I2C Library**: For controlling the I2C-based 16x2 LCD.

The main functionality:
- Initializes the DHT11 sensor and LCD.
- Reads temperature and humidity in the loop.
- Displays the readings on both the serial monitor and the LCD.

```cpp
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4  // GPIO pin for DHT11
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define I2C_ADDR 0x27  
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);

#define SDA_PIN 5  
#define SCL_PIN 6  

void setup() {
  dht.begin();
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("C  ");
  Serial.print("Humidity: ");
  Serial.println(humidity);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  
  delay(2000);
}
```

## How to Use
1. **Hardware Setup**:
   - Assemble the circuit as per the pin configuration table.
2. **Software Setup**:
   - Install the required libraries:
     - [DHT Library](https://github.com/adafruit/DHT-sensor-library)
     - [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)
   - Upload the provided code to your ESP32 using the Arduino IDE.
3. **Run the Project**:
   - Open the serial monitor to view temperature and humidity readings.
   - The LCD will also display the current temperature and humidity.

## Future Improvements
- Add more sensors for environmental monitoring (e.g., air quality sensors).
- Implement a web interface to display the sensor data using the ESP32's Wi-Fi capability.
  
## License
This project is open-source under the MIT License. Feel free to modify and distribute as needed.

