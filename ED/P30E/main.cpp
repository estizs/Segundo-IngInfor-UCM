// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tsol {
	int excursionistas;
	int equipos;
};

tsol excursion(bintree<int> const& a) {
	if (a.empty())
		return { 0, 0 };
	else {
		tsol izq = excursion(a.left());
		tsol dcha = excursion(a.right());
        tsol act = { std::max(izq.excursionistas, dcha.excursionistas) + a.root(), izq.equipos + dcha.equipos };
        if(a.root() != 0 && izq.equipos == 0 && dcha.equipos == 0)
            act.equipos = 1;
        return act;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    tsol sol = excursion(arbol);
    // escribir sol
    std::cout << sol.equipos << " " << sol.excursionistas << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-30E.in");
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