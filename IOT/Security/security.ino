// Ultrasonic pins
int trigPin = 9;
int echoPin = 10;

// PIR sensor
int pirPin = 7;

// LEDs
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
  // ===== ULTRASONIC =====
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // ===== DOOR LED =====
  if(distance < 80)
  {
    digitalWrite(doorLED, HIGH);   // Door open indication
  }
  else
  {
    digitalWrite(doorLED, LOW);
  }

  // ===== PIR MOTION =====
  int motion = digitalRead(pirPin);

  if(motion == HIGH)
  {
    digitalWrite(motionLED, HIGH);   // Motion detected
  }
  else
  {
    digitalWrite(motionLED, LOW);
  }

  delay(200);
}