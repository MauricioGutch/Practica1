
//Este código en ASM realiza la función del parpadeo de un led cambiando de frecuencia sí un botón ees activado.
void setup(){
  DDRB = DDRB | B10000000; // Data Direction Register B: Inputs 0-6, Output 7
  }
void loop(){
  asm (
    "inicio:\n\t"
    "in r17,0x03\n\t" //Configuramos el puerto 12 de la Arduino como entrada
    "LDI r18,0\n\t"
    "cp r17,r18\n\t" //Comparamos si está activado el botón con un 0 
    "brne pushBut\n\t" //salta a la secuencia del delay porque se activó el PushButton
    "jmp norm\n\t" //salta a la secuencia de delay normal
    
    "pushBut:\n\t" //Secuencia de botón activado
    "sbi 0x05,0x07\n\t" //Se coloca un 1 en la salida para que encienda el Led
    "call tiempo_2\n\t" //El tiempo 2 tarda lo doble ya que tiene una frecuencia de 0.5 Hz
    "cbi 0x05,0x07\n\t" //Se coloca un 0 en la salida para que se apague el Led
    "call tiempo_2\n\t"
    "jmp main\n\t" //Salta al inicio

    "norm:\n\t" //Secuencia normal
    "sbi 0x05,0x07\n\t" 
    "call tiempo_1\n\t" //El tiempo 1 tarda 1 sec porque tiene una frecuencia de 1 hz
    "cbi 0x05,0x07\n\t" 
    "call tiempo_1\n\t" 
    "jmp main\n\t" 
    
    "tiempo_1:\n\t" //Con esta configuración, el parpadeo se hace cada segundo
    "LDI r22, 124\n\t" //Con 124 se asegura un retardo de 1 segundo
    "LOOP_3:\n\t"//Con 3 loops se puede realizar un retardo máximo de 255^3 pasos
    "LDI r21, 255\n\t"
    "LOOP_2:\n\t"
    "LDI r20, 255\n\t"
    "LOOP_1:\n\t"
    "DEC r20\n\t" //Se decrementa el número 255 
    "BRNE LOOP_1\n\t"
    "DEC r21\n\t"
    "BRNE LOOP_2\n\t"
    "DEC r22\n\t"
    "BRNE LOOP_3\n\t"
    "ret\n\t" //Regreso a la rutina de la secuencia normal

    "tiempo_2:\n\t" //Con esta configuración el parpadeo se hace cada 2 segundos
    "LDI r25, 247\n\t" // Con 247 se asegura un retardo de 1 más que en la secuencia normal
    "LOOP_6:\n\t"
    "LDI r24, 255\n\t"
    "LOOP_5:\n\t"
    "LDI r23, 255\n\t"
    "LOOP_4:\n\t"
    "DEC r23\n\t"
    "BRNE LOOP_4\n\t"
    "DEC r24\n\t"
    "BRNE LOOP_5\n\t"
    "DEC r25\n\t"
    "BRNE LOOP_6\n\t"
    "ret\n\t" //Regreso a la rutina de la secuencia de botón activado
  );
}
