#include "sensorDistancia.h"
#include <Stepper.h>
#include <Servo.h>

#define STEPS 360 //No se si es un numero valido
#define INI 115
#define DER 175
#define IZQ 55

//Pines arduino
//Stepper stepper(STEPS, 2, 3, 4, 5);
Servo servo;

void sensorDist::init_sensorDist(void)
{
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
//    stepper.setSpeed(5);
    servo.attach(5); 
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
//    stepper.step(90);
    servo.write(DER);
    delay(500);
    int distance = distancia();
    delay(100);
//    stepper.step(-90);
    servo.write(INI);
    return distance;
}

int sensorDist::mirarIzq(void)
{
    //stepper.step(90);
    servo.write(IZQ);
    delay(500);
    int distance = distancia();
    delay(100);
    //stepper.step(-90);
    servo.write(INI);
    return distance;
}