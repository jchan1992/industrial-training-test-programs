const long brate = 115200;
unsigned char tx[3];


void setup(){

   Serial.begin(brate,8E1);
   tx[0] = 0x80|0;

}

void loop(){
  
  for (int i = 3500; (3500 < i) && (i < 11500); i += 1000)
  {
     tx[1] = i >> 7 & 0x7F;
     tx[2] = i & 0x7F;
     Serial.write(tx[0]);

     Serial.write(tx[1]);

     Serial.write(tx[2]);

  }
    
}

