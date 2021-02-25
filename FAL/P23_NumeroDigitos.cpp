// Estibaliz Zubimendi
// A80


#include <iostream>
#include <vector>
#include <fstream>

using lli = long long int;

// función que resuelve el problema
int resolver(lli n) {
    if (n < 10) return 1;
    else {
        return 1 + resolver(n / 10);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli n; std::cin >> n;
    if (!std::cin)
        return false;
    int sol = resolver(n);
    // escribir sol

    std::cout << sol << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-23.1.in");
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