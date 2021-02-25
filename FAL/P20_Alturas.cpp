// Estibaliz Zubimendi
// A80


#include <iostream>
#include <vector>
#include <fstream>


// función que resuelve el problema
void resolver(std::vector<int> const&v, int maxAltura, int intervalo, int &sol) {
    std::vector<int> aux(maxAltura + 1);
    for (int i = 0; i < aux.size(); ++i) aux[i] = 0;
    for (int i = 0; i < v.size(); ++i) ++aux[v[i]];
    int maxN = 0;
    // primer intervalo
    for (int i = 0; i < intervalo; ++i) {
        maxN += aux[i];
    }
    int maxAct = maxN;
    for (int i = intervalo; i < aux.size(); ++i) {
        maxAct -= aux[i - intervalo];
        maxAct += aux[i];
        if (maxAct > maxN) maxN = maxAct;
    }
    sol = maxN;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == -1)
        return false;
    int maxAltura, intervalo; std::cin >> maxAltura >> intervalo;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    int sol;
    resolver(v, maxAltura, intervalo, sol);

    // escribir sol
    std::cout << sol << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-20.1.in");
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
