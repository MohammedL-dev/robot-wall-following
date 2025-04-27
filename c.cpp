#include <Ultrasonic.h>

int ENA = 10;
 int ENB = 9; 
 int IN1 = 8;
 int IN2 = 7;
 int IN3 = 6;
 int IN4 = 5;


Ultrasonic sensorFront(12, 11);
Ultrasonic sensorRight(4, 3);

int speedBase = 150; 
int speedMax = 180;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENA, speedBase); 
  analogWrite(ENB, speedBase); 
}

void loop() {
  long distFront = sensorFront.Ranging(CM);
  long distRight = sensorRight.Ranging(CM);

  if (distFront > 0 && distFront < 15) {
    stop();
  } else if (distRight < 10) {
    turnLeft(distRight);
  } else if (distRight > 30) {
    turnRight(distRight);
  } else {
    forward();
  }
}

void forward() {
  analogWrite(ENA, speedBase);
  analogWrite(ENB, speedBase);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnRight(long distRight) {
  int speedAdj = map(distRight, 30, 50, speedBase, speedMax);
  analogWrite(ENA, speedAdj); 
  analogWrite(ENB, speedBase);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft(long distRight) {
  int speedAdj = map(distRight, 0, 10, speedMax, speedBase);
  analogWrite(ENA, speedBase); 
  analogWrite(ENB, speedAdj);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}