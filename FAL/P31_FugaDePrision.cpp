// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
char resolver(std::vector<char> const& v, int ini, int fin, char x1) {
    if (ini + 1 == fin) {
        if (v[ini] == x1) return v[ini] + 1;
        else return v[ini] - 1;
    }
    else if (ini + 2 == fin) {
        if (v[ini + 1] - v[ini] == 2) return v[ini] + 1;
        else if (v[ini] == x1) return v[ini + 1] + 1;
        else return v[ini] - 1;
    }
    else {
        int m = (ini + fin) / 2;
        if ((v[m] - x1) != (m - ini)) return resolver(v, ini, m + 1, x1);
        else return resolver(v, m, fin, v[m]);
    }
    return ' ';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char ini, fin; std::cin >> ini >> fin;
    int n = fin - ini;
    std::vector<char> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    char sol = resolver(v, 0, v.size(), ini);
    // escribir sol
    std::cout << sol << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
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