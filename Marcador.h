#ifndef MARCADOR_H
#define MARCADOR_H

class Marcador {
public:
    int columna;
    int posicion;
    bool activo;
    bool permanente;

    Marcador(int col);
};

#endif // MARCADOR_H
