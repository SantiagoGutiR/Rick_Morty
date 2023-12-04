#ifndef PERSONAJE_H
#define PERSONAJE_H
#define velocidad 5

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
    bool validar_limites();
};

#endif // PERSONAJE_H
