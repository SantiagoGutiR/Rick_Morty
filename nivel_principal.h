#ifndef NIVEL_PRINCIPAL_H
#define NIVEL_PRINCIPAL_H
#define total_plataformas 7

#include "objetos.h"

class nivel_principal: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *escena;
    Objetos *fondo;
    QVector <Objetos*> plataformas;
public:
    nivel_principal();
    ~nivel_principal();
    QGraphicsScene *getEscena() const;
};

#endif // NIVEL_PRINCIPAL_H
