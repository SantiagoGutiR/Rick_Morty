#include "personaje.h"

personaje::personaje()
{
    n = 1000;
}

void personaje::setN(int newN)
{
    n = newN;
}

void personaje::movimiento(char direccion)
{
    if(direccion == 'D') setPos(x()+velocidad, y());
    else if (direccion == 'A')setPos(x()-velocidad, y());
}

void personaje::salto(float vxo, float vyo)
{
    int x,y;
    float t;

    t = 1.8*n*0.001;

    x = this->x()+vxo*t;
    y = this->y()-vyo*t+0.5*9.8*t*t;
    setPos(x, y);
    n++;
}
