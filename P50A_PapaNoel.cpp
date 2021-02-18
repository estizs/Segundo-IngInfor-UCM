// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<std::string> const& juguetes, int m, int n, int k, std::vector<int> &s) {
    int aux = 0;
    for (int i = 0; i < m; ++i) {
        s[k] = i;
        if (k % 2 == 0 || juguetes[s[k]] > juguetes[s[k-1]]) {
            if (k == 2 * n - 1) {
                ++aux;
                for (int j = 0; j < s.size(); ++j)
                    std::cout << s[j] << " ";
                std::cout << "\n";
            }
            else aux += resolver(juguetes, m, n, k + 1, s);
        }
    }
    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n; std::cin >> m >> n;
    if (!std::cin)
        return false;
    std::vector<std::string>juguetes(m);
    for (int i = 0; i < m; ++i) std::cin >> juguetes[i];
    std::vector<int>s(2*n);
    int sol = resolver(juguetes, m, n, 0, s);

    // escribir sol
    if (sol == 0) std::cout << "SIN SOLUCION\n\n";
    else std::cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-50A.in");
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