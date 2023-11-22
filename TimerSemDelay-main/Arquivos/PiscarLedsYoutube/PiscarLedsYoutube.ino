#include <Crescer.h>
Tempora tLed1;
Tempora tLed2;
Tempora temp_Imprime;

byte StatusLed1 = 1;
byte StatusLed2 = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("E2T");
  pinMode(A0, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  tLed1.defiSP(500);
  tLed2.defiSP(100);
  temp_Imprime.defiSP(10);

}

void loop() {

  analogWrite(10, analogRead(A0) / 4);

  if (temp_Imprime.Saida(1))
  {
    Serial.print(analogRead(A0));
    Serial.print(" : ");
    Serial.println(digitalRead(2));
    temp_Imprime.Saida(0);
  }

  if (tLed1.Saida(1))
  {
    StatusLed1 = 1 - StatusLed1;
    digitalWrite(8, StatusLed1);
    tLed1.Saida(0);
  }

  if (tLed2.Saida(1))
  {
    StatusLed2 = 1 - StatusLed2;
    digitalWrite(9, StatusLed2);
    tLed2.Saida(0);
  }


}
