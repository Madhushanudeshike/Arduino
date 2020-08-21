void setup() {
  pinMode(8, INPUT);
  pinMode(7, OUTPUT);
Serial.begin(9600);
}

void loop( ) {
 int val = digitalRead(8);
 Serial.println(val);
 if(val == 1){
  digitalWrite(7, HIGH);
  }else{
    digitalWrite(7, LOW);
    }

}
