// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

class ListaAmpliada : public queue<int> {
    using Nodo = typename queue<int>::Nodo;
public:
    void invertirNodos() {
        // guardar el siguiente al actual para no perderlo
        // modificar act->sig para que apunte al anterior
        // modificar el anterior para que apunte al actual
        // modificar el actual para que apunte al siguiente
        Nodo* ant = this->prim;
        Nodo* act = ant->sig;
        Nodo* next = act->sig;
        while (next != nullptr) {
            act->sig = ant;
            ant = act;
            act = next;
            next = next->sig;
            act->sig = ant;
        }
        this->ult = this->prim;
        this->prim = act;
        (this->prim)->sig = ant;
        (this->ult)->sig = nullptr;
    }

    void mostrar() {
        Nodo* it = this->prim;
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
    ListaAmpliada lista;
    int aux; std::cin >> aux;
    if (!std::cin)
        return false;
    while (aux != 0) {
        lista.push(aux);
        std::cin >> aux;
    }
    if(lista.size() > 1)
        lista.invertirNodos();
    lista.mostrar();

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-10.in");
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