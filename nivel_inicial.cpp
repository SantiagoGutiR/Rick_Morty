#include "nivel_inicial.h"

nivel_inicial::nivel_inicial()
{
    escena = new QGraphicsScene;
    fondo = new Objetos();
    piezas_encontradas.reserve(7);
    for(short i = 0; i < piezas_encontradas.length(); i++){
        piezas_encontradas[i] = false;
    }
    for(short i = 0; i < 7 ; i++){
        piezas.push_back(new QPushButton);
    }
    piezas.shrink_to_fit();
    for(short i = 0; i < 7 ; i ++){
        imagenes.push_back(new Objetos);
    }
    imagenes.shrink_to_fit();

    piezas[0]->setGeometry(450*0.92, 375*0.92, 42, 36);
    //imagenes[0]->Setup_Imagen();


    fondo->Setup_Imagen(":/Imagenes/Fondo_inicial.jpeg", 0, 0, 1080, 607, 0.92);
    escena->addWidget(piezas[0]);
    escena->addItem(fondo);

}

QGraphicsScene *nivel_inicial::getEscena() const
{
    return escena;
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
