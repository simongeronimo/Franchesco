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
    analogWrite(A2, velocidad);
    analogWrite(B2, velocidad);
}

void motores::atras(byte velocidad){
    analogWrite (A1, velocidad);
    analogWrite (B1, velocidad);
    analogWrite(A2, LOW);
    analogWrite(B2, LOW);
}

void motores::parar(){
    digitalWrite (A1, LOW);
    digitalWrite (B1, LOW);
    analogWrite(A2, LOW);
    analogWrite(B2, LOW);
}

