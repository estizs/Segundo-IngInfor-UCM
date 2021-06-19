// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

class ListaAmpliada : public deque<int> {
    using Nodo = typename deque<int>::Nodo;
public:
    void mezclar(ListaAmpliada &lista) {
        Nodo* l1 = this->fantasma->sig;
        Nodo* l2 = lista.fantasma->sig;
        Nodo* ult = this->fantasma; // anterior al primero enena<3
        int i = 0, j = 0;
        while (i < this->nelems && j < lista.nelems) {
            if (l1->elem <= l2->elem) {
                ult->sig = l1;
                l1->ant = ult;
                ult = ult->sig;
                l1 = l1->sig;
                ++i;
            }
            else { // l1->elem > l2->elem
                ult->sig = l2;
                l2->ant = ult;
                ult = ult->sig;
                l2 = l2->sig;
                ++j;
            }
        }
        // ifs por si alguna lista ha uqedado son recorrer
        if (i < this->nelems) {
            ult->sig = l1;
            ult = this->fantasma->ant;
        }
        if (j < lista.nelems) {
            ult->sig = l2;
            ult = lista.fantasma->ant;
        }
        this->fantasma->ant = ult;
        ult->sig = this->fantasma;
        this->nelems += lista.nelems;
        lista.fantasma->ant = lista.fantasma;
        lista.fantasma->sig = lista.fantasma;
        lista.nelems = 0;
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
void resuelveCaso() {
    // leer los datos de la entrada
    ListaAmpliada lista1;
    int aux; std::cin >> aux;
    while (aux != 0) {
        lista1.push_back(aux);
        std::cin >> aux;
    }
    ListaAmpliada lista2;
    std::cin >> aux;
    while (aux != 0) {
        lista2.push_back(aux);
        std::cin >> aux;
    }
    lista1.mezclar(lista2);
    lista1.mostrar();
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-16.in");
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