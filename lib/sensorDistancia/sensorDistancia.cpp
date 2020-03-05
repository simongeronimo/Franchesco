#include "sensorDistancia.h"
#include <Stepper.h>

#define STEPS 360 //No se si es un numero valido

Stepper stepper(STEPS, 14, 12, 13, 15); //Revisar si los pines estan disponibles

void sensorDist::init_sensorDist(void)
{
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    stepper.setSpeed(5); 
}

int sensorDist::distancia(void)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    return (pulseIn(echo, HIGH) / 58.2);
}

int sensorDist::mirarDer(void)
{
    stepper.step(90);
    delay(500);
    int distance = distancia();
    delay(100);
    stepper.step(-90);
    return distance;
}

int sensorDist::mirarIzq(void)
{
    stepper.step(90);
    delay(500);
    int distance = distancia();
    delay(100);
    stepper.step(-90);
    return distance;
}