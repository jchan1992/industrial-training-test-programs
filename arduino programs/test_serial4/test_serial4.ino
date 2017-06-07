#include <TimerThree.h>


int greenPin = 5;
int redPin = 4;
int bluePin = 3;
int yellowPin = 2;
int stater = LOW;
int statey = LOW;
int stateb = LOW;
int stateg = LOW;
String rx;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  Timer3.initialize(10000);
  Timer3.attachInterrupt(timerIsr);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,LOW);
  digitalWrite(yellowPin,LOW);
  while(!Serial1){
    Serial.println("waiting for bluetooth");
  }
};

void loop(){
  if(Serial1.available()>0){
    rx = Serial1.readString();
    Serial1.println(rx);
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
      Serial1.print(stater);
      Serial1.print(statey);
      Serial1.print(stateb);
      Serial1.println(stateg);
    }
  }
}

void timerIsr(){
  Serial.print(digitalRead(bluePin));
  Serial.print(digitalRead(yellowPin));
  Serial.print(digitalRead(greenPin));
  Serial.println(digitalRead(redPin));
}
