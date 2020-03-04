#include "sensorDistancia.h"

void sensorDist::init_sensorDist(void)
{
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

int sensorDist::distancia(void)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duracion = pulseIn(echo, HIGH);
    return (duracion / 58.2);
}
