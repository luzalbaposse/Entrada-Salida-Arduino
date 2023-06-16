/* Modificar el programa para que presente la siguiente secuencia de encendido de leds: 000, 
001, 011, 111, 110, 100. La misma se debe repetir todo el tiempo en intervalos regulares de 1 
segundo entre cada valor. 
*/
const int ledPin0 = 4; 
const int ledPin1 = 5; 
const int ledPin2 = 6; 
void setup() { 
pinMode(ledPin0, OUTPUT); 
pinMode(ledPin1, OUTPUT); 
pinMode(ledPin2, OUTPUT); }

void loop() { 
// 000
digitalWrite(ledPin0, 0); 
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 0); 
delay(1000);
// 001
digitalWrite(ledPin0, 0); 
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 1); 
delay(1000); 
// 011
digitalWrite(ledPin0, 0); 
digitalWrite(ledPin1, 1); 
digitalWrite(ledPin2, 1); 
delay(1000); 
// 111
digitalWrite(ledPin0, 1); 
digitalWrite(ledPin1, 1); 
digitalWrite(ledPin2, 1); 
delay(1000); 
// 110
digitalWrite(ledPin0, 1);
digitalWrite(ledPin1, 1);
digitalWrite(ledPin2, 0);
delay(1000);

// 100
digitalWrite(ledPin0, 1); 
digitalWrite(ledPin1, 0); 
digitalWrite(ledPin2, 0); 
delay(1000); 
}
