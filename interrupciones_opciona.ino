/*
Modificar el programa para que cada vez que se presiona el botón del Joystick se prendan todos los leds y estos queden prendidos. Cuando se presione nuevamente, estos se deben apagar. 
*/
#include <Servo.h>
Servo servo1;
const int servoPin = 10;
const byte interruptPin = 2;
volatile byte button = 0;
const int ledPin0 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;
int time_stamp = 0; // Usamos time_stamp para solucionar el problema con las interrupciones

void setup() {
  servo1.attach(servoPin);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
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
  int angulo1 = map(xPosition, 0, 1023, 0, 180);
  servo1.write(angulo1);
  int brillo = map(yPosition, 0, 1023, -255, 255);
  analogWrite(ledPin1, abs(brillo));
  
  if (button) {
    digitalWrite(ledPin0, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    time_stamp = 250;
  } else{
    digitalWrite(ledPin0, LOW);
    //digitalWrite(ledPin1, LOW); Como se juega con el brillo de este pin, lo dejamos relacionado al estado que tenga
    digitalWrite(ledPin2, LOW);
    time_stamp = 250;
  }
  if (time_stamp > 0){
    time_stamp = time_stamp - 1;
  }
  delay(2);
}

void click() {
  if(time_stamp == 0){
if (button == 0) {
    button = 1;
  } else {
    button = 0;
  } 
  }
}
