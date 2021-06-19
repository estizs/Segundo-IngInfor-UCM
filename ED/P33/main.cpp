// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

bool multiplo7(int n) {
    // el 7 no nos cae bien
    return n != 7 && n % 7 == 0;
}

bool primo(int n) {
    if (n % 2 == 0) return false;
    else {
        int i = 3;
        while (i < n / 2 && n % i != 0)
            i = i + 2;
        return n % i != 0;
    }
}

// función que resuelve el problema
// ar como los piratas
std::pair<bool, std::pair<int, int>> resolver(bintree<int> const& ar) {
    bool encontrado = false;
    int nodo{};
    int nivel = 0;

    // raíz estúpida
    if (ar.empty() || primo(ar.root()))
        return { false, {} };

    std::queue<std::pair<int, bintree<int>>> cola;
    cola.push({ 1, ar });

    while (!cola.empty() && !encontrado) {
        auto const& par = cola.front();
        // arbolito
        auto const& a = par.second;
        // nivelito
        auto const& aa = par.first;
        if (!primo(a.root()) && multiplo7(a.root())) {
            encontrado = true;
            nodo = a.root();
            nivel = aa;
        }
        // los primos también nos caen mal, cuanta endogamia
        else if(!primo(a.root())) {
            if(!a.left().empty())
                cola.push({ aa + 1, a.left() });
            if (!a.right().empty())
                cola.push({ aa + 1, a.right() });
        }
        cola.pop();
    }
    return { encontrado, {nodo, nivel} };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    std::pair<bool, std::pair<int, int>> sol = resolver(arbol);
    // escribir sol
    if (sol.first)
        std::cout << sol.second.first << " " << sol.second.second << "\n";
    else
        std::cout << "NO HAY\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-33.in");
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