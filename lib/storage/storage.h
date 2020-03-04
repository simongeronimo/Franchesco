/*
Libreria que maneja almacenamiento en memoria flash de variables
Proyecto Carro automatico Electronica Industrial 2020
Simon Mesber, Santos Michelena y Sergio Duran
*/

#include <Arduino.h>
#include <EEPROM.h>

#ifndef STORAGE_H
#define STORAGE_H

    namespace storage{
        void init_storage(void);
        void setPosicion(byte posicion);
        byte getPosicion(void);
    };

#endif
