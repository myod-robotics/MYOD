#include <Wire.h>

#include <I2Cdev.h>

#include <MPU6050.h>


/************************************************
 * RAIDER 1.0 Sensor-Reader *
 * Lector de sensores para Teensy 3.0 *
 * www.JavierIH.blogspot.com *
 ************************************************/



//DEFINICION DE VALORES CRÍTICOS
#define US 14
#define IR 480
#define GREEN500 500
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

MPU6050 mpu; //declaración del objeto MPU6050

//Aceleración lineal en los 3 ejes
int16_t ax, ay, az;
int16_t gx, gy, gz;

//Velocidad angular
int rateX;  // Medición actual de velocidad X
int rateY;  // Medición actual de velocidad Y
int rateZ;  // Medición actual de velocidad Z

float CMP_A;
float CMP_B;
int work=0;
int prev=1000;
int sampleNum=500;  // Número de muestras para el promediar el offset

// Declaración de variables de offset y ruido
int dc_offsetX=0; // Offset en X
double noiseX=0;  // Nivel de ruido en X

int dc_offsetY=0;  // Offset en Y
double noiseY=0;  // Nivel de ruido en Y

int dc_offsetZ=0;  // Offset en Z
double noiseZ=0;  // Nivel de ruido en Z

// Declaración de variables para muestras de la velocidad
unsigned long time;
int sampleTime=10;

// Declaración de variables para medición del ángulo
int prev_rateX=0;  // Medición previa de velocidad X
double angleX=0;  // Valor del ángulo en Z

int prev_rateY=0;  // Medición previa de velocidad Y
double angleY=0;  // Valor del ángulo en Y

int prev_rateZ=0;  // Medición previa de velocidad Z
double angleZ=0;  // Valor del ángulo en Z

void setup()
{
  Serial.begin (9600);

  //I2C interface.
  Wire.begin();


//  //Gyroscope
//  mpu.initialize(); 
//  if (!mpu.testConnection())
//  {
//    Serial.println("Ha fallado la comunicacion con el sensor");
//    while (1);
//  }
//
//  mpu.enableDefault();  // Si hay comunicación se configura
//                         // por defecto el sensor
// 
  calculoOffset();  // Función para calcular el offset de cada eje

  delay(20);
}


void loop()
{

  //GYROSCOPE
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 

  Serial.println("\n\n\n\n ");   

  float aux=0;
  aux=ax*19.62;
  aux=aux/32767;

  float aux2=0;
  aux2=ay*19.62;
  aux2=aux2/32767;

  float aux3=0;
  aux3=az*19.62;
  aux3=aux3/32767;

  Serial.print("Acc X: ");
  Serial.println(aux);
  Serial.print("Acc Y: "); 
  Serial.println(aux2);  
  Serial.print("Acc Z: ");  
  Serial.println(aux3);  
  Serial.print("Gyr X: ");  
  Serial.println(gx);  
  Serial.print("Gyr Y: "); 
  Serial.println(gy);   
  Serial.print("Gyr Z: ");  
  Serial.println(gz);  

//Cálculo del ángulo de giro

if(millis() - time > sampleTime)
  {
    time = millis(); // Tiempo de la próxima actualización
    
    // **********************************
    rateX=((int)gx-dc_offsetX)/100;  // Calculo de la velocidad X en °/s

    // Sumatoria (integración) de la velocidad para el calculo de grados X
    angleX += ((double)(prev_rateX + rateX) * sampleTime) / 2000;
    
    prev_rateX = rateX;  // Se debe recordar una muestra previa de velocidad
    // Se coloca el ángulo recorrido en una escala de 0 a 360 grados
    if (angleX < 0){
      angleX += 360;
    }
    else if (angleX >= 360)
    {
      angleX -= 360;
    }
    
    // **********************************
    rateY=((int)gy-dc_offsetY)/100;  // Calculo de la velocidad Y en °/s

    // Sumatoria (integración) de la velocidad para el calculo de grados Y
    angleY += ((double)(prev_rateY + rateY) * sampleTime) / 2000;
    
    prev_rateY = rateY;  // Se debe recordar una muestra previa de velocidad
    // Se coloca el ángulo recorrido en una escala de 0 a 360 grados
    if (angleY < 0){
      angleY += 360;
    }
    else if (angleY >= 360)
    {
      angleY -= 360;
    }   
    
    // **********************************
    rateZ=((int)gz-dc_offsetZ)/100;  // Calculo de la velocidad Z en °/s

    // Sumatoria (integración) de la velocidad para el calculo de grados Z
    angleZ += ((double)(prev_rateZ + rateZ) * sampleTime) / 2000;
    
    prev_rateZ = rateZ;  // Se debe recordar una muestra previa de velocidad
    // Se coloca el ángulo recorrido en una escala de 0 a 360 grados
    if (angleZ < 0){
      angleZ += 360;
    }
    else if (angleZ >= 360)
    {
      angleZ -= 360;
    }

    // Impresión de los datos por consola
    Serial.print("AnguloZ: ");
    Serial.print(angleZ);
    Serial.print("\tVelZ: ");
    Serial.print(rateZ);
    
    Serial.print("\tAnguloY: ");
    Serial.print(angleY);
    Serial.print("\tVelY: ");
    Serial.println(rateY);
    
    Serial.print("\tAnguloX: ");
    Serial.print(angleX);
    Serial.print("\tVelX: ");
    Serial.println(rateX); 
  }
}

// Función del cálculo de Offset y nivel de ruido
void calculoOffset(){

  //**************************************
  //Eje X
  //**************************************
  
  // Promedio de muestras
  for(int n=0;n<sampleNum;n++){
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
    dc_offsetX+=(int)gx;
  }
  dc_offsetX=dc_offsetX/sampleNum;

  // Calculo de nivel de ruido
  for(int n=0;n<sampleNum;n++){
     mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
    if((int)gx-dc_offsetY>noiseX)
      noiseX=(int)gx-dc_offsetX;
    else if((int)gx-dc_offsetX<-noiseX)
      noiseX=-(int)gx-dc_offsetX;
  }
  noiseX=noiseX/100;
   
  //**************************************
  //Eje Y
  //**************************************
  
  // Promedio de muestras  
  for(int n=0;n<sampleNum;n++){
     mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
    dc_offsetY+=(int)gy;
  }
  dc_offsetY=dc_offsetY/sampleNum;
  
  // Calculo de nivel de ruido
  for(int n=0;n<sampleNum;n++){
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
    if((int)gy-dc_offsetY>noiseY)
      noiseY=(int)gy-dc_offsetY;
    else if((int)gy-dc_offsetY<-noiseY)
      noiseY=-(int)gy-dc_offsetY;
  }
  noiseY=noiseY/100;
  
  //**************************************
  //Eje Z
  //**************************************
  
  // Promedio de muestras  
  for(int n=0;n<sampleNum;n++){
     mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
    dc_offsetZ+=(int)gz;
  }
  dc_offsetZ=dc_offsetZ/sampleNum;

  // Calculo de nivel de ruido
  for(int n=0;n<sampleNum;n++){
     mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
    if((int)gz-dc_offsetZ>noiseZ)
      noiseZ=(int)gz-dc_offsetZ;
    else if((int)gz-dc_offsetZ<-noiseZ)
      noiseZ=-(int)gz-dc_offsetZ;
  }
  noiseZ=noiseZ/100;
}






