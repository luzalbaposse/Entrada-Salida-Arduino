#include <Servo.h> 
const int servoPin = 10; // En qué pin está el servomotor
Servo servo1; 
void setup() { 
servo1.attach(servoPin); 
} void loop() { 
servo1.write(0); // Ángulo 0
delay(1000); 
servo1.write(30); // Ángulo 30 
delay(1000); 
servo1.write(60); // Ángulo 60 
delay(1000); 
servo1.write(90); // Ángulo 90
delay(1000); 
servo1.write(180); // Ángulo 180 
delay(1000); 
} 
