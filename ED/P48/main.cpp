// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "autoescuela.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string op; std::cin >> op;
    if (!std::cin)
        return false;
    autoescuela escuela;
    while (op != "FIN") {
        try {
            if (op == "alta") {
                std::string a, p; std::cin >> a >> p;
                escuela.alta(a, p);
            }
            else if (op == "es_alumno") {
                std::string a, p; std::cin >> a >> p;
                bool es = escuela.es_alumno(a, p);
                if (es)
                    std::cout << a << " es alumno de " << p << "\n";
                else
                    std::cout << a << " no es alumno de " << p << "\n";
            }
            else if (op == "puntuacion") {
                std::string a; std::cin >> a;
                int puntos = escuela.puntuacion(a);
                std::cout << "Puntuacion de " << a << ": " << puntos << "\n";
            }
            else if (op == "actualizar") {
                std::string a; std::cin >> a;
                int puntos; std::cin >> puntos;
                escuela.actualizar(a, puntos);
            }
            else if (op == "examen") {
                std::string p; std::cin >> p;
                int puntos; std::cin >> puntos;
                std::vector<std::string> v = escuela.examen(p, puntos);
                std::cout << "Alumnos de " << p << " a examen:\n";
                for (std::string s : v)
                    std::cout << s << "\n";
            }
            else if (op == "aprobar") {
                std::string a; std::cin >> a;
                escuela.aprobar(a);
            }
        }
        catch (std::domain_error &de) {
            std::cout << de.what() << "\n";
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
    std::ifstream in("sample-48.in");
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