#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>


const int trigPin = 9;
const int echoPin = 10;
// defining variables
long duration;
int distance;
/*
SoftwareSerial Bluetooth(0, 1);
char Data;
void sendData(String transmitData){
Bluetooth.println(transmitData);}
*/

int input1 = 3; // Arduino'nun 3. digital pinine bağlanmıştır.
int input2 = 4; // Arduino'nun 4. digital pinine bağlanmıştır.
int input3 = 5; // Arduino'nun 5. digital pinine bağlanmıştır.
int input4 = 6; // Arduino'nun 6. digital pinine bağlanmıştır.



void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
//Motorları sürmek için input pinleri çıkış olarak ayarlandı.  
//Motors have been set up to drive the input to the output pins.
pinMode(input1,OUTPUT);
pinMode(input2,OUTPUT);
pinMode(input3,OUTPUT);
pinMode(input4,OUTPUT);

}

void moveForward(){
  //MOtorlar İleri //forward
  digitalWrite(input1,LOW);
  digitalWrite(input2,HIGH);  
  digitalWrite(input4,LOW);
  digitalWrite(input3,HIGH);  
  
}

void turnRight(){
  //MOtorlar İleri //forward
  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW); 
   
  digitalWrite(input4,LOW);
  digitalWrite(input3,HIGH);  
  
}

void turnLeft(){
  //MOtorlar İleri //forward
  digitalWrite(input1,LOW);
  digitalWrite(input2,HIGH); 
   
  digitalWrite(input4,LOW);
  digitalWrite(input3,LOW);  
  
}

void stopMovement(){
 //  Motorlar DURSUN // stop
 digitalWrite(input1,LOW);
 digitalWrite(input2,LOW);  
 digitalWrite(input3,LOW);
 digitalWrite(input4,LOW);  
 
 
}

void moveBackward(){
  //Motorlar Geri // back
   digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);  
  digitalWrite(input4,HIGH);
  digitalWrite(input3,LOW);  
}


void loop() {// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

  turnRight();
  delay(1000);
  stopMovement();
  delay(5000);
  /*
  if(Bluetooth.available()){
        Data=Bluetooth.read();
        if(Data==('1')){
            moveForward();
            sendData("Moving forward");
        }
        if(Data==('0')){
            stopMovement();
            sendData("Moving stopped");
        }
    }
  */

}
