// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:
    bintree_ext() : bintree<T>() {}
    bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
    void frontera(std::vector<T>& dev) {
        frontera(this->raiz, dev);
    }
private:
    void frontera(Link l, std::vector<T>& dev) {
        if (l != nullptr) {
            frontera(l->left, dev);
            frontera(l->right, dev);
            if (l->left == nullptr && l->right == nullptr)
                dev.push_back(l->elem);
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
    bintree_ext<int> arbol = leerArbol_ext(-1);
    std::vector<int> sol;
    arbol.frontera(sol);
    // escribir sol
    for (int i = 0; i < sol.size(); ++i)
        std::cout << sol[i] << " ";
    std::cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-27I.in");
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