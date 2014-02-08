#include <Servo.h>

/* PROPERTIES */
#define N 24 //Cantidad de servos (Max 48)
#define INTERVALTIME 10.0 //Tiempo en ms para calcular el movimiento relativo 
//Ejemplo: para N=24 ==> INTERVALTIME recomendado 10.0-20.0 ||| tiempo en minimo en mover 24 servos 2 o 3 ms)

/* GLOBAL VARIABLE */
Servo servoList[N]; //Listado de servos
int servoPins[N] = {2,3,4,5,6,7,8,9,10,11,12,13,22,23,24,25,26,27,28,29,30,31,32,33}; //Listado de los N pins
int oldPosition[N]; //Posicion actual 

//**** EXAMPLE INSTRUCTION *****//
int t = 500;
int oldPosition_test[N] = {20,50,80,90,20,50,80,90,20,50,80,90,20,50,80,90,20,50,80,90,20,50,80,90};
int newPosition_test[N] = {160,140,125,112,160,140,125,112,160,140,125,112,160,140,125,112,160,140,125,112,160,140,125,112};

void setup(){
   //Serial.begin(9600);
   //Serial.println("HELLO WORLD");   
   
   initServos();   
}

void loop(){  
//unsigned long tmp = millis();
   moveNServos(t, newPosition_test);
//Serial.println(millis()-tmp);
   delay(300);
   moveNServos(t, oldPosition_test);
   delay(300);    
}

void initServos(){
  //Para todos los servos
  for(int i=0;i<N;i++){
      //atach servos
      servoList[i].attach(servoPins[i]);
      //move initial position
      servoList[i].write(oldPosition_test[i]);
      oldPosition[i] = oldPosition_test[i];
  }
}

void moveNServos(int time, int newPosition[]){
  
  //calcula el incremento de posicion en funcion del tiempo
  float increment[N];  
  for(int i=0;i<N;i++){
	increment[i] = getGradeInrcrement(time, oldPosition[i], newPosition[i]); 
  }
  
  //tiempo para calcular la duracion exacta del ciclo
  unsigned long final_time =  millis() + time; //tiempo de referencia final;
  
  int iteration = 1; //para saber en que iteracion nos encontramos  
  while(millis() < final_time){  
      unsigned long interval_time = millis()+INTERVALTIME;  //referencia de tiempo en un subciclo en ms
      
      int oneTime=0;      
      while(millis()<interval_time){	  
          //solo lo hace en la primera iteracion
          if(oneTime<1){ 
//unsigned long tmp = millis();
              //enviar la posicion a conseguir en este subciclo 
              for(int i=0;i<N;i++){
                  servoList[i].write(oldPosition[i] + (iteration * increment[i]));
              }			
              iteration++;
              oneTime++;
//Serial.println(millis()-tmp);
          }

      }     
  }   
  //convertir las nuevas posiciones en las actuales
  for(int i=0;i<N;i++){
	oldPosition[i] = newPosition[i];
  }    
}

float getGradeInrcrement(int time, int posI, int posF){  
	// numeroIncrementos = time/20.0 --> cantidad de incrementos (escala 20ms)
	// numeroIncrementos = time/INTERVALTIME --> cantidad de incrementos (escala INTERVALTIME ms)
	// varPosicion/numeroIncrementos --> variacion de posicion en cada incremento
	return (posF-posI)/(time/INTERVALTIME);   
}
