#ifndef REGLAS_H
#define REGLAS_H

#include "objetos.h"
#include "personaje.h"

class reglas
{
public:
    reglas();
    bool verificar_choque(Objetos &personaje, QVector<Objetos*> plataformas);
};

#endif // REGLAS_H
