#include "nivel_principal.h"

nivel_principal::nivel_principal()
{
    escena = new QGraphicsScene();
    fondo = new Objetos();
    jugador = new personaje();
    tiempo_caida = new QTimer();
    tiempo_salto = new QTimer();
    tiempo_disparo = new QTimer();
    for(int i = 0 ; i < total_plataformas ; i++){
        plataformas.push_back(new Objetos);
    }
    plataformas.shrink_to_fit();

    crear_balas();
    cargar_imagenes();
    poscionar_plataformas();
    setup_escena();

    connect(tiempo_caida, SIGNAL(timeout()), this, SLOT(jugador_caida()));
    connect(tiempo_salto, SIGNAL(timeout()), this, SLOT(jugador_salto()));
    connect(tiempo_disparo, SIGNAL(timeout()), this, SLOT(disparar()));
}

void nivel_principal::crear_balas()
{
    //for(short n = 0 ; n < 2 ; n++){
    pistolas.push_back(new balas('A', 968, 300));
    //}
    pistolas.shrink_to_fit();

}

void nivel_principal::cargar_imagenes()
{
    fondo->Setup_Imagen(":/Imagenes/Fondo_principal.jpeg", 0, 0, 1600, 940, 0.62);

    jugador->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);//Organizar
    jugador->setPos(200, 300);

    for(int i = 0 ; i < total_plataformas ; i++){
        plataformas[i]->Setup_Imagen(":/Imagenes/Plataforma.png", 0, 0, 955, 87, 0.31);
    }

    pistolas[0]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.025); //Hacer el for con la imagen elegida
}

void nivel_principal::poscionar_plataformas()
{
    plataformas[0]->setPos(125,150);
    plataformas[1]->setPos(525,150);
    plataformas[2]->setPos(225,250);
    plataformas[3]->setPos(425,250);
    plataformas[4]->setPos(125,350);
    plataformas[5]->setPos(525,350);
    plataformas[6]->setPos(225,450);
    plataformas[7]->setPos(425,450);
}

void nivel_principal::setup_escena()
{
    escena->addItem(fondo);
    for(int i = 0 ; i < total_plataformas ; i++){
        escena->addItem(plataformas[i]);
    }
    for(int i = 0 ; i < total_balas ; i++){
        escena->addItem(pistolas[i]);
    }
    escena->addItem(jugador);
}


void nivel_principal::moviento_personaje(QKeyEvent *event)
{
    if(!verificar_choque(*jugador, plataformas)) tiempo_caida->start(1000*0.01);
    if(event->key() == Qt::Key_D)jugador->movimiento('D');
    else if(event->key() == Qt::Key_A)jugador->movimiento('A');
    else if(event->key() == Qt::Key_W) tiempo_salto->start(1000*0.01);
}

void nivel_principal::jugador_caida()
{//Slot
    jugador->salto(0, 8);
    if(verificar_choque(*jugador, plataformas)){
        tiempo_caida->stop();
        jugador->setN(1000);
    }
}

void nivel_principal::jugador_salto()
{//Slot
    jugador->salto(0, 9.6);
    if(tiempo_caida->isActive()) tiempo_caida->stop();
    if(verificar_choque(*jugador, plataformas)){
        tiempo_salto->stop();
        jugador->setN(1000);
    }
}

void nivel_principal::disparar()
{//Slot
    for(int i = 0 ; i < total_balas ; i++){
        pistolas[i]->mover();
    }
}

nivel_principal::~nivel_principal(){
    delete escena;
    delete fondo;
    for(int i = 0 ; i < total_plataformas ; i++){
        delete plataformas[i];
    }
    delete jugador;
    delete tiempo_caida;
    delete tiempo_salto;
    for(int i = 0 ; i < total_balas ; i++){
        delete pistolas[i];
    }
    delete tiempo_disparo;
}

QGraphicsScene *nivel_principal::getEscena() const
{
    return escena;
}

QTimer *nivel_principal::getTiempo_disparo() const
{
    return tiempo_disparo;
}

