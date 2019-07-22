#include<Servo.h>
int trig = 13;    
int echo = 12;
int trig2 = 9;    
int echo2 = 8;
int led1 = 7;
int led2 = 6;
int servoPin = 10;
Servo servo;

void setup(){
 Serial.begin(9600); 
 servo.attach(servoPin);
 pinMode(trig, OUTPUT);  
 pinMode(echo, INPUT); 
 pinMode(trig2, OUTPUT);  
 pinMode(echo2, INPUT); 
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
}

void loop(){    
      distance();
//    Serial.println(distance());
//    Serial.println("cm");
//    delay(200);
  if(distance()<30){
    do{      
      servo.write(90);
      distance();
    }while(distance()<30);
    delay(5000);   
    for(int i=90;i>0;i--){
      servo.write(i);
      delay(20);
    }
  }
  else {
    servo.write(0);
    } 
//    Serial.print(distance2());
  distance2();
  if(distance2()<15){
    digitalWrite(led1,HIGH);
  }
  else{
    digitalWrite(led1,LOW);
  }
  if(distance2()<8){
    
    digitalWrite(led2,HIGH);
  }
  else{
    digitalWrite(led2,LOW);
  }
}
float distance(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  int timer = pulseIn(echo, HIGH);
  return timer/58.3f; 
}
float distance2(){
  digitalWrite(trig2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2,LOW);
  int timer = pulseIn(echo2, HIGH);
  return timer/58.3f; 
}
