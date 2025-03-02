/*
Test to check the correct behaviour of motors. The loop will tell in morse powera when the motor a is working
faster and powerb when the motor b does.
*/
int pin_motor_a_forward = 5;
int pin_motor_b_forward = 6;

int pin_motor_a_1 = 7;
int pin_motor_a_2 = 8;
int pin_motor_b_1 = 12;
int pin_motor_b_2 = 13;

int pinTone = 10;




int pot_curva[2] = { 100, 100 };  //potencia calculada por los ajustes independientes

void setup() {
  PlayChar('s');
  PlayChar('e');
  PlayChar('t');
  //need to use pwm pins
  pinMode(pin_motor_a_forward, OUTPUT);
  pinMode(pin_motor_b_forward, OUTPUT);

  pinMode(pin_motor_a_1, OUTPUT);
  pinMode(pin_motor_a_2, OUTPUT);
  pinMode(pin_motor_b_1, OUTPUT);
  pinMode(pin_motor_b_2, OUTPUT);

  pinMode(pinTone, OUTPUT);
  Serial.begin(9600);

  digitalWrite(pin_motor_a_1, HIGH);
  digitalWrite(pin_motor_a_2, LOW);
  digitalWrite(pin_motor_b_1, LOW); //cambio de sentido para que se dirija con las baterias al frente y el arduino detras
  digitalWrite(pin_motor_b_2, HIGH);
}

void loop() {
  Play3Char("loo");
  analogWrite(pin_motor_a_forward, pot_curva[0]);
  analogWrite(pin_motor_b_forward, pot_curva[1]);

  Play7Char("powerb"); //plus power b
  analogWrite(pin_motor_a_forward, 100);
  analogWrite(pin_motor_b_forward, 200);
  
  Play7Char("powera");
  analogWrite(pin_motor_a_forward, 200);
  analogWrite(pin_motor_b_forward, 100);
}