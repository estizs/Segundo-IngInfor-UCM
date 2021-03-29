// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

class ListaAmpliada : public queue<int> {
    using Nodo = typename queue<int>::Nodo;
private:
    void aux_invertir(Nodo* prim_elem, Nodo* ult_elem, Nodo*& ini_intervalo, Nodo*& fin_intervalo, int n) {
        // Copiamos la estructura del problema de invertir lista
        Nodo* ant = prim_elem;
        Nodo* act = ant->sig;
        Nodo* next = act->sig;
        fin_intervalo = prim_elem;
        act->sig = ant;
        // La condición del bucle ahora es que se hagan los cambios n - 2 veces
        for (int i = 1; i < n - 1; ++i) {
            //act->sig = ant;
            ant = act;
            act = next;
            next = next->sig;
            act->sig = ant;
        }
        ini_intervalo = act;
    }
public:
    void invertirSegmento(int ini, int fin) {
        // Obtenemos el nodo anterio al primero que queremos cambiar
        Nodo* prim = this->prim;
        Nodo* ant_prim = nullptr;
        for (int i = 1; i < ini; ++i) {
            ant_prim = prim;
            prim = prim->sig;
        }
        // Obtenemos el último al nodo que queremos cambiar
        Nodo* ult = prim;
        for (int i = 1; i < fin; ++i)
            ult = ult->sig;
        // También guardamos el siguiente al último
        Nodo* sig_ult = ult->sig;

        // Llamamos a la función auxiliar
        Nodo* ini_intervalo = nullptr;
        Nodo* fin_intervalo = nullptr;
        aux_invertir(prim, ult, ini_intervalo, fin_intervalo, fin);
        
        if (ant_prim == nullptr)
            this->prim = ini_intervalo;
        else
            ant_prim->sig = ini_intervalo;
        if (sig_ult == nullptr) {
            this->ult = fin_intervalo;
            this->ult->sig = nullptr;
        }
        else
            fin_intervalo->sig = sig_ult;
            
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
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    int ini, fin; std::cin >> ini >> fin;
    // escribir sol
    ListaAmpliada lista;
    int aux;
    for (int i = 0; i < n; ++i) {
        std::cin >> aux;
        lista.push(aux);
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
    std::ifstream in("sample-11.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}