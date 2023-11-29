#ifndef NIVEL_INICIAL_H
#define NIVEL_INICIAL_H

#include <QPushButton>
#include <QTimer>
#include "objetos.h"

class nivel_inicial: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *escena;
    Objetos *fondo;
    int armas_encontradas;
    QVector <QPushButton*> piezas;
    QVector <Objetos*> imagenes;
    QTimer *tiempo_limite;
    QVector <Objetos*> historieta;
    int frame_historieta;
    QTimer *tiempo_animacion;

    void ocultar_armas();
    void setup_historieta();
    void arma_encontrada(int i);
    void setup_escena();
    void asignar_bonus();
private slots:
    void boton1_valido();
    void boton2_valido();
    void boton3_valido();
    void boton4_valido();
    void boton5_valido();
    void boton6_valido();
    void boton7_valido();
    void tiempo_agotado();
    void mostrar_historieta();
public:
    nivel_inicial();
    ~nivel_inicial();
    QGraphicsScene *getEscena() const;

    QTimer *getTiempo_limite() const;

signals:
    void cambio_nivel(int bonus);
};

#endif // NIVEL_INICIAL_H
