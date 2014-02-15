/*
 *Autor:Roberto Herrera Esteban
 *Fecha de creación: 2/2/14
 *Última modificación: 12/2/14
 *
 *Proyecto MYOD, Asrob, UC3M
 *
 *En esta libreria se incluyen las funciones que harán posible
 *la movilidad de un robot humanoide imprimible de bajo coste
 *
 *
 */
#ifndef MYOD
#define MYOD

#include <Arduino.h>
#include <Servo.h>


#define Nmotor 24 //num of motors

#define INTERVALTIME 5 //ms

#define MAXANG 170 //grad
#define MINANG 10  //grad


class Robot {
 private:
   Servo _motors[Nmotor];
   int _position[Nmotor];
   int _trim[Nmotor];
 public:
   /*Constructor sin trim*/
   Robot();
   /*Constructor con trim*/
   Robot(int trim[Nmotor]);
   //~Robot();
   /*Vincula los servos a cada GPIO*/
   void attach(int port[Nmotor]);
   /*Desvincula los servos*/
   void detach();
   /*Mueve los servos a la posición indicada en un tiempo determinado*/
   void move(int time, int newPosition[Nmotor]);
   /*Mueve un solo servo a la posición indicada a máxima velocidad*/
   void moveOne(int motor, int pos);
   /*Mueve un solo servo a la posición indicada en un tiempo determinado*/
   void moveOneTime(int time,int motor, int pos);
   /*Mueve todos los servos a una posición relativa de la actual en un tiempo determinado*/
   void moveOffs(int time, int offsPos[Nmotor]);
   /*Mueve un único servo a una posición relativa a máxima verlocidad*/
   void moveOffsOne(int motor, int inc);
   /*Mueve un único servo a una posición relativa en un tiempo determinado*/
   void moveOffsTime(int time,int motor, int inc);
   /*Devuelve la posición de un servo*/
   int readPos(int motor);
   /*Reajusta el trim del robot*/
   void trimming(int trim[Nmotor]);
   /*Función de inicio*/
   void inititalize(int pos[Nmotor]); //sin hacer
  private:
   /*Calcula la velocidad de movimiento*/
   float getGradeInrcrement(int time, int posI, int posF);
   /*Evita que el servo llegue a posiciones límite*/
   int compare(int pos);
};

#endif
