#include "Tablero.h"

Tablero::Tablero() {
    for (int i = 2; i <= 12; ++i) {
        columnas[i] = 0;
    }
}

bool Tablero::puedeMoverse(const vector<int>& sumas, const vector<Marcador>& marcadoresActivos) {
    if (marcadoresActivos.empty()) {
        return true;
    }

    for (int suma : sumas) {
        for (const Marcador& marcador : marcadoresActivos) {
            if (marcador.columna == suma && !columnaCompleta(suma)) {
                return true;
            }
        }
    }
    return false;
}

bool Tablero::moverMarcador(Marcador& marcador, char simbolo, int cantidadCasillas, bool esPermanente) {
    if (columnas[marcador.columna] < visualTablero.getAlturaColumna(marcador.columna)) {
        int posicionFinal = marcador.posicion + cantidadCasillas;
        if (posicionFinal < visualTablero.getAlturaColumna(marcador.columna)) {
            for (int i = marcador.posicion; i < posicionFinal; ++i) {
                if (visualTablero.getSimbolo(marcador.columna, i) != ' ') {
                    marcador.posicion = i + 1;
                    break;
                }
            }
        }
        visualTablero.actualizarTablero(marcador.columna, marcador.posicion, simbolo);
        columnas[marcador.columna] = marcador.posicion;
        marcador.posicion += cantidadCasillas;

        if (!esPermanente) {
            marcadoresTemporales[marcador.columna].emplace_back(marcador.posicion - 1, simbolo);
        }
        return true;
    }
    return false;
}

void Tablero::limpiarMarcadoresTemporales() {
    for (const auto& par : marcadoresTemporales) {
        for (const auto& marcador : par.second) {
            visualTablero.limpiarPosicion(par.first, marcador.first);
        }
    }
    marcadoresTemporales.clear();
}

void Tablero::hacerMarcadoresPermanentes(vector<Marcador>& marcadores, char simbolo) {
    for (auto& marcador : marcadores) {
        for (int i = 0; i < marcador.posicion; i++) {
            visualTablero.actualizarTablero(marcador.columna, i, simbolo);
        }
        marcador.permanente = true;
    }
    marcadoresTemporales.clear();
}

bool Tablero::columnaCompleta(int columna) {
    return columnas[columna] >= visualTablero.getAlturaColumna(columna);
}

void Tablero::mostrarTablero() {
    visualTablero.mostrar();
}

void Tablero::limpiarColumnaPerdida(int columna, char simbolo) {
    for (int i = 0; i < visualTablero.getAlturaColumna(columna); i++) {
        if (visualTablero.getSimbolo(columna, i) == simbolo) {
            visualTablero.limpiarPosicion(columna, i);
        }
    }
}
