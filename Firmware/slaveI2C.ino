#include <Wire.h>
int pinLed=13;
int pinPlez=6;
int x=0;

void setup()
{
  //I2C
  //Inisialisasi, slave 1, jika match dengan master, respon, receiveEvent
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  pinMode(pinLed,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany){
  x= Wire.read();
  if (x == 1){
  	digitalWrite(pinLed, HIGH);
    digitalWrite(pinPlez, HIGH);
  }
  else{
  	digitalWrite(pinLed, LOW);
    digitalWrite(pinPlez, LOW);
  }
}