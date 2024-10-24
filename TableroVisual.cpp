#include "TableroVisual.h"

TableroVisual::TableroVisual() {
    guia[0] = 3; guia[1] = 5; guia[2] = 7; guia[3] = 9; guia[4] = 11; guia[5] = 13;
    guia[6] = 11; guia[7] = 9; guia[8] = 7; guia[9] = 5; guia[10] = 3;
    rotulo[0] = "2 : "; rotulo[1] = "3 : "; rotulo[2] = "4 : "; rotulo[3] = "5 : ";
    rotulo[4] = "6 : "; rotulo[5] = "7 : "; rotulo[6] = "8 : "; rotulo[7] = "9 : ";
    rotulo[8] = "10: "; rotulo[9] = "11: "; rotulo[10] = "12: ";

    ptr = new Celda*[11];
    for (int i = 0; i < 11; i++) {
        ptr[i] = new Celda[guia[i]];
        for (int j = 0; j < guia[i]; j++) {
            ptr[i][j] = Celda(' ', ' ', ' ', ' ');
        }
    }
}

void TableroVisual::mostrar() {
    cout << "\033[32m" << "                                 TABLERO" << "\033[0m" << endl;

    for (int i = 0; i < 11; i++) {
        cout << "\033[33m" << rotulo[i] << "\033[0m";

        for (int k = 0; k < ((13 - guia[i]) / 2); k++) {
            cout << "     ";
        }

        cout << "|";
        for (int j = 0; j < guia[i]; j++) {
            ptr[i][j].mostrar();
        }
        cout << endl;
    }
}

void TableroVisual::actualizarTablero(int columna, int posicion, char simbolo) {
    if (columna >= 2 && columna <= 12) {
        int indexColumna = columna - 2;
        if (posicion < guia[indexColumna]) {
            ptr[indexColumna][posicion].actualizar(simbolo);
        }
    }
}

void TableroVisual::limpiarPosicion(int columna, int posicion) {
    if (columna >= 2 && columna <= 12) {
        int indexColumna = columna - 2;
        if (posicion < guia[indexColumna]) {
            ptr[indexColumna][posicion].actualizar(' ');
        }
    }
}

int TableroVisual::getAlturaColumna(int columna) {
    return guia[columna - 2];
}

char TableroVisual::getSimbolo(int columna, int posicion) {
    if (columna >= 2 && columna <= 12) {
        int indexColumna = columna - 2;
        if (posicion < guia[indexColumna]) {
            return ptr[indexColumna][posicion].getSimbolo();
        }
    }
    return ' ';
}

TableroVisual::~TableroVisual() {
    for (int i = 0; i < 11; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}
