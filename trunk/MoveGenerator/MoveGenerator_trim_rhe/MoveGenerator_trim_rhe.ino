#include <Servo.h> 

#define N 22 //number of servos
//Settings
Servo servoList[N]; //Listado de servos
int servoPins[N] = {32,25,24,45,44,23,43,31,30,33,12,13,6,7,10,11,4,5,8,9,2,3}; //Listado de los N pins
int trim [N] ={0,-1,12,-5,-1,0,0,-7,5,-6,18,3,-12,-12,1,0,-4,-3,0,-2,2,0};

char serialReadString[50];//stores the recieved characters
int stringPosition=-1;//stores the current position of my serialReadString

void setup(){
  Serial.begin(115200);

  for (int i=0;i<N;i++){
    servoList[i].attach(servoPins[i]);  // attache the servo on the given servoPin
  }
}

void loop(){
   readSerialLine();//check for incoming data
}

//Method check for incoming charactersand stores them in serialReadString
//if a new line character is detected, the string serialReadString is closed
//and the method stringReceived is called
void readSerialLine(){
  while (Serial.available() > 0){ // As long as there's more to read, keep reading
      int inByte = Serial.read();// Read next byte
      stringPosition++;//increase the position in the string
      if(inByte=='\n'){//if it's my terminating character
         serialReadString[stringPosition] = 0;//set current position to Null to terminate the String
          stringReceived();//call the method, to encode the recieved signal
          stringPosition=-1;//set the string position to -1
      }else{//if it's not a terminating character
          serialReadString[stringPosition] = inByte; // Save the character in a character array
      }
  }
}

//Method is called after a new Command is recieved
void stringReceived(){
      int i=0;
      char servoPos[10];//create a new String to store the characters of the value
      char servoNumber[10];
        
      while(serialReadString[i]!=';'){//run through all the characters after "s;s1,"  
        servoNumber[i]=serialReadString[i];//and store them in the new String
        i++;//increase for new position
      }      
      servoNumber[i]=0;//terminate the String
      i++;

      int j=0;
      while(serialReadString[i]!=0){
        servoPos[j]=serialReadString[i];
        i++;
        j++;
      }
      
      servoPos[j]=0;//terminate the String
      int receivedServo=atoi(servoNumber);
      int recievedPosition=atoi(servoPos);//convert String to int
      servoList[receivedServo].write(recievedPosition + trim[receivedServo]);//set the Servo
  }

