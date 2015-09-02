#ifndef CINTURA_H
#define CINTURA_H

extern Robot myod;

void cintura(int grados, int msec){


  //derecha disminuye
  //izquierda aumenta
  

int vector_1[25] = {90,grados,155,35,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};

myod.move(msec, vector_1);


}
#endif
