
char tx[3];
int i = 0;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2(115200,SERIAL_8E1);
}

void loop(){
  if(Serial1.available()>0){
     for(i = 0;i<3;i++){
       tx[i] = Serial1.read();
       Serial2.write(tx[i];
     }
  }
}
