// Estibaliz Zubimendi
// A80


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using lli = long long int;


// función que resuelve el problema
int resolver(std::vector<int> &v) {
    sort(v.begin(), v.end());
    int longMax = 0, longAct = 0, ultMax = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i-1]) {
            ++longAct;
            if (longMax < longAct) {
                longMax = longAct;
                ultMax = i;
            }
        }
        else { 
            longAct = 0; 
        }
    }
    return v[ultMax];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli n; std::cin >> n;
    if (n == -1)
        return false;
    std::vector<int> v(n);
    for (int i = 0; i < v.size(); ++i) std::cin >> v[i];
    int sol = resolver(v);

    // escribir sol
    std::cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-13.1.in");
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
