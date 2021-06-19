// Esti Zubimendi
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <stack>
#include <string>

bool vocal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void decodificar1(std::string const& XXX, std::queue<char> &XX) {
    std::queue<char>q;
    std::stack<char>s;
    for (int i = 0; i < XXX.size(); ++i) {
        if (i % 2 == 0)
            q.push(XXX[i]);
        else
            s.push(XXX[i]);
    }
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        XX.push(q.front());
        q.pop();
    }
    n = s.size();
    for (int i = 0; i < n; ++i) {
        XX.push(s.top());
        s.pop();
    }
}

void decodificar2(std::queue<char> &XX, std::string& X) {
    std::stack<char> s;
    while (!XX.empty()) {
        if (vocal(XX.front())) {
            X.push_back(XX.front());
            XX.pop();
        }
        else {
            while (!XX.empty() && !vocal(XX.front())) {
                s.push(XX.front());
                XX.pop();
            }
            while (!s.empty()) {
                X.push_back(s.top());
                s.pop();
            }
        }
    }
}

void resolver(std::string const& XXX) {
    std::queue<char> XX;
    decodificar1(XXX, XX);
    std::string X;
    decodificar2(XX, X);
    std::cout << X << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string XXX;
    std::getline(std::cin, XXX);
    if (!std::cin)
        return false;
    resolver(XXX);
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-18.in");
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