#include "Jugador.h"

Jugador::Jugador(string n, char s) : nombre(n), simbolo(s) {}

string Jugador::getNombre() const {
    return nombre;
}

char Jugador::getSimbolo() const {
    return simbolo;
}

void Jugador::ganarColumna(int columna) {
    if (find(columnasGanadas.begin(), columnasGanadas.end(), columna) == columnasGanadas.end()) {
        columnasGanadas.push_back(columna);
    }
}

bool Jugador::tieneColumna(int columna) const {
    return find(columnasGanadas.begin(), columnasGanadas.end(), columna) != columnasGanadas.end();
}

int Jugador::columnasGanadasTotal() const {
    return columnasGanadas.size();
}

void Jugador::perderColumna(int columna) {
    auto it = find(columnasGanadas.begin(), columnasGanadas.end(), columna);
    if (it != columnasGanadas.end()) {
        columnasGanadas.erase(it);
    }
}
