// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:
    bintree_ext() : bintree<T>() {}
    bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
    T min() {
        return min(this->raiz);
    }
private:
    T min(Link l) {
        T m = l->elem;
        if (l->left != nullptr) {
            T izq = min(l->left);
            if (izq < m) m = izq;
        }
        if (l->right != nullptr) {
            T dcha = min(l->right);
            if (dcha < m) m = dcha;
        }
        return m;
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
bool resuelveCaso() {
    // leer los datos de la entrada
    char aux; std::cin >> aux;
    if (!std::cin)
        return false;
    if (aux == 'N') {
        bintree_ext<int> arbol = leerArbol_ext(-1);
        int sol = arbol.min();
        std::cout << sol << "\n";
    }
    else { // aux == 'P'
        std::string vacio = "#";
        bintree_ext<std::string> arbol = leerArbol_ext(vacio);
        std::string sol = arbol.min();
        std::cout << sol << "\n";
    }
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-28I.in");
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