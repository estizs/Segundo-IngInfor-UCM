// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

template <class T>
T resolver(bintree<T> const& arbol) {
    // arbol nunca puede ser empty (porque no se puede calcular el mínimo de un cjto vacío)
    T min = arbol.root();
    // miramos la izquierda
    if (!arbol.left().empty()) {
        T izq = resolver(arbol.left());
        if (izq < min) min = izq;
    }
    // miramos la derecha
    if (!arbol.right().empty()) {
        T dcha = resolver(arbol.right());
        if (dcha < min) min = dcha;
    }
    return min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char aux; std::cin >> aux;
    if (!std::cin)
        return false;
    if (aux == 'N') {
        bintree<int> arbol = leerArbol(-1);
        int sol = resolver(arbol);
        std::cout << sol << "\n";
    }
    else { // aux == 'P'
        std::string vacio = "#";
        bintree<std::string> arbol = leerArbol(vacio);
        std::string sol = resolver(arbol);
        std::cout << sol << "\n";
    }
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-28E.in");
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