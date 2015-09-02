#ifndef PASOLATERALDER_H
#define PASOLATERALDER_H

extern Robot myod;

void pasolateralder(){

/*-------CONFIG------
tiempo total: 1600
numero de pasos: 8
cadera: -28
rodilla: 12
avance: 0
cintura: 0
brazos avance: 0
brazos cadera: 0
*/
int inctime = 200;//200
int vector_1[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 91, 91, 90, 90, 90, 90, 90, 90, 90, 90, 91, 91, 90};
int vector_2[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 62, 82, 97, 90, 97, 90, 83, 90, 83, 90, 61, 81, 90};
int vector_3[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 62, 82, 144, 90, 114, 90, 66, 90, 66, 90, 61, 81, 90};
int vector_4[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 62, 82, 97, 90, 97, 90, 83, 90, 83, 90, 61, 81, 90};



int vector_5[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 91, 91, 90, 90, 90, 90, 90, 90, 90, 90, 91, 91, 90};
int vector_6[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 99, 99, 90, 83, 90, 83, 90, 97, 90, 97,101,101, 90};
int vector_7[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 99, 99, 90, 66, 90, 66, 90,114, 90,114,101,101, 90};
int vector_8[25] = { 90, 90, 155,30, 90, 90, 90, 90, 90, 90, 90, 90, 99, 99, 90, 83, 90, 83, 90, 97, 90, 97,101,101, 90};


myod.move(inctime, vector_1);
myod.move(inctime, vector_2);
myod.move(inctime, vector_3);
myod.move(inctime, vector_4);
myod.move(inctime, vector_5);
myod.move(inctime, vector_6);
myod.move(inctime, vector_7);
myod.move(inctime, vector_8);

}
#endif
