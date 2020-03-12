/*
libreria de control de movimiento del carro proyecto electronica
Autores: Sergio Duran Y Santos Michelena
*/
#include <Arduino.h>

#ifndef CONTROL_H
#define CONTROL_H

//Pines del esp8266
#define MOTORA1  0 //D3
#define MOTORA2  2 //D4
#define MOTORB1  14 //D5
#define MOTORB2  12 //D6
#define MAX_SPEED 1023
#define FARO_DER 15 //D8 

enum Direccion{
    ADELANTE,
    ATRAS,
    DERECHA,
    IZQUIERDA,
    STOP
};

namespace control
{
    void init(void);
    void mover(Direccion);
    void rutina(void);
    void test(void);
}

#endif