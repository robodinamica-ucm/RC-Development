/*
Test to check the correct behaviour of bluetooth module. The loop will read the character send by the phone 
and then play it with the morse functions
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
String message = "test de comunicacion hc06 a movil aprobado, para repetir escriba: ";
void loop() {
  
  
  while (BTSerial.available() > 0) {
    char data = (char) BTSerial.read();
  
    PlayChar(data);

    if (data == ';'){
       message = message + data;
      BTSerial.print(message); // send back to bluetooth terminal
      Serial.print(message); // send to serial monitor
    }
  }
  

  
}
