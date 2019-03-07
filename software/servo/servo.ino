#include <Servo.h>

#define OPEN 90
#define CLOSE 0
#define storage_a 1
#define storage_b 2
#define storage_c 3
#define claw 4

Servo Storage_a;
Servo Storage_b;
Servo Storage_c;
Servo Claw;

void setup() {
  Storage_a.attach(8);    // Color A Storage (D5)
  Storage_b.attach(9);    // Color B Storage (D6)
  Storage_c.attach(12);   // Color C Storage (D9)
  Claw.attach(6);

  Serial.begin(9600);
}

// DO NOT NEED THIS. (between the dotted lines)
//------------------------------------------------------------------------------
//        This is just a test case. Everything above is needed
//        and the "moveServo()" function is needed but not "void loop"
void loop() {
  int incomingByte;

  while (Serial.available() <= 0);
  while (Serial.available() > 0)
  {
    incomingByte = Serial.read();
  }
  moveServo(storage_c, OPEN);
  delay(1000);

  while (Serial.available() <= 0);
  while (Serial.available() > 0)
  {
    incomingByte = Serial.read();
  }
  moveServo(storage_c, CLOSE);
  delay(1000);
}
//--------------------------------------------------------------------------------

/*
    Purpose:
        This function allows for any servo to be called upon. Each can be opened,
        closed separately from everything else
*/
void moveServo(int servo, int pos){
      switch (servo){
        case 1:
          Storage_a.write(pos);
          delay(15);
          break;
        case 2:
          Storage_b.write(pos);
          delay(15);
          break;
        case 3:
          Storage_c.write(pos);
          delay(15);
          break;
        case 4:
          Claw.write(pos);
          delay(15);
          break;
      }
}
