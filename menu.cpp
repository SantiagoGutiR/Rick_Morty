#include "menu.h"

menu::menu()
{
    escena = new QGraphicsScene;
    jugar = new QPushButton;
    fondo = new Objetos;

    fondo->Setup_Imagen(":/Imagenes/Inicio_fondo.png", 0, 0, 495, 275, 2.2);
    fondo->setPos(0,0);
    jugar->setText("Jugar");
    jugar->setGeometry(450, 400, 100, 50);
    setup_escena();
}

void menu::setup_escena()
{
    escena->setSceneRect(0,0,998,598);
    escena->addItem(fondo);
    escena->addWidget(jugar);
}

QGraphicsScene *menu::getEscena() const
{
    return escena;
}

QPushButton *menu::getJugar() const
{
    return jugar;
}

menu::~menu()
{
    delete escena;
    delete jugar;
    delete fondo;
}
