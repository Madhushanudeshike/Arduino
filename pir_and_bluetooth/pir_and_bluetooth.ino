#include <IRremote.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);
decode_results results;
String voice;
char madhu;

int sensor = 2;
int state = LOW;
int val = 0;
int led = 13;   

void allon() {
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(7, HIGH);
}
void alloff() {
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
}
void blinkyBlinky(int repeats, int time) {
  for (int i = 0; i < repeats; i++) {
    digitalWrite(9, HIGH);
    delay(time);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(time);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    delay(time);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delay(time);
    digitalWrite(12, LOW);
    delay(time);
    digitalWrite(7, HIGH);
    delay(time);
    digitalWrite(7, LOW);
  }
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

    pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input

}

void loop() {

  if (digitalRead(8) == HIGH) {
    if (irrecv.decode( & results)) {
      irrecv.resume();

      //   Serial.println(results.value);
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

      } else if (results.value == 3251430937) { //7 
        digitalWrite(7, HIGH);

      } else if (results.value == 3251377897) { //7 
        digitalWrite(7, LOW);

      } else if (results.value == 3251394982) { //6 
        allon();
      } else if (results.value == 3251399062) { //7 
        alloff();
      } else if (results.value == 3251424817) { //7 
        alloff();

      } else if (results.value == 3251427622) { //7 

        blinkyBlinky(1, 500);

      }

    }

    while (Serial.available()) { //Check if there is an available byte to read
      delay(10); //Delay added to make thing stable 
      char c = Serial.read(); //Conduct a serial read
      // Serial.println(c);
      if (c == '#') {
        break;
      } //Exit the loop when the # is detected after the word
      voice += c; //Shorthand for voice = voice + c
    }
    if (voice.length() > 0) {

      if (voice == "1") { //0 
        digitalWrite(9, HIGH);
      } else if (voice == "11") { //1 
        digitalWrite(9, LOW);

      } else if (voice == "2") { //2 
        digitalWrite(12, HIGH);
      } else if (voice == "22") { //3 
        digitalWrite(12, LOW);
      } else if (voice == "3") { //4
        digitalWrite(11, HIGH);
      } else if (voice == "33") { //5
        digitalWrite(11, LOW);

      } else if (voice == "4") { //6 
        digitalWrite(10, HIGH);
      } else if (voice == "44") { //7 
        digitalWrite(10, LOW);

      } else if (voice == "5") { //6 
        allon();
      } else if (voice == "55") { //7 
        alloff();
      } else if (voice == "6") { //7 
        blinkyBlinky(1, 500);
      }

      voice = "";
    }

  }
//////////////
//  val = digitalRead(sensor);   // read sensor value
//  if (val == HIGH) {           // check if the sensor is HIGH
//    digitalWrite(led, HIGH);   // turn LED ON
// //   delay(100);                // delay 100 milliseconds 
//    
//    if (state == LOW) {
// // Serial.println("Motion detected!"); 
//      state = HIGH;       // update variable state to HIGH
//    }
//  } 
//  else {
//      digitalWrite(led, LOW); // turn LED OFF
//     // delay(200);             // delay 200 milliseconds 
//      
//      if (state == HIGH){
//    //    Serial.println("Motion stopped!");
//        state = LOW;       // update variable state to LOW
//    }
//  }
}
