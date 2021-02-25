// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

// función que resuelve el problema
std::vector <int> resolver(std::vector<int> const& v, int l, int& longMax) {
    std::vector<int> sol;
    int longAct = 1, maxDerecha = v[v.size() - 1];
    longMax = 0;
    for (int i = v.size() - 2; i >= 0; --i) {
        if (v[i] > maxDerecha) {
            longAct = 1;
            maxDerecha = v[i];
        }
        else if (v[i] == maxDerecha) ++longAct;
        else longAct = 0;
        if (longAct == l) sol.push_back(i + longAct - 1);
        if (longAct > longMax && longAct >= l) longMax = longAct;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    int l; std::cin >> l;
    std::vector<int>v(n);
    int longMax;
    for (int i = 0; i < v.size(); ++i) std::cin >> v[i];
    std::vector<int> sol = resolver(v, l, longMax);

    // escribir sol
    std::cout << longMax << " " << sol.size() << " ";
    for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << " ";
    std::cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-14.1.in");
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