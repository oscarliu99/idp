#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  AFMS.begin();
  
  // Set the speed to start, from 30 (off) to 255 (max speed)

  //myMotor1->run(FORWARD);
  //myMotor2->run(FORWARD);
  // turn on motor
  //myMotor1->run(RELEASE);
  //myMotor2->run(RELEASE);
}

void loop() {
//    int state;
//  if (Serial.available()>0){
//    state = Serial.read();}
//  
//  if (int state == 1){
//  Serial.print("Hello World");
  int i;
  
  Serial.print("tick");
  //test motor forward
  myMotor1->setSpeed(50);
  myMotor2->setSpeed(52);
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  
  for (i=0; i<100; i++) {
    myMotor1->setSpeed(i);  
    myMotor2->setSpeed(i+2);
    delay(10);
  }
  for (i=100; i!=0; i--) {
    myMotor1->setSpeed(i); 
    myMotor2->setSpeed(i+2); 
    delay(10);
  }
  
  Serial.print("tock");
  //test motor backward
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  for (i=0; i<100; i++) {
    myMotor1->setSpeed(i);
    myMotor2->setSpeed(i+2); 
    delay(10);  }
    delay(5000);
  for (i=100; i!=0; i--) {
    myMotor1->setSpeed(i);
    myMotor1->setSpeed(i+2);    
    delay(10);
  }
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  delay(5000);
  //test turning to the right
  Serial.print("clockwise");
  myMotor1->setSpeed(50);
  myMotor2->setSpeed(52); 
  myMotor1->run(FORWARD);
  myMotor2->run(RELEASE);
  delay(5000);
  //test turning to the left
  Serial.print("anticlockwise");
  myMotor1->run(RELEASE);
  myMotor2->run(FORWARD);
  delay(5000);
  //Stop
  Serial.print("tech");
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  delay(1000);}
