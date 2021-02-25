//*****************
// IMPORTANTE
//
// Estibaliz Zubimendi
// A80
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

// Aqui la funcion recursiva que resuelve el problema
int resolver(std::vector<int> const& vA, std::vector<int>const&vB, int ini, int fin) {
    if (ini + 1 == fin) return vA[ini]; // vector de un elemento
    else if (ini + 2 == fin) {
        if (vA[ini] == vB[ini]) return vA[ini + 1];
        else return vA[ini];
    }
    else {
        int m = (ini + fin) / 2;
        if (vA[m] < vB[m]) return resolver(vA, vB, ini, m + 1);
        else return resolver(vA, vB, m, fin);
    }
}
// Tratar cada caso
void resuelveCaso() {
    int numA;
    // lectura del vector A
    std::cin >> numA;
    std::vector<int> vA(numA);
    for (int i = 0; i < numA; ++i)
        std::cin >> vA[i];
    // lectura del vector B
    std::vector<int> vB(numA - 1);
    for (int j = 0; j < numA - 1; ++j)
        std::cin >> vB[j];
    // resolver
    int n = resolver(vA, vB, 0, vA.size());
        // mostrar resultado
        std::cout << n << '\n';

}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample-32.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i)
        resuelveCaso();

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
