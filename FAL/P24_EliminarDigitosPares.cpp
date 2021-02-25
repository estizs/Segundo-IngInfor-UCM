// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>

using lli = long long int;

// función que resuelve el problema
lli resolver(lli n, lli pot) {
    if (n == 0) return 0;
    else {
        if ((n % 10) % 2 != 0) {
            return (pot * (n % 10)) + resolver(n/10, pot*10);
        }
        else return resolver(n/10, pot);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli n; std::cin >> n;
    if (!std::cin)
        return false;
    lli pot = 1;
    lli sol = resolver(n, pot);
    // escribir sol
    std::cout << sol << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-24.1.in");
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