#include "nivel_principal.h"

nivel_principal::nivel_principal()
{
    vidas = 3;
    nivel_actual = 1;
    escena = new QGraphicsScene();
    for(short i = 0; i < 3 ; i++){
        fondo.push_back(new Objetos);
    }
    fondo.shrink_to_fit();
    jugador = new personaje();
    tiempo_caida = new QTimer();
    tiempo_salto = new QTimer();
    tiempo_disparo = new QTimer();
    tiempo_nivel = new QTimer();
    score = new QLabel("Puntaje: ");
    lives = new QLabel("Vidas: ");
    for(int i = 0 ; i < total_plataformas ; i++){
        plataformas.push_back(new Objetos);
    }
    plataformas.shrink_to_fit();
    restricciones.push_back(new Objetos); //Pendiente


    actualizar_parametros();
    crear_balas();
    cargar_imagenes();
    poscionar_plataformas();
    setup_escena();

    connect(tiempo_caida, SIGNAL(timeout()), this, SLOT(jugador_caida()));
    connect(tiempo_salto, SIGNAL(timeout()), this, SLOT(jugador_salto()));
    connect(tiempo_disparo, SIGNAL(timeout()), this, SLOT(disparar()));
    connect(tiempo_nivel, SIGNAL(timeout()), this, SLOT(aumentar_nivel()));
}

void nivel_principal::crear_balas()
{
    for(short n = 0 ; n < 2 ; n++){
        pistolas.push_back(new balas('A', 968, 300));//Falta las otras balas
    }
    pistolas.shrink_to_fit();

}

void nivel_principal::cargar_imagenes()
{
    fondo[0]->Setup_Imagen(":/Imagenes/Fondo_principal.jpeg", 0, 0, 1600, 940, 0.62);
    fondo[1]->Setup_Imagen(":/Imagenes/Imagenes_finales.jpeg", 0, 0, 990, 590, 1);
    fondo[2]->Setup_Imagen(":/Imagenes/Imagenes_finales.jpeg", 1007, 0, 990, 590, 1);

    jugador->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.03);//Organizar
    jugador->setPos(400, 300);

    for(int i = 0 ; i < total_plataformas ; i++){
        plataformas[i]->Setup_Imagen(":/Imagenes/Plataforma.png", 0, 0, 955, 87, 0.31);
    }
    restricciones[0]->Setup_Imagen(":/Imagenes/Plataforma.png", 0, 0, 955, 87, 0.314); //Pendiente
    restricciones[0]->setVisible(false);

    score->setStyleSheet("background-color: black; color: white;");
    score->setFont(QFont("Snap ITC", 20));
    lives->setStyleSheet("background-color: black; color: white;");
    lives->setFont(QFont("Snap ITC", 20));
    score->setGeometry(175*0.62, 875*0.62, 370*0.62, 60*0.62);
    lives->setGeometry(990*0.62, 875*0.62, 370*0.62, 60*0.62);

    pistolas[0]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.025); //Hacer el for con la imagen elegida
    pistolas[1]->Setup_Imagen(":/Imagenes/Pistola.png", 0, 0, 1200, 929, 0.025);
}

void nivel_principal::poscionar_plataformas()
{
    plataformas[0]->setPos(125,150);
    restricciones[0]->setPos(124,151);//Pendiente
    plataformas[1]->setPos(425,250);
    plataformas[2]->setPos(125,350);
    plataformas[3]->setPos(425,450);
    plataformas[4]->setPos(525,150);
    plataformas[5]->setPos(225,250);
    plataformas[6]->setPos(525,350);
    plataformas[7]->setPos(225,450);
}

void nivel_principal::setup_escena()
{
    escena->addItem(fondo[0]);
    for(int i = 0 ; i < total_plataformas ; i++){
        escena->addItem(plataformas[i]);
    }
    for(int i = 0 ; i < pistolas.length() ; i++){
        escena->addItem(pistolas[i]);
    }
    escena->addItem(restricciones[0]); //Pendiente
    escena->addWidget(score);
    escena->addWidget(lives);
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
    if(verificar_choque(*jugador, restricciones)){
        jugador->setPos(jugador->x(), jugador->y()+velocidad);
        tiempo_salto->stop();
        jugador->setN(1000);
        tiempo_caida->start(1000*0.01);
    }
    else if(verificar_choque(*jugador, plataformas)){
        tiempo_salto->stop();
        jugador->setN(1000);
    }
}

void nivel_principal::disparar()
{//Slot
    for(int i = 0 ; i < total_balas*nivel_actual ; i++){
        if(i < pistolas.length())pistolas[i]->mover();
    }
    validar_movimiento_bala();
    puntaje += 1;
    actualizar_parametros();
}

void nivel_principal::aumentar_nivel()
{//Slot
    if(nivel_actual == 2) ganar();
    else{
        tiempo_disparo->stop();
        nivel_actual++;
        puntaje += 100;
        tiempo_disparo->start(8);
        escena->removeItem(plataformas[4]);
        escena->removeItem(plataformas[5]);
        escena->removeItem(plataformas[6]);
        escena->removeItem(plataformas[7]);
        for(short n = 0; n < 4 ; n++){
            delete plataformas[4+n];
            plataformas.pop_back();
        }
        plataformas.shrink_to_fit();
    }
}

void nivel_principal::validar_movimiento_bala()
{
    for(int i = 0 ; i < total_balas ; i++){
        if(pistolas[i]->collidesWithItem(jugador)){
            vidas --;
            actualizar_parametros();
            pistolas[i]->devolver();
            if(vidas == 0){
                fin_juego();
            }
        }
    }
}

void nivel_principal::actualizar_parametros()
{
    QString temp;
    temp = "Puntaje: ";
    temp.push_back(QString::number(puntaje));
    score->setText(temp);
    temp.clear();
    temp = "Vidas: ";
    temp.push_back(QString::number(vidas));
    lives->setText(temp);
    temp.clear();
}

void nivel_principal::fin_juego()
{
    tiempo_nivel->stop();
    tiempo_disparo->stop();
    tiempo_caida->stop();
    tiempo_salto->stop();
    escena->addItem(fondo[2]);
}

void nivel_principal::ganar()
{
    tiempo_nivel->stop();
    tiempo_disparo->stop();
    tiempo_caida->stop();
    tiempo_salto->stop();
    escena->addItem(fondo[1]);
}

nivel_principal::~nivel_principal(){
    delete escena;
    for(int i = 0 ; i < fondo.length(); i++){
        delete fondo[i];
    }
    for(int i = 0 ; i < plataformas.length() ; i++){
        delete plataformas[i];
    }
    delete jugador;
    delete tiempo_caida;
    delete tiempo_salto;
    for(int i = 0 ; i < pistolas.length() ; i++){
        delete pistolas[i];
    }
    delete tiempo_disparo;
    delete tiempo_nivel;
    delete score;
    delete lives;
}

QGraphicsScene *nivel_principal::getEscena() const
{
    return escena;
}

QTimer *nivel_principal::getTiempo_disparo() const
{
    return tiempo_disparo;
}

void nivel_principal::setPuntaje(int newPuntaje)
{
    puntaje = newPuntaje;
}

QTimer *nivel_principal::getTiempo_nivel() const
{
    return tiempo_nivel;
}

