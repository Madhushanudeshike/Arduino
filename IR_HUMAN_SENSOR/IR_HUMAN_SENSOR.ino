int inputPin = 9;      
int pirState = LOW; 
int val = 0; 
 
void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);
  if (val == HIGH) { 
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
