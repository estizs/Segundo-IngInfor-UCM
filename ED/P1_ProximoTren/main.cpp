// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include "header.h"

Hora siguienteHora(std::vector<Hora> const& v, Hora const&h) {
    auto low = std::lower_bound(v.begin(), v.end(), h);
    if (low == v.end()) throw std::invalid_argument("NO");
    return *low;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int trenes, horas; std::cin >> trenes >> horas;
    if (trenes == 0 && horas == 0)
        return false;
    std::vector<Hora> v(trenes);
    for (int i = 0; i < trenes; ++i) std::cin >> v[i];
    for (int j = 0; j < horas; ++j) {
        std::string horario;
        int h, m, s;
        char aux;
        std::cin >> h >> aux >> m >> aux >> s;
        try {
            Hora hActual(h, m, s);
            std::cout << siguienteHora(v, hActual);
        }
        catch (std::invalid_argument& ia) {
            std::cout << ia.what() << "\n";
        }
    }
    std::cout << "---\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-01.in");
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
