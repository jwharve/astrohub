#include <Servo.h>
#include <HCSR04.h>

// open and close angles
#define OPEN 0
#define CLOSE 180

// servo pins
#define SERVO_1 9
#define SERVO_2 10
#define SERVO_3 11

// distance sensor pins
#define TRIG_1 3
#define TRIG_2 5
#define TRIG_3 7

#define ECHO_1 4
#define ECHO_2 6
#define ECHO_3 8

char incomingChar = 0;
double distance = 0;

// declare servos
Servo Servo1;
Servo Servo2;
Servo Servo3;

// declare sensors
UltraSonicDistanceSensor Sensor1(TRIG_1,ECHO_1);
UltraSonicDistanceSensor Sensor2(TRIG_2,ECHO_2);
UltraSonicDistanceSensor Sensor3(TRIG_3,ECHO_3);

void setup()
{
  // set up serial port
  Serial.begin(9600);

  // set up servo pins
  Servo1.attach(SERVO_1);
  Servo2.attach(SERVO_2);
  Servo3.attach(SERVO_3);
}

void loop()
{

  if (Serial.available() >0)
  {
    // read character
    incomingChar = Serial.read();

    switch (incomingChar)
    {
        case 'a':
          // move servo 1
          Servo1.write(OPEN);
          delay(3000);
          Servo1.write(CLOSE);
          break;
        case 'b':
          // move servo 2
          Servo2.write(OPEN);
          delay(3000);
          Servo2.write(CLOSE);
          break;
        case 'c':
          // move servo 3
          Servo3.write(OPEN);
          delay(3000);
          Servo3.write(CLOSE);
          break;
        case 'd':
          // read distance sensor 1
          distance = Sensor1.measureDistanceCm();
          Serial.println(distance);
          break;
        case 'e':
          // read distance sensor 2
          distance = Sensor2.measureDistanceCm();
          Serial.println(distance);
          break;
        case 'f':
          // read distance sensor 3
          distance = Sensor3.measureDistanceCm();
          Serial.println(distance);
          break;
    }  
    distance = 0;
  }
}
