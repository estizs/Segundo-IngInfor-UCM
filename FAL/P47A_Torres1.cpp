// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(int n, int k, std::vector<std::string> &v) {
    for (std::string s : {"azul", "rojo", "verde"}) {
        v[k] = s;
        if (k == n - 1) {
            for (std::string t : v)
                std::cout << t << " ";
            std::cout << "\n";
        }
        else resolver(n, k + 1, v);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    std::vector<std::string> v(n);
    resolver(n, 0, v);

    // escribir sol
    std::cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-47A.in");
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
