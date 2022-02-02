#include <SoftwareSerial.h>


SoftwareSerial nodemcu(2,3);
#include <Servo.h>
Servo servo1;
int trigPin = 11;
int echoPin = 12;
long distance;
long duration;

int parking1_slot1_ir_s = 4; // parking slot1 infrared sensor connected with pin number 4 of arduino
int parking1_slot2_ir_s = 5;
int parking1_slot3_ir_s = 6;

int parking2_slot1_ir_s = 7;
int parking2_slot2_ir_s = 8;
int parking2_slot3_ir_s = 9;

String sensor1; 
String sensor2; 
String sensor3; 
String sensor4; 
String sensor5; 
String sensor6; 


String cdata =""; // complete data, consisting of sensors values

void setup()
{
  parks();
Serial.begin(9600); 
nodemcu.begin(9600);

pinMode(parking1_slot1_ir_s, INPUT);
pinMode(parking1_slot2_ir_s, INPUT);
pinMode(parking1_slot3_ir_s, INPUT);

pinMode(parking2_slot1_ir_s, INPUT);
pinMode(parking2_slot2_ir_s, INPUT);
pinMode(parking2_slot3_ir_s, INPUT);

servo1.attach(10); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop()
{

p1slot1(); 
p1slot2();
p1slot3(); 

p2slot1();
p2slot2();
p2slot3();

  
  
   cdata = cdata + sensor1 +"," + sensor2 + ","+ sensor3 +","+ sensor4 + "," + sensor5 + "," + sensor6 +","; // comma will be used a delimeter
   Serial.println(cdata); 
   nodemcu.println(cdata);
   delay(6000); // 100 milli seconds
   cdata = ""; 
digitalWrite(parking1_slot1_ir_s, HIGH); 
digitalWrite(parking1_slot2_ir_s, HIGH); 
digitalWrite(parking1_slot3_ir_s, HIGH);

digitalWrite(parking2_slot1_ir_s, HIGH);
digitalWrite(parking2_slot2_ir_s, HIGH);
digitalWrite(parking2_slot3_ir_s, HIGH);

ultra();
  servo1.write(0);
  if(distance <= 10){
    
  servo1.write(90);
  }

}


void p1slot1() // parkng 1 slot1
{
  if( digitalRead(parking1_slot1_ir_s) == LOW) 
  {
  sensor1 = "255";
 delay(200); 
  } 
if( digitalRead(parking1_slot1_ir_s) == HIGH)
{
  sensor1 = "0";  
 delay(200);  
}

}

void p1slot2() // parking 1 slot2
{
  if( digitalRead(parking1_slot2_ir_s) == LOW) 
  {
  sensor2 = "255"; 
  delay(200); 
  }
if( digitalRead(parking1_slot2_ir_s) == HIGH)  
  {
  sensor2 = "0";  
 delay(200);
  } 
}


void p1slot3() // parking 1 slot3
{
  if( digitalRead(parking1_slot3_ir_s) == LOW) 
  {
  sensor3 = "255"; 
  delay(200); 
  }
if( digitalRead(parking1_slot3_ir_s) == HIGH)  
  {
  sensor3 = "0";  
 delay(200);
  } 
}


// now for parking 2

void p2slot1() // parking 1 slot3
{
  if( digitalRead(parking2_slot1_ir_s) == LOW) 
  {
  sensor4 = "255"; 
  delay(200); 
  }
if( digitalRead(parking2_slot1_ir_s) == HIGH)  
  {
  sensor4 = "0";  
 delay(200);
  } 
}


void p2slot2() // parking 1 slot3
{
  if( digitalRead(parking2_slot2_ir_s) == LOW) 
  {
  sensor5 = "255"; 
  delay(200); 
  }
if( digitalRead(parking2_slot2_ir_s) == HIGH)  
  {
  sensor5 = "0";  
 delay(200);
  } 
}


void p2slot3() // parking 1 slot3
{
  if( digitalRead(parking2_slot3_ir_s) == LOW) 
  {
  sensor6 = "255"; 
  delay(200); 
  }
if( digitalRead(parking2_slot3_ir_s) == HIGH)  
  {
  sensor6 = "0";  
 delay(200);
  } 
}

void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
}
void parks(){
int ran = 1+ rand()%6;
switch (ran) {
  case 1:
     Serial.print("go to p1s1");
    break;
  case 2:
     Serial.print("go to p1s2") ;
    break;
  case 3:
     Serial.print( "go to p1s3");
    break;
  case 4:
     Serial.print("go to p2s1");
    break;
  case 5:
     Serial.print ("go to p2s2");
    break;
  case 6:
    Serial.print ("go to p2s3");
    break;
 
 }
} 
