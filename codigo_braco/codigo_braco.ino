#include <Crescer.h>

#define pot1 A0
#define pot2 A1
#define pot3 A2

#define servo1 9
#define servo2 10
#define servo3 11

int value1 = 0;
int value2 = 0;
int value3 = 0;

Tempora temp1;
Tempora temp2;
Tempora temp3;

void setup() {
  Serial.begin(9600);
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  pinMode(servo3, OUTPUT);
  temp1.defiSP(30);
  temp2.defiSP(40);
  temp3.defiSP(50);
  Serial.println("testando...");
}

void loop() {
  Serial.println("");
  Serial.println("");
  Serial.println("Novo print: ");
  if (temp1.Saida(1)) {
    value1 = analogRead(pot1);
    value1 = map(value1, 0, 1023, 0, 180);
    controleServo(value1, servo1);
    temp1.Saida(0);
  }
  else if (temp2.Saida(1)) {
    value2 = analogRead(pot2);
    value2 = map(value2,0,1023,0,180);
    controleServo(value2, servo2);
    temp2.Saida(0);
    
  }
  else if (temp3.Saida(1)) {
    value3 = analogRead(pot3);
    value3 = map(value3, 0, 1023, 0, 180);
    controleServo(value3, servo3);
    temp3.Saida(0);
    
  } 
}

void controleServo(int potenciometro, int servo) {
  int tempo = map(potenciometro, 0, 180, 500, 2400);
  int i;
  for (i = 0; i < 5; i++) {
    digitalWrite(servo, HIGH);
    delayMicroseconds(tempo);
    digitalWrite(servo, LOW);
    delayMicroseconds(20000 - tempo);
    digitalWrite(servo, HIGH);
  }
}