#include <Wire.h>
int pushButton = A0;
int x=0;


void setup()
{
  Wire.begin();
  pinMode(pushButton, INPUT);

}

void loop()
{
  x = digitalRead(pushButton);
  //I2C
  Wire.beginTransmission(1);
  Wire.write(x);
  Wire.endTransmission();
  delay(100);

}