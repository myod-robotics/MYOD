/************************************************
* RAIDER 1.0 Sensor-Reader                      *
* Lector de sensores para Teensy 3.0            *
* www.JavierIH.blogspot.com                     *
************************************************/

#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050.h"

//DEFINICION DE VALORES CRÍTICOS
#define US 14
#define IR 480
#define GREEN 500
#define CAIDA 220
#define MARGEN 20 //Para los giros


//PINES DE SENSORES
#define US_TRIGGER 3
#define US_ECHO 4
#define CMP_IN 17
#define IR1_IN 22
#define IR2_IN 23
#define COLOR1 21
#define COLOR2 20
#define CLR_S0 14
#define CLR_S1 15
#define CLR_S2 12
#define CLR_S3 11


//PINES DE TEENSY A CM900
#define IR1_OUT 0
#define IR2_OUT 1
#define US_OUT 2
#define CMPR_OUT 5
#define CMPL_OUT 6
#define CLR_OUT 7
#define FALLA_OUT 8
#define FALLB_OUT 9
#define LED 13

//PINES DE CM900 A TEENSY
#define INV 10

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
float CMP_A;
float CMP_B;
int work=0;
int prev=1000;


void setup()
{
      Serial.begin (9600);

//I2C interface.
      Wire.begin();

//Ultrasonic
      pinMode(US_TRIGGER, OUTPUT);
      pinMode(US_ECHO, INPUT);
      pinMode(US_OUT, OUTPUT);
      
//Infrarred
      pinMode(IR1_OUT, OUTPUT);
      pinMode(IR2_OUT, OUTPUT);
  
//Compass
      pinMode(CMP_IN, INPUT);
      pinMode(CMPR_OUT, OUTPUT);
      pinMode(CMPL_OUT, OUTPUT);
      pinMode(INV,INPUT);

//Gyroscope
      mpu.initialize(); 
      
//White line
      pinMode(CLR_S0, OUTPUT); 
      pinMode(CLR_S1, OUTPUT); 
      pinMode(CLR_S2, OUTPUT);
      pinMode(CLR_S3, OUTPUT);
      pinMode(COLOR1, INPUT); 
      pinMode(COLOR2, INPUT);
      pinMode(CLR_OUT, OUTPUT); 
      
//Led
      pinMode(LED, OUTPUT);      
      delay(200);
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
      digitalWrite(LED, HIGH);
      
      
//REFERENCIA MAGNETICA
      unsigned int data=pulseIn(CMP_IN , HIGH);
      data=data-989;
      CMP_A=data/97.67;
      if(CMP_A>180) CMP_B=CMP_A-180;
      else CMP_B=CMP_A+180;
    
delay(20);
}
 
 
void loop()
{
    float data=0; //Podria llamarse aux, pero no, es data.

//ULTRASONIC
    digitalWrite(US_TRIGGER, HIGH);
    delay(10);
    digitalWrite(US_TRIGGER, LOW);
    data = pulseIn(US_ECHO, HIGH);
      
    //Serial.print("\n\n\n\n\n\nUS: ");Serial.print(data/60);
      
    if(data/60<US&&data!=0) {digitalWrite(US_OUT, HIGH); Serial.println("YAY!");}
    else { digitalWrite(US_OUT, LOW); Serial.println("NOPE!");}
      
      
    delay(10);
    data=0;
      
//INFRARRED RIGHT (1)
    data=analogRead(IR1_IN);
    //Serial.print("IR1: ");Serial.print(data);
    if(data>IR){ digitalWrite(IR1_OUT, HIGH); Serial.println(" H");} 
    else{ digitalWrite(IR1_OUT, LOW); Serial.println(" L");} 
      
    delay(10);
    data=0;

//INFRARRED LEFT (2)
    data=analogRead(IR2_IN);
    //Serial.print("IR2: ");Serial.print(data);
    if(data>IR){ digitalWrite(IR2_OUT, HIGH); Serial.println(" H");}
    else {digitalWrite(IR2_OUT, LOW); Serial.println(" L");} 
      
    delay(10);
    data=0;
    
//COMPASS
    float dif=0;
    unsigned int mag=pulseIn(CMP_IN , HIGH);
    mag=mag-989;
    data=mag/97.67;

    //Serial.print("REFERENCIA: ");
    //Serial.println(CMP_A);
    //Serial.print("Brujula: ");
    //Serial.println(data);
    
    if(!digitalRead(INV)){
            //Serial.println("\ORIGINAL\n");

      if(CMP_A<CMP_B){
        if(data>CMP_A&&data<CMP_B){
          dif=abs(CMP_A-data);
          if (dif>180) dif=dif-180;
          if (dif>MARGEN){
            digitalWrite(CMPR_OUT, HIGH);
            digitalWrite(CMPL_OUT, LOW);
          }          
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }          
        }
        else{
          dif=abs(CMP_A-data);
          if (dif>180) dif=dif-180;
          if (dif>MARGEN){
            digitalWrite(CMPL_OUT, HIGH);
            digitalWrite(CMPR_OUT, LOW);
          }
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }      
        }
      }
      else{
        if(data<CMP_A&&data>CMP_B){
          dif=abs(CMP_A-data);
          if (dif>180) dif=dif-180;
          if (dif>MARGEN){
            digitalWrite(CMPL_OUT, HIGH);
            digitalWrite(CMPR_OUT, LOW);
          }
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }      
        }
        else{
          dif=abs(CMP_A-data);
          if (dif>180) dif=dif-180;
          if (dif>MARGEN){
            digitalWrite(CMPR_OUT, HIGH);
            digitalWrite(CMPL_OUT, LOW);
          }
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }      
        }
      }
    }
    //Inverted signals!!!!
    else{
      //Serial.println("\nINVERTIDO\n");
      if(CMP_B<CMP_A){
        if(data>CMP_B&&data<CMP_A){
          dif=abs(CMP_B-data);
          if (dif>180) dif=dif-180;
          //Serial.print("\ndif: ");
          //Serial.println(dif);
          if (dif>MARGEN){
            digitalWrite(CMPR_OUT, HIGH);
            digitalWrite(CMPL_OUT, LOW);
          }          
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }          
        }
        else{
          dif=abs(CMP_B-data);
          if (dif>180) dif=dif-180;
          //Serial.print("\ndif: ");
          //Serial.println(dif);
          if (dif>MARGEN){
            digitalWrite(CMPL_OUT, HIGH);
            digitalWrite(CMPR_OUT, LOW);
          }
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }      
        }
      }
      else{
        if(data<CMP_B&&data>CMP_A){
          dif=abs(CMP_B-data);
          if (dif>180) dif=dif-180;
          //Serial.print("\ndif: ");
          //Serial.println(dif);
          if (dif>MARGEN){
            digitalWrite(CMPL_OUT, HIGH);
            digitalWrite(CMPR_OUT, LOW);
          }
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }      
        }
        else{
          dif=abs(CMP_B-data);
          if (dif>180) dif=dif-180;
          //Serial.print("\ndif: ");
          //Serial.println(dif);
          if (dif>MARGEN){
            digitalWrite(CMPR_OUT, HIGH);
            digitalWrite(CMPL_OUT, LOW);
          }
          else{
            digitalWrite(CMPR_OUT, LOW);
            digitalWrite(CMPL_OUT, LOW);
          }      
        }
      }
      
    }
    
       
    delay(10);
    data=0;      
       
//GYROSCOPE
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);   

    if((prev-ay)>24000){
      //Serial.println("\n\n\n\n\n\nADELANTE");
      digitalWrite(FALLA_OUT, HIGH);
      //digitalWrite(FALLB_OUT, LOW);
      delay(5000);
    }
    else{
      digitalWrite(FALLA_OUT, LOW);
      //digitalWrite(FALLB_OUT, LOW);
    }     
    if((prev-ay)<-24000){
      //Serial.println("\n\n\n\n\n\nATRAS");
      digitalWrite(FALLA_OUT, LOW);
      //digitalWrite(FALLB_OUT, HIGH);
      delay(5000);
    }
    else{
      digitalWrite(FALLA_OUT, LOW);
      //digitalWrite(FALLB_OUT, LOW);
    }      
    
    prev=gy;

    delay(10);
    data=0;
      
//WHITE LINE
    digitalWrite(CLR_S0, HIGH); //S0
    digitalWrite(CLR_S1, LOW);
    digitalWrite(CLR_S3, HIGH); //S3
    digitalWrite(CLR_S2, HIGH); //S2
    int colorD = pulseIn(COLOR2, LOW, 80000);
    if(colorD < .1) colorD = 80000;
    int colorI = pulseIn(COLOR1, LOW, 80000);
    if(colorI < .1) colorI = 80000;
    digitalWrite(CLR_S0, LOW); 
    digitalWrite(CLR_S1, LOW);
    //Serial.print("GreenD: ");
    //Serial.println(colorD);
    //Serial.print("GreenI: ");
    //Serial.println(colorI);
      
    if (colorD<GREEN||colorI<GREEN) digitalWrite(CLR_OUT,HIGH);
    else digitalWrite(CLR_OUT,LOW);
    
    
    

//LED (me inspira cierta tranquilidad ver que parpadea de tanto en tanto)
/**/
if(work==1){
  digitalWrite(LED, HIGH);
}
else if(work==10){
  digitalWrite(LED, LOW);
}
else if(work==20) work=0;
delay(500);
work++;
} 


