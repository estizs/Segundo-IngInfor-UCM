// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>

struct tSol {
    int valor, pot;
};

// función que resuelve el problema
tSol resolver(int n) {
    if (n < 10) {
        return { n, 10 };
    }
    else {
        tSol s = resolver(n / 10);
        return { s.valor + (n % 10) * s.pot, s.pot * 10 };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;
    if (n == 0)
        return false;
    tSol s = resolver(n);

    // escribir sol
    std::cout << s.valor << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-26.1.in");
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
