/*
Libreria que maneja motores
proyecto Electronica Industrial 2020
Simon Mesber, Santos Michelena Y Sergio Duran
*/

#include <Arduino.h>

#define A1 5
#define A2 4
#define B1 2
#define B2 3

#ifndef MOTORES_H
#define MOTORES_H

    namespace motores{
        void initMotores();
        void adelante(byte velocidad);
        void atras(byte velocidad);
        void izquierda(byte velocidad);
        void derecha(byte velocidad);
        void parar();
    };

#endif