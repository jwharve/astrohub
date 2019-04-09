#include <Servo.h>
#include <HCSR04.h>

// open and close angles
#define OPEN 20
#define CLOSE 180

#define COLLECT 0
#define NOT_COLLECT 180

// servo pins
#define SERVO_1 9
#define SERVO_2 10
#define SERVO_3 11
#define COLLECTION 3

// distance sensor pins
#define TRIG_1 2
#define TRIG_2 5
#define TRIG_3 7

#define ECHO_1 4
#define ECHO_2 6
#define ECHO_3 8

// stepper pins
#define FR_STEP A0
#define FL_STEP A1
#define BR_STEP A2
#define BL_STEP A3
#define DIR A4
#define ENABLE A5

// breakbeam pin
#define BREAK A6




#define UNBROKEN 0

#define ELEVATOR_STEPS 1450
#define DROP_STEPS 225

#define GOOD 'c'
#define BAD 'n'

// cases
#define S1 'a'
#define S2 'b'
#define S3 'c'
#define D1 'd'
#define D2 'e'
#define D3 'f'
#define RF 'g'
#define CF 'h'
#define CB 'i'
#define CL 'j'
#define CR 'k'

char incomingChar = 0;
double distance = 0;

// declare servos
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Collection;

// declare sensors
UltraSonicDistanceSensor Sensor1(TRIG_1,ECHO_1);
UltraSonicDistanceSensor Sensor2(TRIG_2,ECHO_2);
UltraSonicDistanceSensor Sensor3(TRIG_3,ECHO_3);

void up(void);
void down(void);
void downFull(void);
void dropFront(void);
void dropBack(void);
void dropLeft(void);
void dropRight(void);
void upSome(void);

void setup()
{
  // set up serial port
  Serial.begin(9600);

  // pinmodes for stepper
  pinMode(FR_STEP, OUTPUT);
  pinMode(FL_STEP, OUTPUT);
  pinMode(BR_STEP, OUTPUT);
  pinMode(BL_STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(BREAK, INPUT_PULLUP);
  pinMode(ENABLE, OUTPUT);
  digitalWrite(ENABLE,HIGH);
  

  // set up servo pins
  Servo1.attach(SERVO_1);
  Servo2.attach(SERVO_2);
  Servo3.attach(SERVO_3);
  Collection.attach(COLLECTION);

  Servo1.write(CLOSE);
  Servo2.write(OPEN);
  Servo3.write(CLOSE);
  Collection.write(NOT_COLLECT);
}

void loop()
{
  int i;

  if (Serial.available() >0)
  {
    // read character
    incomingChar = Serial.read();

    switch (incomingChar)
    {
        case S1:
          // move servo 1
          Servo1.write(OPEN);
          delay(3000);
          Servo1.write(CLOSE);
          break;
        case S2:
          // move servo 2
          Servo2.write(CLOSE);
          delay(3000);
          Servo2.write(OPEN);
          break;
        case S3:
          // move servo 3
          Servo3.write(OPEN);
          delay(3000);
          Servo3.write(CLOSE);
          break;
        case D1:
          // read distance sensor 1
          distance = Sensor1.measureDistanceCm();
          Serial.println(distance);
          break;
        case D2:
          // read distance sensor 2
          distance = Sensor2.measureDistanceCm();
          Serial.println(distance);
          break;
        case D3:
          // read distance sensor 3
          distance = Sensor3.measureDistanceCm();
          Serial.println(distance);
          break;
        case RF:
          // raise flag
          Servo3.write(90);
          delay(3000);
          Servo3.write(CLOSE);
          break;

        
        case CF: 
          // Collect Front
          downFull();
          for (i = 0; (i < 3) && (digitalRead(BREAK) == UNBROKEN); i ++)
          {
            Collection.write(COLLECT);
            delay(1000);
            Collection.write(NOT_COLLECT);
            delay(500);
          }
          digitalWrite(ENABLE,LOW);
          if (digitalRead(BREAK) != UNBROKEN)
          {
            Serial.println(GOOD);
          }
          else
          {
            Serial.println(BAD);
            upSome();
            digitalWrite(ENABLE,HIGH);
            break;
          }
          up();
          dropFront();
          down();
          digitalWrite(ENABLE,HIGH);
          break;
        case CB: 
          // Collect Back
          downFull();
          for (i = 0; (i < 3) && (digitalRead(BREAK) == UNBROKEN); i ++)
          {
            Collection.write(COLLECT);
            delay(1000);
            Collection.write(NOT_COLLECT);
            delay(500);
          }
          digitalWrite(ENABLE,LOW);
          if (digitalRead(BREAK) != UNBROKEN)
          {
            Serial.println(GOOD);
          }
          else
          {
            Serial.println(BAD);
            upSome();
            digitalWrite(ENABLE,HIGH);
            break;
          }
          up();
          dropBack();
          down();
          digitalWrite(ENABLE,HIGH);
          break;
        case CL: 
          // Collect Left
          downFull();
          for (i = 0; (i < 3) && (digitalRead(BREAK) == UNBROKEN); i ++)
          {
            Collection.write(COLLECT);
            delay(1000);
            Collection.write(NOT_COLLECT);
            delay(500);
          }
          digitalWrite(ENABLE,LOW);
          if (digitalRead(BREAK) != UNBROKEN)
          {
            Serial.println(GOOD);
          }
          else
          {
            Serial.println(BAD);
            upSome();
            digitalWrite(ENABLE,HIGH);
            break;
          }
          up();
          dropLeft();
          down();
          digitalWrite(ENABLE,HIGH);
          break;
        case CR: 
          // Collect Right
          downFull();
          for (i = 0; (i < 3) && (digitalRead(BREAK) == UNBROKEN); i ++)
          {
            Collection.write(COLLECT);
            delay(1000);
            Collection.write(NOT_COLLECT);
            delay(500);
          }
          digitalWrite(ENABLE,LOW);
          if (digitalRead(BREAK) != UNBROKEN)
          {
            Serial.println(GOOD);
          }
          else
          {
            Serial.println(BAD);
            upSome();
            digitalWrite(ENABLE,HIGH);
            break;
          }
          up();
          dropRight();
          down();
          digitalWrite(ENABLE,HIGH);
          break;
    }
    distance = 0;
  }
}

void up()
{
  int i;
  digitalWrite(DIR,HIGH);
  for (i = 0; i < ELEVATOR_STEPS; i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
  }
}

void down(void)
{
  int i;
  digitalWrite(DIR,LOW);
  for (i = 0; i < 3*ELEVATOR_STEPS/4; i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
  }
}

void downFull(void)
{
  int i;
  digitalWrite(DIR,LOW);
  for (i = 0; i < (ELEVATOR_STEPS - 3*ELEVATOR_STEPS/4); i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
  }  
}

void dropFront(void)
{
  int i;
  digitalWrite(DIR,HIGH);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    delay(1);
  }
  digitalWrite(DIR,LOW);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    delay(1);
  }
}

void dropBack(void)
{
  int i;
  digitalWrite(DIR,HIGH);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
    digitalWrite(FR_STEP,LOW);
    digitalWrite(FL_STEP,LOW);
    delay(1);
  }
  digitalWrite(DIR,LOW);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
    digitalWrite(FR_STEP,LOW);
    digitalWrite(FL_STEP,LOW);
    delay(1);
  }
}

void dropLeft(void)
{
  int i;
  digitalWrite(DIR,HIGH);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(FR_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(FR_STEP,LOW);
    delay(1);
  }
  digitalWrite(DIR,LOW);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(FR_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(FR_STEP,LOW);
    delay(1);
  }
}

void dropRight(void)
{
  int i;
  digitalWrite(DIR,HIGH);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(FL_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    delay(1);
    digitalWrite(FL_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    delay(1);
  }
  digitalWrite(DIR,LOW);
  for (i = 0; i < DROP_STEPS; i++)
  {
    digitalWrite(FL_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    delay(1);
    digitalWrite(FL_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    delay(1);
  }
}

void upSome(void)
{
  int i;
  digitalWrite(DIR,HIGH);
  for (i = 0; i < (ELEVATOR_STEPS - 3*ELEVATOR_STEPS/4); i++)
  {
    digitalWrite(BR_STEP,HIGH);
    digitalWrite(BL_STEP,HIGH);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
    digitalWrite(BR_STEP,LOW);
    digitalWrite(BL_STEP,LOW);
    digitalWrite(FR_STEP,HIGH);
    digitalWrite(FL_STEP,HIGH);
    delay(1);
  }
}

