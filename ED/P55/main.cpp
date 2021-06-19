// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "gestor_futbolistas.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string op; std::cin >> op;
    if (!std::cin)
        return false;
    gestor_futbolistas gf;
    while (op != "FIN") {
        try {
            if (op == "fichar") {
                std::string j, e; std::cin >> j >> e;
                gf.fichar(j, e);
            }
            else if (op == "equipo_actual") {
                std::string j; std::cin >> j;
                std::string e = gf.equipo_actual(j);
                std::cout << "El equipo de " << j << " es " << e << "\n";
            }
            else if (op == "fichados") {
                std::string e; std::cin >> e;
                int f = gf.fichados(e);
                std::cout << "Jugadores fichados por " << e << ": " << f << "\n";
            }
            else if (op == "ultimos_fichajes") {
                std::string e;
                int n;
                std::cin >> e >> n;
                std::vector<std::string> ult = gf.ultimos_fichajes(e, n);
                std::cout << "Ultimos fichajes de " << e << ": ";
                for (int i = 0; i < (int)ult.size(); ++i)
                    std::cout << ult[i] << " ";
                std::cout << "\n";
            }
            else if (op == "cuantos_equipos") {
                std::string j; std::cin >> j;
                int c = gf.cuantos_equipos(j);
                std::cout << "Equipos que han fichado a " << j << ": " << c << "\n";
            }
        }
        catch (std::domain_error& de) {
            std::cout << "ERROR: " << de.what() << "\n";
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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