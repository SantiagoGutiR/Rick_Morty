#include "menu.h"

menu::menu()
{
    escena = new QGraphicsScene;
    jugar = new QPushButton("Jugar");
    fondo = new Objetos;
    tiempo_animacion = new QTimer;
    for(short n = 0; n < 7; n++){
        historieta.push_back(new Objetos);
    }
    historieta.shrink_to_fit();

    setup_historieta();
    frame_historieta = 1;
    fondo->Setup_Imagen(":/Imagenes/Fondo_menu.jpeg", 0, 0, 1366, 808, 0.73);
    fondo->setPos(0,0);
    jugar->setGeometry(450, 200, 100, 50);
    setup_escena();

    connect(jugar, SIGNAL(clicked(bool)), this, SLOT(boton_jugar()));
    connect(tiempo_animacion, SIGNAL(timeout()), this, SLOT(mostrar_historieta()));
}

void menu::setup_escena()
{
    escena->setSceneRect(0,0,998,598);
    escena->addItem(fondo);
    escena->addWidget(jugar);
}

void menu::mostrar_historieta()
{
    if(frame_historieta < historieta.length())escena->addItem(historieta[frame_historieta]);
    frame_historieta++;
    if(frame_historieta > historieta.length()){
        tiempo_animacion->stop();
        emit cambio_escena();
    }
}

void menu::boton_jugar()
{//Slot
    jugar->setEnabled(false);
    escena->addItem(historieta[0]);
    tiempo_animacion->start(2000);
}


QGraphicsScene *menu::getEscena() const
{
    return escena;
}

menu::~menu()
{
    delete escena;
    delete jugar;
    delete fondo;
    for(short n = 0; n < historieta.length(); n++){
        delete historieta[n];
    }
    delete tiempo_animacion;
}

void menu::setup_historieta(){
    historieta[0]->Setup_Imagen(":/Imagenes/Historia.png", 76, 25, 878, 533, 1.13);
    historieta[1]->Setup_Imagen(":/Imagenes/Historia.png", 995, 32, 872, 524, 1.14);
    historieta[2]->Setup_Imagen(":/Imagenes/Historia.png", 85, 564, 834, 504, 1.19);
    historieta[3]->Setup_Imagen(":/Imagenes/Historia.png", 958, 558, 870, 519, 1.148);
    historieta[4]->Setup_Imagen(":/Imagenes/Historia.png", 78, 1073, 837, 508, 1.19);
    historieta[5]->Setup_Imagen(":/Imagenes/Historia.png", 965, 1078, 874, 520, 1.14);
    historieta[6]->Setup_Imagen(":/Imagenes/Historia.png", 2010, 0, 1000, 600, 1);
}
