#include<Arduino.h>
 void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A);   
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D);   

}                                                                                                                                            // the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop() {
disp_7447(0,1,0,1);
}

int Z=0,Y=0,X=0,W=0;
int D,C,B,A;

void disp_7447(int D, int C, int B, int A)
{
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
}

void loop() {
  A=(!W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
  B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);

disp_7447(D,C,B,A);
}


int Z,Y,X,W;

void disp_7447(int D, int C, int B, int A)
{
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

disp_7447(Z,Y,X,W);
}
