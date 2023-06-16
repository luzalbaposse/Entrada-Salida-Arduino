#include <Servo.h> 
Servo servo1; 
const int servoPin = 10; // Define el pin
const byte interruptPin = 2; 
volatile byte button = 0; 
const int ledPin0 = 4; 
const int ledPin1 = 5; 
const int VRy = A0; 
const int VRx = A1; 
const int SW = 2; 
void setup() { 
servo1.attach(servoPin); // Le digo que el servo está acá
pinMode(ledPin0, OUTPUT); // Esto envia señales
pinMode(ledPin1, OUTPUT); 
pinMode(interruptPin, INPUT_PULLUP); // Recibe señales
attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING); pinMode(VRx, INPUT); 
pinMode(VRy, INPUT); 
pinMode(SW, INPUT_PULLUP); 
} 
void loop() { 
int xPosition = analogRead(VRx); // Se guarda en variables lo que se lee
int yPosition = analogRead(VRy); 
int SW_state = digitalRead(SW); 
int angulo1 = map(xPosition, 0, 1023, 0, 180); // Mapea para convertir a ángulo 
servo1.write(angulo1); 
int brillo = map(yPosition, 0, 1023, -255, 255); // Mapea para convertir a brillo o intensidad
analogWrite(ledPin1, abs(brillo)); 
if( button ) { 
digitalWrite(ledPin0, 1); 
} else { 
digitalWrite(ledPin0, 0); 
} 
} 
void click() { 
if( button == 0 ) { button = 1; } else { button = 0; } 
}
