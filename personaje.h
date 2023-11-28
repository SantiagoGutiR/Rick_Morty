#ifndef PERSONAJE_H
#define PERSONAJE_H
#define velocidad 3

#include "objetos.h"

class personaje: public Objetos
{
    Q_OBJECT
private:
    int n;
public:
    personaje();
    void movimiento(char direccion);
    void salto(float vxo, float vyo);
    void setN(int newN);
};

#endif // PERSONAJE_H
