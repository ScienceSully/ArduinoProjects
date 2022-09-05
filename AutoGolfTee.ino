#include <Servo.h>
int angle = 1;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(A0, INPUT);
myservo.attach(9);
Serial.begin(9600);
}

void loop() {

Serial.println(analogRead(A0));
if (analogRead(A0) < 200) {
delay(500);
for (angle = 0; angle <= 90; angle += 1){
  myservo.write(angle);
  delay(15);
}

delay(1000);

for (angle = 90; angle >= 0; angle -= 5){
  myservo.write(angle);
  delay(20);
    }

delay(1000);
  }
}
