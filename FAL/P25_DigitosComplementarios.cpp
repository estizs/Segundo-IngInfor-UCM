// Estibaliz Zubimendi
// A80


#include <iostream>
#include <fstream>

// función que resuelve el problema

// esta función calcula el complementario sin invertir
int finalInvertir(int n, int s) {
    if (n < 10) return (s * 10) + (9 - n);
    else return finalInvertir(n / 10, (s * 10) + (9 - (n % 10)));
}

// esta otra calcula el complementario invertido
int noFinalNoInvertir(int n) {
    if (n < 10) return 9 - n;
    else return noFinalNoInvertir(n / 10) * 10 + (9 - (n % 10));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; std::cin >> n;

    // escribir sol
    std::cout << noFinalNoInvertir(n) << " " << finalInvertir(n, 0) << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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