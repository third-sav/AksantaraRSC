#include <SPI.h>
#include <LiquidCrystal.h>

// SPI pin
#define CLK 7
#define SS 8
#define MOSI 9
#define MISO 10

// LCD pin
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(MISO, OUTPUT); // MISO output
  pinMode(SS, INPUT);    // SS input
  SPI.begin();           // SPI
  SPCR |= _BV(SPE);      // Slave mode

  //  LCD
  lcd.begin(16, 2);    
  lcd.print("Standby. . ."); // No Warning
}

void loop() {
  if (digitalRead(SS) == LOW) { // Check 
    byte receivedData = SPI.transfer(0x00); // Receive

    if (receivedData == 0x01) { // Check if signal is 0x01
      displayWarning();
    }
  }
}

// Display Warning on LCD
void displayWarning() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WARNING!!");   // Print warning 
  delay(5000);              // Keep message for 5 seconds
  lcd.clear();
  lcd.print("Standby...");    // Reset
}
