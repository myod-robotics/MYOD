#ifndef IDLE_H
#define IDLE_H

extern Robot myod;

void idle(){

/*-------CONFIG------
tiempo total: 1200
numero de pasos: 20
cadera: 27
rodilla: 12
avance: 10
cintura: 4
brazos avance: 16
brazos cadera: 0
*/
int inctime = 200;
int vector_1[25] = { 86, 86,155, 35, 82, 66, 90, 90, 90, 90, 94, 94, 89, 89, 93, 93, 90, 90, 90, 90, 93, 93, 89, 89, 90};

myod.move(inctime, vector_1);


}
#endif
