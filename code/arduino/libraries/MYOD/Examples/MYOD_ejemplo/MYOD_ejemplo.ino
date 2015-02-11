/*
Proyect: Make Your Own Robot Uc3m
Authors: Roberto Herrera, Rubén Vilches
8/2/14

*/
#include <MYOD.h>
#include <Servo.h>
#define Nmotor 24
int port[Nmotor]={2,3,4,5,6,7,8,9,10,11,
              12,13,22,24,26,28,30,32,34,36,
              38,40,42,44};

Robot myod;
int oldPosition_test[Nmotor] = {10,10,170,12,23,34,25,67,12,103,10,10,170,12,23,34,45,67,12,23,70,20,20,20};
int newPosition_test[Nmotor] = {90,150,55,98,76,83,94,26,87,43,170,150,55,98,76,143,54,76,87,60,20,70,70,70};
int time = 500;
void setup(){
  myod.attach(port);
}
void loop(){
  myod.move(time, oldPosition_test);
  //delay(200);
  myod.move(time, newPosition_test);
  //delay(200);
};
