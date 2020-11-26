#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);        // Creacion del objeto 
int sensor;                            // Variable creada para tomar el valor del sensor
float temperatura;                     // Variable creada para el resultado de la conversion 
int ventilador = 8;                    // Variable para encender vetilador 

void setup(){
   lcd.begin(16,2);                    // Tamaño del lcd, 16 columnas y 2 lineas
   pinMode (ventilador,OUTPUT);        // se asigna como salida para el ventilador
                                       // entrada analogica no es necesario
   }

void loop(){
   
   sensor= analogRead(A0);                        // lee la entrada analogica y se asigna a la variable sensor
   temperatura= ((sensor * 5000.0) / 1023) / 10 ; // Se realiza la conversion 
   lcd.setCursor(0,0);                            // se fija la posicion de escritura en el lcd 
   lcd.print("Temp:(C)   ");                      // se muestra en pantalla Temp: (C)
   lcd.print(temperatura,1);                      // y los grados leidos por el sensor
   
   
   if(temperatura>=20){                           // condicional que enciende ventilador (HIGH) si es mayor de 20 grados 
      digitalWrite(ventilador,HIGH);
      lcd.setCursor(0,1);                         // fijamos la fila 2 
      lcd.print("Ventilador: ON  ");              // Mostramos que el ventilador enciende
   }
   else{
     digitalWrite(ventilador,LOW);                // de lo contario apaga ventilador (LOW) 
     lcd.setCursor(0,1);                          // fijamos la fila 2 
     lcd.print("Ventilador: OFF");                // Mostramos que el ventilador Apaga
   }
  delay(2000);                                   // Retardo de 2 segundos 
}
  
