// Test para comprobar en correcto output of BLUE RC JFK app, correct input and read of C:\Users\Usuario\Documents\1Robodinamica\bluetooth\Blue_RC_JFK_v2
// Printeamos en pantalla la string recibida, los valores interpretados y asignados a las variables left, right: potencia
//Printeamos con bluetooth serial
// Con un contador de 50 segundos expresamos la string y los valores haciendo el cambio de numero a caracter: a => 0, b = > 1 ...
//si no escuchamos salida morse es probable que estemos saturando el while con bluetooth.avaliable()

//Ahora debemos modificar BLUE RC JFK app para interpretar la llegada de bluetooth strings e imprimir la informacion como mensajes de aviso por ejemplo
// pondremos una casilla de test para activar/desactivar estos mensajes. Corregir el problema de resolucion vertical para oppo

// while (bluetooth.available()>0) { => ahora funciona correctamente


//Funciona todo perfectamente salvo la recepcion de las strings en forma de alertas en la app pero esto se corrige con ajustes en la aplicacion
#include <SoftwareSerial.h>

const int rxPin = 3;   // RX for Arduino
const int txPin = 2;   // TX for Arduino
int pinTone = 10;

SoftwareSerial bluetooth(rxPin, txPin); // RX, TX

String inputString = "";  // To hold incoming string
String morseString = "";
byte left = 0;             // Variable to store the left number
byte right = 0;            // Variable to store the right number

unsigned long previousMillis = 0;  // Store last time the function was executed
const long interval = 50000;        // Interval of 5 seconds (5000 milliseconds)


void setup() {
  Serial.begin(9600);               // Serial monitor communication
  bluetooth.begin(9600);            // Bluetooth communication
  Serial.println("Ready to receive data from HC-06");
}

void loop() {
  // If there is data available from the Bluetooth module
  while (bluetooth.available()>0) {
    char c = bluetooth.read();
    
    // Append the incoming character to the inputString
    inputString += c;
    
    // If we receive a newline character, assume the string is complete
    if (c == '\n') {
      Serial.print(inputString);
      bluetooth.print(inputString);
      morseString = inputString;
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
        Serial.print("Left: ");
        Serial.println(left);
        Serial.print("Right: ");
        Serial.println(right);
        bluetooth.print("Left: ");
        bluetooth.println(left);
        bluetooth.print("Right: ");
        bluetooth.println(right);
      }

      // Clear the input string after processing
      inputString = "";
    }
  }
  unsigned long currentMillis = millis();  // Get the current time in milliseconds

  // Check if 5 seconds have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Update the time of the last execution
    Play8Char(convertNumbersToLetters(morseString).c_str());
  }
}


String convertNumbersToLetters(String input) {
  for (int i = 0; i < input.length(); i++) {
    if (isDigit(input[i])) {
      // Convierte el número a su letra correspondiente (0 => 'a', 1 => 'b', ..., 9 => 'j')
      input[i] = char('a' + (input[i] - '0'));
    }
  }
  return input;
}
