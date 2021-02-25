
//Este código recibe la señal de un botón y crea un retardo mayor en el parpadeo del led cuando está activo.
int aux=0; //Variable auxiliar que recibe la señal del Pussh Button
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT); //El Led se configura como salida
  pinMode(12, INPUT); //El botón se configura como entrada
}

// the loop function runs over and over again forever
void loop() {
  aux= digitalRead(12); //Lectura digital de la señal del botón
  if (aux == 1){ //Si el botón está activado, el retardo en el parpadeo será mayor
    digitalWrite(13, HIGH);//Esta señal digital hace prender el Led
    delay(2000); // Duración de 2 segundos prendido el Led
    digitalWrite(13, LOW);//Esta señal digital hace apagar el Led
    delay(2000); //Duración de 2 segundos apagado el Led
    }
  else { //El botón está desactivado y el parpadeó es más rápido
    digitalWrite(13, HIGH);    
    delay(1000);//El led parpadea más rapido porque su frecuencia es mayor                       
    digitalWrite(13, LOW);   
    delay(1000);  
  }                     
}
