#define trig 2
#define echo 4
void setup() {
 pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

long t = pulseIn(echo, HIGH);
long inch = t / 74 / 2;
long cm = t / 29 / 2;

Serial.print(inch);
Serial.print("in \t ");
Serial.print(cm);
Serial.println("cm");
}
