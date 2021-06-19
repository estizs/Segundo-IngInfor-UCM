// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tsol {
    bool zurdo;
    int hijos;
};

// función que resuelve el problema
tsol resolver(bintree<char> const& a) {
    if (a.empty())
        return { true, 0 };
    else {
        tsol izq = resolver(a.left());
        tsol dcha = resolver(a.right());
        // es hoja o izq y der zurdos y la restricción esa de la mitad
        return { a.left().empty() && a.right().empty() || (izq.zurdo && dcha.zurdo && (izq.hijos > ((izq.hijos + dcha.hijos) / 2))), izq.hijos + dcha.hijos + 1};
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    tsol sol = resolver(arbol);
    // escribir sol
    if (sol.zurdo)
        std::cout << "SI";
    else
        std::cout << "NO";
    std::cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-31E.in");
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