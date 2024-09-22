#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DHT11 sensor configuration
#define DHTPIN 4  // GPIO pin for DHT11
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define I2C_ADDR 0x27  
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);  // 16x2 LCD

// GPIO pins for I2C
#define SDA_PIN 5  // custom SDA GPIO pin
#define SCL_PIN 6  //  your custom SCL GPIO pin

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  delay(2000);
  Serial.begin(115200);

    // Initialize I2C communication with custom SDA and SCL pins
  Wire.begin(SDA_PIN, SCL_PIN);  // Explicitly set SDA and SCL


  lcd.begin(16, 2);
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hej mina");
  delay(5000);

  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("C  ");
  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println("%");

   lcd.setCursor(0, 0);  // Set the cursor to column 0, row 0
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C  ");  // Leave some space for the degree symbol

  // Display humidity on the second line of the LCD
  lcd.setCursor(0, 1);  // Set the cursor to column 0, row 1
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  delay(2000);
}
