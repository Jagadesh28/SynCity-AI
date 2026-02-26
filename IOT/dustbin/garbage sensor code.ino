#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig = 9;
int echo = 10;

int led = 7;
int buzzer = 8;


int binHeight = 40;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Smart Waste Bin");
  delay(2000);
}

void loop()
{
  long duration;
  float distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  distance = constrain(distance, 0, binHeight);


  float level = ((binHeight - distance) / binHeight) * 100;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waste:");
  lcd.print(level);
  lcd.print("%");

  lcd.setCursor(0,1);

  if(level > 60)
  {
    lcd.print("BIN FULL ");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else if(level > 30)
  {
    lcd.print("BIN MID  ");
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    lcd.print("BIN EMPTY");
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(500);

}

