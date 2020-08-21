#include <IRremote.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);
decode_results results;
String voice;
char madhu;
void allon() {
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}
void alloff() {
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void setup() {
    irrecv.enableIRIn();
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(7, OUTPUT);
    Serial.begin(9600);

}

void loop() {
  
  if (digitalRead(8) == HIGH) {
    if (irrecv.decode( & results)) {
        irrecv.resume();

         Serial.println(results.value);
      if (results.value == 3251406457) { //0 
        digitalWrite(9, HIGH);
      } else if (results.value == 3251397277) { //1 
        digitalWrite(9, LOW);
      } else if (results.value == 3251390137) { //2 
        digitalWrite(12, HIGH);
      } else if (results.value == 3251429917) { //3 
        digitalWrite(12, LOW);
      } else if (results.value == 3251422777) { //4
        digitalWrite(11, HIGH);
      } else if (results.value == 3251376877) { //5
        digitalWrite(11, LOW);
      } else if (results.value == 3251381977) { //6 
        digitalWrite(10, HIGH);
      } else if (results.value == 3251409517) { //7 
        digitalWrite(10, LOW);
      } else if (results.value == 0x1FEF00F) { //8 GARAGE DOOR OPEN
        digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
        delay(700);
        digitalWrite(2, HIGH);
      } else if (results.value == 0x1FE9867) { //9 GARAGE  DOOR CLOSE 
        digitalWrite(3, LOW); // turn the LED off by making the voltage LOW
        delay(700);
        digitalWrite(3, HIGH);
      }
    }
 if(digitalRead(8) == LOW){

 Serial.println("sssssssssssssssssssssssssssss");

        if (Serial.available()) {
        madhu = Serial.read();
        Serial.println(madhu);

  

        
    }


    
//    while (Serial.available()) { //Check if there is an available byte to read
//          Serial.println("sdds");
//      delay(10); //Delay added to make thing stable 
//      char c = Serial.read(); //Conduct a serial read
//       Serial.println(c);
//      if (c == '#') {
//        break;
//      } //Exit the loop when the # is detected after the word
//      voice += c; //Shorthand for voice = voice + c
//    }
//
//    Serial.println(voice);
//    if (voice.length() > 0) {
//      Serial.println(voice);
//      
//      //-----------------------------------------------------------------------//    
//      //----------Control Multiple Pins/ LEDs----------//  
//      if (voice == "*all on") {
//        allon();
//      } //Turn Off All Pins (Call Function)
//      else if (voice == "*turn off everything") {
//        alloff();
//      } //Turn On  All Pins (Call Function)
//
//      //----------Turn On One-By-One----------// 
//      else if (voice == "*living room lights on") {
//        digitalWrite(12, HIGH);
//      } else if (voice == "*fan on") {
//        digitalWrite(9, HIGH);
//      } else if (voice == "*dining hall lights on") {
//        digitalWrite(10, HIGH);
//      } else if (voice == "*bedroom lights on") {
//        digitalWrite(11, HIGH);
//      } else if (voice == "*open garage door") {
//        digitalWrite(3, HIGH);
//        digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
//        delay(700);
//        digitalWrite(2, HIGH);
//      }
//
//      //----------Turn Off One-By-One----------// 
//      else if (voice == "*living room lights off") {
//        digitalWrite(12, LOW);
//      } else if (voice == "*fan off") {
//        digitalWrite(9, LOW);
//      } else if (voice == "*dining hall lights off") {
//        digitalWrite(10, LOW);
//      } else if (voice == "*bedroom lights off") {
//        digitalWrite(11, LOW);
//      } else if (voice == "*close garage door") {
//        digitalWrite(2, HIGH);
//        digitalWrite(3, LOW); // turn the LED off by making the voltage LOW
//        delay(700);
//        digitalWrite(3, HIGH);
//      }
//
//      //-----------------------------------------------------------------------//  
//      voice = "";
//       Serial.println("zzzzzzzzzzzzz");
//    }
    
//    }

}
