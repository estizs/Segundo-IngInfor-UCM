// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <climits>
#include "bintree_eda.h"

struct sol{
    int maxi, mini;
    bool es;
};

// función que resuelve el problema
sol resolver(bintree<int> const&a) {
    if (a.empty())
        return { 0, INT_MAX, true };
    else {
        sol izq = resolver(a.left());
        sol dcha = resolver(a.right());
        return { std::max({izq.maxi, dcha.maxi, a.root()}),
                 std::min({izq.mini, dcha.mini, a.root()}),
                 izq.es && dcha.es && a.root() > izq.maxi && a.root() < dcha.mini };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    sol sol = resolver(arbol);
    // escribir sol
    if (sol.es)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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