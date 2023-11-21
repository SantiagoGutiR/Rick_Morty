#ifndef NIVEL_INICIAL_H
#define NIVEL_INICIAL_H

#include <QPushButton>
#include "objetos.h"

class nivel_inicial: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *escena;
    Objetos *fondo;
    QVector <bool> piezas_encontradas;
    QVector <QPushButton*> piezas;
    QVector <Objetos*> imagenes;

    void arma_encontrada(int i);
private slots:
    void boton_valido();
public:
    nivel_inicial();
    ~nivel_inicial();
    QGraphicsScene *getEscena() const;

signals:
    void cambio_nivel();
};

#endif // NIVEL_INICIAL_H
