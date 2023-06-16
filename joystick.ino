const int ledPin0 = 4; // Asigna el pin 4 al led (es digital)
const int VRy = A0; // Asigna el pin A0 que es analógico
const int VRx = A1; 
const int SW = 2; 
void setup() { 
Serial.begin(9600); 
pinMode(ledPin0, OUTPUT); // Esto va a enviar señales
pinMode(VRx, INPUT); // Esto va a recibir señales
pinMode(VRy, INPUT); 
pinMode(SW, INPUT_PULLUP); 
} 
void loop() { 
int xPosition = analogRead(VRx); 
int yPosition = analogRead(VRy); 
int SW_state = digitalRead(SW); 
int mapX = map(xPosition, 0, 1023, -512, 512); // Convierte la posición 
int mapY = map(yPosition, 0, 1023, -512, 512); 
Serial.println(mapX); // Lo imprime en monitor serie 
Serial.println(mapY); 
Serial.println(SW_state); 
digitalWrite(ledPin0, SW_state); 
delay(10); 
}
