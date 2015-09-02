#ifndef GIRODERECHA_H
#define GIRODERECHA_H

extern Robot myod;

void giroDerecha(){

int time_1 = 300;
int vector_1[25] = {90,90,150,40,90,90,90,90,90,90,90,90,90,90,120,60,120,60,    60,120,  60,120,90,90,90};
int time_2 =   300;
int vector_2[25] = {90,90,150,40,90,90,90,90,90,90,120,90,80,100,120,60,120,60,  60,120,  60,120,80,80,90};
int time_3 =   300;
int vector_3[25] = {90,90,150,40,130,50,90,90,90,90,90,90,90,90,120,60,120,60,   60,120,  60,120,90,90,90};
int time_4 =   800;
int vector_4[25] = {90,90,150,40,90,90,90,90,90,90,90,90,90,90,90,90,90,90,      90,90,  90,90,90,90,90};

myod.move(time_4, vector_4);
myod.move(time_1, vector_1);
myod.move(time_2, vector_2);
myod.move(time_3, vector_3);
myod.move(time_4, vector_4);
myod.move(500, vector_4);
}
#endif
