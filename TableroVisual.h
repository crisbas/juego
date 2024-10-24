#ifndef TABLEROVISUAL_H
#define TABLEROVISUAL_H

#include "Celda.h"
#include <string>
#include <iostream>
using namespace std;

class TableroVisual {
private:
    int guia[11];
    string rotulo[11];
    Celda** ptr;

public:
    TableroVisual();
    void mostrar();
    void actualizarTablero(int columna, int posicion, char simbolo);
    void limpiarPosicion(int columna, int posicion);
    int getAlturaColumna(int columna);
    char getSimbolo(int columna, int posicion);
    ~TableroVisual();
};

#endif // TABLEROVISUAL_H
