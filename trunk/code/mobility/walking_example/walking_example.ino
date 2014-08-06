#include <EEPROM.h>
#include "configServos.h"
#include <Servo.h>
#include <MYOD.h>
#include "prueba_exp.h"

enum configuracion {
  nouso=-1,NeckY=0,HipY,RShoulderR,LShoulderR,RShoulderP,LShoulderP,
  RElbowP,LElbowP,RHand,LHand,RLegY,LLegY,RLegR,LLegR,RLegP,LLegP,RKnee1,
  LKnee1,RKnee2,LKnee2,RAnkleP,LAnkleP,RAnkleR,LAnkleR,NeckP};
int port[Nmotor]={
  NECKY,HIPY,RSHOULDERR,LSHOULDERR,RSHOULDERP,LSHOULDERP,
  RELBOWP,LELBOWP,RHAND,LHAND,RLEGY,LLEGY,RLEGR,LLEGR,RLEGP,LLEGP,RKNEE1,
  LKNEE1,RKNEE2,LKNEE2,RANKLEP,LANKLEP,RANKLER,LANKLER,NECKP};

int trim[Nmotor];//={  -6,-9,3,-7,6,0,54,-44,-7,-3,8,3,5,-7,-5,0,0,0,7,2,6,0};
Robot myod;
byte b1, b2;

void setup(){
  for(int i=0 ; i< NeckP;i++){
    b1=EEPROM.read(i);
    b2=EEPROM.read(i+NeckP);
    trim[i]=((b1<<8)&0xFF00)+(b2&0xFF);
  }
  myod.trimming(trim);
  myod.attach(port);

}

void loop(){
 prueba();
}


