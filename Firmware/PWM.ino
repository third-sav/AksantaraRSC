
int pwmPin = 13;
void setup() {
  
  pinMode(pwmPin, OUTPUT);
}
void loop() {
digitalWrite(pwmPin, HIGH);  // pin HIGH (ON)
  delay(1000);  // Delay
  
  digitalWrite(pwmPin, LOW);   // Set pin LOW (OFF)
  delay(1000);  // Delay 
}