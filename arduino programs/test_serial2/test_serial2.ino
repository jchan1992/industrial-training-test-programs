unsigned int x = 0;
char bytes;
char a[4];
char i =0;
char j = 0;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop(){
  if(Serial1.available()>0){
    Serial.println("available data");
    Serial1.readBytes(a,4);
    for(i=0;i<4;i++){
      Serial.print("ascii ");
      Serial.println(a[i]);
      Serial.print("binary ");
      Serial.println(a[i],BIN);
      Serial.print("decimal ");
      Serial.println(a[i],DEC);
      Serial.print("hex ");
      Serial.println(a[i],HEX);
    }
    x = (0xFF & a[0])<<24|(0xFF &a[1])<<16;
    Serial.print("int = ");
    Serial.println(x);
    Serial.println(x,BIN);
    x = (0xFF& a[1])<<16;
    Serial.print("int = ");
    Serial.println(x);
    Serial.println(x,BIN);
  }  
}
  
