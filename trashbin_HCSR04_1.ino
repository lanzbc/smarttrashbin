#include<Servo.h>
int trig = 13;    
int echo = 12;
int servoPin = 10;
Servo servo;

void setup(){
 Serial.begin(9600); 
 servo.attach(servoPin);
 pinMode(trig, OUTPUT);  
 pinMode(echo, INPUT); 
}

void loop(){    
    Serial.print(distance());
    Serial.println("cm");
    delay(200);
  if(distance()<30){
    do{
    Serial.println(distance());
      servo.write(75);
    }while(distance()<30);
    delay(5000);   
    for(int i=75;i>0;i--){
      servo.write(i);
      delay(20);
    }
  }
  else {
    servo.write(0);
    }    
}
float distance(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  int timer = pulseIn(echo, HIGH);
  return timer/58.3f; 
}
