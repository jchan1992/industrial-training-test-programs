int x = 0;
int a[4] = 0;
int i = 0;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop(){
  if(Serial1.available()>0){
    for(i = 0;,i<3;i++){
      a[i] = Serial1.read();
    }
  }
  for(i = 0;i<3;i++){
    x |= (0xFF&a[i])<<8*(3-i);
  }
  
  Serial.print("int = ");
  Serial.println(x);
}
