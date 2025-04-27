#include <Ultrasonic.h>

const int MOTOR_A_EN = 9;
const int MOTOR_B_EN = 3; 
const int MOTOR_A1 = 7;
const int MOTOR_A2 = 6;
const int MOTOR_B1 = 5;
const int MOTOR_B2 = 4;
int redPin= A0;
int greenPin = A1;
int  bluePin = A2;
int x;

Ultrasonic ultrasonicFront(13, 12);
Ultrasonic ultrasonicRight(A4, A5);

const int baseSpeedA = 220; 
const int baseSpeedB = 220;

const int safeDistance1 = 10;
const int safeDistance2 = 12;

void setup() {
  
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(MOTOR_B_EN, OUTPUT);
  pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  int distanceFront = ultrasonicFront.read();
  int distanceRight = ultrasonicRight.read();


   Serial.print(distanceRight); delay(100);
   Serial.print("    ");
   if (x == 1) { Serial.println("Stop"); delay(100); } 
   else if (x == 3) { Serial.println("Rigth"); delay(100); } 
   else if (x == 2) { Serial.println("left"); delay(100); } 
   else if (x == 4) { Serial.println("9dam"); delay(100); }


  if (distanceFront < safeDistance2 && distanceRight <= safeDistance2) {
    stopMotors(); 
    x = 1;
    setColor(0, 0, 0);
  } else if (distanceRight < safeDistance1) {
    steerLeft(); 
    x = 2;
    setColor(0, 255, 0);
  } else if (distanceRight > safeDistance2) {
    steerRight(); 
    x = 3;
    setColor(255, 0, 0);
  } else {
    moveForward();
    x = 4;
  }

  delay(90); 
}


void moveForward() {
  analogWrite(MOTOR_A_EN, baseSpeedA);   
  analogWrite(MOTOR_B_EN, baseSpeedB);   
  setMotorsForward();             
}

void steerRight() {
  analogWrite(MOTOR_A_EN, baseSpeedA / 2); // possibilité tkoun 2 ou *0.75
  analogWrite(MOTOR_B_EN, baseSpeedB);     
  setMotorsForward();                  
}

void steerLeft() {
  analogWrite(MOTOR_A_EN, baseSpeedA);     
  analogWrite(MOTOR_B_EN, baseSpeedB / 2); // possibilité tkoun 2 ou *0.75
  setMotorsForward();                     
}

oid stopMotors() {
  analogWrite(MOTOR_A_EN, 0);   
  analogWrite(MOTOR_B_EN, 0);  
}

void setMotorsForward() {
  digitalWrite(MOTOR_A1, HIGH);
  digitalWrite(MOTOR_A2, LOW);
  digitalWrite(MOTOR_B1, HIGH);
  digitalWrite(MOTOR_B2, LOW);
}

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);

}