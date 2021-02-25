// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const&v, int ini, int fin) {
    if (ini + 1 == fin) return v[ini]; // vector de un elemento
    else if (ini + 2 == fin) return std::min(v[ini], v[ini + 1]); // vector dos elementos
    else {
        int m = (ini + fin) / 2;
        if (v[m] < v[m - 1]) return resolver(v, m, fin);
        else return resolver(v, ini, m + 1);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    std::vector<int>v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    int sol = resolver(v, 0, n);

    // escribir sol
    std::cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-33.in");
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