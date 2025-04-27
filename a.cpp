#include <Ultrasonic.h>

// hna declaration
const int ENA = 9;
const int ENB = 3; 
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;



Ultrasonic ultrasonicFront(12, 11);
Ultrasonic ultrasonicRight(A0, A4);

int baseSpeed = 150; 
int baseSpeed_1 = 165;
int turnSpeed = 200; 

void setup() {
  // kanhto dakchi li diclarenah ka output
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  //kanhto 150 hiya sor3a l2iftiradia
  analogWrite(ENA, baseSpeed); 
  analogWrite(ENB, baseSpeed); 

void loop() {
  
  //kn9raw l9yam dyal ultrasonic b cm
  long distanceFront = ultrasonicFront.Ranging(CM);
  long distanceRight = ultrasonicRight.Ranging(CM);

  // ila kan chi haja 9damk
  if (distanceFront > 0 && distanceFront < 5) {
    //w9af
    stopMotors();
  // ila l7it wla 9rib
  } else if (distanceRight < 10) {
    //dor o ba3ad mno
    steerLeftSmooth();
  //ila l7it wla b3id
  } else if (distanceRight > 20) {
    // dor o 9arab mno
    steerRightSmooth();
  
  } else {
    //b9a radi nichan (y3ni lbo3d dyal l7it howa li khaso ykon)
    moveForward();
  }
}


void moveForward() {
  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed_1);
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


void steerRightSmooth() {
  analogWrite(ENA, turnSpeed); 
  analogWrite(ENB, baseSpeed_1);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void steerLeftSmooth() {
  analogWrite(ENA, baseSpeed); 
  analogWrite(ENB, turnSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void loop()
{

    //Moves straight for 2.5 seconds
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2500);

    /*
    //STOPS for 1 second
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(10000);
    */

    //Turns right(1.075 seconds)
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1075);

    //Straight for 1 seconds
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(1000);

    //Turns left(1.075 seconds)
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(1075);

    //Straight for 1 seconds
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(1000);

    //Turns around 180 degrees
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(900);

    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(10000);


}