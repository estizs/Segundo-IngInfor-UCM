﻿// Estibaliz Zubimendi
// A79

#include "complejo.h"

#include <iostream>
#include <iomanip>
#include <fstream>

const float UPPER_BOUND = 2.0;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    float real, img; std::cin >> real >> img;
    int n; std::cin >> n;
    Complejo prev_c = Complejo(real, img);
    Complejo c = Complejo(real, img);
    while (n > 0 && c.mod() <= UPPER_BOUND) {
        c = c * c + prev_c;
        --n;
    }
    // escribir sol
    if (n == 0) std::cout << "SI\n";
    else std::cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-03.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}