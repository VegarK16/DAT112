#include<Servo.h>
#include<Arduino.h>

Servo myServo;
int const potPin = A0;
uint8_t* inputPin = (uint8_t*)0x28;
int potVal;
int angle;

void setup(){
  noInterrupts();
  PCICR |= (1 << PCIE1);
  PCMSK1 |= (1 << PCINT8);
  digitalWrite(A0, HIGH);
  interrupts();
  myServo.attach(9);
  Serial.begin(9600);
}

ISR(PCINT1_vect){
  Serial.print("Victory!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.println(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print("angle: ");
  Serial.println(angle);
}

void loop(){
  potVal = analogRead(potPin);
//  Serial.print("potVal: ");
  //Serial.println(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  //Serial.print("angle: ");
  //Serial.println(angle);
  myServo.write(angle);
  delay(15);
}
