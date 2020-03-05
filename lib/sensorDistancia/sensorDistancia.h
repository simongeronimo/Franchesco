/*
Libreria que maneja lecturas de sensor de distancia
proyecto carro autonomo Electronica Industrial 2020
Simon Mesber, Santos Michelena y Sergio Duran.
*/

#include <Arduino.h>
#include <Stepper.h>

#ifndef SENSORDISTANCIA_H
#define SENSORDISTANCIA_H


#define trig 14
#define echo 12
long duracion = 0;
long distancia = 0;

Stepper stepper(360, 14, 12, 13, 15); //Revisar si los pines estan disponibles 

namespace sensorDist
{
    void init_sensorDist(void);
    int distancia(void);
    int mirarDer(void);
    int mirarIzq(void);
};

#endif