#include <Arduino.h>

const int Apin = 2;  
const int Bpin = 3;
const int Cpin = 4;
const int Dpin = 5;  

const int Wpin = 6;   
const int Xpin = 7;
const int Ypin = 8;
const int Zpin = 9;   

void disp_7447(int D, int C, int B, int A) {
  digitalWrite(Apin, A);
  digitalWrite(Bpin, B);
  digitalWrite(Cpin, C);
  digitalWrite(Dpin, D);
}

void setup() {
  pinMode(Apin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(Cpin, OUTPUT);
  pinMode(Dpin, OUTPUT);
  pinMode(Wpin, INPUT_PULLUP);
  pinMode(Xpin, INPUT_PULLUP);
  pinMode(Ypin, INPUT_PULLUP);
  pinMode(Zpin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int W = !digitalRead(Wpin);
  int X = !digitalRead(Xpin);
  int Y = !digitalRead(Ypin);
  int Z = !digitalRead(Zpin);

  disp_7447(Z, Y, X, W);

  Serial.print("Inputs WXYZ = ");
  Serial.print(W);
  Serial.print(X);
  Serial.print(Y);
  Serial.println(Z);

  delay(300);
}
