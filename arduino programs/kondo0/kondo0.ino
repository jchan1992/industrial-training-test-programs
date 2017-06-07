//set id number for motors;
const int id1 = 0x0;
const int id2 = 0x1;
//record position for motors;
unsigned char pos1 = 0;
unsigned char pos2 = 0;
//record current values for motors;
int cur1;
int cur2;
// code received from pc; 0 = on spot; 1 = below;2 = above...
int state;
// rx and tx values for each motor

unsigned char rx1[5];
unsigned char rx2[5];
unsigned char tx1[3];
unsigned char tx2[3];
unsigned char txc1[2];
unsigned char txc2[2];
int i = 0;

void setup(){
  //initiate serial communications
  Serial1.begin(115200);//bluetooth module communication to pc
  Serial2.begin(115200);//motor 1
  Serial3.begin(115200);//motor 2
  Serial1.write("starting bluetooth module: waiting for data...");
  
}

void loop(){
//check for bluetooth; read command;
  if(Serial1.available()){
    state = Serial1.read();
  }
  
  if (Serial2.available() && Serial3.available()){
      if (state =='0'){
        //do nothing   
      }else if (state=='1'){
        //beam is below line, move motors up
        // set new pos for each motor
        pos1 = pos1++;
        pos2 = pos2--; 
        //encode pos1;
        tx1[0] = 0x80 | id1;
        tx1[1] = unsigned char(pos1 >> 7 & 127);
        tx1[2] = unsigned char(pos1 & 127);
        // encode pos2;
        tx1[0] = 0x80|id1;
        tx1[1] = unsigned char(pos1>>7&0x7F);
        tx1[2] = unsigned char(pos1 & 0x7F);
        //send pos data
        for(int i = 0;i<3,i++){
          Serial2.write(tx1[i];
          Serial3.write(tx2[i];  
        }
      }else if(state == '2'){
        //beam is above the line, move motors down
        // set new pos for each motor
        pos1 = pos1--;
        pos2 = pos2++; 
        //encode pos1;
        tx1[0] = 0x80|id2;
        tx1[1] = unsigned char(pos1>>7&0x7F);
        tx1[2] = unsigned char(pos1 & 0x7F)
        // encode pos2;
        tx1[0] = 0x80|id2;
        tx1[1] = unsigned char(pos1>>7&0x7F);
        tx1[2] = unsigned char(pos1 & 0x7F)
        //send pos data
        for(int i = 0;i<3,i++){
          Serial2.write(tx1[i];
          Serial3.write(tx2[i];  
        }
      }
      //send back current value
      unsigned char tx1[2];
        txc1[0] = 0x161 | id1;
        txc1[1] = 0x3;
        Serial2.write(tx1);  
        unsigned char rx1[5]
        for(i = 0; i <5;i++){
        Serial2.read(rx1[i]);
        cur1 = rx1[4];
        
        unsigned char tx2[2];
        txc2[0] = 0x161 | id2;
        txc2[1] = 0x3;
        Serial3.write(tx2);  
        unsigned char rx2[5]
        for(i = 0; i <5;i++){
        Serial3.read(rx2[i]);
        cur2 = rx2[4];
        //send back to pc
        cur[2] = {cur1,cur2};
        Serial1.write(cur);
  }
}
    
