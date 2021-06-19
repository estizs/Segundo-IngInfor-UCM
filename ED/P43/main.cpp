// A79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using tabla = std::map<std::string, int>;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string linea1, linea2, clave;
    int valor;
    // primera tabla
    tabla ant;
    std::getline(std::cin, linea1);
    std::stringstream ss1(linea1);
    while (ss1 >> clave) {
        ss1 >> valor;
        ant[clave] = valor;
    }
    // segunda tabla
    tabla nuevo;
    std::getline(std::cin, linea2);
    std::stringstream ss2(linea2);
    while (ss2 >> clave) {
        ss2 >> valor;
        nuevo[clave] = valor;
    }
    auto it1 = ant.begin();
    auto it2 = nuevo.begin();
    std::vector<std::string> plus, menos, por;
    while (it1 != ant.end()) {
        // si en el antiguo hay un elemento que no está en el nuevo
        if (!nuevo.count(it1->first))
            menos.push_back(it1->first);
        // el elemento está en los dos diccionarios pero el valor está cambiado
        else if (nuevo[it1->first] != it1->second)
            por.push_back(it1->first);
        ++it1;
    }
    while (it2 != nuevo.end()) {
        // si en el antiguo hay un elemento que no está en el nuevo
        if (!ant.count(it2->first))
            plus.push_back(it2->first);
        ++it2;
    }
    if (plus.empty() && menos.empty() && por.empty())
        std::cout << "Sin cambios\n";
    else {
        if (!plus.empty()) {
            // añadidos
            std::cout << "+ ";
            for (int i = 0; i < plus.size(); ++i)
                std::cout << plus[i] << " ";
            std::cout << "\n";
        }
        if (!menos.empty()) {
            // quitados
            std::cout << "- ";
            for (int i = 0; i < menos.size(); ++i)
                std::cout << menos[i] << " ";
            std::cout << "\n";
        }
        if (!por.empty()) {
            // cambiados
            std::cout << "* ";
            for (int i = 0; i < por.size(); ++i)
                std::cout << por[i] << " ";
            std::cout << "\n";
        }
    }
    std::cout << "---\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-43.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore(1);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
        


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}