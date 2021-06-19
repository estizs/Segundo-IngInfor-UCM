// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tsol {
    bool completo, semi;
    int altura;
};


// función que resuelve el problema
tsol resolver(bintree<char> const& a) {
    if (a.empty())
        return { true, true, 0 };
    else {
        tsol izq = resolver(a.left());
        tsol dcha = resolver(a.right());
        tsol dev = {false, false, 0};
        if (izq.completo && dcha.completo && (izq.altura == dcha.altura))
            dev.completo = true;
        if (dev.completo || 
            (dcha.semi && izq.completo && (izq.altura == dcha.altura)) || 
            (dcha.completo && izq.completo && (izq.altura == dcha.altura + 1) ||
            (dcha.completo && izq.semi && (izq.altura == dcha.altura + 1))))
            dev.semi = true;
        dev.altura = std::max(izq.altura, dcha.altura) + 1;
        
        return dev;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    tsol sol = resolver(arbol);
    // escribir sol
    if (sol.completo)
        std::cout << "COMPLETO\n";
    else if (sol.semi)
        std::cout << "SEMICOMPLETO\n";
    else
        std::cout << "NADA\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-36.in");
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