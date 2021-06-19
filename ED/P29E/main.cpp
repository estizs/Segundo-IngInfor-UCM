// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tsol {
    int altura, diametro;
};

tsol resolver(bintree<char> const& a) {
    if (a.empty())
        return { 0, 0 };
    else {
        tsol izq = resolver(a.left());
        tsol dcha = resolver(a.right());
        return { std::max(izq.altura, dcha.altura) + 1, std::max({izq.altura + dcha.altura + 1, izq.diametro, dcha.diametro}) };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    tsol sol = resolver(arbol);
    // escribir sol
    std::cout << sol.diametro << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-29E.in");
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