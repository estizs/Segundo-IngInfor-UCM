// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tsol {
    int nodos, hojas, altura;
};

template <class T>
class bintree_ext : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:
    bintree_ext() : bintree<T>() {}
    bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
    int nodos() {
        return nodos(this->raiz);
    }
    int hojas() {
        return hojas(this->raiz);
    }
    int altura() {
        return altura(this->raiz);
    }
private:
    int nodos(Link l) {
        if (l == nullptr)
            return 0;
        else {
            int izq = nodos(l->left);
            int dcha = nodos(l->right);
            return izq + dcha + 1;
        }
    }
    int hojas(Link l) {
        if (l == nullptr)
            return 0;
        else {
            int izq = hojas(l->left);
            int dcha = hojas(l->right);
            bool hoja = l->left == nullptr && l->right == nullptr;
            int h;
            if (hoja)
                h = izq + dcha + 1;
            else
                h = izq + dcha;
            return h;
        }
    }
    int altura(Link l) {
        if (l == nullptr)
            return 0;
        else {
            int izq = altura(l->left);
            int dcha = altura(l->right);
            return std::max(izq, dcha) + 1;
        }
    }
};

template <typename T>
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
    // escribir sol
    std::cout << arbol.nodos() << " " << arbol.hojas() << " " << arbol.altura() << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-26I.in");
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