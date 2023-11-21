#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QPushButton>
#include "objetos.h"

class menu: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *escena;
    QPushButton *jugar;
    Objetos *fondo;

    void setup_escena();
public:
    menu();
    ~menu();
    QGraphicsScene *getEscena() const;
    QPushButton *getJugar() const;
};

#endif // MENU_H
