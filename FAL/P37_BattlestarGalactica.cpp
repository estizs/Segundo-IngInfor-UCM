// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>   

// función que resuelve el problema
int resolver(std::vector<int> &v, int ini, int fin) {
    if (ini + 1 == fin) return 0;
    else if (ini + 2 == fin) {
        if (v[ini] > v[ini + 1]) {
            //std::swap(v[ini], v[ini + 1]);
            return 1;
        }
        else return 0;
    }
    else {
        int m = (ini + fin) / 2;
        // guardamos las inversiones de los dos lados
        int izq = resolver(v, ini, m);
        int dcha = resolver(v, m, fin);

        // ordenamos con mergesort los dos lados
        std::inplace_merge(v.begin() + ini, v.begin() + (ini + m) / 2, v.begin() + m);
        std::inplace_merge(v.begin() + m, v.begin() + (m + fin) / 2, v.begin() + fin);

        // ahora tenemos que mirar las inversiones de un lado con el otro
        int i = ini, j = m, inversiones = 0;
        while (i < m && j < fin) {
            if (v[i] > v[j]) {
                inversiones += m - i;
                ++j;
            }
            else if (v[i] < v[j]) {
                ++i;
            }
        }
        return inversiones + izq + dcha;
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
    int sol = resolver(v, 0, v.size());
    // escribir sol
    std::cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-37.in");
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