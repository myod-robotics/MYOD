/*
Proyect: Make Your Own Robot
Authors: Roberto Herrera, Rubén Vilches
8/2/14

*/


#include <MYOD.h>
#include <Servo.h>

int port[Nmotor]={2,3,4,5,6,7,8,9,10,11,
              12,13,22,24,26,28,30,32,34,36,
              38,40,42,44};
int trim[Nmotor]={0,0,0,0,0,0,0,0,0,0,
              0,-0,0,0,0,0,0,0,0,0,
              0,0,0,0};

//Robot myod;
Robot myod(trim);   //Constructor with trim

int oldPosition_test[Nmotor] = {10,10,170,12,23,34,25,67,12,103,10,10,170,12,23,34,45,67,12,23,70,20,20,20};
int newPosition_test[Nmotor] = {90,150,55,98,76,83,94,26,87,43,170,150,55,98,76,143,54,76,87,60,20,70,70,70};
int time = 500;
void setup(){
  Serial.begin(9600);
  myod.attach(port);
  myod.trimming(trim);
}
void loop(){
  myod.move(1.5*time, oldPosition_test);
  //delay(200);
  myod.move(time, newPosition_test);
  //delay(200);
  if(millis()%1000<150){ //new 
    myod.detach();
    Serial.println("Detached"); 
    delay(1000);
    //no move because servos aren't attached
    myod.move(time, oldPosition_test);
    myod.attach(port);
    Serial.println("Attached Again");
    
    //now its moving again
    myod.move(time, oldPosition_test);
    Serial.println(myod.readPos(11)); //pin13
    delay(1500);
    
    //moving one servo
    myod.moveOne(11,90);
    Serial.println(myod.readPos(11)); //pin13
    delay(1500);
    
    //moving one servo with offset
    myod.moveOffs(11,20);
    Serial.println(myod.readPos(11)); //pin13
    delay(1500);   
    myod.moveOffs(11,-40);
    delay(1500);
    Serial.println(myod.readPos(11)); //pin13
    //miving one servo with
    myod.moveOffsTime(100,11,40);
    delay(1500);
    Serial.println(myod.readPos(11)); //pin13
    
    myod.moveOneTime(1500,11,40);
    delay(1500);
    Serial.println(myod.readPos(11)); //pin13
    myod.moveOneTime(1500,11,-40); //this servo only can move to 10 because a limit angle 
    delay(1500);
    Serial.println(myod.readPos(11)); //pin13
    
    Serial.println("Restarting service....");
  }   
};
