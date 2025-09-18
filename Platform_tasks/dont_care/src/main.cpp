#include <Arduino.h>

int W, X, Y, Z;
int A, B, C, D;

void disp_7447(int D, int C, int B, int A) {
  digitalWrite(2, A);
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D);
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  W = digitalRead(6);
  X = digitalRead(7);
  Y = digitalRead(8);
  Z = digitalRead(9);

  A = (!W);
  B = (W && !X && !Z) || (!W && X);
  C = (!X && Y) || (!W && Y) || (W && X && !Y);
  D = (!W && Z) || (W && X && Y);

  disp_7447(D, C, B, A);
}
