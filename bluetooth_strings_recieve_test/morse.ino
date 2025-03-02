// *** Characters to Morse Code Conversion *** //
/*
Pausa para el punto: delay(2*dotLen) => el tiempo para hacer el punto y despues otra pausa igual
Pausa para la raya: delay(4*dotLen) => 3 de la raya y luego la pausa del punto
Pausa entre caracteres: 3 puntos, como despues del punto o raya ya hemos hecho una pausa solo tendremos que poner pausa de dos puntos
Pausa entre palabras: 7 puntos(7 decimas) poner 4 decimas extra a las 3 decimas entre caracteres
*/

#define NOTE_A4 440
int dotLen = 100;          // length of the morse code 'dot'
int dashLen = dotLen * 3;  // length of the morse code 'dash'


void PlaySentence(char[]){}
void PlayWord(char myWord[]){ //a better option will be working wwith fixed array legths using various functions for different word lengths
  //int arrayLength = sizeof(myWord)/sizeof(char); 
  int arrayLength = sizeof(myWord)/sizeof(myWord[0]);
  for(int i=0; i<arrayLength; i++){
    PlayChar(myWord[i]);
  }
  delay(dotLen*4);
}

void Play3Char(char myWord[]){
  for(int i=0; i<3; i++){
    PlayChar(myWord[i]);
  }
  delay(dotLen*4);
}
void Play7Char(char myWord[]){
  for(int i=0; i<7; i++){
    PlayChar(myWord[i]);
  }
  delay(dotLen*4);
}

void PlayChar(char tmpChar)
{
	// Take the passed character and use a switch case to find the morse code for that character
	switch (tmpChar) {
	  case 'a':	
		MorseDot();
		MorseDash();
		break;
	  case 'b':
		MorseDash();
		MorseDot();
		MorseDot();
		MorseDot();
		break;
	  case 'c':
	    MorseDash();
		MorseDot();
		MorseDash();
		MorseDot();
		break;
	  case 'd':
		MorseDash();
		MorseDash();
		MorseDot();
		break;
	  case 'e':
		MorseDot();
		break;
	  case 'f':
	    MorseDot();
		MorseDot();
		MorseDash();
		MorseDot();
		break;
	  case 'g':
		MorseDash();
		MorseDash();
		MorseDot();
		break;
	  case 'h':
	    MorseDot();
		MorseDot();
		MorseDot();
		MorseDot();
		break;
	  case 'i':
	    MorseDot();
		MorseDot();
		break;
	  case 'j':
	    MorseDot();
		MorseDash();
		MorseDash();
		MorseDash();
		break;
      case 'k':
	    MorseDash();
		MorseDot();
		MorseDash();
		break;
	  case 'l':
	    MorseDot();
		MorseDash();
		MorseDot();
		MorseDot();
		break;
      case 'm':
	    MorseDash();
		MorseDash();
		break;
	  case 'n':
	    MorseDash();
		MorseDot();
		break;
	  case 'o':
	    MorseDash();
		MorseDash();
		MorseDash();
		break;
	  case 'p':
	    MorseDot();
		MorseDash();
		MorseDash();
		MorseDot();
		break;
	  case 'q':
	    MorseDash();
		MorseDash();
		MorseDot();
		MorseDash();
		break;
	  case 'r':
	    MorseDot();
		MorseDash();
		MorseDot();
		break;
	  case 's':
	    MorseDot();
		MorseDot();
		MorseDot();
		break;
	  case 't':
	    MorseDash();
		break;
	  case 'u':
	    MorseDot();
		MorseDot();
		MorseDash();
		break;
	  case 'v':
	    MorseDot();
		MorseDot();
		MorseDot();
		MorseDash();
		break;
	  case 'w':
	    MorseDot();
		MorseDash();
		MorseDash();
		break;
	  case 'x':
	    MorseDash();
		MorseDot();
		MorseDot();
		MorseDash();
		break;
	  case 'y':
	    MorseDash();
		MorseDot();
		MorseDash();
		MorseDash();
		break;
	  case 'z':
	    MorseDash();
		MorseDash();
		MorseDot();
		MorseDot();
		break;

		
	}
  delay(dotLen*2);
}

void MorseDot(){
	tone(pinTone, NOTE_A4, dotLen);
	delay(dotLen*2);
}

void MorseDash()
{
  tone(pinTone, NOTE_A4, dashLen);	// start playing a tone
  delay(dotLen*4);               // hold in this position
}