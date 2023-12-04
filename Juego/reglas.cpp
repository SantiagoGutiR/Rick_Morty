#include "reglas.h"

reglas::reglas()
{

}
bool reglas::verificar_choque(Objetos &personaje, QVector<Objetos*> plataformas)
{
    bool choco = false;
    for(int i = 0; i < plataformas.length(); i++){
        if(personaje.collidesWithItem(plataformas[i])) choco = true;
    }
    return choco;
}
