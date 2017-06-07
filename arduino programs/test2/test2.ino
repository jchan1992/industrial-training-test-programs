#include <Servo.h>

int potPin = A0;
int val = 0;
Servo myservo;

void setup(){
myservo.attach(3);
}

void loop(){
  val = analogRead(potPin);
  val = map(val,0,1023,0,179);
  myservo.write(val);
  delay(100);
}

  
