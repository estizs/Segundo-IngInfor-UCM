// Estibaliz Zubimendi Solaguren
// A80


#include <iostream>
#include <vector>
#include <fstream>


// función que resuelve el problema
void resolver(std::vector<int> const& v, int l, std::vector<int> &sol) {
    int longAct = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1] || v[i] + 1 == v[i - 1] || v[i] - 1 == v[i - 1]) {
            ++longAct;
            if (longAct == l)
                sol.push_back(i - l + 1);
        }
        else longAct = 1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, L; std::cin >> n >> L;
    if (n == 0 && L == 0)
        return false;
    std::vector<int>v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    std::vector<int> sol;
    resolver(v, L, sol);

    // escribir sol
    std::cout << sol.size() << " ";
    for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << " ";
    std::cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-19.1.in");
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
