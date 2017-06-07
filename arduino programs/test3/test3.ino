/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
  myservo.write(pos);
  delay(10000);
} 
 
void loop() 
{ 
  
  for(pos = 0; pos <= 178; pos += 1) // goes from 0 degrees to 180 degrees 
  { 
    Serial.println(pos);    // in steps of 1 degree 
    myservo.write(pos);    // tell servo to go to position in variable 'pos' 
    delay(100);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  for(pos = 178; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  { 
    Serial.println(pos);    
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 
