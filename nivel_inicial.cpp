#include "nivel_inicial.h"

nivel_inicial::nivel_inicial()
{
    escena = new QGraphicsScene;
    fondo = new Objetos();
    tiempo_limite = new QTimer();
    for(short i = 0; i < 7 ; i++){
        piezas.push_back(new QPushButton);
    }
    piezas.shrink_to_fit();
    for(short i = 0; i < 7 ; i ++){
        imagenes.push_back(new Objetos);
    }
    imagenes.shrink_to_fit();

    armas_encontradas = 0;
    ocultar_armas();
    setup_escena();
    connect(piezas[0], SIGNAL(clicked(bool)), this, SLOT(boton1_valido()));
    connect(piezas[1], SIGNAL(clicked(bool)), this, SLOT(boton2_valido()));
    connect(piezas[2], SIGNAL(clicked(bool)), this, SLOT(boton3_valido()));
    connect(piezas[3], SIGNAL(clicked(bool)), this, SLOT(boton4_valido()));
    connect(piezas[4], SIGNAL(clicked(bool)), this, SLOT(boton5_valido()));
    connect(piezas[5], SIGNAL(clicked(bool)), this, SLOT(boton6_valido()));
    connect(piezas[6], SIGNAL(clicked(bool)), this, SLOT(boton7_valido()));
    connect(tiempo_limite, SIGNAL(timeout()), this, SLOT(tiempo_agotado()));
}

void nivel_inicial::setup_escena()
{
    for(short i = 0; i < 7 ; i++){
        escena->addWidget(piezas[i]);
    }
    fondo->Setup_Imagen(":/Imagenes/Fondo_inicial.jpeg", 0, 0, 1080, 607, 0.92);
    escena->addItem(fondo);
    for(short i = 0; i < 7 ; i ++){
        escena->addItem(imagenes[i]);
    }
}

void nivel_inicial::asignar_bonus()
{
    if(armas_encontradas < 3)armas_encontradas = 200;
    else if(armas_encontradas >= 3 && armas_encontradas < 6) armas_encontradas = 400;
    else if(armas_encontradas >= 6) armas_encontradas = 600;
}

void nivel_inicial::arma_encontrada(int i)
{
    piezas[i]->setEnabled(false);
    imagenes[i]->setVisible(false);
    armas_encontradas ++;

    if(armas_encontradas == 7){
        tiempo_limite->stop();
        armas_encontradas = 600;
        emit cambio_nivel(armas_encontradas);
    }
}

void nivel_inicial::boton1_valido()
{//Slot
    arma_encontrada(0);
}

void nivel_inicial::boton2_valido()
{//Slot
    arma_encontrada(1);
}

void nivel_inicial::boton3_valido()
{//Slot
    arma_encontrada(2);
}

void nivel_inicial::boton4_valido()
{//Slot
    arma_encontrada(3);
}

void nivel_inicial::boton5_valido()
{//Slot
    arma_encontrada(4);
}

void nivel_inicial::boton6_valido()
{//Slot
    arma_encontrada(5);
}

void nivel_inicial::boton7_valido()
{//Slot
    arma_encontrada(6);
}

void nivel_inicial::tiempo_agotado()
{//SLot
    tiempo_limite->stop();
    asignar_bonus();
    emit cambio_nivel(armas_encontradas);
}

nivel_inicial::~nivel_inicial()
{
    delete escena;
    for(short i = 0; i < piezas.length() ; i++){
        delete piezas[i];
    }
    for(short i = 0; i < imagenes.length() ; i ++){
        delete imagenes[i];
    }
    delete tiempo_limite;
}

QGraphicsScene *nivel_inicial::getEscena() const
{
    return escena;
}

QTimer *nivel_inicial::getTiempo_limite() const
{
    return tiempo_limite;
}

void nivel_inicial::ocultar_armas()
{
    piezas[0]->setGeometry(450*0.92, 375*0.92, 36, 28);
    imagenes[0]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);
    imagenes[0]->setPos(450*0.92, 375*0.92);

    piezas[1]->setGeometry(312*0.92, 27*0.92, 36, 28);
    imagenes[1]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);
    imagenes[1]->setPos(312*0.92, 27*0.92);

    piezas[2]->setGeometry(932*0.92, 164*0.92, 36, 28);
    imagenes[2]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);
    imagenes[2]->setPos(932*0.92, 164*0.92);

    piezas[3]->setGeometry(107*0.92, 210*0.92, 36, 28);
    imagenes[3]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);
    imagenes[3]->setPos(107*0.92, 210*0.92);

    piezas[4]->setGeometry(935*0.92, 396*0.92, 36, 28);
    imagenes[4]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);
    imagenes[4]->setPos(935*0.92, 396*0.92);

    piezas[5]->setGeometry(140*0.92, 453*0.92, 36, 28);
    imagenes[5]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);
    imagenes[5]->setPos(140*0.92, 453*0.92);

    piezas[6]->setGeometry(636*0.92, 565*0.92, 36, 28);
    imagenes[6]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);
    imagenes[6]->setPos(636*0.92, 565*0.92);
}
