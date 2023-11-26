#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QTimer>
#include "objetos.h"

class menu: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *escena;
    QPushButton *jugar;
    Objetos *fondo;
    QVector <Objetos*> historieta;
    QTimer *tiempo_animacion;
    int frame_historieta;

    void setup_escena();
    void setup_historieta();
public:
    menu();
    ~menu();
    QGraphicsScene *getEscena() const;
signals:
    cambio_escena();
private slots:
    void boton_jugar();
    void mostrar_historieta();
};

#endif // MENU_H
