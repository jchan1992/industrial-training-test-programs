unsigned int x = 0;
char a[4] = {0};
char i = 0;
char clearchar;
int j = 0;
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop(){
  if(Serial1.available()>0){
    for(i = 0;i<4;i++){
      j = Serial1.available();
      Serial.print("number of bytes = ");
      Serial.println(j);
      a[i] = Serial1.read();
      Serial.print("current byte is ");
      Serial.println(a[i]);
    }
      x = ((0xFF & a[0])<<24)|((0xFF & a[1])<<16)|((0xFF & a[2])<<8) | (0xFF & a[3]);
    Serial.print("int = ");
    Serial.println(x);
    Serial1.write(x);
  }
  while(Serial1.available()>0){
    clearchar = Serial1.read();
  }
  clearchar = 0;
  delay(100);
}
