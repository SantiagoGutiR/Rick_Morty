#include "nivel_principal.h"

nivel_principal::nivel_principal()
{
    escena = new QGraphicsScene();
    fondo = new Objetos();
    for(int i = 0 ; i < total_plataformas ; i++){
        plataformas.push_back(new Objetos);
    }
    plataformas.shrink_to_fit();

    fondo->Setup_Imagen(":/Imagenes/Fondo_principal.jpeg", 0, 0, 1600, 940, 0.62);
    escena->addItem(fondo);
}

nivel_principal::~nivel_principal(){
    delete escena;
    delete fondo;
    for(int i = 0 ; i < total_plataformas ; i++){
        delete plataformas[i];
    }
}

QGraphicsScene *nivel_principal::getEscena() const
{
    return escena;
}
