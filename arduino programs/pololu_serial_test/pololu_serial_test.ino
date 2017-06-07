byte tx[3];

void setup(){
  Serial.begin(115200);
  Serial1.begin(115200,SERIAL_8E1);
  Serial2.begin(9600);
}

void loop(){
//  if(Serial2.available()>0){
//    for(int i = 0;i<3;i++){
//      tx[i] = Serial2.read();
//      Serial1.write(tx[i]);
//    }
if(Serial.available()>0){
  //Serial.println("receiving data");
    for(int i = 0;i<3;i++){
      tx[i] = Serial.read();
      //Serial.println(tx[i]);
      Serial1.write(tx[i]);
    }
  }
}
