#include <iostream>
#include "Juego.h"

using namespace std;

int main() {
    int numJugadores;
    do {
        cout << "Ingrese la cantidad de jugadores (1 a 3): ";
        cin >> numJugadores;
    } while (numJugadores < 1 || numJugadores > 3);

    Juego juego(numJugadores);
    juego.jugar();
    return 0;
}
