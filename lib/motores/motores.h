/*
Libreria que maneja motores
proyecto Electronica Industrial 2020
Simon Mesber, Santos Michelena Y Sergio Duran
*/

#include <Arduino.h>

#define motorA1 5
#define motorA2 4
#define motorB1 2
#define motorB2 3

#ifndef MOTORES_H
#define MOTORES_H

    namespace motores{
        void initMotores();
        void adelante(byte velocidad);
        void atras(byte velocidad);
        void izquierda(byte velocidad);
        void derecha(byte velocidad);
        void diagonalDerechaUp(int x, int y);
        void diagonalDerechaDown(int x, int y);
        void diagonalIzquierdaUp(int x, int y);
        void diagonalIzquierdaDown(int x, int y);
        void stop();
    };

#endif