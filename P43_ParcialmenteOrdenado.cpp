// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>
#include <vector>

struct tsol {
    int max, min;
    bool ord;
};


// función que resuelve el problema
tsol resolver(std::vector<int> const& v, int ini, int fin) {
    if (ini + 1 == fin)
        return { v[ini], v[ini], true };
    else {
        int m = (ini + fin) / 2;
        tsol izq = resolver(v, ini, m);
        tsol dcha = resolver(v, m, fin);
        if (izq.min <= dcha.min && dcha.max >= izq.max && izq.ord && dcha.ord)
            return { dcha.max, izq.min, izq.ord && dcha.ord };
        else return { dcha.max, izq.min, false };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0) return false;
    std::vector<int>v;
    while (n != 0) {
        v.push_back(n);
        std::cin >> n;
    }

    tsol sol = resolver(v, 0, v.size());

    // escribir sol
    if (sol.ord) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-432.in");
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