
char data;

void setup(){
  Serial.begin(115200);
}

void loop(){
  if(Serial.available()>0){
     data = Serial.read();
     Serial.println("printing...");
     Serial.println(data);
     Serial.println(data,HEX);
     Serial.println(data,BIN);
  }
}
    
