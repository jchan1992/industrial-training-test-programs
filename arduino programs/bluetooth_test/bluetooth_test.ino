#include <LiquidCrystal.h>

int ledPin = 13; 
int state = 0;
int flag = 0; 
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
 lcd.begin(16,2); 
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
 Serial.begin(9600); // Default connection rate for my BT module
 Serial.println("starting bluetooth");
//lcd.print("th module");
lcd.setCursor(0,0);
lcd.print("starting bluetoo");
lcd.setCursor(0,1);
lcd.print("th module");
}
 
void loop() {

 if(Serial.available() > 0){
 state = Serial.read();
 Serial.println(state);
 flag=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("waiting");
 }

 if (state == '0') {
 digitalWrite(ledPin, LOW);
   if(flag == 0){
     Serial.print("LED: off");
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("LED OFF");
     flag = 1;
   }
 }else if (state == '1') {
   digitalWrite(ledPin, HIGH);
   if(flag == 0){
     Serial.print("LED: on");
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("LED ON");
     flag = 1;
   }
 }else if(state == '2'){
   while(1){
    digitalWrite(ledPin,HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(100);
    //Serial.println(state);
    if(flag ==0){
      Serial.println("flashing");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("FLASHING");
      flag = 1;
    }
    if(Serial.available()>0){
      println(Serial.available);
      break;
    }
   }
 }    
}
