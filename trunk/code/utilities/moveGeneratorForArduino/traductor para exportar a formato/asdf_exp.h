#ifndef ASDF_H
#define ASDF_H

extern Robot myod;
void asdf(){

int time_1 = 90;
int vector_1[24] = {90,90,90,90,90,90,90,90,90,90,90,30,90,90,90,90,90,90,90,90,90,90,90,90};
int time_2 = ;
int vector_2[24] = {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
int time_3 = ;
int vector_3[24] = {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
int time_4 = ;
int vector_4[24] = {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};


myod.move(time_1, vector_1);
myod.move(time_2, vector_2);
myod.move(time_3, vector_3);
myod.move(time_4, vector_4);

}

#endif