#include "Dado.h"

int Dado::tirar() {
    return rand() % 6 + 1;
}