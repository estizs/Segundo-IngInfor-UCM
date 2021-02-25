// Estibaliz Zubimendi
// A80


#include <iostream>
#include <vector>
#include <fstream>


// función que resuelve el problema
void resolver(std::vector<int> const &v, int k, int &maxDesnivel, int &ini, int &mismo) {
    int desnivelActual = 0;
    for (int i = 0; i < k; ++i) {
        desnivelActual += v[i];
    }
    maxDesnivel = desnivelActual;
    for (int i = k; i < v.size(); ++i) {
        desnivelActual -= v[i - k];
        desnivelActual += v[i];
        if (desnivelActual > maxDesnivel) {
            maxDesnivel = desnivelActual;
            ini = i - k + 1;
            // por si no hay ninguno igual
            mismo = ini;
        }
        else if (desnivelActual == maxDesnivel)
            mismo = i - k + 1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k; std::cin >> n >> k;
    if (n == 0 && k == 0)
        return false;
    std::vector<int>v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    int maxDesnivel = 0, ini = 0, mismo = 0;
    resolver(v, k, maxDesnivel, ini, mismo);

    // escribir sol
    std::cout << maxDesnivel << " " << ini << " " << mismo << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-18.1.in");
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
