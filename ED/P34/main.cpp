// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

// función que resuelve el problema
std::vector<int> resolver(bintree<int> const& a) {
    std::vector<int> dev;

    if (a.empty())
        return {};

    std::queue<std::pair<int, bintree<int>>> cola;
    cola.push({ 1, a });
    // la raíz siempre se ve
    dev.push_back(a.root());
    // dev tiene el tamaño de la altura del árbol

    while (!cola.empty()) {
        auto const& par = cola.front();
        auto const& f = par.first;
        auto const& s = par.second;
        if (dev.size() != f) {
            dev.push_back(s.root());
        }
        if (!s.left().empty())
            cola.push({ f + 1, s.left() });
        if (!s.right().empty())
            cola.push({ f + 1, s.right() });
        cola.pop();
    }
    return dev;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    std::vector<int> sol = resolver(arbol);
    // escribir sol
    for (int i = 0; i < sol.size(); ++i)
        std::cout << sol[i] << " ";
    std::cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-34.in");
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