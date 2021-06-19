// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct info {
    int sol = 0;
    int caudal = 0;
};

// función que resuelve el problema
info resolver(bintree<int> const& a) {
    // es hoja
    if (a.left().empty() && a.right().empty())
        return { 0, 1 };
    else {
        info izq = { 0, 0 };
        info dcha = { 0, 0 };
        if(!a.left().empty())
            izq = resolver(a.left());
        if(!a.right().empty())
            dcha = resolver(a.right());
        int s = 0;
        if (izq.caudal >= 3)
            ++s;
        if (dcha.caudal >= 3)
            ++s;
        return { izq.sol + dcha.sol + s, std::max(0, izq.caudal + dcha.caudal - a.root()) };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    info sol = resolver(arbol);
    // escribir sol
    std::cout << sol.sol << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-39.in");
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