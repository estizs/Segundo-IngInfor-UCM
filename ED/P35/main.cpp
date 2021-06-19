// A79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tsol {
    int maxi, alturaPares;
};

// función que resuelve el problema
tsol resolver(bintree<int> const& a) {
    if (a.empty())
        return { 0, 0 };
    else {
        tsol izq = resolver(a.left());
        tsol dcha = resolver(a.right());
        tsol dev;
        if (a.root() % 2 == 0) {
            dev.maxi = std::max({ izq.maxi, dcha.maxi, izq.alturaPares + dcha.alturaPares + 1 });
            dev.alturaPares = std::max(izq.alturaPares, dcha.alturaPares) + 1;  
        }
        else {
            dev.maxi = std::max(izq.maxi, dcha.maxi);
            dev.alturaPares = 0;
        }
        return dev;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    tsol sol = resolver(arbol);
    // escribir sol
    std::cout << sol.maxi << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-35.in");
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