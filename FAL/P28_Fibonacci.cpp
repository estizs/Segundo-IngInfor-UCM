// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>

using lli = long long int;

// función que resuelve el problema
lli fib(int n, int x, lli n1, lli n2) {
    if (x == n) return n2;
    else return fib(n, x + 1, n1 + n2, n1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    lli sol = fib(n, 0, 1, 0);
    // escribir sol
    std::cout <<  sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-28.1.in");
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