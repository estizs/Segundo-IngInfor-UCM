// Estibaliz Zubimendi
// A79


#include <iostream>
#include <fstream>
#include "deque_eda.h"

class ListaDobleAmpliada : public deque<int> {
    using Nodo = typename deque<int>::Nodo;
public:
    void invertirLista() {
        Nodo* act = this->fantasma;
        Nodo* sig = act->sig;
        act->sig = act->ant;
        while (sig->sig != this->fantasma) {
            act = sig;
            sig = sig->sig;
            act->sig = act->ant;
        }
        sig->sig = sig->ant;
    }
    void mostrar() {
        Nodo* it = this->fantasma->sig;
        for (int i = 0; i < this->nelems; ++i) {
            std::cout << it->elem << " ";
            it = it->sig;
        }
        std::cout << "\n";
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    ListaDobleAmpliada lista;
    while (n != 0) {
        lista.push_back(n);
        std::cin >> n;
    }
    lista.invertirLista();
    lista.mostrar();
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-14.in");
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