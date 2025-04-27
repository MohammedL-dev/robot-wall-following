#include <Ultrasonic.h>



Ultrasonic ultrasonicLeft(12, 11);
Ultrasonic ultrasonic(4, 3);

const int ENA = 10;
const int ENB = 9;
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 6;
const int IN4 = 5;


void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  
  analogWrite(ENA, 150); 
  analogWrite(ENB, 150); 
}

void loop() {
  
  long distanceLeft = ultrasonicLeft.Ranging(CM);
  long distanceRight = ultrasonicRight.Ranging(CM);

  
  // if (distanceLeft < 15 && distanceRight < 15) {
  //   stopMotors();
  //   delay(500);
  //   turnRight(); 
  // } else if (distanceLeft < 15) {
  //   steerRight();
  // } else if (distanceRight < 15) {
  //   steerLeft();
  // } else {
  //   moveForward();
  //}
  
  if (distanceLeft < 15 && distanceRight < 15) {
    
    stopMotors();
    delay(500);
    turnRight(); 
  } else if (distanceLeft < 15) {
    steerRight();
  } else if (distanceRight < 15) {
    steerLeft();
  } else {
    moveForward();
  }
  
  
  
}


void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

 
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(800);
}

void steerRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(400);
}


void steerLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(400);
}