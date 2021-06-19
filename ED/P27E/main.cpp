// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

template <class T>
void resolver(bintree<T> const& arbol, std::vector<T> &dev) {
    if (!arbol.empty()) {
        resolver(arbol.left(), dev);
        resolver(arbol.right(), dev);
        if (arbol.left().empty() && arbol.right().empty())
            dev.push_back(arbol.root());
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    std::vector<int> sol;
    resolver(arbol, sol);
    // escribir sol
    for (int i = 0; i < sol.size(); ++i)
        std::cout << sol[i] << " ";
    std::cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-27E.in");
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