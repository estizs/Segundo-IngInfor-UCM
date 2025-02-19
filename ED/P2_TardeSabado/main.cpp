﻿// Estibaliz Zubimendi
// A79

#include "peliculas.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int pelis; std::cin >> pelis;
    if (pelis == 0)
        return false;
    try {
        std::vector<Pelicula> v(pelis);
        for (int i = 0; i < pelis; ++i) std::cin >> v[i];
        std::sort(v.begin(), v.end());
        for (int i = 0; i < pelis; ++i) std::cout << v[i] << "\n";
        std::cout << "---\n";
    }
    catch (std::invalid_argument& ia) {
        std::cout << ia.what() << "\n";
    }
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-02.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
