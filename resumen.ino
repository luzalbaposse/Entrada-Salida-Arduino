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
int time_stamp = 0;

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

  // Estado inicial: LEDs verticales, servomotor horizontal
  int horizontal = 90;  // Posición horizontal media para el servomotor
  int vertical = 0;    // Valor inicial para los LEDs verticales
  servo1.write(horizontal);
  digitalWrite(ledPin0, (vertical & 1));
  digitalWrite(ledPin1, (vertical & 2));
  digitalWrite(ledPin2, (vertical & 4));
}

void loop() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int horizontal, vertical;

  if (button) {
    horizontal = map(yPosition, 0, 1023, 0, 180);
    vertical = map(xPosition, 0, 1023, 0, 7);
  } else {
    horizontal = map(xPosition, 0, 1023, 0, 180);
    vertical = map(yPosition, 0, 1023, 0, 7);
  }

  servo1.write(horizontal);

  digitalWrite(ledPin0, (vertical & 1));
  digitalWrite(ledPin1, (vertical & 2));
  digitalWrite(ledPin2, (vertical & 4));

  if (time_stamp > 0) {
    time_stamp = time_stamp - 1;
  }

  delay(2);
}

void click() {
  if (time_stamp == 0) {
    if (button == 0) {
      button = 1;
    } else {
      button = 0;
    }
  }
}
