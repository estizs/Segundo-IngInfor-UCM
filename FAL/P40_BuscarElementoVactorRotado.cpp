// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const&v, int ini, int fin, int valor) {
    if (ini + 1 == fin) {
        if (v[ini] == valor) return true;
        else return false;
    }
    else if (ini + 2 == fin) {
        if (v[ini] == valor || v[ini + 1] == valor) return true;
        else return false;
    }
    else {
        int m = (ini + fin) / 2;
        // rotación está a la derecha
        if (v[m] > v[fin - 1] && v[m] > v[ini]) {
            if (valor <= v[fin - 1] || valor >= v[m]) return resolver(v, m, fin, valor);
            else return resolver(v, ini, m, valor);
        }
        // rotación está a la izquierda
        else if (v[m] < v[fin - 1] && v[m] < v[ini]) {
            if (valor >= v[ini] || valor < v[m]) return resolver(v, ini, m, valor);
            else return resolver(v, m, fin, valor);
        }
        // no hay rotación
        else {
            if (valor < v[m]) return resolver(v, ini, m, valor);
            else return resolver(v, m, fin, valor);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == -1)
        return false;
    int valor; std::cin >> valor;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    bool sol = resolver(v, 0, v.size(), valor);

    // escribir sol
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-40.in");
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
