// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(int m, int n, int k, std::vector<char>& s, std::vector<bool> &marcas) {
    for (char c = 'a'; c < 'a' + m; ++c) {
        s[k] = c;
        if (!marcas[c - 'a']) { // la letra no se ha usado todavía
            marcas[c - 'a'] = true;
            if (k == n - 1) { // si es solución
                for (char d : s)
                    std::cout << d;
                std::cout << "\n";
            }
            else resolver(m, n, k + 1, s, marcas);
            marcas[c - 'a'] = false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n; std::cin >> m >> n;
    if (!std::cin)
        return false;
    std::vector<char> sol(n);
    std::vector<bool> marcas;
    marcas.assign(m, false);
    resolver(m, n, 0, sol, marcas);

    // escribir sol
    std::cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-46.in");
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