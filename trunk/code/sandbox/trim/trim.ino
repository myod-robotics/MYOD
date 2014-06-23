#include <Servo.h>
#include <MYOD.h>
int port[Nmotor]={
  32,31,24,44,25,45,23,43,30,33,12,6,26,7,10,4,11,5,8,2,9,3};
  
//enum configuracion {nouso=-1,NeckY=0,HipY,RShoulderR,LShoulderR,RShoulderP,LShoulderP,
//                   RElbowP,LElbowP,RLegY,LLegY,RLegR,LLegR,RLegP,LLegP,RKnee1,LKnee1,RKnee2,LKnee2,RAnkleP,
//                   LAnkleP,RAnkleR,LAnkleR,NeckP};
//  
  
/*   Trim sin carga
int trim[Nmotor]={
  -6,-9,3,-7,6,0,54,-44,-5,0,18,-18,0,5,-2,-4,-2,-3,6,-2,-4,-28};
*/  
/*TRIM CARGA*/
int trim[Nmotor]={
  -6,-9,3,-7,6,0,54,-44,-7,-3,13,11,13,-7,1,0,-5,0,0,5,10,0};
int vector_1[22] = {
    90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};

int time, mov;

Robot myod(trim);

void setup(){
  myod.attach(port);
  //inicialize();
  //delay(3000);

}

void loop(){
  //cadera();
  myod.move(1000,vector_1);
  delay(5000);
}


