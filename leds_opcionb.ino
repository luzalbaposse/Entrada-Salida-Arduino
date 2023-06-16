/*
Modificar el programa anterior para que por cada iteración de la secuencia, 
el tiempo entre cada valor se reduzca en 0,05 segundos. Una vez que llegue a 
0 se debe volver a reiniciar a 1 segundo
*/
const int ledPin0 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;

void setup() {
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  int tiempo = 1000; 

  while (tiempo > 0) {
    digitalWrite(ledPin0, HIGH); // Dato: se puede poner 1 o high, simplemente simboliza que hay una señal
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    delay(tiempo);

    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    delay(tiempo);

    tiempo = tiempo - 50;
      if (tiempo <= 0) {
      tiempo = 1000;
    }
  }
}
