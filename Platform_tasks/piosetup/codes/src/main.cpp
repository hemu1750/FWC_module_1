#include <Arduino.h>
int n=13;
void setup() {
  pinMode(n,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  digitalWrite(n,HIGH);
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(n,LOW);
  digitalWrite(7,LOW);
  delay(500);
}
