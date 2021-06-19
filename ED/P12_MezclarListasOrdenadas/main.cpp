// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

class ListaAmpliada : public queue<int> {
    using Nodo = typename queue<int>::Nodo;
public:

    void mezclar(ListaAmpliada& lista) {
        if (!this->empty() && !lista.empty()) {
            Nodo* l1 = this->prim;
            Nodo* l2 = lista.prim;
            Nodo* ult = this->ult; // último elemento que está bien
            int i = 0, j = 0;
            while (i < this->nelems && j < lista.nelems) {
                if (l1->elem <= l2->elem) {
                    ult->sig = l1;
                    ult = ult->sig;
                    l1 = l1->sig;
                    ++i;
                }
                else { // l1->elem > l2->elem
                    ult->sig = l2;
                    ult = ult->sig;
                    l2 = l2->sig;
                    ++j;
                }
            }
            // como añadimos elementos por el culo de la cola, el siguiente al último es el primero de la nueva lista
            this->prim = this->ult->sig;
            // ifs por si alguna lista ha uqedado son recorrer
            if (i < this->nelems) {
                ult->sig = l1;
                ult = this->ult;
            }
            if (j < lista.nelems) {
                ult->sig = l2;
                ult = lista.ult;
            }
            this->ult = ult;
            this->ult->sig = nullptr;
            this->nelems += lista.nelems;
        }
        else if (this->empty()) {
            this->prim = lista.prim;
            this->ult = lista.ult;
            this->nelems = lista.nelems;
        }
        lista.prim = nullptr;
        lista.ult = nullptr;
        lista.nelems = 0;
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
void resuelveCaso() {
    // leer los datos de la entrada
    ListaAmpliada lista1;
    int aux; std::cin >> aux;
    while (aux != 0) {
        lista1.push(aux);
        std::cin >> aux;
    }
    ListaAmpliada lista2;
    std::cin >> aux;
    while (aux != 0) {
        lista2.push(aux);
        std::cin >> aux;
    }
    lista1.mezclar(lista2);
    lista1.mostrar();
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-12.in");
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