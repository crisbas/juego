#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "Marcador.h"

class Jugador {
private:
    string nombre;
    vector<int> columnasGanadas;
    char simbolo;

public:
    vector<Marcador> marcadores;
    vector<Marcador> marcadoresPermanentes;

    Jugador(string n, char s);
    string getNombre() const;
    char getSimbolo() const;
    void ganarColumna(int columna);
    bool tieneColumna(int columna) const;
    int columnasGanadasTotal() const;
    void perderColumna(int columna);
};

#endif // JUGADOR_H