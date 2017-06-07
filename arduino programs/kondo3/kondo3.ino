//set baud rate 
const int brate = 9600;
//set angle range
const double minAngle = 3500;
const double maxAngle = 11500;
//set id number for motors;
const int id1 = 0x0;
const int id2 = 0x1;

//record current values for motors;
int cur1 =0;
int cur2 =0;
// see if angle is received or not
boolean gotAngle = false;
// rx and tx values for each motor
int angle = 7500;
int prevAngle = 7500;
unsigned char rxc1[5];
unsigned char rxc2[5];
unsigned char txp1[3];
unsigned char txp2[3];
unsigned char txc1[2];
unsigned char txc2[2];
int i = 0;

void setup(){
  gotAngle = false;
  //initiate serial communications
  Serial.begin(brate);//arduino communication for monitoring
  Serial1.begin(brate);//bluetooth module communication to pc
  Serial2.begin(brate);//motor 1
  Serial3.begin(brate);//motor 2
  while(!Serial){
    Serial.println("wtf this should not happen");
  }
  Serial.println("communication to pc established");
  while(!Serial1){
    Serial.println("waiting for bluetooth connection");  
  }
  Serial.println("communication to bluetooth established");
  Serial1.println("communication to bluetooth established");
//commented for testing  
/*while(!Serial3 && !Serial2){
    Serial.println("no motors connected, please wait")
  Serial.println("servos connected, ready for use");*/
}


void loop(){
  //get count from qt
  if(!gotAngle){
    angle = Serial1.parseInt();
    gotAngle = !gotAngle;
    if(angle < minAngle || angle > maxAngle){
      Serial.print(angle);
      Serial.println(" you fucktard this is invalid"); 
    }else{
      Serial.print(angle);
      Serial.println(" is valid");
      if(angle == 7500){
         Serial.println("no adjustments need to be made");
      }else{
         Serial.print("converting "); 
         Serial.println(angle);
      }
         
      
    }
    
  }
  gotAngle = !gotAngle;
  
  




}
