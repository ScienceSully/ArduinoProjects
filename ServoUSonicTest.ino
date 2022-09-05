#include <Servo.h>

Servo myservo;
unsigned int ADCValue;
int leftLED = 4;
int rightLED = 5;
int leftDist = 0;
int rightDist = 0;


void setup(){
    
    myservo.attach(9);
    pinMode(leftLED, OUTPUT);
    pinMode(rightLED, OUTPUT);
}
 
void loop(){
  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, LOW);
  
    myservo.write(30);
    delay(1000);
    leftDist = analogRead(A0);
    
    myservo.write(120);
    delay(1000);
    rightDist = analogRead(A0);

    if (leftDist < rightDist) 
    {
      digitalWrite(rightLED, HIGH);
    }
    else
    {
      digitalWrite(leftLED, HIGH);
    }
delay(3000);
}
