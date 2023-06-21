/*
Modificar el programa para que el movimiento de izquierda a derecha del Joystick, 
reproduzca el mismo comportamiento que el Servo de 0 a 180 grados.
*/
#include <Servo.h>

const int VRx = A1;
const int servoPin = 10;
Servo servo1;

void setup() {
  servo1.attach(servoPin);
}

void loop() {
  int xPosition = analogRead(VRx);
  int mapX = map(xPosition, 0, 1023, 0, 180);
  servo1.write(mapX);
  delay(10);
}
