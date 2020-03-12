#include "control.h"
#include "SensorDistancia.h"
#include "Servo.h"


#define MEDIO 90
#define DER 5
#define IZQ 175
Servo myservo;

const int servoPin = 5; //D1

void faros(bool encendido){
  digitalWrite(FARO_DER, encendido);
}

void motores(int speed1, int speed2, int speed3, int speed4){
    analogWrite(MOTORA1, speed1);
    analogWrite(MOTORA2, speed2);
    analogWrite(MOTORB1, speed3);
    analogWrite(MOTORB2, speed4);
}

int volteaDER()
{
  myservo.write(DER);
  delay(1500);
  int distance = sensorDist::distancia();
  delay(1000);
  myservo.write(MEDIO);
  delay(1500);
  return distance;
}

int volteaIZQ()
{
  myservo.write(IZQ);
  delay(1500);
  int distance = sensorDist::distancia();
  delay(1000);
  myservo.write(MEDIO);
  delay(1500);
  return distance;
}

void control::init(){
    Serial.begin(9600);
    sensorDist::init_sensorDist();
    myservo.attach(servoPin);
    pinMode(FARO_DER, OUTPUT); 
    faros(LOW);
    myservo.write(MEDIO);
}

void control::mover(Direccion direccion)
{
    switch (direccion)
    {
        case ADELANTE:
            for (int i=0; i<MAX_SPEED; ++i){
                if (i < 525){
                    motores(i, 0, 2*i, 0);
                }else{
                    motores(i, 0, 550, 0);
                }
            }
            break;
        case ATRAS:
            faros(HIGH);
            for (int i=0; i<MAX_SPEED; ++i){
                if (i < 525){
                    motores(0, i, 0, 2*i);
                }else{
                    motores(0, i, 0, 560);
                }
            }
            break;
        case DERECHA:
            motores(1023, 0, 0, 700);
            break;
        case IZQUIERDA:
            motores(0, 1023, 650,0);
            break;
        default:
            faros(LOW);
            motores(0,0,0,0);
            break;
    }
}

void control::rutina(){
  if (sensorDist::distancia()<15)
  {
    mover(STOP);
    delay(100);
    mover(ATRAS);
    delay(500);
    mover(STOP);
    delay(500);
    int distDER = volteaDER();
    int distIZQ = volteaIZQ();
    if(distDER > distIZQ){
      mover(DERECHA);
      delay(1000);
      mover(STOP);
    }else{
      mover(IZQUIERDA);
      delay(1000);
      mover(STOP);
    }
    delay(2000);
  }else{
    mover(ADELANTE);
  }
  delay(40);
}

void control::test(){
  int distance = sensorDist::distancia();
  Serial.println();
    if(distance> 15){
      faros(HIGH);
    }else{
      faros(LOW);
    }
}