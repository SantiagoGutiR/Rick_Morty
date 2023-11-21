#ifndef OBJETOS_H
#define OBJETOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsView>

class Objetos: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Objetos();
    void Setup_Imagen(QString ruta, int x, int y, int ancho, int alto, float tamano);
};

#endif // OBJETOS_H
