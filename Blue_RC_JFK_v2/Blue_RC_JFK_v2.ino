/*
Aplicacion compatible con BLUE RC JFK v3
String recivida: l#r#
# => number between(0-255)

bluetooth input: realiza todas las operaciones para recibir e interpretar las strings de bluetooth
  Asigna los valores correctos a left y right (byte)

#CORRECCIONES
CAMBIADO EL ORDEN DE: pin_motor_a_forward a 6 para que el mando izquierdo controle la rueda derecha
Desactivados los serial print para evitar delays.
*/
#include "Arduino.h"
#include <SoftwareSerial.h>


const byte rxPin = 3;
const byte txPin = 2;
SoftwareSerial bluetooth(rxPin, txPin); // RX, TX

int pin_motor_a_forward = 6; //corregimos el orden de los mandos
int pin_motor_b_forward = 5;
int pin_motor_a_1 = 7;
int pin_motor_a_2 = 8;
int pin_motor_b_1 = 12;
int pin_motor_b_2 = 13;

int pinTone = 10;

void setup() {
  pinMode(pinTone, OUTPUT);
  Play7Char("sunlast");
  Play3Char("set");


  
  Serial.begin(9600);
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  bluetooth.begin(9600);

  pinMode(pin_motor_a_forward, OUTPUT);
  pinMode(pin_motor_b_forward, OUTPUT);
  pinMode(pin_motor_a_1, OUTPUT);
  pinMode(pin_motor_a_2, OUTPUT);
  pinMode(pin_motor_b_1, OUTPUT);
  pinMode(pin_motor_b_2, OUTPUT);
  digitalWrite(pin_motor_a_1, HIGH);
  digitalWrite(pin_motor_a_2, LOW);
  digitalWrite(pin_motor_b_1, LOW);  //cambio de sentido para que se dirija con las baterias al frente y el arduino detras
  digitalWrite(pin_motor_b_2, HIGH);

  
  Play3Char("loo");
}


String inputString = "";
byte left = 0;
byte right = 0;
void loop() {


  while (bluetooth.available()) {
    char c = bluetooth.read();
    
    // Append the incoming character to the inputString
    inputString += c;
    
    // If we receive a newline character, assume the string is complete
    if (c == '\n') {
      inputString.trim();  // Remove any extraneous spaces or newline characters

      // Check if the string starts with 'l' and contains 'r'
      if (inputString.startsWith("l") && inputString.indexOf('r') > 1) {
        // Split the string into left and right values
        //ahora voy a subir a la biblio a buscar un libri que salga algo de big bang vienes?? 3.30
        //a las 14.30 entro en clase con deva
        
        int rIndex = inputString.indexOf('r');
        
        // Extract the number after 'l' and before 'r'
        String leftString = inputString.substring(1, rIndex);
        
        // Extract the number after 'r'
        String rightString = inputString.substring(rIndex + 1);

        // Convert the extracted strings to integers and constrain to valid values
        left = constrain(leftString.toInt(), 0, 255);
        right = constrain(rightString.toInt(), 0, 255);

        // Print out the results for debugging
        //Serial.print("Left: ");
        //Serial.println(left);
        //Serial.print("Right: ");
        //Serial.println(right);
      }

      // Clear the input string after processing
      inputString = "";
    }
  }

  
  analogWrite(pin_motor_a_forward, left);
  analogWrite(pin_motor_b_forward, right);
}

