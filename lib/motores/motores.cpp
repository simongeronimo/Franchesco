#include "motores.h"
#include "math.h"

void motores::initMotores(){
    pinMode (motorA1, OUTPUT);
    pinMode (motorA2, OUTPUT);
    pinMode (motorB1, OUTPUT);
    pinMode (motorB2, OUTPUT);
}

void motores::adelante(byte velocidad){
    digitalWrite (motorA1, LOW);
    digitalWrite (motorB1, LOW);
    byte regulador = map(velocidad, 0, 255, 0, 150);
    analogWrite(motorA2, regulador);
    analogWrite(motorB2, velocidad);
}

void motores::atras(byte velocidad){
    digitalWrite (motorA2, LOW);
    digitalWrite (motorB2, LOW);
    byte regulador = map(velocidad, 0, 255, 0, 150);
    analogWrite(motorA1, regulador);
    analogWrite(motorB1, velocidad);
}

void motores::izquierda(byte velocidad){
    digitalWrite (motorA1, LOW);
    digitalWrite (motorB2, LOW);
    analogWrite(motorA2, velocidad);
    analogWrite(motorB1, velocidad);
}

void motores::derecha(byte velocidad){
    digitalWrite (motorA2, LOW);
    digitalWrite (motorB1, LOW);
    analogWrite(motorA1, velocidad);
    analogWrite(motorB2, velocidad);
}

void motores::diagonalDerechaUp(int x, int y){
    byte velocidadIzquierda = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadDerecha = map(x, 0, 1024, 255, 0);
    digitalWrite (motorA1, LOW);
    digitalWrite (motorB1, LOW);
    analogWrite(motorA2, velocidadDerecha);
    analogWrite(motorB2, velocidadIzquierda);
}

void motores::diagonalDerechaDown(int x, int y){
    byte velocidadIzquierda = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadDerecha = map(x, 0, 1024, 255, 0);
    digitalWrite (motorA2, LOW);
    digitalWrite (motorB2, LOW);
    analogWrite(motorA1, velocidadDerecha);
    analogWrite(motorB1, velocidadIzquierda);
}

void motores::diagonalIzquierdaUp(int x, int y){
    byte velocidadDerecha = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadIzquierda = map(x, 0, 1024, 255, 0);
    digitalWrite (motorA1, LOW);
    digitalWrite (motorB1, LOW);
    analogWrite(motorA2, velocidadDerecha);
    analogWrite(motorB2, velocidadIzquierda);
}

void motores::diagonalIzquierdaDown(int x, int y){
    byte velocidadDerecha = map(sqrt(x*x+y*y), 0, 1449, 0, 255);
    byte velocidadIzquierda = map(x, 0, 1024, 255, 0);
    digitalWrite (motorA2, LOW);
    digitalWrite (motorB2, LOW);
    analogWrite(motorA1, velocidadDerecha);
    analogWrite(motorB1, velocidadIzquierda);
}

void motores::stop(){
    digitalWrite (motorA2, LOW);
    digitalWrite (motorB2, LOW);
    digitalWrite (motorA1, LOW);
    digitalWrite (motorB1, LOW);
}
