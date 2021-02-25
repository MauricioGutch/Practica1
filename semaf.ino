void setup() {
  // Se generan 6 salidas para ambos semáforos, es decir 6 Leds
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}
//Este loop se mantiene por tiempo indefinido y permite la repetición de la secuencia en el semáforo
void loop() {
  digitalWrite(13, HIGH);//Semáforo 1:Rojo prendido
  digitalWrite(12, LOW);//Semáforo 1:Amarillo apagado
  digitalWrite(11, LOW);//Semáforo 1:Verde apagado
  digitalWrite(10, LOW);//Semáforo 2:Rojo apagado
  digitalWrite(9, LOW);//Semáforo 2:Amarillo apagado
  digitalWrite(8, HIGH);//Semáforo 2:Verde Prendido
  delay(5000);// Segundo semáforo en Verde
  digitalWrite(13, HIGH); 
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);// Semáforo 2: Amarillo Prendido
  digitalWrite(8, LOW);
  delay(1000); //Transición a amarillo
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);//Semáforo 1: Verde Prendido
  digitalWrite(10, HIGH);//Semáforo 2: Rojo Prendido
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(5000); //Primer semáforo en verde
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);//Semáforo 1: Amarillo prendido
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(1000); //Transición a amarillo
}
