/*
Test to check the correct reception and treatment of the strings sent by the double joystick rc app: Blue RC JFK. 
"El rango que enviamos se encuentra entre 0-228 en los extremos que solo se consiguen cuando se desliza el joystick lentamente"
Las strings enviadas son: "l###", "r###" donde el numero puede oscilar entre -1 y 228 => constrain, modular a 255, round low values to 0
The program will check if we are able to assign the correct values to powerL and powerR variables, print on screen and morse them.

  Morse not ready
  Functional printing.
  Problemas when both joysticks are moved at the same time.
  Would be much easier if app sended both values with one string
*/

#include "Arduino.h"
#include <SoftwareSerial.h>

const byte rxPin = 3;
const byte txPin = 2;
SoftwareSerial BTSerial(rxPin, txPin); // RX TX

int pinTone = 10;

void setup() {
  pinMode(pinTone, OUTPUT);
  Serial.begin(9600);
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);

  Play3Char("set");
  Play3Char("loo");
}

char letra = ""; 
const String messageTest = "test de comunicacion hc06 a movil aprobado, para repetir escriba: ";
String messageBuffer = "000";
int powerL = 0;
int powerR = 0;
int signalId;
int prevSignalId = 0;
bool number;

void loop() {
  
  
  while (BTSerial.available() > 0) {
    char data = (char) BTSerial.read();
    if(data == 'l'){
      signalId = 0;
      number = false;
    }  
    else if(data == 'r'){
      signalId = 1;
      number = false;
    }
    else{
      number = true; // si no recivimos un char significa que ya estamos leyendo el numero de 3 digitos
      prevSignalId = signalId;
    }  

    // si el caracter es un numero we add it to the buffer, if not we actalize signalId, y mandamos el buffer con numeros a la variable Left or Right
    if(number){
      messageBuffer += data;
    }else {
      if(prevSignalId == 0){
        powerL = (int) messageBuffer.toInt();
      }  
      else {
        powerR = (int) messageBuffer.toInt();
      }
      messageBuffer = "";
      Serial.print("powerL, powerR: ");
      Serial.print(powerL);
      Serial.print(", ");
      Serial.print(powerR);
      Serial.println();
    }





    

    if (data == ';'){
       messageTest = messageTest + data;
      BTSerial.print(messageTest); // send back to bluetooth terminal
      Serial.print(messageTest); // send to serial monitor
    }
  }
  

  
}
