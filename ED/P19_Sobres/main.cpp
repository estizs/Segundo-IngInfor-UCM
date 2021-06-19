// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int sobres; std::cin >> sobres;
    if (sobres == 0)
        return false;
    int comensales; std::cin >> comensales;
    std::deque<std::pair<int, int>> dq;
    // el primer elemento siempre se incluye
    int n; std::cin >> n;
    dq.push_back({0, n});
    for (int i = 1; i < comensales; ++i) {
        std::cin >> n;
        while (!dq.empty() && n > dq.back().second) // se come todos los valores más pequeños que haya en la deque
            dq.pop_back();
        dq.push_back({ i, n });
    }
    std::cout << dq.front().second << " ";
    for (int i = comensales; i < sobres; ++i) {
        if(dq.front().first <= (i - comensales))
            dq.pop_front();
        std::cin >> n;
        while (!dq.empty() && n > dq.back().second)
            dq.pop_back();
        dq.push_back({i, n});
        std::cout << dq.front().second << " ";
    }
    std::cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-19.in");
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
