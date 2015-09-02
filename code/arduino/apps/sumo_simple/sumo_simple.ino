#include <EEPROM.h>
#include "configServos.h"
#include <Servo.h>
#include <Ultrasonic.h>
#include "MYOD.h"
#include "prueba_exp.h"
#include "punetazoder.h"
#include "punetazoizq.h"
#include "girardcha.h"
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


#define avanzamin 22
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

int trim[Nmotor];
Robot myod;
byte b1, b2;

int vector_90[25] = {
  90, 90, 155, 30, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90
};



long durationD, cmD, durationI, cmI;
Ultrasonic ultrasonicD(trigPinD, echoPinD); // (Trig PIN,Echo PIN)
Ultrasonic ultrasonicI(trigPinI, echoPinI); // (Trig PIN,Echo PIN)


void setup() {
  Serial.begin(9600);

  for (int i = 0 ; i < NeckP; i++) {
    b1 = EEPROM.read(i);
    b2 = EEPROM.read(i + NeckP);
    trim[i] = ((b1 << 8) & 0xFF00) + (b2 & 0xFF);
  }
  myod.trimming(trim);
  myod.attach(port);
  myod.move(300,vector_90);
  delay(4500);
  prueba();
  punetazoder();

}

void loop() {
  while (1) {

    //agacharse (defensa)
    Serial.println("----------");
    //NO SE LEVANTA AHORA: SE LEVANTA DENTRO DE CAD MOVIMIENTO


    cmD = ultrasonicD.Ranging(CM);

    cmI = ultrasonicI.Ranging(CM);



    Serial.print("derecha= "); Serial.println(cmD);
    Serial.print("izquierda= "); Serial.println(cmI);

    if (cmD < avanzamin && cmI < avanzamin) { //pelea centro
      punetazoder();
      Serial.println("Centro corto");
    }
    else if (cmD <= avanzamin) { //Pelea Derecha
      Serial.println("Corto derecha");
      punetazoder();
    }
    else if (cmI <= avanzamin) { //Pelea Izquierda
      punetazoizq();
      Serial.println("Corto izquierda");
    }
    else if ((cmD > avanzamin && cmD <= avanzamax) || (cmI > avanzamin && cmI <= avanzamax)) { //Avanzar hacia el enemigo de frente
      prueba();
      Serial.println("Centro medio. avance");
    }
    else if ((cmD> avanzamax)&& (cmI > avanzamax)){
    prueba();
    }
  }
}
