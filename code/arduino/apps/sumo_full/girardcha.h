#ifndef PRUEBA_H
#define PRUEBA_H


#define param 10
extern Robot myod;

void prueba(){

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
int inctime = 90;
int vector_1[25] = { 86, 86,155, 35, 90, 80, 90, 90, 90, 90, 94, 92, 89, 89, 93, 93, 90, 90, 90, 90, 93, 93, 89, 89, 90};
int vector_2[25] = { 86, 86,155, 35, 87, 75, 90, 90, 90, 90, 94, 92, 93, 93, 93, 93, 90, 90, 90, 90, 93, 93, 94, 94, 90};
int vector_3[25] = { 87, 87,155, 35, 85, 69, 90, 90, 90, 90, 94, 91, 97, 97, 92, 89, 90, 87, 90, 93, 92, 95, 98, 98, 90};
int vector_4[25] = { 88, 88,155, 35, 89, 73, 90, 90, 90, 90, 93, 91, 97, 97, 91, 80, 90, 79, 90,101, 91,102, 98, 98, 90};
int vector_5[25] = { 89, 89,155, 35, 93, 77, 90, 90, 90, 90, 93, 91, 97, 97, 90, 70, 90, 70, 90,110, 90,110, 95, 98, 90};
int vector_6[25] = { 90, 90,155, 35, 98, 82, 90, 90, 90, 90, 92, 90, 97, 97, 89, 65, 90, 66, 90,114, 89,113, 94, 98, 90};
int vector_7[25] = { 91, 91,155, 35,100, 87, 90, 90, 90, 90, 92, 90, 97, 97, 88, 68, 90, 70, 90,110, 88,108, 93, 98, 90};
int vector_8[25] = { 92, 92,155, 35,102, 91, 90, 90, 90, 90, 91, 90, 97, 97, 87, 76, 90, 79, 90,101, 87, 98, 91, 98, 90};
int vector_9[25] = { 93, 93,155, 35,102, 95, 90, 90, 90, 90, 91, 90, 97, 97, 87, 84, 90, 87, 90, 93, 87, 90, 90, 98, 90};
int vector_10[25] = { 94, 94,155, 35,102, 90, 90, 90, 90, 90, 90, 90, 93, 93, 87, 87, 90, 90, 90, 90, 87, 87, 90, 94, 90};
int vector_11[25] = { 94, 94,155, 35,114, 98, 90, 90, 90, 90, 86, 86, 89, 89, 87, 87, 90, 90, 90, 90, 87, 87, 89, 89, 90};
int vector_12[25] = { 94, 94,155, 35,113, 97, 90, 90, 90, 90, 86, 86, 85, 85, 87, 87, 90, 90, 90, 90, 87, 87, 84, 84, 90};
int vector_13[25] = { 93, 93,155, 35,111, 95, 90, 90, 90, 90, 87, 87, 81, 81, 90, 87, 93, 90, 87, 90, 84, 87, 80, 80, 90};
int vector_14[25] = { 92, 92,155, 35,107, 91, 90, 90, 90, 90, 88, 88, 81, 81, 99, 88,101, 90, 79, 90, 77, 88, 79, 79, 90};
int vector_15[25] = { 91, 91,155, 35,103, 87, 90, 90, 90, 90, 89, 89, 81, 81,109, 89,110, 90, 70, 90, 69, 89, 79, 79, 90};
int vector_16[25] = { 90, 90,155, 35, 98, 82, 90, 90, 90, 90, 90, 90, 81, 81,114, 90,114, 90, 66, 90, 66, 90, 79, 79, 90};
int vector_17[25] = { 89, 89,155, 35, 93, 77, 90, 90, 90, 90, 91, 91, 81, 81,111, 91,110, 90, 70, 90, 71, 91, 79, 79, 90};
int vector_18[25] = { 88, 88,155, 35, 89, 73, 90, 90, 90, 90, 92, 92, 81, 81,103, 92,101, 90, 79, 90, 81, 92, 79, 79, 90};
int vector_19[25] = { 87, 87,155, 35, 85, 69, 90, 90, 90, 90, 93, 93, 81, 81, 96, 93, 93, 90, 87, 90, 90, 93, 80, 80, 90};

int vector_20[25] = { 86, 86,155, 35, 83, 67, 90, 90, 90, 90, 94, 94, 85, 85, 93, 93, 90, 90, 90, 90, 93, 93, 84, 84, 90};
/*
int vector_maravillas[25] = {0,0,0,0,0,  0,0,0,0,0  ,0,0,0,0,  param,-param,param,-param,-param,param,1.2*(-param),1.2*param,0,0,0};
int vector_aux[25];

for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_6[i];
}
myod.move(200, vector_aux);

 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_7[i];
} 
myod.move(inctime, vector_aux);
 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_8[i];
} 
  myod.move(inctime, vector_aux);

 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_9[i];
}
  myod.move(inctime, vector_aux);
 

 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_10[i];
}
  myod.move(inctime, vector_aux);
 

 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_11[i];
}
  myod.move(inctime, vector_aux);
 

 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_12[i];
}
  myod.move(inctime, vector_aux);
 

 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_13[i];
}
  myod.move(inctime, vector_aux);
 

 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_14[i];
}
  myod.move(inctime, vector_aux);


 for(int i=0; i<25;i++){
  vector_aux[i]=vector_maravillas[i] + vector_15[i];
}
  myod.move(inctime, vector_aux);
 

 
*/


myod.move(350, vector_1);
myod.move(inctime, vector_2);
myod.move(inctime, vector_3);
myod.move(inctime, vector_4);
myod.move(inctime, vector_5);

myod.move(inctime, vector_6);
myod.move(inctime, vector_7);
myod.move(inctime, vector_8);
myod.move(inctime, vector_9);
myod.move(inctime, vector_10);
delay(250);
/*myod.move(inctime, vector_11);
myod.move(inctime, vector_12);
myod.move(inctime, vector_13);
myod.move(inctime, vector_14);
myod.move(inctime, vector_15);
myod.move(inctime, vector_16);
myod.move(inctime, vector_17);
myod.move(inctime, vector_18);
myod.move(inctime, vector_19);
myod.move(inctime, vector_20);*/

}
#endif
