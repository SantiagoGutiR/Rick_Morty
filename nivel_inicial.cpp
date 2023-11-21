#include "nivel_inicial.h"

nivel_inicial::nivel_inicial()
{
    escena = new QGraphicsScene;
    fondo = new Objetos();
    for(short i = 0; i < 7; i++){
        piezas_encontradas.push_back(false);
    }
    piezas_encontradas.shrink_to_fit();
    for(short i = 0; i < 7 ; i++){
        piezas.push_back(new QPushButton);
    }
    piezas.shrink_to_fit();
    for(short i = 0; i < 7 ; i ++){
        imagenes.push_back(new Objetos);
    }
    imagenes.shrink_to_fit();

    piezas[0]->setGeometry(450*0.92, 375*0.92, 42, 36);
    imagenes[0]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03571);
    imagenes[0]->setPos(450*0.92, 375*0.92);


    fondo->Setup_Imagen(":/Imagenes/Fondo_inicial.jpeg", 0, 0, 1080, 607, 0.92);
    escena->addWidget(piezas[0]);
    escena->addItem(fondo);
    escena->addItem(imagenes[0]);

    connect(piezas[0], SIGNAL(clicked(bool)), this, SLOT(boton_valido()));
}

QGraphicsScene *nivel_inicial::getEscena() const
{
    return escena;
}

void nivel_inicial::arma_encontrada(int i)
{
    piezas[i]->setEnabled(false);
    imagenes[i]->setVisible(false);
    piezas_encontradas[i] = true;
    emit cambio_nivel();
}

void nivel_inicial::boton_valido()
{//Slot
    arma_encontrada(0);
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
}
