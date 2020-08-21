int LDRValue = 0;     // result of reading the analog pin
const int LDRpin = A0;
void setup() {
  Serial.begin(9600); // sets serial port for communication
}

void loop() {
  LDRValue = analogRead(LDRpin); // read the value from the LDR
  Serial.println(LDRValue);      // print the value to the serial port
  delay(100);                    // wait a little
}
