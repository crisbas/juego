#ifndef TABLERO_H
#define TABLERO_H

#include <map>
#include <vector>
#include "TableroVisual.h"
#include "Marcador.h"
#include "Jugador.h"

class Tablero {
private:
    map<int, int> columnas;
    TableroVisual visualTablero;
    map<int, vector<pair<int, char>>> marcadoresTemporales;

public:
    Tablero();
    bool puedeMoverse(const vector<int>& sumas, const vector<Marcador>& marcadoresActivos);
    bool moverMarcador(Marcador& marcador, char simbolo, int cantidadCasillas, bool esPermanente = false);
    void limpiarMarcadoresTemporales();
    void hacerMarcadoresPermanentes(vector<Marcador>& marcadores, char simbolo);
    bool columnaCompleta(int columna);
    void mostrarTablero();
    void limpiarColumnaPerdida(int columna, char simbolo);
};

#endif // TABLERO_H