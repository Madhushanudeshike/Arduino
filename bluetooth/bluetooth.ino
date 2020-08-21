char madhu;
void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop() {
if(Serial.available()){
   madhu = Serial.read();
  Serial.println(madhu);
  
  }


if(madhu == '1'){
  digitalWrite(9, HIGH);
  
  }else if(madhu == '2'){
    digitalWrite(9, LOW);
    }
    delay(100);
}
