

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int pin = 33;  
 
void setup() 
{ 
  myservo.attach(pin);  
} 
 
void loop() 
{ 
  myservo.write(90);                  
  delay(15);                          
} 
