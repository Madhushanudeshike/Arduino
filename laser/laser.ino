int Laser = 6;
int Detector = 7;
int Play = 13;

void setup(){ 
  Serial.begin (9600);
  pinMode(Laser, OUTPUT);
  pinMode(Detector, INPUT);
  pinMode(Play, OUTPUT);
}

void loop(){
  digitalWrite(Laser, HIGH);
  
  boolean val = digitalRead(Detector);
  Serial.println(val);
  if (val == 0) {
    digitalWrite(Play, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(Play, LOW);
  }
}
