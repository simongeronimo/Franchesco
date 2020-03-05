#include <Arduino.h>
#include <control.h>
#include <sensorDistancia.h>

void setup()
{
  // put your setup code here, to run once:
  sensorDist::init_sensorDist();
}

void loop()
{
  if (sensorDist::distancia() <= 15)
  { //Cuando se encuentra con un obstaculo, retorcede y busca el camino mas largo
    int distanceR = 0;
    int distanceL = 0;
    
    control::mover(STOP);
    delay(100);
    control::mover(ATRAS);
    delay(300);
    control::mover(STOP);
    delay(200); //Este tiempo hay que cambiarlo por el necesario para separarse del obstaculo
    distanceR = sensorDist::mirarDer();
    delay(200); 
    distanceL = sensorDist::mirarIzq();
    delay(200);

    if (distanceR >= distanceL)
    {
      control::mover(DERECHA);
      delay(200); //Este delay hay que cambiarlo por el tiempo necesario para que de una vuelta de 90 grados
      control::mover(STOP);
    }
    else
    {
      control::mover(IZQUIERDA);
      delay(200); //Este delay hay que cambiarlo por el tiempo necesario para que de una vuelta de 90 grados
      control::mover(STOP);
    }
  }
  else
  {
    control::mover(ADELANTE);
  }
  delay(40);
}