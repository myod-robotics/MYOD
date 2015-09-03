#ifndef QWER_H
#define QWER_H

extern Robot qwer;

void qwer(){

/*-------CONFIG------
tiempo total: 1000
numero de pasos: 20
cadera: 11
rodilla: 1
avance: 1
cintura: 1
brazos avance: 1
brazos cadera: 0
*/
int inctime = 50;
int vector_1[22] = { 90, 89, 89, 89, 89, 89, 91, 89, 89, 91, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89};
int vector_2[22] = { 90, 89, 89, 89, 89, 89, 91, 89, 89, 91, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89};
int vector_3[22] = { 90, 89, 89, 89, 89, 89, 91, 89, 89, 91, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89};
int vector_4[22] = { 90, 89, 89, 89, 89, 89, 91, 89, 89, 91, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89};
int vector_5[22] = { 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int vector_6[22] = { 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int vector_7[22] = { 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int vector_8[22] = { 90, 91, 91, 91, 91, 91, 89, 91, 91, 89, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
int vector_9[22] = { 90, 91, 91, 91, 91, 91, 89, 91, 91, 89, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
int vector_10[22] = { 90, 91, 91, 91, 91, 91, 89, 91, 91, 89, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
int vector_11[22] = { 90, 91, 91, 91, 91, 91, 89, 91, 91, 89, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
int vector_12[22] = { 90, 91, 91, 91, 91, 91, 89, 91, 91, 89, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
int vector_13[22] = { 90, 91, 91, 91, 91, 91, 89, 91, 91, 89, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
int vector_14[22] = { 90, 91, 91, 91, 91, 91, 89, 91, 91, 89, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
int vector_15[22] = { 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int vector_16[22] = { 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int vector_17[22] = { 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int vector_18[22] = { 90, 89, 89, 89, 89, 89, 91, 89, 89, 91, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89};
int vector_19[22] = { 90, 89, 89, 89, 89, 89, 91, 89, 89, 91, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89};
int vector_20[22] = { 90, 89, 89, 89, 89, 89, 91, 89, 89, 91, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89};


qwer.move(inctime, vector_1);
qwer.move(inctime, vector_2);
qwer.move(inctime, vector_3);
qwer.move(inctime, vector_4);
qwer.move(inctime, vector_5);
qwer.move(inctime, vector_6);
qwer.move(inctime, vector_7);
qwer.move(inctime, vector_8);
qwer.move(inctime, vector_9);
qwer.move(inctime, vector_10);
qwer.move(inctime, vector_11);
qwer.move(inctime, vector_12);
qwer.move(inctime, vector_13);
qwer.move(inctime, vector_14);
qwer.move(inctime, vector_15);
qwer.move(inctime, vector_16);
qwer.move(inctime, vector_17);
qwer.move(inctime, vector_18);
qwer.move(inctime, vector_19);
qwer.move(inctime, vector_20);

}
#endif
