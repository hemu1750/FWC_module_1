#include <Arduino.h>

#define P 2
#define Q 3
#define R 4

#define F_PIN 13  

void setup() {
  pinMode(P, INPUT);
  pinMode(Q, INPUT);
  pinMode(R, INPUT);
  pinMode(F_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int p = digitalRead(P);
  int q = digitalRead(Q);
  int r = digitalRead(R);

  int F = ((!q) && r) || (p && r);

  digitalWrite(F_PIN, F);

  Serial.print("PQR=");
  Serial.print(p);
  Serial.print(q);
  Serial.print(r);
  Serial.print(" -> F=");
  Serial.println(F);

  delay(500);
}
