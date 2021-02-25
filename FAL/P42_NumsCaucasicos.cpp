// Estibaliz Zubimendi
// A80

#include <iostream>
#include <fstream>
#include <vector>

struct tsol {
    int pares;
    bool caucasico;
};

// Aqui la funcion recursiva que resuelve el problema

tsol resolver(std::vector<int> v, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v[ini] % 2 == 0) return { 1, true };
        else return { 0, true };
    }
    else {
        int m = (ini + fin) / 2;
        tsol izq = resolver(v, ini, m);
        tsol dcha = resolver(v, m, fin);
        if (std::abs(izq.pares - dcha.pares) <= 2 && izq.caucasico && dcha.caucasico)
            return { izq.pares + dcha.pares, izq.caucasico && dcha.caucasico };
        else return { izq.pares + dcha.pares, false };
    }
}

// Tratar cada caso
bool resuelveCaso() {
    // Lectura de los datos
    int num;
    std::cin >> num;
    if (num == 0) return false;
    std::vector<int> v(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> v[i];
    }

    // resolver
    tsol s = resolver(v, 0, num);

    // Escribir los resultados
    if (s.caucasico) std::cout << "SI" << '\n';
    else std::cout << "NO\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample-42.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Para restablecer entrada.

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
