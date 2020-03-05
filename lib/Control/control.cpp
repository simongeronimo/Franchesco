#include "control.h"

void motores(int speed1, int speed2, int speed3, int speed4){
    analogWrite(MOTORA1, speed1);
    analogWrite(MOTORA2, speed2);
    analogWrite(MOTORB1, speed3);
    analogWrite(MOTORB2, speed4);
}
/*

    Falta medir el tiempo que se demora en dar una vuelta de 90 grados, dependiendo de que direccion vaya.

*/
void control::mover(Direccion direccion)
{
    switch (direccion)
    {
        case ADELANTE:
            for (int speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
            {
                if(speedSet <105)
                {
                    motores(speedSet, 0, speedSet, 0);
                }else
                {
                    motores(105, 0, speedSet, 0);
                }
                delay(5);
            }
            break;
        case ATRAS:
            for (int speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
            {
                if(speedSet <105)
                {
                    motores(0, speedSet, 0, speedSet);
                }else
                {
                    motores(0, 105, 0, speedSet);
                }
                delay(5);
            }
            break;
        case DERECHA:
            for (int speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
            {
                motores(speedSet, 0, 0, 0);
                if(speedSet <105)
                {
                    motores(speedSet, 0, 0, speedSet);
                }else
                {
                    motores(105, 0, 0, speedSet);
                }
                delay(5);
            }
            break;
        case IZQUIERDA:
            for (int speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
            {
                if(speedSet <105)
                {
                    motores(0, speedSet, speedSet, 0);
                }else
                {
                    motores(0, 105, speedSet, 0);
                }
                delay(5);
            }
            break;
        default:
            motores(0,0,0,0);
            break;
    }
}
