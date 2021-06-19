// A79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "carnet_puntos.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string op;
    std::cin >> op;
    if (!std::cin)
        return false;
    carnet_puntos cp;
    while (op != "FIN") {
        try {
            if (op == "nuevo") {
                std::string dni; std::cin >> dni;
                cp.nuevo(dni);
            }
            else if (op == "cuantos_con_puntos") {
                int puntos; std::cin >> puntos;
                int a = cp.cuantos_con_puntos(puntos);
                std::cout << "Con " << puntos << " puntos hay " << a << "\n";
            }
            else if (op == "quitar") {
                std::string dni; std::cin >> dni;
                int puntos; std::cin >> puntos;
                cp.quitar(dni, puntos);
            }
            else if (op == "consultar") {
                std::string dni; std::cin >> dni;
                int a = cp.consultar(dni);
                std::cout << "Puntos de " << dni << ": " << a << "\n";
            }
            else if (op == "recuperar") {
                std::string dni; std::cin >> dni;
                int puntos; std::cin >> puntos;
                cp.recuperar(dni, puntos);
            }
            else if (op == "lista_por_puntos") {
                int puntos; std::cin >> puntos;
                std::list<std::string> lista = cp.lista_por_puntos(puntos);
                std::cout << "Tienen " << puntos << " puntos: ";
                for (std::string s : lista) {
                    std::cout << s << " ";
                }
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
    std::ifstream in("sample-49.in");
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
