#ifndef MYOD
#define MYOD

#include <Arduino.h>
#include <Servo.h>


#define Nmotor 24 //num of motors

#define INTERVALTIME 5 //ms

#define MAXANG 170
#define MINANG 10


class Robot {
 private:
   Servo _motors[Nmotor];
   int _position[Nmotor];
   int _trim[Nmotor];
 public:
   Robot();
   Robot(int trim[Nmotor]);
   //~Robot();
   void attach(int port[Nmotor]);
   void detach();
   void move(int time, int newPosition[Nmotor]);
   void moveOne(int motor, int pos);
   void moveOneTime(int time,int motor, int pos);
   void moveOffs(int motor, int inc);
   void moveOffsTime(int time,int motor, int inc);
   int readPos(int motor);
   void trimming(int trim[Nmotor]);
   void inititalize(int pos[Nmotor]); //sin hacer
  private:
   float getGradeInrcrement(int time, int posI, int posF);
   int compare(int pos);
};

#endif
