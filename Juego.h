#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <iostream>
#include "Jugador.h"
#include "Tablero.h"
#include "Dado.h"

using namespace std;

class Juego {
private:
    vector<Jugador> jugadores;
    Tablero tablero;
    int jugadorActual;
    vector<Marcador> marcadoresActivos;

public:
    Juego(int numJugadores);
    void turno();
    void jugar();
};

#endif // JUEGO_H