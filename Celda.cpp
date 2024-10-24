#include "Celda.h"

void Celda::mostrar() {
    cout << "\033[31m" << c_[0] << c_[1] << c_[2] << c_[3] << "\033[0m|";
}

void Celda::actualizar(char simbolo) {
    c_[0] = simbolo;
}

char Celda::getSimbolo() const {
    return c_[0];
}