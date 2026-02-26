#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


int trig = 9;
int echo = 10;


int motorLED = 7;
int buzzer = 8;


int tankHeight = 50;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Water Monitor");
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


  distance = constrain(distance, 0, tankHeight);


  float level = ((tankHeight - distance) / tankHeight) * 100;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Level:");
  lcd.print(level);
  lcd.print("%");

  lcd.setCursor(0,1);


  if(level > 80)
  {
    lcd.print("Tank FULL ");
    digitalWrite(motorLED, LOW);
    digitalWrite(buzzer, LOW);
  }

  else if(level > 30)
  {
    lcd.print("Tank MID  ");
    digitalWrite(motorLED, LOW);
    digitalWrite(buzzer, LOW);
  }

  else
  {
    lcd.print("Tank EMPTY");
    digitalWrite(motorLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(500);

}
