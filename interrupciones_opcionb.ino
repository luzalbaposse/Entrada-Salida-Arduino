/*
 Modificar el programa para que cada vez que se presiona el botón del Joystick se intercambie 
 el sentido de rotación del Servo.
*/

#include <Servo.h>

Servo servo1;
const int servoPin = 10;
const byte interruptPin = 2;
volatile byte button = 0;
const int ledPin0 = 4;
const int ledPin1 = 5;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;
int time_stamp = 0;

void setup() {
  servo1.attach(servoPin);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);
  int angulo1 = (map(xPosition, 0, 1023, 0, 180));
  
  if (button == 1) {
    digitalWrite(ledPin0, HIGH);
    angulo1 = (map(xPosition, 0, 1023, 180, 0));
  } else {
    digitalWrite(ledPin0, LOW);
  }

  servo1.write(angulo1);
  int brillo = map(yPosition, 0, 1023, -255, 255);
  analogWrite(ledPin1, abs(brillo));

  if (time_stamp > 0) {
    time_stamp = time_stamp - 1;
  }

  delay(10);

}

void click() {
  if (time_stamp == 0) {
    if (button == 0) {
      button = 1;
      time_stamp = 40;
    } else {
      button = 0;
      time_stamp = 40;
    }
  }
}
