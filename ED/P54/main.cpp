// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "oficinaEmpleo.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string op; std::cin >> op;
    if (!std::cin)
        return false;
    oficinaEmpleo oe;
    while (op != "FIN") {
        try {
            if (op == "altaOficina") {
                std::string n, e; std::cin >> n >> e;
                oe.altaOficina(n, e);
            }
            else if (op == "ofertaEmpleo") {
                std::string e; std::cin >> e;
                std::string p = oe.ofertaEmpleo(e);
                std::cout << e << ": " << p << "\n";
            }
            else if (op == "listadoEmpleos") {
                std::string p; std::cin >> p;
                std::vector<std::string> dev = oe.listadoEmpleos(p);
                std::cout << p << ": ";
                for (int i = 0; i < dev.size(); ++i)
                    std::cout << dev[i] << " ";
                std::cout << "\n";
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