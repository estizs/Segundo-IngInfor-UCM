// Estibaliz Zubimendi 
// A79

#include "polinomio.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int64_t coef, expo;
	std::cin >> coef >> expo;
	if (!std::cin) return false;
	Polinomio p;
	while (coef != 0 || expo != 0) {
		p.anyadirMonomio({ coef, expo });
		std::cin >> coef >> expo;
	}
	int64_t numPreguntas = 0;
	std::cin >> numPreguntas;
	for (int i = 0; i < numPreguntas; ++i) {
		int64_t valor; std::cin >> valor;
		int64_t x = p.evaluar(valor);
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-04A.in");
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