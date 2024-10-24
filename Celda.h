#ifndef CELDA_H
#define CELDA_H

#include <iostream>
using namespace std;

class Celda {
public:
    char c_[4];

    Celda(char a = ' ', char b = ' ', char c = ' ', char d = ' ') {
        c_[0] = a;
        c_[1] = b;
        c_[2] = c;
        c_[3] = d;
    }

    void mostrar();
    void actualizar(char simbolo);
    char getSimbolo() const;
};

#endif // CELDA_H
