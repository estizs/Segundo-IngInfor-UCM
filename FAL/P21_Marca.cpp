// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

using pii = std::pair<int, int>;

// función que resuelve el problema
pii resolver(std::vector<int> const&v) {
    int longMax = 0, ult = 0, longAct = 0, maxMarca = v[0];
    pii sol;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] <= maxMarca) {
            ++longAct;
            if (longAct >= longMax) {
                ult = i;
                longMax = longAct;
            }
        }
        else {
            longAct = 0;
            maxMarca = v[i];
        }
    }
    sol.first = longMax;
    sol.second = ult - longMax + 1;
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    std::vector<int>v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    pii sol = resolver(v);

    // escribir sol
    std::cout << sol.first << " " << sol.second << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
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
