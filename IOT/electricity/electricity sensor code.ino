#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;

float voltage = 0;
float current = 0;
float power = 0;

void setup()
{  lcd.begin(16, 2);
  lcd.print("Hello Jagadesh!");
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(sensorPin);

  voltage = sensorValue * (5.0 / 1023.0);

  // Simulated current scaling
  current = voltage * 2;

  power = voltage * current;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pwr:");
  lcd.print(power);
  lcd.print("W");

  lcd.setCursor(0,1);
  lcd.print("V:");
  lcd.print(voltage);

  Serial.print("Voltage:");
  Serial.print(voltage);
  Serial.print(" Power:");
  Serial.println(power);

  delay(1000);
}