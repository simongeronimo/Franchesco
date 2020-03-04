#include "motores.h"

void motores::initMotores(){
    pinMode (A1, OUTPUT);
    pinMode (A2, OUTPUT);
    pinMode (B1, OUTPUT);
    pinMode (B2, OUTPUT);
}

void motores::adelante(byte velocidad){
    digitalWrite (A1, LOW);
    digitalWrite (B1, LOW);
    analogWrite(A2, 100);
    analogWrite(B2, 255);
}

