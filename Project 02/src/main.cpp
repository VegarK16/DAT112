#include <Arduino.h>

uint8_t* PIN_Direction = (uint8_t*)0x2A;
uint8_t* PIN_Data = (uint8_t*)0x29;
uint8_t* PIN_Shine = (uint8_t*)0x2B;
void setup()
{


for(int PINNUMBER = 3; PINNUMBER <= 5;PINNUMBER++)
  *PIN_Direction |= (1 << PINNUMBER);

  //pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);

*PIN_Direction |= (0 << 2);
//pinMode(2, INPUT);
}
void loop(){
  //switchState = digitalRead(2);

  if (!(*PIN_Data & (1 << 2))){
    *PIN_Shine |= (1 << 3);
    *PIN_Shine &= ~(1 << 4);
    *PIN_Shine &= ~(1 << 5);

  }
  else
  {
    *PIN_Shine &= ~(1 << 3);
    *PIN_Shine &= ~(1 << 4);
    *PIN_Shine |= (1 << 5);

    /*
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
*/

    delay(250);
    *PIN_Shine |= (1 << 4);
    *PIN_Shine &= ~(1 << 5);
/*
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
*/
    delay(250);
  }
}
