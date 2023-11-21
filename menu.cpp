#include "menu.h"

menu::menu()
{
    escena = new QGraphicsScene;
    jugar = new QPushButton("Jugar");
    fondo = new Objetos;

    fondo->Setup_Imagen(":/Imagenes/Fondo_menu.jpeg", 0, 0, 1366, 808, 0.73);
    fondo->setPos(0,0);
    jugar->setGeometry(450, 200, 100, 50);
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
