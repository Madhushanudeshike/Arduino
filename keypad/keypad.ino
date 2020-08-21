
#include <Keypad.h>

 byte rowPins[4] = {2, 3, 4, 5};

 byte colPins[4] = {6, 7, 8, 9};

char keys[4][4]= { 
  {'1', '2', '3', 'A'},

  {'4', '5', '6', 'B'},

  {'7', '8', '9', 'C'},

  {'*', '0', '#', 'D'} 
  };



Keypad myKeypad= Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
pinMode(13, OUTPUT);
Serial.begin(9600);

}


void loop() {

char key = myKeypad.getKey();

if (key != NO_KEY)

{

Serial.print(key);
if(key == '8'){
  digitalWrite(13, LOW);
  }
  else{
     digitalWrite(13, HIGH);
    }

}

}
