int input1 = 3; // Arduino'nun 3. digital pinine bağlanmıştır.
int input2 = 4; // Arduino'nun 4. digital pinine bağlanmıştır.
int input3 = 5; // Arduino'nun 5. digital pinine bağlanmıştır.
int input4 = 6; // Arduino'nun 6. digital pinine bağlanmıştır.



void setup() {
//  Serial.begin (9600);

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

void stopMovement(){
 //  Motorlar DURSUN // stop
 digitalWrite(input1,LOW);
 digitalWrite(input2,LOW);  
 digitalWrite(input3,LOW);
 digitalWrite(input4,LOW);  
 
 
}

void moveBackward(){
  //Motorlar Geri // back
  digitalWrite(input1,LOW);
  digitalWrite(input2,HIGH);  
  digitalWrite(input3,LOW);
  digitalWrite(input4,HIGH);  
}


void loop() {
   
  moveForward();
  delay(3000);

}
