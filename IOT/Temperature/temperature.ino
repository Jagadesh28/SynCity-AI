#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int tempPin = A0;

int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;

int buzzer = 8;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.print("Temp Monitor");
  delay(2000);
}

void loop()
{
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;   // TMP36

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0,1);

  if(temperature > 35)
  {
    lcd.print("HIGH TEMP!");

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);

    digitalWrite(buzzer, HIGH);
  }
  else
  {
    lcd.print("Normal Temp");

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);

    digitalWrite(buzzer, LOW);
  }

  delay(500);
}