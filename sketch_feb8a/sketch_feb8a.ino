
#include <Servo.h>

byte LedPin = 13;

const byte PAW1 = 1;
const byte PAW2 = 2;
const byte PAW3 = 3;
const byte PAW4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;

Servo LeftEar;
Servo RightEar;

void setup() { 

 pinMode(LedPin, OUTPUT);
 pinMode(PAW1, INPUT);
 pinMode(PAW2, INPUT);
 pinMode(PAW3, INPUT);
 pinMode(PAW4, INPUT);

 pinMode(LEFTEARPIN, OUTPUT);
 pinMode(RIGHTEARPIN, OUTPUT);


RightEar.attach(RIGHTEARPIN);
LeftEar.attach(LeftEARPIN);

}

void loop() {

  LeftEar.write(0)
  RightEar.write(0)
  LeftEar.write(180)
  RightEar.write(180)
  LeftEar.write(0)
  RightEar.write(0)
  LeftEar.write(180)
  RightEar.write(180)
digitalWrite(LedPin,HIGH)

}

void blinkingLed() {
  
  byte randNumber = random(1, 3);  //system chooses between

  for (int i = 0; i < randNumber; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
  }