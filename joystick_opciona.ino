/*
Modificar el programa de forma que se enciendan los leds respetando el siguiente patron: 
010 -> arriba
101 -> abajo
110 -> izquierda
011 -> derecha

El umbral de encendido debe ser del 10% del recorrido del joystick

*/
const int ledPin0 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int VRy = A0;
const int VRx = A1;
const int SW = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin0, OUTPUT);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  int xPosition = analogRead(VRx); // Lees analógicamente
  int yPosition = analogRead(VRy); // Aca tambien jaja
  int SW_state = digitalRead(SW); // Lees digital el botón. 
  int mapX = map(xPosition, 0, 1023, -512, 512);
  int mapY = map(yPosition, 0, 1023, -512, 512);
  
  Serial.println(mapX);
  Serial.println(mapY);
  Serial.println(SW_state);

  // Verificar los patrones de movimiento
  if (mapX < 51 && -51 < mapX && mapY >= 51) {  // Patrón: arriba (010) // 10% es 461
    digitalWrite(ledPin0, 0);
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2, 0);
  } else if (mapX < 51 && -51 < mapX && mapY < -51) {  // Patrón: abajo (101)
    digitalWrite(ledPin0, 1);
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 1);
  } else if (mapX <= -51 && mapY >= -51 && mapY <= 51) {  // Patrón: izquierda (110)
    digitalWrite(ledPin0, 1);
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2, 0);
  } else if (mapX >= 51 && mapY >= -51 && mapY <= 51) {  // Patrón: derecha (011)
    digitalWrite(ledPin0, 0);
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2, 1);
  }
  else {
    digitalWrite(ledPin0, 0);
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 0);
  }
  
  
  delay(10);
}
/*
Se utilizan las variables mapX y mapY para almacenar las lecturas mapeadas 
de los sensores analógicos. Después, se verifica el estado de los botones y las 
lecturas mapeadas para determinar el patrón de movimiento. Si se encuentra una 
coincidencia con uno de los patrones especificados, se enciende el LED (ledPin0).
*/
