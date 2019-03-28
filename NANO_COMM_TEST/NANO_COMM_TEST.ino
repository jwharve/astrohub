void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.println("RESTART");
}

void loop() {
  // put your main code here, to run repeatedly:
  char b;
  
  if (Serial.available() > 0)
  {
    b = Serial.read();
    if (b == 'a')
    {
      digitalWrite(LED_BUILTIN,HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN,LOW);
      delay(500);
    }
    else
    {
      digitalWrite(LED_BUILTIN,HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN,LOW);
      delay(500);
      digitalWrite(LED_BUILTIN,HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN,LOW);
      delay(500);
    }
    while(Serial.available() > 0)
    {
      b = Serial.read();
      Serial.print(b);
    }
  }
}
