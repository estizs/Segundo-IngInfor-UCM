// Estibaliz Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <stack>

// función que resuelve el problema
void resolver(std::queue<int> &cola, int n) {
    // utilizo la queue para los números positivos
    std::queue<int> q;
    // el stack para los negativos
    std::stack<int> s;
    // vaciamos la cola inicial y llenamos q y s dependiendo del primer elemento de cola
    for (int i = 0; i < n; ++i) {
        if (cola.front() <= 0)
            s.push(cola.front());
        else
            q.push(cola.front());
        cola.pop();
    }
    // ahora insertamos los números negativos ordenados de menor a mayor
    int n_neg = s.size();
    for (int i = 0; i < n_neg; ++i) {
        cola.push(s.top());
        s.pop();
    }
    int n_pos = q.size();
    // y los positivos como ya estaban ordenados los metemos tal cual
    for (int i = 0; i < n_pos; ++i) {
        cola.push(q.front());
        q.pop();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    std::queue<int>cola;
    int aux;
    for (int i = 0; i < n; ++i) {
        std::cin >> aux;
        cola.push(aux);
    }
    resolver(cola, n);

    // escribir sol

    for (int i = 0; i < n; ++i) {
        std::cout << cola.front() << " ";
        cola.pop();
    }
    std::cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-17.in");
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
