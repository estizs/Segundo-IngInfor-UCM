// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

class ListaAmpliada : public queue<int>{
    using Nodo = typename queue<int>::Nodo;
public:
    void duplicarNodos() {
        // hacer una copia del elemento original
        // hacer que el elemento original apunte a la copia
        Nodo* it = this->prim;
        for (int i = 0; i < this->size(); ++i) {
            Nodo* aux = new Nodo(it->elem, it->sig);
            it->sig = aux;
            it = aux->sig;
        }
        this->ult = it;
        this->nelems = 2 * this->nelems;
    }
    void mostrar() {
        Nodo* it = this->prim;
        for (int i = 0; i < this->nelems; ++i) {
            std::cout << (*it).elem << " ";
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
    lista.duplicarNodos();
    lista.mostrar();

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-09.in");
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