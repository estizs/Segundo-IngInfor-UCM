// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    std::map<std::string, int> tabla;
    // ignorar el salto de línea
    std::cin.ignore(1);
    for (int i = 0; i < n; ++i) {
        std::string nombre, nota;
        std::getline(std::cin, nombre);
        std::getline(std::cin, nota);
        if (nota == "CORRECTO")
            tabla[nombre] += 1;
        else tabla[nombre] -= 1;
    }
    // escribir sol
    auto it = tabla.begin();
    while (it != tabla.end()) {
        if (it->second != 0)
            std::cout << it->first << ", " << it->second << "\n";
        ++it;
    }
    std::cout << "---\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-41.in");
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
