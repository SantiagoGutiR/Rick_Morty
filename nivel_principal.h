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
#include <QLabel>

class nivel_principal: public QObject, public reglas
{
    Q_OBJECT
private:
    QGraphicsScene *escena;
    QVector <Objetos*> fondo;
    QVector <Objetos*> plataformas;
    QVector <Objetos*> restricciones;
    QVector <balas*> pistolas;
    personaje *jugador;
    QTimer *tiempo_caida;
    QTimer *tiempo_salto;
    QTimer *tiempo_disparo;
    QTimer *tiempo_nivel;
    int puntaje, vidas, nivel_actual;
    QLabel *score;
    QLabel *lives;

    void setup_escena();
    void cargar_imagenes();
    void crear_balas();
    void poscionar_plataformas();
    void validar_movimiento_bala();
    void actualizar_parametros();
    void fin_juego();
    void ganar();
private slots:
    void jugador_caida();
    void jugador_salto();
    void disparar();
    void aumentar_nivel();
public:
    nivel_principal();
    void moviento_personaje(QKeyEvent *event);
    ~nivel_principal();
    QGraphicsScene *getEscena() const;
    QTimer *getTiempo_disparo() const;
    void setPuntaje(int newPuntaje);
    QTimer *getTiempo_nivel() const;
};

#endif // NIVEL_PRINCIPAL_H
