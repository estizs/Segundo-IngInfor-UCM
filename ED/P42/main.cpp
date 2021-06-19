// A79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include<string>
#include <sstream>
#include <vector>
#include <algorithm> // transform

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    std::map<std::string, std::vector<int>> tabla;
    std::cin.ignore(1);
    for (int i = 1; i <= n; ++i) {
        std::string linea, palabra;
        std::getline(std::cin, linea); // leer toda la línea
        std::stringstream ss(linea); // para separar cada palabra
        while (ss >> palabra) { // una vuelta por cada palabra de la línea
            // transformar palabra a minúsculas
            std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
            if(palabra.size() > 2 && !tabla.count(palabra)) // si no está no hay ningún problema
                tabla[palabra].push_back(i);
            else if(palabra.size() > 2 && tabla.count(palabra)) // si está hay que mirar si ya ha aparecido en la línea
                // si el último número insertado coincide con la línea entonces no se añade
                if(tabla.find(palabra)->second[tabla.find(palabra)->second.size() - 1] != i)
                    tabla[palabra].push_back(i);
        }
    }
    // escribir sol
    auto it = tabla.begin();
    while (it != tabla.end()) {
        std::cout << it->first << " ";
        for (int i = 0; i < it->second.size(); ++i)
            std::cout << it->second[i] << " ";
        std::cout << "\n";
        ++it;
    }
    std::cout << "---\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-42.in");
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
