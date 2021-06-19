// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tsol {
    int nodos, hojas, altura;
};

template <class T>
tsol resolver(bintree<T> const& arbol) {
    if (arbol.empty())
        return { 0, 0, 0 };
    else {
        tsol izq = resolver(arbol.left());
        tsol dcha = resolver(arbol.right());
        bool hoja = arbol.left().empty() && arbol.right().empty();
        int h;
        if (hoja)
            h = izq.hojas + dcha.hojas + 1;
        else
            h = izq.hojas + dcha.hojas;
        return { izq.nodos + dcha.nodos + 1, h , std::max(izq.altura, dcha.altura) + 1 };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    tsol sol = resolver(arbol);
    // escribir sol
    std::cout << sol.nodos << " " << sol.hojas << " " << sol.altura << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-26E.in");
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