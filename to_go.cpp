#include <Ultrasonic.h>

int MOTOR_A_EN = 9;
int MOTOR_B_EN = 3;
int MOTOR_A1 = 7;
int MOTOR_A2 = 6;
int MOTOR_B1 = 5;
int MOTOR_B2 = 4;
int redPin = A0;
int greenPin = A1;
int  bluePin = A2;
int x;

Ultrasonic ultrasonicFront(13, 12);
Ultrasonic ultrasonicRight(A4, A5);

int baseSpeedA = 230; 
int baseSpeedB = 230;

int safeDistance1 = 10;
int safeDistance2 = 13;

void setup() {
  
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(MOTOR_B_EN, OUTPUT);
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  
  int distanceFront = ultrasonicFront.read(); 
  int distanceRight = ultrasonicRight.read();

    if (distanceFront < 5) {
    x = 0;
  }
  if (distanceRight > safeDistance2 && distanceFront > 5) {
    x = 1;
  }
  else if (distanceRight < safeDistance1 && distanceFront > 5) {
    x = 2;
  } 
   else if (distanceRight < safeDistance2 && distanceRight > safeDistance1) {
    moveForward();
  }
    if (x == 1) {
      setColor(255, 0, 0);
      steerRight(); 
    }
    else if (x == 2) {
      setColor(0, 255, 0);
      steerLeft();
    }
    else if (x == 0) {
      stopMotors(); 
      setColor(0, 0, 0);
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

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);

}
