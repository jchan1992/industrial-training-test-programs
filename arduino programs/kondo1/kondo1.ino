//set baud rate 
const int brate = 9600;
//set id number for motors;
const int id1 = 0x0;
const int id2 = 0x1;
//record position for motors;
unsigned char pos1 = 0;
unsigned char pos2 = 0;
//record current values for motors;
int cur1 =0;
int cur2 =0;
// code received from pc; 0 = on spot; 1 = below;2 = above...
int state;
// rx and tx values for each motor
unsigned char rxc1[5];
unsigned char rxc2[5];
unsigned char txp1[3];
unsigned char txp2[3];
unsigned char txc1[2];
unsigned char txc2[2];
int i = 0;

void setup(){
  //initiate serial communications
  Serial.begin(brate);//arduino communication for monitoring
  Serial1.begin(brate);//bluetooth module communication to pc
  Serial2.begin(brate);//motor 1
  Serial3.begin(brate);//motor 2
}

void loop(){
//check for bluetooth; read command;
  if(Serial1.available()>0){
    Serial1.write("bt ready");
    state = Serial1.read();
  //check for motors 1 and 2
  //if (Serial2.available() && Serial3.available()){
    //Serial1.write("motors 1 and 2 available");
      switch(state){
        case '0':
        //do nothing   
        Serial1.write("state = 0");
        break;
        case '1':
        //beam is below line, move motors up
        // set new pos for each motor
        Serial1.write("state = 1");
        pos1 = pos1++;
        pos2 = pos2--; 
        //encode pos1;
        txp1[0] = 0x80 | id1;
        txp1[1] = pos1 >> 7 & 127;
        txp1[2] = pos1 & 127;
        // encode pos2;
        txp2[0] = 0x80|id1;
        txp2[1] = pos1>>7&0x7F;
        txp2[2] = pos1 & 0x7F;
        //send pos data
        for(i = 0;i<3;i++){
          Serial2.write(txp1[i]);
          Serial3.write(txp2[i]);  
        }
        break;
      case '2':
        //beam is above the line, move motors down
        // set new pos for each motor
        Serial1.write("state = 2");
        pos1 = pos1--;
        pos2 = pos2++; 
        //encode pos1;
        txp1[0] = 0x80|id2;
        txp1[1] = pos1>>7&0x7F;
        txp1[2] = pos1 & 0x7F;
        // encode pos2;
        txp2[0] = 0x80|id2;
        txp2[1] = pos1>>7&0x7F;
        txp2[2] = pos1 & 0x7F;
        //send pos data
        for(i = 0;i<3;i++){
          Serial2.write(txp1[i]);
          Serial3.write(txp2[i]);  
        }
        break;
      default:
        Serial1.write("invalid");
        break;
      }
      
      
      //send back current value for motor 1
      txc1[0] = 0x161 | id1;
      txc1[1] = 0x3;
      for(i = 0; i< 2;i++){
        Serial2.write(txc1[i]);
      }  
      for(i = 0; i <5;i++){
        rxc1[i] = Serial2.read();
      }
      unsigned char cur1 = rxc1[4];
      
      //send back current value for motor 2  
      txc2[0] = 0x161 | id2;
      txc2[1] = 0x3;
      for(i = 0; i< 2;i++){
        Serial3.write(txc2[i]);
      }  
      for(i = 0; i <5;i++){
        rxc2[i] = Serial3.read();
      }
        unsigned char cur2 = rxc2[4];
      
      //send back to pc
        unsigned char cur[2] = {cur1,cur2};
        for(i = 0;i<2;i++){
          Serial1.write(cur[i]);
        }
    }
  }
    
