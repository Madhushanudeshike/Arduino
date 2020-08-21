#include <IRremote.h>

int RECV_PIN = 8; // IR Receiver - Arduino Pin Number 8
IRrecv irrecv(RECV_PIN);
decode_results results;

int delayTime = 100;
char madhu;

int led = 7;
int sensor = 2;
int state = LOW;
int val = 0;

int checker = LOW;

int webVar = LOW;

void setup()
{
  
    pinMode(sensor, INPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(7, OUTPUT);
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop()
{

  int webVar;

    // bluetooth
    if (Serial.available()) {
        madhu = Serial.read();
        Serial.println(madhu);

  

        
    }


    if (madhu == '1') {
        digitalWrite(9, HIGH);
        
    }
    if (madhu == '2') {
        digitalWrite(10, HIGH);
    }
    if (madhu == '3') {
        digitalWrite(11, HIGH);
    }
    if (madhu == '4') {
        digitalWrite(12, HIGH);
    }
    if (madhu == '5') {
//        digitalWrite(9, HIGH);
//        digitalWrite(10, HIGH);
//        digitalWrite(11, HIGH);
//        digitalWrite(12, HIGH);
onMyfun(6);

    }
    if (madhu == '6') {
//        digitalWrite(9, LOW);
//        digitalWrite(10, LOW);
//        digitalWrite(11, LOW);
//        digitalWrite(12, LOW);
//        webVar = 4;

offMyfun(0);
    }


//pir

            val = digitalRead(sensor);


    


            
            if(val == HIGH){
              
                  if (state == LOW) {
                      Serial.println("Motion detected!");
                      digitalWrite(7, HIGH);
                      state = HIGH;
                  }



                  
              }else{
               
                  if (state == HIGH) {
                    digitalWrite(7, LOW);
                      Serial.println("stopped!");
                      state = LOW;
                  }

          
                
                }


    // IR Receiver

    if (irrecv.decode(&results)) {
        Serial.println(results.value);

        if (results.value == 3251376877) {
            digitalWrite(9, HIGH);
            delay(delayTime);
        }

        if (results.value == 3251429917) {
            digitalWrite(10, HIGH);
            delay(delayTime);
        }

        if (results.value == 3251409517) {
            digitalWrite(11, HIGH);
            delay(delayTime);
        }

        if (results.value == 3251397277) {
            digitalWrite(12, HIGH);
            delay(delayTime);
        }

        if (results.value == 3251424817) {

        webVar = LOW;
offMyfun(0);
//            digitalWrite(9, LOW);
//            digitalWrite(10, LOW);
//            digitalWrite(11, LOW);
//            digitalWrite(12, LOW);
//            delay(delayTime);
        }

        if (results.value == 3251427622) {

            webVar = HIGH;
              onMyfun(6);

//            digitalWrite(9, HIGH);
//            digitalWrite(10, HIGH);
//            digitalWrite(11, HIGH);
//            digitalWrite(12, HIGH);
//            delay(delayTime);
        }
        
        irrecv.resume();
    }


   if(webVar == HIGH){
    
     Serial.println("x");
    
    }else if(webVar == LOW){
      
      Serial.println("y");
      }



}

int onMyfun(int x){
  int result;
  result = x;
  Serial.println(result);

             digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            delay(delayTime);

            
 // return result;
}

int offMyfun(int x){
  int result;
  result = x;
  Serial.println(result);

             digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            delay(delayTime);

            
 // return result;
}
