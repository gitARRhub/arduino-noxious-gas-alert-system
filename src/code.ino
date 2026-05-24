#include <LiquidCrystal.h>
#include <DHT.h>
#include <Wire.h>
#include "RTClib.h"

// DHT Sensor
int pin = 11;
int type = DHT11;
DHT dht(pin, type);

// LCD
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Pins
#define alc A0
#define led1 A1
#define led2 A2
#define led3 12
#define led4 13
#define buzzer 8

// RTC
RTC_DS3231 rtc;

char daysOfTheWeek[7][4] = {
  "Sun", "Mon", "Tue", "Wed",
  "Thu", "Fri", "Sat"
};

int Day, Month, Year;
int Secs, Minutes, Hours;

String dofweek;
String myDate;
String myTime;

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);
  dht.begin();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ARDUINO BASED");
  lcd.setCursor(0, 1);
  lcd.print("NOXIOUS GAS");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALERTING SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("WITH AMBIENT");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OBSERVATION");
  lcd.setCursor(0, 1);
  lcd.print("FOR MINES");
  delay(2000);

  lcd.clear();

  pinMode(alc, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(buzzer, OUTPUT);

  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Set RTC time from computer compile time
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  digitalWrite(led4, HIGH);
  digitalWrite(led2, HIGH);
}

void loop()
{
  // ================= GAS SENSOR =================

  float adcValue = analogRead(alc);
  delay(10);

  float voltage = adcValue * (5.0 / 1024.0);
  float mgL = 0.67 * voltage;

  Serial.print("GAS: ");
  Serial.print(mgL);
  Serial.println(" mg");

  lcd.setCursor(0, 0);
  lcd.print("GAS: ");
  lcd.print(mgL, 2);
  lcd.print(" PPM");

  // Buzzer alert
  if (mgL >= 20)
  {
    digitalWrite(buzzer, HIGH);
    delay(500);

    digitalWrite(buzzer, LOW);
    delay(500);
  }

  delay(3000);
  lcd.clear();

  // ================= TEMPERATURE =================

  float Temp = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Temperature:");

  lcd.setCursor(0, 1);
  lcd.print(Temp);
  lcd.print(" C");

  delay(3000);
  lcd.clear();

  if (Temp >= 45)
  {
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else
  {
    digitalWrite(led4, HIGH);
    digitalWrite(led3, LOW);
  }

  // ================= HUMIDITY =================

  float Humid = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("Humidity:");

  lcd.setCursor(0, 1);
  lcd.print(Humid);
  lcd.print("%");

  delay(3000);
  lcd.clear();

  if (Humid >= 65)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }

  // ================= RTC =================

  DateTime now = rtc.now();

  Day = now.day();
  Month = now.month();
  Year = now.year();

  Hours = now.hour();
  Minutes = now.minute();
  Secs = now.second();

  dofweek = daysOfTheWeek[now.dayOfTheWeek()];

  myDate = dofweek + " " +
           String(Day) + "/" +
           String(Month) + "/" +
           String(Year);

  myTime = String(Hours) + ":" +
           String(Minutes) + ":" +
           String(Secs);

  // Serial Monitor
  Serial.println(myDate);
  Serial.println(myTime);

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print(myDate);

  lcd.setCursor(0, 1);
  lcd.print(myTime);

  delay(3000);

  lcd.clear();
}
