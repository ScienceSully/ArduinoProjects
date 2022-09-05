#include <Servo.h>
#include <CuteBuzzerSounds.h>
/*
 S_CONNECTION   S_DISCONNECTION S_BUTTON_PUSHED   
 S_MODE1        S_MODE2         S_MODE3     
 S_SURPRISE     S_OHOOH         S_OHOOH2    
 S_CUDDLY       S_SLEEPING      S_HAPPY     
 S_SUPER_HAPPY  S_HAPPY_SHORT   S_SAD       
 S_CONFUSED     S_FART1         S_FART2     
 S_FART3        S_JUMP 20
 */

Servo myservo;

int distF = 0;
int distR = 0;
int distL = 0;

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 11;
int ENA = 5;
int ENB = 6;


void setup() {
  myservo.attach(9);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); 
  pinMode(ENB, OUTPUT);
  pinMode(A0, INPUT);
  analogWrite(ENA, 80);
  analogWrite(ENB, 80);
 cute.init(7);
  myservo.write(90);
  Serial.begin(9600);
  cute.play(S_CUDDLY);
  delay(1000);
}

void loop() {
 goforward();
 distF = (analogRead(A0));
 Serial.println(distF);
 if (distF < 250){
  off();
  cute.play(S_SURPRISE);
  delay(1000);
  goback();
  off();
  look();
  }
}

void goforward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(100);
}

void goback()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1000);
}

void turnleft()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);
}

void turnright()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);
}

void off()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
}

void look()
{
  cute.play(S_OHOOH2);
  delay(1000);
  myservo.write(30);
  delay(1000);
  distL = (analogRead(A0));
  delay(50);
  myservo.write(150);
  delay(1000);
  distR = (analogRead(A0));
  delay(50);
  cute.play(S_SUPER_HAPPY);
  delay(1000);
  if (distL < distR){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(100);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(100);
  }
  myservo.write(90);
  delay(500);

}
