// Nombre del alumno .....
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>
#include "persona.h"

class filtro_edad {
    int edadMin, edadMax;
public:
    filtro_edad() {}
    filtro_edad (int min, int maxi) : edadMin(min), edadMax(maxi){}
    bool operator() (int const& elem) const {
        return edadMin <= elem && elem <= edadMax;
    }
};

// función que resuelve el problema
template <class T, class Predicado>
void remove_if(std::list<T>& lista, Predicado pred) {
    auto it = lista.begin();
    int tam = lista.size();
    for (int i = 0; i < tam; ++i) {
        auto sig_it = ++it;
        if (!pred((*--it).get_edad()))
            lista.erase(it);
        it = sig_it;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int personas, edadMin, edadMax; std::cin >> personas >> edadMin >> edadMax;
    if (personas == 0 && edadMin == 0 && edadMax == 0)
        return false;
    std::list<Persona> l;
    int edad;
    std::string nombre;
    char aux;
    for (int i = 0; i < personas; ++i) {
        std::cin >> edad;
        std::cin.get(aux);
        std::getline(std::cin, nombre);
        l.push_back({ edad, nombre });
    }
    remove_if(l, filtro_edad(edadMin, edadMax));

    // escribir sol
    for (Persona const& p : l) {
        std::cout << p.get_nombre() << "\n";
    }
    std::cout << "---\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-21.in");
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
