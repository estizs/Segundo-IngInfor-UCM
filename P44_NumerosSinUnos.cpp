// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>

using lli = long long int;
struct tsol {
    lli valor;
    bool tieneUno;
};

// función que resuelve el problema
tsol resolver(lli n) {
    if (n < 10) {
        if (n == 0) return {1, false};
        else {
            if (n == 1) return { n, true };
            else return { n, false };
        }
    }
    else {
        tsol s = resolver(n / 10);
        s.valor = s.valor * 9;
        if (s.tieneUno) return s;
        else {
            if (n % 10 > 1) s.valor -= 9 - n % 10;
            else s.valor -= 8;
            if (n % 10 == 1) s.tieneUno = true;
            return s;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli n; std::cin >> n;
    if (!std::cin)
        return false;

    tsol sol = resolver(n);

    // escribir sol
    std::cout << sol.valor << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-44.in");
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