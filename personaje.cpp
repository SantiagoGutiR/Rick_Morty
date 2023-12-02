#include "personaje.h"

personaje::personaje()
{
    n = 1000;
}

void personaje::setN(int newN)
{
    n = newN;
}

bool personaje::validar_limites()
{
    if(!(this->x() > 0 && this->x() < 968)||!(this->y() < 558)) return true;
    else return false;
}

void personaje::movimiento(char direccion)
{
    if(direccion == 'D'){
        setPos(x()+velocidad, y());
        Setup_Imagen(":/Imagenes/Rick.png", 132, 1068, 121, 160, 0.26);
    }
    else if (direccion == 'A'){
        setPos(x()-velocidad, y());
        Setup_Imagen(":/Imagenes/Rick.png", 136, 902, 121, 160, 0.26);
    }
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
