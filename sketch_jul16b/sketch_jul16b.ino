void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(2, INPUT);// Input from sensor
  pinMode(7, OUTPUT);// OUTPUT to alarm or LED
}

void loop() {
  int motion =digitalRead(2);
  if(motion){
    Serial.println("Motion detected");
    digitalWrite(7,HIGH);
  }else{
     Serial.println("===nothing moves");
     digitalWrite(7,LOW);
  }
  delay(500);

}
