// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int>const&v, int l) {
    int maxi = v[0], posMax = 0;
    for (int i = 1; i < v.size(); ++i)
        if (v[i] > maxi) maxi = v[i];

    int maxAct = v[0], satisAct = 0, satisMax = 0;
    for (int i = 0; i < l; ++i) {
        satisAct += v[i];
        if (v[i] >= maxAct) {
            maxAct = v[i];
            posMax = i;
        }
    }
    int pos = 0;
    if (maxi == maxAct) {
        pos = l - 1;
        satisMax = satisAct;
    }
    for (int i = l; i < v.size(); ++i) {
        satisAct += v[i];
        satisAct -= v[i - l];
        if (v[i] >= maxAct || (v[i - l] == maxAct && posMax == i - l)) {
            maxAct = v[i];
            posMax = i;
        }
        if (satisAct >= satisMax && maxAct == maxi) {
            satisMax = satisAct;
            pos = i;
        }
    }
    return pos - l + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, l; std::cin >> n >> l;
    if (n == 0 && l == 0)
        return false;
    std::vector<int>v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    int sol = resolver(v, l);

    // escribir sol
    std::cout << sol << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-22.in");
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
