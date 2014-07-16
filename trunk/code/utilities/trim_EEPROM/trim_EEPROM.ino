#include <EEPROM.h>
#include "configServos.h"
#include <Servo.h>
#include <MYOD.h>

enum configuracion {
  nouso=-1,NeckY=0,HipY,RShoulderR,LShoulderR,RShoulderP,LShoulderP,
  RElbowP,LElbowP,RHand,LHand,RLegY,LLegY,RLegR,LLegR,RLegP,LLegP,RKnee1,
  LKnee1,RKnee2,LKnee2,RAnkleP,LAnkleP,RAnkleR,LAnkleR,NeckP};

const char* c[] = {
  "NeckY","HipY","RShoulderR","LShoulderR","RShoulderP","LShoulderP",
  "RElbowP","LElbowP","RHand","LHand","RLegY","LLegY","RLegR","LLegR","RLegP","LLegP","RKnee1",
  "LKnee1","RKnee2","LKnee2","RAnkleP","LAnkleP","RAnkleR","LAnkleR","NeckP"
};

int port[Nmotor]={
  NECKY,HIPY,RSHOULDERR,LSHOULDERR,RSHOULDERP,LSHOULDERP,
  RELBOWP,LELBOWP,RHAND,LHAND,RLEGY,LLEGY,RLEGR,LLEGR,RLEGP,LLEGP,RKNEE1,
  LKNEE1,RKNEE2,LKNEE2,RANKLEP,LANKLEP,RANKLER,LANKLER,NECKP};

int time = 500; //ms min 10ms entre cambio de las posiciones
int trim[Nmotor];
int vector_0[Nmotor] = { //posicion de reposo para trim
  90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90
};
char a[3];
int t=0, motor=0, m;
byte b1, b2;
Robot myod;

void setup(){
  Serial.begin(9600);
  for(int i=0; i<NeckP;i++){ //Leer el trim guardado en la eeprom del robot
    b1=EEPROM.read(i);
    b2=EEPROM.read(i+NeckP);
    trim[i]=((b1<<8)&0xFF00)+(b2&0xFF);
  }
  myod.trimming(trim);
  myod.attach(port);
  myod.move(100,vector_0); //mover al reposo
  Serial.println("TRIM ACTUAL DE LOS SERVOS");
  for(int i=0; i<Nmotor; i++){
    Serial.print(trim[i]); 
    Serial.print(" -> ");
    showconfig(i);
  }
  Serial.println(" 'C'   PARA CAMBIAR DE MOTOR  ");
  Serial.println(" 'S'   PARA MOSTRAR TODOS LOS TRIMS");
  Serial.print("MOTOR ACTIVO: ");
  showconfig(motor);
}

void loop(){
  if(Serial.available()>0){ //Si se envia algo
    delay(10);
    a[0] = Serial.read();
    a[1] = Serial.read();
    a[2] = Serial.read();
    switch (a[0]){
    case 'c':
    case 'C':
      Serial.println("¿A que motor quieres cambiar?");
      for(int i=0; i<Nmotor; i++){
        Serial.print(i); 
        Serial.print("->");
        showconfig(i);
      }
      Serial.flush();
      while(Serial.available()==0){
      };
      delay(10);
      a[0] = Serial.read();
      a[1] = Serial.read();
      a[2] = Serial.read();
      if(a[0]==-1){
        a[2]=a[1];
        a[1]=a[0];
        a[0]='0';
        if(a[1]==-1){
          a[1]='0';
        }
      }
      m = atoi(a);
      if(m <NeckP && motor >=0){
        motor=m;
        Serial.print("Trim de ");
        showconfig(motor);
        b1 = EEPROM.read(motor);
        b2 = EEPROM.read(motor + NeckP);
        t = ((b1<<8)&0xFF00)+(b2&0xFF);
        Serial.println(t);
      }
      else{
        Serial.println("Valor fuera de rango");
      }
      break;
    case 's':
    case 'S':
      Serial.println("El trim actual es: ");
      for(int i=0; i< NeckP; i++){
        b1 = EEPROM.read(i);
        b2 = EEPROM.read(i + NeckP);
        t = ((b1<<8)&0xFF00)+(b2&0xFF);
        Serial.print(t);
        Serial.print(" <- ");        
        showconfig(i);
      }
      break; 
    default:
      if(a[0]==-1){
        a[2]=a[1];
        a[1]=a[0];
        a[0]='0';
        if(a[1]==-1){
          a[1]='0';
        }
      }
      Serial.flush();
      t = atoi(a);
      trim[motor] = t;
      Serial.print("Trim: ");
      Serial.println(trim[motor]);
      myod.trimming(trim);
      myod.move(time,vector_0);
      EEPROM.write(motor,(t>>8)&0xFF);
      EEPROM.write(motor+NeckP,0xFF&t);
    }
    Serial.print("MOTOR ACTIVO: ");
    showconfig(motor);
  }
}
void showconfig(int conf){
  Serial.println(c[conf]);
}
