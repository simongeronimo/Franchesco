#include "storage.h"

#define SIZE 10
#define SETPOSADD 0
#define GETPOSADD 2

void storage::init_storage(void){
    EEPROM.begin(SIZE);
}

void storage::setPosicion(byte posicion){
    EEPROM.write(SETPOSADD,posicion);
    EEPROM.commit();
}

void storage::getPosicion(){
    EEPROM.read(GETPOSADD);
}