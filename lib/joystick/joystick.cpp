#include "motores.h"

void direccion(){
  int x = analogRead(A0);
  int y = analogRead(A1);
  
  if(y>550){
    if(x>550){motores::diagonalDerechaUp(x,y);}
    else if(x<480){motores::diagonalIzquierdaUp(x,y);}
    else{motores::adelante(map(y,0,1024,0,255));}
  }
  else if(y<480){
    if(x>550){motores::diagonalDerechaDown(x,y);}
    else if(x<480){motores::diagonalIzquierdaDown(x,y);}
    else{motores::atras(map(y,0,1024,0,255));}
  }
  else if(x>550){motores::derecha(map(x,0,1024,0,255));}
  else if(x<480){motores::izquierda(map(x,0,1024,0,255));}
  else{motores::stop();}
}