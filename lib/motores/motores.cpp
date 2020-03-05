#include "motores.h"
#include "math.h"

void motores::initMotores(){
    pinMode (A1, OUTPUT);
    pinMode (A2, OUTPUT);
    pinMode (B1, OUTPUT);
    pinMode (B2, OUTPUT);
}

void motores::adelante(byte velocidad){
    digitalWrite (A1, LOW);
    digitalWrite (B1, LOW);
    byte regulador = map(velocidad, 0, 255, 0, 150);
    analogWrite(A2, regulador);
    analogWrite(B2, velocidad);
}

void motores::atras(byte velocidad){
    digitalWrite (A2, LOW);
    digitalWrite (B2, LOW);
    byte regulador = map(velocidad, 0, 255, 0, 150);
    analogWrite(A1, regulador);
    analogWrite(B1, velocidad);
}

void motores::izquierda(byte velocidad){
    digitalWrite (A1, LOW);
    digitalWrite (B2, LOW);
    analogWrite(A2, velocidad);
    analogWrite(B1, velocidad);
}

void motores::derecha(byte velocidad){
    digitalWrite (A2, LOW);
    digitalWrite (B1, LOW);
    analogWrite(A1, velocidad);
    analogWrite(B2, velocidad);
}

void motores::diagonalDerechaUp(int x, int y){
    byte velocidadIzquierda = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadDerecha = map(x, 0, 1024, 255, 0);
    digitalWrite (A1, LOW);
    digitalWrite (B1, LOW);
    analogWrite(A2, velocidadDerecha);
    analogWrite(B2, velocidadIzquierda);
}

void motores::diagonalDerechaDown(int x, int y){
    byte velocidadIzquierda = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadDerecha = map(x, 0, 1024, 255, 0);
    digitalWrite (A2, LOW);
    digitalWrite (B2, LOW);
    analogWrite(A1, velocidadDerecha);
    analogWrite(B1, velocidadIzquierda);
}

void motores::diagonalIzquierdaUp(int x, int y){
    byte velocidadDerecha = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadIzquierda = map(x, 0, 1024, 255, 0);
    digitalWrite (A1, LOW);
    digitalWrite (B1, LOW);
    analogWrite(A2, velocidadDerecha);
    analogWrite(B2, velocidadIzquierda);
}

void motores::diagonalIzquierdaDown(int x, int y){
    byte velocidadDerecha = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadIzquierda = map(x, 0, 1024, 255, 0);
    digitalWrite (A2, LOW);
    digitalWrite (B2, LOW);
    analogWrite(A1, velocidadDerecha);
    analogWrite(B1, velocidadIzquierda);
}

void motores::stop(){
    digitalWrite (A2, LOW);
    digitalWrite (B2, LOW);
    digitalWrite (A1, LOW);
    digitalWrite (B1, LOW);
}