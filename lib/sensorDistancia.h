/*
Libreria que maneja lecturas de sensor de distancia
proyecto carro autonomo Electronica Industrial 2020
Simon Mesber, Santos Michelena y Sergio Duran.
*/

#include <Arduino.h>

#ifndef SENSORDISTANCIA_H
#define SENSORDISTANCIA_H


#define trig 14
#define echo 12
long duracion = 0;
long distancia = 0;

namespace sensorDist
{
    void init_sensorDist(void);
    int distancia(void);
};

#endif