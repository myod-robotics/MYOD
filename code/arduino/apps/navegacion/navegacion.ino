#include <EEPROM.h>
#include "configServos.h"
#include <Servo.h>
#include <Ultrasonic.h>
#include "MYOD.h"
#include "prueba_exp.h"
#include "punetazoder.h"
#include "punetazoizq.h"
#include "giroDerecha.h"
#include "giroIzquierda.h"
#include "idle.h"
#include "punetazolateralder.h"
#include "punetazolateralizq.h"
#include "pasolateralizq.h"
#include "pasolateralder.h"
#include "cintura.h"


#define echoPinD 49
#define trigPinD 48
#define echoPinI 47
#define trigPinI 46
#define avanzamin 15
#define avanzamax 40


enum configuracion {
  nouso = -1, NeckY = 0, HipY, RShoulderR, LShoulderR, RShoulderP, LShoulderP,
  RElbowP, LElbowP, RHand, LHand, RLegY, LLegY, RLegR, LLegR, RLegP, LLegP, RKnee1,
  LKnee1, RKnee2, LKnee2, RAnkleP, LAnkleP, RAnkleR, LAnkleR, NeckP
};
int port[Nmotor] = {
  NECKY, HIPY, RSHOULDERR, LSHOULDERR, RSHOULDERP, LSHOULDERP,
  RELBOWP, LELBOWP, RHAND, LHAND, RLEGY, LLEGY, RLEGR, LLEGR, RLEGP, LLEGP, RKNEE1,
  LKNEE1, RKNEE2, LKNEE2, RANKLEP, LANKLEP, RANKLER, LANKLER, NECKP
};
int vector_90[25] = {
  90,90,155,30,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
int trim[Nmotor];//={  -6,-9,3,-7,6,0,54,-44,-7,-3,8,3,5,-7,-5,0,0,0,7,2,6,0};
Robot myod;
byte b1, b2;


long durationD, cmD, durationI, cmI;

Ultrasonic ultrasonicI(trigPinI,echoPinI); // (Trig PIN,Echo PIN)
Ultrasonic ultrasonicD(trigPinD,echoPinD); // (Trig PIN,Echo PIN)



void setup() {
  //Serial.begin(9600);
  /*pinMode(trigPinD, OUTPUT);
   pinMode(echoPinD, INPUT);
   pinMode(trigPinI, OUTPUT);
   pinMode(echoPinI, INPUT);
   */
  for (int i = 0 ; i < NeckP; i++) {
    b1 = EEPROM.read(i);
    b2 = EEPROM.read(i + NeckP);
    trim[i] = ((b1 << 8) & 0xFF00) + (b2 & 0xFF);
  }
  myod.trimming(trim);
  myod.attach(port);
  //prueba();
  
        myod.move(400,vector_90);
        delay(5000);
}

void loop() {
  while (1) {
    //agacharse (defensa)
    //Serial.println("----------");
    //NO SE LEVANTA AHORA: SE LEVANTA DENTRO DE CAD MOVIMIENTO

    /*
    //leer ultrasonidos
     digitalWrite(trigPinD, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPinD, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigPinD, LOW);
     durationD = pulseIn(echoPinD, HIGH);
     //transformacion ultra a cm
     */
    cmD = ultrasonicD.Ranging(CM);
    /*
    //leer ultrasonidos
     digitalWrite(trigPinI, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPinI, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigPinI, LOW);
     durationI = pulseIn(echoPinI, HIGH);
     //transformacion ultra a cm
     */
    cmI = ultrasonicI.Ranging(CM);
    //Serial.print("derecha= "); 
    //Serial.println(cmD);
    //Serial.print("izquierda= "); 
    //Serial.println(cmI);
    //pasolateralder();
    if (cmD < avanzamin && cmI < avanzamin) { //pelea centro
      if(cmD <=cmI){
        pasolateralizq();
          myod.move(400,vector_90);
        //desplazamiento lateral izquierda
      }
      else{
        //Desplazamiento lateral derecha
        pasolateralder();
        myod.move(400,vector_90);
      }
      //Serial.println("Centro corto");
    }
    else if (cmD <= avanzamin) { //Pelea Derecha
      //Serial.println("Corto derecha");
      //desplazamiento lateral izquierda
      pasolateralizq();
      myod.move(400,vector_90);
    }
    else if (cmI <= avanzamin) { //Pelea Izquierda
      //desplazamiento lateral derecha
      pasolateralder();
      myod.move(400,vector_90);      
      //Serial.println("Corto izquierda");
    }
    else if ((cmD > avanzamin && cmD <= avanzamax) && (cmI > avanzamin && cmI <= avanzamax)) { //Avanzar hacia el enemigo de frente
      prueba();
      prueba();
      myod.move(400,vector_90);
      //Serial.println("Centro medio. avance");
    }
    else if (cmD > avanzamin && cmD <= avanzamax) { //Giro derecha
      //desplazamiento lateral derecha
      pasolateralder();
      prueba();
      myod.move(400,vector_90);
      //Serial.println("medio derecha- giro");
    }
    else if (cmI > avanzamin && cmI <= avanzamax) { //Giro izquierda
      //desplazamiento lateral izquierda
      pasolateralizq(); 
      prueba();
      myod.move(400,vector_90);
      //Serial.println("medio izquierda- giro");
    }
    else { //avance recto
      prueba();
      prueba();
        
        prueba();
        prueba();
      myod.move(600,vector_90);


    }
  }

}


long microsecondsToCentimeters(long microseconds) {
  // La velocidad del sonido a 20º de temperatura es 340 m/s o
  // 29 microsegundos por centrimetro.
  // La señal tiene que ir y volver por lo que la distancia a
  // la que se encuentra el objeto es la mitad de la recorrida.
  return microseconds / 29 / 2 ;
}











