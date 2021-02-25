// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

using pbi = std::pair<bool, int>;

// función que resuelve el problema
pbi resolver(std::vector<int> const& v, int ini, int fin) {
    if (ini + 1 == fin) return {v[ini], true}; // vector 1 elemento
    else if (ini + 2 == fin) { // vector de 2 elementos
        if (v[ini] < v[ini + 1]) return {true, v[ini] + v[ini + 1] };
        else return {false, v[ini] + v[ini + 1]};
    }
    else {
        int m = (ini + fin) / 2;
        pbi izq = resolver(v, ini, m);
        pbi dcha = resolver(v, m, fin);
        return {izq.first && dcha.first && (izq.second < dcha.second), izq.second + dcha.second };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m; std::cin >> n >> m;
    if (!std::cin)
        return false;
    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> v[i][j];
    // asumo que en principio la matriz está degradada
    bool sol = true;
    int cont = 0;
    while (cont < n && sol) {
        sol = resolver(v[cont], 0, v[cont].size()).first;
        ++cont;
    } 

    // escribir sol
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-36.in");
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