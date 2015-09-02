#ifndef CINTURA_H
#define CINTURA_H

extern Robot myod;

void cintura(int grados){


  //derecha disminuye
  //izquierda aumenta
  
int inctime = 200;
int vector_1[25] = {90,grados,155,35,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};

myod.move(inctime, vector_1);


}
#endif
