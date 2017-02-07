#include <Arduino.h>

const int sensorPin = 0x28;
const float baselineTemp = 25.0;

void setup()
{

  Serial.begin(9600);

  uint8_t* PINNUMBER = (uint8_t*)0x2A;

  for(int pinNumber = 2; pinNumber<5; pinNumber++)
    *PINNUMBER |= (1 << pinNumber);

}

void loop()
{
  uint8_t* LED = (uint8_t*)0x2B;

  int sensorVal = analogRead(A0);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");

  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp+2)
  {
    *LED |= (1 << 2);
    *LED &= ~(1 << 3);
    *LED &= ~(1 << 4);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4)
  {
    *LED |= (1 << 2);
    *LED |= (1 << 3);
    *LED &= ~(1 << 4);
  }
  else if(temperature >= baselineTemp+6)
  {
    *LED |= (1 << 2);
    *LED |= (1 << 3);
    *LED |= (1 << 4);
  }
  delay(1);
}
