const int trigPin = 4;
const int echoPin = 8;
const int greenLED = 5;
const int yellowLED = 6;
const int redLED = 7;
const int buzzerPin = 11;
const int servoPin = 3;

const int warnDist = 80;
const int breachDist = 40;

unsigned long latchTime = 0;
const unsigned long resetDelay = 15000;

bool alarmOn = false;

int servoAngle = 90;
int dir = 1;
int breachCount = 0;


void pulseServo(int angle) {
  int pw = map(angle, 0, 180, 500, 2500);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pw);
  digitalWrite(servoPin, LOW);
}


long getDistance() {
  long total = 0;

  for (int i = 0; i < 5; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long dur = pulseIn(echoPin, HIGH, 50000);
    long dist;

    if (dur == 0) {
      dist = 800;
    } else {
      dist = dur * 0.0343 / 2;
    }

    if (dist < 5 || dist > 800) dist = 800;

    total += dist;
    delay(5);
  }

  return total / 5;
}


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
}


void loop() {
  if (!alarmOn) {
    servoAngle += dir;
    if (servoAngle >= 165 || servoAngle <= 15) dir = -dir;
  }
  pulseServo(servoAngle);

  long dist = getDistance();

  Serial.print(servoAngle);
  Serial.print(",");
  Serial.print(dist);
  Serial.println(".");

  if (alarmOn) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(buzzerPin, 2500);

    if (millis() - latchTime >= resetDelay) {
      alarmOn = false;
      breachCount = 0;
      noTone(buzzerPin);
    }
  }

  else {
    if (dist > warnDist) {
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
      noTone(buzzerPin);
      breachCount = 0;
    }
    else if (dist <= warnDist && dist > breachDist) {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
      tone(buzzerPin, 1000);
      delay(50);
      noTone(buzzerPin);
      breachCount = 0;
    }
    else if (dist <= breachDist) {
      breachCount++;
      if (breachCount >= 3) {
        alarmOn = true;
        latchTime = millis();
        breachCount = 0;
      }
    }
  }

  delay(20);
}