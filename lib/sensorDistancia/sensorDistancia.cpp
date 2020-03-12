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
    int distance = pulseIn(echo, HIGH);
    distance = distance/ 58.2;
    if(distance > 200){
        distance = 200;
    } else if(distance<0){
        distance = 0;
    } 
    return distance;
}