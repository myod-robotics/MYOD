
#include <Arduino.h>
#include <Servo.h>
#include <MYOD.h>

Robot::Robot(int trim[Nmotor]){
  // this->attach(port);
    for(int i=0;i<Nmotor;i++){ //Cambiar a la posición de reposo del robot
    _position[i]=90;
    _trim[i]=trim[i];
    }
}
Robot::Robot(){
    for(int i=0;i<Nmotor;i++){ //Cambiar a la posición de reposo del robot
    _position[i]=90;
    _trim[i]=0;
    }
}
void Robot::attach(int port[Nmotor]){
   for(int i=0;i<Nmotor;i++){
      _motors[i].attach(port[i]);
   }
}
void Robot::detach(){
    for(int i=0;i<Nmotor;i++){
       _motors[i].detach();
    }
}

float Robot::getGradeInrcrement(int time, int posI, int posF){  
    // numeroIncrementos = time/20.0 --> cantidad de incrementos (escala INTERVALTIME)
	// varPosicion/numeroIncrementos --> variacion de posicion en cada incremento
	return (posF-posI)*1.0/(time/INTERVALTIME);   
}

void Robot::moveOne(int motor, int pos){
     _position[motor]= pos;
     _motors[motor].write(_position[motor] + _trim[motor] );

}
void Robot::moveOffs(int motor, int var){
    _position[motor]=_position[motor]+var;
    this->moveOne(motor,_position[motor]);
}

void Robot::move(int time, int newPosition[Nmotor]){

  //calcula el incremento de posicion en funcion del tiempo
  float increment[Nmotor];
  for(int i=0;i<Nmotor;i++){
    increment[i] = getGradeInrcrement(time,_position[i], newPosition[i]);
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
              for(int i=0;i<Nmotor;i++){
                  _motors[i].write(_trim[i] + _position[i] + (iteration * increment[i]));
              }
              iteration++;
              oneTime++;
//Serial.println(millis()-tmp);
          }

      }
  }
  //convertir las nuevas posiciones en las actuales
  for(int i=0;i<Nmotor;i++){
    _position[i] = newPosition[i];
    _motors[i].write(_trim[i] + _position[i]); //Aseguramos la posicion final sin error de propagacion
  }
}
void Robot::trimming(int trim[Nmotor]){
    for(int i=0;i<Nmotor;i++){
        _trim[i]=trim[i];
    }
}
int Robot::readPos(int motor){
    return _position[motor];
}
