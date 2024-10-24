#include "Juego.h"

Juego::Juego(int numJugadores) {
    char simbolos[] = { 'A', 'B', 'C' };
    for (int i = 0; i < numJugadores; ++i) {
        string nombre;
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> nombre;
        jugadores.emplace_back(nombre, simbolos[i]);
    }
    jugadorActual = 0;
    srand(time(0));
}

void Juego::turno() {
    Jugador& jugador = jugadores[jugadorActual];
    cout << "\033[36m" << "Turno de " << jugador.getNombre() << " (" << jugador.getSimbolo() << ")" << "\033[0m" << "\n";
    marcadoresActivos.clear();

    while (true) {
        cout << "Presiona Enter para tirar los dados...";
        cin.ignore();
        cin.get();

        int dado1 = Dado::tirar();
        int dado2 = Dado::tirar();
        int dado3 = Dado::tirar();
        int dado4 = Dado::tirar();

        cout << "Dados: " << dado1 << ", " << dado2 << ", " << dado3 << ", " << dado4 << "\n";

        vector<pair<int, int>> opciones = {
            {dado1 + dado2, dado3 + dado4},
            {dado1 + dado3, dado2 + dado4},
            {dado1 + dado4, dado2 + dado3}
        };

        cout << "Elige qué pareja de dados usar:\n";
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << ". (" << opciones[i].first << ", " << opciones[i].second << ")\n";
        }

        int eleccion;
        cin >> eleccion;
        eleccion = max(1, min(3, eleccion)) - 1;

        vector<int> sumas = {opciones[eleccion].first, opciones[eleccion].second};

        if (!tablero.puedeMoverse(sumas, marcadoresActivos)) {
            cout << "\033[31m" << "¡Has sido eliminado! No puedes mover ningún marcador." << "\033[0m" << "\n";
            marcadoresActivos.clear();
            jugadorActual = (jugadorActual + 1) % jugadores.size();
            return;
        }

        for (int suma : sumas) {
            auto it = find_if(marcadoresActivos.begin(), marcadoresActivos.end(),
                [suma](const Marcador& m) { return m.columna == suma; });

            if (it != marcadoresActivos.end()) {
                if (sumas[0] == sumas[1]) {
                    if (!tablero.moverMarcador(*it, jugador.getSimbolo(), 2)) {
                        cout << "No se puede mover el marcador en la columna " << suma << "\n";
                    }
                } else {
                    if (!tablero.moverMarcador(*it, jugador.getSimbolo(), 1)) {
                        cout << "No se puede mover el marcador en la columna " << suma << "\n";
                    }
                }
            } else if (marcadoresActivos.size() < 3) {
                Marcador nuevoMarcador(suma);
                if (sumas[0] == sumas[1]) {
                    if (tablero.moverMarcador(nuevoMarcador, jugador.getSimbolo(), 2)) {
                        marcadoresActivos.push_back(nuevoMarcador);
                    }
                } else {
                    if (tablero.moverMarcador(nuevoMarcador, jugador.getSimbolo(), 1)) {
                        marcadoresActivos.push_back(nuevoMarcador);
                    }
                }
            }
        }

        tablero.mostrarTablero();

        cout << "¿Quieres seguir jugando? (s/n)\n";
        char decision;
        cin >> decision;

        if (decision == 'n') {
            tablero.hacerMarcadoresPermanentes(marcadoresActivos, jugador.getSimbolo());

            for (const Marcador& marcador : marcadoresActivos) {
                if (tablero.columnaCompleta(marcador.columna)) {
                    jugador.ganarColumna(marcador.columna);

                    for (Jugador& otroJugador : jugadores) {
                        if (&otroJugador != &jugador && otroJugador.tieneColumna(marcador.columna)) {
                            otroJugador.perderColumna(marcador.columna);
                            tablero.limpiarColumnaPerdida(marcador.columna, otroJugador.getSimbolo());
                        }
                    }
                }
            }

            if (jugador.columnasGanadasTotal() >= 3) {
                cout << "\033[33m" << "¡" << jugador.getNombre() << " ha ganado el juego!" << "\033[0m" << "\n";
                exit(0);
            }

            marcadoresActivos.clear();
            jugadorActual = (jugadorActual + 1) % jugadores.size();
            return;
        }
    }
}

void Juego::jugar() {
    while (true) {
        turno();
    }
}
