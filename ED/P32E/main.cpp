// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tsol {
    int altMax, altRaiz;
};

// función que resuelve el problema
tsol resolver(bintree<char> const& a) {
    if (a.empty())
        return { 0,0 };
    else {
        tsol izq = resolver(a.left());
        tsol dcha = resolver(a.right());
        int altR = std::min(izq.altRaiz, dcha.altRaiz) + 1;
        int altM = std::max(izq.altMax, dcha.altMax, altR);
        return { altM, altR };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    tsol sol = resolver(arbol);
    std::cout << sol.altMax << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-32E.in");
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