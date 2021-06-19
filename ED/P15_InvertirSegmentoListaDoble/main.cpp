// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

class ListaDobleAmpliada : public deque<int> {
    using Nodo = typename deque<int>::Nodo;
    void aux_invertir(Nodo* prim_elem, Nodo* ult_elem, Nodo*& prim_intervalo, Nodo*& ult_intervalo, int n) {
        Nodo* act = prim_elem;
        Nodo* sig = act->sig;
        ult_intervalo = prim_elem;
        act->sig = act->ant;
        for (int i = 1; i < n; ++i) {
            act = sig;
            sig = sig->sig;
            act->sig = act->ant;
        }
        prim_intervalo = act;
    }
public:
    void invertirSegmento(int ini, int n) {
        Nodo* prim = this->fantasma->sig;
        for (int i = 1; i < ini; ++i)
            prim = prim->sig;
        Nodo* ant_prim = prim->ant;
        Nodo* ult = prim;
        for (int i = 1; i < n; ++i)
            ult = ult->sig;
        Nodo* sig_ult = ult->sig;

        Nodo* prim_intervalo = nullptr;
        Nodo* ult_intervalo = nullptr;
        aux_invertir(prim, ult, prim_intervalo, ult_intervalo, n);

        // no debería haber problema
        ant_prim->sig = prim_intervalo;
        ult_intervalo->sig = sig_ult;
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
    int ini, fin; std::cin >> ini >> fin;
    ListaDobleAmpliada lista;
    int aux;
    for (int i = 0; i < n; ++i) {
        std::cin >> aux;
        lista.push_back(aux);
    }
    if(fin > 1)
        lista.invertirSegmento(ini, fin);
    lista.mostrar();
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-15.in");
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