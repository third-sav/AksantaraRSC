#include <Wire.h>
#include <SPI.h>
#define CLK 7
#define SS 8
#define MOSI 9
#define MISO 10

int pushButton = A0;
int x=0;


void setup()
{
  Wire.begin();
  pinMode(pushButton, INPUT);
  
  	pinMode(CLK, OUTPUT);
	pinMode(MOSI, OUTPUT);
    pinMode(MISO, INPUT);
	pinMode(SS, OUTPUT);
  digitalWrite(SS,HIGH);
 
}

void loop()
{
  x = digitalRead(pushButton);
  
  //SPI
  if (x == LOW) {
    digitalWrite(SS, LOW);           
    SPI.transfer(0x01);              
    digitalWrite(SS, HIGH);
  }

  
 
  

}