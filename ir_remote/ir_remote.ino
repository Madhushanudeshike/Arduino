#include<IRremote.h>

IRrecv Madhu(11);
decode_results results;
void setup() {
  Serial.begin(9600);
  Madhu.enableIRIn();
  pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop() {
  if(Madhu.decode(&results)){
    Serial.println(results.value, DEC);
    Madhu.resume();
    }
delay(100);

  long val = results.value;

  if(val == 16753245){
    digitalWrite(7, HIGH);
     digitalWrite(8, HIGH);
   }

  if(val == 16756815){
    digitalWrite(7, LOW);
     digitalWrite(8, LOW);
   }
   //////////////////////////// peo tv


  if(val == 3251406457){
    digitalWrite(7, HIGH);
     digitalWrite(8, HIGH);
   }

  if(val == 3251390137){
    digitalWrite(7, LOW);
     digitalWrite(8, LOW);
   }


   //////////////////
    if(val == 1033561079){
      digitalWrite(8, HIGH);
      }

    if(val == 1635910171){
      digitalWrite(7, HIGH);
      }
      
  if(val == 16716015){
    digitalWrite(7, LOW);
    
    }

    if(val == 1217346747){
      digitalWrite(8, LOW);
     }

         if(val == 16734885){
          
      digitalWrite(7, HIGH);
      delay(100);
        digitalWrite(7, LOW);
      
       digitalWrite(8, HIGH);
      delay(100);
        digitalWrite(8, LOW);
      delay(100);
      digitalWrite(7, HIGH);
      delay(100);
        digitalWrite(7, LOW);
      
       digitalWrite(8, HIGH);
      delay(100);
        digitalWrite(8, LOW);
      delay(100);
     }


}
