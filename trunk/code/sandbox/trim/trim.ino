#include <Servo.h>
#include <MYOD.h>
int port[Nmotor]={
  32,31,24,44,25,45,23,43,30,33,12,6,26,7,10,4,11,5,8,2,9,3};
  

  
  
/*   Trim sin carga
int trim[Nmotor]={
  -6,-9,3,-7,6,0,54,-44,-5,0,18,-18,0,5,-2,-4,-2,-3,6,-2,-4,-28};
*/  
/*TRIM CARGA*/
int trim[Nmotor]={
  -6,-9,3,-7,6,0,54,-44,-3,-5,32,9,3,-6,-2,-4,-2,2,2,0,-5,2};
  
  
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


