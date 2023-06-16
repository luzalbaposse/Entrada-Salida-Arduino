const int ledPin0 = 4; // Acá se configuran los pines de los leds.
const int ledPin1 = 5; 
const int ledPin2 = 6; 
void setup() { 
pinMode(ledPin0, OUTPUT);// Se define que se van a usar para enviar señales (controlar leds)
pinMode(ledPin1, OUTPUT); 
pinMode(ledPin2, OUTPUT); }
void loop() { 
digitalWrite(ledPin0, 1); // Se prenden los tres pines (están en 1)
digitalWrite(ledPin1, 1); 
digitalWrite(ledPin2, 1); 
delay(1000); 
digitalWrite(ledPin0, 0); // Se apagan los tres pines (están en 0)
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 0); 
delay(1000); }
