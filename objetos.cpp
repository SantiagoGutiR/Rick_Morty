#include "objetos.h"

Objetos::Objetos()
{

}

void Objetos::Setup_Imagen(QString ruta, int x, int y, int ancho, int alto, float tamano)
{
    QPixmap variable(ruta);
    variable = variable.copy(x, y, ancho, alto);
    setPixmap(variable.scaled(ancho*tamano, alto*tamano));
}
