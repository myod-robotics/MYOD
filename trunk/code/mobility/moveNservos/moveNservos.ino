#include <Servo.h>


/* PROPERTIES */
#define N 16//Cantidad de servos (Max 48)
#define OFFSET 15 //Servos conectados consecutivamente a partir del OFFSET

/* GLOBAL VARIABLE */
Servo servoList[N]; //Listado de servos
int *oldPosition; //Posicion actual 


//**** EXAMPLE INSTRUCTION *****//
int t = 1000;
int oldPosition_test[] = {10,10,180,12,23,34,45,67,12,23,10,10,180,12,23,34,45,67,12,23};
int newPosition_test[] = {90,180,55,98,76,43,54,26,87,43,90,180,55,98,76,43,54,76,87,43};

//int oldPosition_test[] = {10,10,180,12,23,34,45,67,12,23,10,10,180,12,23,34,45,67,12,23,90,180,55,98,76,43,54,26,87,43,90,180,55,98,76,43,54,76,87,43,54,76,87,43,54,76,87,43};
//int newPosition_test[] = {90,180,55,98,76,43,54,26,87,43,90,180,55,98,76,43,54,76,87,43,90,180,55,98,76,43,54,26,87,43,90,180,55,98,76,43,54,76,87,43,54,76,87,43,54,76,87,43};

void setup(){

  //Para todos los servos
  for(int i=0;i<N;i++){
      //atach servos
      servoList[i].attach(i+OFFSET);	
      //move initial position
      servoList[i].write(oldPosition_test[i]);
      oldPosition[i] = oldPosition_test[i];
  }
}

void loop(){
  
   moveNServos(t, newPosition_test);
   delay(1000);
   moveNServos(t, oldPosition_test);
   delay(1000);  
  
}

void moveNServos(int time, int newPosition[]){
  
  //calcula el incremento de posicion en funcion del tiempo
  float increment[N];  
  for(int i=0;i<N;i++){
	increment[i] = getGradeInrcrement(time, oldPosition[i], newPosition[i]); 
  }
  
  //tiempo para calcular la duracion exacta del ciclo
  int final_time =  millis() + time; //tiempo de referencia final;
   
  int iteration = 1; //para saber en que iteracion nos encontramos
  while(millis() < final_time){ 
	int interval_time = millis()+20;  //referencia de tiempo en un subciclo en ms
	int oneTime=0;
	while(millis()<interval_time){	  
		//solo lo hace en la primera iteracion
		if(oneTime<1){ 
			//enviar la posicion a conseguir en este subciclo 
			for(int i=0;i<N;i++){
				servoList[i].write(oldPosition[i] + (iteration * increment[i]));			
			}			
			iteration++;
			oneTime++;

		}
	}     
  }   
  oldPosition = newPosition;  
}

float getGradeInrcrement(int time, int posI, int posF){  
	// numeroIncrementos = time/20.0 --> cantidad de incrementos (escala 20ms)
	// varPosicion/numeroIncrementos --> variacion de posicion en cada incremento
	return (posF-posI)/(time/20.0);   
}
