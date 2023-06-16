/*
Utilizado lo aprendido en los puntos anteriores construir un programa que respete el siguiente
comportamiento:
Los leds van a mostrar contando del 000 al 111 la posici´on del Joystick en sentido vertical.
El movimiento del Joystick en sentido horizontal deber´a mover el Servo en todo su rango.
Si se presiona el botón del Joystick se intercambiar´a el comportamiento de los ejes vertical y
horizontal.
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
  int horizontal = map(xPosition, 0, 1023, 0, 180);
  servo1.write(horizontal);
  int vertical = map(yPosition, 0, 1023, 0, 7);
  int led0 = vertical & 1;
  int led1 = vertical & 2;
  int led2 = vertical & 4;
  digitalWrite(ledPin0, led0);
  digitalWrite(ledPin1, led1);
  digitalWrite(ledPin2, led2);
  
  if (button) {
    int aux = horizontal;
    int aux2 = vertical;
    horizontal = aux2;
    vertical = aux;
  }
  
  delay(100); // Agrega un retraso de 100 milisegundos para evitar que se ejecute demasiado rápido. El objetivo es ayudar a estabilizar la lectura del joystick 
}

void click() {
  if (button == 0) {
    button = 1;
  } else {
    button = 0;
  }
}
