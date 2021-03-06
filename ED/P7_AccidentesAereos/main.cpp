// Estibaliz Zubimendi
// A79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (!std::cin)
        return false;
    std::stack<std::pair<std::string, int>> s;

    std::cout << "NO HAY\n"; // el primer vuelo

    std::pair<std::string, int> aux;
    std::cin >> aux.first >> aux.second;
    s.push(aux);

    for (int i = 1; i < n; ++i) {
        std::cin >> aux.first >> aux.second;
        if (aux.second >= s.top().second) {
            // while para encontrar el elemento que supera al actual
            while (!s.empty() && aux.second >= s.top().second) {
                s.pop();
            }
            if (s.empty()) // no hay ningún elemento mayor
                std::cout << "NO HAY\n"; 
            else // se ha encontrado un elemento mayor
                std::cout << s.top().first << "\n";
        } 
        else {
            std::cout << s.top().first << "\n";
        }
        // añadimos el nuevo elemento
        s.push(aux);
    }
    std::cout << "---\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-07.in");
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