#include <Arduino.h>
#include <motores.h>

void setup() {
  // put your setup code here, to run once:
  motores::initMotores();
}

void loop() {
    motores::adelante(255);
}