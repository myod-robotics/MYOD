/***************************************************
*  14/10/2013 Javier I. H.                         *
*                                                  *
*  Movimiento de un sensor de ultrasonidos         *
*  mediante un servo                               *
*                                                  *
*  CONFIGURACION DE PINES:                         *
*    Pin 3: Control del servo                      *
*    Pin 13: Trigger                               *
*    Pin 10: Echo                                  *
*                                                  *
***************************************************/

#include <Servo.h> 
#define trig 13
#define echo 10
#define serv 3 //Hay que cerciorarse de que el pin soporte PWM


Servo servo; //Declaramos un objeto de la clase Servo

int pos; 
float retardo; 
float distancia;

void setup() 
{ 
  Serial.begin (9600); //Iniciamos la comunicación con el ordenador (para los print)
  pinMode(trig, OUTPUT); //Definimos el pin trig (13) como pin de salida
  pinMode(echo, INPUT);  //Definimos el pin echo (10) como pin de entrada
  servo.attach(serv); //Definimos el pin serv (3) como salida para control de servo
} 
 
 
void loop() 
{ 
    for(pos=30; pos<150; pos=pos+30)
    {
      servo.write(pos); //Situamos el servo en la posicion pos (en grados)            
      delay(500); //Esperamos a que el servo complete su recorrido
      
      digitalWrite(trig, HIGH); //Activamos el trigger
      delay(1);
      digitalWrite(trig, LOW); //Desactivamos el trigger
      retardo = pulseIn(echo, HIGH); //Almacenamos la lectura del sensor
      
      distancia=retardo/60; //Una conversión de unidades simple
      
      Serial.print("Distancia: "); //Salida por pantalla del valor tomado
      Serial.println(distancia);
    }
    
    //A partir de aqui es exactamente lo mismo, solo que el servo gira en sentido contrario
    
    for(pos=160; pos>30; pos=pos-30)
    {
      servo.write(pos);            
      delay(500);
      digitalWrite(trig, HIGH);
      delay(1);
      digitalWrite(trig, LOW);
      retardo = pulseIn(echo, HIGH);
      distancia=retardo/60;
      Serial.print("Distancia: ");
      Serial.println(distancia);
    }
} 
