// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct tProblema {
    bool resuelto = false;
    int intentos = 0;
};

struct tEquipo {
    int nProblemas = 0, tiempo = 0;
    std::unordered_map<std::string, tProblema> problemas;
};

struct tSol {
    std::string nombre;
    int problemas;
    int tiempo;
};

class ordEquipos {
public:
    bool operator() (tSol const& e1, tSol const& e2) {
        return (e1.problemas > e2.problemas) || ((e1.problemas == e2.problemas) && (e1.tiempo < e2.tiempo)) ||
            ((e1.problemas == e2.problemas) && (e1.tiempo == e2.tiempo) && (e1.nombre < e2.nombre));
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string nombre, problema, veredicto;
    int tiempo;

    std::unordered_map<std::string, tEquipo> equipos;

    std::cin >> nombre;
    while (nombre != "FIN") {
        std::cin >> problema >> tiempo >> veredicto;

        auto& info_equipo = equipos[nombre];
        auto& info_problema = info_equipo.problemas[problema];

        if (!info_problema.resuelto) {
            if (veredicto == "AC") {
                info_problema.resuelto = true;
                ++info_equipo.nProblemas;
                info_equipo.tiempo += tiempo + info_problema.intentos * 20;
            }
            else
                ++info_problema.intentos;
        }
        std::cin >> nombre;
    }
    
    std::vector<tSol> sol;
    for (auto it = equipos.begin(); it != equipos.end(); ++it)
        sol.push_back({ it->first, it->second.nProblemas, it->second.tiempo });
    std::sort(sol.begin(), sol.end(), ordEquipos());
    for (int i = 0; i < sol.size(); ++i)
        std::cout << sol[i].nombre << " " << sol[i].problemas << " " << sol[i].tiempo << "\n";
    std::cout << "---\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-46.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}