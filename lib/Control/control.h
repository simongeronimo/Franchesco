/*
libreria de control de movimiento del carro proyecto electronica
Autores: Sergio Duran Y Santos Michelena
*/
#include <Arduino.h>

#ifndef CONTROL_H
#define CONTROL_H

#define MOTORA1  11 
#define MOTORA2  10 
#define MOTORB1  9 
#define MOTORB2  6 
#define MAX_SPEED 255

enum Direccion{
    ADELANTE,
    ATRAS,
    DERECHA,
    IZQUIERDA,
    STOP
};

namespace control
{
    void mover(Direccion);
}

#endif