#include <Arduino.h>
#include "control.h"

void setup() {
  control::init();
}

void loop() {
  control::rutina();
}
