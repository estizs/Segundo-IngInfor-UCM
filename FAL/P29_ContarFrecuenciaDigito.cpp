// Estibaliz Zubimendi Solaguren
// A80

#include <iostream>
#include <fstream>

// función que resuelve el problema
int noFinal(int n, int digito) {
    if (n < 10) {
        if (n == digito) return 1;
        else return 0;
    }
    else {
        if (n % 10 == digito) return noFinal(n / 10, digito) + 1;
        else return noFinal(n / 10, digito);
    }
}

int finall(int n, int digito, int s) {
    if (n < 10) {
        if (n % 10 == digito) return s + 1;
        else return s;
    }
    else {
        if (n % 10 == digito) return finall(n / 10, digito, s + 1);
        else return finall(n / 10, digito, s);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, digito; std::cin >> n >> digito;

    int sol1 = noFinal(n, digito);
    int sol2 = finall(n, digito, 0);
    
    // escribir sol
    std::cout << sol1 << " " << sol2 << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-29.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}