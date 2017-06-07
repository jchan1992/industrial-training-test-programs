#include <TimerThree.h>
#include <Servo.h>

Servo myServo;
const int greenPin = 5;
const int redPin = 4;
const int bluePin = 3;
const int yellowPin = 2;
const int servoPin = 6;
int stater = LOW;
int statey = LOW;
int stateb = LOW;
int stateg = LOW;
String rx;
int motorpos = 90;

boolean isValidNumber(String str);

void setup(){
  Serial.begin(9600);
  Timer3.initialize(500000);
  Timer3.attachInterrupt(timerIsr);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,LOW);
  digitalWrite(yellowPin,LOW);
  myServo.attach(servoPin);
  myServo.write(motorpos);

};

void loop(){
  if(Serial.available()>0){
    rx = Serial.readString();
    Serial1.println(rx);
    if(isValidNumber(rx)==true){
      motorpos = rx.toInt();
      motorpos = abs(motorpos%179);
      Serial.println(motorpos);
      myServo.write(motorpos); 
    }else{
      if(rx == "green"){       
          if(stateg == HIGH){
            stateg = LOW;
          }else{
            stateg = HIGH;
          }
          digitalWrite(greenPin,stateg);
      }else if(rx == "red"){
          if(stater == HIGH){
            stater = LOW;
          }else{
            stater = HIGH;
          }  
          digitalWrite(redPin,stater);
      }else if(rx == "blue"){
          if(stateb == HIGH){
            stateb = LOW;
          }else{
            stateb = HIGH;
          }  
          digitalWrite(bluePin,stateb);
      }else if(rx == "yellow"){
          if(statey == HIGH){
            statey = LOW;
          }else{
            statey = HIGH;
          }
          digitalWrite(yellowPin,statey);
      }else if(rx =="get"){
        Serial.print(stateb);
        Serial.print(stateg);
        Serial.print(stater);
        Serial.print(statey);
        Serial.print("\t");
        Serial.print(motorpos);
        Serial.print("\n");
      }else{
        Serial.print("invalid input");
      }
    }
  }
}

void timerIsr(){
        Serial.print(stateb);
        Serial.print(stateg);
        Serial.print(stater);
        Serial.print(statey);
        Serial.print("\t");
        Serial.print(motorpos);
        Serial.print("\n");
}

boolean isValidNumber(String str){
   boolean isNum=false;
   for(byte i=0;i<str.length();i++)
   {
       isNum = isDigit(str.charAt(i)) || str.charAt(i) == '+' || str.charAt(i) == '.' || str.charAt(i) == '-';
       if(!isNum) return false;
   }
   return isNum;
}
