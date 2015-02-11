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
int vector_aux[Nmotor];
int vector_cpy[Nmotor+1];

char a[3];
int t=0, mov=0 , motor=0, m,cp1,cp2;
byte b1, b2;
Robot myod;
int nmovimientos = 0;
boolean firstTime=HIGH;


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
  Serial.println(" 'C'   PARA CAMBIAR DE MOTOR/TIEMPO  ");
  Serial.println(" 'M'   PARA CAMBIAR A OTRO MOVIMIENTO");
  Serial.println(" 'S'   PARA MOSTRAR TODOS LOS MOVIMIENTOS");
  Serial.println(" 'X'   PARA COPIAR DOS MOVIMIENTOS");
  Serial.println(" 'E'   PARA EJECUTAR EL MOVIMENTO");
  Serial.println(" 'H'   PARA MOSTRAR LA LISTA DE COMANDOS");


  Serial.println("------------------------------------------");
  do{
    Serial.println("Define un numero de pasos para el movimiento: ");
    while(Serial.available()==0){
    }
    delay(100);
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
    nmovimientos = atoi(a);
  }
  while(nmovimientos<=0);
  Serial.print("El movimiento esta compuesto por ");
  Serial.print(nmovimientos);
  Serial.println(" movimientos");
}

void loop(){
  int matrixmov[nmovimientos][NeckP+1];

  while(1){

    if(firstTime){
      //firstTime=LOW;
      for(int j=0; j<nmovimientos; j++){
        for(int i =0; i<NeckP+1; i++){
          matrixmov[j][i]=90;
        } 
      }
    }



    if(Serial.available()>0||firstTime){ //Si se envia algo
      delay(10);
      a[0] = Serial.read();
      a[1] = Serial.read();
      a[2] = Serial.read();
      if(firstTime){
        a[0]='s'; 
        firstTime=LOW;
      }

      switch (a[0]){
      case 'c':
      case 'C':
        Serial.println("¿A que motor quieres cambiar?");
        Serial.print(0);
        Serial.println("->Tiempo");
        for(int i=0; i<Nmotor; i++){
          Serial.print(i+1); 
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
        if(m <= NeckP+1 && m >=0){
          motor=m;
          if(motor!=0){
            Serial.print("Motor elegido: ");
            showconfig(motor-1);

          }
          else{
            Serial.println("Tiempo:");
          }
        }
        else{
          Serial.println("Valor fuera de rango");
        }
        break;



      case 's':
      case 'S':
        Serial.println("El Movimiento actual es: ");
        for(int i=0; i< nmovimientos; i++){
          for(int j=0; j<NeckP+1; j++){
            Serial.print(matrixmov[i][j]);
            if(j==0){
              Serial.print(",{");
            }
            else if(j==NeckP){
              Serial.print("}");
            }
            else{
              Serial.print(",");
            }
          }
          Serial.print('\n');
        }
        Serial.println("COPIA ESTA MATRIZ A UN DOCUMENTO DE TEXTO PLANO PARA PODER GUARDARLO");
        break; 


      case 'm':
      case 'M':
        Serial.println("¿A que movimiento quieres cambiar?");
        ;
        for(int i=0; i<nmovimientos; i++){
          Serial.print(i);
          Serial.print(" -> ");
          for(int j=0; j<NeckP+1; j++){
            Serial.print(matrixmov[i][j]);
            if(j==0){
              Serial.print(",{");
            }
            else if(j==NeckP){
              Serial.print("}");
            }
            else{
              Serial.print(",");
            }
          }
          Serial.print('\n');
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
        if(m < nmovimientos && m >=0){
          mov=m;
          Serial.print("Movimiento elegido: ");
          Serial.println(mov);
          for(int j=0; j<NeckP+1; j++){
            Serial.print(matrixmov[mov][j]);
            if(j==0){
              Serial.print(",{");
            }
            else if(j==NeckP){
              Serial.print("}");
            }
            else{
              Serial.print(",");
            }
          }
          Serial.print('\n');
        }
        else{
          Serial.println("Valor fuera de rango");
        }
        break;


      case 'e':
      case 'E':
        Serial.print("Ejecutando....");
        for(int i=0; i<NeckP;i++){
          vector_aux[i]=matrixmov[0][i+1];
        }
        myod.move(matrixmov[0][0],vector_aux);
        for(int j=0; j<nmovimientos; j++){
          for(int i=0; i<NeckP;i++){
            vector_aux[i]=matrixmov[j][i+1];
          }
          myod.move(matrixmov[j][0],vector_aux);
        }       
        Serial.println("FIN");   
        break;

      case 'x':
      case 'X':

        Serial.println("¿Qué movimiento quieres copiar");

        for(int i=0; i<nmovimientos; i++){
          Serial.print(i);
          Serial.print(" -> ");
          for(int j=0; j<NeckP+1; j++){
            Serial.print(matrixmov[i][j]);
            if(j==0){
              Serial.print(",{");
            }
            else if(j==NeckP){
              Serial.print("}");
            }
            else{
              Serial.print(",");
            }
          }
          Serial.print('\n');
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
        if(m < nmovimientos && m >=0){
          cp1=m;
          Serial.print("Movimiento elegido: ");
          Serial.println(cp1);
          for(int j=0; j<NeckP+1; j++){
            Serial.print(matrixmov[cp1][j]);
            if(j==0){
              Serial.print(",{");
            }
            else if(j==NeckP){
              Serial.print("}");
            }
            else{
              Serial.print(",");
            }
          }
          Serial.print('\n');
        }
        else{
          Serial.println("Valor fuera de rango");
        }
        Serial.println("¿Sobre que movimiento quieres grabarlo?");
        for(int i=0; i<nmovimientos; i++){
          Serial.print(i);
          Serial.print(" -> ");
          for(int j=0; j<NeckP+1; j++){
            Serial.print(matrixmov[i][j]);
            if(j==0){
              Serial.print(",{");
            }
            else if(j==NeckP){
              Serial.print("}");
            }
            else{
              Serial.print(",");
            }
          }
          Serial.print('\n');
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
        if(m < nmovimientos && m >=0){
          cp2=m;
          Serial.print("Movimiento elegido: ");
          Serial.println(cp2);
          for(int j=0; j<NeckP+1; j++){
            Serial.print(matrixmov[mov][j]);
            if(j==0){
              Serial.print(",{");
            }
            else if(j==NeckP){
              Serial.print("}");
            }
            else{
              Serial.print(",");
            }
          }
          Serial.print('\n');
        }
        else{
          Serial.println("Valor fuera de rango");
        }
        Serial.print("Deseas confirmar copiar el movimiento "); 
        Serial.print(cp1);
        Serial.print(" sobre "); 
        Serial.print(cp2); 
        Serial.println("? Pulse 'Y' par confirmar");
        Serial.flush();
        while(Serial.available()==0){
        };
        if(Serial.available()>0){ //Si se envia algo
          delay(10);
          a[0] = Serial.read();
          if(a[0]=='y' || a[0]=='Y'){
            for(int i=0; i < NeckP+1; i++){
              vector_cpy[i]=matrixmov[cp1][i];
              matrixmov[cp2][i]=vector_cpy[i];
            }
          }
          else{
            Serial.println("Cancelado"); 
          }
        }
        break;






      case 'h':
      case 'H':
        Serial.println(" 'C'   PARA CAMBIAR DE MOTOR/TIEMPO  ");
        Serial.println(" 'M'   PARA CAMBIAR A OTRO MOVIMIENTO");
        Serial.println(" 'S'   PARA MOSTRAR TODOS LOS MOVIMIENTOS");
        Serial.println(" 'X'   PARA COPIAR DOS MOVIMIENTOS");
        Serial.println(" 'E'   PARA EJECUTAR EL MOVIMENTO");
        Serial.println(" 'H'   PARA MOSTRAR LA LISTA DE COMANDOS");
        if(motor==0){
          Serial.println("TIEMPO ACTIVO");
        }
        else{
          Serial.print("MOTOR ACTIVO: ");
          showconfig(motor-1);
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

        Serial.print("Mov: ");
        Serial.println(t);
        matrixmov[mov][motor]=t;
        for(int i=0; i<NeckP;i++){
          vector_aux[i]=matrixmov[mov][i+1];
        }
        myod.move(300,vector_aux);

      }
      if(motor==0){
        Serial.println("TIEMPO ACTIVO");
      }
      else{
        Serial.print("MOTOR ACTIVO: ");
        showconfig(motor-1);
      }
    }    
  }

}
void showconfig(int conf){
  Serial.println(c[conf]);
}













