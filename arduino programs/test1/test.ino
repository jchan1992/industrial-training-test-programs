void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}

char i;

void loop(){
  if(Serial1.available()>0){
    i = Serial1.read();
    Serial.println(i,HEX);
  }
}
