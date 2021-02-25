// Estibaliz Zubimendi Solaguren
// A80


#include <iostream>
#include <fstream>
#include <vector>

bool tieneVistas(std::vector<std::pair<std::string, std::pair<int, int>>> const& v, int i) {
    // comparo el que está más a la costa con el edificio actual i
    return v[i + 1].second.first < v[i].second.second;
}

// función que resuelve el problema
void resolver(std::vector<std::pair<std::string, std::pair<int, int>>> v, std::vector<std::string> &sol) {
    // el primer edificio siempre tendrá vistas a no ser que no se venda piso
    if (v[v.size() - 1].second.second != -1) sol.push_back(v[v.size() - 1].first);
    // ahora recorremos el resto de edificios
    for (int i = v.size() - 2; i >= 0; --i) {
        // si tiene vistas y además se vende piso, se añade a la solución
        if (tieneVistas(v, i) && v[i].second.second != -1) {
            sol.push_back(v[i].first);
        }
        // si la altura actual es menor tenemos que actualizar su altura a la máxima, que será la del edificio anterior
        if (v[i + 1].second.first > v[i].second.first) {
            v[i].second.first = v[i + 1].second.first;
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    std::vector<std::pair<std::string, std::pair<int, int>>>v(n);
    std::vector<std::string>sol;
    for (int i = 0; i < v.size(); ++i) std::cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    resolver(v, sol);

    // escribir sol
    if (sol.size() == 0) std::cout << "Ninguno";
    else {
        std::cout << sol.size() << "\n";
        for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << " ";
    }
    std::cout << "\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-17.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
