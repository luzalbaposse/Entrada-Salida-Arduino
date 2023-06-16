/*
Modificar el programa para que el Servo reproduzca el siguiente patrón de comportamiento 
una y otra vez, cambiando de posición cada 2 segundos. 1 0 grados 
2 90 grados 3 45 grados 4 180 grados 
*/
#include <Servo.h> 
const int servoPin = 10; 
Servo servo1; 
void setup() { 
servo1.attach(servoPin); 
} 
void loop() { 
servo1.write(0); 
delay(2000); 
servo1.write(90); 
delay(2000); 
servo1.write(45); 
delay(2000); 
servo1.write(180); 
delay(2000); 
} 
