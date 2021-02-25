// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

// divide y vencerás pero lo que se divide es el espacio de soluciones

// función que resuelve el problema
int resolver(std::vector<int> const& v, int numViajes, int ini, int fin) {
    // caso base es tener un peso
    // el intervalo entre el mínimo y el máximo de los pesos del camión es 1
    // consecutivo
    if (ini == fin) return ini; // un elemento
    else { // más de un elemento
        int m = (ini + fin) / 2;
        int viajes = 1, pesoAct =  v[0]; // inicialmente cogemos el primer peso
        for (int i = 1; i < v.size(); ++i) {
            if (pesoAct + v[i] <= m)
                pesoAct += v[i];
            else {
                ++viajes;
                pesoAct = v[i];
            }
        }
        // tardo poco = he elegido un camión muy grande
        if (viajes <= numViajes) return resolver(v, numViajes, ini, m);
        else return resolver(v, numViajes, m + 1, fin);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, numViajes; std::cin >> n >> numViajes;
    if (n == 0 && numViajes == 0)
        return false;
    std::vector<int>v(n);
    int minimo = 0, maxi = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (v[i] > minimo) minimo = v[i];
        maxi += v[i];
    }
    int sol = resolver(v, numViajes, minimo, maxi);

    // escribir sol
    std::cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-39.in");
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
