#include <Ultrasonic.h>

const int ENA = 9;
const int ENB = 3; 
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;

Ultrasonic ultrasonicFront(13, 12);
Ultrasonic ultrasonicRight(A4, A5);

const int baseSpeedA = 170; 
const int baseSpeedB = 170;

const int safeDistance1 = 10;
const int safeDistance2 = 12;

void setup() {
  
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(MOTOR_B_EN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  int distanceFront = ultrasonicFront.read();
  int distanceRight = ultrasonicRight.read();


  Serial.print("Distance avant : ");
  Serial.print(distanceFront);
  Serial.print(" cm | Distance droite : ");
  Serial.println(distanceRight);


  if (distanceFront < safeDistance2 && distanceRight <= safeDistance2) {
    stopMotors(); // Arrêt si obstacle devant et à droite
  } else if (distanceRight < safeDistance1) {
    steerLeft(); // Tourner à gauche si trop proche du mur droit
  } else if (distanceRight > safeDistance2) {
    steerRight(); // Tourner à droite si trop loin du mur droit
  } else {
    moveForward(); // Avancer 
  }

  delay(90); 
}


void moveForward() {
  analogWrite(MOTOR_A_EN, baseSpeedA);   
  analogWrite(MOTOR_B_EN, baseSpeedB);   
  setMotorsForward();             
}

void steerRight() {
  analogWrite(MOTOR_A_EN, baseSpeedA / 3); // possibilité tkoun 2 ou *0.75
  analogWrite(MOTOR_B_EN, baseSpeedB);     
  setMotorsForward();                  
}

void steerLeft() {
  analogWrite(MOTOR_A_EN, baseSpeedA);     
  analogWrite(MOTOR_B_EN, baseSpeedB / 3); // possibilité tkoun 2 ou *0.75
  setMotorsForward();                     
}

void stopMotors() {
  analogWrite(MOTOR_A_EN, 0);   
  analogWrite(MOTOR_B_EN, 0);  
}

void setMotorsForward() {
  digitalWrite(MOTOR_A1, HIGH);
  digitalWrite(MOTOR_A2, LOW);
  digitalWrite(MOTOR_B1, HIGH);
  digitalWrite(MOTOR_B2, LOW);
}