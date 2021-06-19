// A79
#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tsol {
	bool pareado;
	int hijosPares;
};
tsol resolver(bintree<int> const& a) {
	if (a.empty())
		return { true, 0 };
	else {
		tsol izq = resolver(a.left());
		tsol dcha = resolver(a.right());
		// Suponemos al principio que tenemos un número par así que sumamos 1
		tsol dev = { izq.pareado && dcha.pareado && std::abs(izq.hijosPares - dcha.hijosPares) <=
		1, izq.hijosPares + dcha.hijosPares + 1 };
		// Si nos llega un impar entonces la cantidad de números pares no cambia
		if (a.root() % 2 != 0)
			dev.hijosPares = izq.hijosPares + dcha.hijosPares;
		return dev;
	}
}
void resuelveCaso() {
	// Código del alumno
	bintree<int> arbol = leerArbol(-1);
	tsol sol = resolver(arbol);
	if (sol.pareado)
		std::cout << "SI";
	else
		std::cout << "NO";
	std::cout << "\n";
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-37.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCasos = 1; std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}