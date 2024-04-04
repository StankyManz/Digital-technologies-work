
#include <Servo.h>

const byte LEDPIN = 13;
const byte BTNPIN = 2;
const byte SERVOPIN = 3;
const byte MICROPIN = 4;

Servo latch;

void setup() { 

 pinMode(LEDPIN, OUTPUT);
 pinMode(BTNPIN, INPUT);
 pinMode(MICROPIN, INPUT);

latch.at


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