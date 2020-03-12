/*
Libreria que maneja lecturas de sensor de distancia
proyecto carro autonomo Electronica Industrial 2020
Simon Mesber, Santos Michelena y Sergio Duran.
*/

#include <Arduino.h>


#ifndef SENSORDISTANCIA_H
#define SENSORDISTANCIA_H


//Pines arduino
#define trig 16
#define echo 4
#define MAX 200
 

namespace sensorDist
{
    void init_sensorDist(void);
    int distancia(void);
};

#endif