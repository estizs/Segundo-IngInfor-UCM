// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

struct tsol {
    bool cruzar;
    int x, y;
};

// función que resuelve el problema
tsol resolver(std::vector<int> const& v1, std::vector<int> const& v2, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v1[ini] == v2[ini]) return { true, ini, 0 };
        else if (v1[ini] < v2[ini]) return { false, ini, ini + 1 };
        else return { false, -1, 0 };
    }
    else {
        int m = (ini + fin) / 2;
        if (v1[m] > v2[m]) return resolver(v1, v2, ini, m);
        else if (v1[m] < v2[m]) return resolver(v1, v2, m, fin);
        else return { true, m, 0};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    std::vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i) std::cin >> v1[i];
    for (int j = 0; j < n; ++j) std::cin >> v2[j];
    tsol sol = resolver(v1, v2, 0, n);

    // escribir sol
    if (sol.cruzar) std::cout << "SI " << sol.x << "\n";
    else std::cout << "NO " << sol.x << " " << sol.y << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-41.in");
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
