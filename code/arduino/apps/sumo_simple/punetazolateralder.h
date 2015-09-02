#ifndef PUNETAZOLATERALDER_H
#define PUNETAZOLATERALDER_H

extern Robot myod;

void punetazolateralder(){
  

int time_1 = 200;
int vector_1[24] = {90,90,155,30,90,90,147,90,10,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
int time_2 =   200;
int vector_2[24] = {90,90,90,30,90,90,147,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
int time_3 =   400;
int vector_3[24] = {90,90,155,30,90,90,147,90,10,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};




myod.move(time_1, vector_1);
myod.move(time_2, vector_2);
delay(300);
myod.move(time_3, vector_3);


}
#endif
