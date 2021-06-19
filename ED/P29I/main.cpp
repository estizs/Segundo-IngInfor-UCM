// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tsol {
    int altura, diametro;
};

template <class T>
class bintree_ext : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:
    bintree_ext() : bintree<T>() {}
    bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
    tsol calcular_diametro() {
        return calcular_diametro(this->raiz);
    }
private:
    tsol calcular_diametro(Link const& a) {
        if (a == nullptr)
            return { 0,0 };
        else {
            tsol izq = calcular_diametro(a->left);
            tsol dcha = calcular_diametro(a->right);
            return { std::max(izq.altura, dcha.altura) + 1, std::max({izq.altura + dcha.altura + 1, izq.diametro, dcha.diametro}) };
        }
    }
};

template <class T>
inline bintree_ext<T> leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio)
        return {};
    else {
        bintree_ext<T> izq = leerArbol_ext(vacio);
        bintree_ext<T> dcha = leerArbol_ext(vacio);
        return { izq, raiz, dcha };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree_ext<char> arbol = leerArbol_ext('.');
    std::cout << arbol.calcular_diametro().diametro << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-29I.in");
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