byte rx[4];
byte rxa;
byte got = 0b10101010;
int i = 0;
boolean flag = false;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop(){
  if(Serial1.available()>0){
   
    if(Serial1.read()==1){
      Serial1.write("GAY");
    }
  }
}



