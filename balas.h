#ifndef BALAS_H
#define BALAS_H
#define velocidad 3

#include "objetos.h"

class balas: public Objetos
{
    Q_OBJECT
private:
    char direccion;
    int xo, yo;
public:
    balas(char dir, int x, int y);
    void mover();
    void devolver();
};

#endif // BALAS_H
