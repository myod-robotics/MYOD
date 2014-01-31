#ifndef MYOD
#define MYOD

#include <Arduino.h>
#include <Servo.h>


#define Nmotor 24 //num of motors

#define INTERVALTIME 10 //ms

class Robot {
 private:
   Servo _motors[Nmotor];
   int _position[Nmotor];
 public:
   Robot();
   Robot(int port[Nmotor]);
   //~Robot();
   void attach(int port[Nmotor]);
   void Move(int time, int newPosition[Nmotor]);
   void MoveOne(int motor, int pos);
   float getGradeInrcrement(int time, int posI, int posF);
   int read(int n);

};

#endif
