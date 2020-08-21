#include<IRremote.h>

IRrecv Madhu(11);
decode_results results;
void setup() {
  Serial.begin(9600);
  Madhu.enableIRIn();
  pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
}

void loop() {
  if(Madhu.decode(&results)){
    Serial.println(results.value, DEC);
    Madhu.resume();
    }
delay(100);

  long val = results.value;

  if(val == 16732845){
    digitalWrite(8, HIGH);
    
    }

    if(val == 16730805){
      digitalWrite(9, HIGH);
      
      }

  if(val == 16728765){
    digitalWrite(8, LOW);
    
    }

    if(val == 16734885){
      digitalWrite(9, LOW);
      
      }

    if(val == 16756815){
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      
      }

      
    if(val == 16753245){
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      
      }

}
