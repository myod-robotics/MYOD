#ifndef SUICIDA_H
#define SUICIDA_H

extern Robot myod;

void suicida(){

int time_1 = 300;
int vector_1[24] = {90,90,165,15,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
int time_2 =   200;
int vector_2[24] = {90,90,165,15,90,90,90,90,90,90,90,90,90,90,110,70,110,70,70,110,70,110,90,90};
int time_3 =   300;
int vector_3[24] = {90,90,165,15,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,80,100,90,90};
int time_4 =   500;
int vector_4[24] = {90,90,20,170,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,80,100,90,90};
int time_5 =   200;
int vector_5[24] = {90,90,20,170,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,60,120,90,90};


myod.move(time_1, vector_1);
myod.move(time_2, vector_2);
myod.move(time_3, vector_3);
myod.move(time_4, vector_4);
myod.move(time_5, vector_5);

}
#endif
