#ifndef NIVEL_PRINCIPAL_H
#define NIVEL_PRINCIPAL_H
#define total_plataformas 8
#define total_balas 1

#include "objetos.h"
#include "personaje.h"
#include "reglas.h"
#include "balas.h"
#include <QKeyEvent>
#include <QTimer>

class nivel_principal: public QObject, public reglas
{
    Q_OBJECT
private:
    QGraphicsScene *escena;
    Objetos *fondo;
    QVector <Objetos*> plataformas;
    QVector <balas*> pistolas;
    personaje *jugador;
    QTimer *tiempo_caida;
    QTimer *tiempo_salto;
    QTimer *tiempo_disparo;

    void setup_escena();
    void cargar_imagenes();
    void crear_balas();
    void poscionar_plataformas();
private slots:
    void jugador_caida();
    void jugador_salto();
    void disparar();
public:
    nivel_principal();
    void moviento_personaje(QKeyEvent *event);
    ~nivel_principal();
    QGraphicsScene *getEscena() const;
    QTimer *getTiempo_disparo() const;
};

#endif // NIVEL_PRINCIPAL_H
