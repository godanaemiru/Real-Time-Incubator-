#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#include <SoftwareSerial.h>

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int fan = 7;
int bulb = 6;
int ldrpin = 9;
int ldrstate = 0; 

float temp, t;

String name[6] {"BABY INCUBATOR", "SSALI BENJAMIN", "GODANA EMIRU", "LUKAMBUUZI FRED", "BIGOSI PHIONAH", "NABUNNYA IMMARK"};
String nameid[6] = { "GROUP 17", "18/U/24933/EVE", "18/U/21516/EVE", "18/U/26540/EVE", "18/U/36037/EVE", ""};
int i;

void setup()
{
  lcd.init();
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode (fan, OUTPUT);
  pinMode (bulb, OUTPUT);
  //pinMode (ldrpin, INPUT);
  dht.begin();
  Serial.begin (9600); // Setting the Baud Rate
  lcd.begin (16, 2); // Activating both Rows of LCD
  pinMode(bulb, HIGH);
  pinMode(fan, HIGH);

  //information and identification of the group members including the students numbers

  for (i = 0; i < 6; i++) {
    lcd.clear();
    lcd.print(name[i]);
    lcd.setCursor(1, 1);
    lcd.print(nameid[i]);
    delay(2000);
  }

  temp = dht.readTemperature();
  t = dht.readTemperature();
}
void loop()
{
  // temp = dht.readTemperature();
  float  humidity = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(1, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  delay(2000);
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.println(F("°F"));
  delay(1000);
  //code to check on the different temperatures
  if (t >= 28 && t <= 30) {

    if (temp == (t + 1)) {
      temp = (t + 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("moderate temp");
      delay(1000);
      lcd.clear();
    }
    else if (temp == (t - 1)) {
      temp = (t - 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("Moderate temp");
      delay(1000);
      lcd.clear();
    }
    else {
      Serial.print(F("Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.print(f);
      Serial.println(F("°F"));
      lcd.print("Moderate temp");
      delay(1000);
      lcd.clear();
    }

  }
  else if (t < 28) {
    digitalWrite(bulb, HIGH);
    if (temp == (t + 1)) {
      temp = (t + 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("LOW TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
    else if (temp == (t - 1)) {
      temp = (t - 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("LOW TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
    else {
      Serial.print(F("Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.print(f);
      Serial.println(F("°F"));
      lcd.print("LOW TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
  }
  else if (t > 30) {
    digitalWrite(bulb, HIGH);
    if (temp == (t + 1)) {
      temp = (t + 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("LOW TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
    else if (temp == (t - 1)) {
      temp = (t - 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("LOW TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
    else {
      Serial.print(F("Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.print(f);
      Serial.println(F("°F"));
      lcd.print("LOW TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
  }
  else {
    if (temp == (t + 1)) {
      temp = (t + 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("HIGH TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
    else if (temp == (t - 1)) {
      temp = (t - 1);
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(F("Temp: "));
      lcd.print(temp);
      lcd.print("HIGH TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
    else {
      Serial.print(F("Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.print(f);
      Serial.println(F("°F"));
      lcd.print("HIGH TEMPERATURE");
      delay(1000);
      lcd.clear();
    }
  }
}
