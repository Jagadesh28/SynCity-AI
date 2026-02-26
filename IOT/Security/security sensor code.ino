
int trigPin = 9;
int echoPin = 10;


int pirPin = 7;


int doorLED = 3;
int motionLED = 4;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pirPin, INPUT);

  pinMode(doorLED, OUTPUT);
  pinMode(motionLED, OUTPUT);
}

void loop()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  
  if(distance < 80)
  {
    digitalWrite(doorLED, HIGH);   
  }
  else
  {
    digitalWrite(doorLED, LOW);
  }

  
  int motion = digitalRead(pirPin);

  if(motion == HIGH)
  {
    digitalWrite(motionLED, HIGH);   
  }
  else
  {
    digitalWrite(motionLED, LOW);
  }

  delay(200);

}
