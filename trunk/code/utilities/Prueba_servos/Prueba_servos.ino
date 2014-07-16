// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
char a[3]; 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{
 Serial.begin(9600); 
  
  myservo.attach(52);  // attaches the servo on pin 9 to the servo object 
  myservo.write(90);
} 

 
 
void loop() {
  if(Serial.available()>0){
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
      
    Serial.flush();
    pos = atoi(a);
    Serial.println(pos);
    if(pos<10){
      pos = 10;
    }else if(pos >170)
      pos = 170;
    myservo.write(pos);
  }
 
} 
