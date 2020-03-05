#include "sensorDistancia.h"

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
    duracion = pulseIn(echo, HIGH);
    return (duracion / 58.2);
}

int sensorDist::mirarDer(void)
{
    stepper.step(90);
    delay(500);
    int distance = sensorDist::distancia();
    delay(100);
    stepper.step(-90);
    return distance;
}

int sensorDist::mirarIzq(void)
{
    stepper.step(90);
    delay(500);
    int distance = sensorDist::distancia();
    delay(100);
    stepper.step(-90);
    return distance;
}