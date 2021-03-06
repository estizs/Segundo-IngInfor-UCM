// Estibaliz Zubimendi
// A79

#include "conjunto.h"

#include <iostream>
#include <iomanip>
#include <fstream>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo; std::cin >> tipo;
    if (!std::cin)
        return false;
    int k; std::cin >> k;
    if (tipo == 'N') {
        set<int> s(k);
        int aux; 
        for (int i = 0; i < k; ++i) {
            std::cin >> aux;
            if (!s.contains(aux))
                s.insert(aux);
            // si hay repetidos al principio inserto el mínimo posible
            else s.insert(0);
        }
        std::cin >> aux;
        while (aux != -1) {
            if (aux > s.min() && !s.contains(aux)) {
                s.erase_min();
                s.insert(aux);
            }
            std::cin >> aux;
        }
        for (auto it = s.end() - 1; it >= s.begin(); --it)
            std::cout << *it << " ";
        std::cout << "\n";
    }
    else {
        set<std::string> s(k);
        std::string aux;
        for (int i = 0; i < k; ++i) {
            std::cin >> aux;
            if (!s.contains(aux))
                s.insert(aux);
            // si hay repetidos al principio inserto el mínimo posible
            else s.insert("");
        }
        std::cin >> aux;
        while (aux != "FIN") {
            if (aux > s.min() && !s.contains(aux)) {
                s.erase_min();
                s.insert(aux);
            }
            std::cin >> aux;
        }
        for (auto it = s.end() - 1; it >= s.begin(); --it)
            std::cout << *it << " ";
        std::cout << "\n";
    }


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-05.in");
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