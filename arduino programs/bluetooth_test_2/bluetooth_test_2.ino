int state = 0;

void setup(){
  Serial.begin(115200);
  Serial.println("Starting bluetooth");
  Serial1.begin(115200);
}

void loop(){
//  if(Serial1.available()>0){
//    state = Serial1.read();
//    Serial.println(state);
//    Serial1.write(state);
//    delay(1000);
//  }
    if(Serial1.available()>0){
    state = Serial1.read();
    Serial.println(state);
    Serial1.write(state);

  }

}

