/*
Adafruit Arduino - Lesson 16. Stepper
*/

#include <Stepper.h>
/*
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

Stepper motor(64, in1Pin, in2Pin, in3Pin, in4Pin);  */
const int steps = 1;
Stepper myStepper (64,8,9,10,11);
int val = 136;

void setup()
{
 /* pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  DDRB = 0xff;
  PORTB = val;
  val = val >> 1;
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  
  Serial.begin(9600);
 // motor.setSpeed(4);*/
 myStepper.setSpeed(32);
}

void loop()
{
  /*if (Serial.available())
  {
    int steps = Serial.parseInt();
  //  motor.step(steps);
  PORTB = steps;
    
  }*/
  myStepper.step(2048);
  //delay(1000);
}
