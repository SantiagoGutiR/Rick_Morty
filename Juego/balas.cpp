#include "balas.h"

balas::balas(char dir, int x, int y)
{
    direccion = dir;
    xo = x;
    yo = y;
    setPos(x,y);
}

void balas::mover()
{
    if(direccion == 'D') setPos(this->x()+velocidad, this->y());
    else if(direccion == 'A') setPos(this->x()-velocidad, this->y());

    if(!(this->x() > 0 && this->x() < 968)) setPos(xo, yo);
}

void balas::devolver()
{
    setPos(xo, yo);
}
