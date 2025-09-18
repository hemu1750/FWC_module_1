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

  Serial.begin(9600);
}

void loop() {
  W = digitalRead(6);  
  X = digitalRead(7);  
  Y = digitalRead(8);  
  Z = digitalRead(9);  

  A = (!W && !Z) || (!W && !X && !Y);
  B = (W && !X && !Z) || (!W && X && !Z);
  C = (W && X && !Y && !Z) || (!X && Y && !Z) || (!W && Y && !Z);
  D = (W && X && Y && !Z) || (!W && !X && !Y && Z);

  disp_7447(D, C, B, A);

  Serial.print("Inputs WXYZ = ");
  Serial.print(W); Serial.print(X);
  Serial.print(Y); Serial.println(Z);

  Serial.print("Outputs DCBA = ");
  Serial.print(D); Serial.print(C);
  Serial.print(B); Serial.println(A);

  delay(300);
}
